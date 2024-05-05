#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Manajemen sistem =========================================
void Header(){
    printf("\n");
    printf("+------------------------------------+\n");
    printf("|      Selamat Datang Di Program     |\n");
    printf("|        Database Perpustakaan       |\n");
    printf("+------------------------------------+\n");
}

void Clear_System() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
// ===========================================================

// Manajemen Data Perpus =====================================

typedef struct 
{  
    unsigned int Id_Buku;
    char Judul[100], Penulis[100] , Penerbit[100] ;
    unsigned int Jumlah_Halaman , Tahun_Terbit , Jumlah_Tersedia ;

} Perpus;

//=============================================================
 


// Manajemen Admin ===========================================

    void Create(){
    Clear_System();
    Perpus Buku;
    FILE* fp;
    fp = fopen("Data_Buku.txt", "a"); 
    printf("============================\n");
    printf("      Input Data Buku       \n");
    printf("============================\n");
    if(fp == NULL){
        printf("File Tidak Ditemukan...");
    }
    else {
        printf("\n Id Buku         (int)   : "); 
        scanf("%u", &Buku.Id_Buku); 
        getchar(); 
        printf("\n Judul Buku      (char)  : "); 
        fgets(Buku.Judul, sizeof(Buku.Judul), stdin); 
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
        
        
        fprintf(fp, "%u|%s|%s|%s|%u|%u|%u\n", Buku.Id_Buku, Buku.Judul, Buku.Penulis, Buku.Penerbit, Buku.Jumlah_Halaman, Buku.Tahun_Terbit, Buku.Jumlah_Tersedia);
        
        fclose(fp); 
    }
}
    
// ===========================================================




// Manajemen User ========================================
typedef struct {
    char Username[100];
    char Password[100];
} Identitas;

Identitas Login_Pengguna(){
    Identitas Identitas_Fix;
    printf(" Username User: ");
    fgets(Identitas_Fix.Username, sizeof(Identitas_Fix.Username), stdin);
    
    printf(" Password User: ");
    fgets(Identitas_Fix.Password, sizeof(Identitas_Fix.Password), stdin);
    return Identitas_Fix;
}
// ===========================================================



int main(){

    // Variabel
    int Pil, pil1 , pil2 ;
    int Login;
    int Selesai = 0;
    int Selesai2;


    Clear_System();
    Header();
    
    while(!Selesai){

        printf("\nAnda Login Sebagai ?\n");
        printf("1. Admin \n2. User\n");
        printf("Pilihan Anda (1 / 2) : ");
        scanf("%d", &Login);
        while (getchar() != '\n');
        switch (Login){
            case 1:
                
                while(!Selesai2){
                Clear_System();
                printf("+------------------------+\n");
                printf("|       Login Admin      |\n");
                printf("+------------------------+\n");
                Identitas Identitas_User = Login_Pengguna(); // Username && Password
                printf("\nSelamat Datang %s", Identitas_User.Username);
                //printf("\nPass :  %s\n", Identitas_User.Password);
                printf("1. Create Buku\n");
                printf("2. Hapus Buku\n");
                printf("3. Edit Buku\n");
                printf("Masukan Opsi: ");
                scanf("%d", &Pil);

                switch (Pil)
                {
                case 1:
                    printf("Berhasil 1.");
                    break;
                
                case 2:
                    printf("Berhasil 2.");
                    break;
                
                case 3:
                    printf("Berhasil 3.");
                    break;
                default:
                    printf("Mohon Masukkan opsi dengan benar");
                    continue;
                }

                Selesai = 1;
                break;
                }
            case 2 :
                
                Clear_System();
                printf("+------------------------+\n");
                printf("|       Login User       |\n");
                printf("+------------------------+\n");
                //Login_Pengguna(); // Username && Password

                //Work on it
                Selesai = 1;
                break;

            default :
                printf("Mohon masukkan input dengan benar !!\n");
                continue;
        
        }

    }
    return 0;
}

