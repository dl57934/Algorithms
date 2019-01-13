import java.io.*;

class Main{
	public static void main(String[] args) throws Exception{	
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		long n = Long.parseLong(bfr.readLine());
		long f1 = 0, f2 = 1;
		long result=0;
		for(int i =1; i < n % 1500000; i++){
			result = (f1 + f2)%1000000;
			f1 = f2;
			f2 = result;
		}
		if(n%1500000 == 0 || n%1500000 == 1)
			System.out.println(n%1500000);
		else
			System.out.println(result);
	}
}