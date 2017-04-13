#include <cstdio>
#include <vector>

using namespace std;

#define UPPERBOUND 100

int reverseNum(long long n)
{
	int reverseN = 0;

	while(n)
	{
		reverseN = reverseN * 10 + n % 10;
		n /= 10;
	}

	return reverseN;
}

int isPalindrome(long long n)
{
	return n == reverseNum(n);
}

void generateSortedFairAndSquareNum(long long upperbound, vector<long long> & listNum)
{
	long long n, squareN;

	listNum.clear();

	for(n = 1; n <= upperbound; n++)
	{
		squareN = n * n;
		if(isPalindrome(n) && isPalindrome(squareN))
		{
			// It is a fair and square number
			listNum.push_back(squareN);
		}
	}
}

// Find the smallest index i such that listNum[i] <= key < listNum[i + 1]
//
// Convention: listNum[-1] = -INFINITY, and listNum[N] = INFINITY
//	where N is the size of listNum
//
// Assumption: listNum is sorted
int findSupremum(const vector<long long> & listNum, long long key)
{
	int N = (int) listNum.size();

	if(listNum[N - 1] <= key)
		return N - 1;
	if(listNum[0] > key)
		return -1;

	int left = 0, right = N - 2, mid;

	while(left <= right)
	{
		mid = left + (right - left) / 2;

		if(listNum[mid] <= key && listNum[mid + 1] > key)
			return mid;

		if(listNum[mid] > key)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return -1;	// Dummy
}

// Find the smallest index i such that listNum[i - 1] < key <= listNum[i]
//
// Convention: listNum[-1] = -INFINITY, and listNum[N] = INFINITY
//	where N is the size of listNum
//
// Assumption: listNum is sorted
int findInfimum(const vector<long long> & listNum, long long key)
{
	int N = (int) listNum.size();

	if(listNum[0] >= key)
		return 0;
	if(listNum[N - 1] < key)
		return N;

	int left = 1, right = N - 1, mid;
	
	while(left <= right)
	{
		mid = left + (right - left) / 2;
		
		if(listNum[mid] >= key && listNum[mid - 1] < key)
			return mid;

		if(listNum[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return -1;	// Dummy
}
int main(void)
{
	int T, caseId;
	long long L, U, lowerInd, upperInd, numFairAndSquare, upperBound;
	vector<long long> fairAndSquareList;

	upperBound = (long long) UPPERBOUND;
	generateSortedFairAndSquareNum(upperBound, fairAndSquareList);

	/*printf("Size = %d\n", (int) fairAndSquareList.size());
	for(int i = 0; i < (int)fairAndSquareList.size(); i++)
		printf("%lld\n", fairAndSquareList[i]);*/

	freopen("in.txt", "r", stdin);
	freopen("out.out", "w", stdout);

	scanf("%d", &T);
	caseId = 1;
	while(caseId <= T)
	{
		scanf("%lld %lld", &L, &U);
		
		lowerInd = findInfimum(fairAndSquareList, L);
		upperInd = findSupremum(fairAndSquareList, U);
		
		if(upperInd < lowerInd)
			numFairAndSquare = 0;
		else
			numFairAndSquare = upperInd - lowerInd + 1;

		printf("Case #%d: %lld\n", caseId, numFairAndSquare); 
		caseId++;
	}

	return 0;
}

