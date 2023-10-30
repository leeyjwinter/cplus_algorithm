#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<int> s;
int minNum = 0;
int maxNum = 0;

// 최대, 최솟값 가져옴
void getMinMax()
{

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 0)
			continue;
		maxNum = max(maxNum, s[i]);
	}
}

// num 이하의 수가 연속적으로 등장하는 최대값
int move(int num)
{
	int streak = 0;
	int maxStreak = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] > num)
		{
			maxStreak = max(maxStreak, streak);
			streak = 0;
		}
		else
		{
			streak++;
		}
	}
	maxStreak = max(maxStreak, streak);
	return maxStreak;
}

// 이분탐색
int solution(vector<int> stones, int k)
{
	int answer = 0;
	s = stones;
	getMinMax();
	while (maxNum >= minNum)
	{
		int mid = (minNum + maxNum) / 2;

		if (k > move((mid)))
		{
			answer = mid + 1;
			minNum = mid + 1;
		}
		else
			maxNum = mid - 1;
	}
	return answer;
}

int main()
{
	cout << solution({2, 4, 5, 3, 2, 1, 4, 2, 5, 1}, 3);
}