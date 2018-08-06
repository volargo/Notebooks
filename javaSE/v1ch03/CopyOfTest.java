public class CopyOfTest
{
	public static void main(String[] args) {
		int[] luckNumbers = new int[20];

		int[] copiedLuckNumbers = Arrays.copyOf(luckNumbers, luckNumbers.length);
	}
}
