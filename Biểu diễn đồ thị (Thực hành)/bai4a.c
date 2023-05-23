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
		if((pG->edges[e].u==u && pG->edges[e].v==v)||
		(pG->edges[e].u==v && pG->edges[e].v==u))
		return 1;
	return 0;
}
int main(){
	int n=4,m=0;
	Graph G;
	init_graph(&G,n);
	add_edge(&G,1,2); 
	printf("%d",adjacent(&G,1,1));
}
