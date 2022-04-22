/*
冒泡排序：
数据交换次数太多。
*/
#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& nums) {
	int len = nums.size();
	int flag = 1;

	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len - i - 1; ++j) {
			if (nums[j] > nums[j + 1]) {
				swap(nums[j], nums[j + 1]);
				flag = 0;
			}
				
		}
		if (flag == 1)
			break;
	}

	return ;
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

	bubbleSort(nums);

	for (int i : nums) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}