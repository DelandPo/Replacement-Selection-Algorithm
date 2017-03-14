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
	const int Size = 100;
	string file_Name = "Input1.txt";
	ifstream infile;
	infile.open(file_Name);
	if (!infile)
		return 0;
	int myArray[Size];
	int Counter = readFromFile(myArray, Size, infile);
	int Boundary = 3;
	MinHeap activeHeap(myArray,Boundary);
	//cout << myArray[3] << "Index 3" << endl;
	activeHeap._vector[0] = 35;
	activeHeap.active_Heapify(Boundary);
	activeHeap._vector.push_back(8899);
	activeHeap._vector.push_back(10000);
	activeHeap._vector.push_back(765);

	activeHeap._vector.push_back(760);
	
	activeHeap.pending_Heapify(3);
	
	//activeHeap.Heapify();
	for (int i = 0; i < 7; i++)
	{
		cout << "Size of the heap" << activeHeap._vector.size() << endl;
		cout << activeHeap._vector[i] << " " << endl;
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