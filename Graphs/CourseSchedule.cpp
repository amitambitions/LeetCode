// Currently failing at:
// Input:
// 2
// [[0,1]]
// Output:
// false
// Expected:
// true
// TODO - need to debug what is the issue

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<bool> visited(prerequisites.size(), false);
        
        // First mistake, the loop should run till numCourses because thats the number of
        // nodes present in our graphs. If we look till the size of prerequisites then we
        // are wasting a lot of memory cycles.
        // for (int i =0; i<prerequisites.size(); ++i) {
        for (int i =0; i< numCourses; ++i) {
            if (visited[i] == false) {
                if (dfs_cycle(graph, visited, i))
                    return false;
            }
        }
        return true;
    }
private:
    // Check that to represent this graph there can be different options, like vector<vector<int>>
    // or vector<list<int>> or this vector<unordered_set<int>>
    vector<unordered_set<int>> make_graph(int numCourses, const vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites) {
            graph[pre.second].insert(pre.first);
        }
        return graph;
    }
    
    bool dfs_cycle(const vector<unordered_set<int>>& graph, vector<bool>& visited, int start) {
        visited[start] = true;
        for (int neighbour : graph[start]) {
            if (visited[neighbour] || dfs_cycle(graph, visited, neighbour))
                return true;
        }
        return false;
    }
    
};
