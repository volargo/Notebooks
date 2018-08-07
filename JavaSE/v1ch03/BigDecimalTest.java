/*
 * Test BigDecimal class.
 */

import java.math.*;
import java.util.*;

public class BigDecimalTest
{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		System.out.print("Enter a: ");
		double a = in.nextDouble();
		
		System.out.print("Enter b: ");
		double b = in.nextDouble();

		BigDecimal result = BigDecimal.valueOf(1);

		result = result.add(BigDecimal.valueOf(a + b));

		System.out.println("x + y = " + result);
	}
}
