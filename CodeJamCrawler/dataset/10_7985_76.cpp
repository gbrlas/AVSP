#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <queue>
#include <stack>
#include <iostream>
#include <map>

using namespace std;

int nCase;

#define BIGNUM_SIZE 40
#define BIGNUM_BASE 1000000000
#define BIGNUM_P10    9
class BigNum{
public:
    int nDigit;
    long long rgDgt[BIGNUM_SIZE];
    bool isNeg;
    BigNum(){
        isNeg  = false;
        nDigit = 1;
        rgDgt[0] = 0;
        for(int x = nDigit; x < BIGNUM_SIZE; x++){
            rgDgt[x] = 0;
        }
    }
    BigNum(const BigNum &bigNum){ (*this) = bigNum; }
    BigNum(const long long nNum){ (*this) = nNum; }
    BigNum(const string &strNum){
        Set(strNum);
    }
    void Set(const string &strNum){
        int nLen = strNum.length();
        int d, x, nBase = 1;
        int nBeg, nEnd, nHead;
        nDigit = 0;
        nDigit = (nLen + BIGNUM_P10 - 1) / BIGNUM_P10;
        nHead  = 0;
        isNeg  = false;
        if(strNum[0] == '-'){
            nDigit = (nLen + BIGNUM_P10 - 2) / BIGNUM_P10;
            isNeg = true;
            nHead = 1;
        }
        for(d = 0; d < nDigit; d++){
            nBeg = nLen - 1 - ((d + 1) * BIGNUM_P10 - 1);
            if(nBeg < nHead) nBeg = nHead;
            nEnd = nLen - 1 - (d * BIGNUM_P10);
            if(nEnd < nHead) nEnd = nHead;
            rgDgt[d] = 0;
            for(x = nBeg; x <= nEnd; x++){
                rgDgt[d] = rgDgt[d] * 10 + strNum[x] - '0';
            }
        }
        for(d = nDigit; d < BIGNUM_SIZE; d++){
            rgDgt[d] = 0;
        }
    }
    BigNum & operator=(const BigNum &bigNum){
        int x;
        nDigit = bigNum.nDigit;
        isNeg  = bigNum.isNeg;
        for(x = 0; x < nDigit; x++){
            rgDgt[x] = bigNum.rgDgt[x];
        }
        for(x = nDigit; x < BIGNUM_SIZE; x++){
            rgDgt[x] = 0;
        }

        return *this;
    }
    BigNum & operator=(const long long nInput){
        long long nNum = llabs(nInput);
        int x;
        
        isNeg = false;
        if(nInput < 0) isNeg = true;
        for(x = 0; x < BIGNUM_SIZE; x++){
            rgDgt[x] = 0;
        }
        for(nDigit = 0; nNum > 0; nDigit++){
            rgDgt[nDigit] = nNum % BIGNUM_BASE;
            nNum /= BIGNUM_BASE;
        }
        if(nDigit == 0) nDigit = 1;;
        return *this;
    }
    string ToString() const {
        string strNum = "";
        char szBuf[20];
        if(isNeg) strNum = "-";
        sprintf(szBuf, "%lld", rgDgt[nDigit - 1]);
        strNum += szBuf;
        for(int x = nDigit - 2; x >= 0; x--){
            sprintf(szBuf, "%0*lld", BIGNUM_P10, rgDgt[x]);
            strNum += szBuf;
        }
        return strNum;
    }
    void UpdateDigit(){
        for(nDigit = BIGNUM_SIZE - 1; nDigit > 0; nDigit--){
            if(rgDgt[nDigit] != 0) break;
        }
        nDigit++;
    }
    void CheckAdvance(int nBeg){
        for(int x = nBeg; x < nDigit; x++){
            if(rgDgt[x] >= BIGNUM_BASE){
                if(nDigit < x + 2) nDigit = x + 2;
                rgDgt[x + 1] += rgDgt[x] / BIGNUM_BASE;
                rgDgt[x] %= BIGNUM_BASE;
            }
        }
        while(rgDgt[nDigit] != 0){
            nDigit++;
        }
    }

