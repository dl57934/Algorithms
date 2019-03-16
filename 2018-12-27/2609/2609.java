import java.io.*;

class Main{	
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));

		String[] AB = bfr.readLine().split(" ");
		int A = Integer.parseInt(AB[0]);
		int B = Integer.parseInt(AB[1]);

		if(A < B){
			changeNumber(A, B);
		}

		int gsd = GSD(A, B);

		System.out.println(gsd);
		System.out.println(LCM(A,B,gsd));
	}

	private static void changeNumber(int A, int B){
		int temp;
		temp = A;
		A = B;
		B = temp;
	}

	private static int GSD(int A, int B){
		if(B==0)
			return A;
		return GSD(B, A%B);
	}

	private static int LCM(int A, int B, int GSD){
		return (A*B)/GSD;
	}
}