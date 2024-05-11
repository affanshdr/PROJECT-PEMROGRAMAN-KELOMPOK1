#include <stdio.h>
#include <string.h>

#define MAX_BUKU 100
#define MAX_DIPINJAM 100

struct Buku {
    int id;
    char judul[100];
    char penulis[100];
    char penerbit[100];
    int halaman;
    int tahun;
    int jumlah;
};

// Struktur data untuk menyimpan buku yang dipinjam
struct Dipinjam {
    char judul[100];
    int jumlah;
};

// Fungsi untuk membaca data buku dari file teks
int bacaBuku(struct Buku daftar_buku[]) {
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
void tulisBuku(struct Buku daftar_buku[], int jumlah_buku) {
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
void tulisDipinjam(struct Dipinjam dipinjam[], int jumlah_dipinjam) {
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
void pinjamBuku(struct Buku daftar_buku[], int jumlah_buku, struct Dipinjam dipinjam[], int *jumlah_dipinjam) {
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

int main() {
    struct Buku daftar_buku[100];
    struct Dipinjam dipinjam[100];
    int jumlah_buku = bacaBuku(daftar_buku);
    int jumlah_dipinjam = 0;

    if (jumlah_buku == 0) {
        printf("Tidak ada data buku.\n");
        return 1;
    }

    pinjamBuku(daftar_buku, jumlah_buku, dipinjam, &jumlah_dipinjam);
    tulisBuku(daftar_buku, jumlah_buku);
    tulisDipinjam(dipinjam, jumlah_dipinjam);

    return 0;
}
