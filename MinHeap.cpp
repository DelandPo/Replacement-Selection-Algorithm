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

void MinHeap::active_Heapify(int active_Heap_Size)
{
	int length = active_Heap_Size;
	for (int i = length - 1; i >= 0; --i)
	{
		BubbleDown(i);
	}
}

void MinHeap::pending_Heapify(int active_Heap_Size)
{
	int length = _vector.size();
	for (int i = length - 1; i >= active_Heap_Size; --i)
	{
		BubbleDown(i);
	}

}

void MinHeap::Heapify()
{
	int length = _vector.size();
	for (int i = length - 1; i >= 0; --i)
	{
		BubbleDown(i);
	}
}


void MinHeap::BubbleDown(int index)
{
	 int length = _vector.size();
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
	int length = _vector.size();
	_vector[length] = newValue;

	BubbleUp(length);
}

int MinHeap::GetMin()
{
	return _vector[0];
}

void MinHeap::DeleteMin()
{
	int length = _vector.size();

	if (length == 0)
	{
		return;
	}

	_vector[0] = _vector[length - 1];
	_vector.pop_back();

	BubbleDown(0);
}