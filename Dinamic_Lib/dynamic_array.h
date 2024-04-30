#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

// Struttura per rappresentare un array dinamico
typedef struct {
    int *array;         // Puntatore all'array di interi
    int size;           // Dimensione attuale dell'array
    int numElements;    // Numero di elementi attualmente presenti nell'array
} DynamicArray;

// Funzione per creare un nuovo array dinamico con dimensione iniziale
DynamicArray *createDynamicArray(int initialSize);

// Funzione per aggiungere un elemento all'array dinamico
void addToDynamicArray(DynamicArray *array, int value);

// Funzione per ridimensionare l'array dinamico
void resizeDynamicArray(DynamicArray *array, int increment);

// Funzione per liberare la memoria allocata per l'array dinamico
void freeDynamicArray(DynamicArray *array);

// Funzione per ottenere l'elemento dell'array dato l'indice
int getElement(DynamicArray *array, int index);

// Funzione per rimuovere un elemento dall'array dato l'indice
void removeElement(DynamicArray *array, int index);

// Funzione per inserire un elemento in una posizione specifica dell'array
void insertElement(DynamicArray *array, int index, int value);

// Funzione per stampare l'array dinamico
void printDynamicArray(DynamicArray *array);

// Funzione per controllare se l'array è vuoto
int isEmpty(DynamicArray *array);

// Funzione per iterare sugli elementi dell'array dinamico
void forEach(DynamicArray *array, void (*callback)(int));

// Funzione per cercare un elemento all'interno dell'array
int findElement(DynamicArray *array, int value);

// Funzione per ordinare l'array dinamico
void sortDynamicArray(DynamicArray *array);

// Funzione per filtrare gli elementi dell'array
DynamicArray *filterDynamicArray(DynamicArray *array, int (*filter)(int));

// Funzione per copiare l'array dinamico
DynamicArray *copyDynamicArray(DynamicArray *array);

// Funzione per confrontare due array dinamici
int compareDynamicArrays(DynamicArray *array1, DynamicArray *array2);

// Funzione di confronto per l'ordinamento
int compareIntegers(const void *a, const void *b);


// Funzione per filtrare i numeri pari
int filterEvenNumbers(int number);

// Funzione per filtrare i numeri dispari
int filterOddNumbers(int number);

#endif /* DYNAMIC_ARRAY_H */
