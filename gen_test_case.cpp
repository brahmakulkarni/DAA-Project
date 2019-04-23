#include<bits/stdc++.h>

using namespace std;

int main(){
    // int N = rand()%99999+100000;
    int N = 10;
    int adj_matrix[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            adj_matrix[i][j] = -1;
        }
    }
    int count = rand()%(N*N-N+1)+N;
    int edges = count;
    while(count){
        int weight = rand()%100+1;
        int x = rand()%N;
        int y = rand()%N;
        if(adj_matrix[x][y]==-1){
            adj_matrix[x][y] = weight;
            count--;
        }
    }
    ofstream testFile;
    testFile.open("input.txt");
    testFile << N << " " << edges << endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(adj_matrix[i][j] != -1){
                // printf("%d %d %d\n",i+1,j+1,adj_matrix[i][j]);
                testFile << i+1 << " " << j+1 << " " << adj_matrix[i][j] << endl;
            }
        }
    }
    testFile.close();
    return 0;
}

