/* 
 * File:   main.cpp
 * Author: zrm
 *
 * Created on May 8, 2010, 1:00 AM
 *
 * Google Code Jam 2010 - Qualification Round
 * Problem B: Fair Warning
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <bits/basic_string.h>
#include <sstream>

using namespace std;
/*
 * 
 */

struct classcomp
{
    bool operator() (const string& lhs, const string& rhs) const
    {
        int an = lhs.size();
        int bn = rhs.size();
        if (an < bn)
            return true;
        if (an > bn)
            return false;
        
        return lhs<rhs;
    }
};

int digitAt(string& s, int i)
{
    int len = s.size();
    if (i >= len) return 0;
    else return(s[len-i-1]-'0');
}

string zeroExtend(string& s, int len)
{
    int slen = s.size();
    string zeros(len-slen, '0');
    return zeros+s;
}

string trimZeros(string& a)
{
    int len = a.size();
    int i;

    for (i=0; i<len; ++i)
    {
        char c = a[i];
        if (c != '0')
            break;
    }

    if (i==len)
        --i;

    return(a.substr(i));
}

string sub(string& a, string& b)
{
    //cout << "SUB\n";
    int an = a.size();
    int bn = b.size();
    int ac, bc;
    bool borrow = false;
    bool borrowOld = false;
    char c;
    string res(an, '0');

    for (int i=0; i<an; ++i)
    {
        ac = digitAt(a, i);
        bc = digitAt(b, i);
        borrowOld = borrow;

        if (borrowOld)
        {
            --ac;
        }

        if ((ac<0) || (ac<bc))
        {
            borrow = true;
            ac += 10;
        }
        else
            borrow = false;

        c = '0' + (ac - bc);
        res[an-i-1] = c;
    }

//    int ia, ib, ic;
//    istringstream(a) >> ia;
//    istringstream(b) >> ib;
//    istringstream(res) >> ic;
//    int realc = ia - ib;
//    if (realc != ic)
//        cout << "ERROR: " << a << " - " << b << " SHOULD BE " << realc << " NOT " << res << endl;
    //cout << "  " << a << " - " << b << " = " << res << endl;
    return res;
}

string modulo(string& a, string& b)
{
    int an = a.size();
    int bn = b.size();
    int maxlen = an>bn?an:bn;

    string ax = zeroExtend(a, maxlen);
    string bx = zeroExtend(b, maxlen);
    //cout << ax << " MOD " << bx << endl;

    while (!(classcomp()(ax, bx)))
    {
        //cout << "  " << ax << " MODULO " << bx << endl;
        ax = sub(ax, bx);
    }

//    int ia, ib, ic;
//    istringstream(a) >> ia;
//    istringstream(b) >> ib;
//    istringstream(ax) >> ic;
//    int realc = ia % ib;
//    if (realc != ic)
//        cout << "ERROR: " << a << " MOD " << b << " SHOULD BE " << realc << " NOT " << ax << endl;
    //cout << "  " << a << " MODULO " << b << " = " << ax << endl;
    return ax;
}

void printSet(set<string, classcomp>& s)
{
    set<string, classcomp>::iterator it = s.begin();
    for (; it != s.end(); ++it)
        cout << (*it) << " ";
    cout << endl;
}

string gcdAll(set<string, classcomp>& diffs)
{
    //cout << "GCDALL\n";
    string res;
    set<string, classcomp>::iterator it;
    it = diffs.end();
    --it;
    string max = (*it);
    int maxlen = max.size();
    string zero(maxlen, '0');

    set<string, classcomp> src = diffs;
    set<string, classcomp> dest;

    while (src.size() > 1)
    {
        //cout << "BEFORE: ";
        //printSet(src);

        set<string, classcomp>::iterator itk = src.begin();
        string base = *itk;
        dest.insert(base);
        ++itk;
        string m, num;

        for (; itk != src.end(); ++itk)
        {
            num = *itk;
            m = modulo(num, base);
            if (classcomp()(zero, m))
                dest.insert(m);
        }
        //cout << "AFTER: ";
        //printSet(dest);

        src = dest;
        dest.clear();
    }

    it = src.begin();
    res = *it;
    return res;
}

string nextMultipleDiff(string& a, string& gcd)
{
    string res;
    //cout << "Next highest multiple of " << gcd << " after " << a << endl;
    string m = modulo(a, gcd);
    //cout << "m: " << m << endl;
    string z = trimZeros(m);
    if (z == "0")
        res = m;
    else
        res = sub(gcd, m);
    return res;
}

int main(int argc, char** argv)
{
    int numCases;
    cin >> numCases;
    //cout << numCases;

    set<string, classcomp> events;
    set<string, classcomp> diffs;
    set<string, classcomp> diggs;
    string s;
    for (int i=0; i<numCases; ++i)
    {
        int maxlen = 0;
        int numEvents;
        cin >> numEvents;
        events.clear();

        for (int j=0; j<numEvents; ++j)
        {
            cin >> s;
            events.insert(s);
        }

        diffs.clear();
        diggs.clear();
        set<string, classcomp>::iterator it = events.begin();
        set<string, classcomp>::iterator itp = events.begin();
        ++itp;

        while (itp != events.end())
        {
            string a = *itp;
            string b = *it;
            string c = sub(a, b);
            //cout << a << " - " << b << " = " << c << endl;
            diffs.insert(c);
            maxlen = c.size()>maxlen?c.size():maxlen;
            ++it; ++itp;
        }

        set<string, classcomp>::iterator itf = diffs.begin();
        for(; itf != diffs.end(); ++itf)
        {
            string q = *itf;
            q = zeroExtend(q, maxlen);
            diggs.insert(q);
        }
        //cout << "DIFFS: ";
        //printSet(diggs);
        string gcd = gcdAll(diggs);
        //cout << "GCD: " << trimZeros(gcd) << endl;
        //cout << trimZeros(gcd) << " " ;
        string first = *(events.begin());
        string res = nextMultipleDiff(first, gcd);
        //cout << trimZeros(res) << " " ;
        //printSet(events);
        cout << "Case #" << i+1 << ": " << trimZeros(res) << endl;
    }

    return (EXIT_SUCCESS);
}

