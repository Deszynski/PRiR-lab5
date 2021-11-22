#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

double oblicz_pi(int x)
{
    double suma = 0;
    double temp;
    
    for(int i = 1; i <= x; i++)
    {
        temp = pow(-1, i-1)/(2 * i-1);
        suma += temp;
    }

    return 4*suma;
}

int main()
{
    int n;
    
    printf("Podaj liczbe procesow \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        if (fork() == 0)
        {
            srand(time(NULL)^(getpid()<<16));
            
            int x = (rand()%(5000-100+1))+100;

            printf("n = %d pi: %f \n", x, oblicz_pi(x));
            exit(0);
        }
    }
    
    return 0;
}
