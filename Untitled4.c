#include <stdio.h>
#define MAX_ELEMENTS 100
#define MAX_VERTICES 100


typedef int ElementType;

typedef struct{
	ElementType data[MAX_ELEMENTS];
	int size;
}List;


typedef struct{
	int n;
	List adj[MAX_VERTICES];
}Graph; 

//Tao danh sach rong
void make_null(List *L){
	L->size = 0;
}

//Them 1 phan tu vao cuoi danh sach
void push_back(List *L, ElementType x){
	L->data[L->size] = x;
	L->size++;
}

//Lay phan tu tai vi tri i
ElementType element_at(List *L, int i){
	return L->data[i-1];
}

//Tra ve so phan tu cua danh sach
int  cout_list(List *L){
	return L->size;
}

List neighbors(Graph *G, int x){
	int y;
	List list;
	make_null(&list);
	for(y = 1; y<=G->n ; y++){
		if(adjacent(G, x, y))
			push_back(&list, y);
	}
	return list;
}

void init_graph(Graph *G, int n){
	int i, j;
	G->n = n;
	for(i=1 ; i<=n ;i++){
		make_null(&G->adj[i]);
	}
}

int adjacent(Graph *G, int x, int y){
	int j;
	for(j=1; j<= G->adj[x].size; j++){
		if(element_at(&G->adj[x], j) == y)
			return 1;
	}
	return 0;
}

void add_edge(Graph* G, int x, int y) {
push_back(&G->adj[x], y); //y ke v?i x
push_back(&G->adj[y], x); //x ke voi y
}

int degree(Graph *G, int x){
	return G->adj[x].size;
}

int main(){
	Graph G;
	int n = 4, v;
	init_graph(&G, n);
	add_edge(&G, 1, 2);
	add_edge(&G, 1, 3);
	add_edge(&G, 1, 3);
	add_edge(&G, 3, 4);
	add_edge(&G, 1, 4);
	for (v = 1; v <= n; v++)
		printf("deg(%d) = %d\n", v, degree(&G, v));
	return 0;
}
