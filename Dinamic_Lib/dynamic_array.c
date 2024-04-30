#include "dynamic_array.h"

int i;

// Dichiarazione di compareIntegers
int compareIntegers(const void *a, const void *b);

// Dichiarazione di filterEvenNumbers e filterOddNumbers
int filterEvenNumbers(int number);
int filterOddNumbers(int number);


// Funzione per creare un nuovo array dinamico con dimensione iniziale
DynamicArray *createDynamicArray(int initialSize) {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (array == NULL) {
        printf("Errore nell'allocazione di memoria.");
        exit(1);
    }
    
    array->array = (int *)malloc(initialSize * sizeof(int));
    if (array->array == NULL) {
        printf("Errore nell'allocazione di memoria.");
        free(array);
        exit(1);
    }
    
    array->size = initialSize;
    array->numElements = 0;
    
    return array;
}

// Funzione per aggiungere un elemento all'array dinamico
void addToDynamicArray(DynamicArray *array, int value) {
    if (array->numElements < array->size) {
        array->array[array->numElements] = value;
        array->numElements++;
    } else {
        printf("L'array è pieno. Ridimensiona l'array prima di aggiungere più elementi.\n");
    }
}

// Funzione per ridimensionare l'array dinamico
void resizeDynamicArray(DynamicArray *array, int increment) {
    array->size += increment;
    array->array = (int *)realloc(array->array, array->size * sizeof(int));
    if (array->array == NULL) {
        printf("Errore nella reallocazione di memoria.");
        exit(1);
    }
}

// Funzione per liberare la memoria allocata per l'array dinamico
void freeDynamicArray(DynamicArray *array) {
    free(array->array);
    free(array);
}

// Funzione per ottenere l'elemento dell'array dato l'indice
int getElement(DynamicArray *array, int index) {
    if (index < 0 || index >= array->numElements) {
        printf("Indice non valido.\n");
        exit(1);
    }
    return array->array[index];
}

// Funzione per rimuovere un elemento dall'array dato l'indice
void removeElement(DynamicArray *array, int index) {
    if (index < 0 || index >= array->numElements) {
        printf("Indice non valido.\n");
        return;
    }
    
    for (i = index; i < array->numElements - 1; i++) {
        array->array[i] = array->array[i + 1];
    }
    array->numElements--;
}

// Funzione per inserire un elemento in una posizione specifica dell'array
void insertElement(DynamicArray *array, int index, int value) {
    if (index < 0 || index > array->numElements) {
        printf("Indice non valido.\n");
        return;
    }
    
    // Ridimensiona l'array se necessario
    if (array->numElements == array->size) {
        resizeDynamicArray(array, 1);
    }
    
    for (i = array->numElements; i > index; i--) {
        array->array[i] = array->array[i - 1];
    }
    array->array[index] = value;
    array->numElements++;
}

// Funzione per stampare l'array dinamico
void printDynamicArray(DynamicArray *array) {
    printf("[ ");
    for (i = 0; i < array->numElements; i++) {
        printf("%d ", array->array[i]);
    }
    printf("]\n");
}

// Funzione per controllare se l'array è vuoto
int isEmpty(DynamicArray *array) {
    return array->numElements == 0;
}

// Funzione per iterare sugli elementi dell'array dinamico
void forEach(DynamicArray *array, void (*callback)(int)) {
    for (i = 0; i < array->numElements; i++) {
        callback(array->array[i]);
    }
}

// Funzione per stampare un singolo elemento
void printElement(int element) {
    printf("%d ", element);
}

// Funzione per cercare un elemento all'interno dell'array
int findElement(DynamicArray *array, int value) {
    for (i = 0; i < array->numElements; i++) {
        if (array->array[i] == value) {
            return i;
        }
    }
    return -1; // Elemento non trovato
}

// Funzione per ordinare l'array dinamico
void sortDynamicArray(DynamicArray *array) {
    qsort(array->array, array->numElements, sizeof(int), compareIntegers);
}

