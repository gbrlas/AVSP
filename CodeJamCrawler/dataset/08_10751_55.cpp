#include <stdio.h>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <assert.h>

using namespace std;

typedef struct {
    string str;
    bool bAvl;
}HASHEntry;

int main()
{
    int n,s,q;
    int i,j,k;
    int caseCnt = 0,minCnt;
    string tpStr;
    HASHEntry * pEntry = NULL;
    const int MASK = 0x7F;
    list<HASHEntry> * pHashTable = NULL;
    list<HASHEntry> * pCurList;
    cin>>n;
    pHashTable = new list<HASHEntry>[128];
    while( n-- ){
        cin>>s;
        for ( i = 0 ; i < 128 ; i++ ) {
            pHashTable[i].clear();
        }
        getline(cin,tpStr,'\n');
        for ( i = 0 ; i < s ; i++ ) {
            HASHEntry tmpEntry;
            string & str = tmpEntry.str;
            int hashKey = 0;
            int size; 
            getline(cin,str,'\n');
            size = str.length();
            for ( j = 0 ; j < size ; j++ ) {
                if ( str[j] != ' ' ) {
                    assert(str[j]<= 'z' && str[j] >= '0');
                    hashKey += str[j] - '0';
                }
            }
            tmpEntry.bAvl = true;
            pHashTable[hashKey & MASK].push_back(tmpEntry);
        }

        int currentCnt = 0;
        string str;
        int hashKey = 0;
        list<HASHEntry>::iterator it;
        minCnt = 0;
        cin>>q;
        getline(cin,tpStr,'\n');
        for ( i = 0 ; i < q; i++ ) {
            hashKey = 0;
            str.clear();
            getline(cin,str,'\n');
            j = str.length();
            for ( k = 0 ; k < j; k++ ) {
                if ( str[k] != ' ' ) {
                    assert(str[k]<= 'z' && str[k] >= '0');
                    hashKey += str[k] - '0';
                }
            }
            pCurList = &pHashTable[hashKey & MASK];

            for ( it = pCurList->begin(); it != pCurList->end(); it++ ) {
                if ( (*it).str == str ) {
                    break;
                }
            }
            
            assert(it != pCurList->end());
            
            if ( (*it).bAvl ) {
                if ( currentCnt == s - 1 ) {
                    pCurList = pHashTable;
                    for ( k = 0; k < 128 ;  k++,pCurList++ ) {
                        for ( list<HASHEntry>::iterator itt = pCurList->begin(); itt != pCurList->end(); itt++ ) {
                            (*itt).bAvl = true;
                        }
                    }
                    (*it).bAvl = false;
                    minCnt++;
                    currentCnt = 1;
                } else {
                    currentCnt++;
                    (*it).bAvl = false;
                }
            }
        }
        tpStr.clear();
        cout<<"Case #"<<++caseCnt<<": "<<minCnt<<endl;
    }
    delete [] pHashTable;
    return 0;
}