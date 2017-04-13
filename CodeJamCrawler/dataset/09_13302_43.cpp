#include <stdio.h>
#include <string.h>
#define BYTE_READ       5000
#define TMAP    100
#define WLIMIT  100
#define MAX_BASIN       26

typedef struct {
    int altitude;
    int id;
    int sinkId;
    int isLabel;
} Sdf_altitude;

int main(int argc, char *argv[])
{
    FILE *fp;
    char filename[50];
    char str[BYTE_READ];
    int numberOfMap = 0;
    int height = 1;
    int width = 1;
    int i = 0;
    int j = 0;
    int k = 0;
    int tmpK = 0;

    strcpy(filename, argv[1]);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Cant open the file!!\n");
        return 0;
    }

    fscanf(fp, "%d", &numberOfMap);

    for (tmpK = 0; tmpK < numberOfMap; tmpK++)
    {
        fscanf(fp, "%d %d", &height, &width);

//        printf("NumberOfMap %d\nHeight %d\nWidth %d\n", numberOfMap, height, width);

        Sdf_altitude altitude[height][width];
        int counter = 1;
        int minValue = 0;
        int label = 97;


        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
            {
                if (fscanf(fp, "%d", &altitude[i][j].altitude))
                {
                     //printf("%d\t", altitude[i][j].altitude);
                    altitude[i][j].sinkId = 0;
                    altitude[i][j].id = counter++;
                    //  printf("%d\n", altitude[i][j].id );
                    altitude[i][j].isLabel = 0;
                }
            }
             //printf("\n");
        }
        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
            {
                 if ((i > 0) && (altitude[i - 1][j].altitude < altitude[i][j].altitude)) {
                     // printf("MinValue i - 1\n");
                     minValue = altitude[i - 1][j].altitude;
                     altitude[i][j].sinkId = altitude[i - 1][j].id;
                     altitude[i][j].isLabel = 1;
                 } else {
                     // printf("Same i - 1\n");
                     minValue = altitude[i][j].altitude;
                 }

                 if ((j > 0) && (altitude[i][j - 1].altitude < minValue)) {
                     // printf("MinValue j - 1\n");
                     minValue = altitude[i][j - 1].altitude;
                     altitude[i][j].sinkId = altitude[i][j - 1].id;
                     altitude[i][j].isLabel = 1;
                 }

                 if ((j+1 < width) && (altitude[i][j + 1].altitude < minValue)) {
                     // // printf("MinValue j + 1\n");
                     minValue = altitude[i][j + 1].altitude;
                     altitude[i][j].sinkId = altitude[i][j + 1].id;
                     altitude[i][j].isLabel = 1;
                 }

                 if ((i+1 < height) && (altitude[i + 1][j].altitude < minValue)) {
                     // printf("MinValue i+1\n");
                     minValue = altitude[i+1][j].altitude;
                     altitude[i][j].sinkId = altitude[i+1][j].id;
                     altitude[i][j].isLabel = 1;
                 }
                  //printf("%d\t", altitude[i][j].sinkId);
            }
           //printf("Sagar\n");
        }
                printf("Case #%d:\n", tmpK + 1);
        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
            {
                int val = 0, tmpI = 0, tmpJ = 0;
                int sinkId;
                val = altitude[i][j].sinkId;

                if (val != 0)
                {
                    while  (val != 0)  
                    {
              //printf("Val %d\n", val);
                        tmpI = 0;
                        tmpJ = 0;
                        if (val <= width)
                        {
                            //printf("Came here\n");
                            tmpI = 0;
                            tmpJ = val - 1;
                        } else {
                            for (k = 1; k <= width; )
                            {
                                if (val > width * k) {
                                                                //printf("incrementing tmpI\n");
                                    tmpI++;
                                    val = val - width;
                                }
                                if (val <= width) {
                                    tmpJ = val - 1;
                                    break;
                                }
                            }
                        }
                            //printf("Val %d tmpI %d tmpJ %d\n", val, tmpI, tmpJ);
                        val = altitude[tmpI][tmpJ].sinkId;
                    }
                     //printf(" Val %d tmpI %d tmpJ %d\n", val, tmpI, tmpJ);

                    if (altitude[tmpI][tmpJ].isLabel == 0) {
                        altitude[tmpI][tmpJ].isLabel = label++;
                    }
                    altitude[i][j].isLabel = altitude[tmpI][tmpJ].isLabel;
                    printf("%c ", altitude[i][j].isLabel);
                } else {
                    if (altitude[i][j].isLabel == 0) {
                        altitude[i][j].isLabel = label++;
                    }
                        printf("%c ", altitude[i][j].isLabel);
                }
            }
            printf("\n");
        }
    }
    fclose(fp);
    return 1;
}



