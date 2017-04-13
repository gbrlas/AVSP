import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();

    for(int i=0; i<t; ++i) {
      eval(i + 1, cin);
    }

  }

  int C = 0;

  void eval(int num, Scanner cin) {

    System.out.println("Case #" + num + ":");

    int r = cin.nextInt();
    int c = cin.nextInt();

    int h[][] = new int[r][c];
    for(int i=0; i<r; ++i) {
      for(int j=0; j<c; ++j) {
        h[i][j] = cin.nextInt();
      }
    }

    int id[][] = new int[r][c];
    for(int i=0; i<r; ++i) {
      for(int j=0; j<c; ++j) {
        id[i][j] = -1;
      }
    }

    C = 0;
    for(int i=0; i<r; ++i) {
      for(int j=0; j<c; ++j) {
        check(h, id, r, c, i, j);
      }
    }

    char used = 'a';
    char assign[] = new char[26];

    for(int i=0; i<r; ++i) {
      for(int j=0; j<c; ++j) {
        if( assign[id[i][j]] == '\0' ) {
          assign[id[i][j]] = used++;
        }
        if( j > 0 ) { System.out.print(' '); }
        System.out.print(assign[id[i][j]]);
      }
      System.out.println();
    }

  }

  int dx[] = { 0, -1, 1, 0 };
  int dy[] = { -1, 0, 0, 1 };

  void check(int h[][], int id[][], int r, int c, int i, int j) {

    if( id[i][j] >= 0 ) { return; }
    int q[][] = new int[r*c][2];
    int a = 0;
    q[a][0] = i;
    q[a][1] = j;

    while( true ) {
      int d = -1;
      int x = q[a][1];
      int y = q[a][0];
      int s = h[y][x];
      for(int k=0; k<4; ++k) {
        int px = x + dx[k];
        int py = y + dy[k];
        if( px < 0 || py < 0 || px >= c || py >= r ) { continue; }
        if( h[py][px] < s ) {
          s = h[py][px];
          d = k;
        }
      }
      ++a;
      if( d == -1 ) {
        for(int k=0; k<a; ++k) {
          id[q[k][0]][q[k][1]] = C;
        }
        ++C;
        return;
      }
      int nx = x + dx[d];
      int ny = y + dy[d];
      if( id[ny][nx] >= 0 ) {
        for(int k=0; k<a; ++k) {
          id[q[k][0]][q[k][1]] = id[ny][nx];
        }
        return;
      }
      q[a][0] = ny;
      q[a][1] = nx;
    }

  }

}
