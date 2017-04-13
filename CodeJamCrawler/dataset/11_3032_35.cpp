#include <fstream>
using std :: ifstream;
using std :: ofstream;
#include <string>
using std :: string;

const int MAX_ALL_TEAMS = 22;


int main ()
{
    ifstream input ("input.txt");
    ofstream output ("output.txt");
    
    int all_query = 0;
    input >> all_query;
    
    for (int query = 0; query < all_query; ++query)
    {
        int all_teams = 0;
        input >> all_teams;
        
        char result[MAX_ALL_TEAMS][MAX_ALL_TEAMS] = {{}};
        for (int team = 0; team < all_teams; ++team)
        {
            string in_res;
            input >> in_res;
            for (int i = 0; i < all_teams; ++i)
                result[team][i] = in_res[i];
        }
        
        double wp[MAX_ALL_TEAMS] = {},
               owp[MAX_ALL_TEAMS] = {},
               oowp[MAX_ALL_TEAMS] = {};
               
        for (int team = 0; team < all_teams; ++team)
        {
            int all_wins = 0,
                all_games = 0;
            for (int i = 0; i < all_teams; ++i)
                if (result[team][i] != '.')
                {
                   ++all_games;
                   if (result[team][i] == '1')
                       ++all_wins;
                } 
                
            wp[team] = static_cast<double> (all_wins) / 
                       static_cast<double> (all_games);
        }
        
        for (int team = 0; team < all_teams; ++team)
        {
            int all_games = 0;
            double sum_wp = 0.00;
            for (int i = 0; i < all_teams; ++i)
                if (result[team][i] != '.')
                {
                   ++all_games;
                   int all_games_opp = 0,
                       all_wins_opp = 0;
                   for (int j = 0; j < all_teams; ++j)
                       if (result[i][j] != '.' && j != team)
                       {
                           ++all_games_opp;
                           if (result[i][j] == '1')
                               ++all_wins_opp;
                       }
                   sum_wp += static_cast<double> (all_wins_opp) / 
                             static_cast<double> (all_games_opp);
                }
                
            owp[team] = sum_wp / static_cast<double> (all_games);
        }
        
        for (int team = 0; team < all_teams; ++team)
        {
            int all_games = 0;
            double sum_owp = 0.00;
            for (int i = 0; i < all_teams; ++i)
                if (result[team][i] != '.')
                {
                   ++all_games;
                   sum_owp += owp[i];
                }
                
            oowp[team] = sum_owp / static_cast<double> (all_games);
        }
        
        output << "Case #" << query + 1 << ':' << '\n';
        for (int team = 0; team < all_teams; ++team)
            output << 0.25 * wp[team] + 0.50 * owp[team] + 0.25 * oowp[team] << '\n';
    }
    
    
    return 0;
}
