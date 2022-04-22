/*
选择排序
*/

#include <iostream>
#include <vector>
using namespace std;

void choiceSort(vector<int>& nums) {
	int len = nums.size();

	for (int i = 0; i < len - 1; ++i) {
		int tem = i;
		for (int j = i + 1; j < len; ++j) {
			if (nums[tem] > nums[j]) {
				tem = j;
			}
		}
		if (tem != i) {
			swap(nums[tem], nums[i]);
		}
	}

	return;
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

	choiceSort(nums);

	for (int i : nums) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}