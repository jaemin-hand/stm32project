#include "fnd_controller.h"

uint8_t _LED_0F[30];
static SPI_HandleTypeDef *mhspi;

void init_fnd(SPI_HandleTypeDef *hspi) {
    mhspi = hspi;
    _LED_0F[0] = 0xC0; _LED_0F[1] = 0xF9; _LED_0F[2] = 0xA4; _LED_0F[3] = 0xB0;
    _LED_0F[4] = 0x99; _LED_0F[5] = 0x92; _LED_0F[6] = 0x82; _LED_0F[7] = 0xF8;
    _LED_0F[8] = 0x80; _LED_0F[9] = 0x90;
    _LED_0F[10] = 0xFF; _LED_0F[11] = 0xBF;
}

void send(uint8_t X) {
    HAL_SPI_Transmit(mhspi, &X, 1, 10);
}

void send_port(uint8_t X, uint8_t port) {
    send(X);
    send(port);
    HAL_GPIO_WritePin(FND_RCLK_GPIO_Port, FND_RCLK_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(FND_RCLK_GPIO_Port, FND_RCLK_Pin, GPIO_PIN_SET);
}

void soft_delay(int loop_cnt) {
    for(volatile int i=0; i<loop_cnt; i++) {
    }
}

void digit4_temper(int n, int replay)
{
    int n1, n2, n3, n4;
    n1 = (int)  n % 10;
    n2 = (int) ((n % 100)) / 10;
    n3 = (int) ((n % 1000)) / 100;
    n4 = (int) ((n % 10000)) / 1000;

    for(int i = 0; i <= replay; i++){
        // 1의 자리
        send_port(_LED_0F[n1], 0b0001);
        soft_delay(5000); // 약 0.2ms 정도 대기 (숫자 조절로 밝기 조절 가능)

        // 10의 자리
        send_port(_LED_0F[n2] & 0x7F, 0b0010);
        soft_delay(5000);

        // 100의 자리
        if(n > 99) send_port(_LED_0F[n3], 0b0100);
        soft_delay(5000);

        // 1000의 자리
        if(n > 999) send_port(_LED_0F[n4], 0b1000);
        soft_delay(5000);
    }
}
