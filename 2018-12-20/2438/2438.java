import java.io.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		int N = Integer.parseInt(line);
		StringBuilder strBuilder1 = new StringBuilder();
		StringBuilder strBuilder2 = new StringBuilder();
		for (int i =1; i<=N;i++){
			strBuilder1.append("*");
			strBuilder2.append(strBuilder1+"\n");
		}
		System.out.println(strBuilder2);
	}
}