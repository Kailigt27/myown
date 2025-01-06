using System;
class Program
{
    static void Main()
    {
        int number;
        number = int.Parse(Console.ReadLine());
        int n = Fbnq(number);
        Console.WriteLine(n);
    }
    static int Fbnq(int s)
    {
        if (s==0)
        {
            return 0;
        }
        if (s==1)
        {
            return 1;
        }
        return Fbnq(s - 1) + Fbnq(s- 2);
    }
}