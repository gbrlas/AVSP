#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <algorithm>

using namespace std;

typedef vector<vector<int> > VVI;

//---------------------------------------------------------
int SToI(const string& s) { return atoi(s.c_str()); }
long long SToLL(const string& s) { return _atoi64(s.c_str()); }
double SToD(const string& s) { return atof(s.c_str()); }
//---------------------------------------------------------
string GetLine(ifstream& fs) { string ln; getline(fs, ln); return ln; }
int ParseInt(ifstream& fs) { return SToI(GetLine(fs)); }

//---------------------------------------------------------
template<typename T> struct Trait {};
template<> struct Trait<string> { static string FromS(const string& s) { return s; } };
template<> struct Trait<int> { static int FromS(const string& s) { return SToI(s); } };
template<> struct Trait<long long> { static long long FromS(const string& s) { return SToLL(s); } };
template<> struct Trait<double> { static double FromS(const string& s) { return SToD(s); } };

template<typename T>
void GetLines(ifstream& fs, vector<T>& out, int ct = 0)
{
    if (ct == 0)
    {
        ct = ParseInt(fs);
    }

    out.resize(ct);

    for (int i = 0; i < ct; i++)
    {
        out.push_back(Trait<T>::FromS(GetLine(fs)));
    }
}

template<typename T>
void Tokenize(ifstream& fs, vector<T>& out)
{
    string ln = GetLine(fs);

    size_t iFrom = 0;
    size_t iTo = 0;

    for (; iTo < ln.size(); iTo++)
    {
        if (ln[iTo] == ' ')
        {
            if (iTo > iFrom)
            {
                out.push_back(Trait<T>::FromS(ln.substr(iFrom, iTo - iFrom)));
            }
            
            iFrom = iTo + 1;
        }   
    }

    if (iTo > iFrom)
    {
        out.push_back(Trait<T>::FromS(ln.substr(iFrom, iTo - iFrom)));
    }
}

template<typename T>
void Tokenize(ifstream& fs, vector<vector<T> >& out, int ct = 0)
{
    if (ct == 0)
    {
        ct = ParseInt(fs);
    }

    out.resize(ct);

    for (int i = 0; i < ct; i++)
    {
        Tokenize(fs, out[i]);
    }
}

//---------------------------------------------------------
//---------------------------------------------------------
void Solve(ifstream&  fs)
{
    vector<int> sz;
    Tokenize(fs, sz);

    int rows = sz[0];
    int cols = sz[1];

    vector<vector<int>> lawn;
    Tokenize(fs, lawn, rows);

    bool no = false;

    for (int h = 1; h <= 100 && !no; h++)
    {
        set<int> rowPass;
        set<int> colPass;

        for (int r = 0; r < rows && !no; r++)
        {
            for (int c = 0; c < cols && !no; c++)
            {
                if (lawn[r][c] == h)
                {
                    if (rowPass.find(r) == rowPass.end() && colPass.find(c) == colPass.end())
                    {
                        bool isColOK = true;
                        bool isRowOK = true;
                        for (int cc = 0; cc < cols; cc++)
                        {
                            if (lawn[r][cc] > h)
                            {
                                isRowOK = false;
                                break;
                            }
                        }

                        for (int rr = 0; rr < rows; rr++)
                        {
                            if (lawn[rr][c] > h)
                            {
                                isColOK = false;
                                break;
                            }
                        }

                        if (!isColOK && !isRowOK)
                        {
                            no = true;
                        }
                        else 
                        {
                            if (isColOK)
                                colPass.insert(c);
                            if (isRowOK)
                                rowPass.insert(r);
                        }
                    }
                }
            }
        }
    }

    cout << (no ? "NO" : "YES");
}
//---------------------------------------------------------
int main(int argc, char* argv[])
{   
    string sz = argc == 2 ? argv[1] : "tt";
    string file = string(sz) + ".in";
    ifstream fs(file.c_str());

    if (fs.is_open())
    {
        int numTests = ParseInt(fs);

        for (int i = 0; i < numTests; i++)
        {
            cout << "Case #" << i + 1 << ": ";

            Solve(fs);

            cout << endl;
        }
    }
    else
    {
        cout << file << " not found" << endl;
    }



    return 0;
}
