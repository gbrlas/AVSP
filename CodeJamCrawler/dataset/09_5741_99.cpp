import java.io.*;
import java.util.*;

public class sol_vv{

	StreamTokenizer iin;

	public int nextInt() throws Exception{
		iin.nextToken();
		return (int)iin.nval;
	}

	BufferedReader in;
	PrintWriter out;

	char[][] a;
	boolean[][] g;
	int[][] h;
	char last;
	int[] dx = new int[]{-1,0,0,1};
	int[] dy = new int[]{0,-1,1,0};


	public char poisk(int x, int y){
		if (g[x][y]) return a[x][y];
		g[x][y] = true;
		a[x][y] = (char)(last+1);
		int bh = h[x][y];
		int bi = -1;
		for(int i = 0;i<4;i++){
			if (h[x+dx[i]][y+dy[i]]<bh){
				bh = h[x+dx[i]][y+dy[i]];
				bi = i;
			}
		}
		if (bi==-1){
			a[x][y] = last++;
		} else {
			a[x][y] = poisk(x+dx[bi],y+dy[bi]);
		}
		return a[x][y];
	}

	public void run() throws Exception{
		in = new BufferedReader(new FileReader("input.in"));
		iin = new StreamTokenizer(in);
		out= new PrintWriter(new FileWriter("output.out"));
		int _ = nextInt();
		a = new char[105][105];
		g = new boolean[105][105];
		h = new int[105][105];
		for(int __ = 0;__<_;__++){
			int n = nextInt();
			int m = nextInt();
			for(int i = 0;i<=n+1;i++){
				Arrays.fill(h[i],1000000);
				Arrays.fill(g[i],false);
			}
			for(int i = 1;i<=n;i++)
				for(int j = 1;j<=m;j++)
					h[i][j] = nextInt();
			out.println("Case #"+(__+1)+":");
			last = 'a';
			for(int i = 1;i<=n;i++)
				for(int j = 1;j<=m;j++){
					poisk(i,j);
					out.print(a[i][j]);
					if (j<m) out.print(" ");
					else out.println();
				}

		}
	}


	public void close(){
		out.close();
	}
	public static void main(String[] args) throws Exception{
		new Thread() {
			public void run(){
				try{
					sol_vv a = new sol_vv();
					a.run();
					a.close();
				} catch (Exception E){
					throw new RuntimeException(E);
				}
			}
		}.start();
	}
}
