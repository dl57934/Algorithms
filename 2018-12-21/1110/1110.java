import java.io.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(bfr.readLine());
		int originalNum = N;
		int count = 0;
		int ten = 0, one = 0;
		while(true){
			one = (N%10+N/10)%10;
			ten = N % 10;
			count+=1;
			if (originalNum == ten*10+one)break;
			N = ten*10+one;
		}
		System.out.println(count);
	}
}