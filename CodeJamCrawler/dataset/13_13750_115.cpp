//#define ORE_DBG

#include "ore.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>


using boost::multiprecision::cpp_int;
using boost::multiprecision::cpp_dec_float;
using namespace boost::multiprecision;   

namespace ore = ore_utils;

bool isPalind(const cpp_int& i)
{
	std::string s = STR(i);
	int n = s.size();
	int q1 = n/2;
	int q2 = (n + 1) / 2;

	for (int i=0; i< q1; i++)
	{
		if ( s[i] != s[ n-i-1] )
			return false;
	}
	
	return true;
}

cpp_int conv(number<cpp_dec_float<100>>i)
{
	std::stringstream ss;
	ss <<  std::setprecision(std::numeric_limits<cpp_dec_float_100>::max_digits10) << i;
	std::string s;
	ss >>s;
	auto ps = SPLIT(s , ".");
	//PRINTALL(ps);
	cpp_int r(ps[0]);
	return r;
}

cpp_int getPalind(cpp_int ra, cpp_int rb, cpp_int a, cpp_int b)
{
	std::string s1 = STR(ra);
	s1 = s1.substr(0, (s1.size()  ) / 2 );
	cpp_int total = 0;
	cpp_int q(s1);
	
	while(true)
	{
		std::string l = STR(q);
		std::string r = l;
		std::reverse(r.begin(), r.end());
		cpp_int n1(l+r);
		cpp_int m1 = n1*n1;
		if (m1 >=a && m1 <= b && isPalind(m1))
		{
			total++;
		}
		q++;

		
		{
			r.erase(r.begin());
			cpp_int n2(l+r);
			cpp_int m2 = n2*n2;
			if (m2 >=a && m2 <=b && isPalind(m2))
			{
				total++;
			}
			if (n2 > rb)
				break;		
		}
	}
	
	return total;
}




int handlecase(strlist& lines, int caseno)
{
	std::stringstream line(POP(lines));
	cpp_int a;
	cpp_int b;
	line >> a;
	line >> b;
	number<cpp_dec_float<100>> c(a);
	c = boost::multiprecision::sqrt(c);
	cpp_int ra  = conv(c);

	number<cpp_dec_float<100>> d(b);
	d = boost::multiprecision::sqrt(d);
	cpp_int rb = conv(d);

	cpp_int res = getPalind(ra, rb, a, b);

 	
	PRINTCASE(res);
	
}

int main(int argc, char** argv)
{
	auto lines = OPEN(argv[1]);
	auto ncases = INT(POP(lines));
	for (auto caseno : RANGE(ncases) ) handlecase(lines, caseno);
}
