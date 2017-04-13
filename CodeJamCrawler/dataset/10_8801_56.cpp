import java.util.*;

public class x{
public static void main(String[] args) throws Throwable{

Scanner in = new Scanner(System.in);
int tt = in.nextInt();
for(int iter = 1; iter <= tt; iter++)
{
    System.out.print("Case #"+iter+": ");
    int N = in.nextInt();
    int K = in.nextInt();
    int B = in.nextInt();
    int T = in.nextInt();
    int[] X = new int[N];
    for(int i = 0; i < N; i++)
        X[i] = B - in.nextInt();
    int[] V = new int[N];
    for(int i = 0; i < N; i++)
        V[i] = in.nextInt();
    int ct = 0;
    boolean[] p = new boolean[N];
    for(int i = 0; i < N; i++)
        if(V[i] * T >= X[i])
        {
            ct++;
            p[i] = true;
        }
    if(ct < K)
        System.out.println("IMPOSSIBLE");
    else
    {
        int ans = 0;
        for(int i = N-1; K > 0; i--)
            if(p[i])
                K--;
            else
                ans += K;
        System.out.println(ans);
    }
}}
}