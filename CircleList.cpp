/*
 单向循环链表
 和STL中类似，除了头结点附近区域的增加删除操作，其余地方都不是明智之举。
 完成 >> 头插，尾插，删除第一个有效节点，删除指定值节点，是否为空，元素个数
*/

#include <iostream>
using namespace std;

class CircleList {
public:
	CircleList() {
		head = new Node();
		head->next = head;
		tail = head;
	}

	~CircleList() {
		Node* p = head->next;
		while (p != head) {
			head->next = p->next;
			delete p;
			p = head->next;
		}
		delete head;
		head = nullptr;
		tail = nullptr;
	}

	void push_front(int val) {
		Node* p = new Node(val);
		p->next = head->next;
		head->next = p;
		if (p->next == head) {
			tail = p;
		}
		head->val++;
	}

	void push_back(int val) {
		Node* p = new Node(val);
		p->next = tail->next;
		tail->next = p;
		tail = p;
		head->val++;
	}

	void pop_front() {
		if (empty())
			throw "error";
		Node* p = head->next;
		head->next = p->next;
		head->val--;
		delete p;
	}

	void remove(int val) {
		Node* p = head->next;
		Node* pre = head;
		while (p->next != head) {
			if (p->val == val) {
				pre->next = p->next;
				delete p;
				p = pre->next;
				head->val--;
			}
			else {
				pre = p;
				p = p->next;
			}
		}
	}

	bool empty() const {
		return head->next == head;
	}

	int size() const {
		return head->val;
	}
	void show() const {
		Node* p = head->next;
		while (p != head)
		{
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}
private:
	struct Node {
		Node(int data = 0) 
			: val(data), next(nullptr)
		{}
		int val;
		Node* next;
	};

	Node* head;
	Node* tail;
};


int main()
{
    int arr[] = { 1,2,3,4,5,6 };
    CircleList list;
    for (int i : arr) {
        list.push_front(i);
    }
    list.show();

    list.push_back(0);
    list.show();

    list.remove(5);
    list.show();

    return 0;
}