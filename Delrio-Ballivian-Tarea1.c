#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char* array_J1;

//condicion de ganar-------------------------------|
//las condiciones para ganar son, J1 mata al J2 o CPU, por ende recibe ambos tableros
int condicion_ganar(char** tablero,int player_num){
    int contador = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){

            if((tablero[i][j] != 'X') && (tablero[i][j] != '_') && (tablero[i][j] != '.')){
                contador++;
                return 0;
                }
        }
    }
    if (contador==0){
        printf("GANO EL JUGADOR %d", player_num);
        exit(0);
    }

    return 0;
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

//imprimir tablero Para saber respuestas
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
int traducir(char posX){
    int intposX = 0;
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
    return 0;
}
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
    int largo;
    char posX;
    int posY;
    char orientacion;
    int intposX;
    char lista[4]={'a','b','c','d'};
    for (int c=0;c<4;c++){ //Recorrer Filas del array
        //Largo barco
        largo = Jpos[c][0] - 48;
        //PosX
        posX = Jpos[c][1]; 
        //Transformar a int
        intposX = traducir(posX);
        //PosY
        posY = Jpos[c][2] - 48;
        //oreintacion 
        orientacion = Jpos[c][3];
        comprobar(largo, intposX, posY, orientacion); //C O M P R O B A R  
        if (orientacion == 104){ //horizontal
            if(matriz[posY][intposX] > 96 && matriz[posY][intposX] < 101){ //Comprobar superposicion
                printf("ERROR, Superposicion de barcos detectada\n");
                exit(0);
            }
            for(int i=0;i<largo;i++){
                matriz[posY][intposX] = lista[c];
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
                    posY++;
                }
        }
        printf("\n");
    } 
    //Tablero
     for (int i=0;i<10;i++){
        for (int j=0 ; j<10;j++){
            char pos_actual = matriz[i][j]; 
            if (pos_actual == 97){//a
                matriz[i][j] = lista[0];
                continue;
            }
            if (pos_actual == 98){//b
                matriz[i][j] = lista[1];
                continue;
            }
            if (pos_actual == 99){//c
                matriz[i][j] = lista[2];
                continue;
            }
            if (pos_actual == 100){//d
                matriz[i][j] = lista[3];
                continue;
            }  
            else{
                matriz[i][j] = '_';
            }
        }
    }

    return matriz; //matriz es el juego 
}
char* concat(const char *s1, const char *s2){
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
    }

char* barco_hundido(char** tablero){
    int contador_barco1 = 0, contador_barco2 = 0, contador_barco3 = 0, contador_barco4 = 0;
    for (int i = 0; i<10;i++){
        for (int j = 0; j<10;j++){
            //------comprueba estado del primer barco------------------|
            if (tablero[i][j] == 'a'){
                contador_barco1++;
                    
            } 
            //------comprueba estado del segundo barco------------------|
            if (tablero[i][j] == 'b'){
                contador_barco2++;
                    
            }
            //------comprueba estado del tercer barco------------------|
            if (tablero[i][j] == 'c' ){
                contador_barco3++;
                   
            }

            //------comprueba estado del cuarto barco------------------|    
            if (tablero[i][j] == 'd'){
                contador_barco4++;
                    
            }

        }
    }


//la parte de abajo verifica barco hundido para el J1-----------------|
    if (contador_barco1 == 0 && array_J1[0] == 0){
        printf("1 barco hundido!!\n");
        array_J1[0]=1;
        }
    if (contador_barco2 == 0 && array_J1[1] == 0){
        printf("2 barco hundido!!\n");
        array_J1[1]=1;
        } 
    if (contador_barco3 == 0 && array_J1[2] == 0){
        printf("3 barco hundido!!\n");
        array_J1[2]=1;
        }
    if (contador_barco4 == 0 && array_J1[3] == 0){
        printf("4 barco hundido!!\n");
        array_J1[3]=1;
        }

//la parte de abajo verifica barco hundido para el J2-----------------|
/*
    if (contador_barco1_j2 == 0 && array_J2[0] == 0){
        printf("1 barco hundido!! j2\n");
        array_J2[0]=1;
        }
    if (contador_barco2_j2 == 0 && array_J2[1] == 0){
        printf("2 barco hundido!! j2\n");
        array_J2[1]=1;
        } 
    if (contador_barco3_j2 == 0 && array_J2[2] == 0){
        printf("3 barco hundido!! j2\n");
        array_J2[2]=1;
        }
    if (contador_barco4_j2 == 0 && array_J2[3] == 0){
        printf("4 barco hundido!! j2\n");
        array_J2[3]=1;
        }  
*/
    return 0;
}

