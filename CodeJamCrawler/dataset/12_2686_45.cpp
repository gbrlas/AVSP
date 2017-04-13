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
        string inputFileName = "A-small-attempt0.in";
        string outputFileName = Path.GetFileNameWithoutExtension(inputFileName) + ".out";

        try
        {
            textReader = new StreamReader(filePath + inputFileName);
            textWriter = new StreamWriter(filePath + outputFileName);

            Console.SetIn(textReader);
            Console.SetOut(textWriter);

            Dictionary<string, string> dictionary = new Dictionary<string, string>();
            dictionary.Add("a", "y");
            dictionary.Add("b", "h");
            dictionary.Add("c", "e");
            dictionary.Add("d", "s");
            dictionary.Add("e", "o");
            dictionary.Add("f", "c");
            dictionary.Add("g", "v");
            dictionary.Add("h", "x");
            dictionary.Add("i", "d");
            dictionary.Add("j", "u");
            dictionary.Add("k", "i");
            dictionary.Add("l", "g");
            dictionary.Add("m", "l");
            dictionary.Add("n", "b");
            dictionary.Add("o", "k");
            dictionary.Add("p", "r");
            dictionary.Add("q", "z");
            dictionary.Add("r", "t");
            dictionary.Add("s", "n");
            dictionary.Add("t", "w");
            dictionary.Add("u", "j");
            dictionary.Add("v", "p");
            dictionary.Add("w", "f");
            dictionary.Add("x", "m");
            dictionary.Add("y", "a");
            dictionary.Add("z", "q");

            int T = Convert.ToInt32(Console.ReadLine());

            for (int t = 0; t < T; t++)
            {
                string input = Console.ReadLine();
                StringBuilder output = new StringBuilder();
                for (int i = 0; i < input.Length; i++)
                {
                    if (dictionary.ContainsKey(input.Substring(i, 1)))
                    {
                        output.Append(dictionary[input.Substring(i, 1)]);
                    }
                    else
                    {
                        output.Append(input.Substring(i, 1));
                    }
                }
                Console.WriteLine("Case #" + (t + 1) + ": " + output.ToString());
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
