#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Tree {
    class node {
        int val;
        vector<node*> neighbours;

        node(int val) : val(val) {}
        friend class Tree;
    };

    map<int, vector<node*>> mapping;
    vector<node*> nodes;

public:
    Tree(int n) {
        nodes.resize(n + 1, nullptr);
        for (int i = 1; i <= n; ++i) {
            nodes[i] = new node(i);
        }
    }

    void addEdge(int a, int b) {
        node* nodeA = nodes[a];
        node* nodeB = nodes[b];
        mapping[a].push_back(nodeB);
    }

    int calculateMaxRoutes() {
        int count = 0;
        queue<node*> q;
        map<node*, bool> visited;

        q.push(nodes[1]);
        visited[nodes[1]] = true;

        while (!q.empty()) {
            node* current = q.front();
            q.pop();

            if (mapping[current->val].size() == 0) {
                ++count;
            }

            for (node* neighbour : mapping[current->val]) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }

        return count;
    }
};

int main() {
    int n;
    cin >> n;

    Tree tree(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v);
    }

    cout << tree.calculateMaxRoutes() << endl;

    return 0;
}
