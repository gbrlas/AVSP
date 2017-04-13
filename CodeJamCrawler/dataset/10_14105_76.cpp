#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int DN = 512;
const int F = 10000, FK = 4;

class BigInt{
public:
    int n[DN], len, sign;
    void format();
    bool lessThan(const BigInt&, int) const;
    void sub(const BigInt&, int);
    void add(const BigInt&);
    BigInt(int e = 0) : len(1), sign(1){memset(n, 0, sizeof(n)); n[0] = e;}
    BigInt(char*, int);

    bool iszero(){if(len == 1 && n[0] == 0) return 1; return 0;}
    bool and1(){return n[0] & 1;}

    BigInt& operator = (int k) { return *this = BigInt(k); }

    bool operator <(const BigInt&) const;
    bool operator >=(const BigInt& b) const {return !(*this < b); }

    void operator += (const BigInt&);
    void operator -= (const BigInt&);
    void operator *= (const BigInt&);
    void operator /= (const BigInt&);
    void operator %= (const BigInt& b) { *this -= *this / b * b; }

    BigInt operator +(const BigInt& b) const{ BigInt r = *this; r += b; return r; }
    BigInt operator -(const BigInt& b) const{ BigInt r = *this; r -= b; return r; }
    BigInt operator *(const BigInt& b) const{ BigInt r = *this; r *= b; return r; }
    BigInt operator /(const BigInt& b) const{ BigInt r = *this; r /= b; return r; }
    BigInt operator %(const BigInt& b) const{ BigInt r = *this; r %= b; return r; }

    void operator *= (int);
    void operator /= (int);

    BigInt operator /(int k) const { BigInt r = *this; r /= k; return r; }

    void print() const;
}input[1024], diff[1024];

