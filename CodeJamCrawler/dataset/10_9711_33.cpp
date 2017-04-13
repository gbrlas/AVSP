/**
 *
 * @author ecasas
 */
import java.io.*;
public class SnapperChain {

	public static BufferedReader sin= new BufferedReader(new InputStreamReader(System.in));
	public static PrintWriter sout= new PrintWriter(System.out, true);

	public static void main(String[] args) throws Exception{
		String line= sin.readLine();
		int t= Integer.parseInt(line);
		String arr[];
                char arr2[];
		int n, k;
                boolean band;
		for(int i= 1; i<= t; i++){
			line= sin.readLine();
			arr= line.split(" ");
			n= Integer.parseInt(arr[0]);
			k= Integer.parseInt(arr[1]);
                        //sout.println(n + "  " + k + ": " + Integer.toBinaryString(k));
                        arr2= ("0" + Integer.toBinaryString(k)).toCharArray();
                        //sout.println(arr2);
                        band= true;

						
                        for(int j=0; j<n; j++){
                            if(arr2[arr2.length-j-1]=='0'){
                                sout.println("Case #" + i + ": OFF");
                                band=false;
                                break;
                            }
                        }
                        if(band){
                        	sout.println("Case #" + i + ": ON");
                            /*if(arr2[arr2.length-n-1]=='1')sout.println("Case #" + i + ": ON");
                            	else sout.println("Case #" + i + ": OFF");*/
                        }
		}
	}

}

