#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>


int main(int argc, char *argv[])
{
    int ncases;
    std::cin >> ncases;

    for(int i = 0; i < ncases; i++)
    {
        int A, B;
        std::cin >> A >> B;

        int scale = 1, ndigits=1;
        while(scale*10 < std::max(A, B))
        {
            scale *= 10;
            ++ndigits;
        }

        int count = 0;
        std::set<std::pair<int, int> > recycles;
        for(int n = A; n <= B; n++)
        {
            int m = n;
            for(int d = 1; d < ndigits; d++)
            {
                m = m/scale + (m%scale)*10;

                if(n<m && m>=A && m<=B)
                {
                    if(recycles.find(std::pair<int, int>(n, m)) == recycles.end())
                    {
                        recycles.insert(std::pair<int, int>(n, m));
                        ++count;
                    }
                }
            }
        }

        std::cout << "Case #" << i+1 << ": " << count << std::endl;
    }
}
