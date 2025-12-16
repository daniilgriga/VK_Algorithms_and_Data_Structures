#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace algs
{
    // 1.1.
    using Graph = std::unordered_map<int, std::vector<int>>;

    void dfs_component (const Graph& graph, int vertex,
                        std::unordered_set<int>& visited,
                        std::vector<int>& component)
    {
        visited.insert (vertex);
        component.push_back (vertex);

        if (graph.find (vertex) != graph.end())
        {
            for (int neighbor : graph.at (vertex))
            {
                if (visited.find (neighbor) == visited.end())
                    dfs_component (graph, neighbor, visited, component);
            }
        }
    }

    std::vector<std::vector<int>> find_connected_components (const Graph& graph)
    {
        std::unordered_set<int> visited;
        std::vector<std::vector<int>> components;

        for (const auto& [vertex, neighbors] : graph)
        {
            if (visited.find (vertex) == visited.end())
            {
                std::vector<int> component;
                dfs_component (graph, vertex, visited, component);
                components.push_back (component);
            }
        }

        return components;
    }

    // 1.2.
    void dfs_color (const Graph& graph, int vertex,
                    std::unordered_map<int, int>& colors,
                    int color)
    {
        colors[vertex] = color;

        if (graph.find (vertex) != graph.end())
        {
            for (int neighbor : graph.at (vertex))
            {
                if (colors.find (neighbor) == colors.end())
                    dfs_color (graph, neighbor, colors, color);
            }
        }
    }

    std::unordered_map<int, int> color_connected_components (const Graph& graph)
    {
        std::unordered_map<int, int> colors;
        int color = 0;

        for (const auto& [vertex, neighbors] : graph)
        {
            if (colors.find (vertex) == colors.end())
            {
                color++;
                dfs_color (graph, vertex, colors, color);
            }
        }

        return colors;
    }

}
