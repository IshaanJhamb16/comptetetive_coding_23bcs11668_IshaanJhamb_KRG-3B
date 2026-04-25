#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> d1(n + 1, -1), d2(n + 1, -1);
        queue<pair<int, int>> q;
        
        q.push({1, 0});
        d1[1] = 0;

        while (!q.empty()) {
            auto [u, d] = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (d1[v] == -1) {
                    d1[v] = d + 1;
                    q.push({v, d1[v]});
                } else if (d2[v] == -1 && d + 1 > d1[v]) {
                    d2[v] = d + 1;
                    q.push({v, d2[v]});
                }
            }
        }

        int steps = d2[n];
        int curr_time = 0;
        for (int i = 0; i < steps; ++i) {
            if ((curr_time / change) % 2 == 1) {
                curr_time = (curr_time / change + 1) * change;
            }
            curr_time += time;
        }
        
        return curr_time;
    }
};