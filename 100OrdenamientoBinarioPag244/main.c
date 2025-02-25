/* Figura 6.19: fig06_19.c
 B�squeda binaria dentro de un arreglo */
 #include <stdio.h>
 #define TAMANIO 15

 /* prototipos de las funciones */
 int busquedaBinaria( const int b[], int claveDeBusqueda, int bajo, int alto );
 void despliegaEncabezado( void );
 void despliegaLinea( const int b[], int bajo, int medio, int alto );

 /* la funci�n main comienza la ejecuci�n del programa */
 int main()
 {
 int a[ TAMANIO ]; /* crea el arreglo a */
 int i; /* contador para inicializar los elementos de 0 a 14 del arreglo a */
//Figura 6.19 B�squeda lineal en un arreglo ordenado. (Parte 1 de 4.)
//Cap�tulo 6 Arreglos en C 207
 int llave; /* valor a localizar en el arreglo a */
 int resultado; /* variable para almacenar la ubicaci�n de la llave o -1 */

 /* crea los datos */
 for ( i = 0; i < TAMANIO; i++ ) {
 a[ i ] = 2 * i;
 } /* fin de for */

 printf( "Introduzca un numero entre 0 y 28: " );
 scanf( "%d", &llave );

 despliegaEncabezado();

 /* busca la llave en el arreglo a */
 resultado = busquedaBinaria( a, llave, 0, TAMANIO - 1 );
 /* despliega los resultados */
 if ( resultado != -1 ) {
 printf( "\n%d se encuentra en el elemento %d del arreglo\n", llave,
resultado );
 } /* fin de if */
 else {
 printf( "\n%d no se encuentra\n", llave );
 } /* fin de else */
 return 0; /* indica terminaci�n exitosa */
 } /* fin de main */
 /* funci�n para realizar la b�squeda binaria en un arreglo */
 int busquedaBinaria( const int b[], int claveDeBusqueda, int bajo, int alto )
 {
 int central; /* variable para mantener el elemento central del arreglo */

 /* realiza el ciclo hasta que el sub�nice bajo es mayor que el sub�ndice
alto */
 while ( bajo <= alto ) {

 /* determina el elemento central del subarreglo en el que se busca */
 central = ( bajo + alto ) / 2;

 /* despliega el subarreglo utilizado en este ciclo */
 despliegaLinea( b, bajo, central, alto );

 /* si claveDeBusqueda coincide con el elemento central, devuelve
central */
 if ( claveDeBusqueda == b[ central ] ) {
 return central;
 } /* fin de if */

 /* si claveDeBusqueda es menor que el elemento central, establece el
nuevo valor de alto */
 else if ( claveDeBusqueda < b[ central ] ) {
 alto = central - 1; /* busca en la mitad inferior del arreglo */
 } /* fin de else if */
//Figura 6.19 B�squeda lineal en un arreglo ordenado. (Parte 2 de 4.)
// Arreglos en C Cap�tulo 6
 /* si claveDeBusqueda es mayor que el elemento central, establece el
nuevo valor para bajo */
 else {
 bajo = central + 1; /* busca en la mitad superior del arreglo */
 } /* fin de else */

 } /* fin de while */

 return -1; /* no se encontr� claveDeBusqueda */

 } /* fin de la funci�n busquedaBinaria */

 /* Imprime un encabezado para la salida */
 void despliegaEncabezado( void )
 {
 int i; /* contador */

 printf( "\nSubindices:\n" );

 /* muestra el encabezado de la columna */
 for ( i = 0; i < TAMANIO; i++ ) {
 printf( "%3d ", i );
 } /* fin de for */

 printf( "\n" ); /* comienza la nueva l�nea de salida */

 /* muestra una l�nea de caracteres - */
 for ( i = 1; i <= 4 * TAMANIO; i++ ) {
 printf( "-" );
 } /* fin de for */

 printf( "\n" ); /* inicia una nueva l�nea de salida */
 } /* fin de la funci�n despliegaEncabezado */

 /* Imprime una l�nea de salida que muestra la parte actual
 del arreglo que se est� procesando. */
 void despliegaLinea( const int b[], int baj, int cen, int alt )
 {
 int i; /* contador para la iteraci�n a trav�s del arreglo b */

 /* ciclo a trav�s del arreglo completo */
 for ( i = 0; i < TAMANIO; i++ ) {

 /* despliega espacios si se encuentra fuera del rango actual del
subarreglo */
 if ( i < baj || i > alt ) {
 printf( " " );
 } /* fin de if */
 else if ( i == cen ) { /* despliega el elemento central */
 printf( "%3d*", b[ i ] ); /* marca el valor central */
 } /* fin de else if */
 else { /* despliega otros elementos en el subarreglo */
 printf( "%3d ", b[ i ] );
 } /* fin de else */
//Figura 6.19 B�squeda lineal en un arreglo ordenado. (Parte 3 de 4.)
//Cap�tulo 6 Arreglos en C 209

 } /* fin de for */

 printf( "\n" ); /* inicia la nueva l�nea de salida */
 } /* fin de la funci�n despliegaLinea */
