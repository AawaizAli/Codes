#include <iostream>
#include <vector>
#include <limits>

#define INF std::numeric_limits<int>::max()

class Node {
public:
    int id;
    std::vector<std::pair<Node*, int> > neighbors; // pair of neighbor node and edge weight
    
    Node(int _id) : id(_id) {}
};

class Graph {
public:
    std::vector<Node*> nodes;

    void addNode(int id) {
        Node* newNode = new Node(id);
        nodes.push_back(newNode);
    }

    void addEdge(Node* u, Node* v, int weight) {
        u->neighbors.push_back(std::make_pair(v, weight));
        v->neighbors.push_back(std::make_pair(u, weight)); // If undirected graph
    }
};

Node* findMinDistanceNode(std::vector<Node*>& nodes, std::vector<bool>& visited, std::vector<int>& distance) {
    int minDistance = INF;
    Node* minNode = nullptr;

    for (Node* node : nodes) {
        if (!visited[node->id] && distance[node->id] < minDistance) {
            minDistance = distance[node->id];
            minNode = node;
        }
    }

    return minNode;
}

void dijkstra(Graph& graph, Node* source) {
    std::vector<bool> visited(graph.nodes.size(), false);
    std::vector<int> distance(graph.nodes.size(), INF);

    distance[source->id] = 0;

    for (size_t i = 0; i < graph.nodes.size() - 1; ++i) {
        Node* curr = findMinDistanceNode(graph.nodes, visited, distance);
        
        visited[curr->id] = true;

        for (auto neighbor : curr->neighbors) {
            Node* adjNode = neighbor.first;
            int weight = neighbor.second;

            if (!visited[adjNode->id] && distance[curr->id] != INF && distance[curr->id] + weight < distance[adjNode->id]) {
                distance[adjNode->id] = distance[curr->id] + weight;
            }
        }
    }

    // Outputting the shortest distances from the source node
    std::cout << "Shortest distances from node " << source->id << ":\n";
    for (size_t i = 0; i < graph.nodes.size(); ++i) {
        std::cout << "To node " << i << ": " << distance[i] << "\n";
    }
}

int main() {
    Graph graph;

    // Adding nodes to the graph
    for (int i = 0; i < 5; ++i) {
        graph.addNode(i);
    }

    // Adding edges with weights
    graph.addEdge(graph.nodes[0], graph.nodes[1], 4);
    graph.addEdge(graph.nodes[0], graph.nodes[2], 1);
    graph.addEdge(graph.nodes[1], graph.nodes[2], 2);
    graph.addEdge(graph.nodes[1], graph.nodes[3], 5);
    graph.addEdge(graph.nodes[2], graph.nodes[3], 8);
    graph.addEdge(graph.nodes[2], graph.nodes[4], 10);
    graph.addEdge(graph.nodes[3], graph.nodes[4], 2);

    // Perform Dijkstra's algorithm starting from node 0
    dijkstra(graph, graph.nodes[0]);

    return 0;
}
