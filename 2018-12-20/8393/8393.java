import java.io.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		String line = bfr.readLine();
		int N = Integer.parseInt(line);
		System.out.print(N*(N+1)/2);
	}
}