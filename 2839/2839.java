import java.io.*;

class Main{
	public static void main(String[] args) throws Exception{
		// 입력
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		int nKgSugar = Integer.parseInt(line);
		int result ;

		// 나머지 별 뺴주어야하는 kg setting
		int[] minusPerReminder = new int[]{0, 6, 12, 3, 9};	

		//얼마나 많은 3kg을 빼주아야 하는지 결정하는 5kg을 나눈 나머지
		int KgReminder = nKgSugar % 5;
		nKgSugar -= minusPerReminder[KgReminder];

		// 숫자가 맞아 떨어지지 않을 때
		if(nKgSugar < 0)
			result = -1;
        else 
		result = nKgSugar / 5 + minusPerReminder[KgReminder] / 3; 
		
		System.out.println(result);
	}
}