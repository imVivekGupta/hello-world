#include <stdio.h>
#include <stdlib.h>
#define W 1
#define G 2
#define B 3

typedef struct node{
	int color;
	int v;
}nd;

void dfs_visit(int u,int V,int G[V][V],char E[V][V],int color[],int parent[]){
	color[u]=G;
	int v,t;
	for(v=0;v<V;i++){
		if(G[u][v]){
			switch(color[v]){
				case W:	E[u][v]='T';
					parent[v]=u;
					dfs_visit(v,V,G,E,color,parent);
					break;
				case G: E[u][v]='B';
					break;					
				case B: t=v;
					while(parent[t]!=v){
						if(parent[t]==u){
							E[u][v]='F';
							break;
						}
						t=parent[t];
					}
					if(E[u][v]!='F')
						E[u][v]='C';
					break;
			}
		}
	}
}
		

void dfs(int V,int G[V][V]){
	int color[V],parent[V],i;
	char E[V][V];
	for(i=0;i<V;i++){
		color[i]=W;
		parent[i]=i;
	}
	for(i=0;i<V;i++)
		for(j=0;j<V;j++)
			E[i][j]='*';
	for(i=0;i<V;i++)
		if(color[i]==W)
			dfs_visit(i,V,G,E,color,parent);
	display(V,E);
}

void display(int V,char E[V][V]){
	int i,j;
	for(i=0;i<V;i++){
		for(j=0;j<V;j++)
			printf("%c ",E[i][j]);
			printf("\n");
	}
}

int main(){
	dfs();
	return 0;
}
