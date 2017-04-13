using System;

class Cookie
{
  static void Main(string[] args)
  {
    Byte T = Byte.Parse(Console.ReadLine());
    Double time1 = 0.0;
    const Double minRate = 2.0;
    string[] nums;
    Double C, F, X;
    var fmt = new System.Globalization.NumberFormatInfo();  
    fmt.NumberDecimalSeparator = ".";
    fmt.NumberDecimalDigits = 7;
    Double farmTime;
    Double rate;
    Double xTime;
    Double cTime;
    for (Byte i = 1; i <= T; i++)
    {
      nums = Console.ReadLine().Split();
      C = Double.Parse(nums[0], fmt);
      F = Double.Parse(nums[1], fmt);
      X = Double.Parse(nums[2], fmt);

      time1 = X / minRate;
      rate = minRate;
      farmTime = 0.0;
      cTime = 0.0;
      while (farmTime < time1)
      {
        if (farmTime > 0.0)
          time1 = farmTime;
        xTime = X / (rate + F);
        cTime += C / rate;
        farmTime = cTime + xTime;
        rate += F;
      }
      Console.WriteLine(String.Format(fmt, "Case #{0}: {1:F}", i,
        Math.Min(time1, farmTime)));
    }
  }
}