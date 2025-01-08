import random
class PSO:
    class point:
      def __init__(self):
         self.x=0
         self.v=0
         self.pBest=0
    def __init__(self,N,maxiter,w,c1,c2,xmin,xmax):
        self.N=N
        self.maxiter=maxiter
        self.w=w
        self.c1=c1
        self.c2=c2
        self.xmin=xmin
        self.xmax=xmax
        self.points=[self.point() for i in range(N)]
        self.gBestX=float('inf')
        self.gBestValue=float('inf')
    def function(self,x):
        return x*x+1
    def init_points(self):
        for i in self.points:
            i.x=self.xmin+(self.xmax-self.xmin)*random.random()
            i.v=0.5*(self.xmax-self.xmin)*(random.random()-0.5)
            i.pBest=i.x
            value=self.function(i.x)
            if value<self.gBestValue:
                self.gBestValue=value
                self.gBestX=i.x
    def optimize(self):
        self.init_points()
        for iter in range(self.maxiter):
            self.w=0.9 -iter*(0.4/self.maxiter)
            for i in self.points:
                r1,r2=random.random(),random.random()
                i.v=self.w*i.v+r1*self.c1*(i.pBest-i.x)+r2*self.c2*r2*(self.gBestX-i.x)
                i.x+=i.v
                if i.x<self.xmin:
                    self.xmin=i.x
                if i.x>self.xmax:
                    self.xmax=i.x
                value=self.function(i.x)
                if value<self.function(i.pBest):
                    i.pBest=i.x
                if value<self.gBestValue:
                    self.gBestValue=value
                    self.gBestX=i.x
            print(f"iter:{iter} gbest value:{self.gBestValue} gbestx:{self.gBestX:.6f}")
        print()
        print(f"gbestvalue{self.gBestValue:.6f} gbestX{self.gBestX:.6f}")

pso=PSO(N=30,maxiter=10000,w=0.9,c1=2.0,c2=2.0,xmin=-10,xmax=10)
pso.optimize()