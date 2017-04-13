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

            int T = int.Parse(Console.ReadLine());
            for (int t_ = 0; t_ < T; t_++)
            {
                int numberCount = int.Parse(Console.ReadLine());
                List<int> numbers = Console.ReadLine().Split(' ').Select(a => Convert.ToInt32(a)).OrderByDescending(b => b).ToList();
                List<string> binaryNumbers = numbers.Select(b => convertToBinary(b)).ToList();
                int[][] array = new int[numbers.Count][];
                int maxLength = binaryNumbers[0].Length;
                List<int> firstBrotherI = new List<int>();
                List<int> secondBrotherI = new List<int>();
                for (int i = 0; i < numbers.Count; i++)
                {
                    array[i] = new int[maxLength];
                    for (int j = 0; j < binaryNumbers[i].Length; j++)
                    {
                        array[i][j] = Convert.ToInt32(binaryNumbers[i][j].ToString());
                    }
                }
                bool isPossible = true;
                for (int j = 0; j < maxLength; j++)
                {
                    int sum = 0;
                    for (int i = 0; i < numbers.Count; i++)
                    {
                        sum += array[i][j];
                    }
                    if (sum % 2 != 0)
                    {
                        isPossible = false;
                        break;
                    }
                }
                if (isPossible == false)
                {
                    //for (int j = numbers.Count - 1; j >= 0; j--)
                    //{
                    //    List<int> listOfIWith1 = new List<int>();
                    //    for (int i = 0; i < numbers.Count; i++)
                    //    {
                    //        if (firstBrotherI.Any(a => a == i)
                    //            || secondBrotherI.Any(b => b == i))
                    //        {
                    //            continue;
                    //        }
                    //        if (array[i][j] == 1)
                    //        {
                    //            listOfIWith1.Add(i);
                    //        }
                    //    }

                    //}
                    Console.WriteLine("Case #" + (t_ + 1) + ": NO");
                }
                else
                {
                    Console.WriteLine("Case #" + (t_ + 1) + ": " + (numbers.Sum() - numbers[numbers.Count - 1]));
                }
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

    private static string convertToBinary(int number)
    {
        StringBuilder stringBuilder = new StringBuilder();
        while (number > 0)
        {
            stringBuilder.Append(number % 2);
            number /= 2;
        }
        return stringBuilder.ToString();
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
