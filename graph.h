#ifndef GRAPH_H
#define GRAPH_H

#include "Generic_files/queue/queue.h" 
#include"minheap.h"
#include"Generic_files/queue/array.h"

struct HeapNode
{
public:
    int distance;
    int vertex;

    // Default constructor
    HeapNode() : distance(0), vertex(0) {}

    // Parameterized constructor
    HeapNode(int d, int v) : distance(d), vertex(v) {}

    // Comparison operators
    bool operator>(const HeapNode &other) const
    {
        return distance > other.distance;
    }

    bool operator<(const HeapNode &other) const
    {
        return distance < other.distance;
    }

    bool operator==(const HeapNode &other) const
    {
        return distance == other.distance && vertex == other.vertex;
    }
};




template <typename T>
class Graph
{
private:
    int V;
    T *vertices; 
    int **adjacency_matrix;

public:
    // ---------------- CONSTRUCTOR ----------------
    Graph(int verticesCount)
    {
        V = verticesCount;

        vertices = new T[V];

        adjacency_matrix = new int *[V];
        for (int i = 0; i < V; i++)
        {
            adjacency_matrix[i] = new int[V];
            for (int j = 0; j < V; j++)
                adjacency_matrix[i][j] = 0;
        }
    }

    // ---------------- DESTRUCTOR ----------------
    ~Graph()
    {
        for (int i = 0; i < V; i++)
            delete[] adjacency_matrix[i];

        delete[] adjacency_matrix;
        delete[] vertices;
    }

    // ---------------- SET VERTEX VALUE ----------------
    void setVertex(int index, T value)
    {
        if (index >= 0 && index < V)
            vertices[index] = value;
    }

    // ---------------- CHECK VALID VERTEX ----------------
    bool isValidVertex(int idx) const
    {
        return (idx >= 0 && idx < V);
    }

    // ---------------- ADD EDGE ----------------
    void addEdge(int source, int dest,int weight)
    {
        if (!isValidVertex(source) || !isValidVertex(dest))
        {
            cout << "Invalid source/destination\n";
            return;
        }

        adjacency_matrix[source][dest] =weight;
        adjacency_matrix[dest][source] =weight;
    }

    // ---------------- DELETE EDGE ----------------
    void deleteEdge(int source, int dest)
    {
        if (!isValidVertex(source) || !isValidVertex(dest))
        {
            cout << "Invalid source/destination\n";
            return;
        }

        adjacency_matrix[source][dest] = 0;
        adjacency_matrix[dest][source] = 0;
    }

    // ---------------- UPDATE EDGE ----------------
    void updateEdge(int old_s, int old_d, int new_s, int new_d, int weight = 1)
    {
        if (isValidVertex(old_s) && isValidVertex(old_d))
        {
            adjacency_matrix[old_s][old_d] = 0;
            adjacency_matrix[old_d][old_s] = 0;
        }

        if (isValidVertex(new_s) && isValidVertex(new_d))
        {
            adjacency_matrix[new_s][new_d] = weight;
            adjacency_matrix[new_d][new_s] = weight;
        }
    }

    // ---------------- CHECK IF CONNECTED ----------------
    bool isConnected(int u, int v)
    {
        if (!isValidVertex(u) || !isValidVertex(v))
            return false;

        return adjacency_matrix[u][v] == 1;
    }

    // ---------------- GET NEIGHBORS (WITHOUT VECTOR) ----------------
    int *getNeighbors(int node, int &count)
    {
        count = 0;

        if (!isValidVertex(node))
            return nullptr;

        // First count neighbors
        for (int i = 0; i < V; i++)
            if (adjacency_matrix[node][i] == 1)
                count++;

        if (count == 0)
            return nullptr;

        // Now create array
        int *neighbors = new int[count];
        int idx = 0;

        for (int i = 0; i < V; i++)
            if (adjacency_matrix[node][i] == 1)
                neighbors[idx++] = i;

        return neighbors;
    }

    // ---------------- DEGREE ----------------
    int getDegree(int vtx)
    {
        if (!isValidVertex(vtx))
        {
            cout << "Invalid vertex\n";
            return -1;
        }

        int degree = 0;
        for (int i = 0; i < V; i++)
        {
            if (adjacency_matrix[vtx][i] == 1)
                degree++;
        }

        return degree;
    }

    // ---------------- BFS (without vector) ----------------
    void BFS(int start)
    {
        if (!isValidVertex(start))
            return;

        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        LinkedQueue<int> q;

        visited[start] = true;
        q.enqueue(start);

        while (!q.isEmpty()) 
        {
            int node = q.dequeue(); 
            cout << node << " ";

            for (int i = 0; i < V; i++)
            {
                if (adjacency_matrix[node][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    q.enqueue(i);
                }
            }
        }

        delete[] visited;
    }

    void DFSUtil(int node, bool visited[])
    {
        visited[node] = true;
        cout << node << " ";

        for (int i = 0; i < V; i++)
        {
            if (adjacency_matrix[node][i] == 1 && !visited[i])
            {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int start)
    {
        if (!isValidVertex(start))
            return;

        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        DFSUtil(start, visited);

        delete[] visited;
    }



    // ---------------- DIJKSTRA -----------------

    void dijkstra(int src)
    {
        const int INF = 1e9;
        int *dist = new int[V];
        bool *visited = new bool[V];

        for (int i = 0; i < V; i++)
        {
            dist[i] = INF;
            visited[i] = false;
        }
        dist[src] = 0;

        // HeapNode ka MinHeap
        MinHeap<HeapNode> pq(V);
        pq.insert(HeapNode(0, src));

        while (!pq.isEmpty())
        {
            HeapNode top = pq.extractMin();
            int u = top.vertex;

            if (visited[u])
                continue;

            visited[u] = true;

            for (int v = 0; v < V; v++)
            {
                if (adjacency_matrix[u][v] > 0)
                {
                    int w = adjacency_matrix[u][v];
                    if (dist[u] + w < dist[v])
                    {
                        dist[v] = dist[u] + w;
                        pq.insert(HeapNode(dist[v], v));
                    }
                }
            }
        }

        // Print results
        cout << "\n=== Dijkstra Results ===" << endl;
        cout << "Source: " << src << endl;
        for (int i = 0; i < V; i++)
        {
            cout << "Node " << i << ": ";
            if (dist[i] == INF)
                cout << "INF (unreachable)";
            else
                cout << dist[i];
            cout << endl;
        }

        delete[] dist;
        delete[] visited;
    }

    // ---------------- DISPLAY GRAPH ----------------
    void displayGraph() const
    {
        cout << "Adjacency Matrix:\n";

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
                cout << adjacency_matrix[i][j] << " ";

            cout << endl;
        }
    }
};

#endif
