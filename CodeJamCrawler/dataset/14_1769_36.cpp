import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class MineSweeper {
	private static PrintWriter sortie;
	private static Scanner scanner = new Scanner(System.in);
	private static char[][] mat;
	private static int[][] moves = {{0,0},{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	private static boolean ok = false;

	public static void main(String[] args) {
		start();
		
	    int T = scanner.nextInt();
	    
	    for(int i = 0;i<T;++i) {
	    	int R = scanner.nextInt();
	    	int C = scanner.nextInt();
	    	int M = scanner.nextInt();
	    	int size = R*C;

	    	mat = new char[R][C];
	    	
	    	for(int k = 0;k<R;++k)
				for(int j = 0;j<C;++j)
					mat[k][j] = '*';
	    	
    		if(M == size-1) {
    			mat[0][0] = 'c';
    			sortie.println("Case #"+(i+1)+":");
    			display(mat, R, C);
    		}
    		else if(M <= size - 4 || ((R == 1 || C == 1) && M <= size - 2)) {
    			ok = false;

    			build(i, R, C, M, 0, 0, size-M);
    			
    			if(!ok) {
    				sortie.println("Case #"+(i+1)+":");
        			sortie.println("Impossible");
    			}
    		}
    		else {
    			sortie.println("Case #"+(i+1)+":");
    			sortie.println("Impossible");
    		}
    	}
	    
	    end();
	}
	
	
	private static void build(int n, int r, int c, int m, int x, int y, int empty) {
		boolean[] touched = new boolean[moves.length];
		int nb = 0;
		
		if(ok) return;
		
		if(empty == 0) {
			mat[0][0] = 'c';
			sortie.println("Case #"+(n+1)+":");
			display(mat, r, c);
			ok = true;
		}
		
		for(int k = 0;k<moves.length;++k)
			if(test(x, y, r, c, k) && mat[x+moves[k][0]][y+moves[k][1]] == '*')
				nb++;

		if(nb <= empty) {
			for(int k = 0;k<moves.length;++k) {
				if(test(x, y, r, c, k) && mat[x+moves[k][0]][y+moves[k][1]] == '*') {
					mat[x+moves[k][0]][y+moves[k][1]] = '.';
					--empty;
					touched[k] = true;
				}
			}
			
			for(int k = 0;k<moves.length;++k)
				if(touched[k])
					build(n, r, c, m, x + moves[k][0], y + moves[k][1],empty);
			
			for(int k = 0;k<moves.length;++k)
				if(touched[k])
					mat[x+moves[k][0]][y+moves[k][1]] = '*';
		}
	}

	private static boolean test(int x, int y, int r, int c, int k) {
		return x + moves[k][0] >= 0 && x + moves[k][0] < r && y + moves[k][1] >= 0 && y + moves[k][1] < c;
	}

	private static void display(char[][] mat, int r, int c) {
		for(int i = 0;i<r;++i) {
			for(int j = 0;j<c;++j)
				sortie.print(mat[i][j]);
			sortie.println();
		}
	}

	private static void end() {
	    sortie.close();
	    try {
		    InputStream ips=new FileInputStream("C:\\Users\\Thomas\\Desktop\\output.txt"); 
			InputStreamReader ipsr=new InputStreamReader(ips);
			BufferedReader br=new BufferedReader(ipsr);
			String ligne;
			while((ligne=br.readLine())!=null) System.out.println(ligne);
			br.close(); 
	    } catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static void start() {
		try {
			sortie = new PrintWriter(new BufferedWriter(new FileWriter("C:\\Users\\Thomas\\Desktop\\output.txt")));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
