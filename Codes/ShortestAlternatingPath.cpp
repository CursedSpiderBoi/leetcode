//implemented using Bellman's ford algo
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    vector<vector<int>> redGraph(n), blueGraph(n);
    for (auto& edge : redEdges) 
		redGraph[edge[0]].push_back(edge[1]);
    for (auto& edge : blueEdges) 
		blueGraph[edge[0]].push_back(edge[1]);
    vector<int> redDist(n, INT_MAX), blueDist(n, INT_MAX);
    redDist[0] = blueDist[0] = 0;
    queue<int> redQ, blueQ;
    redQ.push(0), blueQ.push(0);
    while (!redQ.empty() || !blueQ.empty()) {
        int size = redQ.size();
        while (size--) {
            int node = redQ.front();
            redQ.pop();
            for (int next : blueGraph[node]) {
                if (blueDist[next] == INT_MAX) {
                    blueDist[next] = redDist[node] + 1;
                    blueQ.push(next);
                }
            }
        }
        size = blueQ.size();
        while (size--) {
            int node = blueQ.front();
            blueQ.pop();
            for (int next : redGraph[node]) {
                if (redDist[next] == INT_MAX) {
                    redDist[next] = blueDist[node] + 1;
                    redQ.push(next);
                }
            }
        }
    }
    vector<int> result(n);
    for (int i = 0; i < n; i++) 
		result[i] = min(redDist[i], blueDist[i]);
    for (int i = 0; i < n; i++) 
		result[i] = result[i] == INT_MAX ? -1 : result[i];
    return result;
	}
};
