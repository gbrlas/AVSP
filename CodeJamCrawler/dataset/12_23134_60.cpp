#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>


int main(int argc, char *argv[])
{
    int ncases;
    std::cin >> ncases;

    for(int i = 0; i < ncases; i++)
    {
        int ngooglers, nsurprises, target;
        std::cin >> ngooglers >> nsurprises >> target;


        std::vector<int> scores(ngooglers);
        for(int j = 0; j < ngooglers; j++)
        {
            std::cin >> scores[j];
        }

        std::sort(scores.begin(), scores.end());
        std::reverse(scores.begin(), scores.end());

        int count = 0;
        for(int j = 0; j < scores.size(); j++)
        {
            // can achieve with surprise
            if(scores[j] >= target+std::max(0, target-2)*2)
            {
                // achieved without surprise
                if(scores[j] >= target+std::max(0, target-1)*2)
                {
                    ++count;
                }
                else if(nsurprises>0) // use a surprise
                {
                    --nsurprises;
                    ++count;
                }
            }
        }

        std::cout << "Case #" << i+1 << ": " << count << std::endl;
    }



}
