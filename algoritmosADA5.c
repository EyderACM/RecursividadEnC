#include <stdio.h>
#include <math.h>

// Factorial
void invocarFactorial();
int factorial(int);

// Multiplicacion Entera
void invocarMultiplicacionEntera();
int mult(int, int);

// Exponenciacion Entera
void invocarExponenciacionEntera();
int expR(int, int);

// Maximo Comun Divisor
void invocarMaximoComunDivisor();
int mcd(int, int);

// Suma de elementos de vector
void invocarSumaElementos();
int suma_vec(int size, int[size]);

// Busqueda Binaria
void invocarBusquedaBinaria();
int busBinR(int, int fin, int vector[fin], int);

// Solucion de relacion de recurrencia
void solucionDeRecurrencia();

int main() {

    int accion = 0;
    printf("Ingrese el numero del algoritmo que desea probar\n\n");
    printf("1 Factorial\n");
    printf("2 Multiplicacion Entera\n");
    printf("3 Exponenciacion Entera\n");
    printf("4 Maximo Comun Divisor\n");
    printf("5 Suma de elementos de vector\n");
    printf("6 Busqueda binaria\n");
    printf("7 Solucion de relacion de recurrencia\n");
    scanf("%d", &accion);

    switch (accion) {
    case 1:   
        invocarFactorial();         
        break;
    case 2: 
        invocarMultiplicacionEntera();
        break;
    case 3:
        invocarExponenciacionEntera();
        break;
    case 4:
        invocarMaximoComunDivisor();
        break;
    case 5:
        invocarSumaElementos();
        break;
    case 6:
        invocarBusquedaBinaria();
        break;
    case 7:
        solucionDeRecurrencia();
        break;
    }    
}

/*
 * Factorial
 * Entradas: numero n del que calcular su factorial, cumple con la
 * condicion (n > 0)
 * 
 * Salidas: el factorial de numero
 */

void invocarFactorial(){
    int numero = 1, valorFactorial = 0;
    printf("\nIngresa el numero del que deseas encontrar el factorial\n");
    scanf("%d", &numero);
    valorFactorial = factorial(numero);
    printf("El factorial de %d es de: %d \n", numero, valorFactorial);
}

int factorial(int numero){
    if (!numero){
        return 1;
    }else {
        return numero*factorial(numero-1);
    }
}

/*
 * Multiplicacion Entera
 * Entradas: Los numeros a multiplicar: a y b. Como precondicion se 
 * considera que los numeros deben ser no negativos, a, b >0
 * 
 * Salidas: El valor del producto de los dos factores pasados, 
 * es decir, mult(a, b) = a * b
 */

void invocarMultiplicacionEntera(){
    int numero1 = 0, numero2 = 0, multiplicacion = 0;
    printf("Ingresa el numero 1\n");
    scanf("%d", &numero1);
    printf("Ingresa el numero 2\n");
    scanf("%d", &numero2);
    multiplicacion = mult(numero1, numero2);
    printf("El resultado de la multiplicacion es de %d \n", multiplicacion);
}

int mult(int a, int b) {
    if(b <= 0){
        return 0;
    }else {
        return a + mult(a, b-1);
    }
}

/*
 * Exponenciacion Entera
 * Entradas: La base y el exponente, a y b, respectivamente. Como precondicion
 * se considera que a y b son no negativos, y que no pueden ser 0
 * simultaneamente
 * 
 * Salidas: El resultado de elevar a a b, es decir expR(a, b) = a^b
 */

void invocarExponenciacionEntera() {
    int base, exponente, resultado;
    printf("Ingresa la base\n");
    scanf("%d", &base);
    printf("Ingresa el exponente\n");
    scanf("%d", &exponente);
    resultado = expR(base, exponente);
    printf("El resultado es de %d \n", resultado);
}

int expR(int base, int exponente) {
    if(exponente == 0) {
        return 1;
    } else if ((exponente % 2) == 0){
        int temp = expR(base, exponente/2);
        return temp*temp;
    }else {
        return base*expR(base, exponente-1);
    }
}

