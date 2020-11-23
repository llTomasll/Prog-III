#ifndef QUICKSORT_MAIN_H
#define QUICKSORT_MAIN_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h&amp;gt;
#include "quicksort.cpp"

using namespace std;

int main()
{
    int const MAX = 100;
    int arraySize;

    clock_t start_time;
    clock_t final_time;
    double total_time;
    start_time = clock();

    cout &amp;lt;&amp;lt; "Ingresa tamanyo: " &amp;lt;&amp;lt; endl;
    cin &amp;gt;&amp;gt; arraySize;

    int a[arraySize];

    // Para que el rand no genere siempre los mismos números, utilizando la hora del sistema
    srand(time(0));

    // Para generar enteros aleatorios usamos rand()
    for (int i = 0; i &amp;lt; arraySize; i++) {
        a[i] = rand() % MAX;
    }

    cout &amp;lt;&amp;lt; "Array antes de ordenarse: " &amp;lt;&amp;lt; endl;
    for (int i = 0; i &amp;lt; arraySize; i++) {
        cout &amp;lt;&amp;lt; a[i] &amp;lt;&amp;lt; " ";
    }

    cout &amp;lt;&amp;lt; endl &amp;lt;&amp;lt; endl;

    quicksort(a, 0, arraySize - 1);

    final_time = clock();
    total_time = ((double)(final_time - start_time)) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecución : %lf segundos \n", total_time);

    cout &amp;lt;&amp;lt; "Array ordenado " &amp;lt;&amp;lt; endl;
    for (int i = 0; i &amp;lt; arraySize; i++ ){
        cout &amp;lt;&amp;lt; a[i] &amp;lt;&amp;lt; "-";
    }

    cout &amp;lt;&amp;lt; endl &amp;lt;&amp;lt; endl;

    return 0;
}
#endif //QUICKSORT_MAIN_H
