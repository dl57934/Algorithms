import java.io.*;

class Main{
	static int []arr = new int[50];
	static int []one = new int[50];
	static int []zero = new int[50]; 

	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(bfr.readLine());
		one[0] = 0; one[1] = 1;
		zero[0] = 1; zero[1] = 0;
		for(int i = 0; i < T; i++){
			int N = Integer.parseInt(bfr.readLine());
			fibo(N);
			System.out.printf("%d %d\n", zero[N], one[N]);
		}
	}

	public static int fibo(int N){
		if(N == 0 || N == 1)
			return N;
		else {
			if(arr[N] == 0){
				arr[N] = fibo(N-1) + fibo(N-2);
				one[N] = one[N-1] + one[N-2];
				zero[N] = zero[N-1] + zero[N-2];
			}
			return arr[N];
		}
	}
}