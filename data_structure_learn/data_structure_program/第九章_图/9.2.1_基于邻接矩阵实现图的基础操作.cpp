#include <bits/stdc++.h>

using namespace std;

// 基于邻接矩阵实现的无向图类  note: graph意为图, AdjMat全称 Adjacency Matrix 表示顶点之间相邻关系的矩阵
class GraphAdjMat
{
    // 声明类的成员变量, 作用域是该类的实例
    vector<int> vertices;       // vertex意为顶点(其复数形式为vertices), 这里的vertices为顶点列表, 元素代表"顶点值", 索引代表"顶点索引"
    vector<vector<int>> adjMat; // 邻接矩阵, 行列索引对应顶点索引, 用于表示顶点之间的连接关系, 其中vector<vector<int>>可以视为一个二维矩阵(或二维数组)

public: // 类内类外均能使用, private:则只能在类内使用
    // 成员函数部分
    // 构造方法, 其名称与类名相同, 用于初始化对象, 其使用实例见"Data_Structure"文档
    GraphAdjMat(const vector<int> &vertices, const vector<vector<int>> &edges) // 这里的&意为之间对导入的参数进行引用, 并以const修饰, 以确保函数只读取数据而不修改它.
    {
        // 添加顶点
        for (int val : vertices)
        {
            addVertex(val);
        }
        // 添加边
        // 这里的edges给出了顶点与顶点之间的连接关系, 每行包含两个元素(两个顶点), 故这里遍历edges每行, edge[0], edge[1]分别指两个顶点
        for (const vector<int> &edge : edges)
        {
            addEdge(edge[0], edge[1]);
        }
    }

    // 获取顶点数量, 这里const的作用是指示该成员函数不会修改类的任何成员变量
    int size() const
    {
        return vertices.size();
    }

    // 添加顶点
    void addVertex(int val)
    {
        int n = size();
        // 向顶点列表中添加新顶点的值
        vertices.push_back(val);
        // 在邻接矩阵中添加一行
        adjMat.emplace_back(vector<int>(n, 0)); // 在"DataStruture"中已整理很详尽的解释, 这里是在邻接矩阵adjMat最后一行添加n个为0的元素, 以实现添加一行的效果
        // 在邻接矩阵中添加一列
        for (vector<int> row : adjMat) // 这里声明row的类型为vector<int>, 用于表示adjMat的每一行
        {
            row.push_back(0); // 在每一行的末尾添加0, 相当于多了一列0
        }
    }

    // 删除顶点
    void removevertex(int index)
    {
        if (index < 0 || index >= size())
        {
            throw out_of_range("顶点不存在");
        }
        // 在顶点列表中移除索引index的顶点
        vertices.erase(vertices.begin() + index);
        // 在邻接矩阵中删除索引index的行
        adjMat.erase(adjMat.begin() + index);
        // 在邻接矩阵中删除索引index的列
        for (vector<int> row : adjMat)
        {
            row.erase(row.begin() + index);
        }
    }

    // 添加边
    // 参数i, j对应vertices元素索引
    void addEdge(int i, int j)
    {
        // 索引越界与相等处理
        if (i < 0 || j < 0 || i >= size() || j >= size() || i == j)
        {
            throw out_of_range("顶点不存在"); // 在C++中'throw'关键字用于抛出异常, 用于中断当前程序流程, 并将控制权转移到异常处理机制, 以便处理错误或异常情况. 这里的'out_of_range'异常是C++标准库中定义的一个异常类, 属于'std::out_of_range'用于表示访问超出有效范围的错误, 在这里'out_of_range("顶点不存在")'创建了一个'out_of_range'类型的异常对象, 并传递了一个描述性字符串'"顶点不存在"'说明异常的具体原因
        }
        // 在无向图中, 邻接矩阵关于主对角线对称, 即满足 (i, j) == (j, i)
        adjMat[i][j] = 1;
        adjMat[j][i] = 1;
    }

    // 删除边
    // 参数i, j对应vertices元素索引
    void removeEdge(int i, int j)
    {
        // 索引越界与相等处理
        if (i < 0 || j < 0 || i >= size() || j >= size() || i == j)
        {
            throw out_of_range("顶点不存在"); // 在C++中'throw'关键字用于抛出异常, 用于中断当前程序流程, 并将控制权转移到异常处理机制, 以便处理错误或异常情况. 这里的'out_of_range'异常是C++标准库中定义的一个异常类, 属于'std::out_of_range'用于表示访问超出有效范围的错误, 在这里'out_of_range("顶点不存在")'创建了一个'out_of_range'类型的异常对象, 并传递了一个描述性字符串'"顶点不存在"'说明异常的具体原因
        }
        adjMat[i][j] = 0;
        adjMat[j][i] = 0;
    }

    // 顶点列表打印
    void printVector(const vector<int> vec)
    {
        for (const int &val : vec)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    // 邻接矩阵打印
    void printVectorMatrix(const vector<vector<int>> &matrix)
    {
        for (const vector<int> &row : matrix)
        {
            for (const int &val : row)
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    // 打印邻接矩阵
    void print()
    {
        cout << "顶点列表 = " << endl;
        printVector(vertices);
        cout << "邻接矩阵 = " << endl;
        printVectorMatrix(adjMat);
    }
};
