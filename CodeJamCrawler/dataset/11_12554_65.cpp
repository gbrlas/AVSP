import java.util.*;
public class gogo2 {
  public static void main(String [] args) {
    Scanner in = new Scanner(System.in);
    int t = in.nextInt();
    for (int iter = 1; iter <= t; iter++) {
      int N = in.nextInt();
      long L = in.nextLong();
      long H = in.nextLong();
      
      long[] s = new long[N];
      for (int i = 0; i < N; i++)
        s[i] = in.nextLong();
      
      Arrays.sort(s);
      long prev = 0;
      int ct = 0;
      
      for (long v : s)
        if (v != prev) {
          ct++;
          prev = v;
        }
      
      long[] f = new long[ct]; // filter dups
      ct = 0;
      prev = 0;
      
      for (long v : s)
        if (v != prev)
          prev = f[ct++] = v;
      
      long ans = -1;
      for (long i = L; i <= H; i++) {
        boolean good = true;
        for (int j = 0; j < ct; j++)
          if (i == f[j] || (i < f[j] ? (f[j] % i == 0) : (i % f[j] == 0))) {
            continue;
          } else {
            good = false;
            break;
          }
        if (good) {
          ans = i;
          break;
        }
      }
      
      System.out.printf("Case #%d: ", iter);
      if (ans == -1) System.out.println("NO");
      else System.out.println(ans);
    }
  }
}