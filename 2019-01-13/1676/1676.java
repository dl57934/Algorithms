import java.io.*;

class Main{
	static int fiveCount = 0;
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(bfr.readLine());

		for(int i = 5; i <= N; i++){
			if(i%5==0)
				decomposition(i);
		}
		System.out.println(fiveCount);
	}
	public static void decomposition(int N){
		while(N%5==0){
			fiveCount += 1;
			N/=5;
		}
	}
}