#include <bits/stdc++.h>

using namespace std;

//构造vertex类
class Vertex
{
public:
    int val; //顶点的值

    //构造函数
    Vertex(int value) : val(value) {}
};

class GraphAdjList
{
public:
    //邻接表，key:顶点, value:该顶点的所有邻接顶点
    unordered_map<Vertex*, vector<Vertex*>> adjList;  //这里是使用了哈希表，建议结合先前章节理解，adjList本身有多个key，每个key都对应有value

    //在vector中删除指定节点
    void remove(vector<Vertex*>& vec, Vertex* vet)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == vet)
            {
                vec.erase(vec.begin() + i); //这里实质上是将vec[i] == vet对应的实例删除了，所以在对应图示中，左边列表和右边对应"链表"中相应实例均被删除了
            }
        }
    }

    //构造方法
    GraphAdjList(const vector<vector<Vertex*>>& edges)
    {
        //添加所有顶点和边
        for (const vector<Vertex*>& edge : edges)
        {
            addVertex(edge[0]);
            addVertex(edge[1]);
            addEdge(edge[0], edge[1]);
        }
    }

    //获取顶点数量
    int size()
    {
        return adjList.size(); //这里是返回了adjList的key数量, 即顶点数量
    }

    //添加边
    void addEdge(Vertex* vet1, Vertex* vet2)
    {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
            throw invalid_argument("不存在顶点"); //throw用于抛出异常，invalid_arguement是一个标准库异常类，表示传参无效
        //添加边 vet1 - vet2
        adjList[vet1].push_back(vet2);
        adjList[vet2].push_back(vet1);
    }

    //删除边
    void removeEdge(Vertex* vet1, Vertex* vet2)
    {
        if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
            throw invalid_argument("不存在顶点");
        //删除边 vet1 - vet2
        remove(adjList[vet1], vet2); // remove(列表，值)函数表示从列表中删去对应值, 这里含义则是删去vet1对应"链表"中的vet2
        remove(adjList[vet2], vet1);
    }

    //添加顶点
    void addVertex(Vertex* vet)
    {
        if (adjList.count(vet))  //若已经存在该顶点则直接返回
            return;
        //在临界表中添加一个新链表，这里实质上是声明一个新键值对，其中键为该节点，值为一新的空链表
        adjList[vet] = vector<Vertex*>();
    }

    //删除顶点
    void removeVertex(Vertex* vet)
    {
        if (!adjList.count(vet))
            throw invalid_argument("不存在顶点");
        //在邻接表中删除顶点vet对应的链表
        adjList.erase(vet);
        //遍历其他顶点的链表，删除所有包含vet的边
        for (auto& adj : adjList)
        {
            remove(adj.second, vet);
        }
    }

};