using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        TextReader textReader = null;
        TextWriter textWriter = null;

        string filePath = @"C:\Users\Amit\Desktop\New folder\";
        string inputFileName = "B-large.in";
        string outputFileName = Path.GetFileNameWithoutExtension(inputFileName) + ".out";

        try
        {
            textReader = new StreamReader(filePath + inputFileName);
            textWriter = new StreamWriter(filePath + outputFileName);

            Console.SetIn(textReader);
            Console.SetOut(textWriter);

            int T = Convert.ToInt32(Console.ReadLine());

            for (int t = 0; t < T; t++)
            {
                string[] stringArray = Console.ReadLine().Split(' ');
                int N = Convert.ToInt32(stringArray[0]);
                int S = Convert.ToInt32(stringArray[1]);
                int p = Convert.ToInt32(stringArray[2]);
                int[] sums = new int[N];
                int maxCount = 0;
                int minSum = 0;
                minSum = p;
                minSum += Math.Max(p - 2, 0);
                minSum += Math.Max(p - 2, 0);
                for (int n = 0; n < N; n++)
                {
                    sums[n] = Convert.ToInt32(stringArray[n + 3]);
                    if (sums[n] < minSum)
                    {

                    }
                    else if ((sums[n] == (p + Math.Max(p - 2, 0)) + Math.Max(p - 2, 0)) || (sums[n] == (p + Math.Max(p - 2, 0)) + Math.Max(p - 1, 0)))
                    {
                        if (p <= 1)
                        {
                            maxCount++;
                        }
                        else if (S > 0)
                        {
                            maxCount++;
                            S--;
                        }
                    }
                    else
                    {
                        maxCount++;
                    }
                }
                Console.WriteLine("Case #" + (t + 1) + ": " + maxCount);
            }

        }
        catch (Exception)
        {
        }
        finally
        {
            if (textReader != null)
            {
                textReader.Close();
            }
            if (textWriter != null)
            {
                textWriter.Close();
            }
        }
    }

    private static bool matchForPatter(string word, string pattern)
    {
        int index = 0;
        for (int i = 0; i < pattern.Length; i++)
        {
            char[] char2 = null;
            if (pattern[i] != '(')
            {
                char2 = new char[] { pattern[i] };
            }
            else
            {
                i++;
                string s = pattern.Substring(i, pattern.IndexOf(')', i) - i);
                char2 = s.ToCharArray();
                i += char2.Length;
            }
            if (!char2.Any(a => a == word[index]))
            {
                return false;
            }
            index++;
        }
        return true;
    }
}
