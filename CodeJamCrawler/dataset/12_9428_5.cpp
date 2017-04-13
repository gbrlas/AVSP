using System;
using System.Collections.Generic;
using System.IO;

class Round2_A
{
    static String input = "a-small-attempt0.in";
    static String output = "a-small-attempt0.out";

    //static String input = "a-large.in";
    //static String output = "a-large.out";

    static void Main(string[] args)
    {
        StreamReader reader = new StreamReader(input);
        StreamWriter writter = new StreamWriter(output);

        int T = int.Parse(reader.ReadLine());
        for (int index = 1; index <= T; index++)
        {           
            int n = int.Parse(reader.ReadLine());
            int[] d = new int[n + 1];
            int[] l = new int[n + 1];
            for (int i = 0; i < n; i++)
            {
                String[] lineArray = reader.ReadLine().Split(' ');
                d[i] = int.Parse(lineArray[0]);
                l[i] = int.Parse(lineArray[1]);
            }            
            d[n] = int.Parse(reader.ReadLine());
            l[n] = 0;

            String ans = "NO"; //"YES"
            List<int>[] pos = new List<int>[n + 1];
            for (int i = 0; i < n + 1; i++) pos[i] = new List<int>();
            pos[0].Add(d[0]);
            for (int i = 0; i < n; i++)            
                for (int j = 0; j < pos[i].Count; j++)
                {
                    int p = pos[i][j];
                    for (int k = i + 1; k < n + 1 && d[i] + p >= d[k]; k++)                        
                    {
                        int high = Math.Min(d[k] - d[i], Math.Min(l[i], l[k]));
                        if (! pos[k].Contains(high)) pos[k].Add(high);
                        if (k == n) ans = "YES";
                    }
                }            

            writter.WriteLine("Case #" + index + ": " + ans);    
        }

        reader.Close();
        writter.Close();
    }
}

