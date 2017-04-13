using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

class Program
{
    static void Main(string[] args)
    {
        TextReader textReader = null;
        TextWriter textWriter = null;

        string filePath = @"C:\Users\Amit\Desktop\New folder\";
        string inputFileName = "A-small-attempt2.in";
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
                int N = int.Parse(input[0]);
                int time = 0;
                int oPosition = 1;
                int bPosition = 1;
                for (int i = 0; i < N; i++)
                {
                    string color = input[i * 2 + 1];
                    int button = int.Parse(input[i * 2 + 2]);

                    string otherColor = "";

                    int otherButton = 0;
                    int j = 0;
                    while (otherColor != (color == "O" ? "B" : "O") && input.Length > i * 2 + j + 4)
                    {
                        otherColor = input[i * 2 + j + 3];
                        otherButton = int.Parse(input[i * 2 + j + 4]);
                        j += 2;
                    }

                    if (color == "O")
                    {
                        while (oPosition != button)
                        {
                            if (button > oPosition)
                            {
                                oPosition++;
                                time++;
                            }
                            else
                            {
                                oPosition--;
                                time++;
                            }
                            if (otherColor == "B")
                            {
                                if (otherButton > bPosition)
                                {
                                    bPosition++;
                                }
                                else if (otherButton < bPosition)
                                {
                                    bPosition--;
                                }
                            }
                        }
                        time++;
                        if (otherColor == "B")
                        {
                            if (otherButton > bPosition)
                            {
                                bPosition++;
                            }
                            else if (otherButton < bPosition)
                            {
                                bPosition--;
                            }
                        }
                    }
                    else
                    {
                        while (bPosition != button)
                        {
                            if (button > bPosition)
                            {
                                bPosition++;
                                time++;
                            }
                            else
                            {
                                bPosition--;
                                time++;
                            }
                            if (otherColor == "O")
                            {
                                if (otherButton > oPosition)
                                {
                                    oPosition++;
                                }
                                else if (otherButton < oPosition)
                                {
                                    oPosition--;
                                }
                            }
                        }
                        time++;
                        if (otherColor == "O")
                        {
                            if (otherButton > oPosition)
                            {
                                oPosition++;
                            }
                            else if (otherButton < oPosition)
                            {
                                oPosition--;
                            }
                        }
                    }
                }
                Console.Write("Case #" + (t_ + 1) + ": " + time + "\n");
            }
        }
        catch (Exception)
        {
        }
        finally
        {
            textReader.Close();
            textWriter.Close();
        }
    }

    private static List<int> getListInt(int n)
    {
        List<int> a = new List<int>();
        for (int i = 0; i < n; i++)
        {
            a.Add(0);
        }
        return a;
    }
    private static List<bool> getListBool(int n)
    {
        List<bool> a = new List<bool>();
        for (int i = 0; i < n; i++)
        {
            a.Add(false);
        }
        return a;
    }
}
