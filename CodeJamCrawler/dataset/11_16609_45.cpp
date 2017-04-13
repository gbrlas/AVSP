#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;


class RobotJobDesc {
public:
   int currPos;
   int targetPos;
   int sequence;
};

class InputReader {
public:
   InputReader() {}
   bool openFile(string);
   int readInt();
   string readString();
   long readLong();
   char readChar();
   float readFloat();

   void close();
   ~InputReader(){}

private:
   ifstream mystream;
};

bool InputReader::openFile(string fn) {
   if(mystream.is_open())
      mystream.close();

   mystream.open(fn.c_str());
   return mystream.is_open();
   
}

int InputReader::readInt() {
   int value;
   mystream >> value;

   return value;
}

string InputReader::readString() {
   string value;
   getline(mystream, value);

   return value;
}

long InputReader::readLong() {
   long value;
   mystream >> value;

   return value;
}

char InputReader::readChar() {
   char value;
   mystream >> value;

   return value;
}

float InputReader::readFloat() {
   float value;
   mystream >> value;

   return value;
}

void InputReader::close() {
   mystream.close();
}

class OutputWriter {
public:
   bool openFile(string fn);
   void writeString(string);
   void writeInt(int);
   void endLine();
   void close();

private:
   ofstream mystream;
};

bool OutputWriter::openFile(string fn) {
   if(mystream.is_open())
      mystream.close();

   mystream.open(fn.c_str());
   return mystream.is_open();
   
}

void OutputWriter::writeString(string s) {
   mystream << s;
}

void OutputWriter::writeInt(int value) {
   mystream << value;
}

void OutputWriter::endLine() {
   mystream << endl;
}

void OutputWriter::close() {
   mystream.close();
}

class ProgramLogic {
public:
   void run(InputReader&, OutputWriter&);
   int calculateTime(RobotJobDesc*, RobotJobDesc*, int,int);

private:
  void init(InputReader&, OutputWriter&); 
};

void ProgramLogic::run(InputReader& in, OutputWriter& out) {
   init(in, out);
}

int ProgramLogic::calculateTime(RobotJobDesc *O, RobotJobDesc *B, int oc, int bc) {
   int time=0;
   int ii=0,jj=0;
   int seq=1;
   bool pushedButton;
   bool bpushed=false;
   bool opushed = false;
   while(ii < oc && jj < bc) {
      pushedButton = false;
      //check O robot move
      opushed = false;
     if(O[ii].currPos < O[ii].targetPos)
	O[ii].currPos = O[ii].currPos + 1; 
     else if(O[ii].currPos > O[ii].targetPos)
       O[ii].currPos = O[ii].currPos - 1;
     else if(O[ii].sequence == seq) {
         ii++;
	 time++;
	 seq++;
	 pushedButton = true;
	 opushed = true;
     } 

     //check B robot move
     bpushed = false;
     if(B[jj].currPos < B[jj].targetPos)
	B[jj].currPos = B[jj].currPos + 1; 
     else if(B[jj].currPos > B[jj].targetPos)
       B[jj].currPos = B[jj].currPos - 1;
     else if(B[jj].sequence == seq) {
         jj++;
	 time++;
	 seq++;
	 pushedButton = true;
	 bpushed = true;
	 if(O[ii].currPos < O[ii].targetPos && opushed)
	   O[ii].currPos = O[ii].currPos + 1; 
     	else if(O[ii].currPos > O[ii].targetPos && opushed)
           O[ii].currPos = O[ii].currPos - 1;  
     } 
     if(!pushedButton)
        time++;
   }

   // O robot remaining move if any
   while (ii < oc) {
      if(O[ii].currPos < O[ii].targetPos)
	O[ii].currPos = O[ii].currPos + 1; 
     else if(O[ii].currPos > O[ii].targetPos)
       O[ii].currPos = O[ii].currPos - 1;
     else if(O[ii].sequence == seq) {
         ii++;
	 time++;
	 seq++;
	 continue;
     } 
     time++;
   }

   //B robot remaining move if any
   while(jj < bc) {
      if(B[jj].currPos < B[jj].targetPos)
	B[jj].currPos = B[jj].currPos + 1; 
     else if(B[jj].currPos > B[jj].targetPos)
       B[jj].currPos = B[jj].currPos - 1;
     else if(B[jj].sequence == seq) {
         jj++;
	 time++;
	 seq++;
	 continue;
     } 
     time++;
   }

   return time;
}

void ProgramLogic::init(InputReader& in, OutputWriter& out) {
   int testcase;
   int ii,jj;
   int button;
   string output;
   int result;
   RobotJobDesc Orobot[100], Brobot[100];
   int Ocount,Bcount;

   testcase = in.readInt();
   for(ii=0;ii<testcase;ii++) {
       button=in.readInt();
       Ocount=0;
       Bcount=0;
       for(jj=0;jj<button;jj++) {
	   char ch;
	   int value;
	   ch = in.readChar();
	   value=in.readInt();
	   if(ch == 'O') {
	      Orobot[Ocount].currPos = (Ocount?Orobot[Ocount-1].targetPos:1);
	      Orobot[Ocount].targetPos=value;
	      Orobot[Ocount].sequence = jj+1;
	      Ocount++;
           }
	   else {
	      Brobot[Bcount].currPos = (Bcount?Brobot[Bcount-1].targetPos:1);
	      Brobot[Bcount].targetPos=value;
	      Brobot[Bcount].sequence = jj+1;
	      Bcount++;
	   }
       }
       result =  calculateTime(Orobot, Brobot, Ocount, Bcount);
       output.clear();
       out.writeString("Case #");
       out.writeInt(ii+1);
       out.writeString(": ");
       out.writeInt(result);
       out.endLine();
   }
}

int main() {
  char choice;
  string filename;
  InputReader fr;
  OutputWriter fw;
  ProgramLogic alg;
  
  do {
     cout << "1. Input File" << endl;
     cout << "2. Output File" << endl;
     cout << "3. Run" << endl;
     cout << "4. Exit" << endl;

     cout << "Enter Your Choice: ";
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
	   cout << "ERROR: Invalid Choice!!!" << endl;
     }

  } while(choice != '4');

  return 0;
}
