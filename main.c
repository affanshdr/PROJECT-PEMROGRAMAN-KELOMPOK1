#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

void Login_Pengguna(){
    char Username[100];
    char Password[100];
    printf(" Username User: ");
    scanf("%s", Username);
    printf(" Password User: ");
    scanf("%s", Password);

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
    int Selesai = 0;
    
    while(!Selesai){

        printf("\nAnda Login Sebagai ?\n");
        printf("1. Admin \n2. User\n3. Kembali\n");
        printf("Pilihan Anda (1 - 3) : ");
        scanf("%d", &Login);
        switch (Login){
            case 1:
                
                Clear_System();
                printf("+------------------------+\n");
                printf("|       Login Admin      |\n");
                printf("+------------------------+\n");
                Login_Pengguna();

                //Work on it 



                Selesai = 1;
                break;
                printf("%d" , Selesai);
            case 2 :
                
                Clear_System();
                printf("+------------------------+\n");
                printf("|       Login User       |\n");
                printf("+------------------------+\n");
                Login_Pengguna();


                //Work on it




                Selesai = 1;
                break;
            case 3:
                continue;

            default :
                printf("Mohon masukkan input dengan benar !!!\n");
                continue;
        
        }

    }
}

    //Clear_System();
    /*
   while (1) {
    printf(" --- ( Menu / Option ) --- \n");
    printf("\n1. Melihat Buku Yang Tersedia\n");
    printf("2. Meminjam Buku \n");
    printf("3. Mengembalikan Buku\n");
    printf("4. Logout\n");
    printf("\nPilihan Anda ( 1 - 4 ): ");
    scanf("%d", &Pilihan);

    if (Pilihan < 1 || Pilihan > 4) {
        //Clear_System();
        printf("Mohon Masukkan Opsi yang benar\n");
    } else {
        break;
    }
    }

    return 0;



*/
