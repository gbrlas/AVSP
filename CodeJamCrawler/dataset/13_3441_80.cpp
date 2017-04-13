import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class Bag {
	int x, o;
	boolean t;
	
	Bag(Character ...characters) {
		for(Character c : characters) {
			switch(c) {
				case 'O': o++; break;
				case 'X': x++; break;
				case 'T': t=true; break;
			}
		}
	}
}

public class TickTackToe {
	public static void main(String[] args) {
		if(args.length == 0) {
			System.out.println("Specify filename!");
			return;
		}
		
		Scanner s = null;
		try {
			s = new Scanner(new File(args[0]));
		} catch (FileNotFoundException e) {
			System.out.println("File not found: "+args[0]);
			return;
		}
		
		int cases = s.nextInt();
		
		for(int casenr = 0; casenr < cases; casenr++) {
			s.nextLine();
			doCase(s, casenr);
		}
	}

	static void doCase(Scanner s, int casenr) {
		boolean done = true;
		boolean victory = false;
		
//		System.err.println("Case " + (casenr+1));
		Character board[][] = new Character[4][4]; 
		for(int y = 0; y < 4; y++) {
			String line = s.nextLine();
//			System.err.println(line);
			for(int x = 0; x < 4; x++) {
				board[x][y] = line.charAt(x);
				if(board[x][y] == '.') {
					done = false;
				}
				
				// check line
				if(x == 3) {
					Bag b = new Bag(board[0][y], board[1][y], board[2][y], board[3][y]);
					if(b.x == 4 || b.x == 3 && b.t) {
						victory = true;
						resX(casenr);
					} else if(b.o == 4 || b.o == 3 && b.t) {
						victory = true;
						resO(casenr);
					}
				}
				
				// check row
				if(y == 3) {
					Bag b = new Bag(board[x][0], board[x][1], board[x][2], board[x][3]);
					if(b.x == 4 || b.x == 3 && b.t) {
						victory = true;
						resX(casenr);
					} else if(b.o == 4 || b.o == 3 && b.t) {
						victory = true;
						resO(casenr);
					}
				}
			}
		}
		// check diagonals
		if(!victory) {
			Bag b = new Bag(board[0][0], board[1][1], board[2][2], board[3][3]);
			if(b.x == 4 || b.x == 3 && b.t) {
				victory = true;
				resX(casenr);
			} else if(b.o == 4 || b.o == 3 && b.t) {
				victory = true;
				resO(casenr);
			}
		}
		
		if(!victory) {
			Bag b = new Bag(board[3][0], board[2][1], board[1][2], board[0][3]);
			if(b.x == 4 || b.x == 3 && b.t) {
				victory = true;
				resX(casenr);
			} else if(b.o == 4 || b.o == 3 && b.t) {
				victory = true;
				resO(casenr);
			}
		}
		
		if(!victory) {
			if(done) {
				resD(casenr);
			} else {
				resNC(casenr);
			}
		}
	}

	private static void resX(int casenr) {
		System.out.printf("Case #%d: X won\n", casenr+1);
	}
	
	private static void resO(int casenr) {
		System.out.printf("Case #%d: O won\n", casenr+1);
	}
	
	private static void resD(int casenr) {
		System.out.printf("Case #%d: Draw\n", casenr+1);
	}
	
	private static void resNC(int casenr) {
		System.out.printf("Case #%d: Game has not completed\n", casenr+1);
	}
}
