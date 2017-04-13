using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

class Program
{
    const string Path = @"C:\TopCoder\CodeJam\Data\";
//    const string Problem = "C-test";
   const string Problem = "C-small-attempt1";
//    const string Problem = "C-large";

    private static int ReadInt(StreamReader din)
    {
        string line = din.ReadLine();
        return int.Parse(line.Trim());
    }
    private static long[] ReadLongs(StreamReader din)
    {
        string line = din.ReadLine();
        return line.Split(' ').Select(s => long.Parse(s)).ToArray();
    }

    static void Main(string[] args)
    {
        using(StreamReader din = File.OpenText(Path + Problem+".in"))
        using(StreamWriter dout = File.CreateText(Path + Problem + ".out"))
        {
            int cases = ReadInt(din);

            for (int cur = 1; cur <= cases; cur++)
            {
                long[] data = ReadLongs(din);
                long R = data[0];
                long n = data[1];
                long K = data[1];
                long[] g = ReadLongs(din);

                long[] gIdx = new long[g.Length];
                long[] gIncome = new long[g.Length];

                long pos = 0;
                long income = 0;
                long ride = 1;
                while(ride <= R)
                {
                    if (gIdx[pos] != 0 && gIdx[pos] != ride)
                    {
                        long loops = (R - ride) / (ride - gIdx[pos]);
                        if (loops > 0)
                        {
                            ride += loops * (ride - gIdx[pos]);
                            income += loops * (income - gIncome[pos]);
                            continue;
                        }
                    }
                    else
                    {
                        gIdx[pos] = ride;
                        gIncome[pos] = income;
                    }

                    long seats = 0;
                    long initPos = pos;
                    while (seats + g[pos] <= K)
                    {
                        seats  += g[pos];
                        pos++;
                        if (pos >= g.Length) pos -= g.Length;
                        if (pos == initPos) break;
                    }

                    income += seats;
                    ride++;
                }
                dout.WriteLine("Case #{0}: {1}", cur, income);
            }
        }
    }
}
