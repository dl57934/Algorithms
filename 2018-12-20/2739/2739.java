import java.io.*;

class Main{
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String NLine = br.readLine();
		int N = Integer.parseInt(NLine);

		StringBuilder strBuilder = new StringBuilder();
		for (int i = 1; i<=9;i++)
			strBuilder.append(N + " * " + i + " = "+ N*i +"\n");
		System.out.print(strBuilder);
	}
}