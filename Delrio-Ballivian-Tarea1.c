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


int main (int argc, char** argv){
//int main ()
    //Modo
    char *mode = argv[1];

    char *file_J1;
    char *file_J2;
    file_J1=argv[1];
    file_J2=argv[2];

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
    int i=0;
    char ch[100][50];

    //char str[MAXCHAR];
    printf("vamo vien \n");
    while(1){ //Archivo 1
        char r =(char)fgetc(pos_J1);
        int k = 0;
        printf("pico pal q lee, y el git la chupa con lechuga");
        while (!feof(pos_J1)){
            ch[i][k++] = r;
            r = (char)fgetc(pos_J1);
            if ((r >= '0' && r <= '9')){
                printf(" numeros a guardar: %c\n",r);
                }
            
            }
        ch[i][k]=0;
        if(feof(pos_J1)){
            break;
            }
        i++;

    }
    while(1){
        char r =(char)fgetc(pos_J2);
        int k = 0;
        printf("pico pal q lee, y el git la chupa con lechuga");
        while (!feof(pos_J2)){
            ch[i][k++] = r;
            r = (char)fgetc(pos_J2);
            if ((r >= '0' && r <= '9')){
                printf(" numeros a guardar: %c\n",r);
                }
            
            }
        ch[i][k]=0;
        if(feof(pos_J2)){
            break;
            }
        i++;

    }
    fclose(pos_J1);
    fclose(pos_J2);
    
    return 0;
}