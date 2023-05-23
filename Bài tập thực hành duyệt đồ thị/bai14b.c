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
//    pG->A[v][u]=1;
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
int min(int a,int b){
	if(a<b) return a;
	return b;
}
int num[100], min_num[100];
int k=0;
Stack S;
int dem=0;
int on_stack[100];
void SCC(Graph *pG,int u){
	int v;
    num[u] = min_num[u] = k++;
    push(&S,u);
    on_stack[u]=1;
    for(v=1;v<=pG->n;v++){
    	if(adjacent(pG,u,v)){
        		if(num[v]<0){
        			SCC(pG,v);
        			min_num[u] = min(min_num[u],min_num[v]);
				} else if (on_stack[v])
						min_num[u] = min(min_num[u],num[v]);
		}
	}
	if(num[u] == min_num[u]){
		dem=0;
		int w;
		do{
			dem++;
			w=top(&S);
			pop(&S);
			on_stack[w]=0;
		}while(w != u);
		printf("%d\n",dem);
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
		num[j]= -1;
	}
	k=1;
	make_null_stack(&S);
	for(j=1;j<=G.n;j++){
		if(num[j] == -1)
			SCC(&G,j);
	}
//	for(i=1;i<=n;i++)
//	printf("%d %d\n",num[i],min_num[i]);
	return 0;
}
