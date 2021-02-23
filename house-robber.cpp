//����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������
//
//����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ ����������װ�õ������ ��һҹ֮���ܹ�͵�Ե�����߽�
//
//ʾ�� 1:
//
//����: [1, 2, 3, 1]
//	��� : 4
//	���� : ͵�� 1 �ŷ���(��� = 1) ��Ȼ��͵�� 3 �ŷ���(��� = 3)��
//	͵�Ե�����߽�� = 1 + 3 = 4 ��
//	ʾ�� 2 :
//
//	���� : [2, 7, 9, 3, 1]
//	��� : 12
//	���� : ͵�� 1 �ŷ���(��� = 2), ͵�� 3 �ŷ���(��� = 9)������͵�� 5 �ŷ���(��� = 1)��
//	͵�Ե�����߽�� = 2 + 9 + 1 = 12 ��
//
//	��Դ�����ۣ�LeetCode��
//	���ӣ�https ://leetcode-cn.com/problems/house-robber
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		vector<int> max(nums.size() + 2);
		int ans = 0;
		max[0] = 0;
		max[1] = 0;
		for (int i = 2; i < nums.size() + 2; i++) {
			max[i] = max[i - 2] + nums[i - 2];
			max[i] > ans ? ans = max[i] : max[i] = ans;
		}
		return ans;
	}
};
int main() {
	Solution a;
	vector<int> test = { 2, 1, 1, 2 };
	a.rob(test);
	return 0;
}