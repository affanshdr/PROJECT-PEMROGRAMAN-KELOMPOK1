#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Header(){
     printf("\nSelamat Datang Di program\n");
    printf("Database Perpustakaan\n");
    printf("===========================\n\n");
}

void Clear_System() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

typedef struct 
{  
    unsigned int Id_Buku;
    char Judul[100];
    char Penulis[100];
    char Penerbit[100];
    unsigned int Jum_Hal;
    unsigned int Tahun_Terbit;
    unsigned int Jum_Tersedia;

} Buku;


int main(int argc, char* argv[]){

    Clear_System();
    Header();


    return 0;

}