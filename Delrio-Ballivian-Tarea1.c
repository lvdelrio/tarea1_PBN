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

int imprimir_pantalla(){
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

char* concat(const char *s1, const char *s2){
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
    }
//Esto me tira core dumped

char leer(FILE* carpeta){
    

    char* token;
    int i;
    char **lineas = malloc(sizeof(char*)*4);
    
    if (carpeta != NULL){
        char line[255];
        
        int contador = 0;

        

        
        while ((fgets(line, sizeof line, carpeta)) != NULL){
            char* linea = malloc(sizeof(char)*4);
            printf( "ola men");
            token = strtok(line, ";");
            
            //strcpy(linea,"");
            
            for(i=0;i<5;i++){
                
                
                
                if(i==0){   

                    printf("\n%s\n",token);
                    token = strtok(NULL,";");
                    }
                
                if(i==1){  

                    linea=concat(linea,token);
                    printf("%d\n",atoi(token));
                    token = strtok(NULL,";");
                    
                    }
                    
                if(i==2){   
                    linea=concat(linea,token);
                    printf("%s\n",token);
                    token = strtok(NULL,";");
                    
                    }
                    
                if(i==3){   
                    linea=concat(linea,token);
                    printf("%d\n",atoi(token));
                    token = strtok(NULL,";");
                    }

                if(i==4){   
                    linea=concat(linea,token);
                    printf("%s\n",token);
                    token = strtok(NULL,"\n");
                    }
                printf("\n%s",linea);
                
                
            }
            lineas[contador] = linea;
            printf("mirame aqaui %s",lineas[0]);
            contador++;
        
            
            
        }
        printf("ola como esta: %c",lineas[0][0]);
        
        for (int i=0;i<4;i++){
            for(int j =0;j<4;j++){
                printf("\n%c",lineas[i][j]);
            }
        }
        
        
        //fclose(carpeta);

    }
    else{
        printf("Error\n");  
        } 
    //return 0;
    
    
}



int main (int argc, char** argv){
//int main ()
    //Modo
    char *mode = argv[1];

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
    imprimir_pantalla();

    //char str[MAXCHAR];
    //transformar esto en una funcion!!
    printf("vamo vien \n");
    
    leer(pos_J1);
    //coor_player(pos_J1);
    //coor_player(pos_J2);


    free(Archivo1); 
    free(Archivo2); 
    fclose(pos_J1);
    fclose(pos_J2);

    
    return 0;
}