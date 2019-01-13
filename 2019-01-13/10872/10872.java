import java.io.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(bfr.readLine());
		int result = factorial(N);
		System.out.println(result);
	}

	public static int factorial(int N){
		if(N>0){
			return N*factorial(N-1);
		}else{
			return 1;
		}
	}
}