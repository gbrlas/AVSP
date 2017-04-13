//
//  main.cpp
//  ticTacToeTomek
//
//  Created by Mikhak Misaghian on 4/12/13.
//  Copyright (c) 2013 Mikhak Misaghian. All rights reserved.
//

#include <iostream>

using namespace std;
bool checkDiagonal(int caseNum, char b[4][4], int dotCount, int &xWin, int &oWin, int &T, bool &win);
bool checkReverseDiagonal(int caseNum, char b[4][4], int dotCount, int &xWin, int &oWin, int &T, bool &win);
bool checkRow(int caseNum, char b[4][4], int dotCount, int &xWin, int &oWin, int &T, bool &win, int &allCheckedRow, int &allCheckedCol);
bool checkColumn(int caseNum, char b[4][4], int dotCount, int &xWin, int &oWin, int &T, bool &win, int &allCheckedRow, int &allCheckedCol);
//void checkStatus(int caseNum, char b[4][4], int dotCount);
bool hasResult(int xWin, int oWin, int T, int dotCount, bool win, int allCheckedRow, int allCheckedCol);
void printResult(int xWin, int oWin, int T, int dotCount, bool win, int tNum, int allCheckedRow, int allCheckedCol);
int main()
{
    int allCheckedRow=0;
    int allCheckedCol=0;
    int xWin=0;
    int oWin=0;
    int T=0;
    //int dotCount;
    bool win=false;
    //int tNum=0;
    int testCases=0;
    char board[4][4];
    char ch;
    int dotCount;
    //initializing the board.
    for (int i=0; i<4; i++) {
        for(int j=0; j<4; j++){
            board[i][j]=' ';
        }
    }
    int t=0;
    cin>>testCases; //get the number of test cases
    getchar();
    //cout<<testCases<<endl;
    while (t!=testCases) {
        dotCount=0;
        //cout<<"hello\n";
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                board[i][j]=getchar();
                //cout<<board[i][j];
                if (board[i][j]=='.') {
                    dotCount++;
                }
            }
            //cout<<endl;
            ch=getchar();
            //cout<<ch;
        }
        t++;
//        cin.getline(ch);
        cin.get();//get the empty line
//        checkDiagonal(t, board, dotCount, xWin, oWin, T, win);
//        checkReverseDiagonal(t, board, dotCount, xWin, oWin, T, win);
//        checkRow(t, board, dotCount, xWin, oWin, T, win);
//        checkColumn(t, board, dotCount, xWin, oWin, T, win);
        if (checkDiagonal(t, board, dotCount, xWin, oWin, T, win)==true) {
            //cout<<"1"<<endl;
            printResult(xWin, oWin, T, dotCount, win, t, allCheckedRow, allCheckedCol);
        }else if (checkReverseDiagonal(t, board, dotCount, xWin, oWin, T, win)==true){
            //cout<<"2"<<endl;
            printResult(xWin, oWin, T, dotCount, win, t, allCheckedRow, allCheckedCol);
        }else if (checkRow(t, board, dotCount, xWin, oWin, T, win, allCheckedRow, allCheckedCol)==true){
            //cout<<"3"<<endl;
            printResult(xWin, oWin, T, dotCount, win, t, allCheckedRow, allCheckedCol);
        }else if (checkColumn(t, board, dotCount, xWin, oWin, T, win,allCheckedRow, allCheckedCol)==true){
            //cout<<"4"<<endl;
            printResult(xWin, oWin, T, dotCount, win, t, allCheckedRow, allCheckedCol);
        }
        
        //check if Draw
        else if (win==false && dotCount==0 && allCheckedRow==16 && allCheckedCol==16) {
            cout<<"Case #"<<t<<": "<<"Draw"<<endl;
        }
        //check if game is not completed yet
        else if (win==false && dotCount>0 && allCheckedRow==16 && allCheckedCol==16) {
            cout<<"Case #"<<t<<": "<<"Game has not completed"<<endl;
        }
//        checkDiagonal(t, board, dotCount);
//        if (checkDiagonal(t, board, dotCount)!=true) {
//            checkReverseDiagonal(t, board, dotCount);
//            if (checkReverseDiagonal(t, board, dotCount)!=true) {
//                checkRow(t, board, dotCount);
//                if (checkRow(t, board, dotCount)!=true) {
//                    checkColumn(t, board, dotCount);
//                }
//            }
//        }
//        for (int i=0; i<4; i++) {
//            for (int j=0; j<4; j++) {
//                cout<<board[i][j];
//            }
//            cout<<endl;
//        }
        //checkStatus(t, board, dotCount);
    }
    return 0;
}

