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
    const string Test = "small-attempt0";

    public static bool NextPerm(char[] a)
    {
        for (int i = a.Length - 2; i >= 0; i--)
            if (a[i] < a[i + 1])
            {
                Array.Reverse(a, i + 1, a.Length - i - 1);
                for (int j = i + 1; ; j++) if (a[i] < a[j])
                    { char t = a[i]; a[i] = a[j]; a[j] = t; return true; }
            }
        return false; // no more permutations
    }


    static int Main(string[] args)
    {

        using (StreamReader infile = File.OpenText(@"C:\TopCoder\CodeJam\Inputs\B-" + Test + ".in"))
        using (StreamWriter outfile = File.CreateText(@"C:\TopCoder\CodeJam\Inputs\B-" + Test + ".out"))
        {
            int T = infile.ReadInt();
            for (int testcase = 1; testcase <= T; testcase++)
            {
                string val = infile.ReadLine().Trim();
                char[] vals = val.ToCharArray();

                if (NextPerm(vals))
                {
                    outfile.WriteLine("Case #{0}: {1}", testcase, new string(vals));
                }
                else
                {
                    char[] zvals = new char[vals.Length + 1];
                    Array.Copy(vals, 0, zvals, 1, vals.Length);
                    zvals[0] = '0';
                    NextPerm(zvals);
                    outfile.WriteLine("Case #{0}: {1}", testcase, new string(zvals));
                }
            }
        }
        return 0;
    }
}
