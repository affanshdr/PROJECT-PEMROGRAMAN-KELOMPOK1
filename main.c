#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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


int main(){

    Clear_System();
    Header();
    int Pilihan;
    int Login;
    

   while (1) {
    Clear_System();
    printf(" --- ( Menu / Option ) --- \n");
    printf("\n1. Melihat Buku Yang Tersedia\n");
    printf("2. Meminjam Buku \n");
    printf("3. Mengembalikan Buku\n");
    printf("4. Logout\n");
    printf("\nPilihan Anda ( 1 - 4 ): ");
    scanf("%d", &Pilihan);

    if (Pilihan < 1 || Pilihan > 4) {
        printf("Mohon Masukkan Opsi yang benar\n");
    } else {
        break;
    }
    }

    return 0;

}