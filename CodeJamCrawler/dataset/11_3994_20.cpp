import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class FreeCellStatistics {

	public static String solve_test_case(String[] test_cases){
		
		BigInteger N = new BigInteger(test_cases[0]);
		int Pd = Integer.parseInt(test_cases[1]), Pg = Integer.parseInt(test_cases[2]);
		int minInt = 100;
		if (Pd==100 && Pg!=0) return "Possible";
		else if (Pd==100) return "Broken";
		if (Pg==100){
			return "Broken";
		}
		if (Pg==0){
			if (Pd==0) return "Possible";
			else return "Broken";
		}
		if (Pd%10==0){
			if ((Pd/10)%5==0){
				minInt = 2;
			}
			else if ((Pd/10)%2==0){
				minInt = 5;
			}
			else{
				minInt = 10;
			}
		}
		else{
			if (Pd%25==0){
				minInt = 4;
			}
			else if (Pd%5==0){
				minInt = 20;
			}
			else if (Pd%4==0){
				minInt = 25;
			}
			else if (Pd%2 == 0){
				minInt = 50;
			}
		}
		
		if (N.compareTo(new BigInteger(Integer.toString(minInt))) < 0) return "Broken";
		if (Pg == 100 && Pd != 100) return "Broken";
		if (Pd > 0 && Pg == 0) return "Broken";
		return "Possible";
		
		
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
