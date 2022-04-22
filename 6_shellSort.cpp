/*
希尔排序,又称“缩小增量排序”，
插入排序，当待排序序列的关键字基本有序，并且待排序数据量较小的时候，效率高。希尔排序便是对此的优化。
希尔排序实质上是采用分组插入的方法，先将整个待排序记录序列分割成几组，从而减小数据量，
对每组数据分别进行直接插入排序，然后增加每组数据量，重新分组，这样几次排序后，整个序列就“基本有序”，

*/

#include <vector>
#include <iostream>
using namespace std;

void shellSort(vector<int>& nums) {
	int len = nums.size();

	for (int gap = len / 2; gap > 0; gap /= 2) { 
		for (int i = gap; i < len; i++) {
			int tmp = nums[i];
			int j = i - gap;
			for (; j >= 0; j -= gap) {
				if (tmp < nums[j]) {
					nums[j + gap] = nums[j];
				}
				else {
					break;
				}
			}
			nums[j + gap] = tmp;
		}
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

	shellSort(nums);

	for (int i : nums) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}