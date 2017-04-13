import java.util.*;
import java.io.*;

public class FairAndSquare {

	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);
		int numbers = input.nextInt();
//		System.out.println("number of tests: " + numbers);
		double squaredNumber;
		String palandrome;
		String squaredPalandrome;
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		for (int i = 1; i <= numbers; i++) {
//			System.out.println("in loop");
//			Scanner input = new Scanner(System.in);
			int count = 0;
//			System.out.println(input);
			int start = input.nextInt();
//			System.out.println("start : " + start);
			int end = input.nextInt();
//			System.out.println("end :"+ end);
			char[] one;
			char[] two;
			boolean isEquals = false;
			boolean squaredEquals = false;
			while (start <= end) {
//			System.out.println("in while");
				if (end > 1000) {
					break;
				}
				squaredNumber =  Math.sqrt(start);
				if(squaredNumber % (int) squaredNumber == 0){
					int squaredNumberInt = (int) squaredNumber;
					squaredPalandrome = String.valueOf(squaredNumberInt);
//					System.out.println("squared number" + squaredNumberInt);
				}
				else{
					squaredPalandrome = String.valueOf(squaredNumber);
				}
//				System.out.println("sqrt : " + squaredNumber);
				palandrome = String.valueOf(start);
				one = palandrome.toCharArray();
//				System.out.println(one);
				two = squaredPalandrome.toCharArray();
//				System.out.println(two);
				for (int x = 0; x < one.length; x++) {
//					System.out.println("testing start :" + one[x]);
//					System.out.println("testing last number :" + one[one.length -(x+1)]);
					if (one[x] == one[one.length -(x+1)]) {
//						System.out.println("truth");
						isEquals = true;	
					} else {
						isEquals = false;
						break;
					}
				}
				for (int z = 0; z < two.length; z++) {
//					System.out.println("testing start 2:" + one[z]);
//					System.out.println("testing last number 2:" + one[one.length -(z+1)]);
					if (two[z] == two[two.length - (z+1)]) {
//					System.out.println("truth 2");
						squaredEquals = true;
					} 
					else{
						squaredEquals = false;
						break;
					}
				
				}
				if(isEquals && squaredEquals){
					count+=1;
//					System.out.println("equal");
				}
				start++;
			}
//			System.out.println("Case #" + i + ": " + count + "\n");
			out.append("Case #" + i + ": " + count + "\n");
		}
		out.flush();
	}

	

}
