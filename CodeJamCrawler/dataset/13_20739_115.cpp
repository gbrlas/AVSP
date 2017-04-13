#include<fstream>
#include<vector>
using namespace std;

typedef vector<char> Row;
typedef vector<Row> Matrix;

int main()
{
	fstream readfile("theIn.txt");
	fstream writefile("theOut.txt",ios::out) ;
	if(!readfile || !writefile)
		return -1;

	size_t c=0;
	readfile>>c;
	for(size_t i=0;i<c;i++)
	{
		int row,col;
		readfile>>row>>col;
		Matrix ma(row,Row(col,0));
		for(int l=0;l<row;l++)
			for(int m=0;m<col;m++)
				readfile>>ma[l][m];
		bool ok=true;
		for(int l=0;l<row;l++)
			for(int m=0;m<col;m++)
			{
				char ch=ma[l][m];
				if('1'==ch)
				{
					bool fr=false,fc=false;
					for(int j=0;j<col;j++)
						if(ma[l][j] == '2')
						{
							fr=true;break;
						}
					for(int j=0;j<row;j++)
						if(ma[j][m] == '2')
						{
							fc=true;break;
						}
					if(fr && fc)
						ok=false;
				}

			}
		writefile<<"Case #"<<i+1<<": "<<(ok?"YES":"NO")<<endl;
	}
	writefile.close();
	readfile.close();
	return 0;
}