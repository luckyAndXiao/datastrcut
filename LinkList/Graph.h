#include <iostream>
#include"Quene.h"
#include"cstack.h"
using namespace std;
#define MAX_VERTEX_NUM 20
#define  INFINITY 20

template<class T>
struct  Adj_Graph {

	T Vertex_List[MAX_VERTEX_NUM];//�����

	int Arc_List[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ڽӾ���

	int Ver_Num;//������

	int Arc_Num;//����
};


template<class T>
class  Graph {//�����ڽӾ���Ĵ洢
private:

	Adj_Graph<T> graph;//����һ��ͼ
	bool  kind;//ͼ������
	bool visited[MAX_VERTEX_NUM];


	int arcNum();
	void BFS(int v);
	void DFS(int v);
	void Nore_DFS(int v);//�ǵݹ�ʵ���������
	void visit(int v) {//���ʶ���v
		cout << graph.Vertex_List[v];
	}

public:
	Graph(T * vertex, int* arc, int num, int kind);//��ʼ��

	~Graph() {
		graph.Ver_Num = graph.Arc_Num = 0;
	}

	int InDegree(int v);//�����
	
	int OutDegree(int v);//�����
	
	int Get_Degree(int v);//���
	
	void BFSTraverse();//�������
	
	void DFSTraverse();//�������

	
	void NoreDFSTraverse();
	
	void Top_Logical_Sort();
	
	void Prime();
	
	void Dijistra();
	
	void Floyd();

	int FirstNeighbor(int v);

	int  NextNeighbor(int v, int k);

	

};
template<class T>
void Graph<T>::NoreDFSTraverse()//�ǵݹ�ʵ���������
{//��ʼ����������
	for (int i = 0; i < graph.Ver_Num; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < graph.Ver_Num; i++) {
		if (!visited[i]) {//���δ�����ʣ�������������
			Nore_DFS(i);
		}
	}

}

template<class T>
void Graph<T>::Nore_DFS(int v) {
	int w = 0;
	int x = 0;
	SqStack<int>  s(graph.Ver_Num);//����ջ

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
	while (!s.StackEmpty()) {//ջ��Ϊ��

		if (!visited[w] ) {//δ�����ʾͷ���
			visit(w);
			visited[w] = true;
			s.Push(w);

			x = FirstNeighbor(w);
			if (x != -1) {
				w = x;
			}
		}
		else {//���ʹ����ߣ���ص���һ������
			v = s.Pop();
			 x = NextNeighbor(v, w);//��һ�����㣬��һ���ڽӵ�
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
	//��v�ĵ�һ���ڽӵ�
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
	//��v�ĵ�һ���ڽӵ�
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
	//��ʼ����������
	for (int i = 0; i < graph.Ver_Num; i++)
	{
			visited[i]= false;
	}

	for (int i = 0; i < graph.Ver_Num; i++) {
		if (!visited[i]) {//���δ�����ʣ�������������
			BFS(i);
		}
	}


}

template<class T>
void Graph<T>::DFSTraverse() {
	//��ʼ����������
	for (int i = 0; i < graph.Ver_Num; i++)
	{
		visited[i] = false;
	}

	for (int i = 0; i < graph.Ver_Num; i++) {
		if (!visited[i]) {//���δ�����ʣ�������������
			DFS(i);
		}
	}


}

template<class T>
void Graph<T>::DFS(int v) {//�����������	
		visit(v);//����
		visited[v] = true;
		for (int k = FirstNeighbor(v); k > -1; k = NextNeighbor(v, k)) {
			if (!visited[k]) {
				DFS(k);
			}
	    }

}


template<class T>
void  Graph<T>::BFS(int v) {//�����������

	Quene<int> q(graph.Ver_Num);//��������
	visit(v);//����
	visited[v] = true;
	q.EnQuene(v);//���

	while (!q.isEmpty()) {

		int w = q.DeQuene();

		for (int k = FirstNeighbor(w); k > -1; k = NextNeighbor(w, k)) {
			if (!visited[k]) {//δ�����ʹ�
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
int Graph<T>::Get_Degree(int v) {//��ĳ������Ķ�
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
	//��עͼ������
	this->kind = kind;
	
	for (int i = 0; i < num; i++) {
		
		graph.Vertex_List[i] = vertex[i];//��ʼ�������

		for (int j = 0; j < num; j++) {
			int pos = i * num + j;
			graph.Arc_List[i][j] = arc[pos];//��ʼ���ڽӾ���

		}
	}

	graph.Ver_Num = num;
	graph.Arc_Num = arcNum();
}
template<class T>
int Graph<T>::arcNum() {//�����
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
