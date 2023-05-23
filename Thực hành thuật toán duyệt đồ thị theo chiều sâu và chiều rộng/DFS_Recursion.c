#include <stdio.h>
#define Max_Vertices 20
#define Max_Length 20
typedef struct {
	int A[Max_Vertices][Max_Vertices];
	int n;
}Graph;
//Cau truc danh sach list
typedef struct  {
	int data[Max_Length];
	int size;
}List;

void make_null(List *list){
	list->size=0;
}

//Them phan tu vao cuoi danh sach
void push_back(List *list,int x){
	list->data[list->size] = x;
	list->size++;
}
//Lay mot phan tu (dinh) tai vi tri i
int element_at(List *list,int i){
	return list->data[i-1];
}
void init_Graph(Graph *G,int n){
	int i,j;
	G->n=n;
	for(i=1;i<=G->n;i++)
		for(j=1;j<=G->n;j++)
			G->A[i][j]=0;
}

void add_edge(Graph *G,int x,int y){
	G->A[x][y]=1;
	G->A[y][x]=1;
}

//Kiem tra co thong, co cung khum, lang gieng
int adjacent(Graph *G,int x,int y){
	return (G->A[x][y] != 0);
}
//Bac cua mot dinh
int degree(Graph *G,int x){
	int deg=0,i;
	for(i=1;i<=G->n;i++){
		if(G->A[i][x]==1)
			deg++;
	} 
	return deg;
}

//Tim tat ca lang gieng cua dinh x
List neighbors(Graph *G,int x){
	List L;
	int i;
	make_null(&L);
	for(i=1;i<=G->n;i++)
		if(G->A[i][x] == 1){
			push_back(&L,i);
		}
		return L;
}

int mark[Max_Vertices];
int parent[Max_Vertices];
void DFS_Recursion(Graph *G, int u,int p){
	if(mark[u] == 1)
		return;
//	printf("Duyet: %d\n",u);
	parent[u] = p;
	mark[u] = 1;
	List list=neighbors(G,u);
	int i;
	for(i=1;i<=list.size;i++){
		int v = element_at(&list,i);
		DFS_Recursion(G,v,u);
	}
}

int main(){
	int i,j,n,m;
	Graph G;
	freopen("DFS_Recursion.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_Graph(&G,n);
	int u,v;
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v); 
	} 
	
	for(i=1;i<=n;i++){
		mark[i] = 0;
		parent[i] = -1;
	}
	
	DFS_Recursion(&G,1,0);
	
	for(i=1;i<=n;i++)
		if(mark[i]==0)
			DFS_Recursion(&G,i,0);
	for(i=1;i<=n;i++)
		printf("%d %d\n",i,parent[i]);
//	printf("%d\n",adjacent(&G,3,4)); 
//
//	for(i=1;i<=G.n;i++){
//    	printf("Bac cua dinh %d la: %d\n",i,degree(&G,i));
//	}
//	printf("Danh sach lang gieng cua cac dinh trong do thi\n");
//	for(i=1;i<=G.n;i++){
//		List list=neighbors(&G,i);
//		printf("Neighbors(%d): [ ",i);
//		for(j=1;j<=list.size;j++){
//			printf("%d ",element_at(&list,j));
//		}
//		printf("]\n");
//	}
//	printf("So dinh: %d\n",G.n);
//	for(i=1;i<=G.n;i++){
//		for(j=1;j<=G.n;j++)
//			printf("%d ",G.A[i][j]);
//		printf("\n");
//	}
	return 0;
}
