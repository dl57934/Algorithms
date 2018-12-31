import java.io.*;

class Main{
	private static int bubbleArr[] = new int[1002];
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(bfr.readLine());

		for(int i = 0; i < N; i++)
 			bubbleArr[i] = Integer.parseInt(bfr.readLine());
 		bubbleSort(N);
 		for(int i = 0; i < N; i++)
 			System.out.println(bubbleArr[i]);

	}

	public static void bubbleSort(int N){
		for(int i = 0; i < N; i++){
			for(int j = i+1; j < N; j++)
				if(bubbleArr[i] > bubbleArr[j])
					reverseNumber(i, j);
		}
	}
	public static void reverseNumber(int i, int j){
		int temp;
		temp = bubbleArr[i];
		bubbleArr[i] = bubbleArr[j];
		bubbleArr[j] = temp;
	}
}