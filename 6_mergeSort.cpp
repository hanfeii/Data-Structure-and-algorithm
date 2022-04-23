/*
不仅可以用于内部排序，也可以用于外部排序。
时间复杂度： O(n*logn);
空间复杂度: O(n) + O(logn);
*/
#include <vector>
#include <iostream>

using namespace std;

void merge(vector<int>& nums, int left, int mid, int right) {
	vector<int> arr(right - left + 1);
	int l = left;
	int r = mid + 1;
	int i = 0;
	while (l <= mid && r <= right) {
		if (nums[l] < nums[r]) {
			arr[i++] = nums[l];
			++l;
		}
		else {
			arr[i++] = nums[r];
			++r;
		}
	}

	while (l <= mid) {
		arr[i++] = nums[l++];
	}

	while (r <= right) {
		arr[i++] = nums[r++];
	}

	for (int j = 0; j < i; ++j) {
		nums[left++] = arr[j];
	}

}

void mergeSort(vector<int>& nums, int left, int right) {
	if (left < right) {
		int mid = left + ((right - left) >> 1);
		mergeSort(nums, left, mid);
		mergeSort(nums, mid + 1, right);

		merge(nums, left, mid, right);
	}
}

void mergeSort(vector<int>& nums) {
	mergeSort(nums, 0, nums.size() - 1);
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

	mergeSort(nums);

	for (int i : nums) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
