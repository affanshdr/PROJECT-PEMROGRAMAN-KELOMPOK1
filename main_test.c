#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Header.h"

//----------------------- Punya Affan -------------------------------------------

struct Buku {
    int id;
    char judul[100];
    char penulis[100];
    char penerbit[100];
    int halaman;
    int tahun;
    int jumlah;
};

struct Dipinjam {
    char judul[100];
    int jumlah;
};


// Fungsi untuk membaca data buku dari file teks
int Baca_Buku(struct Buku daftar_buku[]) {
    FILE *file = fopen("Data_Buku.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return 0;
    }

    int jumlah_buku = 0;
    while (fscanf(file, "%d, \"%[^\"]\", \"%[^\"]\", \"%[^\"]\", %d, %d, %d\n",
                  &daftar_buku[jumlah_buku].id,
                  daftar_buku[jumlah_buku].judul,
                  daftar_buku[jumlah_buku].penulis,
                  daftar_buku[jumlah_buku].penerbit,
                  &daftar_buku[jumlah_buku].halaman,
                  &daftar_buku[jumlah_buku].tahun,
                  &daftar_buku[jumlah_buku].jumlah) != EOF) {
        jumlah_buku++;
    }

    fclose(file);
    return jumlah_buku;
}

// Fungsi untuk menulis data buku yang tersedia kembali ke file teks
void Tulis_Buku(struct Buku daftar_buku[], int jumlah_buku) {
    FILE *file = fopen("Data_Buku.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    for (int i = 0; i < jumlah_buku; i++) {
        fprintf(file, "%d, \"%s\", \"%s\", \"%s\", %d, %d, %d\n",
                daftar_buku[i].id,
                daftar_buku[i].judul,
                daftar_buku[i].penulis,
                daftar_buku[i].penerbit,
                daftar_buku[i].halaman,
                daftar_buku[i].tahun,
                daftar_buku[i].jumlah);
    }

    fclose(file);
}

// Fungsi untuk menulis data buku yang dipinjam ke file teks baru
void Dipinjam(struct Dipinjam dipinjam[], int jumlah_dipinjam ) {
    FILE *file = fopen("buku_dipinjam.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    for (int i = 0; i < jumlah_dipinjam; i++) {
        fprintf(file, "\"%s\", %d\n", dipinjam[i].judul, dipinjam[i].jumlah);
    }

    fclose(file);
}

// Fungsi untuk meminjam buku
void Pinjam_Buku(struct Buku daftar_buku[], int jumlah_buku, struct Dipinjam dipinjam[], int *jumlah_dipinjam) {
    char judul[100];
    int jumlah_pinjam;
    printf("Masukkan judul buku yang ingin dipinjam: ");
    scanf(" %[^\n]", judul);
    printf("Masukkan jumlah buku yang ingin dipinjam: ");
    scanf("%d", &jumlah_pinjam);

    for (int i = 0; i < jumlah_buku; i++) {
        if (strcmp(judul, daftar_buku[i].judul) == 0) {
            if (daftar_buku[i].jumlah >= jumlah_pinjam) {
                // Menambah buku yang dipinjam ke dalam struktur data
                strcpy(dipinjam[*jumlah_dipinjam].judul, judul);
                dipinjam[*jumlah_dipinjam].jumlah = jumlah_pinjam;
                (*jumlah_dipinjam)++;

                // Mengurangi jumlah buku yang tersedia
                daftar_buku[i].jumlah -= jumlah_pinjam;
                printf("Buku berhasil dipinjam.\n");
            } else {
                printf("Maaf, stok buku tidak mencukupi.\n");
            }
            return;
        }
    }

    printf("Buku tidak ditemukan.\n");
}



//-------------------------------------------- Punya Reza ------------------------------------------------------------------

void List_Buku(){
    char buffer[512];
    Perpus buku[20];
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
}
//----------------------------------------Batas Punya Reza  --------------------------------------------------------------

void Header(){
    printf("\n");
    printf(" +------------------------------------+\n");
    printf(" |      Selamat Datang Di Program     |\n");
    printf(" |            Perpustakaan            |\n");
    printf(" +------------------------------------+\n");
}

void Clear_System() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Header_Admin(){
    printf(" +-------------------------------+\n");
    printf(" |          Login Admin          |\n");
    printf(" +-------------------------------+\n");
}

void Sign_Up(){
    printf(" +--------------------------------+\n");
    printf(" |             Sign Up            |\n");
    printf(" +--------------------------------+\n");
}

void Log_In(){
    printf(" +--------------------------------+\n");
    printf(" |              Login             |\n");
    printf(" +--------------------------------+\n");
}

void Header_User(){
    printf(" +--------------------------------+\n");
    printf(" |            Login User          |\n");
    printf(" +--------------------------------+\n");
}

struct User {
    char username[100];
    char password[100];
};

