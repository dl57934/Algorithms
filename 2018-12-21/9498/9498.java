import java.io.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		int score = Integer.parseInt(bfr.readLine());
		String rating = "FFFFFFDCBAA";
		System.out.println(rating.charAt((score/10)));
	}
}