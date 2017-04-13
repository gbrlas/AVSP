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

            int T = int.Parse(Console.ReadLine());

            for (int t_ = 0; t_ < T; t_++)
            {
                int N = Convert.ToInt32(Console.ReadLine());
                int[][] win = new int[N][];
                char[][] b = new char[N][];
                decimal[] WP = new decimal[N];
                decimal[] OWP = new decimal[N];
                decimal[] OOWP = new decimal[N];
                for (int i = 0; i < N; i++)
                {
                    b[i] = Console.ReadLine().ToCharArray();
                    for (int j = 0; j < N; j++)
                    {
                        win[i] = new int[N];
                    }
                    decimal c = (decimal)b[i].Where(a => a == '1').Count();

                    WP[i] = (decimal)b[i].Where(a => a == '1').Count() / (decimal)b[i].Where(a => a == '1' || a == '0').Count();
                }
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < b[i].Length; j++)
                    {
                        if (b[i][j] == '1' || b[i][j] == '0')
                        {
                            OWP[i] += ((WP[j] * (decimal)b[j].Where(a => a == '1' || a == '0').Count()) - (b[j][i] == '1' ? 1 : 0)) / ((decimal)b[j].Where(a => a == '1' || a == '0').Count() - 1);
                        }
                    }
                    OWP[i] /= ((decimal)b[i].Where(a => a == '1' || a == '0').Count());
                }
                
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < b[i].Length; j++)
                    {
                        if (b[i][j] == '1' || b[i][j] == '0')
                        {
                            OOWP[i] += OWP[j];
                        }
                    }
                    OOWP[i] /= (decimal)b[i].Where(a => a == '1' || a == '0').Count();
                }

                Console.WriteLine("Case #" + (t_ + 1) + ":");
                for (int i = 0; i < N; i++)
                {
                    Console.WriteLine((decimal)0.25 * WP[i] + (decimal)0.50 * OWP[i] + (decimal)0.25 * OOWP[i]);
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
