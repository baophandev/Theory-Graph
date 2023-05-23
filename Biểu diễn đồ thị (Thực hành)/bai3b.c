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
	int i,d=0;
	for(i=0;i<=pG->m;i++){
		if((pG->edges[i].u==u && pG->edges[i].v==v)){
			d=1;
			break;
		}
	}
	if(d==0){
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
