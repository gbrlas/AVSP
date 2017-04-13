import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class CandySplitting {
	
	
	public static String solve_test_case(String[] test_cases){
		int xor = 0, min=999999, sum=0, number = 0;
		for (int i=0;i<test_cases.length;i++){
			number = Integer.parseInt(test_cases[i]);
			xor = (xor^number);
			if (min > number)
				min = number;
			sum += number;
		}
		if (xor!=0) return "NO";
		else return (sum-min)+"";
	}
	
	public static void main(String[] args) {


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i=0, T = 0;
		try {
			T = Integer.parseInt(br.readLine());
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		String[] soln_array = new String[T];
		for (i=0;i<T;i++){
			try {
				br.readLine();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			String []test_cases = null;
			try {
				test_cases = br.readLine().split(" ");
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			
			String soln = solve_test_case(test_cases);
			
			soln_array[i] = soln;
		}
		for (i=0;i<T;i++){
			System.out.print("Case #"+(i+1)+": "+soln_array[i]);
			System.out.println();
		}
		

	}

}
