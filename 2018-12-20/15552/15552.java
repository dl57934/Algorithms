import java.io.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bfw = new BufferedWriter( new OutputStreamWriter( System.out ) );
		int N =  Integer.parseInt(bfr.readLine());
		String [] splitNumber;
        Integer result;
		for(int i = 0; i<N;i++){
			bfw.flush();
			splitNumber = bfr.readLine().split(" ");
            result = Integer.parseInt(splitNumber[0])+Integer.parseInt(splitNumber[1]);
			bfw.write(result.toString());
            bfw.newLine();
		}
		bfw.close();
		bfr.close();
	}
}