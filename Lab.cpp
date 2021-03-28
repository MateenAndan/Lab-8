#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Linear index method
int LinearIndex(int i, int j, int cols){
    int index = i * cols+j;
    return index;
}

// Inverse index method
int InverseIndex(int index, int rownum){
    int i = index % rownum;
    int j = index/ rownum;
    return i,j;
    
}

// main method
int main (){
    int A[8][8];
    int D[32][32];
    int E[128][128];

    for(int i = 0; i<8; i++){
        for (int j = 0; j < 8; j++){
            if (j > i){
                A[i][j] = 0;
                cout<<A[i][j]<<" ";
            }
            else {
                A[i][j] = rand()%1000 + 1;
                cout<<A[i][j]<<" ";
            }
        }

        cout<<endl;
    }

    for(int i = 0; i<32; i++){
        for (int j = 0; j < 32; j++){
            if (j > i){
                D[i][j] = 0;
                cout<<D[i][j]<<" ";
            }
            else {
                D[i][j] = rand()%1000 + 1;
                cout<<D[i][j]<<" ";
            }
        }

        cout<<endl;
    }

    for(int i = 0; i<128; i++){
        for (int j = 0; j < 128; j++){
            if (j > i){
                E[i][j] = 0;
                cout<<E[i][j]<<" ";
            }
            else {
                E[i][j] = rand()%1000 + 1;
                cout<<E[i][j]<<" ";
            }
        }

        cout<<endl;
    }

    int B[8];
    int Bt[32];
    int Btr[128];

    for(int i = 0; i<8; i++){
        for (int j = 0; j < 8; j++){
            B[LinearIndex(i,j,8)] = A[i][j];
            cout <<B[i]<<" ";
        } 
        
        
    }

    for(int i = 0; i<32; i++){
        for (int j = 0; j < 32; j++){
            Bt[LinearIndex(i,j,32)] = D[i][j];
            cout <<Bt[i]<<" ";
        }
    }

    for(int i = 0; i<128; i++){
        for (int j = 0; j < 128; j++){
            Btr[LinearIndex(i,j,128)] = E[i][j];
            cout <<Btr[i]<< " ";
        }
    }

    int C[8][8];
    int Ct[32][32];
    int Ctr[128][128];

    for(int i = 0; i<8; i++){
        for (int j = 0; j < 8; j++){
           int index = LinearIndex (i,j,8);
           int a,b = InverseIndex(index,8);
            C[a][b] = B[j];
            cout <<C[i][j]<< " ";
        }
    }

    for(int i = 0; i<32; i++){
        for (int j = 0; j < 32; j++){
             int index = LinearIndex (i,j,32);
             int a,b =  InverseIndex(index,32);
            Ct[a][b] = B[j];
            cout <<Ct[i][j]<< " ";
        }
    }

    for(int i = 0; i<128; i++){
        for (int j = 0; j < 128; j++){
            int index = LinearIndex (i,j,128);
             int a,b =  InverseIndex(index,128);
            Ctr[a][b] = B[j];
            cout <<Ctr[i][j]<< " ";
        }
    }
return 0;
}
