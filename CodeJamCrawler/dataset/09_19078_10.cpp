#include <iostream>
#include <fstream>
#include <string>
//#include <vector>
#include <set>
#include <boost/lexical_cast.hpp>

using namespace std;

FILE* pf;
FILE* pfo;

struct node
{
    double p;
    string name;
    node* first;
    node* second;
    double prob;

    ~node(){ if (first) delete first; if (second) delete second; }
};

node cur;

void BuildNewNode(node*& _nd, int& _pos, string& _str)
{
    if ( _pos >= _str.size() || _str[_pos] == ')')
        return;

    while ( _str[_pos] != '(' && _str[_pos] != ')')
        _pos++;

    _nd = new node;

    _nd->p = 1;
    _nd->prob = -1;
    _nd->first = NULL;
    _nd->second = NULL;

    if ( _str[_pos] == '(')
        _pos++;

    double p;
    string num = "";

    while (_str[_pos] != ' ' && _str[_pos] != ')')
    {
        num += _str[_pos];
        _pos++;
    }

    p = boost::lexical_cast<double>(num);
    _nd->p = p;

    if ( _str[_pos] == ' ')
    {
        _pos++;

        while (_pos < _str.size() && _str[_pos] != ' ')
        {
            _nd->name += _str[_pos];
            _pos++;
        }

        while (_pos < _str.size() && _str[_pos] != '(')
            _pos++;

        if ( _pos >= _str.size() )
            return;

        BuildNewNode(_nd->first, _pos, _str);
        BuildNewNode(_nd->second, _pos, _str);
    }
    else
    {
        while ( _pos < _str.size() && (_str[_pos] == ' ' || _str[_pos] == ')' ))
            _pos++;
    }
}

double Find(set<string>& _f, node* _nd, double _p)
{
    if ( !_nd )
        return _p;

    if (_nd->prob == -1)
        _nd->prob = _p * _nd->p;

    if ( _f.find(_nd->name) != _f.end())
        return Find(_f, _nd->first, _nd->prob);
    else
        return Find(_f, _nd->second, _nd->prob);
}

int main()
{
    pf = fopen("A-small.in", "r");
    pfo = fopen("A-small.out", "w");
    int N;

    fscanf(pf, "%d", &N);

    for (int i = 1; i <= N; i++)
    {
        int L;
        fscanf(pf, "%d", &L);

        string def = "";

        while (L+1)
        {
            char c;
            fscanf(pf, "%c", &c);
            if (c == '\n')
                L--;
            else
                if (!( c == ' ' && (def.empty() || def[def.size()-1] == ' ' || def[def.size()-1] == '(')))
                def += c;
        }

        node* nd = NULL;
        int pos = 0;

        BuildNewNode(nd, pos, def);

        int A;
        fscanf(pf, "%d", &A);

        fprintf( pfo, "Case #%d:\n", i);
        //cout<<"Case #"<<i<<":"<<endl;

        for (int j = 0; j < A; j++)
        {
            int col = 0;
            char an[50] = "";
            fscanf(pf, "%s %d", an, &col);

            set<string> feat;

            for (int k = 0; k < col; k++)
            {
                char ft[50];
                fscanf(pf, "%s", ft);
                feat.insert(ft);
            }
            
            fprintf( pfo, "%0.7f\n", Find(feat, nd, 1));
        }

        delete nd;
    }



    return 0;
}