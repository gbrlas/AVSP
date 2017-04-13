#include <stdio.h>
#include <string.h>
#include <list>
using std::list;

struct oppos{
    char with;
    char res;
    oppos(){with=res=0;}
};

int main(){
    FILE *f=fopen("input.txt","rt");
    FILE *out=fopen("output.txt","wt");

    int tests=1;
    fscanf(f,"%d",&tests);

    //tests=1;
    char opposes[256];
    for(int tests_iter=0;tests_iter<tests;tests_iter++){
        memset(opposes, 0, 256*sizeof(char));
        oppos combines[256];

        int combines_count;
        fscanf(f,"%d ",&combines_count);

        char first,second,third;
        for(int combines_iter=0;combines_iter<combines_count;combines_iter++){
            fscanf(f,"%c%c%c ",&first,&second,&third);
            combines[int(first)].res=third,combines[int(first)].with=second;
            combines[int(second)].res=third,combines[int(second)].with=first;
        }

        int opposes_count;
        fscanf(f,"%d ",&opposes_count);

        for(int opposes_iter=0;opposes_iter<opposes_count;opposes_iter++){
            fscanf(f,"%c%c ",&first,&second);
            opposes[first]=second,opposes[second]=first;
        }

        int sequence_length;
        fscanf(f,"%d ",&sequence_length);

        //list<char> res;
        char* res=new char[sequence_length];
        memset(res, 0, sequence_length*sizeof(char));

        int cur_pos=0;
        for(int i=0;i<sequence_length;i++){
            fscanf(f,"%c",&first);
            if(!cur_pos){
                res[cur_pos]=first;
                cur_pos=1;
                continue;
            }
            if(combines[int(first)].with==res[cur_pos-1])
                res[cur_pos-1]=combines[int(first)].res;
            else {
                int opp_num=0;
                char opp_char=opposes[int(first)];
                for(;opp_num<cur_pos&&opp_char!=res[opp_num];opp_num++);
                if(opp_num<cur_pos){
                    memset(res, 0, cur_pos*sizeof(char));
                    cur_pos=0;
                }else
                    res[cur_pos++]=first;
            }
        }

        fprintf(out,"Case #%d: [",tests_iter+1);
        for(int i=0;i<cur_pos-1;i++)
            fprintf(out,"%c, ",res[i]);
        if(cur_pos)
            fprintf(out,"%c]\n",res[cur_pos-1]);
        else
            fprintf(out,"]\n");

        delete[]res;

    }
    return 0;
}
