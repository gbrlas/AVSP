#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    if (argc < 3)
        return -1;

    std::ifstream input(argv[1], std::ios::in);
    std::ofstream output(argv[2], std::ios::out);

    unsigned int cases;
    input >> cases;

    for (unsigned int case_id = 1; case_id <= cases; ++case_id)
    {
        unsigned int A;
        unsigned int B;
        input >> A >> B;

        int count = 0;

        for (unsigned int C = A; C < B; ++C)
        {
            unsigned int D = C;
            unsigned int digits = 1;
            while (D >= digits*10)
                digits *= 10;

            do
            {
                unsigned int low = D%10;
                D = D/10 + low*digits;

                if (C < D && D <= B)
                    ++count;

            } while (D != C);
        }

        output << "Case #" << case_id << ": " << count << std::endl;
    }

    return 0;
}
