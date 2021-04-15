#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//is like globals variable
#define max_rows 10
#define max_col 10
#define MAXCHAR 1000

//functions
void printMap(char map[][max_col]);
int executeShot(int g,int A[][10]);
int incomingShot(char map[][max_col]);
void welcomeScreen();


//condicion de ganar-------------------------------|
//las condiciones para ganar son, J1 mata al J2 o CPU, por ende recibe ambos tableros
int condicion_ganar(char** tablero,int player_num){
    printf("despues de entrar a condiciones\n");
    int contador = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){

            //printf("antes del if por la shit\n");

            if((tablero[i][j] != 'X') && (tablero[i][j] != '_') && (tablero[i][j] != '.')){
                printf("entro esta mierda: %c\n",tablero[i][j]);
                contador++;
                return 0;
                }
        }
    }
    if (contador==0){
        printf("GANO EL JUGADOR %d", player_num);
        exit(0);
    }


}

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
    else intposX = 99;
    return intposX;

}
int comprobar(int largo, int intposX, int posY, char orientacion){
    if(largo < 1 || largo > 10 || posY > 9 || posY < 0){
        printf("ERROR, Coordenadas son negativas y/o mayores a las permitidas \n");
        exit(0);
    }
    if(orientacion == 104){
        printf("%d, %c COMPROBAR en if\n", intposX, orientacion);
        if(intposX == 9){
            printf("ERROR, Barco sobrepasa el borde derecho del tablero\n");
            exit(0);
        }
        else if((intposX + largo - 1) > 9){
            printf("ERROR, Barco sobrepasa el borde derecho\n");
            exit(0);
        }
    }
    if(orientacion == 118){
        if((posY + largo - 1) > 9){
            printf("ERROR, Barco sobrepasa el borde inferior\n");
            exit(0);
        }
        if(posY == 9){
            printf("ERROR, Barco sobrepasa el borde inferior\n");
            exit(0);
        }
    
    }
    //ERROR:
    //Barcos ensima de otros barcos
    return 0;
}
//------------------------------aqui empieza la wea del cucho
char** imprimir_pantalla(char** Jpos){
    
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
            if(matriz[posY][intposX] > 96 && matriz[posY][intposX] < 101){ //Comprobar superposicion
                printf("ERROR, Superposicion de barcos detectada\n");
                exit(0);
            }
            for(int i=0;i<largo;i++){
                matriz[posY][intposX] = lista[c];
                //printf("%d , %d horizontal \n", intposX, posY);
                intposX ++;
                }
            
        }
        else if(orientacion == 118){ //Vertical
            if(matriz[posY][intposX] > 96 && matriz[posY][intposX] < 101){ 
                printf("ERROR, Superposicion de barcos detectada\n");
                exit(0);
            }
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
            char pos_actual = matriz[i][j]; 
            if (pos_actual == 97){//a
                matriz[i][j] = lista[0];
                printf("[%c]",matriz[i][j]);
                continue;
            }
            if (pos_actual == 98){//b
                matriz[i][j] = lista[1];
                printf("[%c]",matriz[i][j]);
                continue;
            }
            if (pos_actual == 99){//c
                matriz[i][j] = lista[2];
                printf("[%c]",matriz[i][j]);
                continue;
            }
            if (pos_actual == 100){//d
                matriz[i][j] = lista[3];
                printf("[%c]",matriz[i][j]);
                continue;
            }  
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
}
//aqui termina la wea del cucho---------------------------------|

char* concat(const char *s1, const char *s2){
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
    }

