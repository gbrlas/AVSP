using System;
using System.Collections;
using System.IO;
using System.Text;

class BooleanTree
{
    public static void Main()
    {
        StreamReader SR;
        SR = File.OpenText("B-small-attempt0.in");
        StreamWriter SW;
        SW = File.CreateText("A.out");

        int T = int.Parse(SR.ReadLine());
        for (int l = 0; l < T; l++)
        {
            int num = int.Parse(SR.ReadLine());
            ArrayList a1 = new ArrayList();
            int n1 = num;
            while (n1 > 0)
            {
                if(n1%10>0)
                    a1.Add(n1 % 10);
                n1 = n1 / 10;
            }
            a1.Sort();
            //for (int k = 0; k < a1.Count; k++)
            //    Console.WriteLine(a1[k]);
            for (int i = num+1; i <=num*10; i++)
            {
                ArrayList a2 = new ArrayList();
                int n=i;
                while (n > 0)
                {
                    if(n%10>0)
                        a2.Add(n % 10);
                    n = n / 10;
                }
                a2.Sort();
                //for (int k = 0; k < a2.Count; k++)
                //    Console.WriteLine(a2[k]);
                bool is_num = true;
                if (a1.Count == a2.Count)
                {
                    for (int k = 0; k < a1.Count; k++)
                    {
                        if (a1[k].ToString()!=a2[k].ToString())
                            is_num = false;
                    }
                    if (is_num)
                    {
                        Console.WriteLine("Case #" + (l + 1) + ": "+i);
                        SW.WriteLine("Case #" + (l + 1) + ": "+i);
                        break;
                    }
                }
            }

            //Console.WriteLine("Case #" + (l + 1) + ": ");
            //SW.WriteLine("Case #" + (l + 1) + ": ");
        }

        SR.Close();
        SW.Close();
    }

}
