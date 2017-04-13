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
        int N;
        input >> N;

        int vals[N];
        for (int i=0; i<N; i++)
            input >> vals[i];

        bool field[N];
        memset(field, 0, N*sizeof(bool));

        long best_value = -1;
        while (true)
        {
            int i = 0;
            while (field[i] == true)
            {
                field[i] = false;
                i++;
            }
            field[i] = true;

            i = 0;
            while (field[i] == true)
                i++;
            if (i == N)
                break;

            long sean_left = 0;
            long sean_right = 0;

            // is crying ?
            for (i=0; i < N; i++)
            {
                if (field[i])
                    sean_left = sean_left xor vals[i];
                else
                    sean_right = sean_right xor vals[i];
            }

            if (sean_left == sean_right)
            {
                long pat_left = 0;
                long pat_right = 0;
                for (i=0; i < N; i++)
                {
                    if (field[i])
                        pat_left += vals[i];
                    else
                        pat_right += vals[i];
                }

                best_value = max(max(pat_left, pat_right), best_value);
            }
        }

        output << "Case #" << test_case+1 << ": ";
        if (best_value == -1)
            output << "NO";
        else
            output << best_value;
        output << std::endl;
    }

    system("pause");

    return 0;
}
