/*
 * This program demostrates a trianglar array.
 */
public class LotteryArray
{
	public static void main(String[] args) {
		final int MAX = 10;

		// allocate trianglar array
		int[][] odds = new int[MAX+1][];
		for (int n = 0; n <= MAX; n++) {
			odds[n] = new int[n + 1];
		}

		// fill trianglar array
		for (int n = 0; n < odds.length; n++) {
			for (int k = 0; k < odds[n].length; k++) {
				/*
				 * computer binomial coefficient n*(n-1)*(n-2)*...*(n-k+1)/(1*2*3*...*k)
				 */
				int lotteryOdds = 1;
				for (int i = 1; i <= k; i++) {
					lotteryOdds = lotteryOdds * (n - i + 1) / i;
				}

				odds[n][k] = lotteryOdds;
			}
		}

		// print trianglar array
		for (int[] row : odds) {
			for (int odd : row) {
				System.out.printf("%4d", odd);
			}
			System.out.println();
		}
	}
}
