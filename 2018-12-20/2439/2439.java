import java.io.*;

class Main{
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		int N = Integer.parseInt(line);

		char[] stars = new char[N];
		for(int i = 0; i < N; i++)
			stars[i] = ' ';

		StringBuilder strBuilder = new StringBuilder();
		// System.out.println(stars);
		for (int i = N-1; i >= 0; i--){
			stars[i] = '*';
			strBuilder.append(stars).append("\n");	
		}
		System.out.print(strBuilder);	
	}
}