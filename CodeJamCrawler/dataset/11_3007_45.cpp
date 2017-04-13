#include <stdio.h>
#include <stdlib.h>

#include <utility>
using std :: pair;
using std :: make_pair;
#include <vector>
using std :: vector;
#include <algorithm>
using std :: max;

int ans_to_query (const vector<pair<char, int> >& query,
                  const vector<int>& query_o,
                  const vector<int>& query_b)
{
    int pos_o = 0, pos_b = 0,
        cur_q_o = 0, cur_q_b = 0,
        time_o = 0, time_b = 0;
    for (int i = 0; i < query.size (); ++i)
        if (query[i].first == 'O')
        {
            int time_step = abs (query[i].second - pos_o) + 1;

            if (cur_q_b < query_b.size ())
            {
                if (query_b[cur_q_b] == pos_b)
                    time_b += time_step;
                else if (abs (query_b[cur_q_b] - pos_b) <= time_step)
                {
                    time_b += time_step;
                    pos_b = query_b[cur_q_b];
                }
                else
                {
                    time_b += time_step;
                    if (query_b[cur_q_b] - pos_b > 0)
                        pos_b += time_step;
                    else
                        pos_b -= time_step;
                }
            }

            time_o += time_step;
            pos_o = query[i].second;
            ++cur_q_o;
        }
        else
        {
            int time_step = abs (query[i].second - pos_b) + 1;

            if (cur_q_o < query_o.size ())
            {
                if (query_o[cur_q_o] == pos_o)
                    time_o += time_step;
                else if (abs (query_o[cur_q_o] - pos_o) <= time_step)
                {
                    time_o += time_step;
                    pos_o = query_o[cur_q_o];
                }
                else
                {
                    time_o += time_step;
                    if (query_o[cur_q_o] - pos_o > 0)
                        pos_o += time_step;
                    else
                        pos_o -= time_step;
                }
            }

            time_b += time_step;
            pos_b = query[i].second;
            ++cur_q_b;
        }

    return max (time_o, time_b);
}

int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

    int all_query = 0;
    scanf ("%d", &all_query);
    vector<vector<pair<char, int>>> query (all_query);
    vector<vector<int> > query_o (all_query),
                         query_b (all_query);
    for (int i = 0; i < all_query; ++i)
    {
        int size = 0;
        scanf ("%d", &size);
        for (int j = 0; j < size; ++j)
        {
            char type = 0, tmp_space = 0;
            scanf ("%c", &tmp_space);
            scanf ("%c", &type);
            int n_button = 0;
            scanf ("%d", &n_button);
            query[i].push_back (make_pair (type, n_button - 1));
            if (type == 'O')
                query_o[i].push_back (n_button - 1);
            else
                query_b[i].push_back (n_button - 1);
        }
    }

    for (int i = 0; i < all_query; ++i)
        printf ("Case #%d: %d\n", i + 1, ans_to_query (query[i],
                                                       query_o[i],
                                                       query_b[i]));

    getchar ();
    getchar ();

    return 0;
}