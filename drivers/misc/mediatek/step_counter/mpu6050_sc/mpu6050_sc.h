#ifndef MPU6050_H
#define MPU6050_H

#include <linux/ioctl.h>



#define MPU6050_SUCCESS             0
#define MPU6050_ERR_I2C             -1
#define MPU6050_ERR_STATUS          -3
#define MPU6050_ERR_SETUP_FAILURE   -4
#define MPU6050_ERR_GETGSENSORDATA  -5
#define MPU6050_ERR_IDENTIFICATION  -6

#define		ONE_PACKAGE_MAX 	7
#define		MPU_ADDR			0x68
#define		MPU6050_SLEEP		0x40

#define MPUREG_SMPLRT_DIV		0x19
#define MPUREG_CONFIG 			0x1A
#define MPUREG_GYRO_CONFIG		0x1B
#define MPUREG_ACCEL_CONFIG	 	0x1C
#define MPUREG_ACCEL_CONFIG2	0x1D
#define MPUREG_LP_ACCEL_ODR   	0x1E

/* MPU6050 Register Map  (Please refer to MPU6050 Specifications) */
#define MPU6050_REG_DEVID			0x75
#define	MPU6050_REG_BW_RATE			0x1A
#define MPU6050_REG_POWER_CTL                   0x6B
#define MPU6050_REG_POWER_CTL2                  0x6C

#define MPU6050_PWRM2_ACCEL_DISABLE				0x38

#define MPU6050_REG_PWR_CTL	        0x6B    
#define MPU6050_REG_PWR_CTL2        0x6C
#define MPU6050_REG_INT_ENABLE		0x38
#define MPU6050_REG_DATA_FORMAT		0x1C
#define MPU6050_REG_DATAX0			0x3B
#define MPU6050_REG_DATAY0			0x3D
#define MPU6050_REG_DATAZ0			0x3F
#define MPU6050_REG_RESET               0x68

#define MPUREG_FIFO_EN			0x23
#define MPUREG_INT_PIN_CFG		0x37
#define MPUREG_INT_ENABLE		0x38
#define MPUREG_INT_STATUS		0x3A
#define MPUREG_ACCEL_INTEL_CTRL 0x69
#define MPUREG_USER_CTRL		0x6A
#define MPUREG_PWR_MGMT_1		0x6B
#define MPUREG_PWR_MGMT_2		0x6C
#define MPUREG_FIFO_COUNTH		0x72
#define MPUREG_FIFO_R_W			0x74
#define MPUREG_WHOAMI			0x75

#define DLPF_CFG_250HZ			0x00
#define DLPF_CFG_184HZ			0x01
#define DLPF_CFG_92HZ			0x02
#define DLPF_CFG_41HZ			0x03
#define DLPF_CFG_20HZ			0x04
#define DLPF_CFG_10HZ			0x05
#define DLPF_CFG_5HZ			0x06
#define DLPF_CFG_3600HZ			0x07

#define GFSR_250DPS				(0 <<3)
#define GFSR_500DPS				(1 <<3)
#define GFSR_1000DPS			(2 <<3)
#define GFSR_2000DPS			(3 <<3)

#define AFSR_2G					(0 <<3)
#define AFSR_4G					(1 <<3)
#define AFSR_8G					(2 <<3)
#define AFSR_16G				(3 <<3)

#define A_DLPF_CFG_460HZ		0x00
#define A_DLPF_CFG_184HZ		0x01
#define A_DLPF_CFG_92HZ			0x02
#define A_DLPF_CFG_41HZ			0x03
#define A_DLPF_CFG_20HZ			0x04
#define A_DLPF_CFG_10HZ			0x05
#define A_DLPF_CFG_5HZ			0x06
//#define A_DLPF_CFG_460HZ		0x07

#define BIT_H_RESET				(1<<7)
#define BIT_SLEEP				(1<<6)
#define BIT_CYCLE				(1<<5)
#define BIT_GYRO_STANDBY		(1<<4)
#define BIT_PD_PTAT				(1<<3)
#define BIT_CLKSEL				(1<<2)

