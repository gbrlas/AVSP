#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

// #define DBG_PRINT

// Globals
int T = 0;

bool isHappy(unsigned long num, unsigned int base)
{
    std::set<unsigned long> visited;
    unsigned long iter, sum, newsum;

    visited.insert(num);
    sum = num;
#ifdef DBG_PRINT
    std::cout << std::endl << "Num: " << num << " base: " << base << std::endl;
#endif
    while (sum != 1)
    {
        newsum = 0;
        for (iter = sum; iter > 0; iter /= base)
        {
            unsigned long dig = iter % base;
            newsum += (dig * dig);
        }
        if (visited.find(newsum) != visited.end())
            return false;
        else
            visited.insert(newsum);
        sum = newsum;
    }
    return true;
}

unsigned int commonhappy(std::vector<unsigned int> &basevec)
{
    unsigned int trial = 2;

    while (trial > 1) // Wrap?
    {
        bool failed = false;
#ifdef DBG_PRINT
        std::cout << "Testing " << trial << std::endl;
#endif
        for (std::vector<unsigned int>::const_iterator baseit = basevec.begin();
             baseit != basevec.end(); ++baseit)
        {
            if (! isHappy(trial, *baseit))
            {
                failed = true;
#ifdef DBG_PRINT
                std::cout << "  " << trial << " failed for " << *baseit <<
                    std::endl;
#endif
                break;
            }
        }
        if (! failed)
            return trial;
        ++trial;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    std::string nl;

    std::cin >> T;
    getline(std::cin, nl); // flush newline

#ifdef DBG_PRINT
    std::cout << "DBG: " << T << std::endl;
#endif
    for (int t = 1; t <= T; ++t)
    {
        unsigned int result = 0;
        std::string testcase;
        std::vector<unsigned int> basevec;

        getline(std::cin, testcase);
#ifdef DBG_PRINT
        std::cout << "Received line \"" << testcase << "\"" << std::endl;
#endif
        std::istringstream iss(testcase);
        unsigned int num;
        while (iss >> num)
        {
            basevec.push_back(num);
        }
#ifdef DBG_PRINT
        std::cout << "Read " << basevec.size()  << " entries" << std::endl;
#endif
        result = commonhappy(basevec);;
        std::cout << "Case #" << t << ": " << result << std::endl; 
    }
}
/* Keep these lines at the end of the file for VI/VIM: Set shift width to 4 */
/* vi: set sw=4: */
