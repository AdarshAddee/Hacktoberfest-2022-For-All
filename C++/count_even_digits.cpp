// Input: [12,345,2,6,7896]
// Output: 2
// Explanation: Program counts number of elements in the array which have even number of digits
#include <iostream>
#include <vector>
using namespace std;
int findNumbers(vector<int> nums)
{
    vector<int> v;
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        while (nums[i] != 0)
        {
            nums[i] = nums[i] / 10;
            count++;
        }
        v.push_back(count);
        if (v[i] % 2 == 0)
            res++;
    }
    return res;
}
int main()
{
    vector<int> v;
    v.push_back(12);
    v.push_back(345);
    v.push_back(2);
    v.push_back(6);
    v.push_back(7896);
    int ans = findNumbers(v);
    cout << ans << endl;
    return 0;
}