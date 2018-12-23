import java.io.*;

class Main{
	public static void  main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(bfr.readLine());
		String OX;
		int last = 0;
		int []result = new int[1000];
		for(int i = 0; i < N; i++){
			result[i]=0;
			last=0;
			OX = bfr.readLine();
			for (int j = 0; j < OX.length(); j++){
				if(OX.charAt(j) == 'X')
					last=0;
				else {
					last+=1;
					result[i]+=last;
				}
			}
		}
		for(int i = 0;i < N; i++)
			System.out.println(result[i]);
	}
}