#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

   using namespace std;

// super brute force solution...
   int color[2222];
   int pow10[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000}; 
	
   int nth(int n, int d)
   {
      return n / pow10[d - 1] % 10;
   }
   
   int N, M;
   int ncolbest = 0;
   vector<vector<int> > rooms;
   int use[2222];
   void recur(int i)
   {
      if(i == N)
      {
         bool can = true;
         int ncolors = 0;
         for(int j = 0; j < N; j++)
            ncolors = max(ncolors, use[j]);
         ncolors++;
         for(int j = 0; j < rooms.size(); j++)
         {
            bool found[11];
            for(int k = 0; k < ncolors; k++)
               found[k] = false;
            for(int k = 0; k < rooms[j].size(); k++)
               found[use[rooms[j][k]]] = true;
            for(int k = 0; k < ncolors; k++)
               if(!found[k])
                  can = false;
            if(!can)
               break;
         }
            	
         if(can && ncolors > ncolbest)
         {
            for(int j = 0; j < N; j++)
               color[j] = use[j] + 1;
            ncolbest = ncolors;
         }
         
         return;
      }
      
      for(int k = 0; k < N; k++)
      {
         use[i] = k;
         recur(i + 1);
      }
   }
	
   int main()
   {
      FILE * w = fopen("kittens.in", "r");
      FILE * o = fopen("kittens.out", "w");
   
      int T;
      fscanf(w, "%d", &T);
      for(int t = 1; t <= T; t++)
      {
         rooms.clear();
      
         fscanf(w, "%d%d", &N, &M);
         vector<int> a, b;
         for(int i = 0; i < M; i++)
         {
            int x;
            fscanf(w, "%d", &x);
            a.push_back(x - 1);
         }
         for(int i = 0; i < M; i++)
         {
            int x;
            fscanf(w, "%d", &x);
            b.push_back(x - 1);
         }
      
         vector<int> temp;
         for(int i = 0; i < N; i++)
            temp.push_back(i);
         rooms.push_back(temp);
         for(int i = 0; i < M; i++)
         {
            int p = a[i], q = b[i];
         	// find the room that contains this wall
            int j, ppos, qpos;
            for(j = 0; j < rooms.size(); j++)
            {
               bool phas = false, qhas = false;
               for(int k = 0; k < rooms[j].size(); k++)
               {
                  if(rooms[j][k] == p)
                  {
                     phas = true;
                     ppos = k;
                  }
                  if(rooms[j][k] == q)
                  {
                     qhas = true;
                     qpos = k;
                  }
               }
               if(phas && qhas)
                  break;
            }
         	
         	// divide this room into two
            vector<int> next = rooms[j];
            rooms.erase(rooms.begin() + j);
         	
            vector<int> nroom1, nroom2;
            nroom1.push_back(p);
            for(int j = (ppos + 1) % next.size(); j != qpos; j = (j + 1) % next.size())
               nroom1.push_back(next[j]);
            nroom1.push_back(q);
            nroom2.push_back(q);
            for(int j = (qpos + 1) % next.size(); j != ppos; j = (j + 1) % next.size())
               nroom2.push_back(next[j]);
            nroom2.push_back(p);
         	
            rooms.push_back(nroom1);
            rooms.push_back(nroom2);
         }
         
         cout << "***" << t << "***" << endl;
         cout << rooms.size() << " rooms total" << endl;
         
         ncolbest = 0;
         recur(0);
      	
         fprintf(o, "Case #%d: %d\n", t, ncolbest);
         for(int i = 0; i < N; i++)
         {
            if(i == 0)
               fprintf(o, "%d", color[i]);
            else
               fprintf(o, " %d", color[i]);
         }
         fprintf(o, "\n");
      }
   
      return 0;
   }