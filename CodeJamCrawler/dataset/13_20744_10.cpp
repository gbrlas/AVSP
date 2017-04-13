#include "googleCodeJam.h"

/**The First Question**/
void kernelPart2013_B1(istream& ifile, ostream &ofile, int index)
{
	vector<unsigned> mote;
	//processing...
	unsigned A,N;
	ifile>>A>>N;
	for(size_t i=0;i<N;i++)
	{
		unsigned tmp;
		ifile>>tmp;
		mote.push_back(tmp);
	}
	sort(mote.begin(),mote.end());
	unsigned op=0;
	for(size_t i=0;i<N;i++)
	{
		if(mote[i]<A)
			A+=mote[i];
		else
		{
			unsigned left=N-i;
			unsigned ta=A;
			size_t j=i;
			for(;j<N;j++)
			{
				ta+=(ta-1);
				if(ta>mote[i])
					break;
			}
			if(ta>mote[i])
			{
				op+=j-i+1;
				A=ta+mote[i];
			}
			else
			{
				op+=left;
				break;
			}

		}
	}
	//print the result
	ofile<<"Case #"<<index+1<<": "<<op<<endl;
	//the result.
	//ofile<<RESULT<<endl;
}

//////////////////////////////////////////////////////////////////
/**The Second Question**/
void kernelPart2013_B2(istream& ifile, ostream &ofile, int index)
{
	//processing...
	
	//print the result
	ofile<<"Case #"<<index+1<<": ";
	//the result.
	//ofile<<RESULT<<endl;
}

//////////////////////////////////////////////////////////////////
/*The Third Question*/
void kernelPart2013_B3(istream& ifile, ostream &ofile, int index)
{
	//processing...
	
	//print the result
	ofile<<"Case #"<<index+1<<": ";
	//the result.
	//ofile<<RESULT<<endl;
}