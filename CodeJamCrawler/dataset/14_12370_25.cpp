using System;
using System.Linq;

class Magic
{
  static void Main(string[] args)
  {
    Byte T = Byte.Parse(Console.ReadLine());
    Byte answer1, answer2;
    const Byte rows = 4;
    string[] nums1, nums2;
    var numbers1 = new Byte[rows];
    var numbers2 = new Byte[rows];

    for (Byte i = 1; i <= T; i++)
    {
      answer1 = Byte.Parse(Console.ReadLine());
      for (Byte j = 1; j <= rows; j++)
      {
        nums1 = Console.ReadLine().Split();
        if (j == answer1)
          for (Byte k = 0; k < rows; k++)
            numbers1[k] = Byte.Parse(nums1[k]);
      }

      answer2 = Byte.Parse(Console.ReadLine());
      for (Byte j = 1; j <= rows; j++)
      {
        nums2 = Console.ReadLine().Split();
        if (j == answer2)
          for (Byte k = 0; k < rows; k++)
            numbers2[k] = Byte.Parse(nums2[k]);
      }

      int matches = 0;
      Byte match = 0;
      int matchCount;
      for (Byte k = 0; k < rows; k++)
      {
        matchCount = numbers2.Count(n => n == numbers1[k]);
        if (matchCount == 1)
          match = numbers2.First(n => n == numbers1[k]);
        matches += matchCount;
      }
      switch (matches)
      {
        case 0:
          Console.WriteLine(String.Format("Case #{0}: Volunteer cheated!", i));
          break;
        case 1:
          Console.WriteLine(String.Format("Case #{0}: {1}", i, match));
          break;
        default:
          Console.WriteLine(String.Format("Case #{0}: Bad magician!", i));
          break;
      }
    }
  }
}