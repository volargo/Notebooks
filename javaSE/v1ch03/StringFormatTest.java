/*
 * Test format metho of String class.
 *
 * Java核心技术(卷1)-基础知识(第10版) - Page 59
 *
 */
import java.lang.*;
import java.util.*;

public class StringFormatTest
{
	public static void main(String[] args) {

		// Create new scanner object
		Scanner in = new Scanner(System.in);

		// Get name
		System.out.println("What's your name? ");
		String name = in.nextLine();

		// Get age
		System.out.println("How old are you? ");
		int age = in.nextInt();

		// Format string, but don't print
		String message = String.format("Hello, %s. Next year, you'll be %d.", name, age);
	}
}
