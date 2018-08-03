/*
 * Test Scanner object.
 */

import java.io.*;
import java.nio.file.*;
import java.util.*;

public class ReadFilesTest
{

	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(Paths.get("myfile.txt"), "UTF-8");
	}
}
