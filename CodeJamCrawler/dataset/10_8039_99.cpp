using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

class Program
{
    const string Path = @"C:\TopCoder\CodeJam\Data\";
//    const string Problem = "A-test";
    const string Problem = "A-small-attempt0";
//    const string Problem = "A-large";

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
                long N = data[0];
                long K = data[1];
                bool isOn = true;
                for (long i = 0; i < N; i++)
                {
                    if (K % 2 == 0)
                    {
                        isOn = false;
                        break;
                    }
                    K /= 2;
                }
                if (isOn)
                {
                    dout.WriteLine("Case #{0}: ON", cur);
                }
                else
                {
                    dout.WriteLine("Case #{0}: OFF", cur);
                }
            }
        }
    }
}
