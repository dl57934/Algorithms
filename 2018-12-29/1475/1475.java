import java.io.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		String N = bfr.readLine();
		int result = setSetNumber(N);
		System.out.println(result);
	}
	public static int setSetNumber(String N){
		int [] usingNumber = new int[10];
		for(int i = 0; i < NLength(N); i++)
			usingNumber[toNumber(N.charAt(i))]+=1;

		return getMax(usingNumber);
	}

	public static int NLength(String N){
		return N.length();
	}

	public static int toNumber(char number){
		return number - '0';
	}	

	public static int getMax(int[] usingNumber){
		int max = 0;
		int nineSix = uniteSixNine(usingNumber);
		usingNumber[6] = nineSix;

		for(int i = 0; i < 9; i++)
			if(max < usingNumber[i])
				max = usingNumber[i];
		return max;	
	}

	public static int  uniteSixNine(int[] usingNumber){
		int nineSix = usingNumber[6] + usingNumber[9];
		return nineSix/2 + nineSix%2;
	}
	
}