#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

int minimumOperationsToMakeEqual(int x, int y)
{
    unordered_set<int> st;

    queue<pair<int, int>> q;
    q.push({x, 0});

    while (!q.empty())
    {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();
        if (st.find(node) != st.end())
            continue;
        if (node == y)
            return steps;
        if (steps > abs(x - y))
            continue;
        st.insert(node);

        if (node % 11 == 0)
        {
            q.push({node / 11, steps + 1});
        }
        if (node % 5 == 0)
        {
            q.push({node / 5, steps + 1});
        }
        q.push({node - 1, steps + 1});
        q.push({node + 1, steps + 1});
    }
    return -1;
}

int main()
{
    int x;
    int y;

    cout << "Enter the value of x : ";
    cin >> x;
    cout << "Enter the value of y : ";
    cin >> y;

    cout << "Minimum Number of operation to make X and Y equal : " << minimumOperationsToMakeEqual(26, 1) << endl;
    return 0;
}