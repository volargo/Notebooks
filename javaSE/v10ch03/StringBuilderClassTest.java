/*
 * 构建字符串
 */
public class StringBuilderClassTest
{
	public static void main(String[] args) {
		// 构建一个空的字符串构建器
		StringBuilder builder = new StringBuilder();
		
		// 调用 append 方法添加内容
		char ch = 'A';
		builder.append(ch);
		System.out.println("1: " + builder);
		
		String str = "append str.";
		builder.append(str);
		System.out.println("2: " + builder);

		// 调用 toString 方法构建字符串
		String completedString = builder.toString();
		System.out.println("3: " + builder);
	}
}
