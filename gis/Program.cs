using System;
class Program
{
    class PSO
    {
        class Point
        {
            public double x;
            public double v;
            public double pBest;
        }
        private int N;
        private int maxiters;
        private double w;
        private double c1;
        private double c2;
        private double xMin;
        private double xMax;
        public PSO(int  N, int maxiters, double w, double c1, double c2, double xMin, double xMax)
        {
            this.N=N;
            this.maxiters = maxiters;
            this.w = w;
            this.c1 = c1;
            this.c2 = c2;
            this.xMin = xMin;
            this.xMax = xMax;
        }
        private double Function(double x)
        {
            return x * x + 1;
        }
        public void optimize()
        {
            Point[] points= new Point[N];
            Random random = new Random();
            double gBest = Double.MaxValue;
            double gBestValue=Double.MaxValue;
            for (int i=0;i<N;i++)
            {
                points[i] = new Point();
                points[i].x = xMin + (xMax - xMin) * random.NextDouble();
                points[i].v=0.1*x

            }
        }
    }
}