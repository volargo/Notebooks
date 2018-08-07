public class ForEachTest
{

	public static void main(String[] args) {
		final int MAX = 10;

		int[] a = new int[MAX];

		for (int i = 0; i < MAX; i++) {
			a[i] = i;
		}

		for (int element: a) {
			System.out.printf("%d", element);
		}
		System.out.print("\n");
	}

}
