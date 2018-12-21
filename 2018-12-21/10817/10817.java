import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bfw = new BufferedWriter(new OutputStreamWriter( System.out ) );
		String[] score = bfr.readLine().split(" ");
		Integer[] intScore = new Integer[] {
			Integer.parseInt(score[0]),
			Integer.parseInt(score[1]),
			Integer.parseInt(score[2]) };
		Arrays.sort(intScore);
		bfw.write(intScore[1].toString());
		bfw.flush();
		bfw.close();
	}
}