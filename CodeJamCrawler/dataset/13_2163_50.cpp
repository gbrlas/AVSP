package com.amazon.first;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class TicTacToeSolver {

	final static String inputFileName = "A-small-attempt2.in";
	final static String outputFileName = "output.out";
	final static int ROW = 4;
	final static int COLUMN = 4;
	static char[][] board = new char[ROW][COLUMN];

	static final char WILD_CARD = 'T';
	final static char NO_WIN = 'N';

	public static void main(String[] args) throws IOException {

		File file = new File(inputFileName);

		BufferedReader bufferedInputStream = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
		BufferedWriter bufferedOutputStream = new BufferedWriter(
				new OutputStreamWriter(new FileOutputStream(new File(outputFileName))));
		
		int numOfTestCases = Integer.parseInt(bufferedInputStream.readLine());

		for (int testCase = 1; testCase <= numOfTestCases; testCase++) {

			String outputPrefix = "Case #" + testCase + ": ";
			String outputSuffix;

			createBoard(bufferedInputStream);

			char player = checkRow();

			if (player == NO_WIN) {
				player = checkColumn();

				if (player == NO_WIN) {
					player = checkDiagnol();
				}
			}

			if (player != NO_WIN) {
				outputSuffix = player + " won";

			} else {
				if (boardContainsEmptySpace()) {
					outputSuffix = "Game has not completed";
				} else {

					outputSuffix = "Draw";
				}

			}

			// add space to output
			bufferedOutputStream.write(outputPrefix + outputSuffix);
			bufferedOutputStream.newLine();
			//skip empty line
			bufferedInputStream.readLine();
			

		}

		bufferedOutputStream.flush();
		bufferedOutputStream.close();
		bufferedInputStream.close();
	}

	private static boolean boardContainsEmptySpace() {
 
		
		for(int row=0; row < ROW; row++){
			for(int col = 0 ; col < COLUMN; col++){
				if(board[row][col] == '.'){
					return true;
				}
			}
		}
		
		return false;
	}

	private static char checkDiagnol() {
		char pl = checkPrimaryDiagonal();
		
		if(pl == NO_WIN){
			pl = checkSecondaryDiagonal();
		}
		
		return pl;
	}

	private static char checkSecondaryDiagonal() {
		char pl = board[0][COLUMN-1];
		
		if(pl == '.'){
			return NO_WIN;
		}
		
		for(int i=COLUMN-2; i>=0; i--){
			
			if(board[COLUMN-1-i][i] != pl && board[COLUMN-1-i][i] != WILD_CARD){
				return NO_WIN;
			}
		}
		
		return pl;
	}

	private static char checkPrimaryDiagonal() {
		char pl = board[0][0];
		
		if(pl == '.'){
			return NO_WIN;
		}
		
		for(int i=1; i<ROW; i++){
			
			if(board[i][i] != pl&& board[i][i] != WILD_CARD){
				return NO_WIN;
			}
		}
		
		return pl;
	}

	private static char checkColumn() {
		for(int col=0; col<COLUMN; col++){
			int row = 0;
			char pl = board[row][col];
			
			if(pl == '.'){
				continue;
			}
			
			for( row = 1; row<ROW; row++){
				if(board[row][col] != pl&& board[row][col] != WILD_CARD){
					pl = NO_WIN;
					break;
				}
			}
			
			if(pl != NO_WIN){
				return pl;
			}
		}
		
		return NO_WIN;
	}

	private static char checkRow() {
		for(int row=0; row<ROW; row++){
			int col = 0;
			char pl = board[row][col];
			
			if(pl == '.'){
				continue;
			}
			
			for( col = 1; col<COLUMN; col++){
				if(board[row][col] != pl && board[row][col] != WILD_CARD){
					pl = NO_WIN;
					break;
				}
			}
			
			if(pl != NO_WIN){
				return pl;
			}
		}
		
		return NO_WIN;
	}

	private static void createBoard(BufferedReader bufferedInputStream) throws IOException {
		for(int i=0;i<ROW; i++){
			String row = bufferedInputStream.readLine();
			for(int j=0; j<COLUMN; j++){
				board[i][j] = row.charAt(j);
			}
		}
		
	}
}
