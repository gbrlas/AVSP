#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility> 
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;
#define CLEAR(t) memset((t),0,sizeof(t))
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,n) for(int i=0;i<(n);++i) 


const int l=125, p=l, offset=0;
const int maxl = l, defFrom = 0;//120;

typedef vector<int> CLAUSE;
typedef vector<CLAUSE> FORM;

int F;
int ommited = 0;

void addClause(FORM &f, CLAUSE &c){
  //REP(i,(int)c.size())if(c[i]==-F){ommited++;return;}
  f.push_back(c);
}

void addFormula(FORM &f, FORM &g){
  f.insert(f.end(),g.begin(),g.end());
}

void joinClause(CLAUSE &c, CLAUSE &d){
  c.insert(c.end(),d.begin(),d.end());
  sort(c.begin(),c.end());
  c.erase(unique(c.begin(),c.end()),c.end());
}

void orClause(FORM &f, CLAUSE &c){
  REP(i,(int)f.size())
    joinClause(f[i],c);
}

void orFormula(FORM &f, FORM&g, FORM &h){
  if(f.size()==0){
    h.assign(g.begin(),g.end());    
  }else if(g.size()==0)h.assign(f.begin(),f.end());
  else {
    h.clear();
    REP(i,(int)f.size())
      REP(j,(int)g.size()){
        CLAUSE c=f[i];
        joinClause(c,g[j]);
        addClause(h,c);
      }
  }
}

void print(FORM &f){
  int mvar = 0;
  REP(i,(int)f.size())
    REP(j,(int)f[i].size())mvar = max(max(mvar, f[i][j]), -f[i][j]);
  printf("p cnf %d %d\n",mvar, (int)f.size());
  REP(i,(int)f.size()){
    REP(j,(int)f[i].size())
      printf("%d ",f[i][j]);
    printf("0\n");
  }
}

CLAUSE& newClause(int x){
  CLAUSE *v=new vector<int>();
  v->push_back(x);
  return *v;
}

CLAUSE& newClause(int x, int y){
  CLAUSE *v=new vector<int>();
  v->push_back(x);
  v->push_back(y);
  return *v;
}


CLAUSE& newClause(int x, int y, int z){
  CLAUSE *v=new vector<int>();
  v->push_back(x);
  v->push_back(y);
  v->push_back(z);
  return *v;
}

CLAUSE& newClause(int x, int y, int z, int w){
  CLAUSE *v=new vector<int>();
  v->push_back(x);
  v->push_back(y);
  v->push_back(z);
  v->push_back(w);
  return *v;
}


int vars = 0;

int getNewVar(){
  return ++vars;
}

//out = ~in
void negateFormula(FORM &in, FORM &out){
  out.clear();
  FORM tmp;
  if(in.size()==0){
    addClause(out, newClause(F));
    return ;
  }
  REP(i,(int)in.size()){
    FORM f;
    REP(j,(int)in[i].size())
      addClause(f, newClause(-in[i][j]));
    orFormula(out, f, tmp);
    out = tmp;
  }
}

//var <-> in
void newName(int var, FORM &in, FORM &out){
  FORM tmp=in;
  orClause(tmp, newClause(-var));
  addFormula(out, tmp);
  negateFormula(in, tmp);
  orClause(tmp, newClause(var));
  addFormula(out, tmp);
}

//x+y
void addBitAdder(FORM &f, int x, int y, int i, int s, int c){
  addClause(f, newClause(x,y,-c));
  addClause(f, newClause(x,i,-c));
  addClause(f, newClause(y,i,-c));
  addClause(f, newClause(-x,-y,c));
  addClause(f, newClause(-x,-i,c));
  addClause(f, newClause(-y,-i,c));

  addClause(f, newClause(x,y,i,-s));
  addClause(f, newClause(x,-y,-i,-s));
  addClause(f, newClause(-x,y,-i,-s));
  addClause(f, newClause(-x,-y,i,-s));
  addClause(f, newClause(-x,-y,-i,s));
  addClause(f, newClause(-x,y,i,s));
  addClause(f, newClause(x,-y,i,s));
  addClause(f, newClause(x,y,-i,s));
}

//x-y
void addBitSub(FORM &f, int x, int y, int i, int s, int c){
  addClause(f, newClause(-x,y,-c));
  addClause(f, newClause(-x,i,-c));
  addClause(f, newClause(y,i,-c));
  addClause(f, newClause(x,-y,c));
  addClause(f, newClause(x,-i,c));
  addClause(f, newClause(-y,-i,c));

  addClause(f, newClause(x,y,i,-s));
  addClause(f, newClause(x,-y,-i,-s));
  addClause(f, newClause(-x,y,-i,-s));
  addClause(f, newClause(-x,-y,i,-s));
  addClause(f, newClause(-x,-y,-i,s));
  addClause(f, newClause(-x,y,i,s));
  addClause(f, newClause(x,-y,i,s));
  addClause(f, newClause(x,y,-i,s));
}


