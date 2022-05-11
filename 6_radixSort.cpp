/*
基数排序
*/
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

void radixSort(vector<int>& nums) {
	int maxnum = nums[0];
	for (int i : nums)
		maxnum = maxnum > i ? maxnum : i;

	int cicle = to_string(maxnum).size();

	vector<list<int>> bucket(10);
	int mul = 1;
	int mod = 10;
	while (cicle--) {
		for (auto num : nums) {
			int index = (num % mod) / mul;
			bucket[index].push_back(num);
		}
		int i = 0;
		for (auto& buck : bucket) {
			while (!buck.empty()) {
				nums[i++] = buck.front();
				buck.pop_front();
			}
		}
		mul *= 10;
		mod *= 10;

		//bucket.clear();
	}


}

int main()
{
	srand(time(NULL));

	vector<int> nums(10);
	for (int i = 0; i < 10; ++i) {
		nums[i] = rand() % 100;
		cout << nums[i] << " ";
	}
	cout << endl;
	radixSort(nums);

	for (int i : nums) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}