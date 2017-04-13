using System;
using System.IO;

namespace SnapperChain
{
  class Program
  {
    static void Main(string[] args)
    {
      if (args.Length == 0)
      {
        Console.WriteLine("Specify path to input file!");
        Console.Read();
        return;
      }
      else
      {
        ProcessFile(args[0]);
        Console.WriteLine("Finished processing file '{0}'", args[0]);
        Console.Read();
      }
    }

    static void ProcessFile(string FilePath)
    {
      string line;
      int CaseNumber=0;
      string[] numbers;
      Chain sc;
      int N, K;
      StreamReader sr = new StreamReader(FilePath);
      StreamWriter sw = new StreamWriter(FilePath + ".out");
      
      int T = Convert.ToInt32(sr.ReadLine());
      while ((line = sr.ReadLine()) != null)
      {
        CaseNumber++;
        numbers = line.Split(' ');
        N=Convert.ToInt32(numbers[0]);
        K=Convert.ToInt32(numbers[1]);
        sc=new Chain(N);
          sw.WriteLine("Case #{0}: {1}", CaseNumber, BoolToState(sc.MultipleSnap(K)));
      }
      sw.Close();
      sr.Close();
    }
    static string BoolToState(bool value)
    {
      if (value)
        return "ON";
      else
        return "OFF";
    }
  }
}
class Snapper
  {
    public bool state = false;
    public bool PowerIn = false;
    public bool PowerOut
    {
      get {return PowerIn && state;}
    }
    public void Toggle()
    {
      if (PowerIn) state = !state;
    }
  }

  class Chain
  {
    Snapper[] snappers;
    public Chain(int size)
    {
      int i;
      snappers = new Snapper[size];
      for(i=0;i<size;i++) snappers[i]=new Snapper();
      snappers[0].PowerIn = true; //first snapper is plugged in the socket
    }
    void SnapOnce()
    {
      int i;
      for (i = 0; i < snappers.Length; i++)
        snappers[i].Toggle(); //update state
      for (i = 1; i < snappers.Length; i++)
        snappers[i].PowerIn = snappers[i - 1].PowerOut; //update power status
    }
    public bool MultipleSnap(int count)
    {
      int i;
      for (i = 0; i < count; i++) SnapOnce();
      return snappers[snappers.Length-1].PowerOut;
    }
  }