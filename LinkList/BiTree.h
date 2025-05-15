#pragma once
#include<iostream>
#include"cstack.h"
#include"Quene.h"
#include<vector>
//������
//���
template<class T>
struct  BiNode {
	T data;//���ֵ

	BiNode* lchild, * rchild;//���Һ���ָ��
};


template<class T>
class   BiTree {
private:
	//��Ա����
	BiNode<T>* root;
	//˽�к���������Ա
	BiNode<T>* CreateByPre(vector<T>& pre, int& i);
	void PreOrder(BiNode<T>* p);//�������
	void Free(BiNode<T>* p);//ɾ����
	void InOrder(BiNode<T>* p);//�������
	void PostOrder(BiNode<T>* p);//�������
	void Copy(BiNode<T>* &root, BiNode<T>* p);
	BiNode<T> * Copy(BiNode<T>* p);//���ƹ��캯��
	BiNode<T>* CreateByPreMid(vector<T>& pre, vector<T> &mid, int ipre , int imid , int n);
	int Count(BiNode<T>* p);//����ڵ���


public:
	BiTree() {//���캯��
		this->root = NULL;
	}
	BiTree(vector<T>& pre);//�������й��������

	BiTree(vector<T>& pre, vector<T>& mid);//�����������������

	BiTree(BiTree<T>& tree);//�������캯��
	
	~BiTree();//��������

	void PreOrder();//�������

	void InOrder() {
		InOrder(this->root);
	}//�������

	void PostOrder() {
		PostOrder(this->root);
	};//�������
	void LevelOrder();//��α���

	int Count();//ͳ�ƽ�����
	int Height();//����������ĸ߶�
	BiNode<T>* Search(T e);//��ֵ����
	BiNode<T>* SearchParent(BiNode<T>* child);//����ָ�����ĸ����
	BiNode<T>* Root() {
		return this->root;
	}
	
	void  pre_order();//�ǵݹ��������
	void  in_order();//�ǵݹ���������
	void  post_order();//��������ķǵݹ��㷨


};

template<class T>
void BiTree<T>::post_order() {
	SqStack<BiNode<T>*> s(50);

	BiNode<T>* r = this->root;
	if (r == NULL) {
		return;
	}
   do{	
		if (r != NULL) {
			s.Push(r);
			r = r->lchild;
		}
		else {
			r = s.Pop();
			if (r == NULL) {
				r = s.Pop();
				cout << r->data;
				r = NULL;
			}
			else if (r->rchild == NULL) {
				cout << r->data;
				r = NULL;
			}
			else {
				s.Push(r);
				s.Push(NULL);
				r = r->rchild;
			}
		}

   } while (!s.StackEmpty());


}
template<class T>
void BiTree<T>::in_order() {
	SqStack<BiNode<T>* > s(50);//��ʼ��ջ
	BiNode<T>* r = this->root;
	s.Push(r);
	while (!s.StackEmpty()) {

		if (r->lchild != NULL) {
			r = r->lchild;
			s.Push(r);
		}
		else {
			r = s.Pop();
			cout << r->data;
			if (r->rchild) {
				r = r->rchild;
				s.Push(r);
			}
		}

	}




}



template<class T>
void BiTree<T>::pre_order() {
	SqStack<BiNode<T> * > s(50);//��ʼ��ջ
	BiNode<T>* r = this->root;
	if (r == NULL) {
		return;
	}
	s.Push(r);
	while (!s.StackEmpty()) {
		
		if (r!= NULL) {
			cout << r->data;
			r = r->lchild;
			if (r != NULL) {
				s.Push(r);
			}		
		}
		else {
			r = s.Pop();
			r = r->rchild;
			if (r != NULL) {
				s.Push(r);
			}
		}

	}

}


template<class T>
int BiTree<T>::Count() {
	return Count(root);
}

template<class T>
int BiTree<T>::Count(BiNode<T>* p) {
	if (p == NULL) {
		return 0;
	}
	int left = 0;
	int right = 0;
	left = Count(p->lchild);
	right = Count(p->rchild);

	return left + right + 1;
}
template<class T>
BiTree<T>::BiTree(vector<T>& pre, vector<T>& mid)//�����������������
{
	int n = pre.size();
	this->root = CreateByPreMid(pre, mid, 0, 0, 6);

}

template<class T>
void BiTree<T>::LevelOrder() {
	Quene< BiNode<T>* >  q(50);//��ʼ������
	if (root == NULL) {
		return;
	}
	q.EnQuene(root);

	while (!q.isEmpty()) {
		BiNode<T>* p = q.DeQuene();
		cout << p->data;
		if (p->lchild ) {
			q.EnQuene(p->lchild);
		}
		if (p->rchild) {
			q.EnQuene(p->rchild);
		}

	}

}




