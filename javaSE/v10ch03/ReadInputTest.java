/*
 * Structure Scanner object and link with System.in stream.
 */

import java.util.*;

public class ReadInputTest
{
	public static void main(String[] args) {
		// structure Scanner object
		Scanner input = new Scanner(System.in);
		
		// raad line
		System.out.println("What's your name? ");
		String name = input.nextLine();

		// read integer
		System.out.println("How old are you? ");
		int age = input.nextInt();

		// read double
		System.out.println("What is your height? (eg: 1.78)");
		double height = input.nextDouble();

		// print input
		System.out.println("Your name is: " + name);
		System.out.println("Your age is: " + age);
		System.out.println("Your height is: " + height + "m");
	}
}
