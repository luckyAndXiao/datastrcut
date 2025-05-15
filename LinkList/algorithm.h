#pragma once

#include<iostream>
using namespace std;


//n个数的全排列

void swap(int& A, int& B) {
	int temp = A;
	A = B;
	B = temp;
}

void show(int* A, int n) {

	for (int i = 0; i < n; i++) {

		cout << A[i];
	}
	cout << endl;
}

void  EntireSort(int* A, int i ,  int n) {//固定元素，对其他进行全排列

	if (i == n - 1) {
		show(A, n);
	}
	else if (i >= n) return;
	

	for (int k = i; k < n; k++) {

		swap(A[k], A[i]);

		EntireSort(A, i + 1 , n);

		swap(A[k], A[i]);
	}
	
}

