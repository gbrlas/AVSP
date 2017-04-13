#include<stdio.h>

main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int t;
    scanf("%d", &t);
    for( int j = 1; j <= t; j++){
        int n;
        scanf("%d", &n);
        int a;
        int *binary = new int[100];
        for( int i = 0; i< 100; i++)
            binary[i] = 0;
        int sum = 0;
        int min = 10000000;
        for ( int i = 0; i <n ; i++){
            scanf("%d", &a);
            if ( a <= min) min = a;
            sum = sum+ a;
            int count = 0;
            while(a != 0){
                int rem = a%2;
                if ( binary[count] == 1 && rem == 1)
                        binary[count] = 0;
                else if ( binary[count] == 0 && rem == 0)
                                    binary[count] = 0;
                        else    binary[count] = 1;

                a = a/2;
                count++;
            }
        }
        int flag = 0;
        for( int i = 0; i < 100; i++){
            if(binary[i] == 1){
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            printf ("%s%d%s", "Case #",j,": NO\n");
        else
            printf ("%s%d%s%d\n", "Case #",j,": ",(sum-min));
    }
}
