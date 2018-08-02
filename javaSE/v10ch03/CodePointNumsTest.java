/*
 * codePoint
 */
public class CodePointNumsTest
{
	public static void main(String[] args) {
		String greeting = "Hello";
		int n = greeting.length();
		// get real length
		int cpCount= greeting.codePointCount(0, greeting.length());
		System.out.println("greeting code point length is: " + cpCount);
	}
}
