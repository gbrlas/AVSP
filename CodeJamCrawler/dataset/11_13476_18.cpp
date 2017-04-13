import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class SquareTiles {
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
				String[] nums = line.split(" ");
				int rows = Integer.parseInt(nums[0]);
				int cols = Integer.parseInt(nums[1]);
				
				String[] mat= new String[rows];
				
				for(int j=0;j<rows;j++){
					mat[j]=br.readLine();
				}
				boolean possible = true;
				for(int j=0;j<rows;j++){
					for(int k=0;k<cols;k++){
						if(mat[j].charAt(k)=='#'){
							if(
									((k+1)<cols && mat[j].charAt(k+1)=='#')
									&& ((j+1)<rows && mat[j+1].charAt(k+1)=='#')
									&& ((j+1)<cols && mat[j+1].charAt(k)=='#') )
									{
										if(k==0){
											if((k+2)==cols)
											{
												mat[j] = "/\\";
												mat[j+1] = "\\/";
											}
											else{
												mat[j] = "/\\"+mat[j].substring(k+2);
												mat[j+1] = "\\/"+mat[j+1].substring(k+2);
											}
										}
										else{
											if((k+2)==cols){
												mat[j] = mat[j].substring(0, k) + "/\\";
												mat[j+1] = mat[j+1].substring(0, k) + "\\/";
											}
											else{
												mat[j] = mat[j].substring(0, k) + "/\\"+mat[j].substring(k+2);
												mat[j+1] = mat[j+1].substring(0, k) + "\\/"+mat[j+1].substring(k+2);
											}
										}
									}
							else{
								possible = false;
								break;
							}
						}
					}
					if(!possible){
						break;
					}
				}
				fr.write("Case #"+(i+1)+":\n");
				if(!possible){
					fr.write("Impossible\n");
					System.out.println("Impossible");
				}
				else{
					for(int j=0;j<rows;j++){
						fr.write(mat[j]+"\n");
						System.out.println(mat[j]);
					}
				}
				
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
