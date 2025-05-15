#pragma once




//��������

void  InsertSort(int* A, int n) {//ֱ�Ӳ�������
	int temp;
	int i, j;
	for (i = 1; i < n; i++) {
		temp = A[i];
		for (j = i - 1; j >= 0&& A[j] > temp; j--) {			
				A[j + 1] = A[j];
		}	
		A[j + 1] = temp;
	}
}

//�۰��������
void  HalfInsertSort(int* A, int n) {
	int temp;
	int i, j;
	int low, high , mid;
	for (i = 1; i < n; i++) {
		temp = A[i];
		low = 0; 
		high = i - 1;

		while (low <= high) {
			
			mid = (low + high) / 2;

			if (A[mid] > temp) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}

		}

		for (int k = i; k >low; k--) {
			A[k] = A[k - 1];
		}
		A[low] = temp;

	}

}

void  ShellSort(int* A, int n) {//ϣ������
	int i, j, d;
	int temp;
	for (d = n / 2; d >= 1; d = d / 2) {

		for (i = d; i < n; i += d) {

			temp = A[i];

			for (j = i - d; j >= 0&&A[j] > temp; j -= d) {
				
					A[j + d] = A[j];
				  
			}

			A[j + d] = temp;

		}

	}


}


void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

//��������

void   BubbleSort(int* A, int n) {

	int i, j;
	bool  flag = true;

	for ( i = 1; i < n ; i++) {
		for (j = 0; j < n - i; j++) {
			if (A[j + 1] < A[j]) {
				swap(A[j + 1], A[j]);
				flag = false;
			}
		}

		if (flag) {
			break;
		}

	 }
}

//��������

int   paritition(int* A, int low, int high) {//һ�˻���

	int pivot = A[low];

	while (low < high) {

		while (A[high] > pivot && low < high) {
			high--;
		}
		A[low] = A[high];
		while (A[low] <= pivot&& low < high) {
			low++;
		}

		A[high] = A[low];

	}

	A[low] = pivot;


	return low;
}

int paritition1(int* A, int low, int high) {
	
	int pivot = low;
	high++;
	do {

		do {
			low++;
		} while (A[low] < A[pivot]);

		do {
			high--;
		} while (A[high] > A[pivot]);


		if (low < high) {
			swap(A[low], A[high]);
		}

	} while (low < high);

	swap(A[pivot], A[high]);

	return high;
}


void  QuickSort(int* A, int low, int high) {

	if (low < high) {
		int pivotPos = paritition1(A, low, high);

		QuickSort(A, low, pivotPos - 1);

		QuickSort(A, pivotPos + 1, high);
	}

}


//ѡ������

//��ѡ������

void  SelectSort(int* A, int n) {
	int i, j, k;
	for (i = 0; i < n - 1; i++) {
		 k = i;
		for (j = i + 1; j < n; j++) {
			if (A[k] > A[j]) {
				k = j;
			}
		}
		if (k != i) {
			swap(A[i], A[k]);
		}
	
	}
}


//������

void  HeapAdjust(int* A, int k, int n) {

	
	for (int i = 2 * k; i <= n; i *=2) {

		if (i < n && A[i + 1] > A[i]) {//�ж��Ƿ����Һ��ӣ������ҵ����ĺ���
			i++;
			}
		if (A[i] > A[k]) {//�жϸ�������ӽ��Ĵ�С
			swap(A[k], A[i]);
			k = i;//ת�Ƶ�������������
		}
		else {
			break;
		}
	}


}

void  BuildMaxHeap(int* A, int n) {

	for (int i = n / 2; i > 0; i--) {

		HeapAdjust(A, i, n);

	}
}

void  HeapSort(int* A, int n) {

	BuildMaxHeap(A , n);

	for (int i = n ; i > 1; i--) {

		swap(A[1], A[i]);

		HeapAdjust(A, 1, i-1);
	}



}


//�鲢����

void Merge(int* A, int low, int mid, int high) {//��·�鲢
	int B[1024];
	int i = low , j = mid + 1, k = low;
	while (k <= high) {
		B[k] = A[k];
		k++;
	}
	for (k = low; i <= mid && j <= high; k++) {
		if (B[i] <= B[j]) {
			A[k] = B[i++];
		  }
		else {
			A[k] = B[j++];
		}
	}

	while (i <= mid) {
		A[k++] = B[i++];
	}
	while (j <= high) {
		A[k++] = B[j++];
	}


}

void   MergeSort(int* A, int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(A, low, mid);
		MergeSort(A, mid + 1, high);
		Merge(A, low,mid ,  high);
	}
}

