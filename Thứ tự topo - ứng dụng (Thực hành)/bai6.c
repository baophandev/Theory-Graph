#include <stdio.h>
#define MAXN 100
#define oo 99999

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
	G->A[u][v] = 1;
	G->m++;
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

typedef struct{
	int front, rear;
	int A[MAXN];
}Queue;

void make_null_queue(Queue *Q){
	Q->front = 0;
	Q->rear = -1; 
}

void enqueue(Queue *Q,int x){
	Q->rear++;
	Q->A[Q->rear] = x;
}

void dequeue(Queue *Q){
	Q->front++;
}

int front(Queue *Q){
	return Q->A[Q->front];
}

int empty_queue(Queue *Q){
	return (Q->rear<Q->front);
}

int d[MAXN];
void topo_sort(Graph *G,List *L){
	int d1[MAXN];
	int u,x,v;
	for(u=1;u<=G->n;u++){
		d1[u]=d[u];
	}
	for(u=1;u<=G->n;u++){
		d1[u]=0;
		for(x=1;x<=G->n;x++)
			if(G->A[x][u] != 0)
				d1[u]++;
	}
	
	Queue Q;
	make_null_queue(&Q);
	
	for(u=1;u<=G->n;u++)
		if(d1[u]==0)
			enqueue(&Q,u);
	make_null_list(L);
	
	while(!empty_queue(&Q)){
		u = front(&Q);
		dequeue(&Q);
		push_back(L,u);
		
		for(v=1;v<=G->n;v++)
			if(G->A[u][v] != 0){
				d1[v]--;
				if(d1[v]==0)
					enqueue(&Q,v);
			}
	}
}

int min(int a,int b){
	if (a<b) return a;
	return b;
}

int max(int a,int b){
	if(a>b) return a;
	return b;
}
int main(){
	Graph G;
	int n,i,j,u,v,m,x;
	freopen("topo.txt","r",stdin);
	scanf("%d",&n);
	for(v=1;v<=n;v++){
		scanf("%d",&d[v]);
	}
	init_graph(&G,n+2);
	int alpha = n+1, beta = n+2;
	d[alpha] = 0;
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	
	for(u = 1 ; u <= n ; u++){
		int deg_neg = 0;
		for(x = 1; x<= n ; x++)
			if(G.A[x][u] > 0)
				deg_neg++;
		if(deg_neg == 0)
			add_edge(&G,alpha,u);
		
	}
	
	for(u = 1 ; u <= n ; u++){
		int deg_pos = 0;
		for(v = 1; v<= n ; v++)
			if(G.A[u][v] > 0)
				deg_pos++;
		if(deg_pos == 0)
			add_edge(&G,u,beta);
	}
	List L;
	make_null_list(&L);
	topo_sort(&G,&L);
	int t[MAXN];
	t[alpha] = 0;
	for(j=2;j<=L.size;j++){
		u = element_at(&L,j);
		t[u] = -oo;
		for(x=1;x<=G.n;x++)
			if(G.A[x][u] > 0)
				t[u] = max(t[u],t[x]+d[x]);
	}
	
	int T[MAXN];
	T[beta] = t[beta];
	
	for(j=L.size-1;j>=1;j--){
		u = element_at(&L,j);
		T[u] = oo;
		for(v=1;v<=G.n;v++)
			if(G.A[u][v] > 0)
				T[u] = min(T[u],T[v] - d[u]);
	}
	printf("%d",t[n]+d[n]);
	return 0;
}
