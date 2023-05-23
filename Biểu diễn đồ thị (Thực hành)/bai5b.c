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

int degree(Graph *pG,int u){
	int e,deg_u=0;
	for(e=0;e<pG->m;e++){
		if(pG->edges[e].u==u)
			deg_u++;
		if(pG->edges[e].v==u)
			deg_u++;
	}
	return deg_u;
}

int main(){
	int n,m,i,u,v;
	Graph G;
	scanf("%d%d",&n,&m);
		init_graph(&G,n);
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}   
	for(i=1;i<=n;i++){
		printf("deg(%d) = %d\n",i,degree(&G,i));
	}
	return 0;
}
