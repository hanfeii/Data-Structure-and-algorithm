/*
插入排序, 如果全局数据趋于有序，那么插入排序是所有排序算法中最优的
在基础排序中， 插入排序 优于 冒泡排序&&选择排序。 比较次数比选择排序少，移动次数比冒泡少
*/
#include <iostream>
#include <vector>

using namespace std;

void insertSort(vector<int>& nums) {
	int len = nums.size();

	for (int i = 1; i < len; ++i) {
		int tmp = nums[i];
		if (nums[i] > nums[i - 1])
			continue;
		int j = i - 1;
		for (; j >= 0; --j) {
			if (tmp < nums[j]) {
				nums[j + 1] = nums[j];
			}
			else
			{
				break;
			}
		}
		nums[++j] = tmp;
	}
}



int main()
{
	vector<int> nums(10);
	srand(time(NULL));

	for (int i = 0; i < 10; ++i) {
		nums[i] = rand() % 100 + 1;
	}

	for (int i : nums) {
		cout << i << " ";
	}
	cout << endl;

	insertSort(nums);

	for (int i : nums) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}