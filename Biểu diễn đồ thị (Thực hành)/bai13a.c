#include <stdio.h>
#define Max_N 100
#define Max_Elements 100
typedef int ElementType;

typedef struct{
	ElementType data[Max_Elements];
	int size;
}List;

typedef struct{
	int n;
	List adj[Max_N];
}Graph;

void make_null(List *pL){
	pL->size=0;
}

void push_back(List *pL, ElementType x){
	pL->data[pL->size]=x;
	pL->size++;
}

ElementType element_at(List *pL,int i){
	return pL->data[i-1];
}

int count_list(List *pL){
	return pL->size;
}

void init_graph(Graph *pG,int n){
	int u;
	pG->n=n;
	for(u=1;u<=n;u++){
		make_null(&pG->adj[u]);
	}
}

void add_edge(Graph *pG,int u,int v){
	push_back(&pG->adj[u],v);
	push_back(&pG->adj[v],u);
}

int adjacent(Graph *pG,int u, int v){
	int j;
	for(j=1;j<=pG->adj[u].size;j++){
		if(element_at(&pG->adj[u],j)==v)
			return 1;
	} 
	return 0;
}

int degree(Graph *pG,int u){
	return pG->adj[u].size;
}

void listadjacent(Graph *pG, int u){
	int i;
	for(i=1;i<=pG->adj[u].size;i++){
		printf("%d ",element_at(&pG->adj[u],i));
	}
}
int main(){
	int i,j,u,v,e,n,m,s;
	Graph G;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1;i<=n;i++){
		scanf("%d",&s);
		for(j=1;j<=s;j++){
			scanf("%d",&v);
			add_edge(&G,u,v);
		}
	}
	int t=element_at(&G.adj[1],1);
	printf("%d",t);
	for(i=1;i<=n;i++){
		for(j=1;j<=G.adj[i].size;j++){
			int h=element_at(&G.adj[i],j);
			printf("%d %d\n",i,h);
		}
	}
}
