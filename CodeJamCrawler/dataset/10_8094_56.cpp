using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

class Program
{
    const string Path = @"C:\TopCoder\CodeJam\Data\";
//    const string Problem = "B-test";
//  const string Problem = "B-small-attempt0";
  const string Problem = "B-large";

    private static int ReadInt(StreamReader din)
    {
        string line = din.ReadLine();
        return int.Parse(line.Trim());
    }
    private static string[] ReadStrings(StreamReader din)
    {
        string line = din.ReadLine();
        return line.Split(' ');
    }
    private static int[] ReadInts(StreamReader din)
    {
        string line = din.ReadLine();
        return line.Split(' ').Select(s => int.Parse(s)).ToArray();
    }
    private static long[] ReadLongs(StreamReader din)
    {
        string line = din.ReadLine();
        return line.Split(' ').Select(s => long.Parse(s)).ToArray();
    }

    static void Main(string[] args)
    {
        using (StreamReader din = File.OpenText(Path + Problem + ".in"))
        using (StreamWriter dout = File.CreateText(Path + Problem + ".out"))
        {
            int cases = ReadInt(din);

            for (int cur = 1; cur <= cases; cur++)
            {
                int[] data = ReadInts(din);
                int N = data[0];
                int K = data[1];
                int B = data[2];
                int T = data[3];
                long[] X = ReadLongs(din);
                long[] V = ReadLongs(din);

                bool[] isFast = new bool[X.Length];

                for (int i = 0; i < X.Length; i++)
                {
                    isFast[i] = (B - X[i]) <= T * V[i];
                }

                int fastCount = isFast.Count(i => i);
                if (fastCount < K)
                {
                    dout.WriteLine("Case #{0}: IMPOSSIBLE", cur);
                    continue;
                }

                bool[] atBarn = new bool[X.Length];
                int atBarnCount = 0;
                int swaps = 0;

                while (atBarnCount < K)
                {
                    int next = 0;
                    int nextCount = int.MaxValue;
                    for (int i = 0; i < X.Length; i++)
                        if (isFast[i] && !atBarn[i])
                        {
                            int curCount = 0;
                            for (int ii = 0; ii < X.Length; ii++)
                                if (!atBarn[ii])
                                {
                                    if (X[ii] >= X[i] && !isFast[ii])
                                    {
                                        curCount++;
                                    }
                                }
                            if (curCount < nextCount)
                            {
                                nextCount = curCount;
                                next = i;
                            }
                        }
                    swaps += nextCount;
                    atBarn[next] = true;
                    atBarnCount++;
                }

                dout.WriteLine("Case #{0}: {1}", cur, swaps);
            }
        }
    }
}
