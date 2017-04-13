import java.io.*;
import java.util.*;


public class TicTacToeTomek{

	private int row = 0;
	private String[] board = new String[4];
	private boolean complete = true;

	public void createboard(String n){

		if(row == 4){
			row = 0;
			complete = true;
		}

		board[row] = n;

		if(n.indexOf('.') != -1){
			complete = false;
		}

		row++;
	}

	public boolean checkWin(char a){
		int brdCtr = 0;
		int strCtr = 0;

		while(brdCtr < 4){
			strCtr = 0;
			while(strCtr < 4){
				if(board[brdCtr].charAt(strCtr) == a || board[brdCtr].charAt(strCtr) == 'T'){
					if(brdCtr == 0 && strCtr == 0){
						if(checkHorizontal(brdCtr, strCtr, a) || checkDiagonal(brdCtr, strCtr, a) || checkVertical(brdCtr, strCtr, a)){
							return true;
						}
						strCtr++;
					}else if(brdCtr == 0 && strCtr == 3){
						if(checkDiagonal(brdCtr, strCtr, a) || checkVertical(brdCtr, strCtr, a)){
							return true;
						}
						strCtr++;
					 }else if(brdCtr == 0){
						if(checkVertical(brdCtr, strCtr, a)){
							return true;
						}
						strCtr++;
					  }else if(strCtr == 0){
						if(checkHorizontal(brdCtr, strCtr, a)){
							return true;
					    }
					    strCtr = 4;
					 }
				}
				strCtr++;
			}
			brdCtr++;
		}
		return false;
	}

	public String judgeGame(){

		if(checkWin('X')){
			return "X won";
		}else if(checkWin('O')){
			return "O won";
		 }else if(complete){
			return "Draw";
		  }else{
			return "Game has not completed";
		   }
	}

	public boolean checkHorizontal(int row, int col, char a){
		col++;
		while(board[row].charAt(col) == a || board[row].charAt(col) == 'T'){
			col++;

			if(col == 4){
				break;
			}
		}

		if(col == 4){
			return true;
		}

		return false;
	}

	public boolean checkVertical(int row, int col, char a){
		row++;
		while(board[row].charAt(col) == a || board[row].charAt(col) == 'T'){
			row++;

			if(row == 4){
				break;
			}
		}

		if(row == 4){
			return true;
		}

		return false;
	}

	public boolean checkDiagonal(int row, int col, char a){
		boolean revDiagonal = false;
		row++;
		if(col == 0){
			col++;
		}else{
		 	col--;
		 	revDiagonal = true;
		 }

		while(board[row].charAt(col) == a || board[row].charAt(col) == 'T'){
			row++;
			if(!revDiagonal){
				col++;
			}else{
				col--;
			 }

			if(row == 4){
				break;
			}
		}

		if(row == 4){
			return true;
		}

		return false;
	}


	public static void main(String args[])throws IOException{
		TicTacToeTomek test = new TicTacToeTomek();

		Scanner scan = null;

		FileWriter fw = null;
		BufferedWriter bw = null;

		try{
			scan = new Scanner(new File("A-small-attempt1.in"));

			fw = new FileWriter("A-small-attempt1.out");
			bw = new BufferedWriter(fw);

			int inputnum = scan.nextInt();
			int ctr = 1;

			while(scan.hasNextLine() && ctr <= inputnum){
				scan.nextLine();
				test.createboard(scan.nextLine());
				test.createboard(scan.nextLine());
				test.createboard(scan.nextLine());
				test.createboard(scan.nextLine());
				bw.write("Case #"+ctr+": "+test.judgeGame() + "\n");
				ctr++;
			}
		}catch(IOException e){
			System.out.println("File not found!");
			e.printStackTrace();
		}finally{
			bw.close();
		 }

	}

}