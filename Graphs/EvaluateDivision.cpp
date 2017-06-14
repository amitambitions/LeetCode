// Equations are given in the format A / B = k, where A and B are variables represented as
// strings, and k is a real number (floating point number). Given some queries, return the
// answers. If the answer does not exist, return -1.0.
//
// Example:
// Given a / b = 2.0, b / c = 3.0. 
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
// return [6.0, 0.5, -1.0, 1.0, -1.0 ].
//
// The input is: vector<pair<string, string>> equations, vector<double>& values,
// vector<pair<string, string>> queries , where equations.size() == values.size(), and the
// values are positive. This represents the equations. Return vector<double>.
//
// According to the example above:
//
// equations = [ ["a", "b"], ["b", "c"] ],
// values = [2.0, 3.0],
// queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
// The input is always valid. You may assume that evaluating the queries will result in no
// division by zero and there is no contradiction.
//
//
// Thought Process:
//
// 1) Initially I thought about graphs, and making each part of the equation a node. For
// e.g. in a/b we will have two nodes a and b, but then how will we represent the values of
// this division? Can we make it an edge weight? That would complicate the whole scenario.
//
// 2) Then thought was to use link process, we have a/b and b/c known then let us say we
// need to calculate a/c. So first we get b from a/b then see if b is mapped with c or not.
// If not then this is going to be -1, and if yes then we need to find that value. So when
// we need to see the mapping like this, the best and most effective data structure is
// hash tables and hence unodered_set. Just referred the code to save soem typing time :)

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, 
        vector<double>& values, vector<pair<string, string>> query) 
    {
        unordered_map<string,unordered_map<string, double>> m;
        vector<double> res;
        
        // When we encounter a/b better to create two entries a and b in the map because we
        // need to find links, if we need to see whether a can be connected to c, then we
        // need to see if b is connected to c, and this is why this mapping helps us a lot. 
        for (int i = 0; i < values.size(); ++i)
        {
            m[equations[i].first].insert(make_pair(equations[i].second,values[i]));
            if(values[i]!=0)
                m[equations[i].second].insert(make_pair(equations[i].first,1/values[i]));
        }

        // Always use const auto reference.
        for (const auto& i : query)
        {
            unordered_set<string> s;
            double tmp = check(i.first,i.second,m,s);
            if(tmp) res.push_back(tmp);
            else res.push_back(-1);
        }
        return res;
    }

    double check(const string &up, const string &down, 
            unordered_map<string,unordered_map<string, double>> &m,
            unordered_set<string> &s)
    {
        // We need base case for our recursion to exit. So base case can be when lets us
        // say up is b and down is c and there is a mapping from b to c, then we just return
        // the value.
        if(m[up].find(down) != m[up].end()) return m[up][down];
        for (auto i : m[up])
        {
            // IMP - for a/b, we store two mappings in the map, one with key a and one with
            // key b. In the same example, let us say we are finding a/c now we first get 
            // b as mapping of a, but then b has mapping to a and c both and if we keep on
            // calling "check", then b will again call check with "up" a sa and hence will
            // result into a never ending cycle. This is like a depth first search, to avoid
            // this cycle for one particular query execution, we need to make sure that 
            // we call "check" only for unvisited nodes and hence we check the below condition
            // first.
            // TODO - set can be a complex ds here, try using a simple visited[] kind of array.
            // we dont have indexes rather we have nodes named as a and b, so we can consider
            // a as 0 and so on.
            if(s.find(i.first) == s.end())
            {
                s.insert(i.first);
                // This is a perfect case for a recursion because let us say we need to find
                // a/c, we checked a and found that a is connected to b, now we need to see 
                // if b is connected to c or not, so we again need to "check" and this time
                // "up" becomes b.
                double tmp = check(i.first,down,m,s);
                if(tmp) return i.second*tmp;
            }
        }
        return 0;
    }
};
