#include <stdio.h>

#define ON  1
#define OFF 0

struct _dev{
    unsigned char   state;
    unsigned char   power;
};

int main(){
    unsigned int    total_cases;
    unsigned int    t_dev=0, t_snap=0;
    unsigned int    i=0;
    unsigned int    j=0;
    unsigned int    snap=0;
    int             index=0;
    
    struct  _dev    *devices=NULL;
    unsigned char   *results=NULL;

    scanf("%d", &total_cases);

    results = (unsigned char*)malloc(total_cases+1);

    for (i=0; i< total_cases; i++){
        scanf("%d %d", &t_dev, &t_snap);

        devices = (struct _dev *)malloc(sizeof(struct _dev) * t_dev+1);

        memset(devices, 0x00, sizeof(struct _dev) * t_dev); 

        devices[0].power = ON;


        for(snap=0;snap<t_snap;snap++){

            for (index=0;index < t_dev;index++){


                if (devices[index].power)
                    devices[index].state = !devices[index].state;

                if (index-1 >= 0)
                    if (devices[index-1].power && devices[index-1].state)
                        devices[index].power = ON;
                    else
                        devices[index].power = OFF;


            }

/*            index=0;
            while(index < t_dev){
                if (index+1 < t_dev)
                    if (devices[index].power && devices[index].state)
                        devices[index+1].power = ON;
                    else
                        devices[index+1].power = OFF;
                index++;
            }*/

        }

        if (devices[t_dev-1].state && devices[t_dev-1].power)
            results[i] = ON;
        else
            results[i] = OFF;

//        for (index=0; index<t_dev; index++)
//            printf("%d %d - ", devices[index].power, devices[index].state);
//        printf("\n");

        free(devices);
    }
    for (index=0;index<total_cases; index++)
        printf("Case #%d: %s\n", index+1, results[index] ? "ON" : "OFF");
}
