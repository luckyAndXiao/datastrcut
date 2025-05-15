#pragma once
#include<iostream>
#include<vector>
#include<string>

using namespace std;


//Huffman数的构造

struct HuffmanNode {
	char data;

	double weight;

	int parent, lchild, rchild;
};

class HuffmanTree {
private:
	vector<HuffmanNode> hufftree;
	int n;

	void SelectSmall(int& least, int& less, int i);
public:
	HuffmanTree(vector<HuffmanNode>& leafs);

	vector<int> GetCode(int i);

	string Decode(vector<int>& source);

};


HuffmanTree::HuffmanTree(vector<HuffmanNode>& leafs) {

	n = leafs.size();

	hufftree.resize(2 * n - 1);

	for (int i = 0; i < n; i++) {

		hufftree[i].data = leafs[i].data;

		hufftree[i].weight = leafs[i].weight;

		hufftree[i].parent = hufftree[i].rchild = hufftree[i].lchild = -1;

	}

	for (int i = n; i < 2 * n - 1; i++) {

		int least, less;

		SelectSmall(least, less, i);

		hufftree[least].parent = hufftree[less].parent = i;

		hufftree[i].parent = -1;

		hufftree[i].lchild = least;

		hufftree[i].rchild = less;

		hufftree[i].weight = hufftree[least].weight + hufftree[i].weight;


	}

}

void HuffmanTree::SelectSmall(int& least, int& less, int n) {

	least = less = -1;
	for (int i = 0; i < n; i++) {
		if (hufftree[i].parent == -1) {

			if (least == -1) {
				least = i;
			}

			else if (hufftree[i].weight < hufftree[least].weight) {

				least = i;

			}
		}

	}

	for (int i = 0; i < n; i++) {

		if (hufftree[i].parent == -1 && hufftree[i].weight > hufftree[least].weight) {

			if (less == -1) {
				less = i;
			}

			else if (hufftree[i].weight < hufftree[less].weight) {

				less = i;

			}

		}


	}


}





vector<int> HuffmanTree::GetCode(int i) {
	vector<int> code;
	int p = i;

	int parent = hufftree[i].parent;

	while (parent != -1) {
		if (hufftree[parent].lchild = p) {
			code.insert(code.begin(), 0);
	     }
		else {
			code.insert.(code.begin(), 1);
		}

		p = parent;
		parent = hufftree[parent].parent;
	}
	return code;
}

string HuffmanTree::Decode(vector<int>& source) {
	string target = "";
	int root = hufftree.size() - 1;

	p = root;

	for (int i = 0; i < source.size(); i++) {
		if (source[i] == 0) {
			p = hufftree[p].lchild;
		}
		else {
			p = hufftree[p].rchild;
		}

		if (hufftree[p].lchild = -1 && hufftree[p].rchild == -1) {
			target = target + hufftree[i].data;
			p = root;
		}
	}

	return target;
}

