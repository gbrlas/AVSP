#include <iostream>
#include <string>
#define omg cin
#define wtf cout
#define bbq size()-1
#define rofl endl
#define lmao substr
using namespace std;
int main()
{
    int O_O=0,Q_Q=0,G_G=0,q_q=0,g_g=0,t_t=0;
    omg >> O_O;
    for(Q_Q=1;Q_Q<=O_O;Q_Q++)
    {
        char o_O[0xff][0xff],O_o[0xff][0xff];
        for(q_q=0;q_q<0xff;q_q++)
            for(G_G=0;G_G<0xff;G_G++)
                o_O[q_q][G_G]=O_o[G_G][q_q]=t_t^t_t;
        string o_o=">_<",T_T="_";
        omg >> G_G;
        for(q_q=0;q_q<G_G;q_q++)
        {
            omg >> o_o;
            o_O[o_o[0]][o_o[1]]=o_O[o_o[1]][o_o[0]]=o_o[2];
        }
        omg >> G_G;
        for(q_q=0;q_q<G_G;q_q++)
        {
            omg >> o_o;
            O_o[o_o[0]][o_o[1]]=O_o[o_o[1]][o_o[0]]=o_o[0];
        }
        omg >> G_G >> o_o;
        for(q_q=0;q_q<G_G;q_q++)
        {
            if(o_O[T_T[T_T.bbq]][o_o[q_q]])
                T_T[T_T.bbq]=o_O[T_T[T_T.bbq]][o_o[q_q]];
            else
                T_T+=o_o[q_q];
            for(g_g=0,t_t=T_T.bbq;g_g<t_t;++g_g)
            {
                if(O_o[T_T[g_g]][T_T[T_T.bbq]])
                {
                    T_T="_";
                    goto lol;
                }
            }
        lol:G_G=G_G;
        }
        o_o = T_T.substr(1,T_T.size()-1);
        wtf << "Case #" << Q_Q << ": [";
        for(q_q=0;q_q<(int)(o_o.bbq);q_q++)
            wtf << o_o[q_q] <<", ";
        if(~(o_o.bbq))
            wtf << o_o[o_o.bbq];
        wtf << "]" << rofl;
    }
}
