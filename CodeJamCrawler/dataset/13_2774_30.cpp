import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;


public class TicTac {
	
	String fileName ;
	
	public TicTac(String fileName) {
		this.fileName = fileName;
	}
	
	
	public static void main(String[] args) {
		TicTac tt = new TicTac("/home/sajith/google/A-small-attempt0.in");
		tt.checWhoWon();
	}
	
	
	private void checWhoWon(){
		BufferedReader br = null;
		int[][] tt = new int[4][4];
		try {
			br = new BufferedReader(new FileReader(fileName));
			int numCase = Integer.parseInt(br.readLine());
			
			for (int i=0; i< numCase; i++){
				readChars(tt[0], br.readLine());
				readChars(tt[1], br.readLine());
				readChars(tt[2], br.readLine());
				readChars(tt[3], br.readLine());
				System.out.println("Case #"+(i+1)+": "+getStatus(tt));
				br.readLine();
			}
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}


	private String getStatus(int[][] tt) {
		boolean emptyexist = false;
		for(int i=0; i<tt.length; i++){
			int t1 = 3;
			for(int j=0; j<tt.length;j++){
				if(tt[i][j] == 0){
					emptyexist = true;
					t1=0;
					break;
				}
				t1 = t1 & tt[i][j];
			}
			if(t1 == 2){
				return "X won";
			}
			if(t1 == 1){
				return "O won";
			}
		}

		for(int i=0; i<tt.length; i++){
			int t1 = 3;
			for(int j=0; j<tt.length;j++){
				if(tt[j][i] == 0){
					emptyexist = true;
					t1=0;
					break;
				}
				t1 = t1 & tt[j][i];
			}
			if(t1 == 2){
				return "X won";
			}
			if(t1 == 1){
				return "O won";
			}
		}

		int t1 = 3;
		for(int j=0; j<tt.length;j++){
			if(tt[j][j] == 0){
				emptyexist = true;
				t1=0;
				break;
			}
			t1 = t1 & tt[j][j];
		}
		if(t1 == 2){
			return "X won";
		}
		if(t1 == 1){
			return "O won";
		}
		
		t1 = 3;
		for(int j=0; j<tt.length;j++){
			if(tt[j][tt.length-1-j] == 0){
				emptyexist = true;
				t1=0;
				break;
			}
			t1 = t1 & tt[j][tt.length-1-j];
		}
		if(t1 == 2){
			return "X won";
		}
		if(t1 == 1){
			return "O won";
		}

		
		if(emptyexist){
			return "Game has not completed";
		}
		return "Draw";
	}


	private void readChars(int[] cs, String readLine) {
		cs[0] = getInt(readLine.charAt(0));
		cs[1] = getInt(readLine.charAt(1));
		cs[2] = getInt(readLine.charAt(2));
		cs[3] = getInt(readLine.charAt(3));
	}
	
	private int getInt(char character){
		if(character == 'T')
			return 3;
		if(character== 'X')
			return 2;
		if(character == 'O')
			return 1;
		return 0;
	}

}
