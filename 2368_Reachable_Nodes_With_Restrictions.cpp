#include <iostream>
using namespace std;
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
class Solution
{
public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {
        int restrictNode = restricted.size();
        unordered_set<int> st(restricted.begin(), restricted.end());

        unordered_map<int, vector<int>> adjList;
        for (auto it : edges)
        {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (st.find(node) != st.end())
                continue;
            st.insert(node);

            for (auto it : adjList[node])
            {
                if (st.find(it) == st.end())
                {
                    q.push(it);
                }
            }
        }
        return st.size() - restrictNode;
    }
};

int main()
{
    return 0;
}