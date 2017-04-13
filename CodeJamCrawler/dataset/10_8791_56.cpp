import java.util.*;

public class y{
public static void main(String[] args) throws Throwable{

Scanner in = new Scanner(System.in);
int tt = Integer.parseInt(in.nextLine());
for(int iter = 1; iter <= tt; iter++)
{
    System.out.print("Case #"+iter+": ");
    String[] t = in.nextLine().split(" ");
    int n = Integer.parseInt(t[0]);
    int m  = Integer.parseInt(t[1]);
    HashSet<String> a = new HashSet<String>();
    for(int i = 0; i < n; i++)
    {
        String[] q = in.nextLine().split("/");
        for(int j = 1; j < q.length; j++)
        {
            q[j] = q[j-1]+q[j];
            a.add(q[j]);
        }
    }
    int sz = a.size();
    for(int i = 0; i < m; i++)
    {
        String[] q = in.nextLine().split("/");
        
        for(int j = 1; j < q.length; j++)
        {
            q[j] = q[j-1]+q[j];
            a.add(q[j]);
        }
    }
    System.out.println(a.size()-sz);
}}
}