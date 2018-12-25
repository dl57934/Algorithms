import java.io.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		String line = bfr.readLine();
		int N = Integer.parseInt(line);
		char[] stars = new char[N];
		for (int i = 0; i<N;i++){
			stars[i] = '*';
		}
		StringBuilder stBuilder = new StringBuilder();
		for (int j = 0; j<N; j++){
			stBuilder.append(stars).append("\n");
			stars[j] = ' ';
		}
		System.out.print(stBuilder);
	}
}