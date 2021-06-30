#include <iostream>
#include <cmath>
using namespace std;
 
bool ok(int q[], int c) {
    for (int i = 0; i < c; ++i)
        if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
            return false;
        return true;
}

void print(int q[]) {
    static int solution = 0;
    int i, j, k, l;
    typedef char box[5][7]; 
    box bb, wb, *board[8][8];

    char black = ' ';
    char white = char(219);
    for (i=0; i<5; i++) {
        for (j=0; j<7; j++) {
            bb[i][j] = black;
            wb[i][j] = white;
        }
    }


static box bq = { {white, white, white, white, white, white, white},
                      {white, black, white, black, white, black, white},
                      {white, black, black, black, black, black, white},
                      {white, black, black, black, black, black, white},
                      {white, white, white, white, white, white, white} };
 
    static box wq = { {black, black, black, black, black, black, black},
                      {black, white, black, white, black, white, black},
                      {black, white, white, white, white, white, black},
                      {black, white, white, white, white, white, black},
                      {black, black, black, black, black, black, black} };

    for(i=0; i<8; i++)
        for(j=0; j<8; j++)
            if((i+j)%2 == 0)
             board[i][j] = &wb;
            else
board[i][j] = &bb;

    for(i=0; i<8; i++)
        if((i+q[i])%2 == 0)
            board[q[i]][i] = &bq;
        else
        board[q[i]][i] = &wq;

cout << "Solution #" << ++solution << ":\t ";
    for(i=0; i<8; i++) cout << q[i] << " ";
    cout << endl;
    
    
    
  cout << " ";
    for (i=0; i<7*8; i++) cout << '_';
    cout << endl;

    for (i=0; i<8; i++) {  
        for (k=0; k<5; k++) {  
            cout << char(179); 
            for (j=0; j<8; j++) { 
                for (l=0; l<7; l++)
                cout << (*board[i][j])[k][l];
            }
            cout << char(179) << "\n";
        }
    }


    cout << " ";
    for (i=0; i<7*8; i++) cout << char(196);
    cout << "\n\n";
}

int main() {
    int q[8] = {}, c = 0;
    q[0] = 0;
 
    while (c >= 0) {  
        c++;                
        if (c>7) {          
            print (q); 
            c--;
        }
        else q[c] = -1;  
        while (c >= 0) {  
            q[c]++;           
            if (q[c] > 7) c--; 
            else            
                if(ok(q, c)) break;
        }
    } 
    return 0;
}
