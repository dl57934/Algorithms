import java.util.*;
import java.io.*;

class Main{
	static Stack<Integer> stack = new Stack<Integer>(); 

	final static String PUSH = "push";
	final static String POP = "pop";
	final static String EMPTY = "empty";
	final static String TOP = "top";
	final static String SIZE = "size";

	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(bfr.readLine());

		for(int i = 0; i < N; i++){
			String[] command = bfr.readLine().split(" ");

			if(command[0].equals(PUSH))
				push(Integer.parseInt(command[1]));

			else if(command[0].equals(POP) || command[0].equals(TOP)){
				if(isEmpty())
					printResult(-1);
				else{
					printResult(peek());
					if(command[0].equals(POP))
						pop();
				}
			}

			else if(command[0].equals(EMPTY)){
				if(isEmpty())
					printResult(1);
				else
					printResult(0);
			}

			else if(command[0].equals(SIZE))
				printResult(size());
			
			
		}
	}

	private static int peek(){
		return stack.peek();
	}

	private static Boolean isEmpty(){
		return stack.empty();
	}

	private static int getSize(){
		return stack.size();
	}

	private static void printResult(int num){
		System.out.println(num);
	}

	private static void push(int num){
		stack.push(num);
	}

	private static int pop(){
		stack.pop();
	}
}