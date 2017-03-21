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

	string file_Name = "Input1.txt";	// FileName 

	ifstream infile;

	infile.open(file_Name);

	if (!infile)

	{

		cout << "File couldn't be open!!" << endl;

		return 0;

	}

	int myArray[Size];			// for Storing the first 10 elements in the Array

	int Counter = readFromFile(myArray, Size, infile);

	   MinHeap activeHeap(myArray, 10);			// making a Active + Pending Heap of Size 10 



	int curr_Active_Heap = 9;			// Counter for tracking the current active heap size

	int curr_Pending_Heap = 0;			// Counter for tracking the current pending heap size

	int borderLIne = 9;

	int Next;

	int Counter_Loop = 0;

	int Looper = 0;

	activeHeap.active_vector_size = 10;		// At the begining the active Heap Size = 10
		
	bool everyThingisDone = false;			// Exit condition 



	do

	{

		cout << "\nRun:: " << Counter_Loop << " ";

		while (curr_Active_Heap != -1 && !activeHeap._vector.empty())	// Exit condition for the while loop, loops until 

		{

			int Previous = activeHeap.GetMin();		// Returns the index 0 of the vector.

			cout << Previous << " ";			// Printing to Console Window

			if (!infile.eof())					// If we have inputs available

			{

				int Next;

				infile >> Next;		// Getting the next element from the file

				if (Next >= Previous)

				{

					activeHeap._vector[0] = Next;

					//activeHeap.Heapify();
					//activeHeap.BubbleDown(0);

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

				activeHeap.Heapify();

			}

			else

			{

				//cout << "Last size of the vector" << activeHeap._vector.size() << endl;

				//activeHeap.Heapify();

				//cout << "\nLast Run" << endl;

				int temp = activeHeap._vector.size();

				int activeSize = activeHeap.active_vector_size;

				

				// Fixing a simple bug
				// out of nowhere this happened
				//int secondTemp = activeHeap.GetMin();
		
				activeHeap._vector[0] = activeHeap._vector[activeHeap._vector.size() - 1];
				activeHeap._vector.pop_back();
				curr_Active_Heap--;
				activeHeap.active_vector_size--;
				activeHeap.Heapify();
				
				//Input ran out so merging the active heap and the pending Heap
				curr_Active_Heap = activeHeap._vector.size() ;
				

				curr_Pending_Heap = 0;

				activeHeap.active_vector_size = curr_Active_Heap;

				activeHeap.Heapify();
				activeSize = activeHeap.active_vector_size;
				for (int i = 0; i < activeSize; i++)

				{

					//cout << "is it in this loop" << endl;

					cout << activeHeap.GetMin() << " ";

					activeHeap.DeleteMin();

					curr_Active_Heap--;



				}
				cout << "Is it done" << endl;
				cout << endl;

				cout << "Actual Vector Size" << activeHeap._vector.size() << endl;

				cout << "Actual Heap Size of pending Heap" << activeHeap.active_vector_size << endl;

				// Now we need to heapify this thing

				activeHeap.active_vector_size = activeHeap._vector.size();

				curr_Active_Heap = activeHeap.active_vector_size;

				int pendingHeap = curr_Active_Heap;

				activeHeap.Heapify();

				cout << "Is it going from the pending Heap " << endl;
				for (int i = 0; i < pendingHeap; i++)

				{

					cout << activeHeap.GetMin() << " ";

					activeHeap.DeleteMin();

					curr_Active_Heap--;

					//activeHeap.Heapify();





				}

				cout << "Current Active Heap that controls the loop" << curr_Active_Heap << endl;

				/*

				for (int i = popper; i < activeHeap._vector.size(); i++)

				{

				activeHeap._vector.pop_back();

				curr_Active_Heap--;

				activeHeap.active_vector_size--;

				}

				cout << "\nLas Current Size:: " << curr_Active_Heap << endl;

				*/

				everyThingisDone = true;

			}





		}

		if (everyThingisDone == false)

		{

			curr_Active_Heap = 9;

			curr_Pending_Heap = 0;

			activeHeap.active_vector_size = 10;

			activeHeap.Heapify();

			Counter_Loop++;

		}

	} while (everyThingisDone == false);

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



int readFromFile(int myArray[], int Size, ifstream& infile)

{

	int Counter = 0;

	while (Counter<Size&&infile >> myArray[Counter])

		Counter++;

	return Counter;

}

