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
			G->W[u][v] = 0;
		}
	}
}

void add_edge(Graph *G,int u,int v,int w){
	G->W[u][v]=w;
	G->m++;
}

#define oo 99999

int pi[MAXN][MAXN];
int next[MAXN][MAXN];
void FloydWarshall(Graph *pG){
	int u,v,k;
	for(u = 1; u<= pG->n; u++)
		for(v = 1; v <= pG->n; v++){
			pi[u][v] = oo;
			next[u][v] = -1;
		}
	for(u = 1; u<= pG->n; u++)
		pi[u][u] = 0;
		
	for(u = 1; u<= pG->n; u++)
		for( v = 1; v<= pG->n; v++)
			if(pG->W[u][v] != NO_EDGE){
				pi[u][v] = pG->W[u][v];
				next[u][v] = v;
			}
			
	for(k = 1; k <= pG->n; k++)
		for(u = 1; u <= pG->n; u++)
			for(v = 1; v <= pG->n; v++)
				if(pi[u][k] + pi[k][v] < pi[u][v]){
					if(pi[u][k]==oo || pi[k][v]==oo) pi[u][v]=oo;
					else pi[u][v] = pi[u][k] + pi[k][v];
					next[u][v] = next[u][k];
				}
}

void nega_cycle(Graph *pG){
	int u,nega=0;
	for(u = 1; u <= pG->n; u++){
		if(pi[u][u] < 0){
			nega = 1;
			break;
		}
	}
		if(nega == 1){
			printf("YES. Cac dinh trong chu tirnh la: ");
			int v=u;
			u = next[u][u];
			while(v != u){
				printf("%d ",u);
				u = next[u][u];
			} printf("%d",u);
		}
		else printf("NO");
	
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
	FloydWarshall(&G);
	nega_cycle(&G);
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n;j++){
//			if(pi[i][j]==oo) printf("%d -> %d: NO PATH\n",i,j);
//			else printf("%d -> %d: %d\n",i,j,pi[i][j]);
//		}
//	}
	return 0;
}