// Funzione per filtrare gli elementi dell'array
DynamicArray *filterDynamicArray(DynamicArray *array, int (*filter)(int)) {
    DynamicArray *filteredArray = createDynamicArray(array->size);
    for (i = 0; i < array->numElements; i++) {
        if (filter(array->array[i])) {
            addToDynamicArray(filteredArray, array->array[i]);
        }
    }
    return filteredArray;
}

// Funzione per copiare l'array dinamico
DynamicArray *copyDynamicArray(DynamicArray *array) {
    DynamicArray *copy = createDynamicArray(array->size);
    for (i = 0; i < array->numElements; i++) {
        addToDynamicArray(copy, array->array[i]);
    }
    return copy;
}

// Funzione per confrontare due array dinamici
int compareDynamicArrays(DynamicArray *array1, DynamicArray *array2) {
    if (array1->numElements != array2->numElements) {
        return 0; // Gli array hanno lunghezze diverse
    }
    for (i = 0; i < array1->numElements; i++) {
        if (array1->array[i] != array2->array[i]) {
            return 0; // Gli elementi degli array sono diversi
        }
    }
    return 1; // Gli array sono uguali
}

// Funzione per filtrare i numeri pari
int filterEvenNumbers(int number) {
    return number % 2 == 0;
}

// Funzione per filtrare i numeri dispari
int filterOddNumbers(int number) {
    return number % 2 != 0;
}

// Funzione di confronto per l'ordinamento
int compareIntegers(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Creazione di un array dinamico con dimensione iniziale di 5
    DynamicArray *array = createDynamicArray(5);

    // Aggiunta di alcuni elementi all'array
    addToDynamicArray(array, 10);
    addToDynamicArray(array, 20);
    addToDynamicArray(array, 30);

    // Stampa dell'array
    printf("Array dopo l'aggiunta di elementi: ");
    printDynamicArray(array);

    // Inserimento di un elemento in una posizione specifica
    insertElement(array, 1, 15);

    // Stampa dell'array dopo l'inserimento
    printf("Array dopo l'inserimento di un elemento: ");
    printDynamicArray(array);

    // Rimozione di un elemento dall'array
    removeElement(array, 2);

    // Stampa dell'array dopo la rimozione
    printf("Array dopo la rimozione di un elemento: ");
    printDynamicArray(array);

    // Esempio di accesso agli elementi dell'array
    printf("Elemento all'indice 0: %d\n", getElement(array, 0));
    printf("Elemento all'indice 1: %d\n", getElement(array, 1));

    // Esempio di iterazione sugli elementi dell'array
    printf("Iterazione sugli elementi dell'array: ");
    forEach(array, &printElement);
    printf("\n");

    // Esempio di ricerca di un elemento
    int index = findElement(array, 20);
    if (index != -1) {
        printf("Elemento 20 trovato all'indice %d\n", index);
    } else {
        printf("Elemento 20 non trovato nell'array\n");
    }

    // Ordinamento dell'array
    sortDynamicArray(array);
    printf("Array ordinato: ");
    printDynamicArray(array);

    // Filtraggio degli elementi dell'array
    DynamicArray *filteredArray = filterDynamicArray(array, &filterEvenNumbers);
    printf("Array filtrato (solo numeri pari): ");
    printDynamicArray(filteredArray);
    freeDynamicArray(filteredArray);

    // Copia dell'array
    DynamicArray *copyArray = copyDynamicArray(array);
    printf("Copia dell'array: ");
    printDynamicArray(copyArray);
    freeDynamicArray(copyArray);

    // Confronto tra array
    DynamicArray *array2 = createDynamicArray(5);
    addToDynamicArray(array2, 10);
    addToDynamicArray(array2, 15);
    addToDynamicArray(array2, 30);
    printf("Confronto tra array: %d\n", compareDynamicArrays(array, array2));
    freeDynamicArray(array2);

    // Liberazione della memoria allocata per l'array
    freeDynamicArray(array);

    return 0;
}
