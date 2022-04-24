/*
大根堆：父节点值大于孩子节点值。 小根堆：父节点值小于孩子节点值。
二叉堆 是一颗完全二叉树，因此用连续空间存储还是很方便的。

优先级队列，则是利用 大根堆（小根堆）这种数据结构去实现的。
*/


#include <vector>
#include <iostream>
#include <functional>
#include <cstring>
using namespace std;

class priorityQueue {
public:
	using Comp = function<bool(int, int)>;
	priorityQueue(int data = 20, Comp com = greater<int>())
		:size_(0)
		, cap_(data)
		, comp(com)
	{
		pQue = new int[cap_];
	}
	priorityQueue(Comp com)
		:size_(0)
		, cap_(20)
		, comp(com)
	{
		pQue = new int[cap_];
	}
	~priorityQueue() {
		delete[] pQue;
		pQue = nullptr;
	}

	void push(int val) {
		if (size_ == cap_) {
			int* newptr = new int[2 * cap_];
			memcpy(newptr, pQue, sizeof(int) * cap_);
			pQue = newptr;
			delete[] newptr;
		}
		if (size_ == 0) {
			pQue[0] = val;
		}
		else {
			pQue[size_] = val;
			swim(size_, val);
		}

		size_++;
	}

	void pop() {
		if (empty())
			throw "error";
		/*
		* 这样写是错误的，因为只有一个元素的话，会越界。
			pQue[0] = pQue[size_ - 1];
			--size_;
			sink(0, pQue[0]);
		*/
		--size_;
		if (size_ > 0) {
			//将最后一个元素放在堆顶，然后下沉操作，重新构成大顶堆。
			sink(0, pQue[size_]);
		}
		
	}

	bool empty() const {
		return size_ == 0;
	}

	int size() const {
		if (empty())
			throw "error";
		return size_;
	}

	int top() const {
		if (empty())
			throw "error";
		return pQue[0];
	}
private:
	void swim(int index, int val) {
		int c = index;
		int p;
		while ((p = (c - 1) >> 1) >= 0) {
			if (comp(val, pQue[p])) {
				pQue[c] = pQue[p];
				c = p;
			}
			else {
				break;
			}
		}
		pQue[c] = val;
	}

	//下沉操作，将父节点与孩子节点比较，调整得到大根堆。
	void sink(int index, int val) {
		int p = index;
		int c;

		while ((c = (p << 1) + 1) <= size_){
			if (c + 1 <= size_ && comp(pQue[c + 1], pQue[c])) {
				c = c + 1;
			}
			if (comp(pQue[c], val)) {
				pQue[p] = pQue[c];
				p = c;
			}
			else {
				break;
			}
		}
		pQue[p] = val;
	}

private:
	int* pQue;
	int size_;
	int cap_;
	Comp comp;
};


int main() {
	srand(time(NULL));
	priorityQueue p;

	for (int i = 0; i < 10; ++i) {
		p.push(rand() % 100);
	}

	while (!p.empty()) {
		cout << p.top() << " ";
		p.pop();
	}
	cout << endl;


	cout << "-------------------------" << endl;
	priorityQueue q([](int a, int b)->bool {return a < b; });

	for (int i = 0; i < 10; ++i) {
		q.push(rand() % 100);
	}

	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;

	return 0;

}