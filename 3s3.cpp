#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<limits>
using namespace std;
double objective_function(double x)
{
	return x * x + 1;
}
class Point
{
public:
	double position;
	double velocity;
	double best_position;
	double best_value;
	Point(double lower_bound, double upper_bound)
	{
		position = lower_bound + (rand() / (RAND_MAX + 1.0)) * (upper_bound - lower_bound);
		velocity = (rand()/(RAND_MAX + 1.0)) * 2.0 - 1.0;
		best_position = position;
		best_value = objective_function(position);
	}
};
class Pgroup
{
public:
	int num;
	int max_iter;
	double w;
	double c1, c2;
	double lower_bound;
	double upper_bound;
	vector<Point>Points;
	double gbest_position;
	double gbest_value;
	Pgroup(int num, int max_iter, double w, double c1, double c2, double lower_bound, double upper_bound):num(num),max_iter(max_iter),w(w), c1(c1),c2(c2),lower_bound(lower_bound),upper_bound(upper_bound)
	{
		gbest_position = 0;
		gbest_value = numeric_limits<double>::max();
		for (int i = 0; i < num; i++)
		{
			Points.push_back(Point(lower_bound, upper_bound));
		}
	}
	void optimize()
	{
		for (int iter = 0; iter < max_iter; iter++)
		{
			for (auto& Point : Points)
			{
				double fitness = objective_function(Point.position);
				if (fitness < Point.best_value)
				{
					Point.best_position = Point.position;
					Point.best_value = fitness;
				}
				if (fitness < gbest_value)
				{
					gbest_position = Point.position;
					gbest_value = fitness;
				}
			}
			for (auto& Point : Points)
			{
				Point.velocity = w * Point.velocity + c1 * (rand() / (RAND_MAX +1.0)) * (Point.best_position - Point.position) + c2 * (rand() / (RAND_MAX +1.0)) * (gbest_position- Point.position);
				Point.position += Point.velocity;
				if (Point.position < lower_bound)
				{
					Point.position = lower_bound;
				}
				if (Point.position > upper_bound)
				{
					Point.position = upper_bound;
				}
			}
			w *= 0.9;
		}
	}
	double getposition() const
	{
		return gbest_position;
	}
	double getvalue() const
	{
		return gbest_value;
	}
};
int main()
{
	srand(time(0));
	int groupnum = 30;
	int max_iter = 100;
	double w = 0.5;
	double c1 = 1.5;
	double c2 = 1.5;
	double lower_bound = -10.0;
	double upper_bound = 10.0;
	Pgroup pgrp(groupnum, max_iter, w, c1, c2, lower_bound, upper_bound);
	pgrp.optimize();
	cout << "global best value:" << pgrp.getvalue()<< endl;
	return 0;
}