/*
 * Maximo Comun Divisor
 * Entradas: Los dos numeros de los que calcular su MCD, a y b
 * Como precondicion se considera que a y b son no negativos y no pueden
 * ser 0 simultaneamente
 * 
 * Salidas: El maximo comun divisor de los dos numeros
 */

void invocarMaximoComunDivisor(){
    int numero1, numero2, resultado;
    printf("Ingresa el numero 1\n");
    scanf("%d", &numero1);
    printf("Ingresa el numero 2\n");
    scanf("%d", &numero2);
    resultado = mcd(numero1, numero2);
    printf("El resultado es de %d \n", resultado);
}

int mcd(int a, int b) {
    if(b == 0){
        return a;
    }else if(a == 0) {
        return b;
    }else if(a >= b) {
        return mcd(a-b, b);
    }else {
        return mcd(a, b-a);
    }
}

/*
 * Suma de Elementos de un Vector
 * Entradas: Un vector de numeros (enteros), representado  por la pareja
 * de datos <v, n>. Como precondicion se considera que el vector ya tiene
 * cargados un conjunto de valores valido  que n es un valor comprendido
 * entre 0 y NMAX (la dimension maxima del arreglo) 
 * 
 * Salidas: La suma de los elementos del vector
 */

void invocarSumaElementos() {
    int sizeVector = 0, resultado;
    printf("Ingresa el largo del vector \n");
    scanf("%d", &sizeVector);
    int vector[sizeVector];

    for(int i = 0; i < sizeVector; i++){
        printf("Ingresa el elemento %d del vector ", (i+1));
        scanf("%d", &vector[i]);
    }
    resultado = suma_vec(sizeVector-1, vector);
    printf("El resultado del vector es de %d\n", resultado);
}

int suma_vec(int size, int vector[size]) {
    if(size == -1) {
        return 0;
    }else {
        return suma_vec(size-1, vector) + vector[size];
    }
}

/*
 * Busqueda Binaria
 * Entradas: Un subvector de numeros (enteros), representado por la tripleta
 * de datos <v, ini, fin>. Como precondicion se considera que el vector
 * ya tiene cargados un conjunto  de valores valido, que estos valores estan
 * ordenados, y que el numero de elementos del subvector es cero si fin <  ini
 * y el valor de la expresion fin - ini + 1, en caso contrario, se tiene que x es el elemento a buscar 
 * 
 * Salidas: La posicion i en la que deberia encontrarse el elemento x dentro del
 * subvector, de forma que se cumple que v[i] <= x < v[i+1]
 */

void invocarBusquedaBinaria() {
    int sizeVector = 100, buscado, resultado;
    int vector[sizeVector];
    printf("Ingresa el numero que deseas encontrar en un rango de 0 a 100\n");
    scanf("%d", &buscado);    

    for(int i = 0; i < sizeVector; i++){        
        vector[i] = (i+1);
    }
    resultado = busBinR(0, sizeVector-1, vector, buscado);
    printf("\nEncontrado en el index: %d\n", (resultado-1));
}

int busBinR(int inicio, int fin, int vector[fin], int buscado) {
    if(fin < inicio) {
        return inicio;
    }else {        
        int cen = (inicio+fin) / 2;        
        if(buscado < vector[cen]){
            return busBinR(inicio, cen-1, vector, buscado);
        }else {
            return busBinR(cen+1, fin, vector, buscado);
        }
    }
}

/*
 * Solucion de recurrencia
 * Entradas: Casos base de una relación de recurrencia
 * 
 * Salidas: Los primeros 20 valores de la recurrencia
 */

void solucionDeRecurrencia(){
    int base1, base2, alfa1, alfa2; 
    double resultado;
    printf("Relacion de la forma 5an-1 - 6an-2\n");
    printf("Ingresa el caso base a0 ");
    scanf("%d", &base1);
    printf("Ingresa el caso base a1 ");
    scanf("%d", &base2);
    alfa1 = (base2 - base1*2);
    alfa2 = (base1 - alfa1);
    for(int i = 0; i <= 20; i++){
        resultado = alfa1*(expR(3, i)) + alfa2*(expR(2, i));
        printf("\nEl resultado %d es de %lf \n", i, resultado);
    }
}




