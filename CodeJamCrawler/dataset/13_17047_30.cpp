import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.Console;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StringWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.logging.ConsoleHandler;
import java.util.logging.Logger;

/**
 * 
 */

/**
 * @author James
 *
 */
public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		 InputStreamReader converter = new InputStreamReader(System.in);
		    BufferedReader in = new BufferedReader(converter);
		int cases = Integer.parseInt(in.readLine());
		String[] arr = new String[cases * 5 + 1];
		arr[0] = ""+cases;
		for(int xx = 1; xx < cases *4 + (( cases+1)*1);xx++){
			arr[xx] =  in.readLine();
		}
		
		//BufferedWriter bw = new BufferedWriter(new FileWriter(new File("new.txt"), false));
		int grps = Integer.parseInt(arr[0]);
		int[][] board = new int[4][4];
		
		for(int i = 0;i < grps;i++)
		{
			int index = i*4 + (( i+1)*1);
			
			for(int k = 0;k <= 3;k++){
				//log("Reading line" + arr[index+k]);
			for(int j = 0;j <= 3;j++){
				switch(arr[index+k].substring(j, j+1)){
				case "X":
					board[k][j] = 1; 
					break;
				case "O":
					board[k][j] = 2; 
					break;
				case "T":
					board[k][j] = 3; 
					break;
				case ".":
					board[k][j] = 0; 
					break;
				}
			}
			}
			System.out.println("Case #" + (i+1) + ": " + getResult(board));
			
				//bw.write("Case #" + (i+1) + ": " + getResult(board)+System.getProperty("line.separator"));
			
		}
		
			
		
	}
	
	
	/**
	 * @param board
	 * @return
	 */
	private static String getResult(int[][] board) {
		int p1 = 0;
		int p2 = 0;
		int[][] board2 = buildboard(board);

		for (int[] _is : board) {
			for (int _i : _is) {
				if((_i & 1) == 1) p1++;
				if((_i & 2) == 2) p2++;
				
			}
			if(p1 > 3) return "X won";
			if(p2 > 3) return "O won";
			p1 =0; p2 = 0;
		}
		
		for (int[] _is : board2) {
			for (int _i : _is) {
				if((_i & 1) == 1) p1++;
				if((_i & 2) == 2) p2++;
				
			}
			if(p1 > 3) return "X won";
			if(p2 > 3) return "O won";
			p1 =0; p2 = 0;
		}
		if(checkWin(board[0][0],board[1][1],board[2][2],board[3][3],1)) return "X won";
		if(checkWin(board[0][3],board[1][2],board[2][1],board[3][0],1)) return "X won";
		if(checkWin(board[0][3],board[1][2],board[2][1],board[3][0],2)) return "O won";	
		if(checkWin(board[0][0],board[1][1],board[2][2],board[3][3],2)) return "O won";
		if(checkArrayFor(0, board))
			return "Game has not completed";
		return "Draw";
		
		
	}
	
	
	
	/**
	 * @param i
	 * @param j
	 * @param k
	 * @param l
	 * @param m
	 * @return
	 */
	private static boolean checkWin(int i, int j, int k, int l, int m) {
		int cnt = 0;
		if((i&m) == m)cnt++;
		if((j&m) == m)cnt++;
		if((k&m) == m)cnt++;
		if((l&m) == m)cnt++;
		
		if(cnt > 3) return true;
		return false;
	}


	/**
	 * @param board
	 * @return
	 */
	private static int[][] buildboard(int[][] board) {
		int[][] newboard = new int[4][4];
		for (int _i = 0; _i < newboard.length; _i++) {
			for (int _i2 = 0; _i2 < newboard.length; _i2++) {
				newboard[_i2][_i] = board[_i][_i2];
			}
		}
		return newboard;
	}


	private static boolean checkArrayFor(int val, int[][] board)
	{
		for (int[] _is : board) {
			for (int _i : _is) {
				if (_i == val) return true;
			}
		}
		return false;
	}


	private static void log(String msg) {
		System.out.println(msg);
	}

}