void SignUpAdmin() {
    
    FILE *file = fopen("Data_Admin.txt", "w"); // Menambahkan data ke file

    if (file == NULL) {
        printf("Error: Gagal membuka file.\n");
        return;
    }

    struct User newUser;

    printf("\n  Masukkan username: ");
    fgets(newUser.username, 100, stdin);
    strtok(newUser.username, "\n"); // Menghapus karakter newline dari input username

    printf("  Masukkan password: ");
    fgets(newUser.password, 100, stdin);
    strtok(newUser.password, "\n"); // Menghapus karakter newline dari input password

    fprintf(file, "%s\n%s\n", newUser.username, newUser.password);
    printf("  Sign-up berhasil!\n");

    fclose(file);
}

void LoginAdmin(int *Selesai2, char *username) {
    char inputUsername[100];
    char inputPassword[100];

    printf("\n  Masukkan username: ");
    fgets(inputUsername, 100, stdin);
    strtok(inputUsername, "\n"); // Menghapus karakter newline dari input username

    printf("  Masukkan password: ");
    fgets(inputPassword, 100, stdin);
    strtok(inputPassword, "\n"); // Menghapus karakter newline dari input password

    FILE *file = fopen("Data_Admin.txt", "r"); // Membuka file untuk membaca data

    if (file == NULL) {
        printf("Error: Gagal membuka file.\n");
        return;
    }

    struct User user;
    char tempUsername[100];
    char tempPassword[100];
    int found = 0;

    // Memeriksa setiap baris dalam file
    while (fgets(tempUsername, 100, file) != NULL) {
        fgets(tempPassword, 100, file); // Membaca password dari baris berikutnya
        strtok(tempUsername, "\n"); // Menghapus karakter newline dari input username
        strtok(tempPassword, "\n"); // Menghapus karakter newline dari input password

        // Memeriksa apakah username dan password cocok
        if (strcmp(tempUsername, inputUsername) == 0 && strcmp(tempPassword, inputPassword) == 0) {
            printf("  Login berhasil!\n");
            (*Selesai2) = 1;
            strcpy(username, inputUsername); // Menyimpan username yang berhasil login
            fclose(file);
            return;
        }
    }

    printf("  Username atau password salah.\n");
    fclose(file);
}

//------------------------------------------------------------------------------------------------------------
void SignUp() {

    FILE *file = fopen("Data_User.txt", "w"); // Menambahkan data ke file

    if (file == NULL) {
        printf("Error: Gagal membuka file.\n");
        return;
    }

    struct User newUser;

    printf("\n  Masukkan username: ");
    fgets(newUser.username, 100, stdin);
    strtok(newUser.username, "\n"); // Menghapus karakter newline dari input username

    printf("  Masukkan password: ");
    fgets(newUser.password, 100, stdin);
    strtok(newUser.password, "\n"); // Menghapus karakter newline dari input password

    fprintf(file, "%s\n%s\n", newUser.username, newUser.password);
    printf("  Sign-up berhasil!\n");

    fclose(file);
}

void Login(int *Selesai2, char *username) {
    char inputUsername[100];
    char inputPassword[100];

    printf("\n  Masukkan username: ");
    fgets(inputUsername, 100, stdin);
    strtok(inputUsername, "\n"); // Menghapus karakter newline dari input username

    printf("  Masukkan password: ");
    fgets(inputPassword, 100, stdin);
    strtok(inputPassword, "\n"); // Menghapus karakter newline dari input password

    FILE *file = fopen("Data_User.txt", "r"); // Membuka file untuk membaca data

    if (file == NULL) {
        printf("Error: Gagal membuka file.\n");
        return;
    }

    struct User user;
    char tempUsername[100];
    char tempPassword[100];
    int found = 0;

    // Memeriksa setiap baris dalam file
    while (fgets(tempUsername, 100, file) != NULL) {
        fgets(tempPassword, 100, file); // Membaca password dari baris berikutnya
        strtok(tempUsername, "\n"); // Menghapus karakter newline dari input username
        strtok(tempPassword, "\n"); // Menghapus karakter newline dari input password

        // Memeriksa apakah username dan password cocok
        if (strcmp(tempUsername, inputUsername) == 0 && strcmp(tempPassword, inputPassword) == 0) {
            printf("  Login berhasil!\n");
            (*Selesai2) = 1;
            strcpy(username, inputUsername); // Menyimpan username yang berhasil login
            fclose(file);
            return;
        }
    }

    printf("  Username atau password salah.\n");
    fclose(file);
}

