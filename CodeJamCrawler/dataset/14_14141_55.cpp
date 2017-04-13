import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		FileWriter fw = new FileWriter("out.txt");

		Scanner scan = new Scanner(new File("test.txt"));
		BufferedWriter bw = new BufferedWriter(fw);
		
		int test_case =0 ;
		
		int sub_case =0;
		

		
		test_case = scan.nextInt();
		
		for(int i=0; i<test_case; i++){
			
			sub_case = scan.nextInt();
			
			double[] naomi = new double[sub_case];
			double[] ken = new double[sub_case];
			
			for(int j=0; j<sub_case; j++){
				naomi[j] = scan.nextDouble();
				//System.out.println(naomi[j]);
			}
			
			for(int j=0; j<sub_case; j++){
				ken[j] = scan.nextDouble();
				//System.out.println(ken[j]);
			}
			
			Arrays.sort(naomi);
			Arrays.sort(ken);
			
			int dw =0;
			int ow =0;
			
			//naomi min > ken max
			if(naomi[0] > ken[sub_case-1]){
				dw = sub_case;
				ow = sub_case;
			}else if(naomi[sub_case-1] < ken[0]){ // naomi max < ken min
				dw =0;
				ow =0;
			}else{
				
				//org
				for(int j=sub_case-1,kt=sub_case-1; j>=0; j--){
					if(naomi[j]>ken[kt]){
						ow++;
					}else {
						kt--;
					}
				}
				
				//dec
				for(int j=sub_case-1,kt=sub_case-1; j>=0; j--){
					if(naomi[kt]>ken[j]){
						dw++;
						kt--;
					}
				}
			}
				
					
			int no = i+1;
			
			
			System.out.println("Case #" + no + ": " + dw + " " + ow + "\n");
			bw.write("Case #" + no + ": " + dw + " " + ow + "\n");
			 

		}
		
		 bw.close();

		
		
	}

	/* (non-Java-doc)
	 * @see java.lang.Object#Object()
	 */
	public Main() {
		super();
	}

}