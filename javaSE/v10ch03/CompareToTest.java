/*
 * Test compareTo method of String class.
 *
 * Java核心技术(卷1)-基础知识(第10版) - Page 38
 *
 */
public class CompareToTest
{
	public static void main(String[] args) {
		String str1 = "XXYYZZ";
		String str2 = "AABBCC";

		// compareTo method
		if (str1.compareTo(str2) == 0) {
			System.out.println("str1 = str2");
		} else if (str1.compareTo(str2) > 0) {
			System.out.println("str1 > str2");
		} else {
			System.out.println("str1 < str2");
		}
	}
}
