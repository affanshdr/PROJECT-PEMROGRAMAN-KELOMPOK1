#include "Header.h"

int main(){
    char buffer[512];
    Perpus buku[20];
    FILE * fp;
    fp = fopen("Data_Buku.txt", "r");
    if(fp == NULL){
        printf("File Error while reading...");
        return EXIT_FAILURE;
    }
    
    int i = 0;
    while(fgets(buffer, 512, fp) != NULL && i < 20){
            sscanf(buffer, "%u, \"%[^\"]\", \"%[^\"]\", \"%[^\"]\", %u, %u, %u", &buku[i].Id_buku, buku[i].Judul, buku[i].Penulis,
                   buku[i].Penerbit, &buku[i].Jumlah_halaman, &buku[i].Tahun_terbit, &buku[i].Jumlah_tersedia);
            i++;
        }
        
        for(i = 0; i < 20; i++){
            if(i == 0){
                printf("+------------------------------------------------------------------------------------------------------------------------+\n");
                printf("| Id_buku | \t Judul Buku \t | \t Penulis \t | \t Penerbit \t | Jumlah_halaman | Tahun_terbit | stock |\n");
                printf("+------------------------------------------------------------------------------------------------------------------------+\n");
            }
            printf("| %-7u | %-30s | %-20s | %-20s | %-7u | %-12u | %-5u |\n", buku[i].Id_buku, buku[i].Judul, 
                   buku[i].Penulis, buku[i].Penerbit, buku[i].Jumlah_halaman, buku[i].Tahun_terbit, buku[i].Jumlah_tersedia);
            printf("+------------------------------------------------------------------------------------------------------------------------+\n");
        }
        
    printf("\n\n");
    
    return EXIT_SUCCESS;
}