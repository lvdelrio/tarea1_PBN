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
    int i=0;
    char ch[100][50];
    FILE*file;
    file=fopen("posicionesJ1.txt","r");

    //char str[MAXCHAR];
    printf("vamo vien \n");
    while(1){
        char r =(char)fgetc(file);
        int k = 0;
        printf("pico pal q lee");
        while (!feof(file)){
            ch[i][k++] = r;
            r = (char)fgetc(file);
            if ((r >= '0' && r <= '9')){
                printf(" numeros a guardar: %c\n",r);
                }
            
            }
        ch[i][k]=0;
        if(feof(file)){
            break;
            }
        i++;
    }

    printf("Chupalo github qlo metete el git por donde te quepa\n");
    fclose(file);
    return 0;
    }

int main (){
    //welcomeScreen();
    imprimir_pantalla();

    }