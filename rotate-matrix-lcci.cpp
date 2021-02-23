﻿#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int temp;
		for (int i = 0; i < matrix.size() / 2; i++) {
			for (int j = i; j < matrix.size() - 1 - i; j++) {
				temp = matrix[i][j];
				matrix[i][j] = matrix[matrix.size() - 1 - j][i];
				matrix[matrix.size() - 1 - j][i] = matrix[matrix.size() - 1 - i][matrix.size() - 1 - j];
				matrix[matrix.size() - 1 - i][matrix.size() - 1 - j] = matrix[j][matrix.size() - 1 - i];
				matrix[j][matrix.size() - 1 - i] = temp;
			}
		}
	}
};

int main() {
	vector<vector<int>>matrix = {
	{15,13, 2, 5},
	{14, 3, 4, 1},
	{12, 6, 8, 9},
	{16, 7,10,11}
	};
	Solution a;
	a.rotate(matrix);
}

/*
给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。

不占用额外内存空间能否做到？

 

示例 1:

给定 matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-matrix-lcci
*/
