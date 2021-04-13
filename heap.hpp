#pragma once
#include <math.h>

#include <iostream>
using namespace std;

#ifndef HEAPHPP
#define HEAPHPP

//compare height of two nodes
//return true if 1>2, else return false
template <class T> 
bool Heap<T>::_isHigher(int index1, int index2) {
	if (index1 < _n && (_heap[index1] > _heap[index2]))
		return true; 
	else 
		return false;
}

//return index of parent
template <class T>
int Heap<T>::_parent(int index) {
	if (index == 0) {
		return index;
	} else {
		return (index - 1)/2;
	}
}

//return index of left child
template <class T>
int Heap<T>::_lChild(int index) {
	return (index * 2) + 1;
}

//return index of right child
template <class T>
int Heap<T>::_rChild(int index) {
	return (index * 2) + 2;
}

template <class T>
void Heap<T>::_swap(int index1, int index2) {
	T temp = _heap[index1];
	_heap[index1] = _heap[index2];
	_heap[index2] = temp;
}

template <class T>
void Heap<T>::_bubbleUp(int index) {
	//if parent bigger, do nothing
	//if (_heap[_parent(index)] < _heap[index])
	if (_isHigher(index, _parent(index))) 
	{
		_swap(_parent(index),index);
		_bubbleUp(_parent(index));
	}
}

template <class T>
void Heap<T>::_bubbleDown(int index) {
	//compare max of both children
	int l = _lChild(index); 
	int r = _rChild(index);
	int curr_max = index; //index of max 

	//if (l < _n && _heap[l] > _heap[index]) 
	if (_isHigher(l,index)) {
		curr_max = l;
	}
	//if (l < _n && _heap[r] > _heap[curr_max]) 
	if (_isHigher(r, curr_max)) {
		curr_max = r;
	}
	if (curr_max != index) {
		_swap(index, curr_max);
		_bubbleDown(curr_max);
	}
}

template <class T>
void Heap<T>::insert(T item) { 
	if (_n != DEFAULTHEAPSIZE) {
		_heap[_n] = item;
		_n++;
		_bubbleUp(_n-1);
	} else {
		cout << "overflow" << endl;
	}
}

template <class T>
T Heap<T>::extractMax() {
	T max = _heap[0];
	deleteItem(max);
	return max;
}


template <class T>
void Heap<T>::printHeapArray() {
	for (int i = 0; i < _n; i++)
		cout << _heap[i] << " ";
	cout << endl;
}

template <class T>
int Heap<T>::_lookFor(T x){ // not a very good implementation, but just use this for now.
    int i;
    for(i=0;i<_n;i++)
        if (!(x > _heap[i]) && !(_heap[i] > x))
            return i;
    
    return -1;
}

template <class T>
void Heap<T>::decreaseKey(T from, T to)
{
	int index = _lookFor(from);
	if (index != -1) {
		_heap[index] = to;
		_bubbleDown(index);	
	} else {
		cout << "element not found" << endl;
	}
}


template <class T>
void Heap<T>::increaseKey(T from, T to)
{
	int index = _lookFor(from);
	if (index != -1) {
		_heap[index] = to;
		_bubbleUp(index);	
	} else {
		cout << "element not found" << endl;
	}
}

template <class T>
void Heap<T>::deleteItem(T x)
{
	int index = _lookFor(x);
	if (index != -1) {
		_swap(index,_n-1);
		//_heap[_n-1] = 0;
		_n--;
		_bubbleDown(index);
		_bubbleUp(index);
	} else {
		cout << "element not found" << endl;
	}
}

template <class T>
void Heap<T>::printTree() {
    int parity = 0;
	if (_n == 0)
		return;
	int space = pow(2,1 + (int) log2f(_n)),i;
	int nLevel = (int) log2f(_n)+1;
	int index = 0,endIndex;
    int tempIndex;
	
	for (int l = 0; l < nLevel; l++)
	{
		index = 1;
        parity = 0;
		for (i = 0; i < l; i++)
			index *= 2;
		endIndex = index * 2 - 1;
		index--;
        tempIndex = index;
        while (index < _n && index < endIndex) {
            for (i = 0; i < space-1; i++)
                cout << " ";
            if(index==0)
                cout << "|";
            else if (parity)
                cout << "\\";
            else
                cout << "/";
            parity = !parity;
            for (i = 0; i < space; i++)
                cout << " ";
			index++;
		}
        cout << endl;
        index=tempIndex;
		while (index < _n && index < endIndex) {
			for (i = 0; i < (space-1-((int) log10(_heap[index]))); i++)
				cout << " ";
			cout << _heap[index];
			for (i = 0; i < space; i++)
				cout << " ";
			index++;
		}
		
		cout << endl;
		space /= 2;
	}

}






#endif