//void checkStatus(int tNum, char b[4][4], int dotCount){
//    //int k=0;
//    bool done=false;
//    bool win=false;
//    int xWin=0;
//    int oWin=0;
//    int T=0;
//    //int dotCount=0;
//    //bool Draw=false;
//    //bool notCompletedYet=false;
////    for (int i=0; i<4; i++) {
////        for (int j=0; j<4; j++) {
////            cout<<b[i][j];
////            if (b[i][j]=='.') {
////                dotCount++;//get number of dots
////            }
////        }
////        cout<<endl;
////    }
//    
//    //check rows
//    for (int i=0; i<4; i++) {
//        //done=false;
//        win=false;
//        xWin=0;
//        oWin=0;
//        T=0;
//        //k++;
//        if(done==false){
//        for (int j=0; j<4; j++) {
//            if (b[i][j]=='X') {
//                xWin++;
//                //cout<<"xwin: "<<xWin<<endl;
//            }else if(b[i][j]=='O'){
//                oWin++;
//                //cout<<"owin: "<<oWin<<endl;
//            }else if(b[i][j]=='T'){
//                T++;
//                //cout<<"T: "<<T<<endl;
//            }
////            else if(b[i][j]=='.'){
////                dotCount++;
////                //cout<<"dotCount: "<<endl;
////            }
//        }
////
////        cout<<"xWin: "<<xWin<<endl;
////        cout<<"oWin: "<<oWin<<endl;
////        cout<<"T: "<<T<<endl;
////        cout<<"dotCount: "<<dotCount<<endl;
//        
//        if (xWin==4 || oWin==4 || (xWin==3 && T==1) || (oWin==3 && T==1)) {
//            win=true;
//        }
//        if (hasResult(xWin, oWin, T, dotCount, win)) {
//            done=true;
//            printResult(xWin, oWin, T, dotCount, win, tNum);
//            return;
//        }}
////        done=false;
////        win=false;
////        xWin=0;
////        oWin=0;
////        T=0;
//        //dotCount=0;
//    }//end of checking rows
////    if (hasResult(xWin, oWin, T, dotCount, win)) {
////        done=true;
////        printResult(xWin, oWin, T, dotCount, win, tNum);
////    }
////    else{
//    
//    
//    //check columns
//    //initializing back the variables
//    cout<<"check column"<<endl;
//    if (done==false) {
//        //int k=0;
//        cout<<"check column"<<endl;
////        bool win=false;
////        int xWin=0;
////        int oWin=0;
////        int T=0;
//        //int dotCount=0;
//        
//        for (int j=0; j<4; j++) {
//            done=false;
//            win=false;
//            xWin=0;
//            oWin=0;
//            T=0;
//            //k++;
//            for (int i=0; i<4; i++) {
//                if (b[i][j]=='X') {
//                    xWin++;
//                }else if (b[i][j]=='O') {
//                    oWin++;
//                }else if(b[i][j]=='T'){
//                    T++;
//                }
////                else if(b[i][j]=='.'){
////                    dotCount++;
////                }
////    cout<<"xWin: "<<xWin<<endl;
////    cout<<"oWin: "<<oWin<<endl;
////    cout<<"T: "<<T<<endl;
////    cout<<"dotCount: "<<dotCount<<endl;
//            }
//            if (xWin==4 || oWin==4 || (xWin==3 && T==1) || (oWin==3 && T==1)) {
//                win=true;
//            }
//            if (hasResult(xWin, oWin, T, dotCount, win)) {
//                done=true;
//                printResult(xWin, oWin, T, dotCount, win, tNum);
//                return;
//            }
////            done=false;
////            win=false;
////            xWin=0;
////            oWin=0;
////            T=0;
//            //dotCount=0;
//        }       
//    }//end of checking columns
//
////    if (hasResult(xWin, oWin, T, dotCount, win)) {
////        done=true;
////        printResult(xWin, oWin, T, dotCount, win, tNum);
////    }else{
//    
//    
//    
//    //check diagonals
//    //initializing back the variables
//
//    if (done==false) {
//        bool win=false;
//        int xWin=0;
//        int oWin=0;
//        int T=0;
//        //int dotCount=0;
//        
//        for (int i=0; i<4; i++) {
//            if (b[i][i]=='X') {
//                xWin++;
//            }else if(b[i][i]=='O'){
//                oWin++;
//            }else if (b[i][i]=='T'){
//                T++;
//            }
////            else if (b[i][i]=='.')
////            {
////                dotCount++;
////            }
//        }
//    }
//    if (xWin==4 || oWin==4 || (xWin==3 && T==1) || (oWin==3 && T==1)) {
//        win=true;
//    }
//    if (hasResult(xWin, oWin, T, dotCount, win)) {
//        done=true;
//        printResult(xWin, oWin, T, dotCount, win, tNum);
//        return;
//    }else{
//
//    
//    //initializing back the variables
//    if (done==false) {
//        bool win=false;
//        int xWin=0;
//        int oWin=0;
//        int T=0;
//        //int dotCount=0;
//        
//        for (int i=3; i<=0; i--) {
//            if (b[i][i]=='X') {
//                xWin++;
//            }else if(b[i][i]=='O'){
//                oWin++;
//            }else if (b[i][i]=='T'){
//                T++;
//            }
////            else if (b[i][i]=='.')
////            {
////                dotCount++;
////            }
//        }
//    }
//        if (xWin==4 || oWin==4 || (xWin==3 && T==1) || (oWin==3 && T==1)) {
//            win=true;
//        }
//    if (hasResult(xWin, oWin, T, dotCount, win)) {
//        done=true;
//        printResult(xWin, oWin, T, dotCount, win, tNum);
//    }
// //end of diagonal else
//    }//end of diagonal reverse else
//    //}//end of check columns else
//    //}//end of check rows else
//
//}//end of checkStatus


