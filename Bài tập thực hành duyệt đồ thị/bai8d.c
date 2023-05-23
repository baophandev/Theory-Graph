#include <stdio.h>

typedef struct{
    int n,m;
    int A[100][100];
}Graph;

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
    pG->A[v][u]=1;
    pG->m++;
}

int adjacent(Graph *pG,int u,int v){
    return pG->A[u][v];
}

typedef struct {
    int data[100];
    int front, rear;
}Queue;

void make_null_queue(Queue *pQ){
    pQ->front = 0;
    pQ->rear= -1;
}

void enqueue(Queue *pQ,int x){
    pQ->rear++;
    pQ->data[pQ->rear] = x;
}

int front(Queue *pQ){
    return pQ->data[pQ->front];
}

void dequeue(Queue *pQ){
    pQ->front++;
}

int empty(Queue *pQ){
    return pQ->front > pQ->rear;
}

int mark[100];
int nb_u;
void BFS(Graph *pG,int s){
    Queue Q;
    int v;
    make_null_queue(&Q);
    enqueue(&Q,s);
    while(!empty(&Q)){
        int u;
        u=front(&Q);dequeue(&Q);
        if(mark[u]!=0) continue;
        printf("%d\n",u);
        mark[u]=1;
        nb_u++;
        for(v=1;v<=pG->n;v++)
        	if(adjacent(pG,u,v))
        		enqueue(&Q,v);
    }
}

int main(){
	int i,j,u,v,n,m,s,max_cnt=0;
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
	for(i=1;i<=n;i++){
		if(mark[i]==0){
			nb_u=0;
			BFS(&G,i);
		}
	    if(max_cnt<nb_u)
	    	max_cnt=nb_u;
	} 
	printf("sd: %d",max_cnt);
	return 0;
}
