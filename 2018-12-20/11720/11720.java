// 내코드
import java.io.*;

class Main{
	public static void main(String[] args) throws Exception {
		//입력
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		String strN = bfr.readLine();
		int result = 0;
		int N = Integer.parseInt(strN);
		String intLine = bfr.readLine();

		// 출력별 횟수 적기
		int[] arr = new int[10];
		
		// 출력별 배열 값 넣기
		for (int i = 0; i<N; i++){
			int index = Character.getNumericValue(intLine.charAt(i));
			arr[index] +=1;
		}

		for (int i =1;i<10;i++)
			result += arr[i] * i;
		System.out.print(result);	 
	}
}

// 1등 코드 
// 배운점 읽어온 줄을 모두 배열로 만드는 방법이 있는 것
// char형은 -> String.valueOf()를 통해서 String으로 바꿀 수 있는 것

import java.io.*;

class Main{
	public static void main(String[] args) throws Exception {
		//입력
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		String strN = bfr.readLine();
		int N = Integer.parseInt(strN);
		char[] charLine = bfr.readLine().toCharArray();
		int total = 0;
		
		for (int i = 0; i < N; i++){
			total += Integer.parseInt(String.valueOf(charLine[i]));
		} 
		System.out.println(total);
	}
}
