// For a undirected graph with tree characteristics, we can choose any node as the 
// root. The result graph is then a rooted tree. Among all possible rooted trees, those 
// with minimum height are called minimum height trees (MHTs).
//
// Given such a graph, write a function to find all the MHTs and return a list of 
// their root labels.
// 
// Format
//     The graph contains n nodes which are labeled from 0 to n - 1.
//     You will be given the number n and a list of undirected edges (each edge is a 
//     pair of labels).
// 
//  
//     You can assume that no duplicate edges will appear in edges. Since all edges are
//     undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
// 
//     Example 1:
// 
//     Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
// 
//         0
//         |
//         1
//        / \
//       2   3
// 
//     return  [1]
// 
//     Example 2:
// 
//     Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
// 
//      0  1  2
//       \ | /
//         3
//         |
//         4
//         |
//         5
// 
//     return  [3, 4]
// 
//     How many MHTs can a graph have at most?
// 
//     Note:
// 
//     (1) According to the definition of tree on Wikipedia: https://en.wikipedia.org/wiki/Tree_(graph_theory)
//         “a tree is an undirected graph in which any two vertices are connected by exactly one path. 
//         In other words, any connected graph without simple cycles is a tree.”
// 
//     (2) The height of a rooted tree is the number of edges on the longest downward path between 
//         the root and a leaf.
// 
// First approach: I thought in the given graph, let us do a DFS for each node and keep on calculating
// the height and save it. This has following disadvantages:
//
// 1) There will be repetitive iterations for some nodes. Let us say we start with 4, then 
// nodes 0,1,2 will be visited again and again. Complexity will be around n^2 and at the 
// same time this will be little complex also. Let us say we are at node 3, we need to do
// a max() of the three child trees.
//
// 2) We can doa  BFS also but same sort of issues will be there.
//
// NOTE - in this question, a leaf node is not the one with no child, rather a leaf node
// is the one which has ONLY ONE NEIGHBOR. So we need to check this condition over and over.
//
// Second Approach - we want to visit every node as ONCE only, and we need to find the
// answer in single iteration. We know the boundary cases are with number of nodes as
// 1 and 2 and we need to process for more than 2 nodes. When we need to iterate once only
// then how about we start WITH leaf nodes and keep on removing them. Remember that when we
// solve problems, once of the idea is to modify the existing data structure to reduce the
// problem size.

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        // Corner case
        vector<int> current;
        if (n == 1) {
            current.push_back(0);
            return current;
        }
        // Initialize the undirected graph
        vector<unordered_set<int>> graph(n);
        
        // Again remember that we need to keep both links because we are not playing with 
        // a directed graphs. WHENEVER we see an undirected graph, we need to take care of
        // this point.
        for (const auto& edge : edges) {
            // TODO: is assignment more costly than insert?
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }
        
        // Now, we need to know all the leaf nodes first.
        vector<int> current_leafs;
        for (int i : graph) {
            if (graph[i].size == 1)
                current_leafs.push_back(i);
        }
        
        // Now start removing the leaf nodes, one by one.
        // TODO - need to complete this part.
        // NOTE - when we remove leaf node, we need to remove it from all its neighbors.
    }
    