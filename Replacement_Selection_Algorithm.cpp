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
		cout << "Run 1:: ";
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


					int temp1 = activeHeap._vector[curr_Active_Heap];
					activeHeap._vector[curr_Active_Heap] = activeHeap._vector[activeHeap._vector.size() - 1];
					activeHeap._vector[activeHeap._vector.size() - 1] = temp1;

					activeHeap._vector.pop_back();



					//activeHeap._vector.push_back(Next);
					curr_Active_Heap--;
					activeHeap.active_vector_size--;

					curr_Pending_Heap++;
					activeHeap._vector.push_back(Next);
					//cout << "Data getting Pushed" << activeHeap._vector[activeHeap._vector.size() - 1] << endl;



				}
			}
			else
				cout << "Ran out of the Input Data" << endl;

			activeHeap.Heapify();
		}
		 curr_Active_Heap = 9;
		curr_Pending_Heap = 0;
		activeHeap.active_vector_size = 10;
		activeHeap.Heapify();
		cout << "\nRun 2 ::";
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


					int temp1 = activeHeap._vector[curr_Active_Heap];
					activeHeap._vector[curr_Active_Heap] = activeHeap._vector[activeHeap._vector.size() - 1];
					activeHeap._vector[activeHeap._vector.size() - 1] = temp1;

					activeHeap._vector.pop_back();



					//activeHeap._vector.push_back(Next);
					curr_Active_Heap--;
					activeHeap.active_vector_size--;

					curr_Pending_Heap++;
					activeHeap._vector.push_back(Next);
					//cout << "Data getting Pushed" << activeHeap._vector[activeHeap._vector.size() - 1] << endl;



				}
			}
			else
				cout << "Ran out of the Input Data" << endl;

			activeHeap.Heapify();
		}
		curr_Active_Heap = 9;
		curr_Pending_Heap = 0;
		activeHeap.active_vector_size = 10;
		activeHeap.Heapify();
		cout << "\nRun 2 ::";
		while (curr_Active_Heap >0)
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


					int temp1 = activeHeap._vector[curr_Active_Heap];
					activeHeap._vector[curr_Active_Heap] = activeHeap._vector[activeHeap._vector.size() - 1];
					activeHeap._vector[activeHeap._vector.size() - 1] = temp1;

					activeHeap._vector.pop_back();



					//activeHeap._vector.push_back(Next);
					curr_Active_Heap--;
					activeHeap.active_vector_size--;

					curr_Pending_Heap++;
					activeHeap._vector.push_back(Next);
					//cout << "Data getting Pushed" << activeHeap._vector[activeHeap._vector.size() - 1] << endl;



				}
			}
			else
			{
				//cout << "Last size of the vector" << activeHeap._vector.size() << endl;
				//activeHeap.Heapify();
				//cout << "\nLast Run" << endl;
				int temp = activeHeap._vector.size();
				//cout << "Vector Size:: " << temp << endl;
				cout << "Active Heap Size :: " << activeHeap.active_vector_size << endl;
				int activeSize = activeHeap.active_vector_size;
				int popper = 0;
				
				for (int i = 0; i <activeSize; i++)
				{
					
					cout << activeHeap.GetMin()<<" ";
					activeHeap.DeleteMin();
					curr_Active_Heap--;
					
				}
				cout << endl;
				cout << "Active Heap Size" << activeHeap._vector.size() << endl;
				cout << "Actual Heap Size of pending Heap" << activeHeap.active_vector_size << endl;
				// Now we need to heapify this thing
				activeHeap.active_vector_size = activeHeap._vector.size();
				curr_Active_Heap = activeHeap.active_vector_size;
				int pendingHeap = curr_Active_Heap;
				activeHeap.Heapify();
				for (int i = 0; i <pendingHeap; i++)
				{
					cout << activeHeap.GetMin() << " ";
					activeHeap.DeleteMin();
					curr_Active_Heap--;

				}
				/*
				for (int i = popper; i < activeHeap._vector.size(); i++)
				{
					activeHeap._vector.pop_back();
					curr_Active_Heap--;
					activeHeap.active_vector_size--;
				}
				cout << "\nLas Current Size:: " << curr_Active_Heap << endl;
				*/
			}

			activeHeap.Heapify();
		}
/*
	cout << "\nActive Vector Size ::" << activeHeap.active_vector_size << endl;
	cout << "Actual Vector Size :: " << activeHeap._vector.size() << endl;
	cout << "Run" << endl;
	for (int i = 0; i < activeHeap._vector.size(); i++)
	{
		cout << activeHeap._vector[i] << " ";
	}
	*/
	return 0;
}

int readFromFile(int myArray[],int Size,ifstream& infile)
{
	int Counter = 0;
	while (Counter<Size&&infile >> myArray[Counter])
		Counter++;
	return Counter;
}