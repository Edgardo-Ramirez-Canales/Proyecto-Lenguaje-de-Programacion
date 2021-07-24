#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<conio.h>

/* GRUPO 5
* Sistema show de luces y agua
* El usuario ingresara un archivo txt de entrada con instrucciones y la consola regresara una
 * de salida con la lectrura de la sintaxis introduciada */

//FUNCIONES-------------------------------------------------------------------------------------------------
void imprimir();
void extra();
void AnalizadorDeCaracter(char letra);//  Leer caracter a caracter las palabras para asignarle un estado
void Estados();//Manda los estados de los caracteres leidos
void Reservadas();// Buscar las palabras reservadas
//-----------------------------------------------------------------------------------------------------------

//PALABRAS RESERVADAS---------------------------------------
const char *reservadas[] = {"encender","apagar","inicio","definir","repetir","fin","mientras","si","sino","string", "int", "boolean", "decimal","true","false","agua","led","intensidad","posicion","para"}; //arreglo de palabras reservadas
//----------------------------------------------------------

//----------------------------------------------------------
int IndicadorTam=sizeof(reservadas)/sizeof(char *);
int i;
char palabraIngresada[50];
char temp[2];
enum TEstados{e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20};
//iniciando el estado en e0
enum TEstados Estado=e0;
//----------------------------------------------------------

//---------------------------------------------------------------------
//Estos son los contadores de los elementos de la tabla
int contadorVariables=0;
int contadorNumeros=0;
int contadorPalabrasReservadas=0;
int contadorSimbolos=0;
int contadorSignos=0;
int contadorEncender=0;
int contadorApagado=0;
int contadorCiclos=0;
int contadorCondicional=0;
//---------------------------------------------------------------------


