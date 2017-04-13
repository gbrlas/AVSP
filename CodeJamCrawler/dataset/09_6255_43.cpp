import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Collection;


public class AlienLanguage {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		
		BufferedReader r = new BufferedReader (new InputStreamReader(AlienLanguage.class.getResourceAsStream("/in")));
		String input = r.readLine();
		String[] a = input.trim().split(" ");
		int l = Integer.valueOf(a[0]);
		int d = Integer.valueOf(a[1]);
		int n = Integer.valueOf(a[2]);
		String[] inps = new String[d];
		for (int i=0;i<d;i++){
			inps[i] = r.readLine();
		}
		String[] pats = new String[n];
		for (int i=0;i<n;i++){
			pats[i] = r.readLine();
			pats[i]=pats[i].replace('(', '[').replace(')', ']');
		}
		r.close();
		//System.out.println(Arrays.asList(inps));
		//System.out.println(Arrays.asList(pats));
		int[] result = new int[n];
		for (int i=0;i<n;i++){
			for (int j=0;j<d;j++){
				if (inps[j].matches(pats[i])){
					result[i]++;
				}
			}
		}
		BufferedWriter w = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File("out"))));
		for (int i=0;i<n;i++){
			w.write("Case #"+(i+1)+": "+result[i]+"\n");
		}
		w.close();

	}

}
