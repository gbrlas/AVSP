import java.util.*;
import java.io.*;

public class B {
	void solve() {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int caseNum = 1; caseNum <= cases; caseNum++) {
			System.out.print("Case #" + caseNum + ": ");
			int R = sc.nextInt();
			int C = sc.nextInt();
			int D = sc.nextInt();
			sc.nextLine();
			int[][] grid = new int[R][C];
			for (int i=0;i<R;i++) {
				char[] c = sc.nextLine().toCharArray();
				for (int j=0;j<C;j++) {
					grid[i][j] = Integer.parseInt(Character.toString(c[j]));
				}
			}
			int max = 0;
			for (int i =3;i<=R&&i<=C;i++) {
				for (int j=0; j+i<=R;j++) {
					for (int k=0; k+i<=C;k++) {
						//calc
						int ver = 0,hor = 0;
						for (int l = 0;l<i;l++) {
							for (int m = 0;m<i;m++) {
								if (!(l==0&&m==0 || l==0&&m==i-1 || l==i-1&&m==0 || l==i-1&&m==i-1)) {
									hor += ((2*(l+1)-1)-i)*grid[j+l][k+m];
									ver += ((2*(m+1)-1)-i)*grid[j+l][k+m];
								}
							}
						}
						if (hor==0 && ver==0) {
							//System.out.print(j+"\n"+k+"\n");
							max = i;
						}
					}
				}
			}
			if (max > 0) {
				System.out.print(max+"\n");
			} else {
				System.out.print("IMPOSSIBLE\n");
			}
			
		}
	}

	public static void main(String[] args) {
		new B().solve();
	}
}
