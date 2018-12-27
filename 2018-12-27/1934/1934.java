import java.io.*;

class Main {
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(bfr.readLine());
		
		StringBuilder strBuilder = new StringBuilder();
		int temp = 0;
		for(int i = 0; i < T; i ++){
			String[] AB = bfr.readLine().split(" ");
			int A = Integer.parseInt(AB[0]);
			int B = Integer.parseInt(AB[1]);
			if( A > B){
				temp = A;
				A = B;
				B = temp;
			}
			strBuilder.append(LCM(A, B, GSD(A, B)).toString()).append("\n");
		}
		System.out.println(strBuilder);
	}

	public static Integer LCM(int A, int B, int GSD){
		return (A*B)/GSD;
	}

	public static int GSD(int A, int B){
		if(B==0)
			return A;
		return GSD(B, A%B);
	}

}