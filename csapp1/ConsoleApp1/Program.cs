using System;
using System.Diagnostics.CodeAnalysis;
using System.Net.NetworkInformation;
class Program
{
    class PSO
    {
        private class Point
        {
            public double x;
            public double v;
            public double pBest;
        }
        private int N;
        private int maxiter;
        private double w;
        private double c1;
        private double c2;
        private double xMin;
        private double xMax;
        public PSO(int N, int maxiter, double w,double c1, double c2, double xMin,double xMax)
        {
            this.N=N;
            this.maxiter=maxiter;
            this.w=w;
            this.c1=c1;
            this.c2=c2;
            this.xMin=xMin;
            this.xMax=xMax;
        }
    public double function(double x)
    {
        return x * x + 1;
    }
    public void optimize()
    {
        Random random= new Random();
        Point[] points = new Point[N];
        double gbestvalue = double.MaxValue;
        double gbestx = double.MaxValue;
        for(int i=0;i<N;i++)
            {
                points[i] = new Point();
                points[i].x=xMin+(xMax-xMin)*random.NextDouble();
                points[i].v=0.1*(random.NextDouble() - 0.5)*(xMax-xMin);
                points[i].pBest=points[i].x;
            }
            for (int j = 0; j < maxiter; j++)
            {
                w = 0.9 - j * (0.5 / maxiter);
                foreach (var p in points)
                {
                    double r1 = random.NextDouble();
                    double r2 = random.NextDouble();
                    p.v=w*p.v+c1*r1*(p.pBest-p.x)+ c2*r2*(gbestx-p.x);
                    p.x += p.v;
                    if (p.x<xMin)
                    {
                        p.x = xMin;
                    }
                    if(p.x>xMax)
                    {
                        p.x = xMax;
                    }
                    double value = function(p.x);
                    if (value<function(p.pBest))
                    {
                        p.pBest = p.x;
                    }
                    if(value<gbestvalue)
                    {
                        gbestvalue = value;
                        gbestx = p.x;
                    }
                    Console.WriteLine($"iter:{j} gBestvalue:{gbestvalue:F6} gbestx{gbestx:F6}");
                }
            }
            Console.WriteLine();
            Console.WriteLine($"gbestvalue:{gbestvalue:F6} gbestx:{gbestx:f6}");
        }
    }
    static void Main(string[] args)
    {
        PSO pso = new PSO(30, 100, 1.2, 1.6, 1.8, -10, 10);
        pso.optimize();
    }
}