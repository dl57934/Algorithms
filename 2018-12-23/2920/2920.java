import java.io.*;

class Main{
	public static void main(String[] args) throws Exception {
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in)); 
		String arr[] = bfr.readLine().split(" ");
		String result ="";
		for(int i = 0; i<7; i++){
			if(toInt(arr[i])+1 == toInt(arr[i+1]))
				result = "ascending";
			else if(toInt(arr[i]) == toInt(arr[i+1])+1)
				result = "descending";
			else {
				result = "mixed";
				break;
			}
		}
		System.out.println(result);
	}
	static int toInt(String data){
		return Integer.parseInt(data);
	}
}