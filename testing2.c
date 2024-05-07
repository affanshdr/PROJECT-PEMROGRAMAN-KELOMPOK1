#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define DATABASE_FOLDER "user_databases"

// Struct untuk menyimpan informasi pengguna
struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

// Fungsi untuk membuat atau memperbarui database pengguna
void createOrUpdateUserDatabase(struct User user) {
    char filename[MAX_USERNAME_LENGTH + 5]; // +5 untuk ".txt" dan null terminator

    // Membuat path file database
    sprintf(filename, "%s/%s.txt", DATABASE_FOLDER, user.username);

    FILE *file = fopen(filename, "w"); // Membuka file untuk menulis

    if (file == NULL) {
        printf("Error: Gagal membuka file.\n");
        return;
    }

    // Menulis username dan password ke dalam file
    fprintf(file, "%s\n%s\n", user.username, user.password);

    fclose(file);
}

// Fungsi untuk melakukan login
void login() {
    char inputUsername[MAX_USERNAME_LENGTH];
    char inputPassword[MAX_PASSWORD_LENGTH];

    printf("Masukkan username: ");
    fgets(inputUsername, MAX_USERNAME_LENGTH, stdin);
    strtok(inputUsername, "\n"); // Menghapus karakter newline dari input username

    printf("Masukkan password: ");
    fgets(inputPassword, MAX_PASSWORD_LENGTH, stdin);
    strtok(inputPassword, "\n"); // Menghapus karakter newline dari input password

    // Membuat path file database
    char filename[MAX_USERNAME_LENGTH + 5]; // +5 untuk ".txt" dan null terminator
    sprintf(filename, "%s/%s.txt", DATABASE_FOLDER, inputUsername);

    FILE *file = fopen(filename, "r"); // Membuka file untuk membaca data

    if (file == NULL) {
        printf("Username tidak ditemukan.\n");
        return;
    }

    char storedUsername[MAX_USERNAME_LENGTH];
    char storedPassword[MAX_PASSWORD_LENGTH];

    // Membaca username dan password dari file
    fgets(storedUsername, MAX_USERNAME_LENGTH, file);
    strtok(storedUsername, "\n"); // Menghapus karakter newline dari username yang dibaca
    fgets(storedPassword, MAX_PASSWORD_LENGTH, file);
    strtok(storedPassword, "\n"); // Menghapus karakter newline dari password yang dibaca

    fclose(file);

    // Memeriksa apakah username dan password cocok
    if (strcmp(inputPassword, storedPassword) == 0) {
        printf("Login berhasil!\n");
    } else {
        printf("Password salah.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Login\n2. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        while (getchar() != '\n'); // Membersihkan input buffer

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 2);

    return 0;
}