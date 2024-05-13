#include "Header.h"

void Display_List_Buku(int page, int data_per_page, int data, Perpus buku[]){
    int stock = 0;
    for(int i = page * data_per_page; i < (page + 1) * data_per_page && i < data; i++){
        if(i == page * data_per_page){
            printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("------------------------------------------------------------------------------------------------------------------------------------------\n\n");
            printf(" %58s<Page %d> \n", " ", page + 1);
            printf("+----------------------------------------------------------------------------------------------------------------------------------------+\n");
            printf("| Id_buku | \t\t Judul Buku \t\t | \t Penulis \t | \t Penerbit \t | Jumlah_halaman | Tahun_terbit | stock |\n");
            printf("+----------------------------------------------------------------------------------------------------------------------------------------+\n");
        }
        printf("| %-7u | %-36s | %-21s | %-21s | %-14u | %-12u | %-5u |\n", buku[i].Id_buku, buku[i].Judul, 
                buku[i].Penulis, buku[i].Penerbit, buku[i].Jumlah_halaman, buku[i].Tahun_terbit, buku[i].Jumlah_tersedia);
        printf("+----------------------------------------------------------------------------------------------------------------------------------------+\n");
            
        stock += buku[i].Jumlah_tersedia;

        if(i == ((page + 1)* data_per_page) - 1 || i == data - 1){
            printf("Jumlah buku \t: %d\n", data);
            printf("Jumlah stock buku : %d\n\n", stock);
            printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("------------------------------------------------------------------------------------------------------------------------------------------\n\n");
            break;
        }
    }
}

void List_Buku(){
    char buffer[512];
    int pilihan;
    int page = 0;
    Perpus buku[Max_char];
    FILE * fp;
    fp = fopen("Data_Buku.txt", "r");
    if(fp == NULL){
        printf("File Error while reading...");
    }
    
    int data = 0;
    while(fgets(buffer, 512, fp) != NULL){
            sscanf(buffer, "%u, \"%[^\"]\", \"%[^\"]\", \"%[^\"]\", %u, %u, %u", &buku[data].Id_buku, buku[data].Judul, buku[data].Penulis,
                   buku[data].Penerbit, &buku[data].Jumlah_halaman, &buku[data].Tahun_terbit, &buku[data].Jumlah_tersedia);
            data++;
    }
    
    fclose(fp);

    int data_per_page = 10;
    int total_page = (data + data_per_page - 1) / data_per_page;

    Display_List_Buku(page, data_per_page, data, buku);

    do{
        printf("Pilihan Opsi :\n");
        printf("1. Page selanjutnya \n2. Page sebelumnya \n3. Kembali\n");
        printf("Pilihan anda (1-3) : ");
        scanf("%d", &pilihan);

        //statemnt dalam memilih opsi
        switch (pilihan)
        {
        case 1:
            if(page < total_page - 1){
                page++;
                Clear_System();
                Display_List_Buku(page, data_per_page, data, buku);
            } else{
                Clear_System();
                Display_List_Buku(page, data_per_page, data, buku);
                printf("\nAnda sudah berada di page terakhir. silahkan lanjutkan pilihan anda (2 atau 3)\n\n");
            }
            break;
        case 2 :
            if(page > 0){
                page--;
                Clear_System();
                Display_List_Buku(page, data_per_page, data, buku);
            } else{
                Clear_System();
                Display_List_Buku(page, data_per_page, data, buku);
                printf("\nAnda sudah berada di page pertama. Silahkan lanjutkan pilihan anda (1 atau 3)\n\n");
            }
            break;
        case 3:
            break;
        
        default:
            Clear_System();
            Display_List_Buku(page, data_per_page, data, buku);
            printf("\nPilihan anda tidak valid. Silahkan ulangi (1-3)\n\n");
            break;
        }
        
        } while(pilihan != 3);

    printf("\n");
}

    
