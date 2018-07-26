/*
 * =====================================================================================
 *
 *       Filename:  traverseDir.c
 *
 *    Description:  traverse a directory
 *
 *        Version:  1.0
 *        Created:  08/18/2017 01:10:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ftw.h>

#ifdef PATH_MAX
static int pathmax = PATH_MAX;
#else
static int pathmax = 0;
#endif  /* PATH_MAX */

#define SUSV3   200112L
#define MAXLINE 4096
/* 
 * If PATH_MAX is indeterminate, no guarantee this is adequate
 */
#define PATH_MAX_GUESS  1024

/* function type that is called for each filenam */
typedef int     Myfunc(const char *, const struct stat *, int);
static Myfunc   myfunc;
static int      myftw(char *, Myfunc *);
static int      dopath(Myfunc *);
char            *path_alloc(int *);    /* also return allocated size, if nonnull */

static void err_doit(int, int, const char *, va_list);
void        err_quit(const char *, ...);
void        err_dump(const char *, ...);
void        err_sys(const char *, ...);
void        err_ret(const char *, ...);

static long posix_version = 0;
static long nreg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot;

int
main(int argc, char *argv[])
{
    int         ret;

    if (argc != 2) {
        err_quit("usage: ftw <starting-pathname>");
    }
    ret = myftw(argv[1], myfunc);       /* does it all */

    ntot = nreg + ndir + nblk + nchr + nfifo + nslink + nsock;
    if (ntot == 0) {
        ntot = 1;       /* avoid divide by 0; print 0 for all counts */
    }
    printf("regular files   = %7ld, %5.2f %%\n", nreg,
            nreg*100.0/ntot);
    printf("directories     = %7ld, %5.2f %%\n", ndir,
            ndir*100.0/ntot);
    printf("block special   = %7ld, %5.2f %%\n", nblk,
            nblk*100.0/ntot);
    printf("char special    = %7ld, %5.2f %%\n", nchr,
            nchr*100.0/ntot);
    printf("FIFOs           = %7ld, %5.2f %%\n", nfifo,
            nfifo*100.0/ntot);
    printf("symbolic links  = %7ld, %5.2f %%\n", nslink,
            nslink*100.0/ntot);
    printf("sockets         = %7ld, %5.2f %%\n", nsock,
            nsock*100.0/ntot);

    exit(ret);
}

/*
 * Descend through the hierarchy starting at "pathname".
 * The caller's func() is called for every file.
 */
#ifndef _FTW_H
#define FTW_F   1       /* file other than directory */
#define FTW_D   2       /* directory */
#define FTW_DNR 3       /* directory that can't be read */
#define FTW_NS  4       /* file that we can't stat */
#endif

static char *fullpath;      /* contains full pathname for every file */

static int
myftw(char *pathname, Myfunc *func) {
    int     len;
    fullpath = path_alloc(&len);    /* malloc's for PATH_MAX+1 bytes (Figure 2.15)*/

    strncpy(fullpath, pathname, len);   /* protect against */
    fullpath[len-1] = 0;

    return(dopath(func));
}

/*
 * Descend through the hierarchy, starting at "fullpath".
 * If "fullpath" is anything other than a directory, we lstat() it,
 * call func(), and return. For a directory, we call ourself
 * recursively for each name in the directory.
 */
static int
dopath(Myfunc *func) {
    struct stat     statbuf;
    struct dirent   *dirp;
    DIR             *dp;
    int             ret;
    char            *ptr;

    /* stat error */
    if (lstat(fullpath, &statbuf) < 0) {
        return(func(fullpath, &statbuf, FTW_NS));
    }
    /* not a directory */
    if (S_ISDIR(statbuf.st_mode) == 0) {
        return(func(fullpath, &statbuf, FTW_F));
    }
    /*
     * It's a directory. First call func() for the directory,
     * then process each filename in the directory.
     */
    if ((ret = func(fullpath, &statbuf, FTW_D)) != 0) {
        return(ret);
    }
    ptr = fullpath + strlen(fullpath);      /* point to end of fullpath */
    *ptr++ = '/';
    *ptr = 0;

    if ((dp = opendir(fullpath)) == NULL) {     /* can't read directory */
        return(func(fullpath, &statbuf, FTW_DNR));
    }

    while ((dirp = readdir(dp)) != NULL) {
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0) {
            continue;       /* ignore dot and dot-dot */
        }
        strcpy(ptr, dirp->d_name);      /* append name after slash */
        if ((ret = dopath(func)) != 0) {        /* recursive */
            break;      /* time to leave */
        }
   }
    ptr[-1] = 0;    /* erase everything from slash onwards */

    if (closedir(dp) < 0) {
        err_ret("can't close directory %s", fullpath);
    }

    return(ret);
}

static int
myfunc(const char *pathname, const struct stat *statptr, int type) {
    switch (type) {
        case FTW_F:
            switch (statptr->st_mode & S_IFMT) {
                case S_IFREG:   nreg++;     break;
                case S_IFBLK:   nblk++;     break;
                case S_IFCHR:   nchr++;     break;
                case S_IFIFO:   nfifo++;    break;
                case S_IFLNK:   nslink++;   break;
                case S_IFSOCK:  nsock++;    break;
                case S_IFDIR:   err_dump("for S_IFDIR for %s", pathname);   break;
                                /* directories should have type = FTW_D */
                case FTW_D:     ndir++;     break;
                case FTW_DNR:   err_ret("stat error for %s", pathname);     break;
                case FTW_NS:    err_ret("stat error for %s", pathname);     break;
                default:        err_dump("unkonw type %d for pathname %s", type, pathname);
            }
    }

    return 0;
}

char *
path_alloc(int *sizep) {
    char    *ptr;
    int     size;

    if (posix_version == 0) {
        posix_version = sysconf(_SC_VERSION);
    }

    if (pathmax == 0) {     /* first time through */
        errno = 0;
    }

    if ((pathmax = pathconf("/", _PC_PATH_MAX)) < 0) {
        if (errno == 0) {
            pathmax = PATH_MAX_GUESS;       /* it's indeterminate */
        } else {
            err_sys("pathconf error for _PC_PATH_MAX");
        }
    } else {
        pathmax++;      /* add one since it's relative to root */
    }
    if (posix_version < SUSV3) {
        size = pathmax + 1;
    } else {
        size = pathmax;
    }

    if ((ptr = malloc(size)) == NULL) {
        err_sys("malloc error for pathname");
    }

    if (sizep != NULL) {
        *sizep = size;
    }
    return(ptr);
}

void
err_quit(const char *fmt, ...) {
    va_list     ap;

    va_start(ap, fmt);
    err_doit(0, 0, fmt, ap);
    va_end(ap);
}

void
err_dump(const char *fmt, ...) {
    va_list     ap;

    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
    abort();
    exit(1);
}

void
err_sys(const char *fmt, ...) {
    va_list     ap;

    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
}

void
err_ret(const char *fmt, ...) {
    va_list     ap;
    
    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
}

static void
err_doit(int errorflag, int error, const char *fmt, va_list ap) {
    char        buf[MAXLINE];

    vsnprintf(buf, MAXLINE, fmt, ap);

    if (errorflag) {
        snprintf(buf+strlen(buf), MAXLINE-strlen(buf), ": %s", strerror(error));
    }
    strcat(buf, "\n");
    fflush(stdout);
    fputs(buf, stderr);
    fflush(NULL);
}