#include <stdio.h>
#define MAX_VERTICES 100
#define MAX_EDGES 500
#define MAX_ELEMENTS 100

typedef int ElementType;

typedef struct{
    ElementType data[MAX_ELEMENTS];
    int size;
}List;

typedef struct{
    int n, m;
    int A[MAX_VERTICES][MAX_EDGES];
}Graph;

void init_graph(Graph *G, int n, int m){
    G->n = n;
    G->m = m;
    
    for(int i=0 ; i<=n; i++){
        for(int j =0; j<=m; j++){
            G->A[i][j] = 0;
        }
    }
}

void add_edge(Graph *G, int e, int x, int y){
    G->A[x][e] = 1;
    G->A[y][e] = 1;
}

int adjacent(Graph *G, int x, int y){
    int e;
    for(e=1 ; e<=G->m; e++){
        if(G->A[x][e] == 1 && G->A[y][e] == 1)
            return 1;
    }
    return 0;
}

int degree(Graph *G, int x){
    int deg = 0;
    for(int e = 1; e<= G->m; e++){  
        if(G->A[x][e] == 1)
            deg++;
    }
    return deg;
}

//Bac cao nhat
void count(Graph *G){
	int n, i, max = 0;
	for(i = 1 ; i<=G->n; i++){
		if(degree(G, i) >max){
			max = degree(G, i);
			n = i;
		}
	}
	printf("%d %d\n", n, max);
}

int main(){
    Graph G;
	int n, m, e, u, v;
	
	FILE *file = fopen("dothi.txt", "r");
	fscanf(file , "%d%d", &n, &m);
	init_graph(&G, n, m);
	for(e=1 ; e<=m; e++){
		fscanf(file, "%d%d", &u, &v);
		add_edge(&G, e, u, v);
	}
	
	for(v=1; v<= n; v++){
		printf("deg(%d) = %d\n", v, degree(&G, v));
	}
	
	count(&G);
	return 0;
}
