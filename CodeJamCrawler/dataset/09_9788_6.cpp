using System;
using System.Collections;
using System.IO;
using System.Text;

class A
{
    public static void Main()
    {
        StreamReader SR;
        SR = File.OpenText("A-small-attempt1.in");
        StreamWriter SW;
        SW = File.CreateText("A.out");

        int T = int.Parse(SR.ReadLine());
        for (int l = 0; l < T; l++)
        {
            int len = int.Parse(SR.ReadLine());
            //int[,] matrix = new int[len, len];
            ArrayList str= new ArrayList();
            for (int i = 0; i < len; i++)
            {
                string s = SR.ReadLine();
                str.Add(s);
                //for (int j = 0; j < len; j++)
                //    matrix[i, j] = Int32.Parse(s[j].ToString());
            }

            int count = 0;
            int k=0;
            bool[] done= new bool[len];
            for (int i = 0; i < len; i++)
                done[i] = false;
            int[] current=new int [len];
            for (int i = 0; i < len; i++)
                current[i]=i;
            while (k < len)
            {
                for (int i = 0; i < len; i++)
                {
                    long t = Convert.ToInt32(str[i].ToString(), 2);
                  //Console.WriteLine(str[i].ToString()+ " "+t);
                   if ((t & ((1 << (len - 1 - k)) - 1)) == 0&&(!done[i]))
                   {
                       //if (current[i] - k>0)
                       count += (current[i]-k);
                       done[i] = true;
                       for (int p = 0; p < i; p++)
                       {
                           current[p]++;
                           //Console.WriteLine(p);
                       }
                       //Console.WriteLine(current[i]+ " " +i);
                       break;
                   }
                }
                k++;
            }

            Console.WriteLine("Case #" + (l + 1) + ": " + count);
            SW.WriteLine("Case #" + (l + 1) + ": " + count);
        }

        SR.Close();
        SW.Close();
    }

}