////////////////////  CHECK Diagonal  ////////////////////////
bool checkDiagonal(int caseNum, char b[4][4], int dotCount, int &xWin, int &oWin, int &T, bool &win){
    bool done=false;
    win=false;
    xWin=0;
    oWin=0;
    T=0;
    //int dotCount=0;
    
    for (int i=0; i<4; i++) {
        if (b[i][i]=='X') {
            xWin++;
        }else if(b[i][i]=='O'){
            oWin++;
        }else if (b[i][i]=='T'){
            T++;
        }
    }

    if (xWin==4 || oWin==4 || (xWin==3 && T==1) || (oWin==3 && T==1)) {
        win=true;
        done=true;
    }
//    if (hasResult(xWin, oWin, T, dotCount, win)) {
//        done=true;
//        //printResult(xWin, oWin, T, dotCount, win, caseNum);
//    //return;
//    }
    return done;
}
///////////////////////////////////////////


////////////////////  CHECK ReverseDiagonal  ////////////////////////
bool checkReverseDiagonal(int caseNum, char b[4][4], int dotCount, int &xWin, int &oWin, int &T, bool &win){
    bool done=false;
        win=false;
        xWin=0;
        oWin=0;
        T=0;
 
    //cout<<b[3][0]<<endl;
    //cout<<"hello"<<endl;
    if (b[3][0]=='X') {
        xWin++;
    }else if (b[3][0]=='O'){
        oWin++;
    }
    else if (b[3][0]=='T'){
        T++;
    }
    
    if (b[2][1]=='X') {
        xWin++;
    }else if (b[2][1]=='O'){
        oWin++;
    }
    else if (b[2][1]=='T'){
        T++;
    }
    
    if (b[1][2]=='X') {
        xWin++;
    }else if (b[1][2]=='O'){
        oWin++;
    }
    else if (b[1][2]=='T'){
        T++;
    }
    
    if (b[0][3]=='X') {
        xWin++;
    }else if (b[0][3]=='O'){
        oWin++;
    }
    else if (b[0][3]=='T'){
        T++;
    }
    
    
//    for (int i=3; i<=0; i--) {
//        cout<<"why"<<endl;
//        cout<<b[i][3-i]<<endl;
//        //for (int j=(3-i); j<=(3-i); j++) {
//            if (b[i][3-i]=='X') {
//                xWin++;
//            }else if(b[i][3-i]=='O'){
//                oWin++;
//            }else if (b[i][3-i]=='T'){
//                T++;
//            }
//        //}
//    }
    //cout<<"bye"<<endl;
//    cout<<"xwin: " <<xWin<<endl;
//    cout<<"owin: " <<oWin<<endl;
//    cout<<"win: " <<win<<endl;
//    cout<<"T: " <<T<<endl;
    if (xWin==4 || oWin==4 || (xWin==3 && T==1) || (oWin==3 && T==1)) {
        win=true;
        done=true;
    }
//    if (hasResult(xWin, oWin, T, dotCount, win)) {
//        done=true;
//        //printResult(xWin, oWin, T, dotCount, win, caseNum);
//    }
    return done;
}
///////////////////////////////////////////


