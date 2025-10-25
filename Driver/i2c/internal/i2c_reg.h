/**
 * @file      i2c_reg.h
 * @brief     Register definitions for the STM32F4xx I2C peripheral.
 */
#ifndef I2C_REG_H
#define I2C_REG_H

#include <stdint.h>

#ifdef __cplusplus
  #define   __I     volatile
#else
  #define   __I     volatile const
#endif
#define     __O     volatile
#define     __IO    volatile

/**
 * @brief Structure type to access the STM32F4xx I2C peripheral registers.
 */
typedef struct {
    __IO uint32_t CR1;      /*!< Offset: 0x00, Control register 1 */
    __IO uint32_t CR2;      /*!< Offset: 0x04, Control register 2 */
    __IO uint32_t OAR1;     /*!< Offset: 0x08, Own address register 1 */
    __IO uint32_t OAR2;     /*!< Offset: 0x0C, Own address register 2 */
    __IO uint32_t DR;       /*!< Offset: 0x10, Data register */
    __IO uint32_t SR1;      /*!< Offset: 0x14, Status register 1 */
    __IO uint32_t SR2;      /*!< Offset: 0x18, Status register 2 */
    __IO uint32_t CCR;      /*!< Offset: 0x1C, Clock control register */
    __IO uint32_t TRISE;    /*!< Offset: 0x20, TRISE register */
    __IO uint32_t FLTR;     /*!< Offset: 0x24, FLTR register */
} i2c_reg_map_t;

/* --- I2Cx_CR1 values ----------------------------------------------------- */

/* SWRST: Software reset */
#define I2C_CR1_SWRST			(1 << 15)

/* Note: Bit 14 is reserved, and forced to 0 by hardware. */

/* ALERT: SMBus alert */
#define I2C_CR1_ALERT			(1 << 13)

/* PEC: Packet error checking */
#define I2C_CR1_PEC			(1 << 12)

/* POS: Acknowledge / PEC position */
#define I2C_CR1_POS			(1 << 11)

/* ACK: Acknowledge enable */
#define I2C_CR1_ACK			(1 << 10)

/* STOP: STOP generation */
#define I2C_CR1_STOP			(1 << 9)

/* START: START generation */
#define I2C_CR1_START			(1 << 8)

/* NOSTRETCH: Clock stretching disable (slave mode) */
#define I2C_CR1_NOSTRETCH		(1 << 7)

/* ENGC: General call enable */
#define I2C_CR1_ENGC			(1 << 6)

/* ENPEC: Enable PEC */
#define I2C_CR1_ENPEC			(1 << 5)

/* ENARP: ARP enable */
#define I2C_CR1_ENARP			(1 << 4)

/* SMBTYPE: SMBus type */
#define I2C_CR1_SMBTYPE			(1 << 3)

/* Note: Bit 2 is reserved, and forced to 0 by hardware. */

/* SMBUS: SMBus mode */
#define I2C_CR1_SMBUS			(1 << 1)

/* PE: Peripheral enable */
#define I2C_CR1_PE			(1 << 0)

/* --- I2Cx_CR2 values ----------------------------------------------------- */

/* Note: Bits [15:13] are reserved, and forced to 0 by hardware. */

/* LAST: DMA last transfer */
#define I2C_CR2_LAST			(1 << 12)

/* DMAEN: DMA requests enable */
#define I2C_CR2_DMAEN			(1 << 11)

/* ITBUFEN: Buffer interrupt enable */
#define I2C_CR2_ITBUFEN			(1 << 10)

/* ITEVTEN: Event interrupt enable */
#define I2C_CR2_ITEVTEN			(1 << 9)

/* ITERREN: Error interrupt enable */
#define I2C_CR2_ITERREN			(1 << 8)

