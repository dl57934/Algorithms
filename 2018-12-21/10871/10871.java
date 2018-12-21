import java.io.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		String[] info = bfr.readLine().split(" ");
		StringBuilder strBuilder = new StringBuilder();

		int N = Integer.parseInt(info[0]);
		int X = Integer.parseInt(info[1]);
		String[] numbers = bfr.readLine().split(" ");
		int [] result = new int[N];
		int count = 0;
		for(int i =0; i <N; i++){
			if( X > Integer.parseInt(numbers[i])){
				strBuilder.append(numbers[i]).append(" ");
			}
		}
		System.out.println(strBuilder);
	}
}