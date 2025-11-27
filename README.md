# Pr-ctica-4-Almacenamiento-en-tiempo-de-ejecuci-n

1. ¿Qué diferencia observaron entre los valores iniciales con malloc y calloc?
  Malloc: reserva memoria pero no la inicializa.
  Calloc: reserva memoria e inicializa todo en cero, así que los valores iniciales del arreglo son 0.

2. ¿Qué sucede si en realloc piden un tamaño más grande que el original? ¿y más pequeño?
   Si es mas grande q el orginal se conserva el contenido previo, se necesitan nuevos datos para llenar lo q falta y si es mas pequeño los demas datos se pierden y solo se mantienen los del inicio.

3. ¿Qué pasa si olvidan llamar a free?
   Significa que no llbera la memoria por lo q queda llena y puede ocasionar lentitud en el programa.
