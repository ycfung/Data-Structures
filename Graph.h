//
// Created by Chingfung Yung on 12/6/2018.
//

#ifndef DATA_STRUCTURES_GRAPH_H
#define DATA_STRUCTURES_GRAPH_H

#include <random>
#include <functional>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

int randint(int lower, int upper)
{
    random_device rd;
    auto gen = std::mt19937(rd());
    uniform_int_distribution<int> dis(lower, upper);
    return dis(gen);
}




class Edge
{
    friend class Graph;

public:
    int VerAdj;
    int weight;
    Edge *link;

    Edge() : VerAdj(0), weight(0), link(nullptr)
    {};

    Edge(int to, int cost) : VerAdj(to), weight(cost), link(nullptr)
    {};

};



class Vertex
{
    friend class Graph;

public:
    int VerName;
    Edge *adjacent;

    explicit Vertex(int a) : VerName(a), adjacent(nullptr)
    {};

};

/* A directed graph */
class Graph
{
public:

    int graphSize;

    vector<Vertex *> Head;

    Graph()
    { graphSize = 0; }


    /* Random graph */
    Graph(int vertex, int edge);


    ~Graph();

    /* Used in destructor */
    bool delAll(int a, int b);

    bool delAllEdge(Edge *node);


    bool delEdge(int a, int b);

    bool delNode(int a);


    Edge *FindNextEdge(int a, int b);

    int edge_weight(int a, int b);

    Vertex *insert_node(int a);

    Edge *insert_edge(int a, int b, int weight);

    string dfs(int a);

    string bfs(int a);

    inline int getFirstNeighbor(int a);

    inline int getNextNeighbor(int a, int b);

};

Graph::Graph(int vertex, int edge)
{
    Head.clear();
    graphSize = 0;

    for (int i = 0; i < vertex; i++)
    {
        auto ptr = new Vertex(1 + i);
        Head.push_back(ptr);
    }

    while (this->graphSize <= edge)
    {
        if (insert_edge(randint(1, vertex), randint(1, vertex), randint(10, 50)) != nullptr)
            graphSize += 1;
        else continue;
    }

}

Vertex *Graph::insert_node(int a)
{
    auto *ptr = new Vertex(a);
    Head.push_back(ptr);
    return ptr;
}

Edge *Graph::insert_edge(int a, int b, int weight)
{


    if (weight <= 0 or a == b)
        return nullptr;

    /* Search the two nodes */
    Vertex *from = nullptr, *to = nullptr;
    for (auto ptr: Head)
        if (ptr->VerName == a)
            from = ptr;

    for (auto ptr:Head)
        if (ptr->VerName == b)
            to = ptr;

    if (from == nullptr or to == nullptr)
        return nullptr;

    /* Create a new edge node at the end of the list if one doesn't exist*/
    Edge *temp = from->adjacent;

    if (from->adjacent == nullptr)
    {
        from->adjacent = new Edge(b, weight);
        graphSize += 1;
    }

    else
    {
        while (temp->link != nullptr)
        {
            if (temp->VerAdj == b) //if the edge already exists
                return nullptr;
            temp = temp->link;
        }
        if (temp->VerAdj == b)
            return nullptr;
        temp->link = new Edge(b, weight);
    }
    return temp;

}

Graph::~Graph()
{
    for (auto ptr:this->Head)
        delAllEdge(ptr->adjacent);

    for (auto ptr:this->Head)
        delete (ptr);

    /* To really release the space allocated to this vector */
    vector<Vertex *>(Head).swap(Head); //NOLINT
}

int Graph::edge_weight(int a, int b) //NOLINT
{
    Vertex *from = nullptr;
    Edge *to = nullptr;
    for (auto ptr: Head)
        if (ptr->VerName == a)
            from = ptr;
    if (from == nullptr)
        return 0;
    to = from->adjacent;
    while (to != nullptr)
    {
        if (to->VerAdj == b)
            return to->weight;
        else to = to->link;
    }
    return 0;


}


