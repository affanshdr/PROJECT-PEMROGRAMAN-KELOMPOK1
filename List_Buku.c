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
    
    int data = 0;
    while(fgets(buffer, 512, fp) != NULL){
            sscanf(buffer, "%u, \"%[^\"]\", \"%[^\"]\", \"%[^\"]\", %u, %u, %u", &buku[data].Id_buku, buku[data].Judul, buku[data].Penulis,
                   buku[data].Penerbit, &buku[data].Jumlah_halaman, &buku[data].Tahun_terbit, &buku[data].Jumlah_tersedia);
            data++;
        }
    
    fclose(fp);
        
        for(int i = 0; i < 20; i++){
            if(i == 0){
                printf("+----------------------------------------------------------------------------------------------------------------------------------------+\n");
                printf("| Id_buku | \t\t Judul Buku \t\t | \t Penulis \t | \t Penerbit \t | Jumlah_halaman | Tahun_terbit | stock |\n");
                printf("+----------------------------------------------------------------------------------------------------------------------------------------+\n");
            }
            printf("| %-7u | %-36s | %-21s | %-21s | %-14u | %-12u | %-5u |\n", buku[i].Id_buku, buku[i].Judul, 
                   buku[i].Penulis, buku[i].Penerbit, buku[i].Jumlah_halaman, buku[i].Tahun_terbit, buku[i].Jumlah_tersedia);
            printf("+----------------------------------------------------------------------------------------------------------------------------------------+\n");
            if(i == data - 1){
                break;
            }
        }
        
    printf("\n\n");
    
    return EXIT_SUCCESS;
}