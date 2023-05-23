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
    int top_idx;
}Stack;

void make_null_stack(Stack *pS){
	pS->top_idx = -1;
}

void push(Stack *pS,int u){
	pS->top_idx++;
	pS->data[pS->top_idx]=u;
}

int top(Stack *pS){
	return pS->data[pS->top_idx];
}

void pop(Stack *pS){
	pS->top_idx--;
}


int empty(Stack *pS){
	return (pS->top_idx == -1);
}

int mark[100];

void DFS(Graph *pG,int s){
    Stack S;
    int v;
    make_null_stack(&S);
    push(&S,s);
    while(!empty(&S)){
        int u;
        u=top(&S);pop(&S);
        if(mark[u]!=0) 
			continue;
        printf("%d\n",u);
        mark[u]=1;
//       for(v=1;v<=pG->n;v++)
       for(v=pG->n;v>=1;v--)
        	if(adjacent(pG,u,v))
        		push(&S,v);
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
			DFS(&G,j);
	}
	return 0;
}
