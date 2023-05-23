#include <stdio.h>
#define NO_COLOR 0
#define BLUE 1
#define RED 2
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

int color[100];
int conflict;
void colorize(Graph *pG,int u,int c){
	int v;
	color[u]=c;
	for(v=1;v<=pG->n;v++)
		if(adjacent(pG,u,v)){
			if(color[v] == 0)
				colorize(pG,v,3-c);
			else if(color[v] == color[u])
				conflict = 1;
		}	
}

int main(){
	int i,j,u,v,n,m,s;
	Graph G;
	freopen("dothi.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	for(j=1;j<=G.n;j++){
		color[j]=0;
	}
	conflict=0;
	for(j=1;j<=G.n;j++){
		if(color[u] == 0){
			colorize(&G,j,1);
		}
		if(conflict == 1) break;
	}
	if(conflict == 1) printf("NO");
	else printf("YES");
	return 0;
}
