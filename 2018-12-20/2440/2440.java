import java.io.*;

class Main{
	public static void main(String[] args)throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		String line = bfr.readLine();
		int N = Integer.parseInt(line);
		String stars = "";

		StringBuilder strBuilder = new StringBuilder();
		for (int i = 0; i< N;i++){
			for (int j = i; j < N; j++){
				strBuilder.append("*");
			}
			strBuilder.append("\n");
		}
		System.out.print(strBuilder);
	}
}