import java.io.*;

class Main{
	public static void main(String[] args)throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		String words = bfr.readLine();
		int ascii = words.charAt(0);
		System.out.printf("%d", ascii);
	}
}