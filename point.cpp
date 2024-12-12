#include<iostream>
#include<vector>
using namespace std;
class Point
{
public:
    double x, y, z;
    string m_name;
    Point(string name, double a, double b, double c)
    {
        m_name = name;
        x = a;
        y = b;
        z = c;
    }
    void print()
    {
        cout <<"Point"<<m_name<<x << " " << y << " " << z << " "<<endl;
    }
};
class Pointlist
{
public:
    vector<Point>m_point;
    void Addpoint(string nm, double a, double b, double c)
    {
        Point ptr(nm, a, b, c);
        m_point.push_back(ptr);
    }
    void Deletepoint(double a, double b, double c)
    {
        for (auto it=m_point.begin();it!=m_point.end();++it)
        {
           if (it->x==a&&it->y==b&&it->z==c)
           {
            m_point.erase(it);
            return;
           }
        }
        cout<<"point "<<a<<" "<<b<<" "<<c<<" "<<"not found"<<endl;
    }
    void Deletepoint(string mname)
    {
        for (auto it=m_point.begin();it!=m_point.end();++it)
        {
            if (it->m_name==mname)
            {
                m_point.erase(it);
                return;
            }
        }
       cout<<"point  "<<mname<<" not found";
    }
    void Updatepoint(string sy, double x1, double y1, double z1)
    {
        for(auto& point:m_point)
        {
            if (sy==point.m_name)
            {
                point.x=x1;
                point.y=y1;
                point.z=z1;
                return;
            }
        }
        cout<<"point sy not found"<<endl;
    }
    void Findpoint(string mname)
    {
        for (auto it=m_point.begin();it!=m_point.end();++it)
        {
           if(it->m_name==mname)
           {
            it->print();
            return;
           }
        }
        cout<<"not found";
    }
    void Findpoint(double x1, double x2, double x3)
    {
        for(auto it=m_point.begin();it!=m_point.end();++it)
        {
            if(it->x==x1&&it->y==x2&&it->z==x3)
            {
                cout<<it->m_name;
                return;
            }
        }
        cout<<"not found";
    }
};
int main()
{
    Pointlist a;
    a.Addpoint("lfq", 16, 502, 2);
    a.Findpoint("lfq");
}