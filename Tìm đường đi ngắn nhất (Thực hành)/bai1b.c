#include <stdio.h>
#define MAXN 100
#define NO_EDGE 0

typedef struct{
	int n,m;
	int W[MAXN][MAXN];
}Graph;

void init_graph(Graph *G,int  n){
	G->n=n;
	G->m=0;
	int u,v;
	for(u=1;u<=G->n;u++){
		for(v=1;v<=G->n;v++){
			G->W[u][v] = -1;
		}
	}
}

void add_edge(Graph *G,int u,int v,int w){
	G->W[u][v]=w;
	G->W[v][u]=w;
	G->m++;
}

int mark[MAXN];
int pi[MAXN];
int p[MAXN];

void MooreDijkstra(Graph *G,int s){
	int u,v,it;
	for(u=1;u<=G->n;u++){
		pi[u]=99999;
		mark[u]=0;
	}
	
	p[s]=-1;
	pi[s]=0;
	
	for(it=1;it<G->n;it++){
		int j,min_pi=99999;
		for(j=1;j<=G->n;j++)
			if(mark[j]==0 && pi[j] < min_pi){
				min_pi=pi[j];
				u=j;
			}
		mark[u]=1;
		for(v=1;v<=G->n;v++)
			if(G->W[u][v]!=-1 && mark[v] == 0)
				if(pi[u]+G->W[u][v] < pi[v]){
					pi[v]=pi[u] + G->W[u][v];
					p[v]=u;
				}
	}
}

int main(){
	Graph G;
	int n,m,u,v,w,i,j;
	freopen("dothi.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add_edge(&G,u,v,w);
	}
	MooreDijkstra(&G,1);
	for(i=1;i<=n;i++){
		printf("pi[%d] = %d, p[%d] = %d\n",i,pi[i],i,p[i]);
	}
	return 0;
}
