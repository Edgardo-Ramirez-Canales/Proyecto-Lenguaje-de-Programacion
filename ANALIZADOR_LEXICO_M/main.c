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

//FUNCION BUSCAS LAS PALABRAS RESERVADAS
void Reservadas(){
	for(int i=0;i<IndicadorTam;i++){
		//strcmp COMPARA CARAACTER A CARACTER
		//reservadas[i] son las palabras reservadas que declaramos como variable global al inicio del programa
		
  if(strcmp(reservadas[i],palabraIngresada)==0){
			
			if(strcmp(reservadas[0],palabraIngresada)==0)
				contadorEncender++;
			
   if(strcmp(reservadas[1],palabraIngresada)==0)
				contadorApagado++;
			
			
			if(strcmp(reservadas[4],palabraIngresada)==0)
				contadorCiclos++;
				
			
			if(strcmp(reservadas[6],palabraIngresada)==0)
				contadorCiclos++;
			
			
			if(strcmp(reservadas[7],palabraIngresada)==0)
				contadorCondicional++;
			
			contadorPalabrasReservadas++;
			palabraIngresada[0]='\0';
			break;
		}
		if(i==(IndicadorTam)-1){
			exit(-1);
		}
	}		
}

/* Esta funcion se encarga se encarga de contar cuantas veces encontramos las palabras reservadas y
para eso buscamos en el arreglo  [numero] ese es el que indica el numero de palabra que utlizamos en esa parte me falta ordenar 
ese orden en las palabras
*/




//Funcion que analiza caracter a carater y decide a que tipo de elemento pertenec
void Estados(){

    switch(Estado){
        case 1:contadorVariables++; 	// Suma variables A ... Z							//Estado vuelve ser 0
            break;
        case 2:contadorVariables++; 	//  A ... Z	 a ... z  0 ... 9
            break;
        case 3: Reservadas();		// Palabras reservadas
            break;
        case 4:contadorNumeros++; 		//Numeros 0 ... 9
            break;
        case 5:contadorNumeros++; 		// 0 ... 9
            break;
        case 6:contadorNumeros++; 		// 0 ... 9
            break;
        case 7:contadorSignos++;			// -
            break;
        case 8:contadorSignos++; 			// +
            break;
        case 9:contadorSimbolos++; 			// =
            break;
        default:
            break;
    }

    Estado = q0;
}
/*Esta funcion falta y no la e probado ya que tendriamos que hacer mas casos ya que tenemos que agregar algun otro contador ya que tengo que tener mas casos al tener mas simbolos diferentes asi como 
les decia en la reunion */




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
 * LOS CAMBIOS DE ESTADOS  , TAMBIEN TENDREMOS QUE
 * QUE COMPARAR LOS CARACTERES AQUI PIENSO QUE PODRIAMOS USAR FUNCIONES QUE ESTAN EN LA BIBLIOTECA O SEPRAR LA CADENAS CADA
 * PUNTO Y COMO QUE ENCONTREMOS*/

//HASTA EL MOMENTO COMPILA :)
