#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct 
{  
    unsigned int Id_Buku;
    char Judul[100], Penulis[100] , Penerbit[100] ;
    unsigned int Jumlah_Halaman , Tahun_Terbit , Jumlah_Tersedia ;

} Perpus;

//=============================================================
 


// Manajemen Admin ===========================================

  void Create(){
    
    Perpus Buku;
    FILE* fp;
    fp = fopen("Data_Buku.txt", "a"); // Gunakan "a" untuk menambahkan data ke file yang sudah ada
    printf("============================\n");
    printf("      Input Data Buku       \n");
    printf("============================\n");
    if(fp == NULL){
        printf("File Tidak Ditemukan...");
    }
    else {
        printf("\n Id Buku         (int)   : "); 
        scanf("%u", &Buku.Id_Buku); // Menggunakan %u untuk unsigned int
        getchar(); // Membersihkan buffer
        printf("\n Judul Buku      (char)  : "); 
        fgets(Buku.Judul, sizeof(Buku.Judul), stdin); // Menggunakan fgets untuk membaca string
        printf("\n Penulis         (char)  : "); 
        fgets(Buku.Penulis, sizeof(Buku.Penulis), stdin);
        printf("\n Penerbit        (char)  : "); 
        fgets(Buku.Penerbit, sizeof(Buku.Penerbit), stdin);
        printf("\n Jumlah Halaman  (int)   : "); 
        scanf("%u", &Buku.Jumlah_Halaman);
        printf("\n Tahun Terbit    (int)   : "); 
        scanf("%u", &Buku.Tahun_Terbit);
        printf("\n Jumlah Tersedia (int)   : "); 
        scanf("%u", &Buku.Jumlah_Tersedia);
        
        // Menulis data ke file dalam format teks
        fprintf(fp, "%u|%s|%s|%s|%u|%u|%u\n", Buku.Id_Buku, Buku.Judul, Buku.Penulis, Buku.Penerbit, Buku.Jumlah_Halaman, Buku.Tahun_Terbit, Buku.Jumlah_Tersedia);
        
        fclose(fp); // Tutup file setelah selesai menulis
    }
}
    

int main(){

    printf("Data \n");
    Create();
    return 0;
}