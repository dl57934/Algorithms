import java.io.*;

class Main{
	static int count = 0;
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		for(;;){
			int number = Integer.parseInt(bfr.readLine());
			if(number == 0)break;

			estorasEntance(number);
		}
	}

	private static void estorasEntance(int num){
		for(int i = num+1; i <= 2*num; i++)
			estoras(i);
		System.out.println(count);
		count=0;
	}

	private static void estoras(int num){
		for(int i = 2; i <= Math.sqrt(num); i++){
			if(num % i== 0)
				return ;
		}
		count+=1;
	}
}