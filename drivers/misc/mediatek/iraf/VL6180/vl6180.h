/*
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
/*
 * Definitions for VL6180 sensor chip.
 */
#ifndef __VL6180_H__
#define __VL6180_H__

#include <linux/ioctl.h>


#define VL6180_SUCCESS				    (0)

#define VL6180_ERR_I2C				    (-1)

#define VL6180_ERR_STATUS			    (-3)

#define VL6180_ERR_SETUP_FAILURE		(-4)

#define VL6180_ERR_GETGSENSORDATA		(-5)

#define VL6180_ERR_IDENTIFICATION		(-6)

#define VL6180_ERR                      (-1)

#define IRAF_I2C_BUS_NUM                (1)

#define VL6180_REG_ID                  0x000

#define VL6180_REG_MODE                0x0018

#define VL6180_REG_PART_TO_PART        0x0024

#define VL6180_REG_IGNORE_THRESHOLD    0x0026

#define VL6180_REG_BLOCK_THRESHOLD     0x0028

#define VL6180_REG_RANGE_AMB_HIGH      0x00DA

#define VL6180_REG_RANGE_AMB_LOW       0x00DC

#define VL6180_CHIP_ID                 0x00B4

#define VL6180_REG_RANGE_VALUE         0x0062

#define VL6180_REG_RAW_VALUE           0x0064

#define VL6180_REG_RETURN_RATE         0x0066


#define IRAFMAGIC 'i'

#define KDIRAFIOC_T_OPEN                       _IOWR(IRAFMAGIC, 0, int)

#define KDIRAFIOC_T_CLOSE                      _IOWR(IRAFMAGIC, 5, int)

#define KDIRAFIOC_T_ENABLE                     _IOWR(IRAFMAGIC, 10, int)

#define KDIRAFIOC_T_GET_RANGE                  _IOWR(IRAFMAGIC, 15, int)

#define KDIRAFIOC_T_RESET                      _IOWR(IRAFMAGIC, 20, int)

#define KDIRAFIOC_T_CALIBRATION                _IOWR(IRAFMAGIC, 25, int)

#define KDIRAFIOC_T_FACTORY_TEST               _IOWR(IRAFMAGIC, 30, int)

#endif

