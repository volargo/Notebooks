public class ConstantTest
{
	public static void main(String[] args)
	{
		final double CM_PER_INCH = 2.54D;
		double paperWidth = 8.5D;
		double paperHeight = 11D;
		System.out.println("Paper width: " + paperWidth * CM_PER_INCH
							+ "\nPaper height: " + paperHeight * CM_PER_INCH);
	}
}
