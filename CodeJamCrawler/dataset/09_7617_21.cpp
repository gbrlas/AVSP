using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

public static class IOHelper
{
    public static int ReadInt(this StreamReader infile)
    {
        string line = infile.ReadLine();
        return int.Parse(line);
    }

    public static int[] ReadIntArr(this StreamReader infile)
    {
        string line = infile.ReadLine();
        int[] data = Array.ConvertAll(line.Split(' '), s => int.Parse(s));
        return data;
    }
}

class A
{

    const string Test = "large";


    static int Main(string[] args)
    {

        using (StreamReader infile = File.OpenText(@"C:\TopCoder\CodeJam\Inputs\A-" + Test + ".in"))
        using (StreamWriter outfile = File.CreateText(@"C:\TopCoder\CodeJam\Inputs\A-" + Test + ".out"))
        {
            int T = infile.ReadInt();
            for (int testcase = 1; testcase <= T; testcase++)
            {
                int N = infile.ReadInt();
                string[] data = new string[N];
                int[] count = new int[N];

                for (int i = 0; i < N; i++)
                {
                    data[i] = infile.ReadLine();
                    count[i] = data[i].LastIndexOf('1');
                    if (count[i] < 0)
                    {
                        count[i] = 0;
                    }
                }


                int ret = 0;
                for (int i = 0; i < N; i++)
                {
                    if (count[i] > i)
                    {
                        int idx;
                        for (idx = i + 1; idx < N; idx++)
                        {
                            if (count[idx] <= i)
                            {
                                break;
                            }
                        }
                        ret += idx - i;
                        int t = count[idx];
                        for (int ii = idx; ii >= i + 1; ii--)
                        {
                            count[ii] = count[ii - 1];
                        }
                        count[i] = t;
                    }
                }


                outfile.WriteLine("Case #{0}: {1}", testcase, ret);
            }
        }
        return 0;
    }
}
