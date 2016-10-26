#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int v;
  struct Node* next;
}node;

node* create_node(int v){
  node* nd = (node*)malloc(sizeof(node));
  nd->v = v;
  return nd;
}

node** create_graph(int V){
    int i;
  node** G = (node**)malloc(V*sizeof(node*));
  for(i=0;i<V;i++)
    G[i]=NULL;
  return G;
}

void add_edge(int u, int v, node** G){
  node* nd = create_node(v);
  nd->next = G[u];
  G[u] = nd;
}

void print_graph(node** G, int V){
    int i;
    node* curr;
    printf("Adjacency list:");
    for(i=0;i<V;i++){
      printf("\n%d ",i);
      curr = G[i];
      while(curr!=NULL){
        printf("->%d ",curr->v);
        curr = curr->next;
      }
    }
}

int main(){
    int u,v,V,E;
    node** G;
    scanf("%d",&V);
    G = create_graph(V);
    scanf("%d",&E);
    while(E--){
      scanf("%d%d",&u,&v);
      add_edge(u,v,G);
    }
    print_graph(G,V);
    return 0;
}
