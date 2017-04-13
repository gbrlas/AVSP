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
	char Googlerese[27] = "yhesocvxduiglbkrztnwjpfmaq";

	FileReader in;
	FileWriter out;

	in.openFile("A-small-attempt1.in");
	out.openFile("out.txt");

	int num_test_cases = in.readInt();
	in.readString();
	
	for( int tnum = 0; tnum < num_test_cases; tnum++ )
	{
		string word = in.readString();
		int len = word.length();

		for (int i = 0; i < len; i++)
		{
			if (word[i] == ' ')
				continue;
			word[i] = Googlerese[word[i] - 97];
		}

		cout<<word<<endl;
		out.writeString("Case #");
		out.writeInt(tnum + 1);
		out.writeString(": ");
		out.writeString(word);
		out.endLine();
	}
	return 0;
}