#include "heaterController.h"


static uint8_t m_state = 0;
void heaterControll(uint8_t onOFF) {
	HAL_GPIO_WritePin(PB5_RELAY_ON_OFF_CTRL_GPIO_Port, GPIO_PIN_5,onOFF);
	m_state = onOFF;
}

uint8_t getHeaterState() {
	return m_state;

}
