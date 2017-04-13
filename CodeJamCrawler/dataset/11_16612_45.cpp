#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;


class Magicka {
public:
   string start();
   bool combine();
   bool oppose();
   string baseElem;
   string finalList;
   char com[100][4];
   char op[100][3];
   int ccount;
   int ocount;
   int picked;
};

bool Magicka::combine() {
   int i, len;
   char ch1,ch2;
   bool combined=false;

   len = finalList.length();
   ch1 = finalList[len - 2];
   ch2 = finalList[len - 1];

   if(len < 2)
      return false;

   for(i=0;i<ccount;i++) {
      if((com[i][0] == ch1 && com[i][1] == ch2) || (com[i][0] == ch2 && com[i][1] == ch1)) {
          finalList.erase(len-2, 2);
	  finalList.push_back(com[i][2]);
          combined = true;
	  break;	  
      }
   }
   return combined;
}

bool Magicka::oppose() {
   int i, len;
   int sind;
   char ch;
   bool opposed=false;

   len = finalList.length();
   ch = finalList[len-1];
  
   if(len < 2)
      return false;

   for(i=0;i<ocount;i++) {
      if(op[i][0] == ch) {
         sind = finalList.find_first_of(op[i][1]);
	 //found oppose rule
	 if (sind > -1) {
	    //finalList.erase(sind, len-sind);
	    finalList.clear();
	    opposed = true;
	    break;
         }
      }
      else if(op[i][1] == ch) {
         sind = finalList.find_first_of(op[i][0]);
	 //found oppose rule
	 if (sind > -1) {
	    //finalList.erase(sind, len-sind);
	    finalList.clear();
	    opposed = true;
	    break;
         }
      }
      
   }
   return opposed;
}

string Magicka::start() {
   picked=0;
   while(picked < baseElem.length()) {
      finalList.push_back(baseElem[picked++]);
      combine();
      oppose();
   }

   return finalList;
}

class FileReader {
public:
   FileReader() {}
   bool openFile(string);
   int readInt();
   string readString();
   long readLong();
   char readChar();
   float readFloat();

   void close();
   ~FileReader(){}

private:
   ifstream mystream;
};

bool FileReader::openFile(string fn) {
   if(mystream.is_open())
      mystream.close();

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

long FileReader::readLong() {
   long val;
   mystream >> val;

   return val;
}

char FileReader::readChar() {
   char val;
   mystream >> val;

   return val;
}

float FileReader::readFloat() {
   float val;
   mystream >> val;

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
   void writeChar(char);
   void endLine();
   void close();

private:
   ofstream mystream;
};

bool FileWriter::openFile(string fn) {
   if(mystream.is_open())
      mystream.close();

   mystream.open(fn.c_str());
   return mystream.is_open();
   
}

void FileWriter::writeString(string s) {
   mystream << s;
}

void FileWriter::writeInt(int val) {
   mystream << val;
}

void FileWriter::writeChar(char ch) {
   mystream << ch;
}

void FileWriter::endLine() {
   mystream << endl;
}

void FileWriter::close() {
   mystream.close();
}

class ProgramLogic {
public:
   void run(FileReader&, FileWriter&);

private:
  void init(FileReader&, FileWriter&); 
};

void ProgramLogic::run(FileReader& in, FileWriter& out) {
   init(in, out);
}


void ProgramLogic::init(FileReader& in, FileWriter& out) {
   int testcase;
   int i,j, k, val;
   Magicka m;
   string s;
   m.ccount=0;
   m.ocount=0;

   testcase = in.readInt();
   cout << testcase << endl;
   for(i=0;i<testcase;i++) {
      val = in.readInt();
      cout << val << "-";
      //reading combine
      for(k=0; k < val;k++) {
	 m.com[m.ccount][0] = in.readChar();
         m.com[m.ccount][1] = in.readChar();
	 m.com[m.ccount][2] = in.readChar();
	 m.com[m.ccount][3] = 0;
	 m.ccount++;
	 cout << m.com[k] << "-";
      }   
      val = in.readInt();
      cout << val << "-";
      //reading opose
      for(k=0; k < val;k++) {
	 m.op[m.ocount][0] = in.readChar();
         m.op[m.ocount][1] = in.readChar();
	 m.op[m.ocount][2] =0; 
	 m.ocount++;
	 cout << m.op[k] << "-";
      } 
      val = in.readInt();
      cout << val << "-";
      //reading base element
      for(k=0; k < val;k++) {
	 m.baseElem.push_back(in.readChar());
      } 
      cout << m.baseElem << endl;
      cout << "Output: " << m.start() << endl;

      //writting into output file
      out.writeString("Case #");
      out.writeInt(i+1);
      out.writeString(": [");
      for(k=0;k+1<m.finalList.length();k++) {
          out.writeChar(m.finalList[k]);
	  out.writeString(", ");
      }
      if(m.finalList.length() > 0)
         out.writeChar(m.finalList[k]);
      out.writeChar(']');
      out.endLine();

      //clear the Magic data
      m.baseElem.clear();
      m.finalList.clear();
      m.ccount=0;
      m.ocount=0;
   }
}

int main() {
  char choice;
  string filename;
  FileReader fr;
  FileWriter fw;
  ProgramLogic alg;
  
  do {
     cout << "\n\n\n1. Input File" << endl;
     cout << "2. Output File" << endl;
     cout << "3. Run" << endl;
     cout << "4. Exit" << endl;

     cout << "\nEnter Your Choice: ";
     cin >> choice;

     switch(choice) {
        case '1':
	   cout << "Enter the input file name: ";
	   cin.ignore();
	   getline(cin, filename);

	   if(!fr.openFile(filename))
	      cout<< "File opening error" << endl;
	   break;

	case '2':
	   cin.ignore();
           cout << "Enter the output file name: ";
	   getline(cin, filename);

	   if(!fw.openFile(filename))
	      cout<< "File opening error" << endl;
	   break;
	case '3':
	   alg.run(fr, fw);
	   fr.close();
	   fw.close();
	   break;

	case '4':
	   cout << "Exiting the program..." << endl;
	   break;
	default:
	   cout << "\n\nERROR: Invalid Choice!!!" << endl;
     }

  } while(choice != '4');

  return 0;
}
