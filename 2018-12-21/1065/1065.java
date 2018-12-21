import java.io.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(bfr.readLine());
		System.out.println(getOneNumber(N));

	}

	static int getOneNumber(int N){
		int count = 0;
		int ten =0,one=0, hun=0;
		int replaceNumber=0;
		for (int i = 1;i<=N;i++){
			replaceNumber = i;
			if(i<100)
				count+=1;
			else {
				replaceNumber = i;
				hun = replaceNumber/100;
				replaceNumber-=hun*100;
				ten = replaceNumber/10;
				one = replaceNumber%10;
				if(hun-ten==ten-one)
					count+=1;
			}
		}
		return count;
	}
}