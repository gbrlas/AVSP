#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main(){

    vector< vector<int> > rows;
    vector<int> row_1;
    vector<int> row_2;

    int QTD_CASE;
    int row_op;
    int num;
    int op = 0;
    int cont = 1;
    int pos;
    int i;
    int j;
    int k;
    vector<int> temp;

    scanf("%d",&QTD_CASE);

    while(QTD_CASE --){

        for(i=0;i<2;i++){
            scanf("%d",&row_op);

            for(j=0;j<4;j++){
                for(k=0;k<4;k++){
                    scanf("%d",&num);
                    temp.push_back(num);
                }
                rows.push_back(temp);
                temp.clear();
            }

            for(j=0;j<4;j++){
                if(i == 0) row_1.push_back(rows[row_op-1][j]);
                else if(i == 1) row_2.push_back(rows[row_op-1][j]);
            }

            for(j=0;j<4;j++){
                rows[j].clear();
            }
            rows.clear();
        }

//        for(i=0;i<4;i++){
//            printf("%d ",row_1[i]);
//        }
//        printf("\n");
//
//        for(i=0;i<4;i++){
//            printf("%d ",row_2[i]);
//        }
//        printf("\n");

        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(row_1[i] == row_2[j]){
                    pos = i;
                    op++;
                }
            }
        }
        if(op == 1){
            printf("Case #%d: %d\n",cont,row_1[pos]);
        }
        else if(op == 0){
            printf("Case #%d: Volunteer cheated!\n",cont);
        }
        else{
            printf("Case #%d: Bad magician!\n",cont);
        }

        cont++;
        row_1.clear();
        row_2.clear();
        for(i=0;i<4;i++){
            rows[i].clear();
        }
        rows.clear();
        op = 0;
    }

return 0;
}
