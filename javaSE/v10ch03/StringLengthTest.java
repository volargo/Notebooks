/*
 * Check string length and was null or not.
 */
public class StringLengthTest
{
	public static void main(String[] args) {
		String str1 = "Hello Java";
		if (str1 != null && str1.length() != 0) {
			System.out.println("str1 not null or length not equal 0.");
		} else {
			System.out.println("str1 is null and length equal 0.");
		}
	}
}
