/*
有序序列
二分搜索：递归与非递归（迭代）

迭代法的时间复杂度：O(log n);
实际上对一棵 BST 树，从根节点开始搜索的过程，每一次搜索只会沿着一条路径搜索。
搜索最多花费的时间就是树的层数，树的层数跟整个数据量的关系为 树的层数 = log n。
最好情况为平衡二叉树(即每次查找会分成两半)时,二分搜索显然满足。

递归：递归的思考是水平方向的，递归的具体执行是垂直方向的. 函数自己调用自己
搞清递归函数的意义是什么，返回值，参数列表，完成的功能。
要有递归结束的条件，每个数据规模要写好他们之间的关系。
不管是什么数据规模，求解问题的方式是一样的。
不同数据规模，其计算结果有关系可寻。
*/
#include <vector>
#include <iostream>
using namespace std;

int binSerach(vector<int>& nums, int target) {
	int l = 0;
	int r = (int)nums.size() - 1;

	while (l <= r) {
		int mid = l + ((r - l) >> 1);
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] > target) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return -1;
}

int binSer(vector<int>& nums, int target, int l, int r) {
	if (l <= r) {
		int mid = l + ((r - l) >> 1);
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			binSer(nums, target, mid + 1, r);
		else
			binSer(nums, target, l, mid - 1);
	}
	else {
		return -1;
	}
}


int main()
{
	vector<int> nums{ 1,2,3,4,5,6,7,8,9 };
	int result;

	//int binSerach(vector<int>& nums, int target)
	result = binSerach(nums, 1);
	result = binSerach(nums, 0);
	result = binSerach(nums, 10);
	result = binSerach(nums, 5);

	//int binSer(vector<int>& nums, int target, int l, int r)
	result = binSer(nums, 1, 0, nums.size()-1);
	result = binSer(nums, 0, 0, nums.size() - 1);
	result = binSer(nums, 10, 0, nums.size() - 1);
	result = binSer(nums, 5, 0, nums.size() - 1);


	return 0;
}