    void NegAdjust(int nDgt){
        if(rgDgt[nDgt] < 0){
            long long nRes;
            int x;
            isNeg = !isNeg;
            rgDgt[nDgt] = 0;
            nRes = 0;
            for(x = 0; x < nDgt; x++){
                if(rgDgt[x] == 0 && nRes == 0) continue;
                rgDgt[x] = BIGNUM_BASE - rgDgt[x] - nRes;
                if(rgDgt[x] != 0) nRes = 1;
            }
            for(x = nDgt; x < nDigit; x++){
                rgDgt[x] = 0;
            }
            if(nDigit == 1 && rgDgt[0] == 0) isNeg = false;
        }
        UpdateDigit();
    }
    bool operator==(const BigNum &bigNum) const{
        if(nDigit != bigNum.nDigit) return false;
        if(isNeg != bigNum.isNeg) return false;
        for(int x = 0; x < nDigit; x++){
            if(rgDgt[x] != bigNum.rgDgt[x]) return false;
        }
        return true;
    }
    bool operator<(const BigNum &bigNum) const{
        bool isLess = true;
        if(isNeg && !bigNum.isNeg) return true;
        if(!isNeg && bigNum.isNeg) return false;
        if(nDigit > bigNum.nDigit){
            isLess = false;
        }else if(nDigit < bigNum.nDigit){
            isLess = true;
        }else{
            int x;
            for(x = nDigit - 1; x >= 0; x--){
                if(rgDgt[x] < bigNum.rgDgt[x]) {
                    isLess = true;
                    break;
                }else if(rgDgt[x] > bigNum.rgDgt[x]){
                    isLess = false;
                    break;
                }
            }
            if(x == -1) return false; // equal
        }
        if(isNeg) return !isLess;
        return isLess;
    }
    bool operator>(const BigNum &bigNum) const{
        if(*this == bigNum) return false;
        return !(*this < bigNum);
    }
    bool operator==(const int nNum) const{
        return (rgDgt[0] == nNum && nDigit == 1);
    }
    bool operator!=(const int nNum) const{
//        fprintf(stderr, "{%d %d}\n", rgDgt[0], nDigit);
        return !(rgDgt[0] == nNum && nDigit == 1);
    }
    bool operator<(const int nNum) const{
        return (rgDgt[0] < nNum && nDigit == 1);
    }
    bool operator>(const int nNum) const{
        return (rgDgt[0] > nNum || nDigit > 1);
    }
    BigNum & operator+=(const BigNum &bigNum){
        if(isNeg == bigNum.isNeg){
            for(int x = 0; x < bigNum.nDigit; x++){
                rgDgt[x] += bigNum.rgDgt[x];
            }
        }else{
            isNeg = !isNeg;
            *this -= bigNum;
            isNeg = !isNeg;
        }
        CheckAdvance(0);
        return *this;
    }
    BigNum & operator+=(const long long nNum){
        if((isNeg == true && nNum < 0) ||
           (isNeg == false && nNum >= 0)){
            rgDgt[0] += llabs(nNum);
            CheckAdvance(0);
        }else{
            return (*this) -= -nNum;
        }
        return *this;
    }
    BigNum & operator-=(const BigNum &bigNum){
        if(isNeg == bigNum.isNeg){
            int x;
            //fprintf(stderr, "-= has been caled\n");
            for(x = 0; x < bigNum.nDigit; x++){
                rgDgt[x] -= bigNum.rgDgt[x];
                if(rgDgt[x] < 0){
                    rgDgt[x] += BIGNUM_BASE;
                    rgDgt[x + 1] --;
                }
            }
            for(x; x < nDigit; x++){
                if(rgDgt[x] < 0){
                    rgDgt[x] += BIGNUM_BASE;
                    rgDgt[x + 1] --;
                }
            }
            if(rgDgt[x] < 0){
                nDigit = bigNum.nDigit + 1;
                NegAdjust(bigNum.nDigit);
            }
            UpdateDigit();

            if(nDigit == 0) nDigit = 1;
        }else{
            isNeg = !isNeg;
            *this += bigNum;
            isNeg = !isNeg;
            return *this;
        }
        return *this;
    }
    BigNum & operator-=(const long long nNum){
        if((isNeg == true && nNum < 0) ||
           (isNeg == false && nNum >= 0)){
            rgDgt[0] -= llabs(nNum);
            for(int x = 0; x < nDigit; x++){
                if(rgDgt[x] < 0){
                    rgDgt[x] += BIGNUM_BASE;
                    rgDgt[x + 1]--;
                }
            }
            NegAdjust(nDigit);
        }else{
            return (*this) += -nNum;
        }
        return *this;
    }
    const BigNum operator * (const BigNum &bigNum) const{
        BigNum bigAns;
        int x, y;
        if(isNeg == bigNum.isNeg)
            bigAns.isNeg = false;
        else
            bigAns.isNeg = true;

        for(y = 0; y < bigNum.nDigit; y++){
            for(x = 0; x < nDigit; x++){
                bigAns.rgDgt[y + x] += rgDgt[x] * bigNum.rgDgt[y];
            }
            bigAns.CheckAdvance(0);
        }
        bigAns.UpdateDigit();
        bigAns.CheckAdvance(0);
        return bigAns;
    }
    BigNum & operator *=(const int nInput){
        int y;
        long long nNum = nInput;
        if(nNum < 0) {
            isNeg = !isNeg;
            nNum = llabs(nNum);
        }
        for(y = 0; y < nDigit; y++){
            rgDgt[y] *= nNum;
        }

        CheckAdvance(0);
        UpdateDigit();
        return *this;
    }

