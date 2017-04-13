/* 
 * File:   code.cpp
 * Author: dzaric
 *
 */

#include <limits.h>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cctype>
#include <cstring>
using namespace std;

typedef pair<int,int> pii;
typedef pair<double,double> pdd;

enum{LPAREN,RPAREN,NUM,FEAT};
char* token_str[]={"LPAREN","RPAREN","NUM","FEAT"};

string tokenVal;

int nextToken(){
    char c;
    int state=0;
    tokenVal="";
    while(true){
        cin.get(c);
        switch(state){
            case 0:{
                if(c=='('){
                    return LPAREN;
                }else
                if(c==')'){
                    return RPAREN;
                }else
                if(c>='0'&&c<='9'){
                    cin.unget();
                    state=1;    //state==1 //reading number
                }else
                if(islower(c)){
                    cin.unget();
                    state=2;
                }
            }break;
            case 1:{
                if(c=='.'||(c>='0'&&c<='9')){
                    tokenVal+=c;
                }else{
                    cin.unget();
                    return NUM;
                }
            }break;
            case 2:{
                if(islower(c)){
                    tokenVal+=c;
                }
                else{
                    cin.unget();
                    return FEAT;
                }
            }break;
        }
    }
}


struct Node{
    bool isLeaf;
    Node *left,*right;
    double prob;
    string feat;
    Node(){
        isLeaf=true;
    }
};


void buildTree(Node* root){
    while(true){
        int t=nextToken();
        if(t==RPAREN){
            return;
        }
        if(t==NUM){
            root->prob=atof(tokenVal.c_str());
        }
        if(t==FEAT){
            root->feat=tokenVal;
        }
        if(t==LPAREN){
            root->isLeaf=false;
            root->left=new Node();
            buildTree(root->left);
            nextToken();
            root->right=new Node();
            buildTree(root->right);            
        }
    }        
}


double getSol(Node* root,const set<string> feats){
    Node* curr=root;
    double ret=1;
    while(true){
        ret*=curr->prob;
        if(curr->isLeaf){
            return ret;
        }        
        else{
            if(feats.find(curr->feat)!=feats.end()){
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
    }
}

void destroy(Node* root){
    Node *curr=root;
    if(curr->isLeaf==false){
        destroy(curr->left);
        delete curr->left;
        destroy(curr->right);
        delete(curr->right);
        return;
    }
       
}

int main(int argc, char** argv) {

    int tcases;
//    scanf("%d",&tcases);
    cin>>tcases;
    for(int tcase=1;tcase<=tcases;tcase++){
        cout<<"Case #"<<tcase<<":"<<endl;
        int N;
        cin>>N;
        nextToken();
        Node* root=new Node();
        buildTree(root);
        cin>>N;
        while(N-->0){
            string name;
            cin>>name;
          //  cout<<name<<endl;
            int nfeats;
            cin>>nfeats;
            set<string> feats;
            for(int i=0;i<nfeats;i++){
                string f;
                cin>>f;
                feats.insert(f);
            }
            //cout<<getSol(root,feats)<<endl;
            printf("%.7lf\n",getSol(root,feats));
        }
        destroy(root);
        delete root;
    }

    return (EXIT_SUCCESS);
}

