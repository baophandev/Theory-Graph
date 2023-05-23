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
int main(){
	int n=4,m=0;
	Graph G;
	init_graph(&G,n);
}
