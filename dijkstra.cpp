#include <set>
#include <list>
#include <unordered_map>
#include <vector>

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // make adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    // distance array
    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }
    // declare set to store the distance & node then insert source
    set<pair<int, int>> st;
    dist[source] = 0;
    st.insert(make_pair(0, source));

    // traverse neighbours using bfs
    while (!st.empty())
    {
        // fetch the top element: becasue its minimum
        auto top = *(st.begin());
        int nodeDist = top.first;
        int topNode = top.second;
        // remove top element
        st.erase(st.begin());

        // traverse the neighbours of top element
        for (auto neighbour : adj[topNode])
        {
            if (nodeDist + neighbour.second < dist[neighbour.first])
            {
                // check if there are similar records b4 inserting new one
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                // if found erase it
                if (record != st.end())
                    st.erase(record);
                // update distance
                dist[neighbour.first] = nodeDist + neighbour.second;
                // insert record into set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}
