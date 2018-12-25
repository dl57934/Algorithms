import java.util.Scanner;

class Main{
	public static void main(String[] args){
		Scanner scn = new Scanner(System.in);
		int A = scn.nextInt();
		int B = scn.nextInt();
		System.out.printf("%.9f", 1.0*A/B);
	}
}