template<class T>
BiNode<T> * BiTree<T>::CreateByPreMid(vector<T>& pre, vector<T>& mid ,int ipre , int imid , int n)//�����������������
{
	if (n == 0) {
		return NULL;
	}
	int i = 0;
	T e = pre[ipre];//�����
	BiNode<T>* p = new BiNode<T>;//��������
	p->data = e;

	for ( i = 0; i < n; i++) {
		if (e == mid[imid + i]) {
			break;
		}
	}
	
	p->lchild = CreateByPreMid(pre, mid, ipre+1 ,imid, i );

	p->rchild = CreateByPreMid(pre, mid, ipre + i+ 1, imid + i + 1, n - i-1);

	return p;
	
}



template<class T>
BiTree<T>::BiTree(vector<T>&pre) {
	int i = 0;
	this->root = CreateByPre(pre, i);
}

template<class T>
void BiTree<T>::InOrder(BiNode<T>* p) {
	if (p == NULL) {
		return;
	}
	InOrder(p->lchild);
	cout << p->data;
	InOrder(p->rchild);
}

template<class T>
BiTree<T>::~BiTree() {
	Free(root);
}
template<class T>
void BiTree<T>::Free(BiNode<T>* p) {
	if (p == NULL) {
		return;
	}
	Free(p->lchild);
	Free(p->rchild);
	delete p;

}


template<class T>
BiNode<T> * BiTree<T>::CreateByPre(vector<T>& pre, int& i) {
	T e = pre[i];
	i++;
	if (e == '*') {
		return NULL;
	}
	
		BiNode<T>* p = new BiNode<T>();
		p->data = e;
		
		p->lchild = CreateByPre(pre, i);
		p->rchild = CreateByPre(pre, i);
	
	return p;
}

template<class T>
void BiTree<T>::PreOrder(BiNode<T>* p) {
	if (p == NULL) {
		return;
	}
	cout << p->data;
	PreOrder(p->lchild);
	PreOrder(p->rchild);

}

template<class T>
void BiTree<T>::PreOrder() {
		PreOrder(root);
	
}
template<class T>
void BiTree<T>::PostOrder(BiNode<T>* p) {
	if (p == NULL) {
		return;
	}

	PostOrder(p->lchild);
	PostOrder(p->rchild);
	cout << p->data;
}
template<class T>
BiTree<T>::BiTree(BiTree<T>& tree) {
	;//�������캯��
	this->root = Copy(tree.Root());
	//Copy(this->root, tree.Root());
}

template<class T>
void BiTree<T>::Copy(BiNode<T>* &root, BiNode<T>* p) {
	if (p == NULL) {
		root = NULL;
		return;
		  }
	root = new BiNode<T>;
	root->data = p->data;

	Copy(root->lchild, p->lchild);//����������
	Copy(root->rchild, p->rchild);//����������


}

template<class T>
BiNode<T>*  BiTree<T>::Copy(BiNode<T>* p) {
	if (p == NULL) {
		return NULL;
	}
	BiNode<T>* r = new BiNode<T>;
	r->data = p->data;

	r->lchild = Copy(p->lchild);//����������

	r->rchild = Copy(p->rchild);//����������

	return r;

};





//==================����������============================================



template<class T>
struct ThBiTNode {
	T data;	
	bool  ltag, rtag;
	ThBiTNode<T>* lchild, *rchild;
};
template<class T>
class  ThBiTree {
private:
	ThBiTNode<T>* root;
	ThBiTNode<T>* pre;


	void PreOrder(ThBiTNode<T>* p);//�������

	void Free(ThBiTNode<T>* p);//ɾ����

	void InOrder(ThBiTNode<T>* p);//�������

	void PostOrder(ThBiTNode<T>* p);//�������

	ThBiTNode<T>* CreateByMidPost(vector<T>& mid, vector<T>& post, int imid, int ipost, int n);//��������������

	void InThreading(ThBiTNode<T>* & p);//��������������
public:
	ThBiTree() {
		root = NULL;
		pre = NULL;
	}
	ThBiTree(vector<T>& mid, vector<T>& post)//����Ӻ����������
	{
		this->pre = NULL;
		int n = mid.size();

		this->root = CreateByMidPost(mid, post, 0, n - 1, n);
	}
	~ThBiTree() {
		//Free(this->root);
	}

	void PreOrder() {
		PreOrder(this->root);
	};//�������

	void InOrder() {
		InOrder(this->root);
	}//�������

