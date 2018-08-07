/*
 * charAt method: get code point unit.
 */
public class CharAtTest
{
	public static void main(String[] args) {
		String s = "Hello, World";
		char first = s.charAt(0);
		char last = s.charAt(4);
		System.out.println("First: " + first + "\nLast: " + last);
	}
}
