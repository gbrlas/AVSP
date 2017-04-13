#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <glpk.h>

int main(int argc, char* argv[])
{
    if (argc != 3)
        return 0;

    // opening file
    std::ifstream file(argv[1]);
    std::ofstream out(argv[2]);
    if (file.fail() || out.fail())
    {
        std::cout << "the file could not be opened !" << std::endl;
        return 1;
    }

    // read number of cases
    unsigned int tcs;
    file >> tcs;

    for (unsigned int tc = 1; tc <= tcs; ++tc)
    {
        unsigned int N;

        file >> N;

        unsigned long S[N];
        for (unsigned int i = 0; i < N; ++i)
            file >> S[i];

        glp_prob* prob = glp_create_prob();
        glp_set_prob_name(prob, "blah");
        glp_set_obj_dir(prob, GLP_MAX);

        // let's add our variables
        glp_add_cols(prob, 2*N);

        for (unsigned int i = 1; i <= N; ++i)
        {
            glp_set_col_bnds(prob, i, GLP_DB, 0.0, 1.0);
            glp_set_col_kind(prob, i, GLP_BV);
            glp_set_obj_coef(prob, i, 0.0);

            glp_set_col_bnds(prob, i + N, GLP_DB, 0.0, 1.0);
            glp_set_col_kind(prob, i + N, GLP_BV);
            glp_set_obj_coef(prob, i + N, 0.0);
        }

        int ia[6*N + 1];
        int ja[6*N + 1];
        double ar[6*N + 1];

        // here are constraints
        glp_add_rows(prob, N + 3);

        glp_set_row_bnds(prob, 1, GLP_FX, 0, 0);
        glp_set_row_bnds(prob, 2, GLP_LO, 1.0, 0);
        glp_set_row_bnds(prob, 3, GLP_LO, 1.0, 0);
        for (unsigned int i = 0; i < N; ++i)
        {
            ia[i*6 + 1] = 1;
            ja[i*6 + 1] = i + 1;
            ar[i*6 + 1] = S[i];

            ia[i*6 + 2] = 1;
            ja[i*6 + 2] = i + 1 + N;
            ar[i*6 + 2] = -(double)S[i];

            ia[i*6 + 3] = 2;
            ja[i*6 + 3] = i + 1;
            ar[i*6 + 3] = 1.0;

            ia[i*6 + 4] = 3;
            ja[i*6 + 4] = i + 1 + N;
            ar[i*6 + 4] = 1.0;

            glp_set_row_bnds(prob, i + 4, GLP_UP, 0.0, 1.0);

            ia[i*6 + 5] = i + 4;
            ja[i*6 + 5] = i + 1;
            ar[i*6 + 5] = 1.0;

            ia[i*6 + 6] = i + 4;
            ja[i*6 + 6] = i + 1 + N;
            ar[i*6 + 6] = 1.0;
        }

        /*double tst[3+N+1][2*N+1];
        for (int i = 1; i <= 3+N; ++i)
        {
            for (int j = 1; j <= 2*N; ++j)
                tst[i][j] = 0;
        }

        for (int i = 1; i <= 6*N; ++i)
            tst[ia[i]][ja[i]] = ar[i];

        for (int i = 1; i <= 3+N; ++i)
        {
            for (int j = 1; j <= 2*N; ++j)
                std::cout << tst[i][j] << " ";
            std::cout << std::endl;
        }*/

        glp_load_matrix(prob, 6*N, ia, ja, ar);
        glp_simplex(prob, NULL);
        glp_intopt(prob, NULL);

        out << "Case #" <<  tc << ": " << std::endl;

        for (unsigned int i = 1; i <= N; ++i)
        {
            if (glp_mip_col_val(prob, i) > 0.5)
                out << S[i-1] << " ";
        }
        out << std::endl;

        for (unsigned int i = 1; i <= N; ++i)
        {
            //std::cout << glp_mip_col_val(prob, i+N) << " ";
            if (glp_mip_col_val(prob, i+N) > 0.5)
                out << S[i-1] << " ";
        }
        out << std::endl;

        glp_delete_prob(prob);
    }

    return 0;
}

