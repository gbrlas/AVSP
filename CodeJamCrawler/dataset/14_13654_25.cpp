//
//  main.cpp
//  CodeJam
//
//  Created by Nelson on 24/03/2014.
//  Copyright (c) 2014 Nelson. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int cartes[4];

void lireGrille(int row, int choix)
{
    int c;
    for(int i=1; i<=4; i++)
    {
        for(int j=1; j<=4; j++)
        {
            cin>>c;
            
            //Premiere Lecture : on enregistre les 4 cartes
            if(i == row && choix == 1)
            {
            	cartes[j-1] = c;
            }
            
            //Deuxieme lecture : on regarde si la carte est deja passee
            else if(i == row && choix == 2)
            {
            	for(int k=0; k<4; k++)
            	{
            		if(cartes[k] == c)
            		{
            			cartes[k] += 16;
            			break;
            		}
            	}
            }
        }
    }
}


int main(int argc, const char * argv[])
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    
    int n;
    cin>>n;
	int row, res, sum;

    for(int i=0; i<n; i++)
    {
    	cin>>row;
        lireGrille(row, 1);
        cin>>row;
        lireGrille(row, 2);
        res = 0;
        sum = 0;
        
        for(int k=0; k<4; k++)
        {
        	res += (cartes[k] > 16);
        	sum += (cartes[k]-16)*(cartes[k]>16);
        }
        
        if(res == 1)
        {
            cout<<"Case #"<<i+1<<": "<<sum<<endl;
        }
        else if(res == 0)
        {
            cout<<"Case #"<<i+1<<": Volunteer cheated!"<<endl;
        }
        else
        {
            cout<<"Case #"<<i+1<<": Bad magician!"<<endl;
        }
    }
}

