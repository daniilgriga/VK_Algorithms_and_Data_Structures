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

int main()
{
    test_task_1();

    return 0;
}