BigInt gcd(BigInt a, BigInt b)
{
    BigInt x, y;
    if(a.iszero() || b.iszero()) return a + b;
    else if(a < b)
    {
        y = b / a;
        x = b - y * a;
        return gcd(a, x);
    }
    else
    {
        y = a / b;
        x = a - y * b;
        return gcd(a % b, b);
    }
}
int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int testcases, n, len, cases;
    char str[1024];

    scanf("%d", &testcases);
    cases = testcases;
    while(testcases--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%s", str);
            len = strlen(str);
            input[i] = BigInt(str, len);
        }
        sort(input, input + n);
        for(int i = 0; i < n - 1; i++)
            diff[i] = input[i + 1] - input[i];
        BigInt T, t1 = input[0], y;
        if(n >= 3)
        {
            T = gcd(diff[0], diff[1]);
            for(int i = 2; i < n - 1; i++) {T = gcd(diff[i], T);}
        }
        else T = diff[0];
        BigInt temp = t1 % T;
        if(temp.iszero()) y = BigInt(0);
        else y = (t1 / T + 1) * T - t1;
        //printf("case%d ", 100-testcases);
        printf("Case #%d: ",cases - testcases);
        y.print();
        putchar('\n');
    }
    return 0;
}
void BigInt::format(){
    while(len > 1 && n[len - 1] == 0) len--;
    if(len == 1 && n[0] == 0) sign = 1;
}
BigInt:: BigInt(char *str, int slen = -1){
    memset(n, 0, sizeof(n));
    sign = (*str == '-' ? -1 : 1);
    if(!isdigit(*str)) str++;
    if(slen == -1) slen = strlen(str);
    len = (slen + FK - 1) / FK;
    for(int i = slen, k = 0; i > 0; i -= FK, k++){
        int sum = 0;
        for(int j = max(i - FK, 0); j < i; j++)
            sum = sum * 10 + str[j] - '0';
        n[k] = sum;
    }
    format();
}
bool BigInt::lessThan(const BigInt& b, int bg = 0) const{
    if(len - bg != b.len) return len - bg < b.len;
    for(int i = len - bg - 1; i >= 0; i--)
        if(n[bg + i] != b.n[i]) return n[bg + i] < b.n[i];
    return false;
}
void BigInt::add(const BigInt& b){
    len >?= b.len;
    int r = 0;
    for(int i = 0; i < len; i++){
        n[i] += r + b.n[i];
        r = n[i] / F;
        n[i] %= F;
    }
    if(r != 0) n[len++] = r;
    format();
}
void BigInt::sub(const BigInt& b, int bg = 0){
    for(int i = 0; i < b.len; i++){
        n[bg + i] -= b.n[i];
        if(n[bg + i] < 0){ n[bg + i] += F; n[bg + i + 1]--;}
    }
    format();
}
bool BigInt::operator < (const BigInt& b) const{
    if(sign != b.sign) return sign < b.sign;
    else if(sign == 1) return lessThan(b);
    else return b.lessThan(*this);
}
void BigInt::operator += (const BigInt& b){
    if(sign == b.sign) add(b);
    else if(b.lessThan(*this)) sub(b);
    else {
        int cs = -sign;
        BigInt r = b; r.sub(*this);
        *this = r; sign = cs;
        format();
    }
}
void BigInt::operator -= (const BigInt& b){
    if(sign != b.sign) add(b);
    else if(b.lessThan(*this)) sub(b);
    else {
        int cs = -sign;
        BigInt r = b; r.sub(*this);
        *this = r; sign = cs;
        format();
    }
}
void BigInt::operator *= (const BigInt& c){
    BigInt a = *this, b = c;
    memset(n, 0, sizeof(n)); len = a.len + b.len; sign *= b.sign;
    for(int i = 0; i < a.len; i++)
        for(int j = 0; j < b.len; j++){
            int k = i + j;
            n[k] += a.n[i] * b.n[j];
            if(n[k] >= F) { n[k + 1] += n[k] / F; n[k] %= F; len >?= k + 2; }
        }
    format();
}
void BigInt::operator /= (const BigInt& c){
    BigInt a = *this, b = c;
    memset(n, 0, sizeof(n));
    len = max(a.len - b.len + 1, 0); sign *= b.sign;
    if(a < b)
    {
        *this = BigInt(0);
        return;
    }

    int temp = 0;
    for(int i = len - 1; i >= 0; i--)
    {
        int al;
        if(a.len > i + b.len) al = a.n[a.len - 1] * F + a.n[a.len - 2];
        else al = a.n[a.len - 1];
        int bl = b.n[b.len - 1], ar = al + 1, br = bl + 1;
        int l = al / br, r = ar / bl + 1;
        while(r - l != 1){
            int mid = (l + r) / 2;
            if(a.lessThan(b * mid, i)) r = mid;
            else l = mid;
        }
        a.sub(b * l, i);
        n[i] = l;
    }
    if(len == 0) len++;
    format();
//    for(int i = len - 1; i >= 0; i--){
//        int al = a.n[max(i + b.len, a.len) - 1], bl = b.n[b.len - 1], ar = al + 1, br = bl + 1;
//        int l = al / br, r = ar / bl + 1;
//        while(r - l != 1){
//            int mid = (l + r) / 2;
//            if(a.lessThan(b * mid, i)) r = mid;
//            else l = mid;
//        }
//        a.sub(b * l, i);
//        n[i] = l;
//    }
//    if(len == 0) len++;
//    format();
}
void BigInt::print() const{
    if(sign == -1) putchar('-');
    printf("%d", n[len - 1]);
    for(int i = len - 2; i >= 0; i--)
        printf("%0*d", FK, n[i]);
}
void BigInt::operator *= (int k){
    int r = 0;
    for(int i = 0; i < len; i++){
        n[i] = n[i] * k + r;
        r = n[i] / F; n[i] %= F;
    }
    if(r != 0) n[len++] = r;
    format();
}
void BigInt::operator /= (int k){
    int r = 0;
    for(int i = len - 1; i >= 0; i--){
        n[i] += r * F;
        r = n[i] % k; n[i] /= k;
    }
    format();
}
