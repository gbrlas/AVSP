 /*	-------------------------------------------------------------	*/
/*		Muhammad Zohaib Khalid										*/
/*	-------------------------------------------------------------	*/

//	
#include<iostream>
#include<conio.h>								//	Including necessary header files
#include<string>
#include<fstream>
#include<process.h>
#include<windows.h>
#include<math.h>

using namespace std;

void main()
{
	ifstream in;
	ofstream out;
	in.open("A-small.in");
	out.open("A-small.out");
	int run,run2;
	in >> run;
	run2=run;

	for(;run>0; run--)
	{
		out << "Case #" << run2-run+1 << ": ";
		int s,q;
		char temp='0';
		string tem;
		in >> s;

		string search[10];
		string queries[100];

		for (int counter=0; counter<s; counter++)
		{
			in>>search[counter];
			in.get(temp);
			while (temp == ' ')
			{
				in >> tem;
				search[counter] = search[counter] + " " + tem;
				in.get(temp);
			}
		}

		in >> q;

		for (counter=0; counter<q; counter++)
		{
			in >> queries[counter];
			in.get(temp);
			while (temp == ' ')
			{
				in >> tem;
				queries[counter] = queries[counter] + " " + tem;
				in.get(temp);
			}
		}
		
		int swish=0;
		int mincountold = 99999999;
		for (int index=0; index<q;)
		{
			int searchcount[10]={0};

			for (counter=index; counter<q; counter++)
				for (int counter2=0; counter2<s; counter2++)
					if (queries[counter] == search[counter2])			// counting engines 1st
						searchcount[counter2]++;

			int minimum = 99999;
			int mincount = 99999;

			for (counter=0; counter<s; counter++)
				if (minimum > searchcount[counter] && mincountold != counter)
				{
					minimum = searchcount[counter];						//	1st minimum
					mincount = counter;
				}

			if (minimum == 0)
				break;

			for (counter=0; counter<s; counter++)
				if (minimum == searchcount[counter] && mincount!=counter && mincountold != counter)
				{
					for (int c1=index; c1<=q; c1++)
						if (queries[c1] == search[mincount])
							break;

					for (int c2=index; c2<=q; c2++)
						if (queries[c2] == search[counter])
							break;
						
					if (c2>c1)
						mincount = counter;
					else if (c1==c2)
						cout << "there is some problem";
				}
					



			int minq=-1;
			for (counter=index; counter<=q; counter++)
				if (search[mincount] == queries[counter])
				{
					minq=counter;										//	1st minimum query counter
					break;
				}

			for (int qq=0; qq<10; qq++)
				searchcount[qq]=0;

			for (counter=index; counter<=minq; counter++)
				for (int counter2=0; counter2<s; counter2++)
					if (queries[counter] == search[counter2])			//	|--| engines counting 2nd
						searchcount[counter2]++;

			minimum = 99999;

			for (counter=0; counter<s; counter++)
				if (minimum > searchcount[counter] && mincountold != counter)
				{
					minimum = searchcount[counter];						//	Minimum again !
					mincount = counter;
				}
		/*		else if (minimum == searchcount[counter])
				{
					for(int c = index; c<q; c++)
					{
						if (search[mincount] == queries[c])
						{
							minimum = searchcount[counter];
							mincount = counter;
							break;
						}
						else if (search[counter] == queries[c])
							break;
					}
				}*/
			for (counter=0; counter<s; counter++)
				if (minimum == searchcount[counter] && mincount!=counter && mincountold != counter)
				{
					for (int c1=index; c1<=q; c1++)
						if (queries[c1] == search[mincount])
							break;

					for (int c2=index; c2<=q; c2++)
						if (queries[c2] == search[counter])
							break;
						
					if (c2>c1)
						mincount = counter;
					else if (c1==c2)
						cout << "there is some problem";
				}

			for (counter=index; counter<q; counter++)
			{
				if (search[mincount] == queries[counter])			// swishing ...
				{
					index = counter+1;
					break;
				}
			}

			swish++;
			mincountold = mincount;
		}

		if(q<=s || swish == -1)
			out << "0" <<endl;
		else out << swish <<endl;
	}
}