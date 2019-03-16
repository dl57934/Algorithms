import java.io.*;

class Main{
	private static String numbers;
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		numbers = bfr.readLine();
		StringBuilder strBuilder = new StringBuilder().append(numbers);
		quickSort(strBuilder);
		System.out.println(strBuilder);
	}

	private static void quickSort(StringBuilder str){
		quickSort(str, 0, numbers.length()-1);
	}

	private static void quickSort(StringBuilder str, int start, int end){
		int part2 = partition(str, start, end);

		if(start < part2-1)
			quickSort(str, start, part2-1);
		if(part2 < end)
			quickSort(str, part2, end);
	}

	public static int partition(StringBuilder str, int start, int end){
		char pivot = str.charAt((start+end)/2);

		while(start <= end){
			while(pivot < str.charAt(start))start++;
			while(pivot > str.charAt(end))end--;
			if(start<=end){
				swap(str, start, end);
				start++; end--;
			}
		}
		return start;
	}

	private static void swap(StringBuilder str, int start, int end){
		char temp = str.charAt(start);
		str.setCharAt(start, str.charAt(end));
		str.setCharAt(end, temp);
	}

}