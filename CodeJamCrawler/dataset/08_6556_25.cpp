import java.util.*;

public class D {

  public static void main(String args[]) {
    (new D()).exec();
  }

  int check(int w, int h, int r, int rs[][]) {

    int count[][] = new int[w+1][h+1];
    count[1][1] = 1;

    for(int i=0; i<=w; ++i) {
    MAIN:
      for(int j=0; j<=h; ++j) {
        for(int k=0; k<r; ++k) {
          if( rs[k][0] == i && rs[k][1] == j ) { continue MAIN; }
        }
        if( i >= 2 && j >= 1 ) {
          count[i][j] += count[i-2][j-1];
        }
        if( i >= 1 && j >= 2 ) {
          count[i][j] += count[i-1][j-2];
        }
        count[i][j] %= 10007;
      }
    }

    return count[w][h];

  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int time = cin.nextInt();

    for(int count=0; count<time; ++count) {

      int w = cin.nextInt();
      int h = cin.nextInt();
      int r = cin.nextInt();
      int rs[][] = new int[r][2];
      for(int i=0; i<r; ++i) {
        rs[i][0] = cin.nextInt();
        rs[i][1] = cin.nextInt();
      }

      int ans = check(w, h, r, rs);
      System.out.println("Case #" + (count + 1) + ": " + ans);

    }

  }

}
