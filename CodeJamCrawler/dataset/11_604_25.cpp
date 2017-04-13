import java.io.*;
import java.util.Arrays;
public class CandySpliting {

    static String a[];
    
    static boolean solve(int m)
    {
        
        String x = Integer.toBinaryString(0);
        for(int i=0;i<m;i++)
        {
            StringBuffer sb = new StringBuffer();
            int l=x.length()-1,k=a[i].length()-1;

            while(l>=0&&k>=0)
            {

            if(x.charAt(l)==a[i].charAt(k))
                sb.append("0");
            else
                sb.append("1");
            l--;k--;

            }

                if(l<0)
                {
                    while(k>=0)
                    {
                        sb.append(a[i].charAt(k));
                                k--;
                    }
                }
                else
                {
                     while(l>=0)
                    {
                        sb.append(x.charAt(l));
                                l--;
                    }
                }

            sb = sb.reverse();
            x = sb.toString();

        }               

        String x2 = Integer.toBinaryString(0);
        for(int i=m;i<a.length;i++)
        {
            StringBuffer sb2 = new StringBuffer();
            int l=x2.length()-1,k=a[i].length()-1;

            while(l>=0&&k>=0)
            {
             
            if(x2.charAt(l)==a[i].charAt(k))
                sb2.append("0");
            else
                sb2.append("1");
            l--;k--;
            }

                if(l<0)
                {
                    while(k>=0)
                    {
                        sb2.append(a[i].charAt(k));
                                k--;
                    }
                }
                else
                {
                     while(l>=0)
                    {
                        sb2.append(x2.charAt(l));
                                l--;
                    }
                }

            sb2 = sb2.reverse();
            x2 = sb2.toString();
            
        }
        //System.out.println("for : "+m+" "+x+" "+x2);

        while(x.length()<x2.length())
        {
            x = "0"+x;
        }
        while(x2.length()<x.length())
        {
            x2 = "0"+x2;
        }

        if(x.equals(x2))
            return true;
        return false;
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintStream p = new PrintStream("C:\\Documents and Settings\\Admin\\Desktop\\output2.txt");

        //System.out.println(Integer.toBinaryString(i));
        int t = Integer.parseInt(br.readLine());
        String temp[];
        int count =1;
        boolean flag=true;
        while(t-->0)
        {
            int n = Integer.parseInt(br.readLine());
            flag = false;
            temp = br.readLine().split(" ");
            //System.out.println(temp.length);
            a = new String[n];
            int b[] = new int[n];
            for(int i=0;i<n;i++)
                b[i] = Integer.parseInt(temp[i]);
            Arrays.sort(b);
            for(int i=0;i<n;i++)
            {
                a[i] = Integer.toBinaryString(b[i]);
                //System.out.println(a[i]);
            }
            int sum1=0,sum2=0;
            for(int i=1;i<n&&!flag;i++)
            {
                if((flag = solve(i)))
                {
                    //System.out.println(sum1+" "+sum2);
                    for(int j=0;j<i;j++)
                    {
                        sum1+=Integer.valueOf(a[j],2);
                        //System.out.println(sum1);
                    }
                    for(int j=i;j<a.length;j++)
                    {
                        sum2+=Integer.valueOf(a[j],2);
                        //System.out.println(sum2);
                    }
                    //System.out.println(sum1+" "+sum2);
                    System.out.println("Case #"+count+": "+Math.max(sum1,sum2));
                    p.println("Case #"+count+": "+Math.max(sum1,sum2));
                    break;
                }               
            }
            if(!flag)
            {
                    System.out.println("Case #"+count+": NO");
                    p.println("Case #"+count+": NO");
            }

            count++;
        }
    }

}