enum i2c_cr2_freq_values  {
	I2C_CR2_FREQ_2MHZ __attribute__ ((deprecated("Replace with 2 directly"))) = 2,
	I2C_CR2_FREQ_3MHZ __attribute__ ((deprecated("Replace with 3 directly"))),
	I2C_CR2_FREQ_4MHZ __attribute__ ((deprecated("Replace with 4 directly"))),
	I2C_CR2_FREQ_5MHZ __attribute__ ((deprecated("Replace with 5 directly"))),
	I2C_CR2_FREQ_6MHZ __attribute__ ((deprecated("Replace with 6 directly"))),
	I2C_CR2_FREQ_7MHZ __attribute__ ((deprecated("Replace with 7 directly"))),
	I2C_CR2_FREQ_8MHZ __attribute__ ((deprecated("Replace with 8 directly"))),
	I2C_CR2_FREQ_9MHZ __attribute__ ((deprecated("Replace with 9 directly"))),
	I2C_CR2_FREQ_10MHZ __attribute__ ((deprecated("Replace with 10 directly"))),
	I2C_CR2_FREQ_11MHZ __attribute__ ((deprecated("Replace with 11 directly"))),
	I2C_CR2_FREQ_12MHZ __attribute__ ((deprecated("Replace with 12 directly"))),
	I2C_CR2_FREQ_13MHZ __attribute__ ((deprecated("Replace with 13 directly"))),
	I2C_CR2_FREQ_14MHZ __attribute__ ((deprecated("Replace with 14 directly"))),
	I2C_CR2_FREQ_15MHZ __attribute__ ((deprecated("Replace with 15 directly"))),
	I2C_CR2_FREQ_16MHZ __attribute__ ((deprecated("Replace with 16 directly"))),
	I2C_CR2_FREQ_17MHZ __attribute__ ((deprecated("Replace with 17 directly"))),
	I2C_CR2_FREQ_18MHZ __attribute__ ((deprecated("Replace with 18 directly"))),
	I2C_CR2_FREQ_19MHZ __attribute__ ((deprecated("Replace with 19 directly"))),
	I2C_CR2_FREQ_20MHZ __attribute__ ((deprecated("Replace with 20 directly"))),
	I2C_CR2_FREQ_21MHZ __attribute__ ((deprecated("Replace with 21 directly"))),
	I2C_CR2_FREQ_22MHZ __attribute__ ((deprecated("Replace with 22 directly"))),
	I2C_CR2_FREQ_23MHZ __attribute__ ((deprecated("Replace with 23 directly"))),
	I2C_CR2_FREQ_24MHZ __attribute__ ((deprecated("Replace with 24 directly"))),
	I2C_CR2_FREQ_25MHZ __attribute__ ((deprecated("Replace with 25 directly"))),
	I2C_CR2_FREQ_26MHZ __attribute__ ((deprecated("Replace with 26 directly"))),
	I2C_CR2_FREQ_27MHZ __attribute__ ((deprecated("Replace with 27 directly"))),
	I2C_CR2_FREQ_28MHZ __attribute__ ((deprecated("Replace with 28 directly"))),
	I2C_CR2_FREQ_29MHZ __attribute__ ((deprecated("Replace with 29 directly"))),
	I2C_CR2_FREQ_30MHZ __attribute__ ((deprecated("Replace with 30 directly"))),
	I2C_CR2_FREQ_31MHZ __attribute__ ((deprecated("Replace with 31 directly"))),
	I2C_CR2_FREQ_32MHZ __attribute__ ((deprecated("Replace with 32 directly"))),
	I2C_CR2_FREQ_33MHZ __attribute__ ((deprecated("Replace with 33 directly"))),
	I2C_CR2_FREQ_34MHZ __attribute__ ((deprecated("Replace with 34 directly"))),
	I2C_CR2_FREQ_35MHZ __attribute__ ((deprecated("Replace with 35 directly"))),
	I2C_CR2_FREQ_36MHZ __attribute__ ((deprecated("Replace with 36 directly"))),
	I2C_CR2_FREQ_37MHZ __attribute__ ((deprecated("Replace with 37 directly"))),
	I2C_CR2_FREQ_38MHZ __attribute__ ((deprecated("Replace with 38 directly"))),
	I2C_CR2_FREQ_39MHZ __attribute__ ((deprecated("Replace with 39 directly"))),
	I2C_CR2_FREQ_40MHZ __attribute__ ((deprecated("Replace with 40 directly"))),
	I2C_CR2_FREQ_41MHZ __attribute__ ((deprecated("Replace with 41 directly"))),
	I2C_CR2_FREQ_42MHZ __attribute__ ((deprecated("Replace with 42 directly"))),
} __attribute__ ((deprecated("Replace _nMHZ with n directly")));


/* --- I2Cx_OAR1 values ---------------------------------------------------- */

/* ADDMODE: Addressing mode (slave mode) */
#define I2C_OAR1_ADDMODE		(1 << 15)
#define I2C_OAR1_ADDMODE_7BIT		0
#define I2C_OAR1_ADDMODE_10BIT		1

/* Note: Bit 14 should always be kept at 1 by software! */

/* Note: Bits [13:10] are reserved, and forced to 0 by hardware. */

/* ADD: Address bits: [7:1] in 7-bit mode, bits [9:0] in 10-bit mode */

/* --- I2Cx_OAR2 values ---------------------------------------------------- */

/* Note: Bits [15:8] are reserved, and forced to 0 by hardware. */

/* ADD2[7:1]: Interface address (bits [7:1] in dual addressing mode) */

/* ENDUAL: Dual addressing mode enable */
#define I2C_OAR2_ENDUAL			(1 << 0)

/* --- I2Cx_DR values ------------------------------------------------------ */

/* Note: Bits [15:8] are reserved, and forced to 0 by hardware. */

/* DR[7:0] 8-bit data register */

/* --- I2Cx_SR1 values ----------------------------------------------------- */

