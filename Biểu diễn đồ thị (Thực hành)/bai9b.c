#include<stdio.h>

#define Max_M 100

typedef struct{
	int n,m;
	int A[Max_M][Max_M];
}Graph;

void init_graph(Graph *pG,int n){
	int i,j;
	pG->n=n;
	pG->m=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			pG->A[i][j]=0;
		}
	}
}
 void add_edge(Graph *pG,int u,int v){
 	pG->A[u][v]=1;
 	pG->m++;
 }
 
 int main(){
 	Graph G;
 	int n,m,u,v,i,j;
 	scanf("%d%d",&n,&m);
 	init_graph(&G,n);
 	for(i=0;i<m;i++){
 		scanf("%d%d",&u,&v);
 		add_edge(&G,u,v);
	 }
	 printf("Ma tran ke:\n");
	 for(i=1;i<=n;i++){
	 	for(j=1;j<=n;j++){
	 		printf("%d ",G.A[i][j]);
		}
		printf("\n");
	 }
 }
