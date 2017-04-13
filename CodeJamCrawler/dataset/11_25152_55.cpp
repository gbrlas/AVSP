#include <iostream>
#include <fstream>
#include <list>

int main()
{
    std::fstream input("input.in", std::fstream::in);
    std::fstream output("output.out", std::fstream::out);

    int test_cases;
    input >> test_cases;

    for (int test_case = 0; test_case < test_cases; test_case++)
    {
        int C;
        input >> C;

        char combs[C][3];
        for (int i=0; i < C; i++)
            input >> combs[i];

        int D;
        input >> D;

        char opps[D][2];
        for (int i=0; i < D; i++)
            input >> opps[i];

        int N;
        input >> N;
        std::list<char> elems;
        for (int i=0; i < N; i++)
        {
            char e;
            input >> e;
            std::cout << e;
            if (elems.empty())
                elems.push_back(e);
            else
            {
                int j;
                char f = *(elems.rbegin());
                for (j=0; j < C; j++)
                {
                    if ((combs[j][0] == e && combs[j][1] == f) || (combs[j][1] == e && combs[j][0] == f))
                    {
                        elems.pop_back();
                        elems.push_back(combs[j][2]);
                        break;
                    }
                }

                if (j == C)
                {
                    for (j=0; j < D; j++)
                    {
                        if (opps[j][0] == e)
                        {
                            for (std::list<char>::iterator k = elems.begin(); k != elems.end(); k++)
                            {
                                if (opps[j][1] == *k)
                                {
                                    elems.clear();
                                    break;
                                }
                            }
                        }
                        else if (opps[j][1] == e)
                        {
                            for (std::list<char>::iterator k = elems.begin(); k != elems.end(); k++)
                            {
                                if (opps[j][0] == *k)
                                {
                                    elems.clear();
                                    break;
                                }
                            }
                        }
                        if (elems.empty())
                            break;
                    }
                    if (j == D)
                        elems.push_back(e);
                }
            }

            std::cout << "[";
            for (std::list<char>::iterator i = elems.begin(); i != elems.end(); i++)
                std::cout << *i;
            std::cout << "]" << std::endl;
        }

        output << "Case #" << test_case+1 << ": [";
        if (!elems.empty())
        {
            std::list<char>::iterator i = elems.begin();
            output << *i;
            for (i++; i != elems.end(); i++)
                output << ", " << *i;
        }
        output << "]" << std::endl;
    }

    system("pause");

    return 0;
}
