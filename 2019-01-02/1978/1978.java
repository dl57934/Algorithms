import java.io.*;

class Main{
	static int count = 0;

	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(bfr.readLine());
		int[] numbers = new int[N];
		String[] strNumbers = bfr.readLine().split(" ");
		strToInt(strNumbers, numbers);
		estoras(numbers);
		System.out.println(count);
	}

	private static void estoras(int num[]){
		for(int i = 0; i < num.length; i++)
			if(num[i] != 1)
				estoras(num[i]);		
	}

	private static void estoras(int num){
		for(int i =2; i <= Math.sqrt(num); i++){
			if(num%i==0){
				return ;
			}
		}
		count++;
	}

	private static void strToInt(String[] str, int[] num){
		for(int i = 0; i < str.length; i++)
			num[i] = Integer.parseInt(str[i]);
	}
}