#include <stdio.h>
#include <stdlib.h>

typedef struct nd{
	int v;
	struct nd* next;
	}node;

node* create_node(int v){
	node* nd = (node*)malloc(sizeof(node));
	nd->v = v;
	return nd;
}

node** getAdjList(int V, int G[V][V]){
	int i,j;
	node** Adjlist;
	Adjlist = (node**)malloc(V*sizeof(node*));
	node* nd,*curr;
	for(i=0;i<V;i++)
		Adjlist[i] = NULL;
	for(i=0;i<V;i++)
		for(j=0;j<V;j++)
			if(G[i][j]){
				nd = create_node(j);
				nd->next = Adjlist[i];
				Adjlist[i] = nd;
			}
	for(i=0;i<V;i++){
		printf("%d ",i);
		curr = Adjlist[i];
		while(curr){
			printf("-> %d ",curr->v);
			curr = curr->next;
		}
		printf("\n");
	}
	return Adjlist;
}

int dfs_visit(int i, node** Adjlist, int visited[]){
	int t=0;
	node* curr;
	visited[i]=1;
	//printf("%d\n",i);
	curr = Adjlist[i];
	while(curr){
		if(!visited[curr->v])
			t=t+dfs_visit(curr->v,Adjlist,visited);
		curr = curr->next;
		}
	return t+1;	
	}
			
				
int dfs(node** Adjlist, int V){
	int visited[V],i,m=0,n,connected=0;
	for(i=0;i<V;i++)
		visited[i] = 0;
	for(i=0;i<V;i++)
		if(!visited[i]){
			n = dfs_visit(i,Adjlist,visited);
			//printf("no. of vertices: %d\n",n);
			connected++;
		}
	return connected;	
}

void bnefind(node** Adjlist, int V){
	int i;
	node* temp,*pre,*curr;
	printf("bottleneck edges:\n");
	for(i=0;i<V;i++){
		if(Adjlist[i]==NULL)
			continue;
		temp = Adjlist[i];
		Adjlist[i] = temp->next;
		if(dfs(Adjlist,V)>1)
			printf("%d->%d\n",i,temp->v);
		Adjlist[i] = temp;		
		pre = Adjlist[i];
		curr = pre->next;
		while(curr){
			pre->next = curr->next;
			if(dfs(Adjlist,V)>1)
				printf("%d->%d\n",i,curr->v);
			pre->next = curr;
			pre = curr;
			curr = curr->next;
		}
	}
}			

int main(){
	int V;
	V=4;
	node** Adjlist;
	int G[4][4]={{0,1,1,1},{1,0,1,1},{1,1,0,0},{1,1,0,0}};
	Adjlist = getAdjList(V,G);
	//dfs(Adjlist,V);
	bnefind(Adjlist,V);
	return 0;
}
