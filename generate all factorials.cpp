/*
Author: Qicai Shi, shiqicai@gmail.com
Date: Jan 1, 2015
Problem: Integer frac
Difficulty: Medium
Solution Type: search / recursion  
Source: QQ friend 
Notes:
give a positive integer, return all factorials of the integer (not include the integer itself).
If the numbers of two factorial are the same and the order is different, consider the two as one. 
Follow up 1:
How about return all factorials with no duplicate factor?
Follow up 2:
return the prime factorial.
*/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
//2015/1/1 11:20-32
void factorialHelp(vector<vector<int> > &res, vector<int> &curFactors, int curNum, int smallestFactor) {
	if (curNum == 1) {
		res.push_back(curFactors);
		return;
	}
	for (int i = smallestFactor; i <= curNum; i++) {
		if (curNum % i == 0) {
			curFactors.push_back(i);
			factorialHelp(res, curFactors, curNum / i, i);  // if want to find out all factorials which have no duplicate factor, change this line to factorialHelp(res, curFactors, curNum / i, i + 1);
			curFactors.pop_back();
		}
	}
	return ;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<vector<int> > res;
	vector<int> curFac;
	factorialHelp(res, curFac, n, 2);
	for (int i = 0 ; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			printf("%d * ", res[i][j]);
		}
		printf("\n");
	}
	getchar();
	getchar();
	return 0;
}
