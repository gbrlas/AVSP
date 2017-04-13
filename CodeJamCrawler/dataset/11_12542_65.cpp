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
      
      long time = 0;
      if (L == 0) {
        for (int i = 0; i < N; i++)
          time += 2*a[i%C];
      } else if (L == 1) {
        long btime = Long.MAX_VALUE;
        for (int i = 0; i < N; i++) {
          long ctime = 0;
          for (int j = 0; j < N; j++) {
            if (j != i)
              ctime += 2*a[j%C];
            else {
              if (ctime + 2*a[j%C] <= t)
                ctime += 2*a[j%C];
              else if (ctime >= t)
                ctime += a[j%C];
              else
                ctime = t + a[j%C] - (t - ctime)/2;
            }
          }
          if (ctime < btime)
            btime = ctime;
        }
        time = btime;
      } else {
        long btime = Long.MAX_VALUE;
        for (int i1 = 0; i1 < N; i1++) { for (int i2 = i1+1; i2 < N; i2++) {
          long ctime = 0;
          for (int j = 0; j < N; j++) {
            if (j != i1 && j != i2)
              ctime += 2*a[j%C];
            else {
              if (ctime + 2*a[j%C] <= t)
                ctime += 2*a[j%C];
              else if (ctime >= t)
                ctime += a[j%C];
              else
                ctime = t + a[j%C] - (t - ctime)/2;
            }
          }
          if (ctime < btime)
            btime = ctime;
        }}
        time = btime;
      }
      System.out.printf("Case #%d: %d\n", iter, time);
    }
  }
}