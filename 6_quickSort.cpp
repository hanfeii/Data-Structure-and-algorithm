/*
快速排序：
选取一个基准数，将小于基准数的元素放在基准数左边，将大于基准数的元素放在基准数右边；
然后对基准数左右两边的序列重复操作；
直到整个序列有序。

最好的时间复杂度： O(n*logn) 最好的空间复杂度：O(logn)
最坏的时间复杂度： O(n*n)    最坏的空间复杂度：O(n) 调用栈所消耗
*/

/*
快速排序优化：
1、随着快排算法进行，整体数据趋于有序，在一定范围内，采用插入排序。
2、采用“三数取中（值中间）”，找合适的基准数。
*/

#include <vector>
#include <iostream>

using namespace std;

int partion(vector<int>& nums, int left, int right) {
	int tmp = nums[left]; //选取基准数

	int l = left;
	int r = right;
	while (l < r) {
		while (l < r && nums[r] >= tmp)
			--r;
		nums[l] = nums[r];

		while (l < r && nums[l] <= tmp)
			++l;
		nums[r] = nums[l];
	}
	
	//l == r 放基准数的位置
	nums[l] = tmp;
	return l;
}

void quicksort(vector<int>& nums, int left, int right) {
	if (left < right) {
		int pos = partion(nums, left, right);
		quicksort(nums, left, pos - 1);
		quicksort(nums, pos + 1, right);
	}
}

void quicksort(vector<int>& nums) {
	int left = 0;
	int right = nums.size()-1;
	quicksort(nums, 0, right);
}

int main()
{
	srand(time(NULL));
	vector<int> nums(10);

	for (int i = 0; i < 10; ++i) {
		nums[i] = rand() % 100;
	}
	for (int i : nums) {
		cout << i << " ";
	}
	cout << endl;

	quicksort(nums);

	for (int i : nums) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