//recibe coordenada del bot-----------------------------------------------|
//hacer que no coloque dos veces la msima coordenada
char** atacar_bot(char** matriz){
    int columna;
    int fila;
    srand(time(NULL));
    while(1){
        columna = rand()%10;
        fila = rand()%10;
        printf("\ncoordenadas ingresadas por el bot: %d y %d\n",fila,columna);
        if (matriz[fila][columna] > 96 && matriz[fila][columna] < 101){
            matriz[fila][columna] = 'X';
            printf("Impacto!\n");
            break;
        }
        else if((matriz[fila][columna] == 46) //Comprobar Agua 
                || (matriz[fila][columna] == 88)){ //Comprobar X
                printf("Esas coordenadas ya fueron Seleccionadas! \n");
                continue;
                }
        else{
            matriz[fila][columna] = '.';
            printf("Agua!\n");
            break;
        }
    }
    return matriz;

}
//recibe coordenada del jugador-----------------------------------------------|
//hacer que no coloque dos veces la msima coordenada
char** atacar(char** matriz){
    char cordenada_col[5];//scanf es mas retrasado q un monooooooo,segun yo para los int?
    int coordenada_fila;
    int columna;
    while(1){
        //Coordenadas ABC
        while(1){
            printf("ingrese coordenada para atacar, primero ingrese la columna(A,B,C.....)\n");
            scanf("%s",cordenada_col);
            char letrita = cordenada_col[0];
            columna = traducir(letrita);
            if(columna == 99){
                printf("Letra No existe en el tablero\n");
                continue;
            }
            else{
                break;
            }

        }

        //Coordenadas 123
        while(1){
            printf("\ningrese coordenada para atacar,ingrese la fila(1,2,3....)\n");
            scanf("%d",&coordenada_fila);
            if(coordenada_fila > 9 || coordenada_fila < 0){ //Comprobar que sean legales la fila
                printf("Error, Coordenada ingresada Invalida.\n");
                continue;
            }
            else{
                break;
            }
        }
        printf("%d Columna, %d Fila\n", columna, coordenada_fila);
        printf("%c matriz\n", matriz[coordenada_fila][columna]);
        printf("%d comparacion\n", matriz[coordenada_fila][columna] == 97 );

        //impacto o no
        if (matriz[coordenada_fila][columna] > 96 && matriz[coordenada_fila][columna] < 101){
            matriz[coordenada_fila][columna] = 'X';
            printf("Impacto!\n");
            break;
            
        }//Error: colocar la coordenada ya puesta
        else if((matriz[coordenada_fila][columna] == 46) //Comprobar Agua 
            || (matriz[coordenada_fila][columna] == 88)){ //Comprobar X
            printf("Esas coordenadas ya fueron Seleccionadas! \n");
            continue;

            } 
        else{
            matriz[coordenada_fila][columna] = '.';
            printf("Agua!\n");
            break;
        }
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

    char** J1 = leer(pos_J1);
    char** J2 = leer(pos_J2);

    //aqui empieza el progrma hipoteticamente
    char** tablero_1;
    char** tablero_2;
    tablero_1 = imprimir_pantalla(J1);
    tablero_2 = imprimir_pantalla(J2);
    int player_num = 2;
    printf("MODO VERSUS\n");
    //MODO VERSUS
    if((strcmp(argv[1], "-v")) == 0){
        printf("bienvenido al battleship peruano, estas en el modo versus, jvj");
        while(1){
            
            if(player_num ==2){
                printf("\nturno player_1\n");
                imprimir_tablero(tablero_2);
                tablero_2 = atacar(tablero_2);
                imprimir_tablero_Cheat(tablero_2);
                printf("cantes de entrar a condiciones");
                condicion_ganar(tablero_2,player_num);
                player_num = 1;
            }
            //turno jugador 2--------|

            if (player_num == 1){

                printf("turno player_2");
                imprimir_tablero(tablero_1);
                tablero_1 = atacar(tablero_1);
                imprimir_tablero_Cheat(tablero_1);
                condicion_ganar(tablero_1,player_num);
                player_num = 2; 
            }
 

        }

            //algo asi planeo y
        //free(matriz);
    }
    //MODO AUTO 
    else if((strcmp(argv[1], "-a")) == 0){
        printf("bienvenido al battleship peruano, estas en el modo autista, jvCPU");
        while(1){
            printf("\nTurno del jugador 1\n");
            imprimir_tablero(tablero_2);
            tablero_2 = atacar(tablero_2);
            imprimir_tablero(tablero_2);
            //imprimir_tablero_Cheat(tablero_1);
            printf("cantes de entrar a condiciones");
            condicion_ganar(tablero_2,player_num);
            //turno del bot qlo
            printf("\nes turno del CPU\n");
            imprimir_tablero(tablero_1);
            tablero_1 = atacar_bot(tablero_1);
            imprimir_tablero(tablero_1);
            //imprimir_tablero_Cheat(tablero_1);

            condicion_ganar(tablero_1,player_num);


        }
    }
    else{
        printf("Modo de juego invalido \n");
    }
    free(Archivo1); 
    free(Archivo2); 
    fclose(pos_J1);
    fclose(pos_J2);
    return 0;
}