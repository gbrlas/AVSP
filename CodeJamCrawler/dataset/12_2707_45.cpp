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
        string inputFileName = "C-small-attempt0.in";
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
                int A = Convert.ToInt32(stringArray[0]);
                int B = Convert.ToInt32(stringArray[1]);
                int count = 0;
                for (int i = A; i <= B; i++)
                {
                    for (int j = i + 1; j <= B; j++)
                    {
                        if (isRecycle(i, j))
                        {
                            count++;
                        }
                    }
                }
                Console.WriteLine("Case #" + (t + 1) + ": " + count);
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

    private static bool isRecycle(int m, int n)
    {
        string mStr = m.ToString();
        string nStr = n.ToString();
        if (mStr.Length == nStr.Length)
        {
            for (int i = 0; i < mStr.Length - 1; i++)
            {
                int r = n % 10;
                n = r * (int)Math.Pow(10, mStr.Length - 1) + (n / 10);
                if (m == n)
                {
                    return true;
                }
            }
        }
        return false;
    }
}