	void PostOrder() {
		PostOrder(this->root);
	};//�������

	void  InThreaded() {//��������������
		this->pre = NULL;
		InThreading(this->root);

	}
	void InOrderThead();//�������
	ThBiTNode<T>* GetNext(ThBiTNode<T>* p);//������
	ThBiTNode<T>* GetPre(ThBiTNode<T>* p);//����ǰ��


};

template<class T>
ThBiTNode<T>* ThBiTree<T>::GetNext(ThBiTNode<T>* p) {
	if (p == NULL) {
		return NULL;
	}
	 
	if (p->rtag == 1) {
		return p->rchild;
	}
	p = p->rchild;

	while (p->ltag == 0) {
		p = p->lchild;
	}
	return p;
}
template<class T>
ThBiTNode<T>* ThBiTree<T>::GetPre(ThBiTNode<T>* p) {

	if (p == NULL) {
		return NULL;
	}

	if (p->ltag == 1) {
		return p->lchild;
	}
	p = p->lchild;

	while (p->rtag == 0) {
		p = p->rchild;
	}

	return p;

}


template<class T>
void ThBiTree<T>::InOrderThead() {

	ThBiTNode<T>* p = this->root;
	if (p == NULL) {
		return;
   }

	while (p->ltag == 0) {//�ҵ��������
		p = p->lchild;
	}
	while (p != NULL) {
		cout << p->data;
		p = GetNext(p);
		
	}
}



template<class T>
void ThBiTree<T>::InThreading(ThBiTNode<T>* & p) {

	if (p == NULL) {
		return;//pΪ�գ������
	}

	InThreading(p->lchild);//������������
	
	if (p->lchild == NULL) {//������Ϊ�գ�ָ��ǰ��
		p->ltag = 1;
		p->lchild = pre;
	}

	if (p->rchild == NULL) {
		p->rtag = 1;
	}
    
	if (pre != NULL) {//������Ϊ�գ�ָ����
		if (pre->rtag == 1) {
			pre->rchild = p;
		}
	}

	pre = p;

	InThreading(p->rchild);//������������
	
}


template<class T>
void ThBiTree<T>::PreOrder(ThBiTNode<T>* p)//�������
{
	if (p==NULL) {//��Ϊ��������������
		return;
	}
	cout << p->data;//���ʸ����
	PreOrder(p->lchild);//����������
	PreOrder(p->rchild);//����������

}
template<class T>
void ThBiTree<T>::Free(ThBiTNode<T>* p)//ɾ����
{
	if (p == NULL) {//��Ϊ��������������
		return;
	}

	Free(p->lchild);//ɾ��������
	Free(p->rchild);//ɾ��������
	
	delete p;
}
template<class T>
void ThBiTree<T>::InOrder(ThBiTNode<T>* p)//�������
{
	if (p == NULL) {//��Ϊ��������������
		return;
	}
	
	InOrder(p->lchild);//����������
	cout << p->data;//���ʸ����
	InOrder(p->rchild);//����������

}
template<class T>
void ThBiTree<T>::PostOrder(ThBiTNode<T>* p)//�������
{
	if (p == NULL) {//��Ϊ��������������
		return;
	}
	
	PostOrder(p->lchild);//����������
	PostOrder(p->rchild);//����������
	cout << p->data;//���ʸ����

}
template<class T>
ThBiTNode<T> *  ThBiTree<T>::CreateByMidPost(vector<T>& mid, vector<T>& post, int imid, int ipost, int n)
{
	if (n == 0) {
		return NULL;
	}
	ThBiTNode<T>* p = new ThBiTNode<T>;
	T r = post[ipost];//��λ�����
	int i;
	p->data = r;
	p->ltag = p->rtag = 0;
	//�����������ж�λ�����
	for ( i = 0; i < n; i++) {
		if (r == mid[imid + i]) {
			break;
		}
	}
	
	p->lchild = CreateByMidPost(mid, post, imid, ipost - n +  i, i);

	p->rchild = CreateByMidPost(mid, post, imid + i + 1, ipost-1, n-i-1);

		return p;
 
}


//=========================================================���Ĵ洢�ṹ======================================================================

//=========1���������ʾ��
struct CTNode {
	int child;//�������±�

	CTNode* next;//��һ���ֵ���������λ��
};

template<class T>
struct CTBox {
	T data;//���������ʾ��

	CTNode* next;//��һ�����ӵĵ�ַ
};

//2.˫�ױ�ʾ��

template<class T>
struct  PTNode {
	T data;//���ֵ

	int parent;//˫��λ��
};






//====================================================================================================
