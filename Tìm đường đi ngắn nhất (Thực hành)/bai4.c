#include <stdio.h>
#define MAXN 100
#define NO_EDGE 0

typedef struct{
	int n,m;
	int W[MAXN][MAXN];
}Graph;

void init_graph(Graph *G,int  n,int m){
	G->n=n;
	G->m=m;
	int u,v;
	for(u=1;u<=G->m;u++){
		for(v=1;v<=G->n;v++){
			G->W[u][v] = -1;
		}
	}
}

void add_edge(Graph *G,int u,int v,int w){
	G->W[u][v]=w;
//	G->W[v][u]=w;
}

int mark[MAXN];
int pi[MAXN];
int p[MAXN];

void MooreDijkstra(Graph *G,int s){
	int u,v,it;
	for(u=1;u<=(G->n*G->m);u++){
		pi[u]=99999;
		mark[u]=0;
	}
	
	pi[s]=0;
	
	int di[]={-1,1,0,0};
	int dj[]={0,0,-1,1};
	
	for(it=1;it<(G->n*G->m);it++){
		int t,min_pi=99999;
		for(t=1;t<=(G->n*G->m);t++)
			if(mark[t]==0 && pi[t] < min_pi){
				min_pi=pi[t];
				u=t;
			}
//		printf("nho nhat la: %d %d\n",u,pi[u]);	
		mark[u]=1;
	
		
	
		int i = (u-1)/G->n;
		int j = (u-1)%G->n;
//		printf("-------i: %d  j: %d\n",i,j);
		
		int k,ii,jj;
		for(k=0;k<4;k++){
			ii = i + di[k];
			jj = j + dj[k];
//			printf("-------ii: %d  jj: %d\n",ii,jj);
			if(ii >= 0 && ii < G->m && jj >= 0 && jj < G->n){
				v=ii*G->n + jj +1;
				if(pi[u]+G->W[ii][jj] < pi[v]){
					pi[v]=pi[u] + G->W[ii][jj];
//					printf(">>>>>>>pi[%d] = %d\n",v,pi[v]);
				}
			}
		}
	}
}


int main(){
	Graph G;
	int a[100][100];
	int n,m,u,v,w,i,j,t,h;
	freopen("dothi.txt","r",stdin);
	scanf("%d%d",&m,&n);
	init_graph(&G,n,m);
	for(u=0;u<m;u++){
		for(v=0;v<n;v++){
			scanf("%d",&w);
			add_edge(&G,u,v,w);
		}	
	}
//	printf("%d %d\n",G.m,G.n);
//	for(u=1;u<=m;u++){
//		for(v=1;v<=n;v++){
//			printf("%d ",G.W[u][v]);
//		}	
//		printf("\n");
//	}
	
	MooreDijkstra(&G,1);
	printf("Duong di tu diem dau den diem cuoi: %d",pi[n*m]);
	return 0;
}
