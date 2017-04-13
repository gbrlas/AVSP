import java.util.*;
public class gogo {
  public static void main(String [] args) {
    Scanner in = new Scanner(System.in);
    int t = Integer.parseInt(in.nextLine());
    for (int iter = 1; iter <= t; iter++) {
      String[] tt = in.nextLine().split(" ");
      int R = Integer.parseInt(tt[0]);
      int C = Integer.parseInt(tt[1]);
      char[][] v = new char[R][C];
      for (int i = 0; i < R; i++)
        v[i] = in.nextLine().toCharArray();
      
      boolean poss = true;
      
      for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
          try {
            if (v[i][j] == '#') {
              if (v[i][j+1] == '#' && v[i+1][j] == '#' && v[i+1][j+1] == '#') {
                v[i][j] = v[i+1][j+1] = '/';
                v[i+1][j] = v[i][j+1] = '\\';
              } else {
                poss = false;
                i = R+1;
                break;
              }
            }
          } catch (Exception e) {
            poss = false;
            i = R+1;
            break;
          }
      
      System.out.printf("Case #%d: \n", iter);
      if (poss)
        for (char[] cc : v)
          System.out.println(new String(cc));
      else
        System.out.println("Impossible");
    }
  }
}