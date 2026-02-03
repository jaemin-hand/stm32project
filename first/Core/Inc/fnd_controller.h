/*
 * fnd_controller.h
 *
 *  Created on: Dec 27, 2025
 *      Author: thswo
 */

#ifndef SRC_FND_CONTROLLER_H_
#define SRC_FND_CONTROLLER_H_
#ifndef INC_FND_CONTROLLER_H_
#define INC_FND_CONTROLLER_H_
#include "main.h"


#define HIGH 1
#define LOW 0

#define false 0
#define true 1

void init_fnd(SPI_HandleTypeDef *hspi);
void send(uint8_t X);

void init_fnd(SPI_HandleTypeDef *hspi);
void fnd_update_isr(void);      // 타이머가 부를 함수
void set_fnd_temp(int temp);

void send_port(uint8_t X, uint8_t port);

void digit4_show(int n, int replay, uint8_t showZero);

void digit4_replay(int n, int replay);

void digit4(int n);

void digit4showZero_replay(int n, int replay);

void digit4showZero(int n);

void digit4_temper(int n,int replay);

void digit2(int n, int port, int replay);

void digit2_port(int n, int port);


#endif /* SRC_FND_CONTROLLER_H_ */
#endif /* INC_FND_CONTROLLER_H_ */
