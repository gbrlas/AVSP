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
                string[] input = Console.ReadLine().Split(' ');
                int R = Convert.ToInt32(input[0]);
                int C = Convert.ToInt32(input[1]);
                char[][] oTiles = new char[R][];
                char[][] rTiles = new char[R][];
                for (int i = 0; i < R; i++)
                {
                    oTiles[i] = Console.ReadLine().ToCharArray();

                }
                bool isPossible = true;
                for (int i = 0; i < R - 1; i++)
                {
                    for (int j = 0; j < C - 1; j++)
                    {
                        if (oTiles[i][j] == '.')
                        {
                            continue;
                        }
                        if (oTiles[i][j] == '#' && oTiles[i][j + 1] == '#' && oTiles[i + 1][j] == '#' && oTiles[i + 1][j + 1] == '#')
                        {
                            oTiles[i][j] = '/';
                            oTiles[i][j + 1] = '\\';
                            oTiles[i + 1][j] = '\\';
                            oTiles[i + 1][j + 1] = '/';
                        }
                    }
                }
                for (int i = 0; i < R; i++)
                {
                    for (int j = 0; j < C; j++)
                    {
                        if (oTiles[i][j] == '.')
                        {
                            continue;
                        }
                        if (oTiles[i][j] == '#')
                        {
                            isPossible = false;
                            break;
                        }
                    }
                }
                Console.WriteLine("Case #" + (t_ + 1) + ":");
                if (isPossible == false)
                {
                    Console.WriteLine("Impossible");
                }
                else
                {
                    for (int i = 0; i < R; i++)
                    {
                        for (int j = 0; j < C; j++)
                        {
                            Console.Write(oTiles[i][j]);
                        }
                        Console.WriteLine();
                    }
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
