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
        string inputFileName = "A-large.in";
        string outputFileName = Path.GetFileNameWithoutExtension(inputFileName) + ".out";

        try
        {
            textReader = new StreamReader(filePath + inputFileName);
            textWriter = new StreamWriter(filePath + outputFileName);

            Console.SetIn(textReader);
            Console.SetOut(textWriter);

            int T = int.Parse(Console.ReadLine());

            for (int t_ = 0; t_ < T; t_++)
            {
                string[] input = Console.ReadLine().Split(' ');
                long N = Convert.ToInt64(input[0]);
                int Pd1 = Convert.ToInt32(input[1]);
                int Pg = Convert.ToInt32(input[2]);

                bool isPossible = true;

                int Pd = Pd1;

                int hundred = 100;

                if (Pd % 2 == 0)
                {
                    Pd /= 2;
                    hundred /= 2;
                }
                if (Pd % 5 == 0)
                {
                    Pd /= 5;
                    hundred /= 5;
                }
                if (Pd % 2 == 0)
                {
                    Pd /= 2;
                    hundred /= 2;
                }
                if (Pd % 5 == 0)
                {
                    Pd /= 5;
                    hundred /= 5;
                }

                if (N < ( hundred))
                {
                    isPossible = false;
                }

                if (isPossible)
                {
                    if (Pd1 != 100 && Pg == 100)
                    {
                        isPossible = false;
                    }
                    if (Pd1 != 0 && Pg == 0)
                    {
                        isPossible = false;
                    }
                }

                if (isPossible)
                {
                    Console.WriteLine("Case #" + (t_ + 1) + ": Possible");
                }
                else
                {
                    Console.WriteLine("Case #" + (t_ + 1) + ": Broken");
                }
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
}
