#include "Header.h"

int Baca_Buku(Perpus daftar_buku[]) {
    FILE *file = fopen("Data_Buku.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return 0;
    }

    int jumlah_buku = 0;
    while (fscanf(file, "%d, \"%[^\"]\", \"%[^\"]\", \"%[^\"]\", %d, %d, %d\n",
                  &daftar_buku[jumlah_buku].Id_buku,
                  daftar_buku[jumlah_buku].Judul,
                  daftar_buku[jumlah_buku].Penulis,
                  daftar_buku[jumlah_buku].Penerbit,
                  &daftar_buku[jumlah_buku].Jumlah_halaman,
                  &daftar_buku[jumlah_buku].Tahun_terbit,
                  &daftar_buku[jumlah_buku].Jumlah_tersedia) != EOF) {
        jumlah_buku++;
    }

    fclose(file);
    return jumlah_buku;
}

void Dipinjam(Borrow dipinjam[], int jumlah_dipinjam , char username[] ) {
    FILE *file = fopen(username, "w");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    for (int i = 0; i < jumlah_dipinjam; i++) {
        fprintf(file, "\"%s\", %d\n", dipinjam[i].Judul, dipinjam[i].Jumlah);
    }

    fclose(file);
}

// Fungsi untuk meminjam buku
void Pinjam_Buku(Perpus daftar_buku[], int jumlah_buku, Borrow dipinjam[], int *jumlah_dipinjam) {
    char judul[100];
    int jumlah_pinjam;
    printf("Masukkan judul buku yang ingin dipinjam \t: ");
    scanf(" %[^\n]", judul);
    printf(" Masukkan jumlah buku yang ingin dipinjam \t: ");
    scanf("%d", &jumlah_pinjam);

    for (int i = 0; i < jumlah_buku; i++) {
        if (strcmp(judul, daftar_buku[i].Judul) == 0) {
            if (daftar_buku[i].Jumlah_tersedia >= jumlah_pinjam) {
                // Menambah buku yang dipinjam ke dalam struktur data
                strcpy(dipinjam[*jumlah_dipinjam].Judul, judul);
                dipinjam[*jumlah_dipinjam].Jumlah = jumlah_pinjam;
                                (*jumlah_dipinjam)++;

                // Mengurangi jumlah buku yang tersedia
                daftar_buku[i].Jumlah_tersedia -= jumlah_pinjam;
                printf("Buku berhasil dipinjam.\n");
            } else {
                printf("Maaf, stok buku tidak mencukupi.\n");
            }
            return;
        }
    }

    printf("Buku tidak ditemukan.\n");
}
