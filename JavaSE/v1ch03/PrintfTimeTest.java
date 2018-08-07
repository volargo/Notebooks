/*
 * Test printf way to print time of String class.
 */

import java.util.Date;

public class PrintfTimeTest
{
	public static void main(String[] args) {
		System.out.printf("%tc\n", new Date());

		// 1 代表第一个参数索引 - "Due Date", 2 代表第二个参数索引 - new Date()
		System.out.printf("%1$s %2$tB %2$te, %2$tY.\n", "Due date:", new Date());

		System.out.printf("%1$s %2$tB %2$te, %2$tY. %3$s\n", "Due date:", new Date(), "Good day!");

		System.out.printf("%s %tB %<te, %<tY. %s\n", "Due date:", new Date(), "Good day!");
	}
}
