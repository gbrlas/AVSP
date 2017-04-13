#include <iostream>
#include <fstream>

#define max(a,b) (a > b ? a : b)

int main()
{
    std::fstream input("input.in", std::fstream::in);
    std::fstream output("output.out", std::fstream::out);

    int test_cases;
    input >> test_cases;

    for (int test_case = 0; test_case < test_cases; test_case++)
    {
        int nb;
        input >> nb;

        int buttons[nb];
        char who[nb];
        for (int i=0; i < nb; i++)
        {
            input >> who[i] >> buttons[i];
        }

        int o = 1, b = 1;
        int time = 0;
        int last_o = 0, last_b = 0;
        for (int i=0; i < nb; i++)
        {
            int free_time = time - (who[i] == 'O' ? last_o : last_b);
            int time_need = max(abs(buttons[i] - (who[i] == 'O' ? o : b)) - free_time, 0) + 1;
            time += time_need;
            (who[i] == 'O' ? o : b) = buttons[i];
            (who[i] == 'O' ? last_o : last_b) = time;
        }

        output << "Case #" << test_case+1 << ": " << time << std::endl;
    }

    system("pause");

    return 0;
}
