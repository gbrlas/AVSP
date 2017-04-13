using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

class Program
{
    const string Path = @"C:\TopCoder\CodeJam\Data\";
//    const string Problem = "A-test";
//  const string Problem = "A-small-attempt0";
  const string Problem = "A-large";

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
                int M = data[1];

                Dictionary<string, bool> exists = new Dictionary<string, bool>();
                for (int i = 0; i < N; i++)
                {
                    exists[din.ReadLine()] = true;
                }
                List<string> need = new List<string>();
                for (int i = 0; i < M; i++)
                {
                    need.Add(din.ReadLine());
                }

                int needCreate = 0;
                foreach (string dir in need)
                {
                    string[] parts = dir.Split('/');
                    for (int i = 2; i <= parts.Length; i++)
                    {
                        string mkdir = string.Join("/", parts, 0, i);
                        if (!exists.ContainsKey(mkdir))
                        {
                            exists[mkdir] = true;
                            needCreate++;
//                            Console.Error.WriteLine(mkdir);
                        }
                    }
                }

                dout.WriteLine("Case #{0}: {1}", cur, needCreate);
            }
        }
    }
}
