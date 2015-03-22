#include <iostream>
#include <vector>
#include <algorithm>

// A set of inter-connected nodes.
typedef std::vector<unsigned> Component;

// Graph node.
struct Node {
    Node() : Traversed(false) {
    }
    std::vector<unsigned> Children;
    std::vector<unsigned> Parents;
    bool Traversed;
};

// Recursive portion of the FindGraphComponents implementation.
//   graph: The graph constructed in FindGraphComponents().
//   node_id: The index of the current element of graph.
//   component: Will receive nodes that comprise the current component.
static void FindConnectedNodes(std::vector<Node>& graph, unsigned node_id, Component& component) {

    Node& node = graph[node_id];
    if (!node.Traversed) {

        node.Traversed = true;
        component.push_back(node_id);

        for (auto i = node.Children.begin(); i != node.Children.end(); ++i)
            FindConnectedNodes(graph, *i, component);

        for (auto i = node.Parents.begin(); i != node.Parents.end(); ++i)
            FindConnectedNodes(graph, *i, component);

    }

}

// Finds self-connected sub-graphs (i.e. "components") on already-prepared graph.
std::vector<Component> FindGraphComponents(std::vector<Node>& graph) {

    std::vector<Component> components;
    for (unsigned node_id = 0; node_id < graph.size(); ++node_id) {
        if (!graph[node_id].Traversed) {
            components.push_back(Component());
            FindConnectedNodes(graph, node_id, components.back());
        }
    }

    return components;

}

// Finds self-connected sub-graphs (i.e. "components") on graph that should be read from the input stream.
//   in: The input test case.
std::vector<Component> FindGraphComponents(std::istream& in) {

    unsigned node_count, edge_count;
    std::cin >> node_count >> edge_count;

    // First build the structure that can be traversed recursively in an efficient way.
    std::vector<Node> graph(node_count); // Index in this vector corresponds to node ID.
    for (unsigned i = 0; i < edge_count; ++i) {
        unsigned from, to;
        in >> from >> to;
        graph[from].Children.push_back(to);
        graph[to].Parents.push_back(from);
    }

    return FindGraphComponents(graph);

}

void main() {

    size_t test_case_count;
    std::cin >> test_case_count;

    for (size_t test_case_i = 1; test_case_i <= test_case_count; ++test_case_i) {

        auto components = FindGraphComponents(std::cin);

        // Sort components by descending size and print them.
        std::sort(
            components.begin(),
            components.end(),
            [] (const Component& a, const Component& b) { return a.size() > b.size(); }
        );

        std::cout << "Case " << test_case_i <<  ": " << components.size() << " component (s) connected (s)" << std::endl;
        for (auto components_i = components.begin(); components_i != components.end(); ++components_i) {
            for (auto edge_i = components_i->begin(); edge_i != components_i->end(); ++edge_i)
                std::cout << *edge_i << ' ';
            std::cout << std::endl;
        }
        std::cout << std::endl;

    }

}
