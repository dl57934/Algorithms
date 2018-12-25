import java.io.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		int N = Integer.parseInt(line);

		for (int i = 1; i<=N;i++)
			System.out.println(i);
	}
}