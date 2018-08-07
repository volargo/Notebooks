/*
 * Test BigInteger class.
 * Page-77
 */

import java.math.*;
import java.util.*;

public class BigIntegerTest2
{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		System.out.print("How many numbers do you need to draw? ");
		int k = in.nextInt();

		System.out.print("What is the heighest number you can draw? ");
		int n = in.nextInt();

		/*
		 * computer binomial coefficient n*(n-1)*(n-2)*...*(n-k+1)/(1*2*3*...*k)
		 */

		BigInteger lotteryOdds = BigInteger.valueOf(1);

		for (int i = 1; i <= k; i++) {
			lotteryOdds = lotteryOdds.multiply(BigInteger.valueOf(n - i + 1)).divide(
					BigInteger.valueOf(i));
		}

		System.out.println("Your odds are 1 in " + lotteryOdds + ". Good luck!");
	}
}

/*
 *	BigInteger add(BigInteger others)
 *	BigInteger substract(BigInteger others)
 *	BigInteger multiply(BigInteger others)
 *	BigInteger divide(BigInteger others)
 *	BigInteger mod(BigInteger others)
 *
 *	int compareTo(BigInteger others)
 *
 *	// 返回值等于x的大整数
 *	static BigInteger valueOf(long x)
 */
