import java.util.Scanner;

class Main {
	public static void main(String[] args) throws Exception {
		Scanner scn = new Scanner(System.in);
		String AB = scn.nextLine();
		String[] ABarray = AB.split(" ");
		System.out.println(ABarray);
		System.out.println(Integer.parseInt(ABarray[0]) - Integer.parseInt(ABarray[1]));
		scn.close();
	}
}
