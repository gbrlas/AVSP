#include <iostream>
#include <cmath>

#define SMALL
#ifdef SMALL
  #define FILE_IN "C-small-attempt0.in"
  #define FILE_OUT "C-small.out"
#else
  #define FILE_IN "C-large.in"
  #define FILE_OUT "C-large.out"
#endif

using namespace std;


class Interval
{
private:
  int sqRootLengthA, sqRootLengthB, ans;
  double A, B;
  long sqRootA, sqRootB;
  bool isEnd;
  int number[7], sqNumber[14];
  
  int Length( long n )
  {
    int l = 0;
  
    while (n > 0)
    {
      l++;
	  n /= 10;
    }
    return l;
  }

  long MakeNumber( int length )
  {
    long n = 0;

	for (int i = 0; i < length; i++)
	  n += number[i] * pow(10, length - i - 1);
	return n;
  }

  bool IsPolindrom( double n )
  {
    int length = 0;
	double cur = n;

    while (cur > 1)
	{
	  sqNumber[length] = cur - floor(cur / 10) * 10;
	  cur /= 10;
	  length++;
	}
    for (int i = 0; i < length / 2; i++)
	  if (sqNumber[i] != sqNumber[length - 1 - i])
        return false;
	return true;
  }

  void MakePolindroms( int start, int length )
  {
    double n;
	
	if (length == 0)
	{
	  n = MakeNumber((start - 1) * 2 + 2);
	  if (A <= n * n && n * n <= B)
	  {
	    if (IsPolindrom(n * n))
	      ans++;
	  }
	  return;
	}

	if (length == 1)
	{
	  for (int i = 0; i < 10; i++)
	  {
	    number[start] = i;
	    n = MakeNumber((start + 1) * 2 - 1 + 2);
	    if (IsPolindrom(n * n))
	      ans++;
	  }
	  return;
	}

	for (int i = 0; i < 10; i++)
	{
	  number[start] = i;
  	  number[start + length - 1] = i;
	  MakePolindroms(start + 1, length - 2);
	}
  }
public:
  void Init()
  {
    cin >> A;
    cin >> B;
    sqRootA = (long)sqrt(A);
    sqRootB = (long)sqrt(B);
	sqRootLengthA = Length(sqRootA);
	sqRootLengthB = Length(sqRootB);
    isEnd = false;
	ans = 0;
	if (sqRootB == 1e7)
	{
	  sqRootLengthB--;
	}
  }
  int GetAnswer()
  {
	for (int length = sqRootLengthA; length <= sqRootLengthB; length++)
	{
      if (length == 1)
	  {
	    for (int i = (int)(sqRootA / (long)pow(10, length - 1)); i <= 3; i++)
		  if (A <= i * i && i * i <= B)
		    ans++;
	    continue;
	  }
	  for (int i = 1;  i < 10; i++)
	  {
	    number[0] = i;
  	    number[length - 1] = i;
	    MakePolindroms(1, length - 2);
	  }
	}
    return ans;
  }
};

void main()
{
  int T;
  Interval a;

  freopen(FILE_IN, "r" , stdin);
  freopen(FILE_OUT , "w" , stdout);
  cin >> T;
  for (int caseNumber = 1; caseNumber <= T; caseNumber++)
  {
	a.Init();
    cout << "Case #" << caseNumber << ": " << a.GetAnswer() << endl;
  }
}