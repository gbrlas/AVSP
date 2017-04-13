import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Lawnmower {
	public static void main(String[] args) {
		FileReader fin;
		try {
			fin = new FileReader(
					new File(
							"D:\\CodeJam\\B-small-attempt1.in"));

			FileWriter fr = new FileWriter(
					new File(
							"D:\\CodeJam\\B-small-out-1.txt"));
			BufferedReader br = new BufferedReader(fin);
			String line = br.readLine();
			int N = Integer.parseInt(line);
			for (int i = 0; i < N; i++) {
				line = br.readLine();
				String[] rc = line.split(" ");
				int r = Integer.parseInt(rc[0]);
				int c = Integer.parseInt(rc[1]);
				int[][] lawn=new int[r][c]; 
				for(int j=0;j<r;j++){
					line = br.readLine();
					String[] row = line.split(" ");
					for(int k=0;k<c;k++){
						lawn[j][k]=Integer.parseInt(row[k]);
					}
				}
				
				
				/*for(int k=0;k<lawn.length;k++){
					for(int j=0;j<lawn[0].length;j++){
						System.out.print(lawn[k][j]+"\t");
					}
					System.out.println();
				}
				System.out.println(compute(lawn));*/
				fr.write("Case #"+(i+1)+": "+compute(lawn)+"\r\n");
				
				
			}
			fr.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private static String compute(int[][] lawn) {
		
		for(int i=0;i<lawn.length;i++){
			for(int j=0;j<lawn[0].length;j++){
				boolean routeR=true,routeC=true;
				for(int k=0;k<lawn.length;k++){
					if(lawn[k][j]>lawn[i][j]){
						routeR = false;
						break;
					}
				}
				for(int k=0;k<lawn[0].length;k++){
					if(lawn[i][k]>lawn[i][j]){
						routeC = false;
					}
				}
				if(routeC==false&&routeR==false){
					return "NO";
				}
			}
		}
		return "YES";
	}
}
