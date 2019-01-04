import java.util.*;
import java.io.*;

class Main{
	private static Stack <String> stack = new Stack<String>();
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(bfr.readLine());

		for(int i = 0; i < T; i++){
			push(bfr.readLine());

			if(isVPS())
				System.out.println("YES");
			else
				System.out.println("NO");

			stack.clear();
		}
	}

	private static void push(String ps){
		for(int i = 0; i < ps.length(); i++)
			stack.push(ps.charAt(i)+"");
	}

	private static Boolean isVPS(){
		char[] ps = new char[52];
		int index = 0;

		while(!stack.empty()){
			
			if(stack.peek().equals("(")){
				if(isNegative(index) || ps[index-1] == '(')
					return false;
				else if(ps[index-1] == ')'){
					index = leftBracket(ps, index);
				}
			}else{
				index = rightBracket(ps, index);
			}
		}
		if(ps[0] == '(' ||ps[0] == ')')
			return false;
		return true;
	}

	private static Boolean isNegative(int index){
		return index-1 < 0;
	}

	private static int leftBracket(char[] ps,int index){
		ps[index-1] = '\0';
		pop();
		index-=1;
		return index;
	}

	private static int rightBracket(char[] ps, int index){
		ps[index] = stack.peek().charAt(0);
		pop();
		index+=1;
		return index;
	}

	private static void pop(){
		stack.pop();
	}

}