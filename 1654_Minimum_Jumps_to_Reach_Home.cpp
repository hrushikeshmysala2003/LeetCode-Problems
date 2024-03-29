#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int minimumJumps(vector<int> &forbidden, int a, int b, int x)
{
    unordered_map<int, int> um;
    for (auto &pos : forbidden)
    { // Adding all the forbidden positions
        um[pos]++;
    }
    queue<pair<int, pair<int, bool>>> q;
    // Queue will store the Position, Number of hops and
    // a bool variable that will denote if the last hop was in
    // forward direction or backward (True: forward, False: backward)
    q.push({0, {0, true}});
    while (!q.empty())
    {
        auto node = q.front();
        int currPos = node.first, ans = node.second.first;
        bool canGoBackwards = node.second.second;
        q.pop();
        if (currPos == x)
            return ans;
        // If the position is already visited we do not add forward and backward from that position
        if (um.find(currPos) != um.end())
            continue;
        um[currPos]++;
        int forward = currPos + a, backward = currPos - b;
        if (canGoBackwards and backward >= 0)
        {
            q.push({backward, {ans + 1, false}});
        }
        if (forward <= 2000 + a + b)
        { // 1 <= a, b, forbidden[i] <= 2000
            // We can at max come backwards from (2000 + a + b) position to x position
            q.push({forward, {ans + 1, true}});
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter the number of forbidden numbers: ";
    cin >> n;
    int a;
    int b;
    int x;
    vector<int> forbidden;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        forbidden.push_back(x);
    }

    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Ener the value of b: ";
    cin >> b;
    cout << "Enter the value of x: ";
    cin >> x;

    cout << "Minimum Jumps to Reach Home: " << minimumJumps(forbidden, a, b, x);

    return 0;
}