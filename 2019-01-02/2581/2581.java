import java .io.*;


class Main{
	static int sum = 0;
	static int min = 10001;

	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		
		int M = Integer.parseInt(bfr.readLine());
		int N = Integer.parseInt(bfr.readLine());
		for(int i = M; i <= N; i++){
			if(i != 1){
				if(estoras(i)){
					if(min > i)
						min = i;
				}
			}
		}

		printResult();
	}

	private static void printResult(){
		if(sum == 0)
			System.out.println("-1");
		else 
			System.out.printf("%d\n%d", sum, min);
	}

	private static boolean estoras(int number){
		for(int i = 2; i <= Math.sqrt(number); i++){
			if(number % i == 0){
				return false;
			}
		}
		sum += number;
		return true;
	}
	
}