//z = x & y
void addAnd(int x, int y, int z, FORM &f){
  addClause(f, newClause(x,-z));
  addClause(f, newClause(y,-z));
  addClause(f, newClause(-x,-y,z));
}

//d = a & b & c
void addAnd(int a, int b, int c, int d, FORM &f){
  addClause(f, newClause(a, -d));
  addClause(f, newClause(b, -d));
  addClause(f, newClause(c, -d));
  addClause(f, newClause(-a, -b, -c, d));
}

void addImplies(int x, int y, FORM &f){
  addClause(f, newClause(-x,y));
}

void addEq(int x, int y, FORM &f){
  addImplies(x,y,f);
  addImplies(y,x,f);
};

void negateSingleton(FORM &f, FORM &out){
  out.clear();
  CLAUSE c;
  REP(i,(int)f.size()){
    assert(f[i].size()==1);
    c.push_back(-f[i][0]);
  }
  out.push_back(c);
}

class fp{
  public:
    vector<int> a;
    int l;
    int from, to;

    void init(int f, int t){
      from = f;
      to = t;      
      l = to - from;
      REP(i,l)a.push_back(getNewVar());
    }

    fp(int ll){
      init(0, ll);
    }

    fp(){
      init(0, ::l);
    }

    fp(int f, int t){
      init(f, t);
    }

    int operator[](int index){
      if(index<from || index >= to)return F;
      return a[index-from];
    }

    void addWellFormed(FORM &f){
      return;
      int allz[l];
      REP(i,l)allz[i]=getNewVar();
      addClause(f, newClause(allz[0]));
      for(int i=1;i<l;i++)
        addAnd(allz[i-1], -a[i-1], allz[i], f);
      REP(i,l)if(i-p+1>=0)addImplies(a[i], allz[i-p+1], f);
    }

};

void setToZeroOutside(fp x, int from, int to, FORM &f, int offset = 0){
  for(int i=x.from; i<from && i<x.to; i++)
    if(i-offset >= 0)
      addClause(f, newClause(-x[i]));
  for(int i=max(x.from, to); i<x.to; i++)
    if(i-offset >= 0)
      addClause(f, newClause(-x[i]));
}

//TODO: x, y disjoint
void addBinary(fp x, fp y, fp z, FORM &f){
  int from = max(x.from, y.from);

  if(x.to <= y.from || y.to <= x.from)
    cerr<<"disjoint-----------------------------------------------"<<endl;

  if(x.from < y.from)
    for(int i=x.from; i<y.from; i++)
      addEq(z[i], x[i], f);
  if(y.from < x.from)
    for(int i=y.from; i<x.from; i++)
      addEq(z[i], y[i], f);
  
  int to = max(x.to, y.to);
  int l = to - from;
  int carry[l+1];
  REP(i,l+1)carry[i] = getNewVar();
  addClause(f, newClause(-carry[0]));
  
  REP(i,l)
    addBitAdder(f, x[i+from], y[i+from], carry[i], z[i+from], carry[i+1]);
  addEq(carry[l], z[to], f);
  setToZeroOutside(z, min(x.from, y.from) , to+1, f);

}

//TODO: x, y disjoint
void subBinary(fp x, fp y, fp z, FORM &f){
  int from = min(x.from, y.from);
  int to = max(x.to, y.to);
  int l = to - from;
  int carry[l+1];
  REP(i,l+1)carry[i] = getNewVar();
  addClause(f, newClause(-carry[0]));  
  addClause(f, newClause(-carry[l]));//no overflow x>y

  REP(i,l)
    addBitSub(f, x[i+from], y[i+from], carry[i], z[i+from], carry[i+1]);

  setToZeroOutside(z, from, to, f);
}

