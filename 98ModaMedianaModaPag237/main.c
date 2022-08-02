/* Figura 6.16: fig06_16.c
 Este programa introduce el tema del an�lisis de datos.
Calcula la media, la mediana y la moda de los datos */
 #include <stdio.h>
 #define TAMANIO 99

 /* prototipos de las funciones */
 void media( const int resp[] );
 void mediana( int resp[] );
 void moda( int frec[], const int resp[] ) ;
 void ordenamBurbuja( int a[] );
 void imprimeArreglo( const int a[] );

 /* la funci�n main comienza la ejecuci�n del programa */
 int main()
 {
 int frecuencia[ 10 ] = { 0 }; /* inicializa el arreglo frecuencia */

//Figura 6.16 Programa para el an�lisis de los datos de una encuesta. (Parte 1 de 4.)
 //Arreglos en C Cap�tulo 6
 /* inicializa el arreglo respuestas */
 int respuesta[ TAMANIO ] =
 { 6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
   7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
   6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
   7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
   6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
   7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
   5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
   7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
   7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
   4, 5, 6, 1, 6, 5, 7, 8, 7 };

 /* procesa las respuestas */
 media( respuesta );
 mediana( respuesta );
 moda( frecuencia, respuesta );

 return 0; /* indica terminaci�n exitosa */

} /* fin de main */

 /* calcula el promedio de todos los valores de las respuestas */
 void media( const int resp[] )
 {
 int j; /* contador del total de elementos del arreglo */
 int total = 0; /* variable para mantener la suma de los elementos del
arreglo */

 printf( "%s\n%s\n%s\n", "********", " Media", "********" );

 /* total de los valores de las respuestas */
 for ( j = 0; j < TAMANIO; j++ ) {
 total += resp[ j ];
 } /* fin de for */

 printf( "La media es el valor promedio de los datos.\n"
         "La media es igual al total de\n"
         "todos los elementos de datos divididos por\n"
         "el numero de elementos de datos ( %d ). La media\n"
         "en esta ejecucion es: %d / %d = %.4f\n\n",
   TAMANIO, total, TAMANIO, ( double ) total / TAMANIO );
 } /* fin de la funci�n media */

 /* ordena el arreglo y determina el valor de la mediana */
 void mediana( int resp[] )
 {
 printf( "\n%s\n%s\n%s\n%s",
 "********", " Mediana ", "********",
 "El arreglo de respuestas desordenado es" );

 imprimeArreglo( resp ); /* muestra el arreglo desordenado */

 ordenamBurbuja( resp ); /* ordena el arreglo */

//Figura 6.16 Programa para el an�lisis de los datos de una encuesta. (Parte 2 de 4.)
//Cap�tulo 6 Arreglos en C 201
 printf( "\n\nEl arreglo ordenado es " );
 imprimeArreglo( resp ); /* muestra el arreglo ordenado */

 /* muestra la mediana */
 printf( "\n\nLa mediana es el elemento %d del\n"
 "arreglo ordenado de elementos %d.\n"
 "Para esta ejecucion la mediana es %d\n\n",
 TAMANIO / 2, TAMANIO, resp[ TAMANIO / 2 ] );
 } /* fin de la funci�n mediana */

 /* determina las respuestas m�s frecuentes */
 void moda( int frec[], const int resp[] )
 {
 int rango; /* contador para acceder a los elementos de 1 a 9 del arreglo
frec */
 int j; /* contador para sumar los elementos de 0 a 98 des arreglo
respuesta */
 int h; /* contador para desplegar histogramas de los elementos en el
arreglo frec */
 int masGrande = 0; /* representa la frecuencia m�s grande */
 int valorModa = 0; /* representa la respuesta m�s frecuente */

 printf( "\n%s\n%s\n%s\n",
 "********", " Moda", "********" );

 /* inicializa las frecuencias a 0 */
 for ( rango = 1; rango <= 9; rango++ ) {
 frec[ rango ] = 0;
 } /* fin de for */

 /* suma las frecuencias */
 for ( j = 0; j < TAMANIO; j++ ) {
 ++frec[ resp[ j ] ];
 } /* fin de for */

 /* muestra los encabezados de las columnas */
 printf( "%s%11s%19s\n\n%54s\n%54s\n\n",
 "Respuesta", "Frecuencia", "Histograma",
 "1 1 2 2", "5 0 5 0 5" );

 /* muestra los resultados */
 for ( rango = 1; rango <= 9; rango++ ) {
 printf( "%8d%11d ", rango, frec[ rango ] );

 /* sigue la pista del valor de la moda y del valor de la frecuencia
m�s grande */
 if ( frec[ rango ] > masGrande ) {
 masGrande = frec[ rango ];
 valorModa = rango;
 } /* fin de if */

 /* muestra los histogramas de barras que representan el valor de la
frecuencia */
 for ( h = 1; h <= frec[ rango ]; h++ ) {
 printf( "*" );
//Figura 6.16 Programa para el an�lisis de los datos de una encuesta. (Parte 3 de 4.)
 //Arreglos en C Cap�tulo 6
 } /* fin del for interno */

 printf( "\n" ); /* nueva l�nea de salida */
 } /* fin del for externo */

 /* despliega el valor de la moda */
 printf( "La moda es el valor mas frecuente.\n"
 "Para esta ejecucion la moda es %d el cual ocurrio"
 " %d veces.\n", valorModa, masGrande );
 } /* fin de la funci�n moda */

 /* funci�n que ordena un arreglo mediante el algoritmo del m�todo de la
burbuja algorithm */
 void ordenamBurbuja( int a[] )
 {
 int pasada; /* contador de pasadas */
 int j; /* contador de comparaciones */
 int almacena; /* ubicaci�n temporal utilizada para intercambiar los
elementos */

 /* ciclo para controlar el n�mero de pasadas */
 for ( pasada = 1; pasada < TAMANIO; pasada++ ) {

 /* ciclo para controlar el n�mero de comparaciones por pasada */
 for ( j = 0; j < TAMANIO - 1; j++ ) {

 /* intercambia los elementos si no se encuentran en orden */
 if ( a[ j ] > a[ j + 1 ] ) {
 almacena = a[ j ];
 a[ j ] = a[ j + 1 ];
 a[ j + 1 ] = almacena;
 } /* fin de if */

 } /* fin del for interno */

 } /* fin del for externo */

 } /* fin de ordenamBurbuja */

 /* muestra el contenido del arreglo (20 valores por l�nea) */
 void imprimeArreglo( const int a[] )
 {
 int j; /* contador */
 /* muestra el contenido del arreglo */
 for ( j = 0; j < TAMANIO; j++ ) {

 if ( j % 20 == 0 ) { /* comienza una nueva l�nea cada 20 valores */
 printf( "\n" );
 } /* fin de if */

 printf( "%2d", a[ j ] );
 } /* fin de for */

 }
