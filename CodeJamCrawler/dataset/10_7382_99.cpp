import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  boolean lights(int n, int k) {
    int req = (1 << n) - 1;
    return (k & req) == req;
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();
    for(int i=0; i<t; ++i) {
      int n = cin.nextInt();
      int k = cin.nextInt();
      System.out.println("Case #" + (i + 1) + ": " + (lights(n, k) ? "ON" : "OFF"));
    }

  }

}
