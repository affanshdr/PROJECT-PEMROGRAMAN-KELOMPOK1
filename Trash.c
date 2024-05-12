



void Read_Peminjaman(const char *namaFile) {
    // Buka file teks
    FILE *file = fopen(namaFile, "r");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("+------------------------------------------+\n");
    printf("|          Judul Buku        |   Jumlah   |\n");
    printf("+------------------------------------------+\n");

    // Variabel untuk menyimpan judul buku dan jumlah buku yang dipinjam
    struct Dipinjam dipinjam;

    // Baca setiap baris dari file
    while (fscanf(file, "\"%[^\"]\", %d\n", dipinjam.judul, &dipinjam.jumlah) != EOF) {
        printf("| %-27s | %-10d |\n", dipinjam.judul, dipinjam.jumlah);
    }

    printf("+------------------------------------------+\n");

    // Tutup file
    fclose(file);
}