    BigNum & operator/=(const long long nInput)
    {
        long long nNum = nInput;
        long long nRem = 0;
        if(nNum < 0){
            isNeg = !isNeg;
            nNum = llabs(nNum);
        }
        for(int y = nDigit - 1; y >= 0; y--){
            rgDgt[y] += nRem * BIGNUM_BASE;
            nRem = rgDgt[y] % nNum;
            rgDgt[y] /= nNum;
            if(y == nDigit - 1 && rgDgt[y] == 0){
                nDigit--;
            }
        }
        return *this;
    }
    BigNum & operator%=(const long long nInput)
    {
        BigNum bn = *this;
        bn /= nInput;
        bn *= nInput;
        *this -= bn;
        return *this;
    }
    const BigNum operator+(const BigNum &bigNum) const{
        return BigNum(*this) += bigNum;
    }
    const BigNum operator+(const long long nNum) const{
        return BigNum(*this) += nNum;
    }
    const BigNum operator-(const BigNum &bigNum) const{
        return BigNum(*this) -= bigNum;
    }
    const BigNum operator-(const long long nNum) const{
        return BigNum(*this) -= nNum;
    }
    BigNum & operator*=(const BigNum &bigNum){
        *this = (*this) * bigNum;
        return *this;
    }
    BigNum &operator*=(const long long nNum){
        return (*this) *= BigNum(nNum);
    }
    const BigNum operator*(const int nNum) const{
        return (BigNum(*this) *= nNum);
    }
    const BigNum operator*(const long long nNum) const{
        return (*this) * BigNum(nNum);
    }
    const BigNum operator/(const long long nNum) const{
        return (BigNum(*this) /= nNum);
    }
};

struct Year{
    char szNum[60];
    int  nLen;
};

Year rgYear[1200];

int compare(const void *A, const void *B)
{
    const Year *a = (const Year *)A;
    const Year *b = (const Year *)B;
    if(a->nLen != b->nLen)
        return a->nLen - b->nLen;
    return strcmp(a->szNum, b->szNum);

}

int main()
{
    int x, y, nCnt;
    char szInput[100000];
    char *pToken;
    string strMin, strAns;
    BigNum rgBN[1200];
    BigNum rgOrgBN[1200];
    BigNum bnMin, bnTmp;
    char rgszNum[1200][60];
    
    int nMaxCase;
    int nDiffCnt;

    scanf("%d", &nMaxCase);
    for(nCase = 1; nCase <= nMaxCase; nCase++){
        scanf("%d", &nCnt);
        for(x = 0; x < nCnt; x++){
            scanf("%s", rgYear[x].szNum);
            rgYear[x].nLen = strlen(rgYear[x].szNum);
        }

        qsort(rgYear, nCnt, sizeof(rgYear[0]), compare);
        for(x = 0; x < nCnt; x++){
            rgOrgBN[x].Set(rgYear[x].szNum);
        }

        bnMin = 0;
        
        while(true){
            nDiffCnt = 0;
            for(x = 0; x < nCnt; x++){
                rgBN[x].Set(rgYear[x].szNum);
            }
            for(x = 1; x < nCnt; x++){
                if(rgBN[x] == rgBN[x - 1]) continue;
                
                bnTmp = rgBN[x] - rgBN[x - 1];
                strcpy(rgYear[nDiffCnt].szNum, bnTmp.ToString().c_str());
                rgYear[nDiffCnt].nLen = strlen(rgYear[nDiffCnt].szNum);
                nDiffCnt++;
            }
            if(nDiffCnt == 0) break;
            if(nDiffCnt == 2){
                rgBN[0].Set(rgYear[0].szNum);
                rgBN[1].Set(rgYear[1].szNum);
                int r, l;
                r = 0; l = 1;
                while(true){
                    while(rgBN[r] > rgBN[l] || rgBN[r] == rgBN[l]){
                        rgBN[r] -= rgBN[l];
                    }
                    if(rgBN[r] == 0){
                        bnMin = rgBN[l];
                        break;
                    }
                    r = 1 - r;
                    l = 1 - l;
                }
                break;
            }
            bnMin = bnTmp;
            nCnt = nDiffCnt;
            qsort(rgYear, nCnt, sizeof(rgYear[0]), compare);
        }

        if(bnMin != 0){
            while(rgOrgBN[0] > bnMin){
                rgOrgBN[0] -= bnMin;
            }
            bnMin -= rgOrgBN[0];
        }
        printf("Case #%d: %s\n", nCase, bnMin.ToString().c_str());
        //fprintf(stderr, "Case #%d: %s\n", nCase, bnMin.ToString().c_str());
    }

    return 0;
}