//TODO: restrict to [inter.from, inter.to)
//z is properly rounded inter (rounds to even)
void round(fp inter, fp z, FORM &f){
//  assert(inter.l==z.l);
//  int l=inter.l;
  int l = inter.to;
  int allz[l];
  REP(i,l)allz[i]=getNewVar();
  addClause(f, newClause(allz[l-1]));
  for(int i=l-2;i>=0;i--)
    addAnd(allz[i+1],-inter[i+1], allz[i], f);

  int remtz[l];
  int allz2[l];
  REP(i,l)remtz[i]=getNewVar();
  REP(i,l)allz2[i]=getNewVar();
  fp copy(inter.from, inter.to), plus(inter.from, inter.to);
  addClause(f, newClause(remtz[0]));
  addClause(f, newClause(allz2[0]));
  for(int i=1;i<l;i++){
    addAnd(remtz[i-1], -copy[i-1], -plus[i-1], remtz[i],f);
    addAnd(allz2[i-1], -inter[i-1], allz2[i], f);
  }

  cerr<<"z : "<<z[0]<<" "<<z[l-1]<<endl;
  cerr<<"pl: "<<plus[0]<<" "<<plus[l-1]<<endl;
  cerr<<"co: "<<copy[0]<<" "<<copy[l-1]<<endl;

  REP(i,l){
    CLAUSE c = newClause(-inter[i], -allz[i]);
    for(int j=0;j<p && i-j>=0; j++){
      FORM tmp;
      addEq(copy[i-j], inter[i-j], tmp);
      orClause(tmp, c);      
      addFormula(f,tmp);
      if(j!=p-1){
        FORM tmp2;
        addClause(tmp2, newClause(-plus[i-j]));
        orClause(tmp2, c);
        addFormula(f,tmp2);
      }
    }
    if(i-p+1>=0)addClause(f, newClause(-inter[i], -allz[i], remtz[i-p+1]));
    FORM tmp;
    addEq(copy[i], inter[i], tmp);
    if(i>0)orClause(tmp, newClause(-allz[i-1]));//TODO: inter[i] is false in this case
    else orClause(tmp, newClause(-allz[0]));
    if(i>0){
      addImplies(allz[i-1], -plus[i], f);
    }else addClause(f, newClause(-plus[0]));//first bit of plus is always 0
    addFormula(f,tmp);

    if(i-p>=0){
      FORM X;
      addClause(X, newClause(inter[i-p]));
      addClause(X, newClause(-allz2[i-p]));
      FORM Y;
      addClause(Y, newClause(inter[i-p]));
      addClause(Y, newClause(allz2[i-p]));
      addClause(Y, newClause(inter[i-p+1]));
      FORM XN, YN;
      negateSingleton(X,XN);negateSingleton(Y,YN);
      int z = plus[i-p+1];
      orClause(XN, newClause(z));
      orClause(YN, newClause(z));
      FORM OR;
      orFormula(X,Y, OR);
      orClause(OR, newClause(-z));
      addFormula(OR,XN);
      addFormula(OR,YN);
      orClause(OR,c);
      addFormula(f,OR);
//      int len=0;REP(i,(int)OR.size())len+=OR[i].size();cerr<<"Clauses: "<<OR.size()<<" Literals: "<<len<<endl;
    }
  }
  addBinary(copy, plus, z, f);
  cerr<<"clauses: "<<f.size()<<endl;

}

//z = x+y
void add(fp x, fp y, fp z, FORM &f){
//  int l=x.l;
  fp inter(min(x.from, y.from), min(z.to, max(x.to, y.to) + 1));
  cerr<<"in: "<<inter[0]<<" "<<inter[l-1]<<endl;
  addBinary(x,y,inter,f);
  round(inter, z, f);
}

//z = x-y
void sub(fp x, fp y, fp z, FORM &f){
//  int l=x.l;
  fp inter(min(x.from, y.from), min(z.to, max(x.to, y.to)));
  cerr<<"in: "<<inter[0]<<" "<<inter[l-1]<<endl;
  subBinary(x,y,inter,f);
  round(inter, z, f);

}

void addEqual(fp a, fp b, FORM &f){
  for(int i=min(a.from, b.from); i<max(a.to, b.to); i++)
    addEq(a[i],b[i],f);
}

void shiftCopy(int shift, int b, fp in, fp out, FORM &f){
  for(int i=in.from; i<in.to; i++)
    addAnd(b, in[i], out[i+shift], f);
  setToZeroOutside(out, in.from + shift, in.to+shift, f);
}

