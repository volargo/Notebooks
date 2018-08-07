/*
 * The program test plusDate method of Date class.
 */

import java.time.*;

public class PlusDaysMethodTest
{
	public static void main(String[] args) {
		LocalDate newYearsEve = LocalDate.of(1999, 12, 31);
		LocalDate aThousandDaysLater = newYearsEve.plusDays(1000);

		int year = aThousandDaysLater.getYear();
		int month = aThousandDaysLater.getMonthValue();
		int day = aThousandDaysLater.getDayOfMonth();

		System.out.printf("%d-%d-%d\n", year, month, day);
	}
}
