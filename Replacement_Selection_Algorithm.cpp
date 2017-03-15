// Replacement_Selection_Algorithm.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <cassert>
#include "MinHeap.h"
using namespace std;
int readFromFile(int myArray[], int Size, ifstream& infile);
int main()
{
	const int Size = 10;
	string file_Name = "Input1.txt";
	ifstream infile;
	infile.open(file_Name);
	if (!infile)
	{
		cout << "File couldn't be open!!" << endl;
		return 0;
	}
	int myArray[Size];
	int Counter = readFromFile(myArray, Size, infile);
	MinHeap activeHeap(myArray, 10);
	
	int curr_Active_Heap = 9;
	int curr_Pending_Heap = 0;
	int borderLIne = 9;
	int Next;
	int Counter_Loop = 0;
	int Looper = 0;
	activeHeap.active_vector_size = 10;
	while (curr_Active_Heap != -1)
	{
		int Previous = activeHeap.GetMin();
		cout << Previous << " ";
		if (!infile.eof())
		{
			int Next;
			infile >> Next;
			if (Next > Previous)
			{
				activeHeap._vector[0] = Next;
				activeHeap.Heapify();
			}
			else
			{
				int temp = activeHeap._vector[0];
				activeHeap._vector[0] = activeHeap._vector[curr_Active_Heap];
				activeHeap._vector[curr_Active_Heap] = temp;
				if (curr_Active_Heap != (activeHeap._vector.size() - 1))
				{
					int temp = activeHeap._vector[curr_Active_Heap];
					activeHeap._vector[activeHeap._vector.size() - 1] = temp;
					activeHeap._vector[curr_Active_Heap] = activeHeap._vector[activeHeap._vector.size() - 1];
					activeHeap._vector.pop_back();

				}
				else
					activeHeap._vector.pop_back();
				activeHeap._vector.push_back(Next);
				curr_Active_Heap--;
				activeHeap.active_vector_size--;
				activeHeap.Heapify();
				curr_Pending_Heap++;

			}
		}
		else
			cout << "Ran out of the Input Data" << endl;
	}
	cout << "\nActive Vector Size ::" << activeHeap.active_vector_size << endl;
	cout << "Actual Vector Size :: " << activeHeap._vector.size() << endl;

	return 0;
}

int readFromFile(int myArray[],int Size,ifstream& infile)
{
	int Counter = 0;
	while (Counter<Size&&infile >> myArray[Counter])
		Counter++;
	return Counter;
}