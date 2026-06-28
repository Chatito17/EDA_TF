#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T, typename Compara>
void maxHeapify(vector<T>& v, int n, int i, Compara comp) {
    int mayor = i;
    int izq = 2 * i + 1;
    int der = 2 * i + 2;
    
    if (izq < n && comp(v[mayor], v[izq])) mayor = izq;
    if (der < n && comp(v[mayor],v[izq])) mayor = der;


    if (mayor != i) {
        swap(v[i], v[mayor]);
        maxHeapify(v, n, mayor, comp);
    }
}

template<typename T, typename Compara>
void buildMaxHeap(vector<T>& v, Compara comp) {
    int n = v.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(v, n, i, comp);
    }
}

template<typename T, typename Compara>
void minHeapify(vector<T>& v, int n, int i, Compara comp) {
    int menor = i;
    int izq = 2 * i + 1;
    int der = 2 * i + 2;

    if (izq < n && comp(v[izq], v[menor])) menor = izq;
    if (der < n && comp(v[der],v[menor])) menor = der;


    if (menor != i) {
        swap(v[i], v[menor]);
        minHeapify(v, n, menor, comp);
    }
}

template<typename T, typename Compara>
void buildMinHeap(vector<T>& v, Compara comp) {
    int n = v.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(v, n, i, comp);
    }
}

template<typename T, typename Compara>
void heapSortMenorAMayor(vector<T>& v, Compara comp) {
    buildMaxHeap(v, comp);
    int n = v.size();
    for (int i = n - 1; i > 0; i--) {
        swap(v[0], v[i]);
        maxHeapify(v, i, 0, comp);
    }
}

template<typename T, typename Compara>
void heapSortMayorAMenor(vector<T>& v, Compara comp) {
    buildMinHeap(v, comp);
    int n = v.size();
    for (int i = n - 1; i > 0; i--) {
        swap(v[0], v[i]);
        minHeapify(v, i, 0, comp);
    }
}
