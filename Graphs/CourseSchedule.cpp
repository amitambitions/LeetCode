#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

// Input:
// 2
// [[0,1]]
// Output:
// false
// Expected:
// true
// Fixed this case.
//
// TODO - change the representation of graphs to different formats and see how
// that affects the runtime.
// NOTE - mistake committed - I was using visited[] array only and thought that
// there is no need to use any other array, but let us consider a simple case
// 1 --> 0 here if we start with 0 then 0 will be marked as visited, then when
// we gte next node as 1 then 1 will found 0 as visited and will return that this
// is a cycle, which is wrong. Cycle is a possobility only 

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	//cout << "req size: " << prerequisites.size() << endl;
	vector<std::unordered_set<int>> graph(numCourses);
	// NOTE - just by changing the signature to pass the graph by reference, the
	// overall performance is increased. DO NOT assume that leetcode's compiler uses
	// C++11 and will use move constructors. Neither assume it anywhere else. 
        //vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites, graph);
	make_graph(numCourses, prerequisites, graph);

	// Second mistake, we should initialize these boolean vectors with numCourses or
	// graph.size(), NOT with prerequisites.size()
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        
        // First mistake, the loop should run till numCourses because thats the number of
        // nodes present in our graphs. If we look till the size of prerequisites then we
        // are wasting a lot of memory cycles.
        // for (int i =0; i<prerequisites.size(); ++i) {
        for (int i =0; i< numCourses; ++i) {
		if (!visited[i] && dfs_cycle(graph, onpath, visited, i))
			return false;
	}
        return true;
    }
private:
    // Check that to represent this graph there can be different options, like vector<vector<int>>
    // or vector<list<int>> or this vector<unordered_set<int>>
    // vector<std::unordered_set<int>> make_graph(int numCourses, const vector<pair<int, int>>& prerequisites) {
    void make_graph(int numCourses, const vector<pair<int, int>>& prerequisites, vector<std::unordered_set<int>>& graph) {
        for (auto pre : prerequisites) {
            graph[pre.second].insert(pre.first);
        }
    }
    
    bool dfs_cycle(const vector<std::unordered_set<int>>& graph, vector<bool>& onpath, vector<bool>& visited, int start) {
        if (visited[start]) return false;
        onpath[start] = visited[start] = true;

        for (int neighbour : graph[start]) {
            if (onpath[neighbour] || dfs_cycle(graph, onpath, visited, neighbour))
                return true;
        }
        return onpath[start] = false;
    }
    
};

int main() {
  vector<pair<int, int>> data = {{0,1}};
  Solution s;
  cout << "reuslt of course schedule is: " << s.canFinish(2, data) << endl;

  return 0;
} 
