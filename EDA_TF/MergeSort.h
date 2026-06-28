#pragma once
#include <vector>

template<typename T, typename Comparador>
void merge(std::vector<T>& A, int left, int mid, int right, Comparador comparar) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	vector<T> L(n1), R(n2);

	for (int i = 0; i < n1; i++)
		L[i] = A[left + i];

	for (int j = 0; j < n2; j++)
		R[j] = A[mid + 1 + j];

	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2) {
		if (comparar(L[i], R[j])) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		A[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		A[k] = R[j];
		j++;
		k++;
	}
}
template<typename T, typename Comparador>
void mergeSort(std::vector<T>& A, int left, int right, Comparador comparar) {
	if (left >= right) return;
	int mid = left + (right - left) / 2;
	mergeSort(A, left, mid, comparar);
	mergeSort(A, mid + 1, right, comparar);
	merge(A, left, mid, right, comparar);
}