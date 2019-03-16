import java.io.*;

class Main{
	static int min = 30000;
	static int small = 0;
	static int big = 0;

	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		int N = strToInt(bfr.readLine());

		for(int i = 0; i < N; i++){
			int num = strToInt(bfr.readLine());
			goldBus(num);
			System.out.println(small+ " "+ big);
			init();
		}
	}

	public static void init(){
		small = 0;
		big = 0;
		min = 30000;
	}

	public static int strToInt(String str){
		return Integer.parseInt(str);
	}

	public static void goldBus(int num){
		for(int i = 2; i <= num/2; i++){
			if(isPrimeNumber(i, num-i)){
				if(min > num - 2*i){
					min = num - 2*i;
					small = i;
					big = num-i;
				}
			}
		}
	}

	public static boolean isPrimeNumber(int small, int big){
		return astoras(small) & astoras(big);
	}

	public static boolean astoras(int num){
		for(int i = 2; i <= Math.sqrt(num); i++){
			if(num % i ==0)
				return false;
		}
		return true;
	}
}