import java.io.*;
import java.math.*;

class Main{

	static BigInteger[][] memo = new BigInteger[102][102];

	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		String[] order = bfr.readLine().split(" ");
		int n = strToInt(order[0]);
		int m = strToInt(order[1]);
		BigInteger big = bibo(n, m);
		System.out.println(big);
	}

	public static BigInteger bibo(int n, int m){
		if(m==n || m ==0)
			return BigInteger.ONE;
		else{
			if(memo[n][m] == null){
				memo[n][m] = bibo(n-1, m-1).add(bibo(n-1, m));
			}
			return memo[n][m];
		}
	}

	public static int strToInt(String str){
		return Integer.parseInt(str);
	}
}