import java.util.Scanner;

class Main{
	public static void main(String[] args){
		Scanner scn = new Scanner(System.in);
		int A = scn.nextInt();
		int B = scn.nextInt();
		System.out.println((A+B)+"\n"+(A-B)+"\n"+(A*B)+"\n"+(A/B)+"\n"+(A%B));
	}
}