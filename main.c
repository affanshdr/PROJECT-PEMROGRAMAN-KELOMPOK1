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

    FILE *file = fopen("Data_user", "r"); // Membuka file untuk membaca data

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
                (*Selesai2)+=1;
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



// ===========================================================



int main(){

    // Variabel
    int Pil  ; // Admin & user dll
    int Pil1 ; // Sign up / login dll
    int Pil2 ;  
    int Selesai  = 0;   // Loop pada Opsi Admin & user
    int Selesai2 = 0;   // Login page
    Clear_System();
    Header();
    
      do {
        printf("\n   Anda Login Sebagai ?\n");
        printf("\n   1. Admin \n   2. User\n");
        printf("\n   Pilihan Anda (1 / 2) : ");
        scanf("%d", &Pil);
        while (getchar() != '\n'); 

        if (Pil != 1 && Pil != 2) {
            printf("\n   Pilihan tidak valid. Silakan masukkan 1 atau 2.\n");
        } else {
            Selesai = 1; 
        }
    } while (!Selesai);

    if (Pil == 1){
        Clear_System();
        Header_Admin();
        printf("\n1. Sign-up\n2. Login\n3. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &Pil1);
        while (getchar() != '\n');
        SignUp();
        Login(&Selesai2);
        printf("Nilai Selesai %d\n", Selesai2);
        printf("1. Create Buku\n");
        printf("2. Hapus Buku\n");
        printf("3. Edit Buku\n");
        printf("Masukan Opsi: ");
        scanf("%d", &Pil1);

        do{

        } while(Pil1 == 4);
        

    }

    return 0;
}


        /*
        switch (Pil){
            case 1:
                
        
                Clear_System();
                printf(" +-------------------------------+\n");
                printf(" |          Login Admin          |\n");
                printf(" +-------------------------------+\n");
                Identitas Identitas_User = Login_Pengguna(); // Username && Password
                printf("\nSelamat Datang %s", Identitas_User.Username);
                //printf("\nPass :  %s\n", Identitas_User.Password);
                printf("1. Create Buku\n");
                printf("2. Hapus Buku\n");
                printf("3. Edit Buku\n");
                printf("Masukan Opsi: ");
                scanf("%d", &Pil1);
                
                switch (Pil1)
                {
                case 1:
                    Create();
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
                
            case 2 :
                
                Clear_System();
                printf("+------------------------+\n");
                printf("|       Login User       |\n");
                printf("+------------------------+\n");
               
                printf("1. Lihat Buku\n");
                printf("2. Pinjam Buku\n");
                printf("3. List Buku yang Dipinjam\n");
                printf("4. Balikkan Buku\n");
                printf("\nOpsi Anda: ");
                scanf("%d", &Pil2);
                

                switch (Pil2)
                {
                case 1:
                    printf("1. Berhasil");
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
                //Work on it
                Selesai = 1;
                break;

            default :
                printf("Mohon masukkan input dengan benar !!\n");
                continue;
        
        }
        */
       //return 0;
    //}
    


