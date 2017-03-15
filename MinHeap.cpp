#include "stdafx.h"
#include "MinHeap.h"

MinHeap::MinHeap(int* array, int length) : _vector(length)
{
	for (int i = 0; i < length; ++i)
	{
		_vector[i] = array[i];
	}

	Heapify();
}

MinHeap::MinHeap(const vector<int>& vector) : _vector(vector)
{
	Heapify();
}


MinHeap::MinHeap()
{
}

void MinHeap::Heapify()
{
	int length = active_vector_size;
	for (int i = length - 1; i >= 0; --i)
	{
		BubbleDown(i);
	}
}

void MinHeap::BubbleDown(int index)
{
	int length = active_vector_size;
	int leftChildIndex = 2 * index + 1;
	int rightChildIndex = 2 * index + 2;

	if (leftChildIndex >= length)
		return; //index is a leaf

	int minIndex = index;

	if (_vector[index] > _vector[leftChildIndex])
	{
		minIndex = leftChildIndex;
	}

	if ((rightChildIndex < length) && (_vector[minIndex] > _vector[rightChildIndex]))
	{
		minIndex = rightChildIndex;
	}

	if (minIndex != index)
	{
		//need to swap
		int temp = _vector[index];
		_vector[index] = _vector[minIndex];
		_vector[minIndex] = temp;
		BubbleDown(minIndex);
	}
}

void MinHeap::BubbleUp(int index)
{
	if (index == 0)
		return;

	int parentIndex = (index - 1) / 2;

	if (_vector[parentIndex] > _vector[index])
	{
		int temp = _vector[parentIndex];
		_vector[parentIndex] = _vector[index];
		_vector[index] = temp;
		BubbleUp(parentIndex);
	}
}



void MinHeap::Insert(int newValue)
{
	if (_vector.size() > 0)
	{
		int length = active_vector_size;
		_vector[length] = newValue;
		active_vector_size++;
		BubbleUp(length);
	}
	else
		_vector.push_back(newValue);
	active_vector_size++;
}

int MinHeap::GetMin()
{
	if (_vector.size() > 0)
		return _vector[0];
	else
		return -1;
}


void MinHeap::DeleteMin()
{
	int length = active_vector_size;
	if (length == 0)
		return;
	_vector[0] = _vector[length - 1];
	//_vector.pop_back();
	_vector.erase(_vector.begin() + (length-1));
	active_vector_size--;
	BubbleDown(0);
	
	
}

