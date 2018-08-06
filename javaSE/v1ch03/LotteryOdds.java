import java.util.*;

public class LotteryOdds
{
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		System.out.print("How many numbers do you need to draw? ");
		int k = input.nextInt();

		System.out.print("What is the heighest number you can draw? ");
		int n = input.nextInt();

		/*
		 * computer binomial coefficient n*(n-1)*(n-2)*...*(n-k+1)/(1*2*3*...*k)
		 */

		int lotteryOdds = 1;
		for (int i = 1; i <= k; i++) {
			lotteryOdds = lotteryOdds * (n - i + 1) / i;
		}

		System.out.println("You odds are 1 in " + lotteryOdds + ". Good luck!");
	}
}
