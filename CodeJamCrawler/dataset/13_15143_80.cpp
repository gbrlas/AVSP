import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class TicTacToe {
	public static void main(String[] args) {
		FileReader fin;
		try {
			fin = new FileReader(
					new File(
							"D:\\CodeJam\\A-small-attempt0.in"));

			FileWriter fr = new FileWriter(
					new File(
							"D:\\CodeJam\\A-Small-out.txt"));
			BufferedReader br = new BufferedReader(fin);
			String line = br.readLine();
			int N = Integer.parseInt(line);
			for (int i = 0; i < N; i++) {
				
				String[] board= new String[4]; 
				for(int j=0;j<4;j++){
					board[j] = br.readLine();
				}
				br.readLine();
				fr.write("Case #"+(i+1)+": "+compute(board)+"\r\n");
				
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
	
	public static String compute(String[] board){
		int xDR=0,xDL=0,oDR=0,oDL=0,empty=0;
		for(int i=0;i<4;i++){
			int xS=0,xD=0,oS=0,oD=0;
			for(int j=0;j<4;j++){
				if(board[i].charAt(j)=='.'){
					empty++;
				}
				if(board[i].charAt(j)=='X' || board[i].charAt(j)=='T'){
					xS++;
				}
				if(board[i].charAt(j)=='O' || board[i].charAt(j)=='T'){
					oS++;
				}
				if(board[j].charAt(i)=='X' || board[j].charAt(i)=='T'){
					xD++;
				}
				if(board[j].charAt(i)=='O' || board[j].charAt(i)=='T'){
					oD++;
				}
			}
			
			if(board[i].charAt(i)=='X' || board[i].charAt(i)=='T'){
				xDR++;
			}
			if(board[i].charAt(i)=='O' || board[i].charAt(i)=='T'){
				oDR++;
			}
			if(board[i].charAt(4-i-1)=='X' || board[i].charAt(4-i-1)=='T'){
				xDL++;
			}
			if(board[i].charAt(4-i-1)=='O' || board[i].charAt(4-i-1)=='T'){
				oDL++;
			}
			
			if(xS==4 || xD==4){
				return "X won";
			}
			else if(oS==4 || oD==4){
				return "O won";
			}
			
		}
		if(xDR==4||xDL==4){
			return "X won";
		}
		else if(oDR==4||oDL==4){
			return "O won";
		}else if(empty>0){
			return "Game has not completed";
		}
		else{
			return "Draw";
		}
	}
}
