/*
双向循环链表：STL中，list的底层数据结构为双向循环链表
下面完成的接口包括： push_front push_back pop_front pop_back remove empty size
*/

#include <iostream>
using namespace std;

class DoubleCirList {
public:
	DoubleCirList() {
		head = new Node();
		head->next = head;
		head->pre = head;
	}
	~DoubleCirList() {
		Node* p = head->next;
		while (p != head) {
			head->next = p->next;
			delete p;
			p = head->next;
		}
		delete head;
		head = nullptr;
	}

	void push_front(int val) {
		Node* p = new Node(val);
		p->next = head->next;
		head->next->pre = p;
		head->next = p;
		p->pre = head;
	}

	void push_back(int val) {
		Node* p = new Node(val);
		p->next = head->pre->next;
		p->pre = head->pre;
		head->pre->next = p;
		head->pre = p;
	}

	void pop_front() {
		if (empty())
			throw "error";
		Node* p = head->next;

		p->next->pre = head;
		head->next = p->next;

		delete p;
	}

	void pop_back() {
		if (empty())
			throw "error";
		Node* p = head->pre;

		p->pre->next = head;
		head->pre = p->pre;

		delete p;
	}

	void remove(int val) {
		Node* p = head->next;
		Node* pren = head;
		while (p != head) {
			if (p->val == val) {
				pren->next = p->next;
				p->next->pre = pren;
				delete p;
				p = pren->next;
			}
			else {
				pren = pren->next;
				p = p->next;
			}
		}
	}

	bool empty() const {
		return head->next == head;
	}

	int size() const {
		int result = 0;
		Node* p = head->next;

		for (; p != head; p = p->next) {
			++result;
		}
		return result;
	}

	void show() const {
		Node* p = head->next;
		while (p != head) {
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}
	
private:
	struct Node {
		Node(int data = 0) 
			: val(data)
			,next(nullptr)
			,pre(nullptr)
		{}
		int val;
		Node* next;
		Node* pre;
	};

	Node* head;
};

int main()
{
	DoubleCirList dlist;
	int arr[] = { 1,2,3,4,5,6,7 };

	for (int i : arr) {
		dlist.push_front(i);
	}
	dlist.show();
    /*
    7 6 5 4 3 2 1 
    */

	dlist.push_back(0);
	dlist.show();
    /*
    7 6 5 4 3 2 1 0
    */

	dlist.pop_back();
	dlist.show();
    /*
    7 6 5 4 3 2 1
    */

	dlist.pop_front();
	dlist.show();
    /*
    6 5 4 3 2 1 
    */

	return 0;
}
