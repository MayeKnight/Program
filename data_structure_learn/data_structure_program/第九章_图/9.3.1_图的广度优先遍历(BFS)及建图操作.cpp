//上一节内容调用
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

    //构造方法(或构造函数)是类的一种特殊方法, 用于初始化类的对象. 即构造方法就是使用类的方法
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

//本节内容如下
//创建图
int main()
{
    //创建顶点
    Vertex* v1 = new Vertex(1);  //动态地创建一个'Vertex'类对象, 并将指针赋给'v1', 其中'new'是一个运算符, 用于在堆内存中动态分配内存, 'Vertex(1)'是'Vertex'类的构造函数, 它将'val'成员变量初始化为'1', 且使用'new'运算符分配的内存是在堆上分配的, 这意味着该内存的生命周期不受作用域的限制, 直到显式地释放它, 可以使用'delete'运算符来释放内存, 如'delete v1;' 以防止内存泄漏
    Vertex* v2 = new Vertex(2);
    Vertex* v3 = new Vertex(3);
    Vertex* v4 = new Vertex(4);

    //创建边的列表(以满足调用GraphAdjList类的构造函数的格式)
    vector<vector<Vertex*>> edges =
    {
        {v1, v2},
        {v1, v3},
        {v2, v4},
        {v3, v4}
    };

    //创建图
    GraphAdjList graph(edges);

    //清理内存
    delete v1;
    delete v2;
    delete v3;
    delete v4;
}

//图的广度优先遍历
//使用邻接表来表示图, 以便获取指定顶点的所有邻接顶点
vector<Vertex* > graphBFS(GraphAdjList& graph, Vertex* startVet)
{
    //顶点遍历序列
    vector<Vertex* > res;

    //哈希集合用于记录已被访问过的顶点
    unordered_set<Vertex* > visited = { startVet };

    //队列用于实现BFS
    queue<Vertex* > que;
    que.push(startVet);

    //以顶点vet为起点, 循环直至访问完所有顶点
    while (!que.empty())
    {
        Vertex* vet = que.front();
        que.pop(); //队首元素出队
        res.push_back(vet); //记录访问顶点

        //遍历该顶点的所有邻接顶点
        for (auto adjVet : graph.adjList[vet])  //前面声明了graph为一个GraphAdjList类, 其中包含adjList哈希表用于某顶点的所有邻接顶点, 这里adjList[vet]即顶点vet的所有邻接顶点, 其数据类型为vector<Vertex* >
        {
            if (visited.count(adjVet))  //这里.count为STL标准模版库中如unordered_map和unordered_set的成员函数, 用于检查容器中是否存在特定的元素, 并返回该元素的出现次数.
                continue; //跳过已访问的节点, 'continue;'是一个控制语句, 用于再循环中跳过当前迭代的剩余部分, 并立即开始下一次迭代, 通常用于在条件判断中, 以便在满足特定条件时跳过某些操作.
            que.push(adjVet); //只入队未访问的顶点
            visited.emplace(adjVet);  //标记该顶点已被访问, emplace是一个用于在容器中直接构造元素的成员函数, 通常用于STL标准模版库中的容器, 如 vector, map, unordered_map, unordered_set等. 与insert不同. emplace允许你在容器中直接构造对象, 而不需要先创建对象再插入, 这样可以提高性能, 尤其是在对象构造开销较大的情况下.
        }
    }

    //返回顶点遍历序列
    return res;
}


