#include<iostream>
using namespace std;
int main()
{
        int no_t,no_t_c=0,no_of_b=0,last_pos_o=1,last_pos_b=1,last_o_f=0,last_b_f=0,curr_pos_o,curr_pos_b,total_time,time_req,time_elapsed;
	cin >> no_t;
        //cout << no_t <<"\n";
	while(no_t_c < no_t)
	{
                no_of_b=0,total_time=-1,last_pos_o=1,last_pos_b=1,last_o_f=0,last_b_f=0;


		cin >> no_of_b;
                //cout << no_of_b <<" ";
                char rob; int butt, b_c=0;
		while(b_c < no_of_b)
		{

			cin >> rob;
                        //cout <<rob<<" ";
			cin >> butt;
                        //cout <<butt<<" ";
                        if(rob == 'O')
                            curr_pos_o=butt;
                        else
                            curr_pos_b=butt;
                        if(rob=='O' && total_time==-1){
                            time_req = curr_pos_o - last_pos_o;
                            if(time_req < 0)
                                time_req=time_req*-1;
                            total_time=time_req + 1;
                            last_pos_o=curr_pos_o;
                            last_o_f=total_time;
                        }
                        else if(rob=='B' && total_time==-1){
                            time_req=curr_pos_b - last_pos_b;
                            if(time_req < 0)
                                time_req=time_req*-1;
                            total_time=time_req + 1;
                            last_pos_b=curr_pos_b;
                            last_b_f=total_time;

                        }
                        else if(rob == 'O'){
                            time_req = curr_pos_o - last_pos_o;
                            if(time_req < 0)
                                time_req=time_req*-1;
                            time_elapsed=total_time - last_o_f;
                            if(time_req <= time_elapsed){
                                total_time ++;
                                //UPDATE ALL THE VARIABLE

                            }
                            else{
                                total_time+=time_req - time_elapsed +1;
                                //UPDATE ALL THE VARIABLE
                            }
                            last_pos_o=curr_pos_o;
                            last_o_f=total_time;
                        }
                        else if(rob == 'B'){
                            time_req = curr_pos_b - last_pos_b;
                            if(time_req < 0)
                                time_req=time_req*-1;
                            time_elapsed=total_time - last_b_f;
                            if(time_req <= time_elapsed){
                                total_time ++;
                                    //UPDATE ALL THE VARIABLE
                             }
                             else{
                                total_time+=time_req - time_elapsed +1;
                                    //UPDATE ALL THE VARIABLE
                            }

                             last_pos_b=curr_pos_b;
                             last_b_f=total_time;
                         }


			b_c++;
		}
                //cout << endl;
                cout<<"Case #"<<no_t_c+1<<": "<<total_time<<endl;
		no_t_c ++;
	}
	return 0;
}

