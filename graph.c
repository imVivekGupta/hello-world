#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int v;
	struct node* next;
}nd;

nd* create_node(int v){
	nd* node = (nd*)malloc(sizeof(nd));
	node->v = v;
	return node;
}

nd** create_graph(int V){
	nd** G;
	int i;
	G = (nd**)malloc(V*sizeof(nd*));
	for(i=0;i<V;i++)
		G[i] = NULL;
	return G;
}

void add_edge(nd** G, int u, int v){
	nd* node = create_node(v);
	node->next = G[u];
	G[u] = node;
}

void degree(nd** G,int V){
	int i;
	nd* curr;
	int deg[V][2];
	for(i=0;i<V;i++)
		deg[i][0] = deg[i][1] = 0;
	for(i=0;i<V;i++){
		curr = G[i];
		while(curr){
			deg[i][1]++;
			deg[curr->v][0]++;
			curr = curr->next;
		}
	}
	printf("in-degree out-degree\n");
	for(i=0;i<V;i++)
		printf("  %d	     %d\n",deg[i][0],deg[i][1]);
}

void display_graph(nd** G,int V){
	int  i;
	//V = sizeof(G)/sizeof(G[0]);
	nd* curr;
	for(i=0;i<V;i++){
		curr = G[i];
		printf("%d ",i);
		while(curr){
			printf("-> %d ",curr->v);
			curr = curr->next;
		}
		printf("\n");
	}
}

int main(){
	nd** G;
	int V,E,u,v;
	scanf("%d",&V);
	G = create_graph(V);
	scanf("%d",&E);
	while(E--){
		scanf("%d%d",&u,&v);
		add_edge(G,u,v);
	}	
	display_graph(G,V);
	degree(G,V);	
	return 0;
}
