#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <limits>

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

    // 2.
    bool dfs_has_cycle (const Graph& graph, int vertex, int parent,
                        std::unordered_set<int>& visited)
    {
        visited.insert (vertex);

        if (graph.find (vertex) != graph.end())
        {
            for (int neighbor : graph.at (vertex))
            {
                if (neighbor == parent)
                    continue;

                if (visited.find (neighbor) != visited.end())
                    return true;

                if (dfs_has_cycle (graph, neighbor, vertex, visited))
                    return true;
            }
        }

        return false;
    }

    bool has_cycle (const Graph& graph)
    {
        std::unordered_set<int> visited;

        for (const auto& [vertex, neighbors] : graph)
        {
            if (visited.find (vertex) == visited.end())
            {
                if (dfs_has_cycle (graph, vertex, -1, visited))
                    return true;
            }
        }

        return false;
    }

    // 3.
    bool is_tree (const Graph& graph, int start)
    {
        if (graph.empty())
            return false;

        std::unordered_set<int> visited;
        std::queue<int> queue;
        std::unordered_map<int, int> parent;

        queue.push (start);
        parent[start] = -1;

        while (!queue.empty())
        {
            int vertex = queue.front();
            queue.pop();
            visited.insert (vertex);

            if (graph.find (vertex) != graph.end())
            {
                for (int neighbor : graph.at (vertex))
                {
                    if (visited.find (neighbor) == visited.end())
                    {
                        queue.push (neighbor);
                        parent[neighbor] = vertex;
                    }
                    else
                    {
                        if (parent[vertex] != neighbor)
                            return false;
                    }
                }
            }
        }

        return visited.size() == graph.size();
    }

    // 4.
    using WeightedGraph = std::unordered_map<int, std::vector<std::pair<int, int>>>;

    std::unordered_map<int, int> dijkstra (const WeightedGraph& graph, int start)
    {
        std::unordered_map<int, int> distances;

        for (const auto& [vertex, neighbors] : graph)
            distances[vertex] = std::numeric_limits<int>::max();

        distances[start] = 0;

        using Pair = std::pair<int, int>;
        std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;

        pq.push ({0, start});

        while (!pq.empty())
        {
            auto [current_distance, current_vertex] = pq.top();
            pq.pop();

            if (current_distance > distances[current_vertex])
                continue;

            if (graph.find (current_vertex) != graph.end())
            {
                for (const auto& [neighbor, weight] : graph.at (current_vertex))
                {
                    int distance = current_distance + weight;

                    if (distance < distances[neighbor])
                    {
                        distances[neighbor] = distance;
                        pq.push ({distance, neighbor});
                    }
                }
            }
        }

        return distances;
    }

}
