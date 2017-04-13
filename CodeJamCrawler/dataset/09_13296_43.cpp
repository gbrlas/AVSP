#include <stdio.h>
#include <string.h>
#define KNOWN_WORDS 25
#define KNOWN_LETTER 10
#define NUM_TESTCASE    10
#define BYTE_READ       1000

int main(int argc, char *argv[])
{
    FILE *fp;
    char filename[50];
    char str[BYTE_READ];

    int testCase = 1;
    int foundBracket = 0;
    int knownWords = 0;
    int bracketIndex = 0;
    int arrayIndex = -1;
    char known_words[KNOWN_WORDS][BYTE_READ];
    char known_letter[KNOWN_LETTER][BYTE_READ];
    char init_array[KNOWN_WORDS][BYTE_READ];
    int getInput = 0;
    int i = 0, x = 0;
    int input[3] = {0, 0, 0};
    char str_cmp[5];
    int k = 0;
    char tmp_array[KNOWN_WORDS][BYTE_READ];
    int tmpArraySize = 0, j= 0;
    int tmp = 0;
    int initArraySize = 0;

    strcpy(filename, argv[1]);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Cant open the file!!\n");
        return 0;
    }


    if (fgets(str,BYTE_READ, fp) != NULL) {
        k = 0;
        for (i=0; str[i] != '\0'; i++)
        {
            while (str[i] != ' ' && str[i] != '\r' && str[i] != '\n')
            {
                if (isdigit(str[i])) {
                str_cmp[k] = str[i];
                k++;
                }
                i++;
            }
            
            if (str[i] == ' ' ||  str[i] != '\r' || str[i] != '\n') {
                str_cmp[k] = '\0';
                input[x] = atoi(&str_cmp[0]);
                x++;
                k = 0;
            }
        }
    }

//j    printf("input[0] %d\ninput[1] %d\ninput[2] %d\n", 
  //          input[0], input[1], input[2]);

    if ( (input[1] > KNOWN_WORDS) || \
            (input[0] > KNOWN_LETTER) || \
            (input[2] > NUM_TESTCASE))
    {
        printf("Error in extracting\n");
        return 0;
    }


    for (knownWords = 0; knownWords < input[1]; knownWords++) {
        k = 0;
        if (fgets(str, BYTE_READ, fp) != NULL) {
            for (i = 0; str[i] != '\0'; i++)
            {
                if (str[i] >= 'a' && str[i] <= 'z')
                {
                    known_words[knownWords][k] = str[i];
                    k++;
                }
            }
            known_words[knownWords][k] = '\0';
        }
    }

    for (testCase = 1; testCase <= input[2]; testCase++) {
        foundBracket = 0;
        arrayIndex = -1;
        foundBracket = 0;
        bracketIndex = 0;

                for (i = 0; i < input[1]; i++)
                    strcpy(&init_array[i], &known_words[i]);

        if (fgets(str, BYTE_READ, fp) != NULL) {
//                printf("String %s", str);
            for (i = 0; str[i] != '\0'; i++) {
                if (foundBracket == 1) {
                    if (str[i] == ')') {
                        known_letter[arrayIndex][bracketIndex] = '\0';
                        foundBracket = 0;
                    } else {
                        known_letter[arrayIndex][bracketIndex] = str[i];
//                        printf("Inside Bracket %c arrayIndex %d bracketIndex %d\n", known_letter[arrayIndex][bracketIndex], arrayIndex, bracketIndex);
                        bracketIndex++;
                    }
                } else if (islower(str[i])) {
                    arrayIndex++;
                    known_letter[arrayIndex][0] = str[i];
                    //printf("lowercase letter %c arrayIndex %d\n", known_letter[arrayIndex][0], arrayIndex);
                    known_letter[arrayIndex][1] = '\0';
                } else if (str[i] == '(') {
                    foundBracket = 1;
                    bracketIndex = 0;
                    arrayIndex++;
                }
            }
        }

        arrayIndex++;
        initArraySize = input[1];
        for (tmp = 0; tmp < arrayIndex; tmp++)
        {
//            printf("INitArraySize %d\n", initArraySize);
            for (i = 0; i < BYTE_READ; i++)
            {
                if (known_letter[tmp][i] == '\0')
                    break;

                for (k = 0; k < initArraySize; k++)
                {
                    if (init_array[k][tmp] == '\0')
                        continue;


  //                  printf("Letter init_array[k] %s\n", init_array[k]);
                    if (known_letter[tmp][i] == init_array[k][tmp])
                    {
   //                     printf("match found %s\n", &init_array[k]);
                        strcpy(&tmp_array[tmpArraySize], init_array[k]);
                        tmpArraySize++;
                    }
                }

//                printf("1st Iteration\n");
            }

 //           printf("Iteration Complete %d\n", tmpArraySize);
            for (j = 0; j < tmpArraySize; j++)
                strcpy(&init_array[j], &tmp_array[j]);

            initArraySize = j;
            tmpArraySize = 0;
        }

        printf("Case #%d: %d\n", testCase, initArraySize);
    }

    return 1;
}



