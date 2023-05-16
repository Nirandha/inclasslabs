#include <iostream>
#include <list>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Node {
    int label;
    list<int> neighbours;
};

struct Graph {
    int n = 8;
    Node* nodes = new Node[n];

    void initializeNodes() {
        for (int i = 0; i < n; i++) {
            nodes[i].label = i + 1;
        }
    }

    bool hasEdge(int u, int v) {
        // Check if the edge already exists in the adjacency list of u
        for (int neighbour : nodes[u - 1].neighbours) {
            if (neighbour == v) {
                return true;
            }
        }
        return false;
    }

    void addEdge(int u, int v) {
        if (hasEdge(u, v)) {
            return;  // Edge already exists, so return without adding
        }

        // Add v to u's neighbours
        nodes[u - 1].neighbours.push_back(v);

        // Add u to v's neighbours
        nodes[v - 1].neighbours.push_back(u);
    }

    void print() {
        for (int i = 0; i < n; i++) {
            cout << nodes[i].label << "\t";

            unordered_set<int> uniqueNeighbours;
            for (int neighbour : nodes[i].neighbours) {
                uniqueNeighbours.insert(neighbour);
            }

            vector<int> sortedNeighbours(uniqueNeighbours.begin(), uniqueNeighbours.end());
            sort(sortedNeighbours.begin(), sortedNeighbours.end());

            for (int neighbour : sortedNeighbours) {
                cout << neighbour << ",";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph* g = new Graph;
    g->initializeNodes();

    // Add edges to the graph
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(1, 4);
    g->addEdge(1, 5);
    g->addEdge(2, 3);
    g->addEdge(2, 6);
    g->addEdge(4, 6);
    g->addEdge(4, 7);
    g->addEdge(4, 8);
    g->addEdge(5, 6);
    g->addEdge(5, 7);
    g->addEdge(5, 8);

    // Print the graph adjacency list
    g->print();

    delete g;
    return 0;
}
