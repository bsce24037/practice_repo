#include <iostream>
#include <string>
using namespace std;
template<typename T>
class Graph {
private:
    int V;
    int currentSize;
    T* nodes;
    int** adjacency;

public:
    Graph(int vertex_count) {
        V = vertex_count;
        currentSize = 0;
        nodes = new T[V];
        adjacency = new int* [V];
        for (int i=0;i<V;i++) {
            adjacency[i] = new int[V]{0};
        }
    }

    ~Graph() {
        for (int i=0;i<V;i++)
            delete[] adjacency[i];
        delete[] adjacency;
        delete[] nodes;
    }
    int getNodeIndex(T value) {
        for(int i=0;i<currentSize;i++){
            if(nodes[i]==value)
                return i;
        }
        return -1; 
    }

    void addNode(T value) {
        if(getNodeIndex(value) == -1){ 
            if(currentSize >= V) {
                cout << "Graph full. Cannot add more nodes."<<endl;;
                return;
            }
            nodes[currentSize]=value;
            currentSize++;
        }
    }

    void addEdge(T u, T v) {
        int ui = getNodeIndex(u);
        int vi = getNodeIndex(v);
        if(ui!=-1&&vi!=-1){
            adjacency[ui][vi] = 1;
            adjacency[vi][ui] = 1;
        }
    }

    bool hasEdge(T u, T v) {
        int ui = getNodeIndex(u);
        int vi = getNodeIndex(v);
        if(ui!=-1&&vi!=-1){
            return adjacency[ui][vi] == 1;
        }
        return false;
    }

    void displayGraph() {
        cout << "Adjacency Matrix:\n";
        for(int i=0;i<currentSize;i++){
            for(int j=0;j<currentSize;j++)
                cout<<adjacency[i][j]<<" ";
            cout<<endl;
        }
    }

    int getNodeCount() {
        return currentSize;
    }
};