#pragma once
#include<iostream>
#include"cstack.h"
#include"Quene.h"
#include<vector>
//二叉树
//结点
template<class T>
struct  BiNode {
	T data;//结点值

	BiNode* lchild, * rchild;//左右孩子指针
};


template<class T>
class   BiTree {
private:
	//成员变量
	BiNode<T>* root;
	//私有函数函数成员
	BiNode<T>* CreateByPre(vector<T>& pre, int& i);
	void PreOrder(BiNode<T>* p);//先序遍历
	void Free(BiNode<T>* p);//删除树
	void InOrder(BiNode<T>* p);//中序遍历
	void PostOrder(BiNode<T>* p);//后序遍历
	void Copy(BiNode<T>* &root, BiNode<T>* p);
	BiNode<T> * Copy(BiNode<T>* p);//复制构造函数
	BiNode<T>* CreateByPreMid(vector<T>& pre, vector<T> &mid, int ipre , int imid , int n);
	int Count(BiNode<T>* p);//计算节点数


public:
	BiTree() {//构造函数
		this->root = NULL;
	}
	BiTree(vector<T>& pre);//先序序列构造二叉树

	BiTree(vector<T>& pre, vector<T>& mid);//由先序、中序构造二叉树

	BiTree(BiTree<T>& tree);//拷贝构造函数
	
	~BiTree();//析构函数

	void PreOrder();//先序遍历

	void InOrder() {
		InOrder(this->root);
	}//中序遍历

	void PostOrder() {
		PostOrder(this->root);
	};//后序遍历
	void LevelOrder();//层次遍历

	int Count();//统计结点个数
	int Height();//计算二叉树的高度
	BiNode<T>* Search(T e);//按值查找
	BiNode<T>* SearchParent(BiNode<T>* child);//查找指定结点的父结点
	BiNode<T>* Root() {
		return this->root;
	}
	
	void  pre_order();//非递归先序遍历
	void  in_order();//非递归的中序遍历
	void  post_order();//后序遍历的非递归算法


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
	SqStack<BiNode<T>* > s(50);//初始化栈
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
	SqStack<BiNode<T> * > s(50);//初始化栈
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
BiTree<T>::BiTree(vector<T>& pre, vector<T>& mid)//由先序、中序构造二叉树
{
	int n = pre.size();
	this->root = CreateByPreMid(pre, mid, 0, 0, 6);

}

template<class T>
void BiTree<T>::LevelOrder() {
	Quene< BiNode<T>* >  q(50);//初始化队列
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
BiNode<T> * BiTree<T>::CreateByPreMid(vector<T>& pre, vector<T>& mid ,int ipre , int imid , int n)//由先序、中序构造二叉树
{
	if (n == 0) {
		return NULL;
	}
	int i = 0;
	T e = pre[ipre];//根结点
	BiNode<T>* p = new BiNode<T>;//构造根结点
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
	;//拷贝构造函数
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

	Copy(root->lchild, p->lchild);//构造左子树
	Copy(root->rchild, p->rchild);//构造右子树


}

template<class T>
BiNode<T>*  BiTree<T>::Copy(BiNode<T>* p) {
	if (p == NULL) {
		return NULL;
	}
	BiNode<T>* r = new BiNode<T>;
	r->data = p->data;

	r->lchild = Copy(p->lchild);//复制左子树

	r->rchild = Copy(p->rchild);//复制右子树

	return r;

};





//==================线索二叉树============================================



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


	void PreOrder(ThBiTNode<T>* p);//先序遍历

	void Free(ThBiTNode<T>* p);//删除树

	void InOrder(ThBiTNode<T>* p);//中序遍历

	void PostOrder(ThBiTNode<T>* p);//后序遍历

	ThBiTNode<T>* CreateByMidPost(vector<T>& mid, vector<T>& post, int imid, int ipost, int n);//中序后序构造二叉树

	void InThreading(ThBiTNode<T>* & p);//中序线索二叉树
public:
	ThBiTree() {
		root = NULL;
		pre = NULL;
	}
	ThBiTree(vector<T>& mid, vector<T>& post)//中序加后序构造二叉树
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
	};//先序遍历

	void InOrder() {
		InOrder(this->root);
	}//中序遍历

	void PostOrder() {
		PostOrder(this->root);
	};//后序遍历

	void  InThreaded() {//中序线索二叉树
		this->pre = NULL;
		InThreading(this->root);

	}
	void InOrderThead();//中序遍历
	ThBiTNode<T>* GetNext(ThBiTNode<T>* p);//中序后继
	ThBiTNode<T>* GetPre(ThBiTNode<T>* p);//中序前驱


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

	while (p->ltag == 0) {//找到中序起点
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
		return;//p为空，则结束
	}

	InThreading(p->lchild);//线索化左子树
	
	if (p->lchild == NULL) {//左子树为空，指向前驱
		p->ltag = 1;
		p->lchild = pre;
	}

	if (p->rchild == NULL) {
		p->rtag = 1;
	}
    
	if (pre != NULL) {//右子树为空，指向后继
		if (pre->rtag == 1) {
			pre->rchild = p;
		}
	}

	pre = p;

	InThreading(p->rchild);//线索化右子树
	
}


template<class T>
void ThBiTree<T>::PreOrder(ThBiTNode<T>* p)//先序遍历
{
	if (p==NULL) {//若为空树，结束遍历
		return;
	}
	cout << p->data;//访问根结点
	PreOrder(p->lchild);//访问左子树
	PreOrder(p->rchild);//访问右子树

}
template<class T>
void ThBiTree<T>::Free(ThBiTNode<T>* p)//删除树
{
	if (p == NULL) {//若为空树，结束遍历
		return;
	}

	Free(p->lchild);//删除左子树
	Free(p->rchild);//删除右子树
	
	delete p;
}
template<class T>
void ThBiTree<T>::InOrder(ThBiTNode<T>* p)//中序遍历
{
	if (p == NULL) {//若为空树，结束遍历
		return;
	}
	
	InOrder(p->lchild);//访问左子树
	cout << p->data;//访问根结点
	InOrder(p->rchild);//访问右子树

}
template<class T>
void ThBiTree<T>::PostOrder(ThBiTNode<T>* p)//后序遍历
{
	if (p == NULL) {//若为空树，结束遍历
		return;
	}
	
	PostOrder(p->lchild);//访问左子树
	PostOrder(p->rchild);//访问右子树
	cout << p->data;//访问根结点

}
template<class T>
ThBiTNode<T> *  ThBiTree<T>::CreateByMidPost(vector<T>& mid, vector<T>& post, int imid, int ipost, int n)
{
	if (n == 0) {
		return NULL;
	}
	ThBiTNode<T>* p = new ThBiTNode<T>;
	T r = post[ipost];//定位根结点
	int i;
	p->data = r;
	p->ltag = p->rtag = 0;
	//在中序序列中定位根结点
	for ( i = 0; i < n; i++) {
		if (r == mid[imid + i]) {
			break;
		}
	}
	
	p->lchild = CreateByMidPost(mid, post, imid, ipost - n +  i, i);

	p->rchild = CreateByMidPost(mid, post, imid + i + 1, ipost-1, n-i-1);

		return p;
 
}


//=========================================================树的存储结构======================================================================

//=========1孩子链表表示法
struct CTNode {
	int child;//在数组下标

	CTNode* next;//下一个兄弟在数组中位置
};

template<class T>
struct CTBox {
	T data;//孩子链表表示法

	CTNode* next;//下一个孩子的地址
};

//2.双亲表示法

template<class T>
struct  PTNode {
	T data;//结点值

	int parent;//双亲位置
};






//====================================================================================================