//recibe coordenada del bot-----------------------------------------------|
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
            barco_hundido(matriz);
            break;
        }
        //Comprobacion de misma coordenada
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
char** atacar(char** matriz){
    char cordenada_col[5];
    int coordenada_fila;
    int columna;
    while(1){
        //Coordenadas ABC
        while(1){
            printf("ingrese coordenada para atacar, primero ingrese la columna(A,B,C.....)");
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
            printf("\ningrese coordenada para atacar,ingrese la fila(0,1,2....)");
            scanf("%d",&coordenada_fila);
            if(coordenada_fila > 9 || coordenada_fila < 0){ 
                printf("Error, Coordenada ingresada Invalida.\n");
                continue;
            }
            else{
                break;
            }
        }

        //impacto o no
        if (matriz[coordenada_fila][columna] > 96 && matriz[coordenada_fila][columna] < 101){
            matriz[coordenada_fila][columna] = 'X';
            printf("Impacto!\n");
            barco_hundido(matriz);
            break;
            
        }
        //Comprobacion de misma coordenada
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
        printf("coordenadas ingresadas: %d %d\n",coordenada_fila, columna);
        return matriz;
    }


char** leer(FILE* carpeta){
    char* token;
    int i;
    char** lineas = malloc(sizeof(char*)*4);
    
    if (carpeta != NULL){
        char line[255];
        int contador = 0;

        while ((fgets(line, sizeof line, carpeta)) != NULL){
            char* linea = malloc(sizeof(char)*4);
            token = strtok(line, ";");

            for(i=0;i<5;i++){

                if(i==0){   
                    token = strtok(NULL,";");
                    }
                
                if(i==1){  
                    linea=concat(linea,token);
                    token = strtok(NULL,";");
                    }
                    
                if(i==2){   
                    linea=concat(linea,token);
                    token = strtok(NULL,";");
                    }
                    
                if(i==3){   
                    linea=concat(linea,token);
                    token = strtok(NULL,";");
                    }

                if(i==4){   
                    linea=concat(linea,token);
                    token = strtok(NULL,"\n");
                    }
            }
            lineas[contador] = linea;
            contador++;
        }
    }
    else{
        printf("Error\n");  
        } 
    return lineas;
}


int main (int argc, char** argv){
    array_J1 = calloc(4, sizeof(int));
    for (int i=0;i<4;i++){
        array_J1[i] = 0;
        printf("%d",array_J1[i]);
    }
    printf("%d",argc);

    char *file_J1;
    char *file_J2;
    file_J1=argv[2];
    file_J2=argv[3];
    
    //Recibe 4 Barcos
    char* Archivo2=concat(file_J2,".txt"); 
    char* Archivo1=concat(file_J1,".txt");

    FILE*pos_J1;
    FILE*pos_J2;
    pos_J1=fopen(Archivo1,"r");
    pos_J2=fopen(Archivo2,"r");

    char** J1 = leer(pos_J1);
    char** J2 = leer(pos_J2);

    char** tablero_1;
    char** tablero_2;
    tablero_1 = imprimir_pantalla(J1);
    tablero_2 = imprimir_pantalla(J2);

    int player_num = 2;
    printf("MODO VERSUS\n");
    //MODO VERSUS
    if((strcmp(argv[1], "-v")) == 0){
        printf("bienvenido al battleship, estas en el modo versus, jvj");
        while(1){
            
            if(player_num ==2){
                printf("\nturno player_1\n");
                imprimir_tablero(tablero_2);
                tablero_2 = atacar(tablero_2);
                imprimir_tablero(tablero_2);
                //imprimir_tablero_Cheat(tablero_2); //Tablero respuesta
                condicion_ganar(tablero_2,player_num);
                player_num = 1;
            }
            //turno jugador 2--------|

            if (player_num == 1){

                printf("\nturno player_2\n");
                imprimir_tablero(tablero_1);
                tablero_1 = atacar(tablero_1);
                imprimir_tablero(tablero_1);
                //imprimir_tablero_Cheat(tablero_1); //Tablero respuesta
                condicion_ganar(tablero_1,player_num);
                player_num = 2; 
            }
        }
    }
    //MODO AUTO 
    else if((strcmp(argv[1], "-a")) == 0){
        printf("bienvenido al battleship peruano, estas en el modo autista, jvCPU");
        while(1){
            printf("\nTurno del jugador 1\n");
            imprimir_tablero(tablero_2);
            tablero_2 = atacar(tablero_2);
            imprimir_tablero(tablero_2);
            //imprimir_tablero_Cheat(tablero_1); //Tablero respuesta
            condicion_ganar(tablero_2,player_num);
            //turno del bot 
            printf("\nes turno del CPU\n");
            imprimir_tablero(tablero_1);
            tablero_1 = atacar_bot(tablero_1);
            imprimir_tablero(tablero_1);
            //imprimir_tablero_Cheat(tablero_1); //Tablero respuesta

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
//gcc -std=c99 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self Delrio-Ballivian-Tarea1.c -o salida  && ./salida -v posicionesJ1 posicionesJ2
