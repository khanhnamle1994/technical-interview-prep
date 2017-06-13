// There are a total of n courses you have to take, labeled from 0 to n - 1.
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

/* Analysis:
This is a classic Graph topology sorting problem, but an easy version. We don't have to store the sort, in other words, we only need to
detect if exists cycle in a directed graph. Both DFS and BFS can be used to solve this problem.

First of all, we need to get a representation of the graph, either adjacency matrix or adjacency list is OK. In my code, you can see both
ways. But note that, when the number of vertex is large, adjacency matrix usually is NOT a good option.

In DFS, the general idea, is to search each vertex in the graph recursively, if the current vertex has been visited in this search, then
there must be a cycle. Be careful with the status of each vertex, here in my code, it has three states:  unvisited (=0), visited(=1),
searching(=-1). The third states is to detect the existence of cycle, while the 2nd state indicate that the vertex is already checked and
there is no cycle.

In BFS, the idea is much easier.  We store the indegree of each vertex, push the vertices with 0 indegree in stack (remember general BFS
framwork?).  Every time, pop the stack and set indegree of connected vertices -1. In the end, if the number of popped out vertices is less
than the total number of vertices in the original graph, there is cycle.

Note, in the test cases, there exist duplicates in prerequisites array. */

// BFS Solution
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int plen = prerequisites.size();
        vector<int> ind(numCourses,0); //indegree vector

        //construct map & get indegree of each vertex
        vector<vector<bool> > map(numCourses, vector<bool>(numCourses, false));
        for (int i=0;i<plen;i++){
            //Important: in case of duplicates in prerequisites, only +1 indegree
            if (map[prerequisites[i].first][prerequisites[i].second] == false){
                map[prerequisites[i].first][prerequisites[i].second] = true;
                ind[prerequisites[i].first]++;
            }
        }

        //BFS
        stack<int> st;
        for (int i=0;i<numCourses;i++){
            if (ind[i]==0) st.push(i);
        }

        int count = 0;  // to get the bool result

        while (!st.empty()){
            int tmp = st.top();
            st.pop();
            count ++;
            for (int i=0;i<numCourses;i++){
                if (map[i][tmp]){
                    ind[i]--;
                    if (ind[i]==0) st.push(i);
                }
            }
        }
        return count < numCourses ? false : true;

    }
};

// DFS Solution
class Solution {
public:
    bool dfs(int v, vector<int> &visit, vector<set<int> > &gr){
        if (visit[v] == 1){return true;}
        visit[v] = -1;
        for (auto it = gr[v].begin(); it != gr[v].end(); it++){
            if (visit[*it] == -1 || ! dfs(*it, visit, gr)){
                return false;
            }
        }
        visit[v] = 1;
        return true;
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int plen = prerequisites.size();
        vector<int> visit(numCourses,0);
        vector<set<int> > gr(numCourses);

        for (int i=0;i<plen;i++){
            gr[prerequisites[i].second].insert(prerequisites[i].first);
        }

        for (int i=0;i<numCourses;i++){
            if (!dfs(i, visit, gr)) return false;
        }
        return true;
    }
};