bool Graph::delEdge(int a, int b)
{
    bool flag1 = false, flag2 = false;
    Edge *ptra = nullptr;
    Vertex *ver = nullptr;

    for (auto ptr:Head)
    {
        if (ptr->VerName == a)
        {
            flag1 = true;
            ptra = ptr->adjacent;
            ver = ptr;
            break;
        }
        if (ptr->VerName == b)
        {
            flag2 = true;
            break;
        }
    }

    if (!flag1 or !flag2)
        return false;

    /* If the first edge is about to delete */
    if (ptra->VerAdj == b)
    {
        Edge *temp = ptra;
        ver->adjacent = ver->adjacent->link;
    }

    /* If other edge is about to delete */
    while (ptra->link != nullptr)
        if (ptra->link->VerAdj == b)
        {
            Edge *temp = ptra->link;
            ptra = ptra->link->link;
            delete temp;
        }

    return false;

}

bool Graph::delNode(int a)
{
    /* Delete a from vertex list */
    vector<Vertex *>::iterator iter;
    for (iter = Head.begin(); iter != Head.end(); iter++)
        if ((*iter)->VerName == a)
        {
            delete *iter;
            iter = Head.erase(iter);
            return true;
        }

    /* Delete edges connected to a */
    for (auto ptr: Head)
        delEdge(a, ptr->VerName);
    for (auto ptr: Head)
        delEdge(ptr->VerName, a);


    return false;
}

bool Graph::delAllEdge(Edge *node)
{
    if (node->link != nullptr)
        delAllEdge(node->link);
    delete node;
    return true;
}


bool Graph::delAll(int a, int b)
{
    Vertex *from = nullptr;
    for (auto ptr:Head)
        if (ptr->VerName == a)
            from = ptr;
    if (from == nullptr)
        return false;
    Edge *pre = from->adjacent, *current = from->adjacent;

    if (from->adjacent->weight == b)
    {
        from->adjacent->link = from->adjacent->link->link;
        delete current;
        return true;
    }

    else
        while (current != nullptr)
        {
            if (current->VerAdj == b)
            {
                pre->link = pre->link->link;
                delete current;
                return true;
            }
            pre = current;
            current = current->link;
        }
    return false;
}


string Graph::bfs(int a)
{
    string result;
    auto *visited = new int[graphSize];
    for (int k = 0; k < graphSize; k++)
        visited[k] = 0;
    stringstream stream;
    stream << a;
    result += stream.str();
    visited[a] = 1;
    queue<int> q;
    q.push(a);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        int w = getFirstNeighbor(v);
        while (w != -1)
        {
            if (visited[w] != 1)
            {
                result += char(w);
                visited[w] = 1;
                q.push(w);
            }
            w = getNextNeighbor(v, w);
        }
    }
    delete[] visited;
    return result;
}

int Graph::getFirstNeighbor(int a)
{
    for (auto ptr:Head)
        if (ptr->VerName == a)
            return ptr->adjacent->VerAdj;
    return -1;
}

int Graph::getNextNeighbor(int a, int b)
{
    Vertex *temp = nullptr;
    for (auto ptr:Head)
        if (ptr->VerName == a)
            temp = ptr;

    if (temp == nullptr)
        return -1;

    Edge *p = temp->adjacent;

    while (p != nullptr)
    {
        if (p->VerAdj == b and p->link != nullptr)
            return p->link->VerAdj;

        else p = p->link;
    }

    return -1;

}


string Graph::dfs(int a)
{
    stack<int> s;
    string result;
    auto *visited = new int[graphSize];
    for (int k = 0; k < graphSize; k++)
        visited[k] = 0;
    for (int k = 0; k < graphSize; k++)
    {
        stringstream stream;
        stream << visited[k];
        result += stream.str();
    }
    s.push(a);
    int w, k;
    while (!s.empty())
    {
        w = s.top();
        s.pop();
        visited[w] = 1;
        stringstream stream;
        stream << w;
        result += stream.str();
        k = getFirstNeighbor(w);
        while (k != -1)
        {
            if (visited[k] == 0)
                s.push(k);
            k = getNextNeighbor(w, k);
        }
    }
    delete[] visited;
    return result;
}

Edge *Graph::FindNextEdge(int a, int b)
{
    Edge *temp = nullptr, *target = nullptr;
    for (auto ptr:Head)
        if (ptr->VerName == a)
            temp = ptr->adjacent;

    while (temp != nullptr)
    {
        if (temp->VerAdj == b)
            target = temp;
        else temp = temp->link;
    }

    if(target == nullptr)
        return nullptr

    if (target->link != nullptr)
        return target;
}


#endif //DATA_STRUCTURES_GRAPH_H
