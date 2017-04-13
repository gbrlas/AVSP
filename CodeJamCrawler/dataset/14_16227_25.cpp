#include "common.h"

int main(int argc, char** argv){
  initialize();
  if(infile.is_open()){
    stringstream str;
    file_read(str, infile);
    int T;
    str>>T;
    for(int t = 0; t < T; t++){
      double c,f,x;
      file_read(str, infile);
      str>>c>>f>>x;
      double current_count = 0;
      double current_rate = 2;
      double total_time = 0;
//       cout<<"\n\n"<<setw(15)<<setfill(' ')<<"CR"<<setw(15)<<setfill(' ')<<"TTF"<<setw(15)<<setfill(' ')<<"TTX"<<setw(15)<<setfill(' ')<<"TTFX";
      while(current_count < x){
        double ttf = c/current_rate;
        double ttx = (x - current_count)/current_rate;
        double ttfx = ttf + x/(current_rate + f);
//         cout<<"\n"<<setw(15)<<setfill(' ')<<setprecision(7)<<fixed<<current_rate<<setw(15)<<setfill(' ')<<setprecision(7)<<fixed<<ttf<<setw(15)<<setfill(' ')<<setprecision(7)<<fixed<<ttx<<setw(15)<<setfill(' ')<<setprecision(7)<<fixed<<ttfx;
        if((ttf < ttx) && (ttfx < ttx)){
          total_time += ttf;
          current_rate += f;
          current_count = 0;
        }else{
          total_time += ttx;
          current_rate += f;
          current_count = x;
        }
      }
      stringstream outstr;
      outstr<< fixed << setprecision(7) <<total_time;
      cout<<"\n"<<outstr.str();
      file_write(outfile, t+1, outstr.str());
    }
  }
  cout<<"\n";
  return 0;
}
