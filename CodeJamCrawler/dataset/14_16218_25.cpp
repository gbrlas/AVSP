#include "common.h"

const int NUM_OF_ARRANGEMENTS = 2;
const int NUM_OF_ROWS = 4;
const int NUM_OF_CARDS = 4;
const unsigned int ONE = 1;

int main(int argc, char** argv){
  string infilename;
  string outfilename;
  ifstream infile;
  ofstream outfile;
  get_file_names(outfilename, infilename, argc, argv);
  int T;
  infile.open(infilename.c_str());
  if(infile.is_open()){
    stringstream str;
    outfile.open(outfilename.c_str());
    file_read(str, infile);
    str>>T;
    for(int t = 0; t < T; t++){
      int ans[NUM_OF_ARRANGEMENTS];
      unsigned int bmap[NUM_OF_ARRANGEMENTS];
      for(int a = 0; a < NUM_OF_ARRANGEMENTS; a++){
        file_read(str, infile);
        str>>ans[a];
        ans[a]--;
        for(int r = 0; r < NUM_OF_ROWS; r++){
          file_read(str, infile);
          if(r == ans[a]){
            bmap[a] = 0;
            for(int c = 0; c < NUM_OF_CARDS; c++){
              int card;
              str>>card;
              bmap[a] |= ONE<<card;
//               cout<<"\n"<< std::setw(2) << std::setfill('0') << dec << card<<" - 0x"<< std::setw(20) << std::setfill('0') << hex <<bmap[a];
            }
//             cout<<"\n"<<"0x"<< std::setw(20) << std::setfill('0') << hex <<bmap[a];
          }
        }
      }
      unsigned int final_bmap = bmap[0];
      for(int i = 0; i < NUM_OF_ARRANGEMENTS; i++){
        final_bmap &= bmap[i];
      }
      int match = 0;
      int index;
//       cout<<"\n"<<"0x"<< std::setw(20) << std::setfill('0') << hex <<final_bmap<<"\n";
      for(int i = 1; i < NUM_OF_ROWS*NUM_OF_CARDS + 1; i++){
        final_bmap = final_bmap >> 1;
        if(final_bmap & ONE){
          match++;
          index = i;
        }
      }
      stringstream outstr;
      if(match == 0) outstr<<"Volunteer cheated!";
      else if(match == 1) outstr<<index;
      else outstr<<"Bad magician!";
      file_write(outfile, t+1, outstr.str());
    }
  }else{
    cout<<"\nT = "<<T;
    return 1;
  }
  return 0;
}
