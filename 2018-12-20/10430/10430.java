import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Main{
	public static void main(String[] args) throws Exception{
		// 입력 기능 만들어주기
		BufferedReader inputData = new BufferedReader(new InputStreamReader(System.in));
		String[] i = inputData.readLine().split(" ");

		//문자열 데이터 숫자로 바꿔주기
		int A = Integer.parseInt(i[0]);

		int B = Integer.parseInt(i[1]);

		int C = Integer.parseInt(i[2]);

		// 계산하기
		int result1 = (A+B)%C;
		int result2 = (A*B)%C;

		//출력하
		System.out.println(result1);
		System.out.println(result1);
		System.out.println(result2);
		System.out.println(result2);
	}
}