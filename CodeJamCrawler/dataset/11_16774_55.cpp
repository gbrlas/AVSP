#include <stdio.h>
#include <vector>
using std::vector;

int main(){
    FILE *f=fopen("input.txt","rt");
    FILE *out=fopen("output.txt","wt");

    int tests;
    fscanf(f,"%d",&tests);

    //tests=1;
    for(int tests_iter=0;tests_iter<tests;tests_iter++){
        int steps,res=0;
        fscanf(f,"%d",&steps);

        vector<int> orange,blue;

        bool *robots = new bool[steps];

        int blu_prev=1;
        int orn_prev=1;
        for(int steps_iter=0;steps_iter<steps;steps_iter++){
            char robot_id;
            int val;
            fscanf(f," %c %d",&robot_id,&val);
            if(robot_id == 'B')
                robots[steps_iter]=false,blue.push_back(val-blu_prev),blu_prev=val;
            else
                robots[steps_iter]=true,orange.push_back(val-orn_prev),orn_prev=val;
        }

        if(orange.empty())orange.push_back(0);
        if(blue.empty())blue.push_back(0);
        int orn_cur=0,blu_cur=0;
        for(int steps_iter=0;steps_iter<steps;steps_iter++){
            int orn_abs=orange[orn_cur],blu_abs=blue[blu_cur];
            if(orn_abs<0)orn_abs=-orn_abs;
            if(blu_abs<0)blu_abs=-blu_abs;
            if(robots[steps_iter]){
                if(blu_abs>orn_abs+1){
                    if(blue[blu_cur]<0)
                        blue[blu_cur]+=orn_abs+1;
                    else
                        blue[blu_cur]-=orn_abs+1;
                }else
                    blue[blu_cur]=0;
                res+=orn_abs+1;
                orn_cur+=1;
            }else{
                if(blu_abs<orn_abs){
                    if(orange[orn_cur]<0)
                        orange[orn_cur]+=blu_abs+1;
                    else
                        orange[orn_cur]-=blu_abs+1;
                }else
                    orange[orn_cur]=0;
                res+=blu_abs+1;
                blu_cur+=1;
            }
        }
        fprintf(out,"Case #%d: %d\n",tests_iter+1,res);

    }


    return 0;
}

