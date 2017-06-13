#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

// [[1,0],[2,0],[3,1],[3,2]]
// There are a total of 4 courses to take. To take course 3 you should have finished both courses 
// 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course
// order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
//
// NOTE - with this approach it beats only 55% submissions and take around 19ms.
// TODO - how to make it faster??
//
// Version 2 changes:
// graph[pre.second].insert(pre.first) -> graph[pre.first].insert(pre.second)
// This helps to avoid to reverse the vector and saves that cost. This makes it a little bit more
// faster, but still around 75% submissions.
//
// TODO - will converting the recursive function to non-recursive help here??
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<std::unordered_set<int>> graph(numCourses);
        make_graph(numCourses, prerequisites, graph);
	cout << "number of courses are: " << numCourses << endl;
	// TODO - check why preallocating memory here is failing.
        //vector<int> toposort(numCourses);
	vector<int> toposort;
	cout << "toposort courses are: " << toposort.size() << endl;
	cout << "toposort courses are: " << toposort.size() << endl;
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
	//stack<int> toposort(numCourses);
        for (int i = 0; i < numCourses; i++) {
		cout << "amit..." << endl;
            if (!visited[i] && dfs(graph, i, onpath, visited, toposort))
                return {};
	}
	// TODO - how about we just pass a stack so that we dont need to do this extra revese operation?
	// will that affect runtime performance.
        //reverse(toposort.begin(), toposort.end());
	cout << "toposort courses are: " << toposort.size() << endl;
        return toposort;
    }
private:
    // Check that to represent this graph there can be different options, like vector<vector<int>>
    // or vector<list<int>> or this vector<unordered_set<int>>
    // vector<std::unordered_set<int>> make_graph(int numCourses, const vector<pair<int, int>>& prerequisites) {
    void make_graph(int numCourses, const vector<pair<int, int>>& prerequisites, vector<std::unordered_set<int>>& graph) {
        for (auto pre : prerequisites) {
            graph[pre.first].insert(pre.second);
        }
    }
    bool dfs(const vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited, vector<int>& toposort) { 
        if (visited[node]) return false;
        onpath[node] = visited[node] = true; 
        for (int neigh : graph[node])
            if (onpath[neigh] || dfs(graph, neigh, onpath, visited, toposort))
                return true;
        toposort.push_back(node);
        return onpath[node] = false;
    }
};

int main() {
  //vector<pair<int, int>> data = {{1,0},{2,0},{3,1},{3,2}};
  vector<pair<int, int>> data = {{1,0}};
  Solution s;
  vector<int> answer = s.findOrder(2, data);
  for (int i = 0; i < answer.size(); ++i) {
     cout << "result of course schedule is: " << answer[i] << endl;
  }
 

  return 0;
} 
