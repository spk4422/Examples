/**
   MappyDot Firmware - i2c_master.h

   Copyright (C) 2017 SensorDots.org

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef I2C_MASTER_H
#define I2C_MASTER_H

#define I2C_READ 0x01
#define I2C_WRITE 0x00

/**
 * \ingroup util_twi
 * \def TW_STATUS_MASK
 * The lower 3 bits of TWSR are reserved on the ATmega163.
 * The 2 LSB carry the prescaler bits on the newer ATmegas.
 */
#define TW_STATUS_MASK		(_BV(TWS7)|_BV(TWS6)|_BV(TWS5)|_BV(TWS4)|\
				_BV(TWS3))
/**
 * \ingroup util_twi
 * \def TW_STATUS
 *
 * TWSR, masked by TW_STATUS_MASK
 */
#define TW_STATUS1		(TWSR1 & TW_STATUS_MASK)

void i2c_init_external(void);
uint8_t i2c_start_external(uint8_t address);
uint8_t i2c_write_external(uint8_t data);
uint8_t i2c_read_ack_external(void);
uint8_t i2c_read_nack_external(void);
uint8_t i2c_transmit_external(uint8_t address, uint8_t* data, uint16_t length);
uint8_t i2c_receive_external(uint8_t address, uint8_t* data, uint16_t length);
uint8_t i2c_writeReg_external(uint8_t devaddr, uint8_t regaddr, uint8_t* data, uint16_t length);
uint8_t i2c_readReg_external(uint8_t devaddr, uint8_t regaddr, uint8_t* data, uint16_t length);
void i2c_stop_external(void);

#endif // I2C_MASTER_H