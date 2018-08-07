/*********************************************************
 * Author		: KhanEmbedded
 * Email		: KhanEmbedded@163.com
 * Last modified: 2015-06-07 14:07
 * Filename		: shellCommand.c
 * Description	: shell command
 *********************************************************/

#include <grp.h> //用户组
#include <pwd.h> //口令文件
#include <stdio.h> //标准输入输出库
#include <unistd.h> //提供对 POSIX 操作系统 API 的访问功能
#include <stdlib.h> //定义杂项函数及内存分配函数
#include <string.h> //字符串操作
#include <malloc.h> //动态存储分配函数头文件
#include <signal.h> //信号机制支持
#include <dirent.h> //目录项
#include <sys/wait.h> //进程控制
#include <sys/stat.h> //文件状态
#include <sys/types.h> //基本系型数据类型

#define DEL_PROMPT "$"
#define ROOT_PROMPT "#"
#define USER_PROMPT "@"
#define PATH_PROMPT "~"
#define BUF_SIZE 50

int execute_command(char **); //执行用户命令参数
int show_user_prompt(); //显示用户操作提示符
int built_in_command(char *, char **); //内建命令
char *next_command(FILE *); //用户进行输入命令操作
char **splitline_command(char *); //用户输入命令参数分析

const int max_name_len = 256;
const int max_path_len = 1024;

int main(void)
{
	int result;
	char *cmd_line, **arg_list;

	//命令参数有效则执行分析和执行命令的子函数
	while((cmd_line = next_command(stdin)) != NULL)
	{
		if ((arg_list = splitline_command(cmd_line)) != NULL) //分析用户输入是否有效
			result = execute_command(arg_list); //执行用户输入命令参数
	}
	
	//释放占用内存
	free(cmd_line);	
	free(arg_list);

	return 0;
}

/****************************** 显 示 用 户 命 令 提 示 符  **********************************/
int show_user_prompt()
{
	//当前主机名称，当前目录路径，替换旧的目录路径缓存域
	char hostname[max_name_len], pathname[max_path_len];
	
	struct passwd *pwd;

	//输出用户名称和主机名称
	pwd = getpwuid(getuid());
	if(gethostname(hostname, max_name_len) == 0)
		printf("[Wshell]%s%s%s:", pwd->pw_name, USER_PROMPT, hostname);
	else
		printf("[Wshell]%s%sunknow:", pwd->pw_name, USER_PROMPT);
	
	//获取用户当前目录路径并进行字符替换处理
	getcwd(pathname, max_path_len);

	//对比当前所在目录路径和用户目录路径, 并且作相关输出
	if (strlen(pathname) < strlen(pwd->pw_dir) || strncmp(pathname, pwd->pw_dir, strlen(pwd->pw_dir)) != 0)
		printf("%s", pathname);
	else
		printf("~%s", pathname + strlen(pwd->pw_dir));

	//判断是否为root用户
	if (getuid() == 0)
		printf("# ");
	else
		printf("$ ");

	return 1;
}

/****************************** 获 取 用 户 输 入 ********************************************/
char *next_command(FILE *fp)
{
	//输入字符的长度，内存域第一个指针值，输入的字符
	int buf_space = 0, pos = 0, inputChar;
	char *buf; //定义二维数组

	show_user_prompt(); //屏幕输出shell命令提示符

	//如果输入参数不以文件标志结束则处理用户输入字符串
	while ((inputChar = getc(fp)) != EOF)
	{
		if (pos+1 >= buf_space)
		{
			//buf长度为0则重新给数组赋值
			if (buf_space == 0)
				buf = malloc(BUF_SIZE); //动态分配50个单位的数组
			else
				buf = realloc(buf, buf_space + BUF_SIZE);
			buf_space += BUF_SIZE;
		}
		
		if (inputChar == '\n') //用户输入为回车符则跳出循环外
			break;

		buf[pos] = inputChar; //将用户输入字符对应分配到"buf"数组中
		pos++; //重复累加"pos"的值
	}

	//输入参数以文件标志结并且"pos"的指向值为空, 则向操作系统返回空
	if (inputChar == EOF && pos == 0)		
		return NULL;

	buf[pos] = '\0'; //将"buf"域中的最后一个值赋值为空作为命令结束标志
	
	return buf; //函数结束并返回"buf"域中的值
}

