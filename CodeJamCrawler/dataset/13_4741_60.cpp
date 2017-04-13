import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;


public class Test {

	public static void main(String [] args) {
		class tictactoe {
			
			private String output;
			private Boolean out;	
			private char[] input;
			
			public tictactoe(String input){
			this.input = input.toCharArray();
			}
			
			public String status(){
				if (this.calcstatus('X',0, 0, 0, 0)){
					return "X won";
				}
				else if (this.calcstatus('O',0, 0, 0, 0)){
					return "O won";
				}
				else {
					if (contain()){
						return "Game has not completed";
					}
					return "Draw";
				}
			}
			
			public Integer position(Integer x, Integer y){
				return x + y*4;
			}
			
			public Boolean inField(Integer x, Integer y){
				if (0 <= x && x <= 3 && 0<= y && y <= 3){ return true;}
				return false;
			}
			
			public Boolean contain(){
				for (int i=0;i<16;++i){
					if (input[i] == '.') return true;
				}
				return false;
			}
			
			public void show(){
				for (int y=0;y<4;++y){
					for (int x=0;x<4;++x){
						System.out.print(input[position(x,y)]);
					}
					System.out.println();
				}
			}
			
			public Boolean calcstatus(char in, Integer x, Integer y, Integer dir, Integer counter){
				if (counter == 4) return true;
				else{
					if (input[position(x,y)] == in | input[position(x,y)] == 'T'){
							//begin
							if (dir == 0){
								Boolean a = false;
								Boolean b = false;
								Boolean c = false;
								Boolean d = false;
								if (x==0){a = calcstatus(in,x+1,y,1,counter +1);}
								if (x==3 && y==0){b = calcstatus(in,x-1,y+1,2,counter +1);}
								if (x==0 && y==0){c = calcstatus(in,x+1,y+1,3,counter +1);}
								if (y==0){d = calcstatus(in,x,y+1,4,counter +1);}
								return a || b || c || d;
							}
							else  {
								// direction 1 - move right
								if (dir == 1){return calcstatus(in,x+1,y,1,counter +1);}
								//direction 2 - move left dia
								if (dir==2){return calcstatus(in,x-1,y+1,2,counter +1);}
								//direction 3 - move right dia
								if (dir==3){return calcstatus(in,x+1,y+1,3,counter +1);}
								//direction 4 - move down
								if (dir == 4){return calcstatus(in,x,y+1,4,counter +1);}
							}
					}
					else {
						Boolean e = false;
						Boolean f = false;
						if (inField(x+1,y)){e = calcstatus(in,x+1,y,0,0);}
						if (inField(0,y+1)){f = calcstatus(in,0,y+1,0,0);}
						return e || f;
					}
					return false;
				}
			}

		}
		
		StringBuffer in = new StringBuffer();
		try {
			BufferedReader input = new BufferedReader(new FileReader("A-small-attempt4.in"));
			String zeile = null;
			while ((zeile = input.readLine()) != null) {
				in.append(zeile);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		Integer fields = new Integer(in.substring(0, 2));
		String inp = in.toString().substring(2);
		for (int i=0;i<fields;++i){
			String input = inp.substring(0, 16);
			inp = inp.substring(16);
			tictactoe t = new tictactoe(input);
			//t.show();
			System.out.print("Case #" + (i+1) + ": " + t.status() + "\n");
		}
	}
}
