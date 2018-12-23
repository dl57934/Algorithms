import java.io.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		String[] AB = bfr.readLine().split(" ");

		int newA = AB[0].charAt(0)-'0' + 
(AB[0].charAt(1)-'0')*10 + (AB[0].charAt(2)-'0')*100;

		int newB = AB[1].charAt(0)-'0' + 
		(AB[1].charAt(1)-'0')*10 + (AB[1].charAt(2)-'0')*100;

		if(newA > newB)
			System.out.println(newA);
		else
			System.out.println(newB);
	}
}