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


class Tree
{
    public decimal Weight;
    public string Feature;
    public Tree OK;
    public Tree NOK;

    public Tree(string data)
    {
        int idx = data.IndexOf('(');
        int idx2 = data.LastIndexOf(')');
        string inner = data.Substring(idx+1, idx2 - idx-1);
        if (!inner.Contains('('))
        {
            Weight = decimal.Parse(inner);
        }
        else
        {
            string[] parts = inner.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            Weight = decimal.Parse(parts[0]);
            Feature = parts[1];
            int count = 0;
            int idx3 = inner.IndexOf('(');
            for (int i = idx3; i < inner.Length; i++)
            {
                if (inner[i] == '(') count++;
                if (inner[i] == ')')
                {
                    count--;
                    if (count == 0)
                    {
                        OK = new Tree(inner.Substring(idx3, i - idx3+1));
                        idx3 = i + 1;
                        break;
                    }
                }
            }
            for (int i = idx3; i < inner.Length; i++)
            {
                if (inner[i] == '(') count++;
                if (inner[i] == ')')
                {
                    count--;
                    if (count == 0)
                    {
                        NOK = new Tree(inner.Substring(idx3, i - idx3+1));
                    }
                }
            }
        }
    }

}


class A
{

    const string Test = "small-attempt0";


    static int Main(string[] args)
    {

        using (StreamReader infile = File.OpenText(@"C:\TopCoder\CodeJam\Inputs\A-" + Test + ".in"))
        using (StreamWriter outfile = File.CreateText(@"C:\TopCoder\CodeJam\Inputs\A-" + Test + ".out"))
        {
            int T = infile.ReadInt();
            for (int testcase = 1; testcase <= T; testcase++)
            {
                int treelines = infile.ReadInt();
                StringBuilder tree = new StringBuilder();
                for (int i = 0; i < treelines; i++)
                {
                    tree.Append(infile.ReadLine());
                }
                Tree t = new Tree(tree.ToString());


                outfile.WriteLine("Case #{0}:", testcase);
                
                int animals = infile.ReadInt();
                for (int i = 0; i < animals; i++)
                {
                    string data = infile.ReadLine();
                    outfile.WriteLine("{0:f7}", Solve(t, data));
                }
            }
        }
        return 0;
    }

    private static decimal Solve(Tree t, string data)
    {
        string[] d = data.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        Dictionary<string, bool> features = new Dictionary<string, bool>();
        for (int i = 2; i < d.Length; i++)
        {
            features[d[i]] = true;
        }
        decimal p = 1;
        while (t != null)
        {
            if (t.Feature != null)
            {
                if (features.ContainsKey(t.Feature))
                {
                    p *= t.Weight;
                    t = t.OK;
                }
                else
                {
                    p *= t.Weight;
                    t = t.NOK;
                }
            }
            else
            {
                p *= t.Weight;
                t = null;
            }
        }
        return p;
    }
}
