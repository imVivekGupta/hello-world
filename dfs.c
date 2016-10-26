#include <stdio.h>
int time;

void toposort(int finish[]){
	int i,j,t;
	int arr[6][2];
	for(i=0;i<6;i++){
		arr[i][0]=finish[i];
		arr[i][1]=i;
	}
	for(i=0;i<6;i++)
		for(j=0;j<5-i;j++)
		{
			if(arr[j][0]<arr[j+1][0]){
				t=arr[j][0];
				arr[j][0]=arr[j+1][0];
				arr[j+1][0]=t;
				t=arr[j][1];
				arr[j][1]=arr[j+1][1];
				arr[j+1][1]=t;
			}
		}
		printf("\n");
	for(i=0;i<6;i++)
		printf("%d ",arr[i][1]);	
	printf("\n");
}

void dfs_visit(int u,int G[6][6],char E[6][6],int visited[],int start[], int finish[]){
	int v;
	visited[u]=1;
	printf("%d\n",u);
	start[u]=++time;
	for(v=0;v<6;v++){
		if(G[u][v] && !visited[v]){
			E[u][v] = 'T';
			//E[u][v] = E[v][u] = 'T';
			dfs_visit(v,G,E,visited,start,finish);
		}	
	}
	finish[u]=++time;
}

void dfs(int G[6][6], char E[6][6]){
	int visited[6]={0,0,0,0,0,0},i,j,time=0;
	int start[6] = {0,0,0,0,0,0};
	int finish[6] = {0,0,0,0,0,0};	
	for(i=0;i<6;i++){
		if(!visited[i])
		dfs_visit(i,G,E,visited,start,finish);
	}
	printf("start :");
	for(i=0;i<6;i++)
		printf("%d ",start[i]);
	printf("\nfinish:");
	for(i=0;i<6;i++)
		printf("%d ",finish[i]);
	printf("\n");
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++){
			if(G[i][j]){
					if(start[j]<start[i] && start[i]<finish[i] && finish[i]<finish[j])
						E[i][j] = 'B';
					if(start[i]<start[j] && start[j]<finish[j] && finish[j]<finish[i] && E[i][j]!='T')
						E[i][j] = 'F';
					if(start[j]<finish[j] && finish[j]<start[i] && start[i]<finish[i])
						E[i][j] = 'C';								
					printf("%c ",E[i][j]);	
			}
			else
				printf("* ");	
			}
		printf("\n");
	}		
	toposort(finish);	
}

int main(){
	int G[6][6]={{0,1,0,0,0,1},{0,0,1,0,1,0},{0,0,0,1,0,0},{0,1,0,0,0,0},{0,0,1,0,0,1},{0,0,0,0,0,0}};
	char E[6][6];
	dfs(G,E);
}