/* SMBALERT: SMBus alert */
#define I2C_SR1_SMBALERT		(1 << 15)

/* TIMEOUT: Timeout or Tlow Error */
#define I2C_SR1_TIMEOUT			(1 << 14)

/* Note: Bit 13 is reserved, and forced to 0 by hardware. */

/* PECERR: PEC Error in reception */
#define I2C_SR1_PECERR			(1 << 12)

/* OVR: Overrun/Underrun */
#define I2C_SR1_OVR			(1 << 11)

/* AF: Acknowledge failure */
#define I2C_SR1_AF			(1 << 10)

/* ARLO: Arbitration lost (master mode) */
#define I2C_SR1_ARLO			(1 << 9)

/* BERR: Bus error */
#define I2C_SR1_BERR			(1 << 8)

/* TxE: Data register empty (transmitters) */
#define I2C_SR1_TxE			(1 << 7)

/* RxNE: Data register not empty (receivers) */
#define I2C_SR1_RxNE			(1 << 6)

/* Note: Bit 5 is reserved, and forced to 0 by hardware. */

/* STOPF: STOP detection (slave mode) */
#define I2C_SR1_STOPF			(1 << 4)

/* ADD10: 10-bit header sent (master mode) */
#define I2C_SR1_ADD10			(1 << 3)

/* BTF: Byte transfer finished */
#define I2C_SR1_BTF			(1 << 2)

/* ADDR: Address sent (master mode) / address matched (slave mode) */
#define I2C_SR1_ADDR			(1 << 1)

/* SB: Start bit (master mode) */
#define I2C_SR1_SB			(1 << 0)

/* --- I2Cx_SR2 values ----------------------------------------------------- */

/* Bits [15:8]: PEC[7:0]: Packet error checking register */

/* DUALF: Dual flag (slave mode) */
#define I2C_SR2_DUALF			(1 << 7)

/* SMBHOST: SMBus host header (slave mode) */
#define I2C_SR2_SMBHOST			(1 << 6)

/* SMBDEFAULT: SMBus device default address (slave mode) */
#define I2C_SR2_SMBDEFAULT		(1 << 5)

/* GENCALL: General call address (slave mode) */
#define I2C_SR2_GENCALL			(1 << 4)

/* Note: Bit 3 is reserved, and forced to 0 by hardware. */

/* TRA: Transmitter / receiver */
#define I2C_SR2_TRA			(1 << 2)

/* BUSY: Bus busy */
#define I2C_SR2_BUSY			(1 << 1)

/* MSL: Master / slave */
#define I2C_SR2_MSL			(1 << 0)

/* --- I2Cx_CCR values ----------------------------------------------------- */

/* F/S: I2C Master mode selection (fast / standard) */
#define I2C_CCR_FS			(1 << 15)

/* DUTY: Fast Mode Duty Cycle */
/** @defgroup i2c_duty_cycle I2C peripheral clock duty cycles
@ingroup i2c_defines

@{*/
#define I2C_CCR_DUTY			(1 << 14)
#define I2C_CCR_DUTY_DIV2		0
#define I2C_CCR_DUTY_16_DIV_9		1
/**@}*/

/* Note: Bits [13:12] are reserved, and forced to 0 by hardware. */

/*
 * Bits [11:0]:
 * CCR[11:0]: Clock control register in Fast/Standard mode (master mode)
 */

/* --- I2Cx_TRISE values --------------------------------------------------- */

/* Note: Bits [15:6] are reserved, and forced to 0 by hardware. */

/*
 * Bits [5:0]:
 * TRISE[5:0]: Maximum rise time in Fast/Standard mode (master mode)
 */

/* --- I2C constant definitions -------------------------------------------- */

/****************************************************************************/
/** @defgroup i2c_rw I2C Read/Write bit
@ingroup i2c_defines

@{*/
#define I2C_WRITE			0
#define I2C_READ			1
/**@}*/

/** FLTR register (I2Cx_FLTR) (noise filter) */
#define I2C_FLTR(i2c_base)		MMIO32((i2c_base) + 0x24)
#define I2C1_FLTR			I2C_FLTR(I2C1)
#define I2C2_FLTR			I2C_FLTR(I2C2)
#define I2C3_FLTR			I2C_FLTR(I2C3)

/**
 * Bits [3:0] DNF - Digital noise filter
 * These bits configure a digital noise filter on SDA and SCL pins.
 * Value sets minimum pulse width needed to trigger i2c operations.
 * 0 disables, 1 - 15 set minimum width to 'n' * TPCLK1
 */
#define I2C_FLTR_DNF_MASK	0xF
#define I2C_FLTR_DNF_SHIFT	0

/**
 * Bit 4 - Analog Noise filter disable
 * Turns off the built in analog noise filter.
 */
#define I2C_FLTR_ANOFF		(1<<4)



#endif // I2C_REG_H