//Funcion encargada de buscar en nuestro arreglo de palabras reservadas
void Reservadas(){
    for(int i=0;i<IndicadorTam;i++){
        //strcmp se encarga de comparar caracter por caracter dos Strings
        //reservadas[i] son las palabras reservadas que declaramos como variable global al inicio del programa
        //identificados es la palabra que el analizador lexico encontro
        if(strcmp(reservadas[i],palabraIngresada)==0){
            //Contar Encender
            if(strcmp(reservadas[0],palabraIngresada)==0)
                contadorEncender++;
            //Contar Apagar
            if(strcmp(reservadas[1],palabraIngresada)==0)
                contadorApagado++;

            //Contar Ciclo Repetir
            if(strcmp(reservadas[4],palabraIngresada)==0)
                contadorCiclos++;

            //Contar Ciclo Mientras
            if(strcmp(reservadas[6],palabraIngresada)==0)
                contadorCiclos++;

            //Contar Condicional
            if(strcmp(reservadas[7],palabraIngresada)==0)
                contadorCondicional++;

            //Cuenta las palabras reservadas que encuentre
            contadorPalabrasReservadas++;
            palabraIngresada[0]='\0';
            break;
        }
        if(i==(IndicadorTam)-1){
            exit(-1);
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------

//Compañeros estaria bien que nos reunieramos a las 8 para avanzar esra funcion de estados pero pienso que algo asi iria la logica, 
//y tambien falta probar la funcion que hicieron mas temprano con Fabiana para ver si cuenta todas las palabras reservadas y me escribe en
//el documento de salida.

void Estados(){
    
    switch(Estado){
        case 1:contadorVariables++; 	// Suma variables A ... Z		        //Estado vuelve ser 0
            break;
        case 2:contadorVariables++; 	//  A ... Z	 a ... z  0 ... 9
            break;
        case 3: Reservadas();		    // Palabras reservadas
            break;
        case 4:contadorNumeros++; 		//Numeros 0 ... 9
            break;
        case 5:contadorNumeros++; 		// 0 ... 9
            break;
        case 6:contadorNumeros++; 		// 0 ... 9
            break;
        case 7:contadorSignos++;		// -
            break;
        default:
            break;
    }
    Estado = e0;
}


int main() {
    printf("Hello, World!\n");
    FILE *archivoE;
    FILE *archivoS;
    printf("--------> ANALIZADOR LEXICO en C <------\n");
    printf("Preparando archivo.....\n");
    archivoE=fopen("C:\\Users\\Edgardo\\CLionProjects\\Proyecto_Analizador_Lexico_FINAL1\\entrada.txt", "r" );
    archivoS=fopen("C:\\Users\\Edgardo\\CLionProjects\\Proyecto_Analizador_Lexico_FINAL1\\salida.txt", "wt");

    char caracter;
    //Validamos si el archivo existe
    if ( archivoE == NULL ) {
        perror ( "ARCHIVO NO ENCONTRADO \n" ) ;
        return 1;
    }
    printf( "LEYENDO ARCHIVO....!!!\n" ) ;
    printf( "ARCHIVO ENCONTRADO CON EXITO\n" ) ;

    //---------------------------------------------------------------------
    while (1){
        //fgetch toma el texto del archivo y itera caracter a caracter
        caracter=fgetc(archivoE);
        if(caracter==EOF){
            break;
        }
        AnalizadorDeCaracter(caracter);
        if(caracter==';'){
            contadorSimbolos++;
        }
    }
    i++;
    //-----------------------------------------------------------------------------

    //--------------------------------------------------------------------------------------------------------------------------
   //  DOCUMENTO DE SALIDA
    fputs("\n\n--------------->ESCRIBE DOCUMENTO DE SALIDA<----------------\n\n", archivoS);
    fprintf(archivoS, "Palabras Reservadas: %d", contadorPalabrasReservadas);
    fprintf(archivoS, "\nVariables: %d", contadorVariables);
    fprintf(archivoS, "\nNumeros: %d", contadorNumeros);
    fprintf(archivoS, "\nAritmeticos: %d", contadorSignos);
    fprintf(archivoS, "\nSimbolos: %d", contadorSimbolos);          //OJO ESTA PARTE NO ESTA FUNCIONANDO TODAVIA NO TENENEMOS NADA QUE ESCRIBIR 
    fprintf(archivoS, "\nEncender: %d", contadorEncender);          // TODAVIA:(
    fprintf(archivoS, "\nApagado: %d", contadorApagado);
    fprintf(archivoS, "\nCiclos: %d", contadorCiclos/2);
    fprintf(archivoS, "\nCondicional: %d", contadorCondicional/2);
 // _______________________________________________________________________________________________________________________________

    int p;
    printf("DESEA ENCENDER:  0=NO  Y 1=SI  ");
    scanf ("%d", &p);
    printf("\n");

    if( p == 1){
//	scanf ("%dc", &cadena);
        int x,s,k,n;

        printf(" INTENSIDA Y FORMA:  ");
        scanf ("%d", &n);

        for(x=1; n-1>=x;x++){

            for(s=n;s>=x;s--){
                printf(" ");
            }
            for(k=1;2*x-1>=k;k++){
                printf("*!*");
            }
            printf("\n");
        }


        for(x=1;n>=x;x++){

            for(s=1;s<=x;s++){
                printf(" ");
            }

            for(k=2*n-1;2*x-1<=k;k--){
                printf("*!*");
            }
            printf("\n");
        }



        printf("\n");

        system("pause");

    }else{

        printf("no quiere prender");






    }








    return 0;
}

//______________________________________________________________________________________________________________________
void AnalizadorDeCaracter(char letra){

    if(letra==32||letra=='}'||letra=='{'
       ||letra=='('||letra==')'||letra==';'){
        Estados();
    }

    if( letra>='A' && letra<='Z' ){
        if(Estado==e0){
            Estado=e1;
        }else if(Estado==e1||Estado==e2){
            Estado=e2;
        }
        else if(Estado!=e0 && Estado!=e1 && Estado!=e2){
            exit(-1);
        }
    }

    if(letra>='a' && letra<='z'){
        if(Estado==e0){
            temp[0]=letra;
            strcat(palabraIngresada,temp);
            Estado=e3;
        }else if(Estado==e1||Estado==e2){
            Estado=e2;
        }
        else if(Estado==e3){
            temp[0]=letra;
            strcat(palabraIngresada,temp);
            Estado=e3;}
        else{
            exit(-1);
        }
    }
    if(letra<='9'&&letra>='0'){
        if(Estado==e0){
            Estado=e4;
        }else if(Estado==e4||Estado==e5){
            Estado=e5;
        }else if(Estado==e13||Estado==e6){
            Estado=e6;
        }else if(Estado==e1||Estado==e2){
            Estado=e2;
        }else if(Estado==e7){
            Estado=e4;
        }else{
            exit(-1);
        }
    }
    if(letra=='+'){
        if(Estado==e0){
            Estado=e8;
        }else if(Estado==e8){
            Estado=e17;
        }
    }

    if(letra=='.'){
        if((letra)<'1' || (letra)>='9'){
            Estado=e19;
        }else{
            if(Estado==e4||Estado==e5&&((letra)=='1'||(letra)=='2'
                                        ||(letra)=='3'||(letra)=='4'||(letra)=='5'||(letra)=='6'
                                        ||(letra)=='7'||(letra)=='8'||(letra)=='9')){
                Estado=e20;
            }
            else if(Estado!=e4 && Estado!=e5){
                exit(-1);
            }
        }
    }
    if(letra=='^'){
        if(Estado==e0){
            Estado=e18;
        }
        else{
            exit(-1);
        }
    }

    if(letra=='-'){
        if(Estado==e0){
            Estado=e7;
        }else if(Estado==e12){
            Estado=e10;}
    }	else if(Estado==e7){
        Estado=e17;
    }

    if(letra=='='){
        if(Estado==e0){
            Estado=e9;
        }else if(Estado==e18){
            Estado=e11;
        }
    }else if(Estado==e12){
        Estado=e16;
    }else if(Estado==e13){
        Estado=e15;
    }


    if(letra=='/'||letra=='*'){
        if(Estado==e0){
            Estado=e18;
        }else{
            exit(-1);
        }
    }

    if(letra=='<'){
        if(Estado==e0){
            Estado=e12;
        }else{
            exit(-1);
        }
    }
    if(letra=='>'){
        if(Estado==e0){
            Estado=e14;
        }else{
            exit(-1);
        }
    }


    if(letra=='!'){
        if(Estado==e0){
            Estado=e18;
        }else{
            exit(-1);
        }
    }

}  // FINAL
//______________________________________________________________________________________________________________________



//----------------------------------------------------------------------------------------------------------------------





//----------------------------------------------------------------------------------------------------------------------


}














/*Faltan funciones seguiremos en conferencia a las 3 pila*/
//HASTA EL MOMENTO COMPILA :)
