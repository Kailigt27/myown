using System;
class Program
{
    class PSO
    {
        public class Point
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
        public PSO(int N,int maxiter,double w;double c1;double c2;double xMin,double xMax)
        {
            this.N=N;
            this.maxiter=iter;
            this.w=w;
            this.c1=c1;
            this.c2=c2;
            this.xMin=xMin;
            this.xMax=xMax;
        }
        public double function(double x)
        {
            return x*x+1;
        }
        public void optimize()
        {
            Point[] points=new Point[N];
            double gbestvalue=double.MaxValue;
            double gbestx=double.Ma
        }
    }
}