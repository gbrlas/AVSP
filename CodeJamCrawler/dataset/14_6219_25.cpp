import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class CookieClicker {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader inputStream = null;
        PrintWriter outputStream = null;

        try {
            inputStream = new BufferedReader(new FileReader("C:\\Users\\Maheshwaran\\Downloads\\CodeJam\\B-small-attempt0.in"));
            outputStream = new PrintWriter(new FileWriter("C:\\Users\\Maheshwaran\\Downloads\\CodeJam\\output2.txt"));

            
            String num = inputStream.readLine();
            //System.out.println("Number of test cases "+num);
           // System.out.println(num);
            for(int i=1;i<Integer.valueOf(num)+1;i++)
            {
            	
            	String l[]=inputStream.readLine().split(" ");
            	double c=Double.parseDouble(l[0]);
            	double f=Double.parseDouble(l[1]);
            	double x=Double.parseDouble(l[2]);
            	double s=2;
            	
            	double l1=x/s;
            	double t=c/s;
            	double l2=t+(x/(s+f));
            	while(l2<l1)
            	{
            		l1=l2;
            		s+=f;
            		t=t+(c/s);
            		l2=t+(x/(s+f));
            	}
            	outputStream.write("Case #"+i+": "+l1+"\n");
            	
            	
            }
            inputStream.close();
            outputStream.close();
        } catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
