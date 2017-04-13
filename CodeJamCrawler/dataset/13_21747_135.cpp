#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<cstring>
#include<set>
#include<cmath>
#include<algorithm>

using namespace std;
string A,B;
vector<string> pal;
vector<string> part;
vector<string> pow_pal;

string tmp = "";

string reverse(string s);
string str_add(string a, string b)
{
    if(a.size() < b.size()){
        string tt = b;
        b = a;
        a = tt;
    }
    string rev_a = reverse(a);
    string rev_b = reverse(b);

    a = rev_a;
    b = rev_b;

    string ret = "";
    int up = 0;
    for(int i=0; i<a.size();i++){
        int a1 = a[i]-'0';
        int b1;
        if(i<b.size())
            b1 = b[i]-'0';
        else b1 = 0;

        int s = a1+b1+up;
        if( s >= 10){
            s-=10;
            up = 1;
        }
        ret += char(s+'0');
    }
    if(up) ret+=char('1');
    return reverse(ret);
}
string str_time(string a, int b, int c){
    string ret = "";
    for(int i=0;i<a.size();i++){
        ret += char((a[i]-'0')*b+'0');
    }
    for(int i=0;i<c;i++){
        ret += char ('0');
    }
    return ret;
}
string str_pow(string a)
{
    string ret = "";
    string b = a;
    for(int i=0;i<b.size();i++){
        string tt = str_time(a,b[i]-'0',i);
        ret = str_add(ret,tt);
    }
    return ret;
}
bool mysort(string a, string b){
    if(a.size() < b.size())
        return true;
    else if(a.size() > b.size()) 
        return false;
    else {
        if( a< b)
            return true;
        else return false;
    }
}
void gen_part(int len, int square_sum)
{
    int length = tmp.size();
    if(len == 0){
        part.push_back(tmp);
        return;
    }
    
    for(int i=0;i*i<=square_sum;++i){
        tmp += char(i + '0');
        gen_part(len-1,square_sum-i*i);
        tmp = tmp.substr(0,length);
    }
}
int sq_sum(string t)
{
    int cnt = 0;
    for(int i=0;i<t.size();i++){
        int inti = t[i]-'0';
        cnt += inti*inti;
    }
    return cnt;
}

string reverse(string s)
{
    string ret = "";
    for(int i=s.size()-1;i>=0;i--){
        ret += char(s[i]);
    }
    return ret;
}
void init()
{
//    cout << reverse("abc") << endl;
//    cout << str_add("111","2222") << endl;
   // cout << str_add("","2222") << endl;
   // cout << str_add("2222","") << endl;
//    cout << str_time("111",2,4) << endl;
//    cout << str_pow("11") << endl;
    for(int len = 1; len <= 25 ; len ++){
        tmp = "";
        gen_part(len,4);
    }
    for(int i=0;i<part.size();++i){
        string  local = part[i];
        if(local[0]=='0') continue;
        int square_sum = sq_sum(local);
        pal.push_back(local+reverse(local));
        for(int i=0;i*i+2*square_sum<10;i++){
            pal.push_back(local+char(i+'0')+reverse(local));
        }
    }
    //cout << pal.size() << endl;
    pal.push_back("1");
    pal.push_back("2");
    pal.push_back("3");
    sort(pal.begin(),pal.end(),mysort);
    for(int i=0;i<pal.size(); i++){
        pow_pal.push_back(str_pow(pal[i]));
    }
}

int low_bin_search(string s)
{
    vector<string>::iterator low;
    low = lower_bound(pow_pal.begin(),pow_pal.end(),s,mysort);
    return low-pow_pal.begin();
}
int up_bin_search(string s)
{
    vector<string>::iterator up;
    up = upper_bound(pow_pal.begin(),pow_pal.end(),s,mysort);
    return up-pow_pal.begin();
}


int gao(){
    int low = low_bin_search(A);
    int up = up_bin_search(B);
//    cout << low << " " << up << endl;
    return up-low;
}
int main()
{
    init();
//    cout << "finish" << endl;
    int T; cin >> T;
    int idx = 0;
    while(T--){
        idx ++;
        cin >> A >> B;
//        cout << A << " " << B << endl;
        cout << "Case #" << idx << ": " << gao() << endl;
        
    }
}
