#include <iostream>
#include <vector>
using namespace std;

//排序数组， 调整节点，节点值，数组最大下标
void sink(vector<int>& nums, int index, int val, int len) {
	int p = index;
	int c;

	while ((c = (p << 1) + 1) <= len) {
		if (c + 1 <= len && nums[c] < nums[c + 1]) {
			c = c + 1;
		}

		if (nums[c] > val) {
			nums[p] = nums[c];
			p = c;
		}
		else {
			break;
		}
	}
	nums[p] = val;
}

void heapSort(vector<int>& nums) {
	int len = nums.size() - 1;

	for (int i = (len - 1) >> 1; i >= 0; --i) {
		sink(nums, i, nums[i], len);;
	}
	for (int i = len; i > 0; --i) {
		swap(nums[i], nums[0]);
		sink(nums, 0, nums[0], len-1);
		len--;
	}
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

	heapSort(nums);

	for (int i : nums) {
		cout << i << " ";
	}
	cout << endl;


	return 0;
}
