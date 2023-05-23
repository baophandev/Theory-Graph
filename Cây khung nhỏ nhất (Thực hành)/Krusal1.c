#include <stdio.h>
#define MAXN 100
int parent[MAXN];
typedef struct{
	int u,v,w;
}Edge; 

typedef struct{
	Edge edges[MAXN];
	int n,m;
}Graph;

void init_graph(Graph *G,int n){
	G->n = n;
	G->m = 0;
}

void add_edge(Graph *G,int u,int v,int w){
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->edges[G->m].w = w;
	G->m++;
}

int findRoot(int u){
	if(parent[u] == u)
		return u;
	return findRoot(parent[u]);
}

int Krusal(Graph *G,Graph *T){
	int i,j;
	for(i=0;i<G->m;i++)
		for(j=i+1;j<G->m;j++)
			if(G->edges[j].w < G->edges[i].w){
				Edge tam = G->edges[i];
				G->edges[i] = G->edges[j];
				G->edges[j] = tam;
			}
	
	init_graph(T,G->n);
	int u,e,v,w,root_u,root_v;
	for(u=1;u<=G->n;u++)
		parent[u] = u;
	int sum_w = 0;
	
	for(e=0;e<G->m;e++){
		u = G->edges[e].u;
		v = G->edges[e].v;
		w = G->edges[e].w;
		root_u = findRoot(u);
		root_v = findRoot(v);
		if(root_u != root_v){
			add_edge(T,u,v,w);
			parent[root_v] = root_u;
			sum_w = sum_w + w;
		}
	}
	return sum_w;
}

int main() {
	Graph G,T;
	int n,m,u,v,w,i,j;
	freopen("data.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add_edge(&G,u,v,w);
	}
	
	int sum_w=Krusal(&G,&T);
	printf("Tong cua cay la: %d\n",sum_w);
	for(j=0;j<T.m;j++)
		printf("(%d, %d): %d\n",T.edges[j].u,T.edges[j].v,T.edges[j].w);
	return 0;
}