int main(){
    int Pilihan_Mode;
    int Pilihan_Log;
    int Pilihan_Opsi;
    int Berhasil = 0;
    int Berhasil2 = 0;
    int Berhasil3 = 0;
    char username[100]; // Variabel untuk menyimpan username yang berhasil login
    struct Buku Data_Buku[100];
    struct Dipinjam dipinjam[100];
    
    Clear_System();
    Header();
    
    do {
        while (!Berhasil) {
            Clear_System();
            Header();
            printf("\n   Anda Login Sebagai ?\n");
            printf("\n   1. Admin \n   2. User\n   3. Keluar\n");
            printf("\n   Pilihan Anda ( 1 - 3 ) : ");
            scanf("%d", &Pilihan_Mode);
            while (getchar() != '\n');

            if (Pilihan_Mode < 1 || Pilihan_Mode > 3) {
                printf("\n   Pilihan tidak valid. Silakan masukkan 1, 2, atau 3.\n");
            } else {
                Berhasil = 1; 
            }
        }

        if (Pilihan_Mode == 1) {
            Berhasil = 0;
            Clear_System();
            Header_Admin();
            do {
                printf("\n  1. Sign-up\n  2. Login\n  3. Kembali\n");
                printf("\n  Pilihan Anda: ");
                scanf("%d", &Pilihan_Log);
                while (getchar() != '\n');
            
                if (Pilihan_Log == 1) {
                    Clear_System();
                    Sign_Up();
                    SignUpAdmin();
                }
                if (Pilihan_Log == 2) {
                    Clear_System();
                    Log_In();
                    LoginAdmin(&Berhasil2, username); // Menyimpan username yang berhasil login
                    if (Berhasil2 == 1) {
                        do{
                        printf("\n  Selamat datang, %s!\n", username);
                        Berhasil2 = 0; 
                        printf("\n\t ( Pilihan )\n");
                        printf("\n  1. Create \n  2. Delete\n  3. Update\n  4. Keluar\n");
                        printf("\n    Pilihan Anda: ");
                        scanf("%d", &Pilihan_Opsi);
                        while (getchar() != '\n');

                            switch(Pilihan_Opsi){
                                case 1:
                                Clear_System();
                                printf("\n  Create \n");
                                system("pause");
                                break;
                                case 2:
                                Clear_System();
                                printf("\n  Delete \n");
                                system("pause");
                                break;
                                case 3:
                                Clear_System();
                                printf("\n  Update \n");
                                system("pause");
                                    break;
                            }


                        } while (Pilihan_Opsi != 4);
                        
                        
                       
                    }
                }
            
            } while (Pilihan_Log != 3); 
        }

        if (Pilihan_Mode == 2) {
            Berhasil = 0;
            Clear_System();
            Header_User();

            do {
                printf("\n  1. Sign-up\n  2. Login\n  3. Kembali\n");
                printf("\n  Pilihan Anda: ");
                scanf("%d", &Pilihan_Log);
                while (getchar() != '\n');
            
                if (Pilihan_Log == 1) {
                    Clear_System();
                    Sign_Up();
                    SignUp();
                }
                if (Pilihan_Log == 2) {
                    Clear_System();
                    Log_In();
                    Login(&Berhasil2, username); // Menyimpan username yang berhasil login
                    if (Berhasil2 == 1) {
                        Berhasil2= 0; // Menampilkan pesan selamat datang dengan username
                        do{
                        printf("\n  Selamat datang, %s!\n", username);
                        printf("\n\t ( Pilihan )\n");
                        Berhasil2 = 0; 
                        printf("\n  1. List Buku yang tersedia \n  2. Pinjam Buku\n  3. List Buku yg dipinjam\n  4. Kembalikan Buku\n  5. Keluar\n");
                        printf("\n    Pilihan Anda: ");
                        scanf("%d", &Pilihan_Opsi);
                        while (getchar() != '\n');

                            switch(Pilihan_Opsi){
                                case 1:
                                Clear_System();
                                List_Buku();
                                system("pause");
                                    break;
                                case 2:
                                Clear_System();
                                List_Buku();
                                printf("\n  Pinjam Buku \n ");
                                int jumlah_buku = Baca_Buku(Data_Buku); 
                                int jumlah_dipinjam = 0;
                                if (jumlah_buku == 0) {
                                    printf("Tidak ada data buku.\n");
                                    return 1;
                                }
                                Pinjam_Buku(Data_Buku, jumlah_buku, dipinjam, &jumlah_dipinjam);
                                Tulis_Buku(Data_Buku, jumlah_buku);
                                Dipinjam(dipinjam, jumlah_dipinjam);
                                system("pause");
                                    break;
                                case 3:
                                Clear_System();
                                printf("\n  Kembali Buku \n ");
                                system("pause");
                                break;

                                case 4:
                                Clear_System();
                                printf("\n  Buku yang Dipinjam \n ");
                                system("pause");
                            }

                        } while (Pilihan_Opsi != 5);
                    }
                }
            } while (Pilihan_Log != 3); 
        }
    if(Pilihan_Mode){
        printf("\n  Terima Kasih Ngabs !!\n");
    }
    } while (Pilihan_Mode != 3);  

    return 0;
}
