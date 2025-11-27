#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i;
    int *arr = NULL;
    int *arr2 = NULL;
    int *tmp = NULL;

    /* Paso 1. Reservar memoria con malloc */
    /* 1. Preguntar al usuario cuántos enteros quiere almacenar. */
    printf("Tamano del arreglo: ");
    scanf("%d", &n);

    /* 2. Reservar memoria con malloc. */
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error con malloc.\n");
        return 1;
    }

    /* 3. Mostrar los valores iniciales (serán basura). */
    printf("\nValores iniciales con malloc:\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    /* Paso 2. Reservar memoria con calloc */
    /* 1. Repetir la reserva, pero ahora con calloc. */
    arr2 = (int *)calloc(n, sizeof(int));
    if (arr2 == NULL) {
        printf("Error con calloc.\n");
        free(arr);
        return 1;
    }

    /* 2. Mostrar los valores iniciales (serán 0). */
    printf("\nValores iniciales con calloc:\n");
    for (i = 0; i < n; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    /* Paso 3. Llenar el arreglo */
    /* 1. Pedir al usuario que ingrese n valores. */
    /* 2. Guardarlos en el arreglo arr2. */
    printf("\nIngresa los %d valores para arr2:\n", n);
    for (i = 0; i < n; i++) {
        printf("arr2[%d] = ", i);
        scanf("%d", &arr2[i]);
    }

    /* Paso 4. Redimensionar con realloc */
    /* 1. Preguntar al usuario un nuevo tamaño m. */
    printf("\nNuevo tamano del arreglo arr2: ");
    scanf("%d", &m);

    /* 2. Usar realloc para cambiar el tamaño de arr2. */
    tmp = (int *)realloc(arr2, m * sizeof(int));
    if (tmp == NULL) {
        printf("Error con realloc.\n");
        free(arr);
        free(arr2);
        return 1;
    }
    arr2 = tmp;

    /* 3. En caso de que el arreglo sea de mayor tamaño, pedir los valores que faltan. */
    if (m > n) {
        printf("\nIngresa los valores adicionales:\n");
        for (i = n; i < m; i++) {
            printf("arr2[%d] = ", i);
            scanf("%d", &arr2[i]);
        }
    }

    /* 5. Imprimir todos los valores */
    printf("\nContenido final de arr2:\n");
    for (i = 0; i < m; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    /* Paso 5. Liberar memoria */
    /* 1. Usar free(arr) y free(arr2). */
    free(arr);
    free(arr2);

    /* 2. Imprimir un mensaje confirmando la liberación. */
    printf("\nMemoria liberada correctamente.\n");
    return 0;
}