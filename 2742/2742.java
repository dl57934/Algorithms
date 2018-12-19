import java.io.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		br.close();
		int N = Integer.parseInt(line);
		// System.out.println으로 연속적으로 출력하는 것 보단 
		// Stringbuilder를 통해 넣어주는 것이 더 편하다. 
		StringBuilder strBuilder = new StringBuilder();
		for (int i = N;i>0;i--)
			strBuilder.append(i+"\n");
		System.out.println(strBuilder);
	}
}