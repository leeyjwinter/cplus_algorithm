#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> a)
{
    int answer = 0;
    int size = a.size();
    vector<int> minLeft(size);
    vector<int> minRight(size);

    // 각 index마다 왼쪽기준 최소값 가져옴
    minLeft[0] = a[0];
    for (int i = 1; i < size; i++)
    {
        minLeft[i] = min(a[i], minLeft[i - 1]);
    }

    // 각 index마다 오른쪽기준 최소값 가져옴
    minRight[size - 1] = a[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        minRight[i] = min(a[i], minRight[i + 1]);
    }

    for (int i = 0; i < size; i++)
    {
        if (i == 0 || i == size - 1)
        {
            answer++;
        }
        else
        {
            if (minLeft[i - 1] > a[i] || minRight[i + 1] > a[i])
            {
                answer++;
            }
        }
    }
    return answer;
}

int main()
{
    cout << solution({1, 2, 3, 4, 5});
}