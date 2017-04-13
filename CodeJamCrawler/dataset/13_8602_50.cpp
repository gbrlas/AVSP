//
//  main.cpp
//  mycom
//
//  Created by Lakshmi Sowmya Upadhyayula on 4/10/13.
//  Copyright (c) 2013 Lakshmi Sowmya Upadhyayula. All rights reserved.
//

#include <iostream>
using namespace std;
int a[100][100],b[100][100];
int row[100];
int col[100];
int num[100];
int h, o, dot, max1;
bool solve(int n,int m, int i, int j)
{
    int i1,j1,i2,j2,im = 0;
    for(i1 = 0; i1 < n; i1++)
    {
        if(row[i1] ==1)
        {
            for(j1=0; j1<m; j1++)
            {
                b[i1][j1] = 2;
            }
        }
    }
    
    for(i1 = 0; i1 < m; i1++)
    {
        if(col[i1] ==1)
        {
            for(j1=0; j1<n; j1++)
            {
                b[j1][i1] = 2;
            }
        }
    }
    
    for(int ik=0;ik<n; ik++)
    {
        for(int jk=0;jk<m;jk++)
        {
            if(a[ik][jk] == 1)
            {
                if(row[ik]!=1)
                {
                    for(j1=0; j1<m; j1++)
                    {
                        b[ik][j1] = 1;
                    }
                }
                if(col[jk]!=1)
                {
                    for(j1=0; j1<n; j1++)
                    {
                        b[j1][jk] = 1;
                    }
                }
            }
        }
    }
    
    //print
    /*
    cout << endl;
    for(int ik=0;ik<n; ik++)
    {
        for(int jk=0;jk<m;jk++)
        {
            cout << a[ik][jk] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
    cout << endl;
    
    for(int ik=0;ik<n; ik++)
    {
        for(int jk=0;jk<m;jk++)
        {
            cout << b[ik][jk] << " ";
        }
        cout << endl;
    }
     */
    //print

    for(int ik=0;ik<n; ik++)
    {
        for(int jk=0;jk<m;jk++)
        {
            if(a[ik][jk] != b[ik][jk])
            {
                return false;
            }
        }
    }
    
    return true;
}

int main(int argc, const char * argv[])
{

    int T;

    freopen("/Users/Sowmya/Documents/mycom/mycom/small.in","rt",stdin);
    freopen("small.out","wt",stdout);
    std::cin >> T;
    //cout << N <<endl;
    for(int im=0;im<T;im++)
    {
        cout << "Case #" << im+1 << ": ";
        //cout << endl;
        int N,M;
        cin >> N;
        cin >> M;
        max1 =0;
        for (int il = 0; il < 100; il ++)
        {
            row[il] = 0;
            col[il] = 0;
            num[il] = 0;
        }
        for (int ii = 0; ii< N; ii ++)
        {
            for (int jj = 0 ; jj < M; jj++)
            {
                cin >> a[ii][jj];
                b[ii][jj] = 0;
                if(a[ii][jj] == 2)
                {
                    row[ii] = 1;
                    col[jj] = 1;
                }
                num[a[ii][jj]]++;
                if(max1 < a[ii][jj])
                    max1 = a[ii][jj];
          //      cout << a[ii][jj] << " ";
            }
            //cout << endl;
        }
        
        cout << (solve(N,M,0,0)? "YES": "NO") << endl;

    }
    return 0;
}
