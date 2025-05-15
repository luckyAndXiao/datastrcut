#include <iostream>
#include"Quene.h"
#include"cstack.h"
using namespace std;
#define MAX_VERTEX_NUM 20
#define  INFINITY 20

template<class T>
struct  Adj_Graph {

	T Vertex_List[MAX_VERTEX_NUM];//顶点表

	int Arc_List[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//邻接矩阵

	int Ver_Num;//顶点数

	int Arc_Num;//边数
};


template<class T>
class  Graph {//基于邻接矩阵的存储
private:

	Adj_Graph<T> graph;//定义一个图
	bool  kind;//图的类型
	bool visited[MAX_VERTEX_NUM];


	int arcNum();
	void BFS(int v);
	void DFS(int v);
	void Nore_DFS(int v);//非递归实现深度优先
	void visit(int v) {//访问顶点v
		cout << graph.Vertex_List[v];
	}

public:
	Graph(T * vertex, int* arc, int num, int kind);//初始化

	~Graph() {
		graph.Ver_Num = graph.Arc_Num = 0;
	}

	int InDegree(int v);//求入度
	
	int OutDegree(int v);//求出度
	
	int Get_Degree(int v);//求度
	
	void BFSTraverse();//广度优先
	
	void DFSTraverse();//深度优先

	
	void NoreDFSTraverse();
	
	void Top_Logical_Sort();
	
	void Prime();
	
	void Dijistra();
	
	void Floyd();

	int FirstNeighbor(int v);

	int  NextNeighbor(int v, int k);

	

};
template<class T>
void Graph<T>::NoreDFSTraverse()//非递归实现深度优先
{//初始化访问数组
	for (int i = 0; i < graph.Ver_Num; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < graph.Ver_Num; i++) {
		if (!visited[i]) {//如果未被访问，则广度优先搜索
			Nore_DFS(i);
		}
	}

}

template<class T>
void Graph<T>::Nore_DFS(int v) {
	int w = 0;
	int x = 0;
	SqStack<int>  s(graph.Ver_Num);//辅助栈

	visit(v);
	visited[v] = true;
	s.Push(v);
	w = FirstNeighbor(v);
/*

while (!s.StackEmpty()) {

		for(int w = FirstNeighbor(v); w > -1; w = NextNeighbor(v , w)) {
			if (!visited[w]) {
				visit(w);
				visited[w] = true;
				s.Push(w);
				break;
			}
		}
		v = s.Pop();
	}

*/
	while (!s.StackEmpty()) {//栈不为空

		if (!visited[w] ) {//未被访问就访问
			visit(w);
			visited[w] = true;
			s.Push(w);

			x = FirstNeighbor(w);
			if (x != -1) {
				w = x;
			}
		}
		else {//访问过或者，则回到上一个顶点
			v = s.Pop();
			 x = NextNeighbor(v, w);//上一个顶点，下一个邻接点
			if (x != -1) {
				w = x;
			}
			else {
				w = v;
			}
		}

		
		

	}



}
template<class T>
int Graph<T>::FirstNeighbor(int v) {
	//求v的第一个邻接点
	int neighbor = -1;
	for (int i = 0; i < graph.Ver_Num; i++) {
		if (graph.Arc_List[v][i] != 0 && graph.Arc_List[v][i] != INFINITY) {
			neighbor = i;
			break;
		}
	}

	return neighbor;
}
template<class T>
int Graph<T>::NextNeighbor(int v, int k) {
	//求v的第一个邻接点
	int neighbor = -1;
	for (int i = k+1; i < graph.Ver_Num; i++) {
		if (graph.Arc_List[v][i] != 0 && graph.Arc_List[v][i] != INFINITY) {
			neighbor = i;
			break;
		}
	}

	return neighbor;
}
template<class T>
void Graph<T>::BFSTraverse() {
	//初始化访问数组
	for (int i = 0; i < graph.Ver_Num; i++)
	{
			visited[i]= false;
	}

	for (int i = 0; i < graph.Ver_Num; i++) {
		if (!visited[i]) {//如果未被访问，则广度优先搜索
			BFS(i);
		}
	}


}

template<class T>
void Graph<T>::DFSTraverse() {
	//初始化访问数组
	for (int i = 0; i < graph.Ver_Num; i++)
	{
		visited[i] = false;
	}

	for (int i = 0; i < graph.Ver_Num; i++) {
		if (!visited[i]) {//如果未被访问，则广度优先搜索
			DFS(i);
		}
	}


}

template<class T>
void Graph<T>::DFS(int v) {//深度优先搜索	
		visit(v);//访问
		visited[v] = true;
		for (int k = FirstNeighbor(v); k > -1; k = NextNeighbor(v, k)) {
			if (!visited[k]) {
				DFS(k);
			}
	    }

}


template<class T>
void  Graph<T>::BFS(int v) {//广度优先搜索

	Quene<int> q(graph.Ver_Num);//辅助队列
	visit(v);//访问
	visited[v] = true;
	q.EnQuene(v);//入队

	while (!q.isEmpty()) {

		int w = q.DeQuene();

		for (int k = FirstNeighbor(w); k > -1; k = NextNeighbor(w, k)) {
			if (!visited[k]) {//未被访问过
				visit(k);
				visited[k] = true;
				q.EnQuene(k);
			}
		}

	}


}


template<class T>
int Graph<T>::OutDegree(int v) {
	int n = 0;
	for (int i = 0; i < graph.Ver_Num; i++) {
		if (graph.Arc_List[v][i] != 0 && graph.Arc_List[v][i] != INFINITY) {
			n++;
		}
	}
	return n;
}
template<class T>
int Graph<T>::InDegree(int v) {
	int n = 0;
	for (int i = 0; i < graph.Ver_Num; i++) {
		if (graph.Arc_List[i][v] != 0 && graph.Arc_List[i][v] != INFINITY) {
			n++;
		}
	}
	return n;
}

template<class T>
int Graph<T>::Get_Degree(int v) {//求某个顶点的度
	int degree = 0;
	if (kind) {
		degree = InDegree(v) + OutDegree(v);
	}
	else {
		degree = InDegree(v);
	}

	return degree;
}
template<class T>
Graph<T>:: Graph(T * vertex, int * arc, int num, int kind) {
	//标注图的类型
	this->kind = kind;
	
	for (int i = 0; i < num; i++) {
		
		graph.Vertex_List[i] = vertex[i];//初始化顶点表

		for (int j = 0; j < num; j++) {
			int pos = i * num + j;
			graph.Arc_List[i][j] = arc[pos];//初始化邻接矩阵

		}
	}

	graph.Ver_Num = num;
	graph.Arc_Num = arcNum();
}
template<class T>
int Graph<T>::arcNum() {//求边数
	int n = 0;
	for (int i = 0; i < graph.Ver_Num; i++) {

		for (int j = 0; i < graph.Ver_Num; i++) {
			if (graph.Arc_List[i][j] != 0 && graph.Arc_List[i][j] != INFINITY) {
				n++;
			}
		}

	}

		return n;
}
