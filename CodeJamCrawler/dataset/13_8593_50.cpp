//
//  main.cpp
//  mycom
//
//  Created by Lakshmi Sowmya Upadhyayula on 4/10/13.
//  Copyright (c) 2013 Lakshmi Sowmya Upadhyayula. All rights reserved.
//

#include <iostream>
using namespace std;
char a[4][4];
int h, o, dot;
int solve(int sum,int icur, int jcur, bool isHoriz, int dia)
{
    if(!isHoriz)
    {
        for(int i = 0; i < 4; i++)
        {
            //cout << a[i][jcur] << " ";
            if(a[i][jcur] == 'X' || a[i][jcur] == 'T')
                h++;
            if(a[i][jcur] == 'O' || a[i][jcur] == 'T')
                o++;
            if(a[i][jcur] == '.')
                dot++;
        }
    }
    else
    {
        for(int j = 0; j < 4; j++)
        {
            //cout << a[icur][j] << " ";
            if(a[icur][j] == 'X' || a[icur][j] == 'T')
                h++;
            if(a[icur][j] == 'O' || a[icur][j] == 'T')
                o++;
            if(a[icur][j] == '.')
                dot++;
        }
    }
    
    if(dia == 1)
    {
        h =0; o =0;
        int j = 0;
        for(int i = icur; i < 4; i++)
        {
            //cout << a[i][j] << " ";
                if(a[i][j] == 'X' || a[i][j] == 'T')
                    h++;
                if(a[i][j] == 'O' || a[i][j] == 'T')
                    o++;
                if(a[i][j] == '.')
                dot++;
            j++;
        }
    }
    else if(dia == 2)
    {
        h =0; o =0;
        int j = 3;
        for(int i = 0; i < 4; i++)
        {
            //cout << a[i][j] << " ";
            if(a[i][j] == 'X' || a[i][j] == 'T')
                h++;
            if(a[i][j] == 'O' || a[i][j] == 'T')
                o++;
            if(a[i][j] == '.')
                dot++;
            j--;
        }
    }

}
int main(int argc, const char * argv[])
{

    int N;

    freopen("small.in","rt",stdin);
    freopen("small.out","wt",stdout);
    std::cin >> N;
    //cout << N <<endl;
    for(int im=0;im<N;im++)
    {
        cout << "Case #" << im+1 << ": ";
        for(int ii=0;ii<4;ii++)
        {
            for(int jj=0;jj<4;jj++)
            {
                cin>>a[ii][jj];
                //cout << a[ii][jj];
            }
            //cout << endl;
        }
        int i;
        dot =0;
        for(i=0;i<4;i++)
        {
            h=0; o =0;
            solve(0,i,0,true,0);
            //cout <<endl << i << " " << h << "  " << o << endl;
            if(h == 4)
            {
             cout << "X won" << endl ;
                break;
            }
            else if(o == 4)
            {
                cout << "O won" << endl ;
                break;
            }
            
            h=0; o =0;
            solve(0,0,i,false,0);
            //cout <<endl << i << " " << h << "  " << o << endl;

            if(h == 4)
            {
                cout << "X won" << endl ;
                break;
            }
            else if(o == 4)
            {
                cout << "O won" << endl ;
                break;
            }
            
        }
        
        h=0; o =0;
        solve(0,0,0,false,2);
        //cout <<endl << i << " " << h << "  " << o << endl;

        if(h == 4)
        {
            cout << "X won" << endl ;
            continue;
        }
        else if(o == 4)
        {
            cout << "O won" << endl ;
            continue;
        }
        
        h=0; o =0;
        solve(0,0,0,true,1);
        //cout <<endl << i << " " << h << "  " << o << endl;

        if(h == 4)
        {
            cout << "X won" << endl ;
            continue;
        }
        else if(o == 4)
        {
            cout << "O won" << endl ;
            continue;
        }
        
        if(i >3)
        {
            if(dot > 0)
            {
                cout << "Game has not completed" << endl ;
            }
            else
            {
                cout << "Draw" << endl;
            }
        }
    }
    return 0;
}
