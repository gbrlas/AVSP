#include<iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class FileReader {
public:
   bool openFile(string);
   int readInt();
   string readString();
   void close();
   void flush();
private:
   ifstream mystream;
};

void FileReader::flush() {
   mystream.clear();
}

bool FileReader::openFile(string fn) {
   mystream.open(fn.c_str());
   return mystream.is_open();
}

int FileReader::readInt() {
   int val;
   mystream >> val;

   return val;
}

string FileReader::readString() {
   string val;
   getline(mystream, val);

   return val;
}

void FileReader::close() {
   mystream.close();
}

class FileWriter {
public:
   bool openFile(string fn);
   void writeString(string);
   void writeInt(int);
   void endLine();
   void close();

private:
   ofstream mystream;
};

bool FileWriter::openFile(string fn) {
   mystream.open(fn.c_str());
   return mystream.is_open();
}

void FileWriter::writeString(string s) {
   mystream << s;
}

void FileWriter::writeInt(int val) {
   mystream << val;
}

void FileWriter::endLine() {
   mystream << endl;
}

void FileWriter::close() {
   mystream.close();
}
int main()
{
	FileReader in;
	FileWriter out;

	in.openFile("B-small-attempt3.in");
	out.openFile("shortout.txt");

	int num_test_cases = in.readInt();
	in.readString();
	
	for( int tnum = 0; tnum < num_test_cases; tnum++ )
	{
		int num_googler = in.readInt();
		int num_surp = in.readInt();
		int p = in.readInt();
		int count = 0;

		if ( p == 0 )
			count = num_googler;
		else
		for ( int i = 0; i<num_googler; i++)
		{
			int total_point = in.readInt();

			if ( total_point <= p )
				continue;

			if ( total_point/3 >= p )
				count++;
			else if ( p == ((total_point - p)/2) + 1 )
				count++;
			else if ( p == ((total_point - p)/2) + 2 )
			{
				if ( num_surp > 0 )
				{
					count++;num_surp--;
				}
			}
		}

		in.readString();
		out.writeString("Case #");
		out.writeInt(tnum + 1);
		out.writeString(": ");
		out.writeInt(count);
		out.endLine();
	}
	return 0;
}