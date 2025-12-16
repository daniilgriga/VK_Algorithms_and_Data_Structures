#include <iostream>

#include "algorithms.hpp"

void test_task_1()
{
    algs::Graph graph = {
        {1, {2, 3}},
        {2, {1, 3}},
        {3, {1, 2}},
        {4, {6, 7}},
        {5, {6, 7}},
        {6, {4, 5, 7}},
        {7, {4, 5, 6}},
        {8, {11}},
        {9, {10, 11}},
        {10, {9}},
        {11, {8, 9}}
    };

    std::cout << "[1.1]: Connected Components (arrays):" << std::endl;
    auto components = algs::find_connected_components (graph);
    std::cout << "Total components: " << components.size() << std::endl;
    for (size_t i = 0; i < components.size(); i++)
    {
        std::cout << "Component " << (i + 1) << ": ";
        for (size_t j = 0; j < components[i].size(); j++)
        {
            std::cout << components[i][j];
            if (j < components[i].size() - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n[1.2]: Connected Components (coloring):" << std::endl;
    auto colors = algs::color_connected_components (graph);
    std::cout << "Vertex -> Color mapping:" << std::endl;
    for (const auto& [vertex, color] : colors)
        std::cout << "Vertex " << vertex << " -> Color " << color << std::endl;

    std::cout << std::endl;
}

void test_task_2()
{
    algs::Graph graph_with_cycle = {
        {1, {2, 4}},
        {2, {1, 3}},
        {3, {2, 4}},
        {4, {1, 3}}
    };

    algs::Graph graph_no_cycle = {
        {1, {2}},
        {2, {1, 3, 4}},
        {3, {2}},
        {4, {2}}
    };

    std::cout << "[2]: Has cycle (graph with cycle): "
              << (algs::has_cycle (graph_with_cycle) ? "true" : "false") << std::endl;

    std::cout << "[2]: Has cycle (graph without cycle): "
              << (algs::has_cycle (graph_no_cycle) ? "true" : "false") << std::endl;

    std::cout << std::endl;
}


int main()
{
    test_task_1();
    test_task_2();

    return 0;
}
