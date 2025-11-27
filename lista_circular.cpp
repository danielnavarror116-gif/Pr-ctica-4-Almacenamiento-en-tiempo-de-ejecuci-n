#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i;
    int *arr = NULL;
    int *arr2 = NULL;
    int *tmp = NULL;

    /* Paso 1. Reservar memoria con malloc */
    printf("Introduce la cantidad de enteros a almacenar: ");
    scanf("%d", &n);

    /* 2. Reservar memoria con malloc. */
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("No se pudo asignar memoria con malloc.\n");
        return 1;
    }

    /* 3. Mostrar los valores iniciales (serán basura). */
    printf("\nContenido inicial del arreglo arr (malloc):\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    /* Paso 2. Reservar memoria con calloc */
    arr2 = (int *)calloc(n, sizeof(int));  /* Repetir la reserva, pero ahora con calloc. */
    if (arr2 == NULL) {
        printf("No se pudo asignar memoria con calloc.\n");
        free(arr);
        return 1;
    }

    /* 2. Mostrar los valores iniciales (serán 0). */
    printf("\nContenido inicial del arreglo arr2 (calloc):\n");
    for (i = 0; i < n; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    /* Paso 3. Llenar el arreglo */
    printf("\nLlena el arreglo arr2 con %d valores:\n", n);
    for (i = 0; i < n; i++) {
        printf("arr2[%d] = ", i);
        scanf("%d", &arr2[i]);
    }

    /* Paso 4. Redimensionar con realloc */
    printf("\nNuevo tamano para arr2 (m): ");
    scanf("%d", &m);

    tmp = (int *)realloc(arr2, m * sizeof(int));  /* Usar realloc para cambiar el tamaño de arr2. */
    if (tmp == NULL) {
        printf("Error al usar realloc.\n");
        free(arr);
        free(arr2);
        return 1;
    }
    arr2 = tmp;

    /* 3. En caso de que el arreglo sea de mayor tamaño, pedir los valores que faltan. */
    if (m > n) {
        printf("\nIngresa los valores nuevos para las posiciones restantes:\n");
        for (i = n; i < m; i++) {
            printf("arr2[%d] = ", i);
            scanf("%d", &arr2[i]);
        }
    }

    /* 5. Imprimir todos los valores */
    printf("\nArreglo arr2 despues de redimensionar:\n");
    for (i = 0; i < m; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    /* Paso 5. Liberar memoria */
    free(arr);
    free(arr2);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}