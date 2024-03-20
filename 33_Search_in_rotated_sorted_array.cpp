#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &arr, int target)
    {
        int high = arr.size() - 1;
        int low = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == target)
                return mid;
            if (arr[low] <= arr[mid])
            {
                // left half is sorted
                if (arr[low] <= target and target <= arr[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                // right half is sorted
                if (target >= arr[mid] and target <= arr[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}