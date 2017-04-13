import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class RPI {
public static void main(String args[]){
		
		try {
			FileReader fin = new FileReader(
					new File("C:\\Users\\Subir Kumar Sao\\Desktop\\Sample\\A-Small-in.txt"));
			FileWriter fr = new FileWriter(new File("C:\\Users\\Subir Kumar Sao\\Desktop\\Sample\\A-Small-out.txt"));
			BufferedReader br = new BufferedReader(fin);
			String line = br.readLine();
			int N = Integer.parseInt(line);
			
			
			for(int i=0;i<N;i++){
				line = br.readLine();
				int c = Integer.parseInt(line);
				String[] plan = new String[c];
				for(int j=0;j<c;j++){
					plan[j] = br.readLine();
				}
				double[] wp = new double[c];
				double[] owp = new double[c];
				double[] oowp = new double[c];
				for(int k =0 ;k<c;k++){
					double wins = 0d;
					double plays = 0d;
					for(int l=0;l<plan[k].length();l++){
						char cur = plan[k].charAt(l);
						if(cur!='.'){
							plays++;
							if(cur=='1'){
								wins++;
							}
						}
					}
					wp[k] = wins/plays;
					double otwp=0f;
					int opts=0;
					for(int m=0;m<c;m++)
					{
					
						if(m!=k && plan[m].charAt(k)!='.')
						{
							opts++;
							double winst = 0d;
							double playst = 0d;
							for(int l=0;l<plan[m].length();l++){
								char cur = plan[m].charAt(l);
								if(l!=k && cur!='.'){
									playst++;
									if(cur=='1'){
										winst++;
									}
								}
							}
							otwp += winst/playst;
						}
					}
					owp[k] = otwp/(opts);
					
				}
				for(int n=0;n<c;n++){
					double oowpt = 0d;
					int opnt = 0;
					for(int p=0;p<c;p++){
						if(p!=n && plan[p].charAt(n)!='.' ){
							oowpt+= owp[p];
							opnt++;
						}
					}
					oowp[n] = oowpt/(opnt);
					
					System.out.println((0.25d * wp[n])+(0.50d*owp[n])+(0.25d*oowp[n]));
				}
				for(int j=0;j<wp.length;j++)
					System.out.print(wp[j]+" ");
				System.out.println();
				for(int j=0;j<owp.length;j++)
					System.out.print(owp[j]+" ");
				System.out.println();
				for(int j=0;j<oowp.length;j++)
					System.out.print(oowp[j]+" ");
				System.out.println();
				
			}
			fr.close();
			fin.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}
}
