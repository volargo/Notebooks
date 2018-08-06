/*
 * Test fill method of Arrays class.
 */

import java.util.*;

public class ArrayFillMethodTest
{
	public static void main(String[] args) {
		final int MAX = 10;

		int[] a = new int[MAX];

		Arrays.fill(a, 100);

		for (int element : a) {
			System.out.print(element + " ");
		}
		System.out.print("\n");
	}
}
