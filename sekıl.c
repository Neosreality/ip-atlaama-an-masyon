#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Alan boyutları
#define WIDTH 100
#define HEIGHT 100

// Noktaları tutacak bir yapı
typedef struct {
    int x;
    int y;
} Point;

// Alanımızı tanımlıyoruz
float Alanim[WIDTH][HEIGHT];  // Alanım'daki Türkçe 'ı' harfini 'i' ile değiştirdik

// Spiral için başlangıç parametreleri
float a = 1.0;
float b = 1.0;

// Başlangıç noktası
Point nokta = {0, 0};

// Spiral çizme fonksiyonu
void capi_arttir(int* cap, int theta) {
    *cap = a + b * theta;  // Spiral büyüme fonksiyonu: R(θ) = a + b * θ
}

// Alanı dolaşarak spiral çizme fonksiyonu
void array_dolas() {
    int cap = 1;  // Başlangıç çapı

    // 360 derece döngüsü ile spiral çiziyoruz
    for (int theta = 0; theta < 360; theta++) {
        capi_arttir(&cap, theta);  // Çapı arttırıyoruz

        // x ve y koordinatlarını hesaplıyoruz (radyan cinsinden)
        int x = (int)(cap * cos(theta * M_PI / 180.0));  // x koordinatı
        int y = (int)(cap * sin(theta * M_PI / 180.0));  // y koordinatı

        // Eğer x ve y koordinatları belirlediğimiz alan içinde ise, işaretle
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
            Alanim[x][y] = 1.0;  // Alan içinde "1" değeriyle işaretliyoruz
        }
    }

    // Alanı ekrana yazdırma
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (Alanim[i][j] == 1.0) {
                printf("*");  // Spiral çizilen noktalar
            } else {
                printf(" ");  // Diğer noktalar boşluk
            }
        }
        printf("\n");
    }
}

int main() {
    // Alanı sıfırlıyoruz (tüm değerleri 0 yapıyoruz)
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            Alanim[i][j] = 0.0;
        }
    }

    // Spiral çizme fonksiyonunu çağırıyoruz
    array_dolas();

    return 0;
}
