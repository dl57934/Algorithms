import java.io.*;

class Main{
	private static int N;

	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		int arr[] = new int[1000002];
		N = Integer.parseInt(bfr.readLine());
		
		for(int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(bfr.readLine());

		quickSort(arr);
		printArray(arr);
	}

	private static void printArray(int arr[]){
		for(int i = 0; i < N; i++)
			System.out.println(arr[i]);
	}

	private static void quickSort(int arr[]){
		quickSort(arr, 0, N-1);
	}

	private static void quickSort(int arr[], int start, int end){
		int part2 = partition(arr, start, end);
		if(start < part2-1)
			quickSort(arr, start, part2-1);
		if(end > part2)
			quickSort(arr, part2, end);
	}

	private static int partition(int arr[], int start, int end){
		int pivot = arr[(start+end)/2];

		while(start<=end){
			while(arr[start]<pivot) start++;
			while(arr[end]>pivot) end--;
			if(start<=end){
				swap(arr, start, end);
				start++;
				end--;
			}
		}
		return start;
	}

	public static void swap(int arr[], int start, int end){
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
	}
}