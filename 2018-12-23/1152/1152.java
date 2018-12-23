import java.io.*;

class Main{
	public static void main(String[] args)throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		String words= bfr.readLine();
			words = words.trim();
		int count = 0;
		for(int i = 1;i < words.length(); i++){
			if(words.charAt(i) == ' ')
				count +=1;
		}
		if(words.equals(""))
			System.out.println(0);
		else
			System.out.println(count+1);
	}
}