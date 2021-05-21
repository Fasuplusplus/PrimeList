//encontrar todos los primos desde el 1 hasta n
#include <iostream>
#include <cstdio>
#include <cmath>
unsigned long const n = 100;             //n itself
unsigned long int primes[n / 2 + 1]{2, 3}; //primos ya encontrados, para usar en divisiones e imprimir al final
unsigned long int primeCount = 1;          //cantidad de primos ya encontrados, para no leer basura de la memoria (starting in 0)
void checkPrime()                          //chequear si los números son primos
{
    for (unsigned long int i = 5; i <= n; i = i + 2)
    {
        unsigned long int j = i / 2; //máximo número que puede ser divisor
        unsigned long int k = 1;     //posición actual dentro del array de primos, el primo que estamos testeando como divisor (empieza en 3 porque no contamos pares para el 2)
        while (k <= primeCount)      //¿Tiene este número algún divisor distinto de 1 y sí mismo?
        {
            if (primes[k] <= j)           //¿Ya nos pasamos del máximo divisor posible? *1
            {                             //*1 si no nos pasamos:
                if ((i % primes[k]) == 0) //¿Es i divisible por el primo actual?
                {
                    break; //Si sí, salimos del while, i NO es primo
                }
                else //Si no, sumamos 1 a k, probamos el próximo primo de la lista. También, primero dividimos i por este primo, para reducir los números revisados
                {
                    j = (i / primes[k]);
                    k++;
                }
            }
            else //*1 si ya nos pasamos del límite, ya probamos todos los primos que hacen falta. Este número ES primo
            {
                primes[(primeCount + 1)] = i; //por lo tanto, registramos el nuevo primo y salimos del while, para probar el próximo candidato
                primeCount++;
                break;
            }
        }
    }
}
void printCount()
{
    printf("Cantidad de primos entre 1 y ");
    printf("%u", n);
    printf(":");
    printf("%u\n", (primeCount + 1));
}
int main()
{
    checkPrime();
    printCount();
    printf("%s\n", "Lista:");
   /* for (unsigned long int i = 0; i <= primeCount; i++)
    {
        printf("%u\n", primes[i]);
    }*/
    return 0;
}