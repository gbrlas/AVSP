import java.util.Scanner;
import java.io.File;
public class tictactoe {
public static void main(String[] args) {
	char[][] map = new char[4][4];
try {	Scanner sc = new Scanner(new File("input.txt"));
	
	int numPuzzle = sc.nextInt();
	for (int i = 1; numPuzzle >= i; i++) {
		sc.nextLine();
		for (int x = 0; x < 4; x++) {
			String s = sc.nextLine();
			for (int y = 0; y < 4; y++) {
			map[x][y] = s.charAt(y);
			/*
				switch (s.charAt(y)) {
					case '.': map[x][y] = ;
					case 'X': map[x][y] = -1;
				}
			*/
			}
		}
	System.out.print("Case #" + i + ": ");
	solveMap(map);
	//printMap(map);
	}
} catch (Exception e) {e.printStackTrace();}
}

static void solveMap(char[][] map) {
	//x win
	for (int x = 0; x < 4; x++) {
		if ((map[x][0] == 'X' || map[x][0] == 'T') && (map[x][1] == 'X' || map[x][1] == 'T') && (map[x][2] == 'X' || map[x][2] == 'T') && (map[x][3] == 'X' || map[x][3] == 'T')) { 
		System.out.println("X won");
		return;}
	}
	//x win
	for (int x = 0; x < 4; x++) {
		if ((map[0][x] == 'X' || map[0][x] == 'T') && (map[1][x] == 'X' || map[1][x] == 'T') && (map[2][x] == 'X' || map[2][x] == 'T') && (map[3][x] == 'X' || map[3][x] == 'T')) { 
		System.out.println("X won");
		return;}
	}


	if ((map[0][0] == 'X' || map[0][0] == 'T') && (map[1][1] == 'X' || map[1][1] == 'T') && (map[2][2] == 'X' || map[2][2] == 'T') && (map[3][3] == 'X' || map[3][3] == 'T')) { 
		System.out.println("X won");
			return;	
		}
	if ((map[3][0] == 'X' || map[3][0] == 'T') && (map[2][1] == 'X' || map[2][1] == 'T') && (map[1][2] == 'X' || map[1][2] == 'T') && (map[0][3] == 'X' || map[0][3] == 'T')) {			System.out.println("X won");
			return;	
		}

        //y win
	for (int x = 0; x < 4; x++) {
		if ((map[x][0] == 'O' || map[x][0] == 'T') && (map[x][1] == 'O' || map[x][1] == 'T') && (map[x][2] == 'O' || map[x][2] == 'T') && (map[x][3] == 'O' || map[x][3] == 'T')) { 
		System.out.println("O won");
		return;}
	}
	//y win
	for (int x = 0; x < 4; x++) {
		if ((map[0][x] == 'O' || map[0][x] == 'T') && (map[1][x] == 'O' || map[1][x] == 'T') && (map[2][x] == 'O' || map[2][x] == 'T') && (map[3][x] == 'O' || map[3][x] == 'T')) { 
		System.out.println("O won");
		return;}
	}
	
	if ((map[0][0] == 'O' || map[0][0] == 'T') && (map[1][1] == 'O' || map[1][1] == 'T') && (map[2][2] == 'O' || map[2][2] == 'T') && (map[3][3] == 'O' || map[3][3] == 'T')) { 
		System.out.println("O won");
			return;	
		}
	if ((map[3][0] == 'O' || map[3][0] == 'T') && (map[2][1] == 'O' || map[2][1] == 'T') && (map[1][2] == 'O' || map[1][2] == 'T') && (map[0][3] == 'O' || map[0][3] == 'T')) {			System.out.println("O won");
			return;	
		}
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			if (map[x][y] == '.'){
			System.out.println("Game has not been completed");
			return;
		}
		}
	}
	System.out.println("Draw");
}
static void printMap(char[][] map) {
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			System.out.print(map[x][y]);
		}
		System.out.println();
	}
}
}
