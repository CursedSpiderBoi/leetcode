// You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1.
// Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

// You are given two arrays redEdges and blueEdges where:

// redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
// blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.

// Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that 
// the edge colors alternate along the path, or -1 if such a path does not exist.

 

// Example 1:

// Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
// Output: [0,1,-1]

// Example 2:

// Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
// Output: [0,1,-1]


// implemented using Bellman's ford algo
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
