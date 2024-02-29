#include <gtest/gtest.h>
#include "Graph.cpp"

TEST(GraphTest, InstantiateEmptyGraph)
{
    Graph<int> g;
    ASSERT_EQ(g.size(), 0);
}

TEST(GraphTest, InstantiateFromVector)
{
    std::vector<std::pair<int, int>> edges({ {1, 2}, {1, 3}, {2, 3} });
    Graph<int> g(edges);
    ASSERT_EQ(g.size(), 3);
    ASSERT_TRUE(g.hasEdge(1, 2));
}

TEST(GraphTest, AddVertex)
{
    Graph<char> g;
    g.addVertex('a');

    ASSERT_EQ(g.size(), 1);
    ASSERT_FALSE(g.hasEdge('a', 'b'));
    ASSERT_EQ(g.getNeighbors('a').value().size(), 0);
}