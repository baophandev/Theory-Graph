#include <stdio.h>
#define Max_Vertices 20
#define Max_Length 20
#define Max_Element 40
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
///Duyet chieu sau 

//Hang doi
typedef struct {
	int data[Max_Element];
	int font;
	int rear;
}Queue;

//Khoi tao hang doi rong
void make_null_queue(Queue *queue){
	queue->font=0;
	queue->rear=-1;
}
//Them mot phan tu vao hang doi
void push_queue(Queue *queue,int x){
	queue->rear++;
	queue->data[queue->rear]=x;
}
//Lay mot phan tu trong queue
int top_queue(Queue *queue){
	return queue->data[queue->font];
}
//Xoa mot phan tu trong queue
void pop_queue(Queue *queue){
	queue->font++;
}
//Kt queue rong
int empty_queue(Queue *queue){
	return(queue->font>queue->rear);
	
}
//DFS 
List breath_first_search(Graph *G,int x){
	Queue Q;
	make_null_queue(&Q);
	int i,j;
	int mark[Max_Vertices];
	for(i=1;i<=G->n;i++)
		mark[i]=0;
	push_queue(&Q,x);
	List L_bfs;
	make_null(&L_bfs);
	while(!empty_queue(&Q)){
		int u=top_queue(&Q);
		pop_queue(&Q);
		if(mark[u]==1)
			continue;
		push_back(&L_bfs,u);
		mark[u]=1;
		List list=neighbors(G,u);
		for(i=1;i <= list.size;i++){
			int v=element_at(&list,i);
			if(mark[v]== 0)
				push_queue(&Q,v);
		}
	}
	return L_bfs;
}
int main(){
	int i,j,n,m,x;
	Graph G;
	freopen("BFS.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_Graph(&G,n);
	int u,v,e;
	for(e=1;e<=m;e++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	int mark_bfs[Max_Vertices];
	for(x=1;x<=G.n;x++){
		mark_bfs[x]=0;	
	}
	for (x=1;x<=G.n;x++){
		if(mark_bfs[x]==0){
			List L = breath_first_search(&G,x);
			for(i=1;i<=L.size;i++){
				int y=element_at(&L,i);
				printf("%d\n",y);
				mark_bfs[y]=1;
			}
		}
	}
//	printf("So dinh: %d\n",G.n);
//	for(i=1;i<=G.n;i++){
//		for(j=1;j<=G.n;j++)
//			printf("%d ",G.A[i][j]);
//		printf("\n");
//	}
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

	return 0;
}
