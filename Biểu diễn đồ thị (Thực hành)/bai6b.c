#include<stdio.h>
//Danh sach cung

#define Max_m 500

typedef struct{
	int u,v;
}Edge;

typedef struct{
	int n,m;
	Edge edges[Max_m];
}Graph;

void init_graph(Graph *pG,int n){
	pG->n=n;
	pG->m=0;
}
void add_edge(Graph *pG,int u,int v){
	
	    pG->edges[pG->m].u=u;
	    pG->edges[pG->m].v=v;
	    pG->m++;
} 
int adjacent(Graph *pG,int u, int v){
	int e;
	for(e=0;e<pG->m;e++)
		if((pG->edges[e].u==u && pG->edges[e].v==v))
		return 1;
	return 0;
}

void neighbours(Graph *pG,int u){
	int v;
	for(v=1;v<=pG->n;v++)
		if(adjacent(pG,u,v)==1)
			printf("%d ",v);
}
int main(){
	int n,m,i,u,v;
	Graph G;
	freopen("dothi.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}   
	for(i=1;i<=n;i++){
	    printf("neighbours(%d) = ",i);
	    neighbours(&G,i);
	    printf("\n");
	} 
	return 0;
}
