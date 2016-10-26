#include <stdio.h>
#include <stdlib.h>

int dfs_visit(int G[8][8],int visited[8], int u, int flag){
    int i;
    visited[u] = 1;
    printf("%d\n",u);
    for(i=1;i<=7;i++){
        if(G[u][i] && visited[i])
          flag = 1;
    }
    for(i=1;i<=7;i++){
        if(G[u][i] && !visited[i])
           dfs_visit(G,visited,i,flag);
    }
}

void dfs(int G[8][8]){
    int visited[8]={0,0,0,0,0,0,0,0};
    int i,flag;
    for(i=1;i<=7;i++){
        if(visited[i]==0)
            flag = dfs_visit(G,visited,i,0);
    }
    if(flag)
    printf("Cyclic\n");
    else
    printf("Acyclic\n");
}

int main(){
    int G[8][8]={{0,0,0,0,0,0,0,0},{0,0,1,1,0,0,0,0},{0,0,0,0,0,1,1,0},{0,0,0,0,0,0,0,1},{0,0,1,0,0,0,0,0},{0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,1},{0,0,0,0,1,0,0,0}};
    dfs(G);
    return 0;
}
