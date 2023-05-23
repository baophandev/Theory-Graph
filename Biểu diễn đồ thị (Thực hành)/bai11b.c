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
    if(u==v){
        pG->A[u][v]+=1;
    } else {
 	pG->A[u][v]+=1;
    }
 	pG->m++;
 }
 
 
void neighbours(Graph *pG,int u){
	int i;
	for(i=1;i<=pG->n;i++){
		if(pG->A[u][i] !=0)
			printf("%d ",i);
	}
	printf("\n");
}
 
 int main(){
 	Graph G;
 	int n,m,u,v,i,j;
 	freopen("dothi.txt","r",stdin);
 	scanf("%d%d",&n,&m);
 	init_graph(&G,n);
 	for(i=0;i<m;i++){
 		scanf("%d%d",&u,&v);
 		add_edge(&G,u,v);
	 }
//	 for(i=1;i<=n;i++){
//	 	for(j=1;j<=n;j++){
//	 		printf("%d ",G.A[i][j]);
//		}
//		printf("\n");
//	 }
	for(i=1;i<=n;i++){
		printf("neighbours(%d) = ",i);
		neighbours(&G,i);
	}
 }
