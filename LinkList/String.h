#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
class  String {
private:
	char * str;
	int size;
	int len(char* s) {//求串长
		int i = 0;
		while (*s++) {
			i++;
		};
		return i;
	}
public:
	String(char * str) {
		this->str = str;
		size = len(str);
	}
	~String() {
		
	}
	int length() {
		return size;
	}

	int BF(char* s, char* t) {//模式匹配的暴力算法
		int s_len = len(s);
		int t_len = len(t);
		int i, j;
		for ( i = 0; i <= s_len - t_len; i++) {
			for (j = 0; j < t_len; j++) {
				if (s[i] == t[j]) {
					i++;
				}
				else {
					break;
				}
			}
			if (j == t_len) {
				return i - j + 1;
			}
		}
	
		return -1;

	}

	int B_Force(char* s, char* t) {//基于while,s为主串，t为模式串
		int i = 0, j = 0;
		int s_len = len(s);
		int t_len = len(t);

		while (i <= s_len - t_len) {
			  
			while(s[i] == t[j] && j < t_len) {
				i++, j++;
			}
			if (j == t_len) {
				return i - j + 1;
			}

			i = i - j + 1;
			j = 0;


		}


		return -1;

	}

	int BFmatching(char* s, char* t) {
		int i = 0, j = 0;
		int n = len(s);
		int m = len(t);

		while (i < n && j < m) {
			if (s[i] == t[j]) {
				i++, j++;
			}
			else {
				i = i - j + 1;
				j = 0;
			}
		}
		if (j >= m) {
			return i - j + 1;
		}

		return -1;

	}

	int * GetNext(char* t , int n) {//kmp求next数组
		int k = 0, j = 0;
		int* next = new int[n];
		next[j] = -1;
		k = next[j];

		while (j < n-1) {

			if (k==-1 || t[j] == t[k]) {
				j++;
				next[j] = k + 1;
				k = next[j];
				//改进的kmp,netval数组
				//if (t[j] == t[k]) {
				//	next[j] = next[k];
				//}
				
			}
			else {
				k = next[k];

			}

		}

		return next;
	}

	int KmpMatching(char* s, char* t) {
		int i = 0, j = 0;
		int n = len(s);
		int m = len(t);
		int* next = GetNext(t, m);

		while (i < n && j < m) {

			if(s[i] == t[j]) {
				i++, j++;
			}
			else {
				j = next[j];
				
			}

			if (j == -1) {
				i++;
				j = 0;
			}

		}

		delete next;

		if (j >= m) {
			return i - j + 1;
		}

		return -1;

	}








	void printNext(char* t) {

		int n = len(t);
		int* next = GetNext(t, n);

		int length = n*4+1;
		int  width = 3;
		cout << endl;
		cout << setfill('-') << left << setw(length) << "-" << endl;
		for (int i = 0; i < n; i++) {
			cout << "|" << setfill(' ') << left << setw(width) << i ;
		}
		cout << "|"<<endl<<setfill('-') << left << setw(length) << "-" << endl;
		for (int i = 0; i < n; i++) {
			cout << "|" << setfill(' ') << left << setw(width) << t[i];
		}
		cout << "|" << endl << setfill('-') << left << setw(length) << "-" << endl;
		for (int i = 0; i < n; i++) {
			cout << "|" << setfill(' ') << left << setw(width) << next[i];
		}
		cout << "|" << endl << setfill('-') << left << setw(length) << "-" << endl;

		delete next;

	}
	



};