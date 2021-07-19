#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<conio.h>

/* GRUPO 5
 Description: Sistema show de luces y agua
* El usuario ingresara un archivo txt de entrada con instrucciones y la consola regresara una
 * de salida con la lectrura de la sintaxis introduciada */

//FUNCIONES
void imprimir();
void extra();
void AnalizadorDeCaracter(char letra);//  Leer caracter a caracter las palabras para asignarle un estado
void Estados();//Manda los estados de los caracteres leidos
void Reservadas();// Buscar las palabras reservadas
//PALABRAS RESERVADAS
const char *reservadas[] = {"encender","apagar","agua","led","intensidad","posicion","inicio","definir","repetir","fin","mientras","si","sino","string", "int", "boolean", "decimal","true","false"};

int IndicadorTam=sizeof(reservadas)/sizeof(char *);
int i;
char palabraIngresada[50];
char temp[2];
enum TEstados{e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10};
enum TEstados Estado=e0;

int main() {
    printf("Hello, World!\n");
    printf("--------> ANALIZADOR LEXICO en C <------\n");
    FILE *archivoE;
    FILE *archivoS;
    archivoE=fopen("C:\\Users\\Edgardo\\CLionProjects\\ANALIZADOR_LEXICO_M\\entrada.txt", "r" ); //ARCHIVO A LEER DIRECCION ABSOLUTA
    archivoS=fopen("C:\\Users\\Edgardo\\CLionProjects\\ANALIZADOR_LEXICO_M\\salida.txt", "wt"); //ARCHIVO DE SALIDA ANALIZADO

    char caracter;
    //Validamos si el archivo existe
    if ( archivoE == NULL ) {
        perror( "ARCHIVO NO ENCONTRADO \n" ) ;
        return 1;
    }
    printf( "LEYENDO CON EXITO....\n" ) ;





    return 0;
}
/* FALTA ESTRUCTURAR LAS FUNCIONES EN ESTAS FUNCIONES ESTARAN LA LECTURA DEL ARCHIVO DE ENTRADA Y AQUI TAMBIEN HAREMOS
 * LOS CAMBIOS DE ESTADOS ASI COMO TAMBIEN TENDREMOS QUE TENER CONTADORES PARA MOSTRAR AL FINAL , TAMBIEN TENDREMOS QUE
 * QUE COMPARAR LOS CARACTERES AQUI PIENSO QUE PODRIAMOS USAR FUNCIONES QUE ESTAN EN LA BIBLIOTECA O SEPRAR LA CADENAS CADA
 * PUNTO Y COMO QUE ENCONTREMOS*/

//HASTA EL MOMENTO COMPILA :)