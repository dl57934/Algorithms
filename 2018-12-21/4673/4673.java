import java.io.*;
import java.util.*;
class Main{
	public static void main(String[] args) throws Exception{
		BufferedWriter bfw = new BufferedWriter(new OutputStreamWriter(System.out));
		int[] selfNumber = new int[10039];
		int tou, hun, ten, one, all;
		for (int i = 1;i<9994;i++){	
			all = i;
			tou = all/1000;
			all -= tou*1000;
			hun = all/100;
			all -= hun*100;
			ten = all/10;
			one = all%10;
			selfNumber[i+tou+hun+ten+one] = 1;
		}

		for (Integer i = 1; i<10000;i++){
				if(selfNumber[i] == 0){
					System.out.println(i);
				}
		}
	}
}