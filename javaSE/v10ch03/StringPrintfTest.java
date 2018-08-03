/*
 * Test printf method of String class
 *
 * Java核心技术(卷1)-基础知识(第10版) - Page 58
 *
 */
public class StringPrintfTest
{
	public static void main(String[] args) {
		double x = 30000.0F / 3.0F;
		System.out.printf("%8.2f\n", x); // Page 59

		x = -100.123F;
		System.out.printf("%,(.2f\n", x); // Page 59
	}
}
