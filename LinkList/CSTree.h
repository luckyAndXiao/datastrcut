#pragma once
#include<iostream>
#include<vector>
#include<string>

using namespace std;


//3.�����ֵܱ�ʾ��

template<class T>
struct CSNode {
	T data;

	int degree;

	CSNode<T>* firstchild, * nextsibling;

};

template<class T>
struct couple {//��ż��

	T parent;

	T child;
};

template<class T>

class CSTree {
private:
	CSNode<T>* root;

	void Free(CSNode<T>* p);
	void InsertNode(couple<T>& p);
	CSNode<T>* Search(CSNode<T>* p, T e);
	int Height(CSNode<T>* p);

	void Degree(CSNode<T>* p);

public:
	CSTree() {
		root = NULL;

	}
	~CSTree() {
		Free(root);
	}

	CSTree(vector<couple>& ps);//���Ĺ����㷨
	CSNode<T>* Search(T e) {

		Search(root, e);
	}

	int  Height() {
		return Height(root);
	}

	void Degree() {
		Degree(root);
	}




};

template<class T>

CSTree<T>::CSTree(vector<couple<T>>& ps) {

	if (ps.size() == 0) {
		root = NULL;
		return;
	}

	//���������
	root = new CSNode<T>;

	root->data = ps[0].parent;

	root->firstchild = root->nextsibling = NULL;

	//���������ÿ����ż�Ķ�Ӧ��ϵ
	for (i = 0; i < ps.size(); i++) {
		InsertNode(ps[i]);
	}


}
template<class T>
void CSTree<T>::InsertNode(couple<T>& p) {
	//�����½��
	CSNode<T>* child = new CSNode<T>;
	child->data = p.child;
	child->firstchild = child->nextsibling = NULL;

	//����p.parent�Ľ��

	CSNode<T>* parent = Search(p.parent);

	if (parent->fistchild = NULL) {

		parent->firstchild = child;

	}

	else {
		parent = parent->firstchild;
		while (parent->nextsibling != NULL) {
			parent = parent->nextsibling;
		}

		parent->nextsibling; = child;
	}

}

template<class T>

CSNode<T>* CSTree<T>::Search(CSNode<T>* p, T e) {
	if (p == NULL) {
		return NULL;
	}

	if (p->data == e) {
		return p;
	}
	CSNode<T>* q = Search(p->firstchild, e);

	if (q != NULL) {
		return q;
	}

	return Search(p->nextsibling);

}

template<class T>
int  CSTree<T>::Height(CSNode<T>* p) {
	int  height = 0;
	int maxheight = 0;

	if (p == NULL) {
		return 0;
	}
	for (p = p->firstchild; p; p = p->nextsibling) {
		height = Height(p);
		if (height > maxheight) {
			maxheight = height;
		}
	}


	return maxheight + 1;
}

template<class T>

void Degree(CSNode<T>* p) {
	if (p == NULL) {
		return;
	}
	p->degree = 0;
	CSNode<T>* q = NULL;

	for (q = p->firstchild; q; q = q->nextsibling) {
		p->degree++;
	}

	Degree(p->firstchild);

	Degree(p->nextsibling);
}


