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

void push_back(List *L, ElementType x){
	L->data[L->size] = x;
	L->size++;
}

ElementType element_at(List *L, int i){
	return L->data[i-1];
}

int count_list(List *L){
	return L->size;
}

int adjacent(Graph *G, int x, int y){
	int j;
	for(j = 1; j<= G->adj[x].size; j++){
		if(element_at(&G->adj[x], j) == j)
			return 1;
	}
	return 0;
}


// Tim cac dinh ke cua dinh x
List neighbors(Graph *G, int x){
	int y;
	List list;
	make_null(&list);
	for(y =1 ; y<= G->n ; y++){
		if(adjacent(G, x, y))
			push_back(&list , y);
	}
	return list;
}

//Khoi tao do thi co n dinh
void init_graph(Graph *G, int n){
	int i, j;
	G->n = n;
	for(i = 1; i<= n ; i++){
		make_null(&G->adj[i]);
	}
}

//Them cung e(x, y) vao do thi
void add_edge(Graph *G, int x, int y){
	push_back(&G->adj[x], y); //y ke voi x
	push_back(&G->adj[y], x); //x ke voi y
}

//Kiem tra y co ke voi x khong 

int degree(Graph *G, int x){
	return G->adj[x].size;
}

int main(){
//	Graph G;
//	int n = 4, v;
//	init_graph(&G, n);
//	add_edge(&G, 1, 2);     //Cach nhap truc tiep
//	add_edge(&G, 1, 3);
//	add_edge(&G, 1, 3);
//	add_edge(&G, 3, 4);
//	add_edge(&G, 1, 4);
//	for (v = 1; v <= n; v++)
//		printf("deg(%d) = %d\n", v, degree(&G, v));
//	return 0;

	Graph G;
	int n, m , e, u , v;
	FILE *file = fopen("dothi.txt", "r");
	fscanf(file , "%d%d", &n, &m);
	init_graph(&G, n);
	for(e=1; e<n ; e++){
		fscanf(file ,"%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	for(v=1; v<= n ; v++){
		printf("deg(%d) = %d\n", v, degree(&G, v));
	}
	return 0;
}
