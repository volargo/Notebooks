/*
 * Test BigInteger class.
 */

import java.math.*;

public class BigIntegerTest1
{
	public static void main(String[] args) {
		BigInteger a = BigInteger.valueOf(100);
		BigInteger b = BigInteger.valueOf(1000);

		BigInteger odds = a.add(b); // odds = a + b
		BigInteger product = odds.multiply(b.add(BigInteger.valueOf(2))); // product = odds * (b + 2)
	}
}
