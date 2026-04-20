/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2
 *   Hari dan Tanggal    : Senin, 20 April 2025
 *   Nama (NIM)          : Kenneth Harrison Siswanto (13224032)
 *   Nama File           : Modul2_Soal1_13224032.c
 *   Deskripsi           : Soal mencari data yang hilang dan menggantinya dengan aturan tertentu.
 * 
 */


 #include <stdio.h>
 #include <string.h>
  
 int main() {
    int N;
    scanf("%d", &N);
    int arr[N];

    for(int k=0; k<N; k++){
        scanf("%d", &arr[k]);
    }

    // cek input
    // for(int j=0; j<N; j++){
    //     printf("%d", arr[j]);
    // }

    for(int j=0; j<N; j++){
        if(arr[j] == -1){
        int kanan = -1; // set default kanan -1 untuk traversal
        // asumsi kiri pasti tidak ada yang -1 karena sudah diubah di loop sebelumnya

            for(int l = j+1; l < N; l++){
                    if(arr[l] != -1){
                        kanan = arr[l]; // kanan jadi data kanan tidak -1
                        break; 
                    }
            }
            
            if(kanan != -1 & arr[j-1] != -1){
                arr[j] = (kanan+arr[j-1])/2;
            }
            else if(kanan != -1){
                arr[j] = kanan;
            }
            else if(arr[j-1] != -1){ // formalitas(?)
                arr[j] = arr[j-1];
            }
            else {
                arr[j] = 0;
            }
        }
    }


    // Recover
    printf("RECOVERED ");
    for(int m = 0; m<N; m++){
        printf("%d ", arr[m]);
    }
    printf("\n");

    // Cari Max Sum
    int sum = 0;
    int maxsum = 0;

    sum = arr[0]; // sum & max sum awal sama dengan nilai pertama array
    maxsum = sum;

    for(int s = 1; s < N; s++){ // mulai dari indeks 1 karena sum awal sudah nilai indeks 0
        if(sum < 0){
            sum = arr[s]; // kalau indeks 0 dan seterusnya dari sum awal nilainya negatif, langsung sum mulai dari indeks berikutnya
        }
        else {
            sum = sum + arr[s];
        }

        if(maxsum < sum){ // menambahkan sum total selama sum menambahkan
            maxsum = sum;
        }
    }

    printf("MAX_SUM %d", maxsum);
    return 0;
}
