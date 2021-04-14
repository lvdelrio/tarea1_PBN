#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//is like globals variable
#define max_rows 10
#define max_col 10
#define MAXCHAR 1000

//functions
void printMap(char map[][max_col]);
int executeShot(int g,int A[][10]);
int incomingShot(char map[][max_col]);
void welcomeScreen();


char** imprimir_tablero(char** matriz){

    printf("  A  B  C  D  E  F  G  H  I  J\n");
     for (int i=0;i<10;i++){
         
         printf("%d",i);
        for (int j=0 ; j<10;j++){
            //Comprobar si la weita es barco y lo esconde
            if (matriz[i][j] > 96 && matriz[i][j] < 101){
                printf("[%c]", '_');
            }
            else{
                printf("[%c]",matriz[i][j]);
            }
            
        }
        printf("%d\n",i);
        if (i==9){
            printf("  A  B  C  D  E  F  G  H  I  J\n");
            }
        }

    return 0;
}
char** imprimir_tablero_Cheat(char** matriz){

    printf("  A  B  C  D  E  F  G  H  I  J\n");
     for (int i=0;i<10;i++){
         printf("%d",i);
        for (int j=0 ; j<10;j++){ 
            printf("[%c]",matriz[i][j]);
            }
        printf("%d\n",i);
        if (i==9){
            printf("  A  B  C  D  E  F  G  H  I  J\n");
            }
        }

    return 0;
}

//Duplicado para recivir info con array

int traducir(char posX){
    int intposX = 0;

    //printf("la wea mal hecha es: %c\n", posX);
    if (posX == 65) intposX = 0;
    else if (posX == 66) intposX = 1;
    else if (posX == 67) intposX = 2;
    else if (posX == 68) intposX = 3;
    else if (posX == 69) intposX = 4;
    else if (posX == 70) intposX = 5;
    else if (posX == 71) intposX = 6;
    else if (posX == 72) intposX = 7;
    else if (posX == 73) intposX = 8;
    else if (posX == 74) intposX = 9;
    else printf("Si entra aqui fallo la cagada\n");
    return intposX;

}
int comprobar(int largo, int intposX, int posY, char orientacion){
    if(largo < 1 || largo > 10 || posY > 9 || posY < 1){
        printf("ERROR, Coordenadas son negativas y/o mayores a las permitidas \n");
        exit(0);
    }
    if(orientacion == 104){
        printf("%d, %c COMPROBAR en if\n", intposX, orientacion);
        if(intposX == 9){
            printf("ERROR, Barco sobrepasa el borde derecho del tablero\n");
            exit(0);
        }
    }
    if(orientacion == 118){
        if((posY + largo - 1) > 9){
            printf("ERROR, Barco sobrepasa el borde inferior\n");
            exit(0);
        }
    
    }
    //poner los siguientes errores: Letras fuera de rango, borde inferior.
    //Barcos ensima de otros barcos
    return 0;
}
//------------------------------aqui empieza la wea del cucho
char** imprimir_pantalla(char** Jpos){
    
    char matriz_u[10][10];
    char** matriz = malloc(10*sizeof(char*));
    for(int i=0; i<10;i++){
        matriz[i]=malloc(10*sizeof(char));
        
    }
    for(int i=0; i<10;i++){
        printf("\n");
        for(int j=0; j<10;j++){
            matriz[i][j] = '_';
            printf("[%c]",matriz[i][j]);
        }
    } 
    

    /*
    //Archivo be like:
    //Jpos[x][0]; Largo barco
    //Jpos[x][1]; Posicion en x (A, B, C ...)
    //Jpos[x][2]; Posicion en y (0, 1, 2, ...)
    //Jpos[x][3]; //orientacion
    */
    
    int largo;
    char posX;
    int posY;
    char orientacion;
    int intposX;
    char lista[4]={'a','b','c','d'};
    for (int c=0;c<4;c++){ //Recorrer Filas del array
        //Largo barco
        largo = Jpos[c][0] - 48;
        //printf("%d largo\n", largo);

        //PosX
        posX = Jpos[c][1];
        //printf("%c Jpos despues\n", Jpos[c][1]);
        printf("%c posX\n", posX);  


        intposX = traducir(posX);


        //printf("%d int posX\n", intposX);
        //PosY
        posY = Jpos[c][2] - 48;
        //printf("%d posY\n", posY);
        //oreintacion 
        orientacion = Jpos[c][3];
        //printf("%c orientacion\n", (char)orientacion); // Recorrer Las lineas y poner en MATRIZ
        
        //
        comprobar(largo, intposX, posY, orientacion); //C O M P R O B A R  
        if (orientacion == 104){ //horizontal
            for(int i=0;i<largo;i++){
                matriz[posY][intposX] = lista[c];
                //printf("%d , %d horizontal \n", intposX, posY);
                intposX ++;
            }
        }
        else if(orientacion == 118){ //Vertical
            for(int i=0;i<largo;i++){
                matriz[posY][intposX] = lista[c];
                //printf("%d , %d vertical \n", intposX, posY);
                posY++;
            }
        } 
        printf("\n");//yap hacer hitscan aqui;
         
    }
    

    printf("  A  B  C  D  E  F  G  H  I  J\n");

     for (int i=0;i<10;i++){
         printf("%d",i);
        for (int j=0 ; j<10;j++){
            char pos_actual = matriz[i][j]; //
            if (pos_actual == 97){//
                matriz[i][j] = lista[0];
                printf("[%c]",matriz[i][j]);
                continue;
            }
            if (pos_actual == 98){//
                matriz[i][j] = lista[1];
                printf("[%c]",matriz[i][j]);
                continue;
            }
            if (pos_actual == 99){
                matriz[i][j] = lista[2];
                printf("[%c]",matriz[i][j]);
                continue;
            }
            if (pos_actual == 100){
                matriz[i][j] = lista[3];
                printf("[%c]",matriz[i][j]);
                continue;
            }  //no hacer nada pq esos espacios ya son 'b'
            else{
                matriz[i][j] = '_';
            }
             ; //rellear con '_' ya que no hay barco
            printf("[%c]",matriz[i][j]);
            }
        printf("%d\n",i);
        if (i==9){
            printf("  A  B  C  D  E  F  G  H  I  J\n");
            }
        }

    return matriz; //matriz es el juego 
                //no se puede retornar matriz :c
}
//aqui termina la wea del cucho---------------------------------|

