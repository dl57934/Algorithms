import java.io.*;

class Main{
	private static char[] box = new char[32];
	private static int result = 0, appendNumber = 0;
	private static int canAppend = 1, pushIndex = 0;
	public static void main(String[] args) throws Exception{
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
		String inputValue = bfr.readLine();
		push(inputValue);
	}

	private static void push(String values){
		for(int i = 0; i < values.length(); i++){
			if(!isRightBrucket(values.charAt(i))){
				box[pushIndex] = values.charAt(i);
			}
			if(calculate(values.charAt(i)) == 0)
				break;	
		}

		if(box[0] != '\0')
			System.out.println(0);
		else
			System.out.println(result);
	}

	private static int calculate(char brucket){
		if(appendNumber == 0){
			init();
			if(brucket == '[')
				appendNumber = 3;
			else if(brucket == '(')
				appendNumber = 2;
		}else{
			if(isLeftBrucket(brucket)){
				leftBrucket(brucket);
			}else if(isRightBrucket(brucket)){
				 if(rightBrucket(brucket) == 0)
				 	return 0;
			}
		}
		return 1;
	}

	public static void init(){
		canAppend = 1;
		pushIndex+=1;
	}

	private static Boolean isLeftBrucket(char brucket){
		return brucket == '[' || brucket =='(';
	}

	private static Boolean isRightBrucket(char brucket){
		return brucket == ']' || brucket ==')';
	}

	private static void leftBrucket(char brucket){
		init();
		if(brucket == '[')
			appendNumber*=3;
		else 
			appendNumber*=2;
	}
	
	private static int rightBrucket(char brucket){
		if(isWrongBrucket(brucket)){
			if(canAppend==1)
			result += appendNumber;
			
			pushIndex-=1;
			box[pushIndex ] = '\0';
			
			devideBrucket(brucket);

			if(appendNumber==1)
				appendNumber = 0;

			canAppend = 0;
			return 1;
		}
		else {
			result = 0;
			return 0;
		}
	}

	private static void devideBrucket(char brucket){
		if(brucket == ']')
			appendNumber/=3;
		else
			appendNumber/=2;
	}

	private static Boolean isWrongBrucket(char brucket){
		if(brucket == ']' && box[pushIndex - 1] == '[')
			return true;
		else if(brucket == ')' && box[pushIndex - 1] == '(')	
			return true;
		
		return false;
		
	}
}