void mult(fp x, fp y, fp z, FORM &f){

  if(x.l < y.l){
    mult(y, x, z, f);
    return;
  }

  int l=y.to-y.from;

  if(l==0 || x.to-x.from ==0){
    for(int i=z.from; i<z.to; i++)
      addClause(f, newClause(-z[i]));
    return;
  }
  
  fp *inter[l];
  REP(i,l)inter[i] = new fp(0,2*l);
  for(int i=y.from; i<y.to; i++){
    shiftCopy(i,y[i],x,*inter[i-y.from], f);
//    cerr<<"in "<<(*inter[i])[i]<<endl;
  }
  fp *br;
  if(l>1){
    fp *res[l-1];
    REP(i,l-1)res[i] = new fp(0, 2*l);
    addBinary(*inter[0], *inter[1], *res[0], f);
    for(int i=2;i<l;i++)
      addBinary(*res[i-2], *inter[i], *res[i-1], f);
    br = new fp(0, 2*l);//+1
    for(int i=0;i<2*l;i++){
//      cerr<<i<<" c "<<(*br)[i]<<endl;
      addEq((*br)[i], (*(res[l-2]))[i],f);
    }
//    round(*res[l-2],*br,f);    
    for(int i=l; i<2*l; i++)
      addClause(f, newClause(-(*res[l-2])[i]));
  } else {
    br = new fp(inter[0]->from, inter[0]->to+1);
//    round(*inter[0], *br, f);
  };
  for(int i=0;i<l;i++)
    addEq(z[i], (*br)[i], f);
  
//  for(int i=l;i<br->to;i++)
//    addClause(f, newClause(-((*br)[i])));

//  setToZeroOutside(*br, 0, l, f, 0);  //no overflow
//  for(int i=z.to+offset; i<br->to; i++)
//    addClause(f, newClause(-(*br)[i]));

}

int main(){
/*
  string cond; cin>>cond;
  CLAUSE ifc;
  while(true){
    string z, s, x, op, y;
    if(!(cin>>z))break;
    if(z=="if"){
      cin>>z>>s>>x;
      fp *zv = getVar(z, true, out);
      fp *xv = getVar(x, true, out);
      if (isNum(z))
        setInt(atoi(z.c_str()), *zv, out);
      if (isNum(x))
        setInt(atoi(x.c_str()), *xv, out);
      int var = -getCompVar(*zv, *xv, s, out);
      cerr<<"if: "+z+s+x+" "<<var<<endl;
      ifc.push_back(var);
    }else if (z=="endif"){
      ifc.pop_back();
    }else if (z=="elseif"){
      int var = ifc.back();
      ifc.pop_back();
      ifc.push_back(-var);
    }else{
      cerr<<"before: "<<out.size()<<endl;
      cin>>s;
      FORM tmp;
      if (s == "<=" || s == "<" || s == ">" || s==">=" || s == "==" || s=="!="){
        fp *zv = getVar(z, true, tmp);
        cin>>x;      
        fp *xv = getVar(x, true, tmp);
        if (isNum(x))
          setInt(atoi(x.c_str()), *xv, tmp);
        int var = getCompVar(*zv, *xv, s, tmp);
        addClause(tmp, newClause(var));
      }else{
        x = s;
        cin>>op>>y;
        fp *xv = getVar(x, true, tmp);
        fp *yv = getVar(y, true, tmp);
        if(isNum(x))          
          setInt(atoi(x.c_str()), *xv, tmp);
        if(isNum(y))
          setInt(atoi(y.c_str()), *yv, tmp);
        if(op == "+"){
          fp *zv = getVar(z, false, tmp, min(xv->from, yv->from), max(xv->to, yv->to)+1);
          add(*xv, *yv, *zv, tmp);
        }else if(op == "-"){
          fp *zv = getVar(z, false, tmp, min(xv->from, yv->from), max(xv->to, yv->to));
          sub(*xv, *yv, *zv, tmp);
        } else if(op == "*"){
          fp *zv = getVar(z, false, tmp, xv->from+yv->from-offset, xv->to+yv->to-offset);
          mult(*xv, *yv, *zv, tmp);
        }
      }
      orClause(tmp, ifc);
      addFormula(out, tmp);
      cerr<<"Command: "<<s<<op<<y<<" "<<out.size()<<endl;
    }
  }
  */

  int tt;scanf("%d",&tt);
  REP(ttt,tt){
    vars=0;
    FORM out;  
    F = getNewVar();
    out.push_back(newClause(-F));
    char s[200];scanf("%s",s);
    int l=strlen(s);
    fp x;
    fp res;
    REP(i,l){
      if(s[l-i-1]=='0'){
        addClause(out, newClause(-res[i]));
      }
      if(s[l-i-1]=='1'){
        addClause(out, newClause(res[i]));
      }
    }
    for(int i=l;i<maxl;i++)
      addClause(out,newClause(-res[i]));
    mult(x, x, res, out);
    sprintf(s,"t%d.in",ttt);
    freopen(s,"w",stdout);
    print(out);
    fclose(stdout);
    REP(i,maxl)cerr<<res[i]<<endl;
  };
  /*
  cerr<<"vars: "<<endl;
  for(map<string, fp*>::iterator it=mfp.begin();it!=mfp.end();it++)
    cerr<<it->first<<" "<<(*(it->second))[it->second->from]<<" "<<
      it->second->from<<" "<<it->second->l<<endl;
  
  cerr<<ommited<<endl;*/
}
