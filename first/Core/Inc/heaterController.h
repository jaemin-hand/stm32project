/*
 * heaterController.h
 *
 *  Created on: Feb 23, 2026
 *      Author: thswo
 */

#ifndef INC_HEATERCONTROLLER_H_
#define INC_HEATERCONTROLLER_H_
#include "main.h"

enum {
	t_OFF = 0,
	t_ON = 1
};

uint8_t getHeaterState();
void heaterControll(uint8_t onOFF);

#endif /* INC_HEATERCONTROLLER_H_ */
