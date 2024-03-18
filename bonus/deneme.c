#include "so_long_bonus.h"
#include <stdlib.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define FRAME_COUNT 7
#define FRAME_DELAY 100000000// Mikrosaniye cinsinden gecikme süresi (10 milisaniye = 10000 mikrosaniye)

// Hareket animasyonunun frame'leri
char *frame_files[FRAME_COUNT] = {
    "texture/player_walk/run0.xpm",
    "texture/player_walk/run1.xpm",
    "texture/player_walk/run2.xpm",
    "texture/player_walk/run3.xpm",
    "texture/player_walk/run4.xpm",
    "texture/player_walk/run5.xpm",
    "texture/player_walk/run6.xpm"
};

// Oyuncu yapısı
typedef struct {
    int x, y; // Oyuncunun konumu
    int current_frame; // Şu anki frame indeksi
    void *frames[FRAME_COUNT]; // Frame'lerin görsel verileri
} Player;

// MLX yapısı
typedef struct {
    void *mlx;
    void *win;
    Player *player; // Oyuncu
} MLX;

// Oyuncuyu oluştur
Player *createPlayer(void *mlx) {
    Player *player = malloc(sizeof(Player));
    player->x = WIN_WIDTH / 2;
    player->y = WIN_HEIGHT / 2;
    player->current_frame = 0;
    
    // Frame'leri yükle
    for (int i = 0; i < FRAME_COUNT; i++) {
        int width, height;
        player->frames[i] = mlx_xpm_file_to_image(mlx, frame_files[i], &width, &height);
    }
    
    return player;
}

// Oyuncuyu hareket ettir
void movePlayer(Player *player, char direction) {
    int speed = 5; // Hareket hızı
    switch(direction) {
        case 'a': // Sol
            player->x -= speed;
            break;
        case 'd': // Sağ
            player->x += speed;
            break;
        // Diğer yönlere göre hareket işlemleri eklenebilir
    }
}

// Özel delay işlevi
void delay(unsigned int microseconds) {
    unsigned int now = 0;
    unsigned int then = 0;
    while (now - then < microseconds) {
        now++;
    }
}

// Animasyon güncelleme fonksiyonu
int updateAnimation(void *param) {
    MLX *mlx = (MLX *)param;
    Player *player = mlx->player;
    
    // Şu anki frame'i bir sonraki frame'e geç
    player->current_frame = (player->current_frame + 1) % FRAME_COUNT;
    
    // Oyuncuyu yeniden çiz
    mlx_clear_window(mlx->mlx, mlx->win);
    mlx_put_image_to_window(mlx->mlx, mlx->win, player->frames[player->current_frame], player->x, player->y);
    
    // Belirli bir süre beklet (10 milisaniye)
    delay(FRAME_DELAY);
    
    return 0;
}

// Klavye tuşlarına basıldığında çağrılan fonksiyon
int handleKeyPress(int key, void *param) {
    MLX *mlx = (MLX *)param;
    Player *player = mlx->player;
    switch (key) {
        case 0x0061: // 'a' tuşuna basıldığında
            movePlayer(player, 'a');
            break;
        case 0x0064: // 'd' tuşuna basıldığında
            movePlayer(player, 'd');
            break;
        // Diğer tuşlara göre hareket işlemleri eklenebilir
    }
    return 0;
}

// Ana işlev
int main(void) {
    MLX mlx;
    Player *player;
    
    // MLX başlat
    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Oyun");
    
    // Oyuncuyu oluştur
    player = createPlayer(mlx.mlx);
    mlx.player = player;
    
    // Animasyon güncelleme fonksiyonunu tanımla
    mlx_loop_hook(mlx.mlx, updateAnimation, &mlx);
    
    // Klavye olaylarını dinlemek için callback fonksiyonunu tanımla
    mlx_key_hook(mlx.win, handleKeyPress, &mlx);
    
    // Olayları işlemek için MLX döngüsünü başlat
    mlx_loop(mlx.mlx);
    
    return 0;
}
