#include <string>
#include <map>
#include <math.h>
#include <sstream>
#include <time.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#define fx first
#define sx second

typedef pair<int,int> ii;
typedef vector<int> vec;
typedef vector<ii> vecp;
typedef long long int lli;
typedef unsigned long long int ulli;

/*************************************
 An ANSI-C implementation of the digamma-function for real arguments based
 on the Chebyshev expansion proposed in appendix E of 
 http://arXiv.org/abs/math.CA/0403344 . This is identical to the implementation
 by Jet Wimp, Math. Comp. vol 15 no 74 (1961) pp 174 (see Table 1).
 For other implementations see
 the GSL implementation for Psi(Digamma) in
 http://www.gnu.org/software/gsl/manual/html_node/Psi-_0028Digamma_0029-Function.html

Richard J. Mathar, 2005-11-24
**************************************/

#ifndef M_PIl
/** The constant Pi in high precision */
#define M_PIl 3.1415926535897932384626433832795029L
#endif
#ifndef M_GAMMAl
/** Euler's constant in high precision */
#define M_GAMMAl 0.5772156649015328606065120900824024L
#endif
#ifndef M_LN2l
/** the natural logarithm of 2 in high precision */
#define M_LN2l 0.6931471805599453094172321214581766L
#endif

/** The digamma function in long double precision.
* @param x the real value of the argument
* @return the value of the digamma (psi) function at that point
* @author Richard J. Mathar
* @since 2005-11-24
*/
long double digammal(long double x)
{
	/* force into the interval 1..3 */
	if( x < 0.0L )
		return digammal(1.0L-x)+M_PIl/tanl(M_PIl*(1.0L-x)) ;	/* reflection formula */
	else if( x < 1.0L )
		return digammal(1.0L+x)-1.0L/x ;
	else if ( x == 1.0L)
		return -M_GAMMAl ;
	else if ( x == 2.0L)
		return 1.0L-M_GAMMAl ;
	else if ( x == 3.0L)
		return 1.5L-M_GAMMAl ;
	else if ( x > 3.0L)
		/* duplication formula */
		return 0.5L*(digammal(x/2.0L)+digammal((x+1.0L)/2.0L))+M_LN2l ;
	else
	{
		/* Just for your information, the following lines contain
		* the Maple source code to re-generate the table that is
		* eventually becoming the Kncoe[] array below
		* interface(prettyprint=0) :
		* Digits := 63 :
		* r := 0 :
		* 
		* for l from 1 to 60 do
		* 	d := binomial(-1/2,l) :
		* 	r := r+d*(-1)^l*(Zeta(2*l+1) -1) ;
		* 	evalf(r) ;
		* 	print(%,evalf(1+Psi(1)-r)) ;
		*o d :
		* 
		* for N from 1 to 28 do
		* 	r := 0 :
		* 	n := N-1 :
		*
 		*	for l from iquo(n+3,2) to 70 do
		*		d := 0 :
 		*		for s from 0 to n+1 do
 		*		 d := d+(-1)^s*binomial(n+1,s)*binomial((s-1)/2,l) :
 		*		od :
 		*		if 2*l-n > 1 then
 		*		r := r+d*(-1)^l*(Zeta(2*l-n) -1) :
 		*		fi :
 		*	od :
 		*	print(evalf((-1)^n*2*r)) ;
 		*od :
 		*quit :
		*/
		static long double Kncoe[] = { .30459198558715155634315638246624251L,
		.72037977439182833573548891941219706L, -.12454959243861367729528855995001087L,
		.27769457331927827002810119567456810e-1L, -.67762371439822456447373550186163070e-2L,
		.17238755142247705209823876688592170e-2L, -.44817699064252933515310345718960928e-3L,
		.11793660000155572716272710617753373e-3L, -.31253894280980134452125172274246963e-4L,
		.83173997012173283398932708991137488e-5L, -.22191427643780045431149221890172210e-5L,
		.59302266729329346291029599913617915e-6L, -.15863051191470655433559920279603632e-6L,
		.42459203983193603241777510648681429e-7L, -.11369129616951114238848106591780146e-7L,
		.304502217295931698401459168423403510e-8L, -.81568455080753152802915013641723686e-9L,
		.21852324749975455125936715817306383e-9L, -.58546491441689515680751900276454407e-10L,
		.15686348450871204869813586459513648e-10L, -.42029496273143231373796179302482033e-11L,
		.11261435719264907097227520956710754e-11L, -.30174353636860279765375177200637590e-12L,
		.80850955256389526647406571868193768e-13L, -.21663779809421233144009565199997351e-13L,
		.58047634271339391495076374966835526e-14L, -.15553767189204733561108869588173845e-14L,
		.41676108598040807753707828039353330e-15L, -.11167065064221317094734023242188463e-15L } ;

		register long double Tn_1 = 1.0L ;	/* T_{n-1}(x), started at n=1 */
		register long double Tn = x-2.0L ;	/* T_{n}(x) , started at n=1 */
		register long double resul = Kncoe[0] + Kncoe[1]*Tn ;

		x -= 2.0L ;

		for(int n = 2 ; n < sizeof(Kncoe)/sizeof(long double) ;n++)
		{
			const long double Tn1 = 2.0L * x * Tn - Tn_1 ;	/* Chebyshev recursion, Eq. 22.7.4 Abramowitz-Stegun */
			resul += Kncoe[n]*Tn1 ;
			Tn_1 = Tn ;
			Tn = Tn1 ;
		}
		return resul ;
	}
}

