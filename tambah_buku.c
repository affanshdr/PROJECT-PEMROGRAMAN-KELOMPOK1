#include "Header.h"

// Fungsi untuk menambahkan buku baru dalam sistem
void Create_Buku() {
    Perpus buku;

    // Menampilkan perintah untuk memasukkan informasi buku 
    printf("--Masukkan informasi buku baru--\n");
    // Meminta admin untuk memasukkan id buku
    printf("ID: ");
    scanf("%u", &buku.Id_buku);
    // Meminta admin untuk memasukkan judul buku
    printf("Judul: "); 
    // Membersihkan newline character dari buffer
    getchar();
    fgets(buku.Judul, Max_char, stdin);
    // Menghapus newline character dari judul
    buku.Judul[strcspn(buku.Judul, "\n")] = '\0'; 
    // Meminta admin untuk memasukkan nama penulis buku
    printf("Penulis: ");
    fgets(buku.Penulis, Max_char, stdin);
    // Menghapus newline character dari penulis
    buku.Penulis[strcspn(buku.Penulis, "\n")] = '\0'; 
    // Meminta admin untuk memasukkan nama penerbit buku
    printf("Penerbit: ");
    fgets(buku.Penerbit, Max_char, stdin);
    // Menghapus newline character dari penerbit
    buku.Penerbit[strcspn(buku.Penerbit, "\n")] = '\0'; 
    // Meminta admin untuk memasukkan jumlah halaman buku
    printf("Jumlah Halaman: ");
    scanf("%u", &buku.Jumlah_halaman);
    // Meminta admin untuk memasukkan tahun terbit buku
    printf("Tahun Terbit: ");
    scanf("%u", &buku.Tahun_terbit);
    // Meminta admin untuk memasukkan slot buku yang ada
    printf("Jumlah Tersedia: ");
    scanf("%u", &buku.Jumlah_tersedia);

    // Buka file untuk menambahkan data buku baru
    FILE *file = fopen("Data_Buku.txt", "a");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
    }

    // Menulis data buku baru ke dalam file
    fprintf(file, "\n%u, \"%s\", \"%s\", \"%s\", %u, %u, %u", buku.Id_buku, buku.Judul, buku.Penulis,
            buku.Penerbit, buku.Jumlah_halaman, buku.Tahun_terbit, buku.Jumlah_tersedia);

    // Menutup file
    fclose(file); 
    printf("Buku berhasil ditambahkan ke dalam sistem.\n");
}
