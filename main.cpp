#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Vertex
{
public:
    vector<pair<int, int>> adj;
    Vertex();
    void addEdge(int to, int weight);
};

Vertex::Vertex()
{
}

void Vertex::addEdge(int to, int weight)
{
    this->adj.push_back(make_pair(to, weight));
}

vector<int> trace1; 


vector<int> traceFunction(vector<int> pre, int v)
{
    stack<int> stack;
    vector<bool> contains(pre.size(), false);
    while (!contains[v])
    {
        stack.push(v);
        contains[v] = true;
        v = pre[v];
    }

    vector<int> cycle;
    cycle.push_back(v);
    while (stack.top() != v)
    {
        int a = stack.top();
        stack.pop();
        cycle.push_back(a);
    }
    cycle.push_back(v);
    return cycle;
}

bool detectCycle(int N, vector<int> pre)
{
    vector<int> vec;

    vector<bool> onStack(N * 2, false);
    vector<bool> visited(N * 2, false);

    for (int i = 0; i < N * 2; i++)
    {
        if (!visited[i])
        {
            for (int j = i; j != -1; j = pre[j])
            {
                if (!visited[j])
                {
                    visited[j] = true;
                    vec.push_back(j);
                    onStack[j] = true;
                }
                else
                {
                    if (onStack[j])
                    {
                        trace1 = traceFunction(pre, j);
                        return true;
                    }
                    break;
                }
            }
            for (int j : vec)
            {
                onStack[j] = false;
            }
            vec.clear();
        }
    }
    return false;
}

bool spfa(int N, vector<Vertex> verteces, vector<int> &pre)
{
    vector<int> dis(N * 2, 0);
    vector<bool> inQueue(N * 2, true);
    queue<int> queue;
    for (int i = 0; i < N * 2; i++)
    {
        queue.push(i);
    }
    int iter = 0;
    while (!queue.empty())
    {
        int u = queue.front();
        queue.pop();
        inQueue[u] = false;
        for (auto a : verteces[u].adj)
        {
            if (dis[u] + a.second < dis[a.first])
            {
                pre[a.first] = u;
                dis[a.first] = dis[u] + a.second;
                if (++iter == N)
                {
                    iter = 0;
                    if (detectCycle(N, pre))
                    {
                        return true;
                    }
                }
                if (!inQueue[a.first])
                {
                    queue.push(a.first);
                    inQueue[a.first] = true;
                }
            }
        }
    }
    if (detectCycle(N, pre))
    {
        return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    string inputFile = argv[1];
    string outputFile = argv[2]; 

  ifstream infile;
    infile.open(inputFile);

    ofstream outfile;
    outfile.open(outputFile);

    int T;
    infile >> T;

    int inf = 1;
    for (int i = 0; i < T; i++)
    {
        int N;
        infile >> N;

        vector<Vertex> verteces(N * 2);

        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                int minusCost;
                infile >> minusCost;
                inf += minusCost;
                if (j == k)
                {
                    verteces[j + N].addEdge(k, minusCost);
                }
                else
                {
                    verteces[j].addEdge(k + N, 0 - minusCost);
                }
            }
        }
        vector<int> pre(N * 2, -1);

        bool loop = spfa(N, verteces, pre);
        while (loop)
        {
            for (int t = 0; t < N * 2; t++)
            {
                pre[t] = -1;
            }

            loop = spfa(N, verteces, pre);

            if (!loop)
            {
                break;
            }

            for (int l = 0; l < trace1.size() - 1; l++)
            {
                int to = trace1[l + 1];
                int index = -1;
                for (int m = 0; m < verteces[trace1[l]].adj.size(); m++)
                {
                    if (verteces[trace1[l]].adj[m].first == to)
                    {
                        index = m;
                    }
                }

                int weight = verteces[trace1[l]].adj[index].second;
                verteces[trace1[l]].adj.erase(verteces[trace1[l]].adj.begin() + index);
                verteces[to].adj.push_back(make_pair(trace1[l], 0 - weight));
            }
        }
        int result = 0;
        for (int i = 0; i < N; i++)
        {
            result += verteces[N + i].adj[0].second;
        }
        outfile << result << endl;
    }

    return 0;
}
