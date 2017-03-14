#include "vector"
using namespace std;

class MinHeap
{
private:
	

public:
	vector<int> _vector;
	void BubbleDown(int index);
	void BubbleUp(int index);
	void active_Heapify(int Limiter);
	void pending_Heapify(int Limmiter);
	void Heapify();
	MinHeap(int* array, int length);
	MinHeap(const vector<int>& vector);
	MinHeap();
	  
	void Insert(int newValue);
	int GetMin();
	void DeleteMin();
};