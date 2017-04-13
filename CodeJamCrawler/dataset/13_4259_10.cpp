using System;
using System.IO;
using System.Linq;

class codejam
{




static bool chk_palindrome(int n)
{
    int rn=0,original_n,l;
    original_n=n;
    do
    {
      l=n%10;
      n=n/10;
      rn=rn*10+l;
    }while(n>0);

    if(original_n==rn)
        return true;
    else
         return false;
}

static bool chk_square(int n)
{
    double d_sqrt = Math.Sqrt(n);
    int i_sqrt = (int)d_sqrt;
    if ( d_sqrt == i_sqrt )
    {
        if(chk_palindrome((int)d_sqrt))
        return true;
    }
    return false;
}


static int find_num_fair_square(int a, int b)
{
    int i,c=0;
    for(i=a;i<=b;i++)
    {
        if(chk_palindrome(i) & chk_square(i) )
            {

                c++;
                //printf("\n%d\n",i);


            }
    }
    return c;
}

public static void Main()
{
//    clrscr();
    //int p=0;

    using (StreamReader sr = new StreamReader("small.in"))
    using (StreamWriter sw = new StreamWriter("small.out"))
    {
        int t = Convert.ToInt32(sr.ReadLine());
        int i;

        int[] a, b, c;
        a = new int[t];
        b = new int[t];
        c = new int[t];


        //Console.WriteLine("Enter number of tests\n");
        //scanf("%d",&t);


        for (i = 0; i < t; i++)
        {
            int[] buf = sr.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            a[i] = buf[0];
            b[i] = buf[1];
            c[i] = find_num_fair_square(a[i], b[i]);
        }

        for (i = 1; i <= t; i++)
        {
            //Console.WriteLine("Case #" + i + ": " + c[i-1]);
            sw.WriteLine("Case #" + i + ": " + c[i-1]);
        }
    }

}





}