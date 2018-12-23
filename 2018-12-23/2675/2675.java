import java.io.*;

class Main{
	public static void main(String[] args)throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(bfr.readLine());
		String[] str;
		int R;
		StringBuilder strBuilder = new StringBuilder();
		for(int i = 0; i < T;i++){
			str = bfr.readLine().split(" ");
			R = Integer.parseInt(str[0]);
			for(int j = 0; j< str[1].length(); j++){
				for(int r = 0; r < R; r++)
					strBuilder.append(str[1].charAt(j));
			}
			strBuilder.append("\n");
		}
		System.out.print(strBuilder);
	}
}