#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

double oblicz(double a, double b, int trapezy)
 {
    double suma = 0;
	   
    double h = (b - a)/trapezy;
    
    suma += (f(a) + f(b)) / 2;
    
    for(int i = 1; i < trapezy; i++)
        suma += f(a+i*h);

    return suma * h;
}

double f(double x)
{
    return 4*x - 6*x + 5;
}

int main()
 {
    int n;

    printf("Podaj liczbe procesow: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        if (fork()==0) 
		{
            srand(time(NULL) ^ (getpid()<<16));

            double a = rand()%20;
            double b = rand()%20;

            while (b <= a)
                b = rand()%20;

            int trapezy = (rand()%(20-1+1))+1;

            printf("a = %f, b = %f, liczba przedzialow (trapezow): %d \n", a, b, trapezy);
            printf("Wynik: %f \n\n", oblicz(a, b, trapezy));
            exit(0);
        }
    }
    
    return 0;
}
