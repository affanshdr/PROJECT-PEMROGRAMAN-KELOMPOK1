#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Manajemen sistem =========================================
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

void Header_User(){
    printf("+--------------------------------+\n");
    printf("|            Login User          |\n");
    printf("+--------------------------------+\n");
}
// Manajemen User =================================================

struct User {
    char username[100];
    char password[100];
};

// Fungsi untuk melakukan sign-up
void SignUp() {
    FILE *file = fopen("Data_User.txt", "w"); // Membuka file untuk menambahkan data

    if (file == NULL) {
        printf("Error: Gagal membuka file.\n");
        return;
    }

    struct User newUser;

    printf("Masukkan username: ");
    fgets(newUser.username, 100, stdin);
    strtok(newUser.username, "\n"); // Menghapus karakter newline dari input username

    printf("Masukkan password: ");
    fgets(newUser.password, 100, stdin);
    strtok(newUser.password, "\n"); // Menghapus karakter newline dari input password

    fprintf(file, "%s\n%s\n", newUser.username, newUser.password);
    printf("Sign-up berhasil!\n");

    fclose(file);
}

// Fungsi untuk melakukan login
void Login(int *Selesai2) {
    char inputUsername[100];
    char inputPassword[100];

    printf("Masukkan username: ");
    fgets(inputUsername, 100, stdin);
    strtok(inputUsername, "\n"); // Menghapus karakter newline dari input username

    printf("Masukkan password: ");
    fgets(inputPassword, 100, stdin);
    strtok(inputPassword, "\n"); // Menghapus karakter newline dari input password

    FILE *file = fopen("Data_user.txt", "r"); // Membuka file untuk membaca data

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

        // Memeriksa apakah username cocok
        if (strcmp(tempUsername, inputUsername) == 0) {
            found = 1;
            // Memeriksa apakah password cocok
            if (strcmp(tempPassword, inputPassword) == 0) {
                printf("Login berhasil!\n");
                (*Selesai2)=1;
                fclose(file);
                return;
            } else {
                printf("Password salah.\n");
                fclose(file);
                return;
            }
        }
    }

    if (!found) {
        printf("Username tidak ditemukan.\n");
    }

    fclose(file);
}

int main(){

    // Variabel
    int Pilihan_Mode  ; // Admin & user dll
    int Pilihan_Log ; // Sign up / login dll
    int Pil2 ;  // Opsi Data
    int Berhasil  = 0;   // Loop pada Opsi Admin & user
    int Berhasil2 = 0;   // Login page
    Clear_System();
    Header();
    
    do {
        while(!Berhasil){
            printf("\n   Anda Login Sebagai ?\n");
            printf("\n   1. Admin \n   2. User\n 3.Keluar\n");
            printf("\n   Pilihan Anda (1 / 2) : ");
            scanf("%d", &Pilihan_Mode);
            while (getchar() != '\n'); 

            if (Pilihan_Mode < 1 || Pilihan_Mode > 3) {
                printf("\n   Pilihan tidak valid. Silakan masukkan 1, 2, atau 3.\n");
            } else {
                Berhasil = 1; 
            }
        }
        
        if (Pilihan_Mode == 1){
            do {
                Clear_System();
                Header_Admin();
                printf("\n1. Sign-up\n2. Login\n3. Kembali\n");
                printf("Pilihan Anda: ");
                scanf("%d", &Pilihan_Log);
                while (getchar() != '\n');
                
                if(Pilihan_Log == 1){
                    Clear_System();
                    SignUp();
                }
                else if(Pilihan_Log == 2){
                    Clear_System();
                    Login(&Berhasil2);
                }
            } while (Pilihan_Log != 3); 
            Berhasil = 0; // Reset variabel Berhasil setelah kembali ke menu utama
        }

        if (Pilihan_Mode == 2){
            do {
                Clear_System();
                Header_User();
                printf("\n1. Sign-up\n2. Login\n3. Kembali\n");
                printf("Pilihan Anda: ");
                scanf("%d", &Pilihan_Log);
                while (getchar() != '\n');
                
                if(Pilihan_Log == 1){
                    SignUp();
                }
                else if(Pilihan_Log == 2){
                    Login(&Berhasil2);
                }
            } while (Pilihan_Log != 3); 
            Berhasil = 0; // Reset variabel Berhasil setelah kembali ke menu utama
        }

    } while (Pilihan_Mode != 3);  

    return 0;

}
