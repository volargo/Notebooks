/*
 * equals method
 */
public class EqualsMethodTest
{
	// main
	public static void main(String[] args) {
		String str1 = "Hello";
		String str2 = "World";

		// Match case
		if (str1.equals(str2) == true) {
			System.out.println("Equal.");
		} else {
			System.out.println("Not equal.");
		}

		// Ignore case
		if (str1.equalsIgnoreCase(str2) == true) {
			System.out.println("Equal.");
		} else {
			System.out.println("Not equal.");
		}
	}
}
