using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

public static class IOHelper
{
    public static int ReadInt(this StreamReader infile)
    {
        string line = infile.ReadLine();
        return int.Parse(line);
    }

    public static int[] ReadIntArr(this StreamReader infile)
    {
        string line = infile.ReadLine();
        int[] data = Array.ConvertAll(line.Split(' '), s => int.Parse(s));
        return data;
    }
}

class DSmall
{

    const string Test = "small-attempt0";

    static double Sqr(double x)
    {
        return x * x;
    }
    static int Main(string[] args)
    {

        using (StreamReader infile = File.OpenText(@"C:\TopCoder\CodeJam\Inputs\D-" + Test + ".in"))
        using (StreamWriter outfile = File.CreateText(@"C:\TopCoder\CodeJam\Inputs\D-" + Test + ".out"))
        {
            int T = infile.ReadInt();
            for (int testcase = 1; testcase <= T; testcase++)
            {
                int N = infile.ReadInt();
                int[] X = new int[N];
                int[] Y = new int[N];
                int[] R = new int[N];
                for (int i = 0; i < N; i++)
                {
                    int[] data = infile.ReadIntArr();
                    X[i] = data[0];
                    Y[i] = data[1];
                    R[i] = data[2];
                }


                
                double rmax = 1000 * 4;
                double rmin = 0;
                if (N == 1)
                {
                    rmax = R[0];
                }

                if (N == 2)
                {
                    rmax = Math.Max(R[0], R[1]);
                }

                if (N == 3)
                {
                    for (int eps = 0; eps < 70; eps++)
                    {
                        double rcur = (rmax + rmin) / 2;

                        bool ok = false;

                        for (int i = 0; i < X.Length && !ok; i++)
                        {
                            for (int ii = i + 1; ii < X.Length && !ok; ii++)
                            {
                                double len = Math.Sqrt(Sqr(X[i] - X[ii]) + Sqr(Y[i] - Y[ii]))  + R[i] + R[ii];
                                if (len / 2 <= rcur && R[0 + 1 + 2 - i - ii] <= rcur)
                                {
                                    ok = true;
                                }
                                /*
                                double len = Math.Sqrt(Sqr(X[i] - X[ii]) + Sqr(Y[i] - Y[ii]));


                                double part = (len - R[i]) / (len + R[i] + R[ii]);

                                double x1 = X[i] + (X[ii] - X[i]) * part;
                                double y1 = Y[i] + (Y[ii] - Y[i]) * part;

                                if (Math.Sqrt(Sqr(X[i] - x1) + Sqr(Y[i] - y1)) + R[i] <= rcur
                                 && Math.Sqrt(Sqr(X[ii] - x1) + Sqr(Y[ii] - y1)) + R[ii] <= rcur
                                 && R[0 + 1 + 2 - i - ii] <= rcur)
                                {
                                    ok = true;
                                } */
                            }
                        }
                        if (ok)
                        {
                            rmax = rcur;
                        }
                        else
                        {
                            rmin = rcur;
                        }
                    }
                }

                outfile.WriteLine("Case #{0}: {1}", testcase, rmax);
            }
        }
        return 0;
    }
}
