#region Template code
using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Globalization;

class Program
{
    static void Main(string[] args)
    {
        System.Threading.Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        Solution sol = new Solution();
        sol.go();
    }
}

partial class Solution
{
    #region I/O
    protected TextReader input = null;
    protected TextWriter output = null;

    string[] line;
    int index;
    protected string ReadLine()
    {
        line = null;
        return input.ReadLine();
    }

    protected int ReadLine_int()
    {
        line = null;
        return Convert.ToInt32(input.ReadLine());
    }

    protected string[] SplitLine()
    {
        index = 0;
        return line = input.ReadLine().Split();
    }

    protected List<int> SplitLine_int()
    {
        index = 0;
        line = input.ReadLine().Split();

        List<int> result = new List<int>();
        foreach (string s in line)
        {
            result.Add(Convert.ToInt32(s));
        }
        return result;
    }

    protected string GetString()
    {
        return line[index++];
    }

    protected int GetInt()
    {
        return Convert.ToInt32(line[index++]);
    }

    protected long GetLong()
    {
        return Convert.ToInt64(line[index++]);
    }

    protected double GetDouble()
    {
        return Convert.ToDouble(line[index++], CultureInfo.InvariantCulture);
    }

    protected void Write(string s)
    {
        output.Write(s);
        Console.Error.Write(s);
    }

    protected void Write(string format, params object[] ss)
    {
        output.Write(format, ss);
        Console.Error.Write(format, ss);
    }

    protected void WriteLine()
    {
        output.WriteLine();
        Console.Error.WriteLine();
    }

    protected void WriteLine(string s)
    {
        output.WriteLine(s);
        Console.Error.WriteLine(s);
    }

    protected void WriteLine(int i)
    {
        output.WriteLine(i.ToString());
        Console.Error.WriteLine(i.ToString());
    }

    protected void WriteLine(string format, params object[] ss)
    {
        output.WriteLine(format, ss);
        Console.Error.WriteLine(format, ss);

    }

    #endregion

    static string hex(int x)
    {
        return String.Format("{0:x}", x);
    }

    public void go()
    {
        input = Console.In;
        output = Console.Out;
        int N = ReadLine_int();
        for (cas = 1; cas <= N; cas++)
        {
            Console.Write("Case #{0}: ", cas);
            Solve();
        }

        Console.Error.WriteLine("Done...");
    }
    int cas = -1;
}
#endregion

partial class Solution
{
    const string name = "Magicka";

    void Solve()
    {
        // combination -> target character, e.g., "QF" -> 'T', "FQ" -> 'T'
        Dictionary<string, char> combs = new Dictionary<string, char>();
        // opposing -> '', e.g., "QF" -> ''
        Dictionary<string, int> opponents = new Dictionary<string, int>();

        string[] words = ReadLine().Trim().Split();
        int C = int.Parse(words[0]);
        int index = 1;
        for(int i=0; i<C; i++, index++)
        {
          //Write(words[index]); 
          string ab = words[index].Substring(0,2);
          string ba = ab[1].ToString() + ab[0].ToString();
          combs[ab] = words[index][2];
          combs[ba] = words[index][2];
        }

        foreach( KeyValuePair<string,char> kvp in combs)
            Console.Error.WriteLine("{0} -> {1}", kvp.Key, kvp.Value);

        int D = int.Parse(words[index]);
        index++;
        
        for(int i=0; i<D; i++, index++)
        {
          // Write(words[index]); 
          string ab = words[index];
          string ba = ab[1].ToString() + ab[0].ToString();
          opponents[ab] = 1;
          opponents[ba] = 1;
        } 

        foreach( KeyValuePair<string,int> kvp in opponents)
            Console.Error.WriteLine("{0} -> {1}", kvp.Key, kvp.Value);

        int N = int.Parse(words[index]);
        index++;
        List<char> list = new List<char>();
        string input = words[index];
        for(int i=0; i<N; i++)
        {
            char ch = input[i];
            //WriteLine(words[index].ToString());
            foreach(char x in list) Console.Error.Write(x.ToString());
            Console.Error.WriteLine();
            if (list.Count > 0)
            {
               // check combination first
               char tail = list[list.Count - 1];
               string ab = tail.ToString() + ch.ToString();
               Console.Error.WriteLine("ab={0}", ab);
               if(combs.ContainsKey(ab))
               {
                  list.RemoveAt(list.Count-1);
                  list.Add(combs[ab]);
                  Console.Error.WriteLine("Added combs[ab]: {0}", combs[ab]);
               }
               else // check opponent next
               {
                  bool toClear = false;
                  foreach(char opp in list)
                  {
                     ab = opp.ToString() + ch.ToString();
                     if(opponents.ContainsKey(ab))
                       toClear = true;
                  }
                  if (toClear)
                     list.Clear();
                  else
                     list.Add(ch);

               }
               
            }
            else
            {
               list.Add(input[i]);
            }
            
        }
        Write("[");
        for(int i=0; i<list.Count; i++)
        {
           Write(list[i].ToString());
           if(i!=list.Count-1) Write(",");
        }
        WriteLine("]");

    }
}

