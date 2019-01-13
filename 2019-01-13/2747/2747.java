import java.io.*;

class Main{
	static int arr[] = new int[50];
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(bfr.readLine());
		System.out.println(fibo(n));
	}

	public static int fibo(int n){
		if(n == 0 || n == 1)
			return n;
		else{
			if(arr[n] == 0)
				arr[n] = fibo(n-1) + fibo(n-2);
			return arr[n];
		}
	}
}