//
// Created by Chingfung Yung on 12/6/2018.
//

#ifndef DATA_STRUCTURES_GRAPH_H
#define DATA_STRUCTURES_GRAPH_H

#include <random>
#include <functional>

using namespace std;

class Edge
{
    friend class Graph;

    int VerAdj;
    int cost;
    Edge *Link;
};

class Vertex
{
    friend class Graph;

    int VerName;
    Edge *adjacent;
};


class Graph
{
public:
    int number_vertex;
    int number_edge;
    Vertex *head;

    Graph()
    {
        number_vertex = 0;
        number_edge = 0;
        head = nullptr;
    }

    Graph(int vertex, int edge);

    int edge_cost(char a, char b);

    void insert(char a, char b, int x);

    void del(char a, char b);

    void find_first_vertex(char a);

    void dfs(char a);

    void dfs_no_output(char a);

    void bfs(char a);

    bool test_path(char a, char b);
};

Graph::Graph(int vertex, int edge)
{
    random_device rd;
    auto gen = std::mt19937(rd());
    uniform_int_distribution<int> dis(10, 50);
    auto randint = bind(dis, gen);

}


#endif //DATA_STRUCTURES_GRAPH_H
