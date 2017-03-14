// Replacement_Selection_Algorithm.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <list>
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
	
	int curr_Active_Heap = 10;
	int curr_Pending_Heap = 0;
	int borderLIne = 9;
	int Next;
	
	while ( !infile.eof())
	{
		int Prev = activeHeap.GetMin();
		cout << Prev<<" ";
		if (!infile.eof())
		{
			infile >> Next;
			if (Next > Prev)
			{
				activeHeap._vector[0] = Next;
				activeHeap.Heapify();
			}
			else
			{
				activeHeap.DeleteMin();
				curr_Active_Heap--;
				curr_Pending_Heap++;
				activeHeap._vector.push_back(Next);
				cout << "Value getting Pushed" << activeHeap._vector[activeHeap._vector.size() - 1] << endl;
			
			}
			
			
		}
		
	}
	cout << "\nWhat is it displaying in here then" << endl;
	cout << "Vector Size::" << activeHeap.active_vector_size << endl;
	cout << "Vector is displayed in following sereis" << endl;
	for (int i = 0; i < activeHeap._vector.size()-1; i++)
	{
		cout << activeHeap._vector[i] << endl;

		
	}

	return 0;
}

int readFromFile(int myArray[],int Size,ifstream& infile)
{
	int Counter = 0;
	while (Counter<Size&&infile >> myArray[Counter])
		Counter++;
	return Counter;
}