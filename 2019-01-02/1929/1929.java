import java.io.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		String MN[] = bfr.readLine().split(" ");

		int M = Integer.parseInt(MN[0]);
		int N = Integer.parseInt(MN[1]);
		for(int i = M; i <= N; i++){
			if(i != 1){
				estoras(i);
			}
		}
	}

	private static int estoras(int num){
		for(int i = 2; i <= Math.sqrt(num); i++){
			if(num % i == 0){
				return 0;
			}
		}
		System.out.println(num);
		return 1;
	}
}