long double C,F,X;
long double eps=1e-7;

//calculates the total time required for making n farms and X cookies
double calc(int q)
{
	if(q==0) return X/2.0L;
	long double n=q;
	n--;
	return C*(digammal(n+2.0L/F+1)-digammal(2.0L/F))/F+X/(2.0L+(n+1)*F);
}

int main()
{
	ifstream input;
	input.open("b3.in",ios::in);
	ofstream out;
	out.open("b.out",ios::out);

	int count;
	input>>count;

	C=500.0;
	F=4.0;
	X=2000.0;

	// for (double n = 0; n < 1000; ++n)
	// {
	// 	printf("%d %.7f \n",(int)n,calc(n));
	// }

	for (int i = 1; i <= count; ++i)
	{
		input>>C>>F>>X;

		// int low=1;
		// int high;
		// int mid;

		// double res=calc(0);
		// double temp=calc(low);
		
		// while(temp<res)
		// {
		// 	res=temp;
		// 	low*=2;
		// 	temp=calc(low);
		// }
		// high=low;
		// low/=4-10;
		// if(low<0) low=0;

		// while(low<high-10)
		// {
		// 	mid=(low+high)/2;
			
		// 	res=calc(mid);
		// 	temp=calc(mid-1);

		// 	if(res<temp) low=mid+1;
		// 	else high=mid-1;
		// }
		// // cout<<low<<" "<<high<<endl;
		// low-=5;
		// if(low<0) low=0;
		
		// for (int j = 0; j < 32; ++j)
		// {
		// 	temp=calc(low);
		// 	if(temp<res) res=temp;
		// 	++low;
		// }

		int n=0;
		double res=0.0f;
		double temp=C/2.0f;

		while(res+X/(2.0f+n*F)>temp+X/(2.0f+(n+1)*F))
		{
			// cout<<n<<" "<<res+X/(2.0f+n*F)<<endl;
			++n;
			res=temp;
			temp+=C/(2.0f+n*F);
		}
		res+=X/(2.0+n*F);

		// cout<<mid<<" "<<res<<endl;

		cout<<i<<"++"<<calc(0)<<endl;
		cout<<i<<"++"<<calc(1)<<endl;




		//printing the output
		out<<"Case #"<<i<<": ";
		out<<fixed<<setprecision(7)<<res;

		
		if(i<count) out<<endl;
	}

	return 0;
}
