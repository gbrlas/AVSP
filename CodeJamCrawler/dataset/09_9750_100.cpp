using System;
using System.Collections;
using System.IO;
using System.Text;

class BooleanTree
{

    public static long to_base(string s, int b)
    { 
        long num=0;
        for (int i = s.Length-1; i >= 0; i--)
        {
            
            long level=1;
            for (int j = s.Length - 1; j > i; j--)
                level *= b;
            //Console.WriteLine(level);
            //Console.WriteLine(int.Parse(s[i].ToString()));
            //Console.WriteLine(int.Parse(s[i].ToString())*b);
            num+=level*int.Parse(s[i].ToString());
        }
        //Console.WriteLine(num);
        return num;
    }


    public static void Main()
    {
        StreamReader SR;
        SR = File.OpenText("A-small-attempt2.in");
        StreamWriter SW;
        SW = File.CreateText("A.out");

        int T = int.Parse(SR.ReadLine());
        for (int l = 0; l < T; l++)
        {
            string s = SR.ReadLine();
            ArrayList c = new ArrayList();
            int b = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (!c.Contains(s[i]))
                {
                    b++;
                    c.Add(s[i]);
                }
            }
            
            StringBuilder s2 = new StringBuilder();
            //Console.WriteLine(b);
            for (int i = 0; i < s.Length; i++)
            {
                //Console.WriteLine(c.IndexOf(s[i]));
                int x;
                if (c.IndexOf(s[i]) == 0)
                    x = 1;
                else if (c.IndexOf(s[i]) == 1)
                    x = 0;
                else
                    x=c.IndexOf(s[i]);
                s2.Append(x);

            }
            if (b == 1) b = 2;
            long res;
            res=to_base(s2.ToString(), b);
           // Console.WriteLine(s2.ToString());
            

           //Console.WriteLine(res);

            Console.WriteLine("Case #" + (l + 1) + ": "+res);
            SW.WriteLine("Case #" + (l + 1) + ": "+res);
        }

        SR.Close();
        SW.Close();
    }

}
