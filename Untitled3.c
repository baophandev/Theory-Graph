#include <stdio.h>
#define MAX_VERTICES 100

//DO THI MA TRAN DINH - DINH

typedef struct{
	int n;
	int A[MAX_VERTICES][MAX_VERTICES];
}Graph;

void init_graph(Graph *G, int n){
	int i ,j;
	G->n = n;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++ )
			G->A[i][j] = 0;
	}
}

void add_edge(Graph *G, int x, int y){
	G->A[x][y] +=1 ;
	G->A[y][x] +=1 ;
}

int adjacent(Graph *G, int x, int y){
	return G->A[x][y] != 0;
}

int degree(Graph *G, int x){
	int y, deg = 0;
	for(y = 0; y<= G->n; y++){
		deg += G->A[x][y];
	}
	return deg;
}

int  main(){
	Graph G;
	int n, m, e, u, v;
	
	FILE *file = fopen("dothi2.txt", "r");
	fscanf(file , "%d%d", &n, &m);
	init_graph(&G, n);
	for(e=1 ; e<=m; e++){
		fscanf(file, "%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	for(v=1; v<= n; v++){
		printf("deg(%d) = %d\n", v, degree(&G, v));
	}
	return 0;
}
