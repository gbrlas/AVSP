import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;


public class C {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		String output = "";

		File fileMap = new File("C-small-attempt0.in");
		BufferedReader reader = null;
		try {
			reader = new BufferedReader(new FileReader(fileMap));
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		int T, A, B, count;
		Double sqrt_ = null;
		String s1;
		boolean palindrom;
			try {
				try {
					T = Integer.parseInt(reader.readLine());
					for (int t=1; t<=T; t++) {
						
						// read
						String[] text = reader.readLine().split(" ");
						A = Integer.parseInt(text[0]);
						B = Integer.parseInt(text[1]);
						count = 0;
						
						for (int i=A; i<=B; i++) {		
							
							sqrt_ = Math.sqrt(i);
							
							if ((sqrt_ == Math.floor(sqrt_))) {
								
								s1 = ((Integer) i).toString();
								palindrom = true;
								
								for (int k=0; k<s1.length()/2; k++) {
									if (s1.charAt(k) != s1.charAt(s1.length()-k-1)) {
										palindrom = false;
										break;
									}										
								}
								
								if (palindrom) {
									s1 = ((Integer) sqrt_.intValue()).toString();
									for (int k=0; k<s1.length()/2; k++) {
										if (s1.charAt(k) != s1.charAt(s1.length()-k-1)) {
											palindrom = false;
											break;
										}											
									}
									if (palindrom)
										count++;
								}

							}
						}
						output = output + "Case #" + t + ": " + count + "\r\n";
					}
				}
				finally {
					// close
					reader.close();
				}
			}
			catch (IOException e) {
				System.err.println("Error while reading data file");
				e.printStackTrace();
			}
			System.out.println(output);

	}

}
