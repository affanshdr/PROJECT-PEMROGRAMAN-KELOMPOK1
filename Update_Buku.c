#include "Header.h"

void Write_Book_File(int data, Perpus buku[]) {
    FILE * fp;
    fp = fopen("Data_Buku.txt", "w");
    if (fp == NULL) {
        printf("Error while writing...");
        return;
    }

    for (int i = 0; i < data; i++) {
        fprintf(fp, "%u, \"%s\", \"%s\", \"%s\", %u, %u, %u\n", buku[i].Id_buku, buku[i].Judul, buku[i].Penulis,
                buku[i].Penerbit, buku[i].Jumlah_halaman, buku[i].Tahun_terbit, buku[i].Jumlah_tersedia);
    }

    fclose(fp);
}

void Update_Buku() {
    char buffer[256];
    int pilihan;
    int temp;
    Perpus buku[Max_char];
    FILE * fp;
    fp = fopen("Data_Buku.txt", "r");
    if (fp == NULL) {
        printf("Error while reading...");
        return;
    }

    int data = 0;
    while (fgets(buffer, 256, fp) != NULL) {
        sscanf(buffer, "%u, \"%[^\"]\", \"%[^\"]\", \"%[^\"]\", %u, %u, %u", &buku[data].Id_buku, buku[data].Judul, buku[data].Penulis,
               buku[data].Penerbit, &buku[data].Jumlah_halaman, &buku[data].Tahun_terbit, &buku[data].Jumlah_tersedia);
        data++;
    }

    fclose(fp);

    unsigned int id;
    printf("Masukkan Id buku yang ingin diupdate: ");
    scanf("%u", &id);
    getchar(); // Membersihkan karakter newline yang tersisa di input buffer

    for (int i = 0; i < data; i++) {
        if (buku[i].Id_buku == id) {
            temp = i;
            break; // Keluar dari loop setelah menemukan buku yang sesuai
        }
    }

    do {
        printf("\nOpsi yang ingin diupdate:\n");
        printf("1. Id buku\n");
        printf("2. Judul buku\n");
        printf("3. Penulis buku\n");
        printf("4. Penerbit buku\n");
        printf("5. Jumlah halaman buku\n");
        printf("6. Tahun terbit buku\n");
        printf("7. Stock buku\n");
        printf("8. Kembali\n");
        printf("Pilihan anda (1-8): ");
        scanf("%d", &pilihan);
        getchar(); // Membersihkan karakter newline yang tersisa di input buffer

        switch (pilihan) {
            case 1:
                Clear_System();
                printf("Id baru: ");
                scanf("%u", &buku[temp].Id_buku);
                getchar(); // Membersihkan karakter newline yang tersisa di input buffer
                break;

            case 2:
                Clear_System();
                printf("Judul baru: ");
                fgets(buku[temp].Judul, sizeof(buku[temp].Judul), stdin);
                buku[temp].Judul[strcspn(buku[temp].Judul, "\n")] = '\0';
                break;

            case 3:
                Clear_System();
                printf("Penulis baru: ");
                fgets(buku[temp].Penulis, sizeof(buku[temp].Penulis), stdin);
                buku[temp].Penulis[strcspn(buku[temp].Penulis, "\n")] = '\0';
                break;

            case 4:
                Clear_System();
                printf("Penerbit baru: ");
                fgets(buku[temp].Penerbit, sizeof(buku[temp].Penerbit), stdin);
                buku[temp].Penerbit[strcspn(buku[temp].Penerbit, "\n")] = '\0';
                break;

            case 5:
                Clear_System();
                printf("Jumlah halaman baru: ");
                scanf("%u", &buku[temp].Jumlah_halaman);
                getchar(); // Membersihkan karakter newline yang tersisa di input buffer
                break;

            case 6:
                Clear_System();
                printf("Tahun terbit baru: ");
                scanf("%u", &buku[temp].Tahun_terbit);
                getchar(); // Membersihkan karakter newline yang tersisa di input buffer
                break;

            case 7:
                Clear_System();
                printf("Stok baru: ");
                scanf("%u", &buku[temp].Jumlah_tersedia);
                getchar(); // Membersihkan karakter newline yang tersisa di input buffer
                break;

            case 8:
                break;

            default:
                Clear_System();
                printf("\nPilihan anda tidak valid. Silakan ulangi (1-8)\n\n");
                break;
        }
    } while (pilihan > 8);

    Write_Book_File(data, buku);
}