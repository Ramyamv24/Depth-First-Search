#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
    }

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }

        if (mp.find(node) == mp.end()) {
            mp[node] = new Node(node->val, {});

            for (auto adj : node->neighbors) {
                mp[node]->neighbors.push_back(cloneGraph(adj));
            }
        }

        return mp[node];
    }
};

// DFS to print graph
void printGraph(Node* node, unordered_map<Node*, bool>& visited) {
    if (node == NULL || visited[node])
        return;

    visited[node] = true;

    cout << "Node " << node->val << " -> ";

    for (auto neighbor : node->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << endl;

    for (auto neighbor : node->neighbors) {
        printGraph(neighbor, visited);
    }
}

int main() {
    /*
        Graph:

            1 ----- 2
            |       |
            |       |
            4 ----- 3
    */

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    cout << "Original Graph:\n";
    unordered_map<Node*, bool> visited1;
    printGraph(n1, visited1);

    Solution obj;
    Node* clonedGraph = obj.cloneGraph(n1);

    cout << "\nCloned Graph:\n";
    unordered_map<Node*, bool> visited2;
    printGraph(clonedGraph, visited2);

    return 0;
}