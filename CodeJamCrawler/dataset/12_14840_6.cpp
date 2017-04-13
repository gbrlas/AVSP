using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.IO;


class Program
{
    static int ncase;
    static UInt64[] n;
    static int N;

    static void Main(string[] args)
    {
        Console.Write(args.Length != 1 ? "args?" : ProcessInput(fileToString(args[0])));
    }

    public static String fileToString(String filePath)
    {
        using (StreamReader re = File.OpenText(filePath)) { return re.ReadToEnd(); }
    }

    public static String ProcessInput(String input)
    {
        string tline, output = "";
        int lineNumber = 0;

        input = input.Replace("\r", "");
        string []lines = input.Split(new char[] { '\n' });

        int NUM_TESTS = int.Parse(lines[lineNumber++]);
        for (ncase = 1; ncase <= NUM_TESTS; ncase++)
        {
            tline = lines[lineNumber++];
            // N = int.Parse(tline)
            String[] parts = tline.Split(new char[] { ' ' });
            N = int.Parse(parts[0]);
            n = new UInt64[N];
            for (int i = 0; i < N; i++)
                n[i] = UInt64.Parse(parts[1 + i]);

            output += ("Case #" + ncase + ": " + Solve("_") + "\n");
        }

        return output;
    }

    static bool incArr(int[] a)
    {
        for (int i=a.Length-1; i>=0; i--)
        {
            a[i]++;
            if (a[i] <= 2)
                return false;
            a[i] = 0;
        }

        return true; // end
    }

    public static string Solve(String paramx)
    {
        int j = 0;

        int []opt = new int[N];
        for (int i=0; i<N; i++)
            opt[i]=0;

        // todo fill opt

        while (true)
        {
            bool end = incArr(opt);
            if (end)
                break;

            UInt64 sa = 0, sb = 0;
            int ga = 0, gb = 0;
            for (j = 0; j < N; j++)
            {
                if (opt[j] == 1)
                {
                    ga++;
                    sa += n[j];
                    if (sa == sb && ga>0 && gb>0)
                        goto Found;
                }
                else
                if (opt[j] == 2)
                {
                    gb++;
                    sb += n[j];
                    if (sa == sb && ga>0 && gb>0)
                        goto Found;
                }
            }
        }

        return "Impossible";

Found:
        String outTxt = "\n";
        for (int i=0; i<=j; i++)
            if (opt[i]==1) outTxt += n[i] + " ";
        outTxt +="\n";
        for (int i=0; i<=j; i++)
            if (opt[i]==2) outTxt += n[i] + " ";

        return outTxt;
    }

}    



