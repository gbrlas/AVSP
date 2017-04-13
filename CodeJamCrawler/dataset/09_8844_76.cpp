import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Watersheds{
	
	public static void main(String args[]) throws IOException{
		
		String inputFileName = "";
		String output = "";
		int numMaps, height, width;
		
		if(args.length != 1){
			System.out.println("Please specify input file name as 1st argument.");
		}else{
			inputFileName = args[0];
		}
		
		FileReader fr = new FileReader(inputFileName);
		BufferedReader br = new BufferedReader(fr);
		
		String line = br.readLine();
		StringTokenizer st = new StringTokenizer(line);
		
		numMaps = Integer.parseInt(st.nextToken());
		
		for(int m = 0; m < numMaps; m++){
			output += "Case #" + (m + 1) + ":";
			char curChar = 'a';
			st = new StringTokenizer(br.readLine());
			height = Integer.parseInt(st.nextToken());
			width = Integer.parseInt(st.nextToken());
			char[][] mark = new char[height][width];
			int[][] map = new int[height][width];
			for(int i = 0; i < height; i++){
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j < width; j++){
					map[i][j] = Integer.parseInt(st.nextToken());
					mark[i][j] = '1';
				}
			}
			
			for(int i = 0; i < height; i++){
				for(int j = 0; j < width; j++){
					if(mark[i][j] == '1'){
						mark[i][j] = markMap(map, mark, i, j, curChar, height, width);
						if(mark[i][j] == curChar){
							curChar++;
						}
					}
				}
			}
			
			for(int i = 0; i < height; i++){
				output += "\n";
				for(int j = 0; j < width - 1; j++){
					output += (mark[i][j] + " "); 
				}
				output += mark[i][width-1];
			}
			
			output += "\n";
			
		}
		
		br.close();
		
		st = new StringTokenizer(inputFileName, ".");
		String outFileName = st.nextToken() + ".out";
		FileWriter fstream = new FileWriter(outFileName);
		BufferedWriter out = new BufferedWriter(fstream);
		
		//System.out.println(output);
		out.write(output);
		out.close();
		
	}
	
	private static char markMap(int[][] map, char[][] mark, int i, int j, char c, int h, int w){
		if(mark[i][j] != '1'){
			return mark[i][j];
		}else{
			int min = map[i][j];
			int minI = -1;
			int minJ = -1;
			if(i < h - 1){//S
				if(min >= map[i + 1][j]){
					minI = i + 1;
					minJ = j;
					min = map[minI][minJ];
				}
			}
			if(j < w - 1){//E
				if(min >= map[i][j + 1]){
					minI = i;
					minJ = j + 1;
					min = map[minI][minJ];
				}
			}
			if(j > 0){//W
				if(min >= map[i][j - 1]){
					minI = i;
					minJ = j - 1;
					min = map[minI][minJ];
				}
			}
			if(i > 0){//N
				if(min >= map[i - 1][j]){
					minI = i - 1;
					minJ = j;
					min = map[minI][minJ];
				}
			}
			
			if(min != map[i][j]){
				mark[i][j] = markMap(map, mark, minI, minJ, c, h, w);
				return mark[i][j];
			}else{
				mark[i][j] = c;
				return c;
			}
		}
	}
}