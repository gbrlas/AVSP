#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

// #define DBG_PRINT

// String and whether it failed
typedef std::map<std::string, int> dict_t;

// Globals
int L = 0, D = 0, N = 0;

void resetdict(dict_t &dict)
{
    for (dict_t::iterator dit = dict.begin();
         dit != dict.end(); ++dit)
        dit->second = 0;
}

void resetdictnopassed(dict_t &dict)
{
    for (dict_t::iterator dit = dict.begin();
         dit != dict.end(); ++dit)
    {
        if (! dit->second)
            dit->second = -1;
    }
}
void resetdictpassed(dict_t &dict)
{
#ifdef DBG_PRINT
    std::cout << "Reset passed" << std::endl;
#endif
    for (dict_t::iterator dit = dict.begin();
         dit != dict.end(); ++dit)
    {
#ifdef DBG_PRINT
        std::cout << "\"" << dit->first << "\" (" <<
            dit->second << ")" << std::endl;
#endif
        if (dit->second == 1)
            dit->second = 0;
    }
}

int countmatch(std::string testcase, dict_t &dict)
{
    std::string::size_type curPos = 0;

    // Trivial case -- no expansion
    if (testcase.find_first_of('(') == std::string::npos)
    {
        if (dict.find(testcase) != dict.end())
            return 1;
        else
            return 0;
    }

    for (int curIdx = 0; curIdx < L; ++curIdx)
    {
        char curlet = testcase[curPos];
        if (curlet == '(')
        {
            std::string::size_type end = testcase.find_first_of(')', curPos);
#ifdef DBG_PRINT
            std::cout << "Paren from " << curPos << " to " << end << std::endl;
#endif
            std::string expr = testcase.substr(curPos + 1, end - curPos - 1);
            // Bump up the current position after getting the string
            if (end != std::string::npos)
            {
                curPos = end + 1;
                if (curPos > testcase.length())
                {
#ifdef DBG_PRINT
                    std::cout << "long abort" << std::endl;
#endif
                    return 0; // Too long?
                }
            }
#ifdef DBG_PRINT
            std::cout << "Expr: \"" << expr << "\"" << std::endl;
#endif
            bool failed = true;
            for (int l = 0; l < expr.length(); ++l)
            {
                for (dict_t::iterator dit = dict.begin(); dit != dict.end();
                     ++dit)
                {
                    if (dit->second)
                        continue;
#ifdef DBG_PRINT
                    std::cout << "  cmp2: \'" << dit->first[curIdx] <<
                        "\' vs \'" << expr[l] << "\'" << std::endl;
#endif
                    if (dit->first[curIdx] == expr[l])
                    {
#ifdef DBG_PRINT
                        std::cout << "  matched (second is)" << dit->second <<
                            std::endl;
#endif
                        dit->second = 1;
                        failed = false;
                    }
                }
            }
            if (failed)
            {
#ifdef DBG_PRINT
                std::cout << "failed match (regex) at " << curIdx <<
                    std::endl;
#endif
                return 0;
            }
            else
            {
#ifdef DBG_PRINT
                std::cout << "  letter passed" << std::endl;
#endif
            }
            resetdictnopassed(dict);
        }
        else
        {
            bool failed = true;
            for (dict_t::iterator dit = dict.begin(); dit != dict.end(); ++dit)
            {
                if (dit->second)
                    continue;
#ifdef DBG_PRINT
                std::cout << "  cmp: \'" << dit->first[curIdx] <<
                    "\' vs \'" << curlet << "\'" << std::endl;
#endif
                if (dit->first[curIdx] == curlet)
                {
#ifdef DBG_PRINT
                    std::cout << "  matched (second is)" << dit->second <<
                        std::endl;
#endif
                    dit->second = 1;
                    failed = false;
                }
            }
            if (failed)
            {
#ifdef DBG_PRINT
                std::cout << "failed match (normal) at " << curIdx << std::endl;
#endif
                return 0;
            }
            else
            {
#ifdef DBG_PRINT
                std::cout << "  letter passed" << std::endl;
#endif
            }
            resetdictnopassed(dict);
            ++curPos;
        }
        resetdictpassed(dict);
    }
    int passed = 0;
    for (dict_t::iterator dit = dict.begin(); dit != dict.end(); ++dit)
    {
#ifdef DBG_PRINT
        std::cout << "\"" << dit->first << "\" (" <<
            dit->second << ")" << std::endl;
#endif
        if (dit->second != -1)
            ++passed;
    }
    return passed;
}

int main(int argc, char *argv[])
{
    dict_t dict;
    std::vector<std::string> expand;
    std::string nl;

    std::cin >> L >> D >> N;
    getline(std::cin, nl); // flush newline

#ifdef DBG_PRINT
    std::cout << "DBG: " << L << " " << D << " " << N << std::endl;
#endif
    // Read in dictionary
    for (int d = 0; d < D; ++d)
    {
        std::string line;

        getline(std::cin, line);
        if (line.length() > L)
            line.resize(L);
        dict.insert(std::make_pair(line, 0));
    }
#ifdef DBG_PRINT
    {
        std::cout << "Dictionary dump:" << std::endl;
        bool first = true;
        for (dict_t::iterator dit = dict.begin(); dit != dict.end(); ++dit)
        {
            if (! first)
                std::cout << ", ";
            std::cout << "\"" << dit->first << "\"";
            first = false;
        }
        std::cout << std::endl;
    }
#endif
    for (int n = 1; n <= N; ++n)
    {
        int result = 0;
        std::string testcase;

        std::cin >> testcase;
#ifdef DBG_PRINT
        std::cout << "Received line \"" << testcase << "\"" << std::endl;
#endif
        expand.clear();
        resetdict(dict);
        result = countmatch(testcase, dict);
        std::cout << "Case #" << n << ": " << result << std::endl; 
    }
}
/* Keep these lines at the end of the file for VI/VIM: Set shift width to 4 */
/* vi: set sw=4: */
