/*
 * Test LocalDate class.
 */

import java.time.*;	// LocalDate class support.
import java.util.*;	// Arrays class support.

public class LocalDateTest
{
	public static void main(String[] args) {
		LocalDate newYearsEve = LocalDate.of(1999, 12, 31);

		int[] nowDate = new int[3];

		int years = newYearsEve.getYear();
		nowDate[0] = years;

		int month = newYearsEve.getMonthValue();
		nowDate[1] = month;

		int day = newYearsEve.getDayOfMonth();
		nowDate[2] = day;

		System.out.println(Arrays.toString(nowDate));
	}
}
