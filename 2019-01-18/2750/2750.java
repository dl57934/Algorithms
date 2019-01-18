import java.io.*;

class Main{
	static int [] arr = new int[1003];
	public static void main(String[] args) throws Exception{
		BufferedReader bfrReader = new BufferedReader(new InputStreamReader(System.in));
		int N = strToInt(bfrReader.readLine());
		input(N, bfrReader);
		mergeSort(0, N-1);
		output(N);
	}

	public static void output(int N){
		for(int i = 0; i < N; i++)
			System.out.println(arr[i]);
	}

	public static void mergeSort(int start,int end){
		if (start < end){
			int mid = (start+end)/2;
			mergeSort(start, mid);
			mergeSort(mid+1, end);
			merge(start, mid, end);
		}
	}

	public static void merge(int start, int mid, int end){
		int part1 = start, part2 = mid+1;
		int index = start; 
		int []temp = new int[1003];
		for(int i = start; i <= end; i++)
			temp[i] = arr[i];

		while(part1 <= mid && part2 <= end ){
			if(temp[part1] < temp[part2]){
				arr[index] = temp[part1];
				part1++;
			}else{
				arr[index] = temp[part2];
				part2++;
			}
			index++;
		}

		for(int i = 0; i <= mid-part1; i++)
			arr[i+index] = temp[part1+i];
	}

	public static void input(int N, BufferedReader bfrReader) throws Exception{
		for(int i =0; i < N; i++)
			arr[i] = strToInt(bfrReader.readLine());
	}

	public static int strToInt(String str){
		return Integer.parseInt(str);
	}
}
