#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; ++i)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ult_p_u = findParent(u);
        int ult_p_v = findParent(v);

        if (ult_p_u == ult_p_v)
            return;

        if (rank[ult_p_u] < rank[ult_p_v])
        {
            parent[ult_p_u] = ult_p_v;
        }
        else if (rank[ult_p_v] < rank[ult_p_u])
        {
            parent[ult_p_v] = ult_p_u;
        }
        else
        {
            parent[ult_p_u] = ult_p_v;
            rank[ult_p_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(3, 4);
    ds.unionByRank(6, 5);
    if (ds.findParent(5) == ds.findParent(3))
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not Same" << endl;
    }
    ds.unionByRank(6, 4);
    if (ds.findParent(5) == ds.findParent(3))
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not Same" << endl;
    }

    return 0;
}