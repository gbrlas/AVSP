import java.io.*;

public class B {

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    String in = br.readLine();
    int tests = Integer.parseInt(in);
    for (int i = 1; i <= tests; i++) {
      in = br.readLine();
      String[] parts = in.split(" ");
      int Y = Integer.parseInt(parts[0]);
      int X = Integer.parseInt(parts[1]);
      int[][] squares = new int[Y][];
      for (int y = 0; y < Y; y++) {
        in = br.readLine();
	parts = in.split(" ");
        squares[y] = new int[X];
	for (int x = 0; x < X; x++) {
	  squares[y][x] = Integer.parseInt(parts[x]);
	}
      }
      System.out.print("Case #");
      System.out.print(i);
      System.out.print(": ");
      if (test(squares, Y, X)) {
        System.out.println("YES");
      }
      else {
        System.out.println("NO");
      }
    }
  }

  public static boolean test(int[][] test, int Y, int X) {
    for (int y = 0; y < Y; y++) {
      for (int x = 0; x < X; x++) {
        int maxRow = 0;
        int maxCol = 0;
	for (int i = 0; i < X; i++) {
	  int value = test[y][i];
	  if (value > maxRow) maxRow = value;
	}
	for (int i = 0; i < Y; i++) {
	  int value = test[i][x];
	  if (value > maxCol) maxCol = value;
	}
	int value = test[y][x];
	if (value < maxRow && value < maxCol) {
	  return false;	
	}
      }
    }
    return true;
  }

}