char* concat(const char *s1, const char *s2){
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
    }

//recibe coordenada del jugador-----------------------------------------------|
char** atacar(char** matriz){
    char cordenada_col[5];//scanf es mas retrasado q un monooooooo,segun yo para los int?
    int coordenada_fila;
    char* lista_cor;
    char s_fila[10];
    printf("ingrese coordenada para atacar, primero ingrese la columna(A,B,C.....)\n");
    scanf("%s",cordenada_col);
    char letrita = cordenada_col[0];
    int columna = traducir(letrita);
    printf("%d",columna);
    printf("\ningrese coordenada para atacar,ingrese la fila(1,2,3....)");
    scanf("%d",&coordenada_fila);
    printf("%c matriz\n", matriz[coordenada_fila][columna]);
    printf("%d comparacion\n", matriz[coordenada_fila][columna] == 97 );
    if (matriz[coordenada_fila][columna] > 96 && matriz[coordenada_fila][columna] < 101){
        matriz[coordenada_fila][columna] = 'X';
        
    }
    else{
        matriz[coordenada_fila][columna] = '.';
        printf("Agua\n");
    }
    
      //  matriz[columna][coordenada_fila] = ;
    //sprintf(s_fila,"%d",coordenada_fila);
    // print our string
    printf("coordenadas ingresadas: %d %d\n",coordenada_fila, columna);
    return matriz;//le tengo q poner &?

    }   





char** leer(FILE* carpeta){
    

    char* token;
    int i;
    char **lineas = malloc(sizeof(char*)*4);
    
    if (carpeta != NULL){
        char line[255];
        
        int contador = 0;

        

        
        while ((fgets(line, sizeof line, carpeta)) != NULL){
            char* linea = malloc(sizeof(char)*4);
            token = strtok(line, ";");
            
            //strcpy(linea,"");
            
            for(i=0;i<5;i++){
                
                
                
                if(i==0){   

                    //printf("\n%s\n",token);
                    token = strtok(NULL,";");
                    }
                
                if(i==1){  

                    linea=concat(linea,token);
                    //printf("%d\n",atoi(token));
                    token = strtok(NULL,";");
                    
                    }
                    
                if(i==2){   
                    linea=concat(linea,token);
                    //printf("%s\n",token);
                    token = strtok(NULL,";");
                    
                    }
                    
                if(i==3){   
                    linea=concat(linea,token);
                    //printf("%d\n",atoi(token));
                    token = strtok(NULL,";");
                    }

                if(i==4){   
                    linea=concat(linea,token);
                    //printf("%s\n",token);
                    token = strtok(NULL,"\n");
                    }
                
                
            }
            lineas[contador] = linea;

            contador++;
        
            
            
        }

        
        for (int i=0;i<4;i++){
            for(int j =0;j<4;j++){
                //printf("\n%c",lineas[i][j]);
            }
        }
        
        
        //fclose(carpeta);

    }
    else{
        printf("Error\n");  
        } 
    return lineas;
    
    
}


//gcc -std=c99 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self Delrio-Ballivian-Tarea1.c -o salida  && ./salida -v posicionesJ1 posicionesJ2

int main (int argc, char** argv){
//int main ()
    //Modo
    //char *mode = argv[1];
    printf("%d",argc);

    char *file_J1;
    char *file_J2;
    file_J1=argv[2];
    file_J2=argv[3];

    char* Archivo2=concat(file_J2,".txt");
    char* Archivo1=concat(file_J1,".txt");
    printf("%s\n",Archivo2);
    printf("%s\n",Archivo1);


    FILE*pos_J1;
    FILE*pos_J2;
    pos_J1=fopen(Archivo1,"r");
    pos_J2=fopen(Archivo2,"r");
    

    //char str[MAXCHAR];
    //transformar esto en una funcion!!
    printf("vamo vien \n");
    
    char** J1 = leer(pos_J1);
    //printf("%c",J1[0][0]);
    printf("vamo vien  parte 2\n");
    
    //imprimir_pantalla(J1);
    //printf("%c pos challa\n", weademat[0][1]);
    

    //aqui empieza el progrma hipoteticamente
    char** tablero;
    tablero = imprimir_pantalla(J1);
    while(1){
        
        int player_num = 1;
        printf("> Bienvenido al battleship chino\n");
  
        imprimir_tablero(tablero);
        tablero = atacar(tablero);

    }

        //algo asi planeo y
    //free(matriz);
    free(Archivo1); 
    free(Archivo2); 
    fclose(pos_J1);
    fclose(pos_J2);

    
    return 0;
}