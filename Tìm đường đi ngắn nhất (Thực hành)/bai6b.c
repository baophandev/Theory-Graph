#include <stdio.h>

#define MAXN 100
#define MAXM 100
typedef struct{
	int u,v;
	int w;
}Edge;

typedef struct{
	int n,m;
	Edge edges[100];
}Graph;

void init_graph(Graph *pG,int n){
	pG->n=n;
	pG->m=0;
}

void add_edge(Graph *G,int u,int v,int w){
	G->edges[G->m].u=u;
	G->edges[G->m].v=v;
	G->edges[G->m].w=w;
	G->m++;
}

#define oo 99999

int pi[100];
int p[100];
void BellmanFord(Graph *pG,int s){
	int u,v,w,it,k;
	for(u = 1; u <= pG->n; u++){
		pi[u] = oo;
	}
	
	pi[s] = 0;
	p[s] = -1;
	
	for(it = 1; it < pG->n; it++){
		for(k = 0; k < pG->m; k++){
			u = pG->edges[k].u;
			v = pG->edges[k].v;
			w = pG->edges[k].w;
			
			if(pi[u] == oo) continue;
			
			if(pi[u] + w < pi[v]){
				pi[v] = pi[u] + w;
				p[v] = u;
			}
		}
	}
}

void Path(Graph *G,int n){
	int path[MAXN];
	int k=0;
	int current = n;
	while(current != -1){
		path[k] = current;
		k++;
		current=p[current];
	}
	int u;
	for(u=k-1;u>=0;u--){
		printf("%d ",path[u]);
		if(path[u]!=n) printf("-> ");
	}
}

int main(){
	Graph G;
	int i,n,m,u,v,w,x,y;
	freopen("dothi.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add_edge(&G,u,v,w);
	}
	scanf("%d%d",&x,&y);
	BellmanFord(&G,x);
	Path(&G,y);
	return 0;
}
