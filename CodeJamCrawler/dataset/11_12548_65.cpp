import java.util.*;
public class gogo3 {
  public static void main(String [] args) {
    Scanner in = new Scanner(System.in);
    int ttt = in.nextInt();
    for (int iter = 1; iter <= ttt; iter++) {
      int L = in.nextInt();
      long t = in.nextLong();
      int N = in.nextInt();
      int C = in.nextInt();
      int[] a = new int[C];
      for (int i = 0; i < C; i++)
        a[i] = in.nextInt();
        
      int[] ae = new int[N];
      for (int i = 0; i < N; i++)
        ae[i] = a[i%C];
      
      long time = 0;
      for (int i = 0; i < N; i++) {
        if (time + 2*ae[i] <= t)
          time += 2*ae[i];
        else {
          int cd = ae[i] - (int)((t - time) / 2);
          time = t;
          int[] rm = new int[N-i];
          rm[0] = cd;
          for (int j = 1; j < (N-i); j++)
            rm[j] = ae[i+j];
          Arrays.sort(rm);
          for (int j = N-i-1; j >= 0; j--)
            if (L > 0) {
              time += rm[j];
              L--;
            } else
              time += 2*rm[j];
          break;
        }
      }
      System.out.printf("Case #%d: %d\n", iter, time);
    }
  }
}