////////////////////  CHECK ROW  ////////////////////////
bool checkRow(int caseNum, char b[4][4], int dotCount, int &xWin, int &oWin, int &T, bool &win, int &allCheckedRow, int &allCheckedCol){
    //cout<<"checkRow"<<endl;
    bool done=false;
    win=false;
    xWin=0;
    oWin=0;
    T=0;
    allCheckedRow=0;
//    allCheckedCol=0;
    
    //check rows
    for (int i=0; i<4; i++) {
        if(done==false){

        //done=false;
        win=false;
        xWin=0;
        oWin=0;
        T=0;
        //k++;
            for (int j=0; j<4; j++) {
                allCheckedRow++;
                if (b[i][j]=='X') {
                    xWin++;
                }else if(b[i][j]=='O'){
                    oWin++;
                }else if(b[i][j]=='T'){
                    T++;
                }
            }
            
            if (xWin==4 || oWin==4 || (xWin==3 && T==1) || (oWin==3 && T==1)) {
                win=true;
            }
            if (hasResult(xWin, oWin, T, dotCount, win, allCheckedRow, allCheckedCol)==true) {
                done=true;
                //printResult(xWin, oWin, T, dotCount, win, caseNum);
                //return done;
            }}

    }//end of checking rows
    return done;
}
///////////////////////////////////////////


////////////////////  CHECK COLUMN  ////////////////////////
bool checkColumn(int caseNum, char b[4][4], int dotCount, int &xWin, int &oWin, int &T, bool &win, int &allCheckedRow, int &allCheckedCol){
    bool done=false;
    win=false;
    xWin=0;
    oWin=0;
    T=0;
//    allCheckedRow=0;
    allCheckedCol=0;
    //check columns
    //initializing back the variables
    //cout<<"check column"<<endl;

        for (int j=0; j<4; j++) {
            //done=false;
            //cout<<"hello"<<endl;
            if (done==false) {
            win=false;
            xWin=0;
            oWin=0;
            T=0;
            //k++;
        
            for (int i=0; i<4; i++) {
                allCheckedCol++;
                if (b[i][j]=='X') {
                    xWin++;
                }else if (b[i][j]=='O') {
                    oWin++;
                }else if(b[i][j]=='T'){
                    T++;
                }
            }
            if (xWin==4 || oWin==4 || (xWin==3 && T==1) || (oWin==3 && T==1)) {
                win=true;
            }
            if (hasResult(xWin, oWin, T, dotCount, win, allCheckedRow, allCheckedCol)==true) {
                done=true;
                //printResult(xWin, oWin, T, dotCount, win, caseNum);
//                return;
            }
        }       
    }//end of checking columns
    return done;
}

///////////////////////////////////////////

bool hasResult(int xWin, int oWin, int T, int dotCount, bool win, int allCheckedRow, int allCheckedCol){
    if (xWin==4 || oWin==4 || (xWin==3 && T==1) || (oWin==3 && T==1)) {
        // || (win==false && dotCount==0 && allCheckedRow==16 && allCheckedCol==16) || (win==false && dotCount>0 && allCheckedRow==16 && allCheckedCol==16)
        //printResult(xWin, oWin, T, dotCount, win, tNum);
        return true;
    }else{
        return false;
    }
}
void printResult(int xWin, int oWin, int T, int dotCount, bool win, int tNum, int allCheckedRow, int allCheckedCol){
//    cout<<"xWin: "<<xWin<<endl;
//    cout<<"oWin: "<<oWin<<endl;
//    cout<<"T: "<<T<<endl;
//    cout<<"dotCount: "<<dotCount<<endl;
//    if (win==true) {
//        cout<<"win is true"<<endl;
//    }else if (win==false){
//        cout<<"win is false"<<endl;
//    }
    //printing the result
    if (xWin==4) {
        //win=true;
        cout<<"Case #"<<tNum<<": "<<"X won"<<endl;
    }
    else if (xWin==3 && T==1) {
        //win=true;
        cout<<"Case #"<<tNum<<": "<<"X won"<<endl;
    }
    else if(oWin==4) {
        //win=true;
        cout<<"Case #"<<tNum<<": "<<"O won"<<endl;
    }
    else if (oWin==3 && T==1) {
        //win=true;
        cout<<"Case #"<<tNum<<": "<<"O won"<<endl;
    }
    
    
//    //check if Draw
//    if (win==false && dotCount==0 && allCheckedRow==16 && allCheckedCol==16) {
//        cout<<"Case #"<<tNum<<": "<<"Draw"<<endl;
//    }
//    //check if game is not completed yet
//    if (win==false && dotCount>0 && allCheckedRow==16 && allCheckedCol==16) {
//        cout<<"Case #"<<tNum<<": "<<"Game has not completed"<<endl;
//    }
}


