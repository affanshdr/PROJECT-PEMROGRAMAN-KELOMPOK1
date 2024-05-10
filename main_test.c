#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

void SignUp() {
    FILE *file = fopen("Data_User.txt", "a"); // Menambahkan data ke file

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
    printf("Sign-up berhasil!\n");

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
            printf("Login berhasil!\n");
            (*Selesai2) = 1;
            strcpy(username, inputUsername); // Menyimpan username yang berhasil login
            fclose(file);
            return;
        }
    }

    printf("Username atau password salah.\n");
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
    Clear_System();
    Header();
    
    do {
        while (!Berhasil) {
            Clear_System();
            Header();
            printf("\n   Anda Login Sebagai ?\n");
            printf("\n   1. Admin \n   2. User\n   3. Keluar\n");
            printf("\n   Pilihan Anda (1 / 2) : ");
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
                    SignUp();
                }
                if (Pilihan_Log == 2) {
                    Clear_System();
                    Log_In();
                    Login(&Berhasil2, username); // Menyimpan username yang berhasil login
                    if (Berhasil2 == 1) {
                        do{
                        printf("Selamat datang, %s!\n", username);
                        Berhasil2 = 0; 
                        printf("\n1. Create \n2. Delete\n3. Update\n 4. Keluar");
                        printf("Pilihan Anda: ");
                        scanf("%d", &Pilihan_Opsi);
                        while (getchar() != '\n');

                            switch(Pilihan_Opsi){
                                case 1:
                                    break;
                                case 2:

                                    break;
                                case 3:

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
                        printf("Selamat datang, %s!\n", username);
                        Berhasil2= 0; // Menampilkan pesan selamat datang dengan username
                        do{
                        printf("Selamat datang, %s!\n", username);
                        Berhasil2 = 0; 
                        printf("\n1. List Buku yang tersedia \n2. Pinjam Buku\n3. List Buku yg dipinjam\n 4. Kembalikan Buku\n 5. Keluar");
                        printf("Pilihan Anda: ");
                        scanf("%d", &Pilihan_Opsi);
                        while (getchar() != '\n');

                            switch(Pilihan_Opsi){
                                case 1:
                                    break;
                                case 2:
                                    break;
                                case 3:
                                    break;
                            }


                        } while (Pilihan_Opsi != 5);
                        // Lanjutan login
                    }
                }
            } while (Pilihan_Log != 3); 
        }

    } while (Pilihan_Mode != 3);  

    return 0;
}
