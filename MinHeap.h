#include "vector"
using namespace std;

class MinHeap
{
private:
	
public:
	int active_vector_size = 10;
	vector<int> _vector;
	void BubbleDown(int index);
	void BubbleUp(int index);
	void Heapify();
	MinHeap(int* array, int length);
	MinHeap(const vector<int>& vector);
	MinHeap();
	void MinHeapify(const vector<int>& vector);
	void Insert(int newValue);
	
	int GetMin();
	void DeleteMin();
};