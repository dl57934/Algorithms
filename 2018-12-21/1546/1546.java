import java.io.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(bfr.readLine());
		String[] stScore = bfr.readLine().split(" ");
		int M = 0;
		float sum = 0;

		for (int i = 0; i < N;  i++){
			int score = Integer.parseInt(stScore[i]);
			if(M < score){
				M = score;
			}
		}
		for (int i = 0; i < N;  i++){
			int score = Integer.parseInt(stScore[i]);
			sum += (float)score/M*100;
		}
		System.out.printf("%.2f",sum/N);
	}
}