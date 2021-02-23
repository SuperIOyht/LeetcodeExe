#include"headfile.h"
using namespace std;
//以计数排序为基础扩展得到的基数排序
vector<int> radix_sort(vector<int> nums) {
	int n = nums.size();
	int exp = 1;//用于记录比较到第几位了
	int max = *max_element(nums.begin(), nums.end());
	vector<int> buff(n);
	while (exp < max)
	{
		vector<int> count(10,0);
		//用count来记录相同尾数的个数
		for (int i = 0; i < n; i++)
		{
			int digit = (nums[i] / exp) % 10;
			++count[digit];
		}
		//记录到此已经有多少个数了，目的是为之前的数留下位置
		for (int i = 1; i < 10; i++)
		{
			count[i] += count[i - 1];
		}
		//倒序遍历是为了保持稳定性
		for (int i = n; i >= 0; i--)
		{
			int digit = (nums[i] / exp) % 10;
			buff[count[digit] - 1] = nums[i];
			--count[digit];
		}
		copy(buff.begin(), buff.end(), nums.begin());
		exp *= 10;
	}
}