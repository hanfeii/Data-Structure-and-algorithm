/*
二叉搜索树
实现非递归版本的插入、删除、查找、前中后层次遍历
删除在实现的时候，要记录要删除节点的父亲节点及孩子节点
*/

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
struct Node {
	Node(int data = 0) :
		val(data), left(nullptr), right(nullptr)
	{}
	int val;
	Node* left;
	Node* right;
};

class BST {
public:
	BST()
		: root_(nullptr)
	{}

	~BST() {
		if (root_ != nullptr) {
			std::queue<Node*> nodeQue;
			Node* cur = root_;

			nodeQue.push(cur);
			while (nodeQue.empty()) {
				cur = nodeQue.front();
				nodeQue.pop();

				if (cur->left)
					nodeQue.push(cur->left);
				if (cur->right)
					nodeQue.push(cur->right);

				delete cur;
			}
		}
		root_ = nullptr;
	}

	Node* n_query(const int data) {
		if (root_ == nullptr)
			return nullptr;

		Node* cur = root_;
		while (cur != nullptr) {
			if (cur->val == data) {
				return cur;
			}
			else if (cur->val > data) {
				cur = cur->left;
			}
			else {
				cur = cur->right;
			}
		}
		return nullptr;
	}

	void n_insert(const int data) {
		if (root_ == nullptr) {
			root_ = new Node(data);
			return;
		}

		Node* cur = root_;
		Node* parent = nullptr;

		while (cur != nullptr) {
			if (cur->val == data) {
				return;
			}
			else if (cur->val > data) {
				parent = cur;
				cur = cur->left;
			}
			else {
				parent = cur;
				cur = cur->right;
			}
		}
		if (parent->val > data) {
			parent->left = new Node(data);
		}
		else {
			parent->right = new Node(data);
		}

		return;

	}

	void n_delete(const int data) {
		//如果头结点为空，直接返回
		if (root_ == nullptr)
			return;

		//搜索目标节点
		Node* cur = root_;
		Node* parent = nullptr;
		while (cur != nullptr) {
			if (cur->val == data)
				break;
			else if (cur->val > data) {
				parent = cur;
				cur = cur->left;
			}
			else {
				parent = cur;
				cur = cur->right;
			}
		}

		//如果没有找到，直接返回
		if (cur == nullptr)
			return;


		Node* node = cur;
		//第三种情况，节点的孩子节点都不为空，找前驱节点
		if (cur->left != nullptr && cur->right != nullptr) {
			Node* pre = cur->left;
			parent = cur;

			while (pre->right != nullptr) {
				parent = pre;
				pre = pre->right;
			}

			cur->val = pre->val;
			cur = pre;
		}
		
		//情况一与情况二
		Node* child = cur->left;
		if (child == nullptr)
			child = cur->right;

		if (cur == root_) {
			root_ = child;
		}
		else {
			if (parent->left == cur) {
				parent->left = child;
			}
			else {
				parent->right = child;
			}
		}
		return;
	}
	
	void n_inorder() {
		std::stack<Node*> nodestack;
		Node* node = root_;

		while (!nodestack.empty() || node != nullptr) {
			if (node != nullptr) {
				nodestack.push(node);
				node = node->left;
			}
			else {
				Node* cur = nodestack.top();
				nodestack.pop();

				std::cout << cur->val << " ";
				
				node = cur->right;
			}
		}

		std::cout << std::endl;
	}

	void n_preorder() {
		std::stack<Node*> nodestack;
		Node* node = root_;

		if (root_ == nullptr)
			return;

		nodestack.push(node);
		while (!nodestack.empty()) {
			Node* cur = nodestack.top();
			nodestack.pop();

			std::cout << cur->val << " ";

			if (cur->right != nullptr)
				nodestack.push(cur->right);
			if (cur->left != nullptr)
				nodestack.push(cur->left);
		}

		std::cout << std::endl;
	}

	void n_backorder() {
		std::stack<Node*> nodestack;
		std::stack<Node*> nodestack1;
		if (root_ == nullptr)
			return;

		Node* cur = root_;
		nodestack.push(cur);

		while (!nodestack.empty()) {
			cur = nodestack.top();
			nodestack.pop();
			nodestack1.push(cur);

			if (cur->left)
				nodestack.push(cur->left);
			if (cur->right)
				nodestack.push(cur->right);
		}
		
		while (!nodestack1.empty()) {
			std::cout << nodestack1.top()->val << " ";
			nodestack1.pop();
		}
		std::cout << std::endl;
	}

	void n_levelorder() {
		std::queue<Node*> nodeque;

		if (root_ == nullptr)
			return;
		Node* cur = root_;

		nodeque.push(cur);
		while (!nodeque.empty()) {
			cur = nodeque.front();
			nodeque.pop();

			std::cout << cur->val << " ";
			if (cur->left)
				nodeque.push(cur->left);
			if (cur->right)
				nodeque.push(cur->right);
		}

		std::cout << std::endl;
		
	}
private:
	Node* root_;
};

int main()
{
	BST bst;
	bst.n_insert(3);
	bst.n_insert(1);
	bst.n_insert(5);
	bst.n_insert(4);
	bst.n_insert(6);
	bst.n_insert(2);

	bst.n_inorder();
	bst.n_levelorder();
	bst.n_preorder();


	bst.n_delete(3);
	bst.n_inorder();
	bst.n_levelorder();
	bst.n_preorder();

	return 0;
}