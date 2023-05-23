#include <stdio.h>
#define MAXN 100

typedef struct{
    int n,m;
    int A[MAXN][MAXN];
}Graph;

typedef struct{
    int A[MAXN];
    int size;
}List;

void init_graph(Graph *G,int n){
	G->n = n;
	G->m = 0;
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			G->A[i][j]=0;
}

void add_edge(Graph *G,int u,int v){
	if(G->A[u][v]==0){
		G->A[u][v] = 1;
		G->m++;
	}
}
void make_null_list(List *L){
    L->size = 0;
}

void push_back(List *L,int x){
	L->A[L->size] = x;
	L->size++;
}

int element_at(List *L,int i){
	return L->A[i-1];
}

void copy_list(List *L1,List *L2){
	int i,x;
	make_null_list(L1);
	for(i=1;i<=L2->size;i++){
		x=element_at(L2,i);
		push_back(L1,x);
	}
}

int r[MAXN];

void ranking(Graph *G){
	int d[MAXN];
	
	int u,x;
	for(u=1;u<=G->n;u++){
		d[u] = 0;
		for(x=1;x<=G->n;x++)
			if(G->A[x][u] != 0)
				d[u]++;
	}
	
	List L1,L2;
	
	make_null_list(&L1);
	for(u=1;u<=G->n;u++){
		if(d[u] == 0) 
			push_back(&L1,u);
	}
	
	int k=0,v,i;
	while( L1.size > 0){
		make_null_list(&L2);
		for(i=1;i<=L1.size;i++){
			u=element_at(&L1,i);
			r[u] = k;
			for(v=1;v<=G->n;v++)
				if(G->A[u][v] != 0){
					d[v]--;
					if(d[v]==0)
						push_back(&L2,v);
				}
		}
		copy_list(&L1,&L2);
		k++;
	}
}

int main(){
	Graph G;
	int n,i,j,u,v,m;
	freopen("topo.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	ranking(&G);
	for(i=1;i<=G.n;i++){
		printf("rank[%d] = %d\n",i,r[i]);
	}
}
