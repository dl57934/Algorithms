import java.io.*;

class Main{
	static long P = 1000000007;

	public static void main(String[] args)throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		String[] NK = bfr.readLine().split(" ");

		long n = strToLong(NK[0]);
		long k = strToLong(NK[1]);
		long result;

		long A = factorial(1,n);
		long B = factorial(1,k);
		B = factorial(B, n-k);

		B = calculateDegree(B, P-2);
		B%=P;
		result = A*B;
		result%=P;
		System.out.println(result);
	}

	public static long strToLong(String str){
		return Long.parseLong(str);
	}

	public static long factorial(long operator, long limit){
		for(long i = 1; i <= limit; i++){
			operator*=i;
			operator%=P;
		}
		return operator;
	}

	public static long calculateDegree(long operator, long limit){
		long ans = 1;
		while(limit>0){
			if(limit%2 != 0){
				ans*=operator;
				ans%=P;
			}
			operator*=operator;
			operator%=P;
			limit/=2;
		}
		return ans;	
	}	
}