#define BIT_ACCEL_STBY       	0x38
#define BIT_GYRO_STBY        	0x07
#define BITS_LPA_WAKE_CTRL	 	0xC0
#define BITS_LPA_WAKE_1HZ 		0x00
#define BITS_LPA_WAKE_2HZ 		0x40
#define BITS_LPA_WAKE_20HZ 		0x80

#define BIT_FIFO_RST			0x04
#define BIT_DMP_RST				0x08
#define BIT_I2C_MST_EN			0x20
#define BIT_FIFO_EN				0x40
#define BIT_DMP_EN				0x80

#define BIT_ACCEL_OUT			0x08
#define BITS_GYRO_OUT			0x70

#define BIT_BYPASS_EN           0x2

#define BIT_INT_STATUS_FIFO_OVERLOW 0x80
#define BIT_MPU_RDY				0x04
#define BIT_DMP_INT				0x02
#define BIT_RAW_RDY				0x01

#define BIT_ACCEL_INTEL_ENABLE	0x80
#define BIT_ACCEL_INTEL_MODE	0x40
	
#if 1 //20160311 wlg: change to 20608D's DMP
#define DMP_IMG_SIZE							(3302 + 112)
#define MPU_MEM_BANK_SIZE		256
#define MPU_DMP_LOAD_START		0x20 

#define KEY_CFG_PED_ENABLE					2535
#define KEY_D_PEDSTD_STEPCTR					(768 + 0x60)
#define KEY_D_PEDSTD_TIMECTR					964
#define KEY_D_PEDSTD_SB						(768 + 0x28)
#define KEY_CFG_PED_INT						3352
#define KEY_D_DMP_RUN_CNTR					(24*16)
#define KEY_CFG_FIFO_INT						2525
#else //20160311 wlg:back up ori code
#define DMP_IMG_SIZE			2512
#define MPU_MEM_BANK_SIZE		256
#define MPU_DMP_LOAD_START		0x20

#define KEY_CFG_PED_ENABLE		1985
#define KEY_D_PEDSTD_STEPCTR	(768 + 96)
#define KEY_D_PEDSTD_TIMECTR	964
#define KEY_D_PEDSTD_SB			(768 + 40)
#define KEY_CFG_PED_INT			2455
#define KEY_D_DMP_RUN_CNTR		(24*16)
#define KEY_CFG_FIFO_INT		1983
#endif

#define MPUREG_BANK_SEL 0x6D
#define MPUREG_MEM_START_ADDR 0x6E
#define MPUREG_MEM_R_W 0x6F
#define MPUREG_FIFO_R_W 0x74

#define INV_PEDO_IO				0x68

#define INV_PEDO_SET_STATUS			_IOW(INV_PEDO_IO, 0x01, char)
#define INV_PEDO_GET_STATUS			_IOR(INV_PEDO_IO, 0x02, char)
#define INV_PEDO_MPU_SETUP          _IO(INV_PEDO_IO, 0x03)
#define INV_PEDO_DOWNLOAD_FW		_IO(INV_PEDO_IO, 0x04)
#define INV_PEDO_START_DMP			_IO(INV_PEDO_IO, 0x05)
#define INV_PEDO_STOP_DMP   		_IO(INV_PEDO_IO, 0x06)
#define INV_PEDO_ENABLE				_IOW(INV_PEDO_IO, 0x07, char)
#define INV_PEDO_SET_DMP_GESTURE	_IOW(INV_PEDO_IO, 0x08, char)
#define INV_PEDO_SET_THRES			_IOW(INV_PEDO_IO, 0x09, long)
#define INV_PEDO_RESET				_IO(INV_PEDO_IO, 0x0A)
#define INV_PEDO_GET_STEP			_IOR(INV_PEDO_IO, 0x0B, long)

extern int MPU6050_gyro_mode(void);
extern int MPU6050_accel_mode(void);

#endif				/* MPU6050_H */

