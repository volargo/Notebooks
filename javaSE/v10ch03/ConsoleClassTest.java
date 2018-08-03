/*
 * Test the Console class.
 *
 * Java核心技术(卷1)-基础知识(第10版) - Page 57
 *
 */
import java.io.*;
import java.lang.*;

public class ConsoleClassTest
{
	public static void main(String[] args) {
		Console cons = System.console();
		String username = cons.readLine("User name: ");
		char[] passwd = cons.readPassword("Password: ");

		String pwd = passwd.toString();
		if (pwd.compareTo("Napoleon") == 0) {
			System.out.println("login successed.");
		} else {
			System.out.println("wrong password.");
		}
	}
}
