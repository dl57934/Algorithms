import java.io.*;
import java.util.Arrays;

class Main{
	static int count = 0;
	public static void main(String[] args)throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(bfr.readLine());
		String[] words = new String[N];
		
		input(N, bfr, words);

		mergeSort(words);
		
		printArray(words);
	}

	private static void input(int N, BufferedReader bfr, String[] words) throws Exception{
		String word;
		for(int i = 0; i < N; i++){
			word = bfr.readLine();
			if(!Arrays.asList(words).contains(word)){
				words[count] = word;
				count++;
			}			
		}
	}

	private static void mergeSort(String[] arr){
		String[] temp = new String[count];
		mergeSort(arr, temp, 0, count-1);
	}

	private static void mergeSort(String arr[], String temp[], int start, int end){
		if(start < end){
			int mid = (start+end)/2;
			mergeSort(arr, temp, start, mid);
			mergeSort(arr, temp, mid+1, end);
			lengthMerge(arr, temp, start, mid, end);
		}
	}

	private static void lengthMerge(String arr[], String temp[], int start, int mid, int end){
		for(int i = start; i <= end; i++)
			temp[i] = arr[i];
		int part1 = start;
		int index = start;
		int part2 = mid+1;

		while(part1<=mid && part2<=end){
			if(temp[part1].length() < temp[part2].length()){
				arr[index] = temp[part1];
				part1++;
			}else if(temp[part1].length() == temp[part2].length()){
				if(temp[part2].compareTo(temp[part1]) >= 0){
					arr[index] = temp[part1];
					part1++;
				}else{
					arr[index] = temp[part2];
					part2++;
				}
			}else{
				arr[index] = temp[part2];
				part2++;
			}
			index++;
		}

		for(int i = 0; i <= mid-part1; i++)
			arr[index+i] = temp[part1+i];
	}

	private static void printArray(String[] words){
		for(int i = 0; i < count; i++)
			System.out.println(words[i]);
	}
}