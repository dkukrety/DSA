/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.



Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.


Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

class Solution
{
public:
    bool hasCycle(int start, vector<vector<int>> &adjList, vector<bool> &visited, unordered_map<int, bool> &mp)
    {
        visited[start] = true;
        mp[start] = true;
        for (int vertex : adjList[start])
        {
            if (!visited[vertex])
            {
                if (hasCycle(vertex, adjList, visited, mp))
                    return true;
            }
            else
            {
                if (mp[vertex])
                    return true;
            }
        }
        mp[start] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        vector<vector<int>> adjList(numCourses);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            // b --> a, must take course b before taking course a
            adjList[b].push_back(a);
        }

        unordered_map<int, bool> mp;
        vector<bool> visited(numCourses, false);
        
          // we have to check for multiple components also
        // thats why this loop is there.
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                // if directed graph has cycle then we cannot finish the course
              
                bool canFinish = !hasCycle(i, adjList, visited, mp);
                if (!canFinish)
                    return false;
            }
        }

        return true;
    }
};
