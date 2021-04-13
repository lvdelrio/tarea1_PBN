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

int crear_pantalla(){
    char matriz[12][12];
    printf("  A  B  C  D  E  F  G  H  I  J\n");
     for (int i=0;i<10;i++){
         printf("%d",i);
        for (int j=0 ; j<10;j++){
            matriz[i][j] = '_';
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
char** imprimir_pantalla(char** Jpos){
    char matriz[12][12];
    /*
    //Archivo be like:
    int x = 0; //en cual fila (barco) estamos
    int largo = Jpos[x][0]; //Largo barco
    char posX = Jpos[x][1]; //Posicion en x (A, B, C ...)
    int posY = Jpos[x][2]; //Posicion en y (0, 1, 2, ...)
    char orientacion = Jpos[x][3]; //orientacion
    */
    int largo;
    char posX;
    int posY;
    char orientacion;
    int intposX;
    
    //poner barcos qlos, cambiar la wea de x para los demas barcos
    //portaaviones
    for (int c=0;c<3;c++){ //Recorrer Filas del array
        //Largo barco
        largo = Jpos[0][c];
        //PosX
        posX = Jpos[1][c];
        
        if ((strcmp(&posX,"A")) == 0) intposX = 0;
/*
        else if (strcmp(posX, 'B') == 1) intposX = 1;
        else if (strcmp(posX, 'C') == 1) intposX = 2;
        else if (strcmp(posX, 'D') == 1) intposX = 3;
        else if (strcmp(posX, 'E') == 1) intposX = 4;
        else if (strcmp(posX, 'F') == 1) intposX = 5;
        else if (strcmp(posX, 'G') == 1) intposX = 6;
        else if (strcmp(posX, 'H') == 1) intposX = 7;
        else if (strcmp(posX, 'I') == 1) intposX = 8;
        else if (strcmp(posX, 'J') == 1) intposX = 9;
        */

        else printf("Que chucha weon \n");
        //PosY
        posY = Jpos[c][2];
        //oreintacion 
        orientacion = Jpos[c][3];// Recorrer Las lineas y poner en MATRIZ
        if (strcmp(orientacion, 'h') == 1){
            for(int i=0;i<largo;i++) {
                intposX += i;
                matriz[intposX][posY] = 'b';
            }
        }
        else{
            for(int i=0;i<largo;i++) {
                posY += i;
                matriz[intposX][posY] = 'b';
            }

        }        
            
    } 

    printf("  A  B  C  D  E  F  G  H  I  J\n");
     for (int i=0;i<10;i++){
         printf("%d",i);
        for (int j=0 ; j<10;j++){
            if (strcmp(matriz[i][j], 'b') == 1){
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

    return 0;
}

char* concat(const char *s1, const char *s2){
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
    }
//Esto me tira core dumped

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

    
    //welcomeScreen();
    crear_pantalla();

    //char str[MAXCHAR];
    //transformar esto en una funcion!!
    printf("vamo vien \n");
    
    char** J1 = leer(pos_J1);
    //printf("%c",J1[0][0]);
    printf("vamo vien  parte 2\n");
    imprimir_pantalla(J1);


    free(Archivo1); 
    free(Archivo2); 
    fclose(pos_J1);
    fclose(pos_J2);

    
    return 0;
}