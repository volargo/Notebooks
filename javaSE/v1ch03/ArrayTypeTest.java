/*
 * Test array type.
 */

public class ArrayTypeTest
{

	public static void main(String[] args) {
		
		final int MAX_SIZE = 5;

		int[] a = new int[MAX_SIZE];

		for (int i = 0; i < MAX_SIZE; i++) {
			a[i] = i;
		}

		for (int i = 0; i < MAX_SIZE; i++) {
			System.out.printf("%d ", a[i]);
		}
		System.out.print("\n");
	}
}
