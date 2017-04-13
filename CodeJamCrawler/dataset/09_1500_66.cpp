#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int L, D, N;
string words[5000];

void output(int test_case, int sol){
    printf("Case #%d: %d\n", test_case, sol);
    return;
}

int main(){

    //scanf("%d %d %d", &L, &D, &N);
    cin >> L >> D >> N;

    for(int i = 0; i < D; i++){
        //scanf("%s", &words[i]);
        cin >> words[i];
    }

    //for each pattern
    for(int i = 0; i < N; i++){
        string pattern;
        string letters[15];
        //scanf("%s", &pattern);
        cin >> pattern;


        /*debug*///cout << "Found pattern " << pattern << ", breaking it up\n" << flush;

        int pos = 0;
        for(int j = 0; j < L; j++){
            letters[j] = "";
            if(pattern[pos] == '('){
                pos ++;
                /*debug*///printf("Breaking letter %d (pos - %d)\n", j+1, pos); fflush(stdout);
                while(pattern[pos] != ')'){
                    /*debug*///printf("   Current position %d (%c)\n", pos, pattern[pos]); fflush(stdout);
                    letters[j] += pattern[pos];
                    pos ++;
                }
            } else{
                letters[j] += pattern[pos];
                /*debug*///printf("Adding letter %c to letters[%d]\n", letters[j][0], j); fflush(stdout);
            }
            pos ++;
            /*debug*///printf("Finished breaking letter %d\n", j+1); fflush(stdout);
        }

        /*debug*///printf("Running known words through, to find matches\n"); fflush(stdout);
        int count = 0;
        //for each word in words
        for(int j = 0; j < D; j++){
            string pos_word = words[j];
            //for each letter in word
            bool match = true;
            for(int k = 0; k < L; k++){
                bool match_letter = false;
                //for each "would be letter" in the pattern
                for(int l = 0; l < letters[k].size(); l++){
                    if(pos_word[k] == letters[k][l]){
                        match_letter = true;
                        break;
                    }
                }
                if(!match_letter){
                    match = false;
                    break;
                }
            }
            if(match){
                count ++;
            }
        }
        output(i+1, count);
    }


    fflush(stdout);

    return 0;
}
