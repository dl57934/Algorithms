import java.io.*;

class Main{
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String oneLine = br.readLine();
		String twoLine = br.readLine();
		int A = Integer.parseInt(oneLine);
		int B = Integer.parseInt(twoLine);
		System.out.println(A+B);
	}
}