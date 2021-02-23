#include"headfile.h"
using namespace std;
//�Լ�������Ϊ������չ�õ��Ļ�������
vector<int> radix_sort(vector<int> nums) {
	int n = nums.size();
	int exp = 1;//���ڼ�¼�Ƚϵ��ڼ�λ��
	int max = *max_element(nums.begin(), nums.end());
	vector<int> buff(n);
	while (exp < max)
	{
		vector<int> count(10,0);
		//��count����¼��ͬβ���ĸ���
		for (int i = 0; i < n; i++)
		{
			int digit = (nums[i] / exp) % 10;
			++count[digit];
		}
		//��¼�����Ѿ��ж��ٸ����ˣ�Ŀ����Ϊ֮ǰ��������λ��
		for (int i = 1; i < 10; i++)
		{
			count[i] += count[i - 1];
		}
		//���������Ϊ�˱����ȶ���
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