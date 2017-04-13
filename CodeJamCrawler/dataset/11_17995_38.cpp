#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int b[1111],e[1111],w[1111];

int main() {
	ifstream cin("input.txt");
	freopen("output.txt","w",stdout);
	//ofstream cout("output.txt");
	int cc;
	cin>>cc;
	for(int cid=1;cid<=cc;++cid) {
	    int x,s,r,n;
	    double t;
	    cin>>x>>s>>r>>t>>n;
	    for(int i=0;i<n;++i) {
	        cin>>b[i]>>e[i]>>w[i];
	        x-=(e[i]-b[i]);
	    }
	    for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j)
                if(w[i]>w[j]) {
                    swap(w[i],w[j]);
                    swap(b[i],b[j]);
                    swap(e[i],e[j]);
                }
        double ans=0.0;
        double runtime=double(x)/double(r);
        if(runtime>t) {
            ans+=t+(double(x)-t*double(r))/double(s);
            t=0.0;
        }
        else {
            t-=runtime;
            ans+=runtime;
        }
        for(int i=0;i<n;++i) {
            if(t>0.0) {
                double rt=min(t,double(e[i]-b[i])/double(w[i]+r));
                t-=rt;
                ans+=rt+(double(e[i]-b[i])-rt*double(w[i]+r))/double(w[i]+s);
            }
            else {
                ans+=double(e[i]-b[i])/double(w[i]+s);
            }
        }
		printf("Case #%d: %.6lf\n",cid,ans);
	}
	return 0;
}
