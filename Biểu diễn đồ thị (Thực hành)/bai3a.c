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
	if(u>=1 && v>=1 && v<=pG->n && u<=pG->n){
	    pG->edges[pG->m].u=u;
	    pG->edges[pG->m].v=v;
	    pG->m++;
	}
} 
int main(){
	int n=4,m=0;
	Graph G;
	init_graph(&G,n);
	add_edge(&G,1,2); 
}
