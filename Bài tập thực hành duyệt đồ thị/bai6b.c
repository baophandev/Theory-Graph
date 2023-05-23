#include <stdio.h>

typedef struct{
    int n,m;
    int A[100][100];
}Graph;

typedef struct{
	int child, pa;
}Parenttype;
////////////////////////////////////////////////
void init_graph(Graph *pG,int n){
    int u,v;
    pG->n=n;
    pG->m=0;
    for(u=1;u<=n;u++){
        for(v=1;v<=n;v++){
            pG->A[u][v]=0;
        }
    }
}

void add_edge(Graph *pG,int u,int v){
    pG->A[u][v]=1;
//    pG->A[v][u]=1;
    pG->m++;
}

int adjacent(Graph *pG,int u,int v){
    return pG->A[u][v];
}
////////////////////////////////////////////////
typedef struct {
    Parenttype data[100];
    int front, rear;
}Queue;

void make_null_queue(Queue *pQ){
    pQ->front = 0;
    pQ->rear= -1;
}

void enqueue(Queue *pQ,Parenttype x){
    pQ->rear++;
    pQ->data[pQ->rear] = x;
}

Parenttype front(Queue *pQ){
    return pQ->data[pQ->front];
}

void dequeue(Queue *pQ){
    pQ->front++;
}

int empty(Queue *pQ){
    return pQ->front > pQ->rear;
}

int mark[100];
int parent[100];
void BFS(Graph *pG,int s){
    Queue Q;
    Parenttype P;
    int v;
    make_null_queue(&Q);
    P.child=s;
    P.pa=-1;
    enqueue(&Q,P);
    while(!empty(&Q)){
        Parenttype pe;
        pe=front(&Q);
		dequeue(&Q);
		int u=pe.child, 
		p=pe.pa;
        if(mark[u]!=0) 
			continue;
//        printf("%d\n",u);
        mark[u]=1;
        parent[u]=p;
        for(v=1;v<=pG->n;v++)
        	if(adjacent(pG,u,v)){
        		Parenttype P;
        		P.child=v;
        		P.pa=u;
        		enqueue(&Q,P);
			}
    }
}

int main(){
	int i,j,u,v,n,m;
	Graph G;
	freopen("dothi.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	for(j=1;j<=G.n;j++){
		mark[j]=0;
	}
	for(j=1;j<=G.n;j++){
		if(mark[j]==0)
			BFS(&G,j);
	}
	for(j=1;j<=G.n;j++){
		printf("%d %d\n",j,parent[j]); 
	}
	return 0;
}
