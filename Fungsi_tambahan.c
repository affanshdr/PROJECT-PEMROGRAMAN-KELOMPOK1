#include "Header.h"

void Clear_System(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Header(){
    printf("\n");
    printf("+--------------------------------------------------------+\n");
    printf("| \t\t Selamat Datang Di Program \t\t |\n");
    printf("| \t\t\t Perpustakaan \t\t\t |\n");
    printf("+--------------------------------------------------------+\n");
}

void Header2(){
    printf("\t +-------------------------------+\n");
    printf("\t | \t Buku Yang Tersedia \t |\n");
    printf("\t +-------------------------------+\n\n");
}

void Header3(){
    printf("\t +-------------------------------+\n");
    printf("\t | \t Buku Yang Dipinjam \t |\n");
    printf("\t +-------------------------------+\n\n");
}

void Header_Admin(){
    printf("+----------------------------------------+\n");
    printf("| \t\t Login Admin \t\t |\n");
    printf("+----------------------------------------+\n");
}

void Sign_Up(){
    printf("\t +---------------------------------------+\n");
    printf("\t | \t\t Sign Up \t\t |\n");
    printf("\t +---------------------------------------+\n\n");
}

void Log_In(){
    printf("\t +---------------------------------------+\n");
    printf("\t | \t\t Login \t\t\t |\n");
    printf("\t +---------------------------------------+\n\n");
}

void Header_User(){
    printf("+----------------------------------------+\n");
    printf("| \t\t Login User \t\t |\n");
    printf("+----------------------------------------+\n");
}

void Pause() {
    #ifdef _WIN32
    Sleep(2000); // Windows
    #else
    sleep(2); // Unix
    #endif
}


void SignUpAdmin() {
    
    FILE *file = fopen("Data_Admin.txt", "w"); // Menambahkan data ke file

    if (file == NULL) {
        printf("Error: Gagal membuka file.\n");
        return;
    }

    User newUser;

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

    User user;
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

void SignUp() {

    FILE *file = fopen("Data_User.txt", "w"); // Menambahkan data ke file

    if (file == NULL) {
        printf("Error: Gagal membuka file.\n");
        return;
    }

    User newUser;

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

    User user;
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
