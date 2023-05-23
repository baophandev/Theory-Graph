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

void topo_sort(Graph *G,List *L){
	int d[MAXN];
	int u,x,v;
	for(u=1;u<=G->n;u++){
		d[u]=0;
		for(x=1;x<=G->n;x++)
			if(G->A[x][u] != 0)
				d[u]++;
	}
	
	Queue Q;
	make_null_queue(&Q);
	
	for(u=1;u<=G->n;u++)
		if(d[u]==0)
			enqueue(&Q,u);
	make_null_list(L);
	
	while(!empty_queue(&Q)){
		u = front(&Q);
		dequeue(&Q);
		push_back(L,u);
		
		for(v=1;v<=G->n;v++)
			if(G->A[u][v] != 0){
				d[v]--;
				if(d[v]==0)
					enqueue(&Q,v);
			}
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
	List L;
	make_null_list(&L);
	topo_sort(&G,&L);
	for(i=1;i<=L.size;i++){
		printf("%d ",element_at(&L,i));
	}
}
