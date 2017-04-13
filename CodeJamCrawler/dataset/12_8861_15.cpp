using System;
using System.Text;

class languages
{
  static void Main(string[] args)
  {
    string G;
    string S;
    int j;
    int index;
    StringBuilder sb;

    string English = "abcdefghijklmnopqrstuvwxyz";
    string Googler = "ynficwlbkuomxsevzpdrjgthaq";

    int CaseNum = Convert.ToInt32(Console.ReadLine());
    //Console.WriteLine("CaseNum = {0}", CaseNum);
    for (int i = 1; i <= CaseNum; i++)
    {
      G = Console.ReadLine();
      //Console.WriteLine("G = '{0}'", G);
      sb = new StringBuilder(G.Length);
      for (j = 0; j < G.Length; j++)
      {
        if (G[j] == ' ')
        {
          sb.Append(G[j]);
        }
        else
        {
          index = Googler.IndexOf(G[j]);
          sb.Append(English[index]);
        }
      }
      S = sb.ToString();
      Console.WriteLine("Case #{0}: {1}", i, S);
    }
  }
}