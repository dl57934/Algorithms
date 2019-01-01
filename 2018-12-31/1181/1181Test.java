import java.util.Arrays;

class Main{
	public static void main(String[] args){
		String hihi =  "hihi";
		String hi = "hi";
		String[] hi2 = {
			"hihi",
			"to"
		};
		if(Arrays.asList(hi2).contains(hihi))
			System.out.println(hihi);
		else 
			System.out.println(hi);
	}
}