#include<iostream>
#include<vector>
using namespace std;
class Point
{
public:
    int x, y, z;
    string m_name;
    Point(string name, int a, int b, int c)
    {
        m_name = name;
        x = a;
        y = b;
        z = c;
    }
    void print()
    {
        cout << x << " " << y << " " << z << " ";
    }
};
class Pointlist
{
public:
    vector<Point>m_point;
    void Addpoint(string nm, int a, int b, int c)
    {
        Point ptr(nm, a, b, c);
        m_point.push_back(ptr);
    }
    void Deletepoint(int a, int b, int c)
    {
        int index = 0;
        for (int i = 0; i < m_point.size(); i++)
        {
            if (m_point[i].x == a && m_point[i].y == b && m_point[i].z == c)
            {
                index = i;
            }
        }
        m_point.erase(m_point.begin() + index);
    }
    void Deletepoint(string mname)
    {
        int index = 0;
        for (int j = 0; j < m_point.size();j++)
        {
            if (m_point[j].m_name == mname)
            {
                index = j;
                break;
            }
        }
        m_point.erase(m_point.begin() + index);
    }
    void Updatepoint(string sy, int x1, int y1, int z1)
    {
        int index = 0;
        for (int u = 0; u < m_point.size(); u++)
        {
            if (sy == m_point[u].m_name)
            {
                index = u;
                break;
            }
        }
        m_point[index].x = x1;
        m_point[index].y = y1;
        m_point[index].z = z1;
    }
    void Findpoint(string mname)
    {
        int index = 0;
        for (int z = 0; z < m_point.size(); z++)
        {
            if (m_point[z].m_name == mname)
            {
                index = z;
                break;
            }
        }
        m_point[index].print();
    }
    void Findpoint(int x1, int x2, int x3)
    {
        int index = 0;
        for (int b = 0; b < m_point.size(); b++)
        {
            index = b;
            break;
        }
        cout << m_point[index].m_name;
    }
};
int main()
{
    Pointlist a;
    a.Addpoint("lfq", 16, 502, 2);
    a.Findpoint("lfq");
}