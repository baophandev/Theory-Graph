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

//Ngan xep
typedef struct {
	int data[Max_Element];
	int size;
}Stack;

//Khoi tao ngan xep rong
void make_null_stack(Stack *stack){
	stack->size=0;
}
//Them mot phan tu vao ngan xep
void push_stack(Stack *stack,int x){
	stack->data[stack->size]=x;
	stack->size++;
}
//Lay mot phan tu trong stack
int top_stack(Stack *stack){
	return stack->data[stack->size-1];
}
//Xoa mot phan tu trong stack
void pop_stack(Stack *stack){
	stack->size--;
}
//Kt stack rong
int empty_stack(Stack *stack){
	return(stack->size==0);
	
}
//DFS 
List depth_first_search(Graph *G,int x){
	Stack S;
	make_null_stack(&S);
	push_stack(&S,x);
	List list_dfs;
	make_null(&list_dfs);
	//Khoi tao tat ca cac dinh chua duoc duyet
	int i,j;
	int mark[Max_Vertices];
	for(i=1;i<=G->n;i++)
		mark[i]=0;
	while(!empty_stack(&S)){
		int u=top_stack(&S);
		pop_stack(&S);
		if(mark[u]==1)
			continue;
		//printf("Duyet: %d\n",u);
		push_back(&list_dfs,u);
		mark[u]=1;
		List list=neighbors(G,u);
		for(i=1;i <= list.size;i++){
			int v=element_at(&list,i);
			if(mark[v]== 0)
				push_stack(&S,v);
		}
	}
	return list_dfs;
}
int main(){
	int i,j,n,m;
	Graph G;
	FILE* file=fopen("DFS.txt","r");
	fscanf(file,"%d%d",&n,&m);
	init_Graph(&G,n);
	int u,v,e;
	for(e=1;e<=m;e++){
		fscanf(file,"%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	fclose(file);
	int mark_dfs[Max_Vertices];
	for(i=1;i<=G.n;i++){
		mark_dfs[i]=0;
	}
	for(i=1;i<=G.n;i++){
		if(mark_dfs[i]==0){
			List dfs=depth_first_search(&G,i);
	    	for(j=1;j<=dfs.size;j++){
	    		int k=element_at(&dfs,j);
				printf("Duyet: %d\n",k);
				mark_dfs[k]=1;
			}
		}
	}

	printf("So dinh: %d\n",G.n);
	for(i=1;i<=G.n;i++){
		for(j=1;j<=G.n;j++)
			printf("%d ",G.A[i][j]);
		printf("\n");
	}
	for(i=1;i<=G.n;i++){
    	printf("Bac cua dinh %d la: %d\n",i,degree(&G,i));
	}
	printf("Danh sach lang gieng cua cac dinh trong do thi\n");
	for(i=1;i<=G.n;i++){
		List list=neighbors(&G,i);
		printf("Neighbors(%d): [ ",i);
		for(j=1;j<=list.size;j++){
			printf("%d ",element_at(&list,j));
		}
		printf("]\n");
	}
	return 0;
}