/****************************** 分 析 用 户 输 入 的 命 令 字 符  ****************************/
char **splitline_command(char *line)
{
	char **args;

	//自定义创建字符串的子函数
	char *newstr();

	//地址表, 临时内存区在表中的字节数, 内存域中的计数值, 计数值
	int spots = 0, buf_space = 0, argnum = 0, len;

	//拷贝的命令参数，头指针
	char *cp_cmd = line, *start;

	//如果参数为空, 则返回空值
	if (line == NULL)
		return NULL;

	//动态分配50个单位值给args
	args = malloc(BUF_SIZE);
	//变量赋值
	buf_space = BUF_SIZE;
	spots = BUF_SIZE / sizeof(char *);

	while (*cp_cmd != '\0')
	{
		//过滤空格字符
		if (*cp_cmd == ' ')
			cp_cmd++;
		if (argnum + 1 >= spots)
		{
			args = realloc(args, buf_space + BUF_SIZE);
			buf_space = buf_space + BUF_SIZE;
			spots += (BUF_SIZE/sizeof(char *));
		}

		start = cp_cmd;
		len = 1;

		while (*++cp_cmd != '\0' && *cp_cmd != ' ') 
			len++;
		args[argnum++] = newstr(start, len);
	}

	args[argnum] = NULL;

	return args;
}

char *newstr(char *str, int i)
{
	char *rv = malloc(i + 1); //动态分配空间
	
	rv[i] = '\0'; //数组赋空值
	
	strncpy(rv, str, i); //依据指定长度拷贝字符

	return rv;
}

/***************************** 执 行 经 过 分 析 的 用 户 输 入 命 令  ************************/
int execute_command(char *argv[]) //执行经过处理字符参数的函数
{
	//标识创建的进程，子进程信息
	int pid, child_info = -1;

	//参数值为空正常返回操作系统
	if (argv[0] == NULL)
		return 0;


	if(!built_in_command(argv[0], argv))
		return 0;

	//创建进程错误时的信息提示
	if ((pid = fork()) == -1)
		perror("fork");
	//成功创建子进程
	else if (pid == 0)
	{
		execvp(argv[0], argv);
		perror("can't execute command"); //输出不能执行进程的错误处理信息提示
		exit(1); //退出程序
	}
	//等待子进程结束返回父进程继续执	行程序
	else 
		if (wait(&child_info) == -1) //如果等待执行子进程错误则输出错误信息提示
			perror("wait");

	return child_info; //返回子进程编号
}

/****************************** 内 建 命 令 **************************************************/
int built_in_command(char *command, char **parameters)
{
	//用户输入'exit'或者'quit'则退出程序
    if(strcmp(command, "exit") == 0 || strcmp(command,"quit") == 0)
        exit(0);
	//用户输入为'about'则输出程序介绍信息
    else if(strcmp(command, "about") == 0)
    {	
        printf("This is a simulation of shell (bash) in Linux.\n");
		printf("Software name: shell\n");
		printf("Author: KhanEmbedded\n");
		printf("Email: KhanEmbedded@163.com\n");
        return 0;
    }
	//用户输入'cd'命令则继续分析后面的参数
    else if(strcmp(command, "cd") == 0) 
    {
		struct passwd *pwd;
        char *cd_path = NULL;
		pwd = getpwuid(getuid());
	
		if(parameters[1][0] == '~')
        {
            cd_path = malloc(strlen(pwd->pw_dir)+strlen(parameters[1]));

			//输入参数无效则输出错误信息
            if(cd_path == NULL)
                printf("cd:malloc failed.\n");

			//将用户目录路径拷贝到cd命令执行的路径
            strcpy(cd_path, pwd->pw_dir);
			//依据指定长度拷贝参数
            strncpy(cd_path+strlen(pwd->pw_dir), parameters[1]+1, strlen(parameters[1]));
        }
        else
        {
			//依据指定长度动态分配大小给cd命令路径的数组
            cd_path = malloc(strlen(parameters[1]+1)); 
            
			//输入命令无效则输入错误提示信息
			if (cd_path == NULL)
                printf("cd:malloc failed.\n");

            strcpy(cd_path, parameters[1]);
        }

        if (chdir(cd_path) != 0) 
            printf("-wshell: cd: %s:%s\n", cd_path, "error");
       
		free(cd_path); //释放内存
		return 0;
    }

	//没有执行自建命令
    return 1;
}
