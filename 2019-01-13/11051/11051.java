import java.io.*;

class Main{
	static long memo[][] = new long[1003][1003];

	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		String[] order = bfr.readLine().split(" ");
		int N = strToInt(order[0]);
		int R = strToInt(order[1]);
		System.out.println(bibo(N, R)%10007);
	}

	public static int strToInt(String num){
		return Integer.parseInt(num);
	}

	public static long bibo(int N, int R){
		if(N==R || R==0)
			return 1;
		else {
			if(memo[N][R] == 0)
				memo[N][R] = bibo(N-1, R-1)%10007 + bibo(N-1, R)%10007;
			return memo[N][R];
		}
	}
}