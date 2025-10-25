/**
 * @file      spi_reg.h
 * @brief     Register definitions for the STM32F4xx SPI peripheral.
 * @note      This file is MCU-specific.
 */
#ifndef SPI_REG_H
#define SPI_REG_H

#include <stdint.h>

#ifdef __cplusplus
  #define   __I     volatile
#else
  #define   __I     volatile const
#endif
#define     __O     volatile
#define     __IO    volatile

/**
 * @brief Structure type to access the STM32F4xx SPI peripheral registers.
 */
typedef struct {
    __IO uint32_t CR1;      /*!< Offset: 0x00, Control register 1 */
    __IO uint32_t CR2;      /*!< Offset: 0x04, Control register 2 */
    __IO uint32_t SR;       /*!< Offset: 0x08, Status register */
    __IO uint32_t DR;       /*!< Offset: 0x0C, Data register */
    __IO uint32_t CRCPR;    /*!< Offset: 0x10, CRC polynomial register */
    __IO uint32_t RXCRCR;   /*!< Offset: 0x14, RX CRC register */
    __IO uint32_t TXCRCR;   /*!< Offset: 0x18, TX CRC register */
    __IO uint32_t I2SCFGR;  /*!< Offset: 0x1C, I2S configuration register */
    __IO uint32_t I2SPR;    /*!< Offset: 0x20, I2S prescaler register */
} spi_reg_map_t;

/* --- SPI_CR1 values ------------------------------------------------------ */

/* Note: None of the CR1 bits are used in I2S mode. */

/* BIDIMODE: Bidirectional data mode enable */
#define SPI_CR1_BIDIMODE_2LINE_UNIDIR	(0 << 15)
#define SPI_CR1_BIDIMODE_1LINE_BIDIR	(1 << 15)
#define SPI_CR1_BIDIMODE		(1 << 15)

/* BIDIOE: Output enable in bidirectional mode */
#define SPI_CR1_BIDIOE			(1 << 14)

/* CRCEN: Hardware CRC calculation enable */
#define SPI_CR1_CRCEN			(1 << 13)

/* CRCNEXT: Transmit CRC next */
#define SPI_CR1_CRCNEXT			(1 << 12)

/* RXONLY: Receive only */
#define SPI_CR1_RXONLY			(1 << 10)

/* SSM: Software slave management */
#define SPI_CR1_SSM			(1 << 9)

/* SSI: Internal slave select */
#define SPI_CR1_SSI			(1 << 8)

/* LSBFIRST: Frame format */
/****************************************************************************/
/** @defgroup spi_lsbfirst SPI lsb/msb first
@ingroup spi_defines

@{*/
#define SPI_CR1_MSBFIRST		(0 << 7)
#define SPI_CR1_LSBFIRST		(1 << 7)
/**@}*/

/* SPE: SPI enable */
#define SPI_CR1_SPE			(1 << 6)

/* BR[2:0]: Baud rate control */
/****************************************************************************/
/** @defgroup spi_baudrate SPI peripheral baud rates
@ingroup spi_defines

@{*/
#define SPI_CR1_BAUDRATE_FPCLK_DIV_2	(0x00 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_4	(0x01 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_8	(0x02 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_16	(0x03 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_32	(0x04 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_64	(0x05 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_128	(0x06 << 3)
#define SPI_CR1_BAUDRATE_FPCLK_DIV_256	(0x07 << 3)
/**@}*/
/****************************************************************************/
/** @defgroup spi_br_pre SPI peripheral baud rate prescale values
@ingroup spi_defines

@{*/
#define SPI_CR1_BR_FPCLK_DIV_2		0x0
#define SPI_CR1_BR_FPCLK_DIV_4		0x1
#define SPI_CR1_BR_FPCLK_DIV_8		0x2
#define SPI_CR1_BR_FPCLK_DIV_16		0x3
#define SPI_CR1_BR_FPCLK_DIV_32		0x4
#define SPI_CR1_BR_FPCLK_DIV_64		0x5
#define SPI_CR1_BR_FPCLK_DIV_128	0x6
#define SPI_CR1_BR_FPCLK_DIV_256	0x7
/**@}*/

/* MSTR: Master selection */
#define SPI_CR1_MSTR			(1 << 2)

/* CPOL: Clock polarity */
/****************************************************************************/
/** @defgroup spi_cpol SPI clock polarity
@ingroup spi_defines

@{*/
#define SPI_CR1_CPOL_CLK_TO_0_WHEN_IDLE	(0 << 1)
#define SPI_CR1_CPOL_CLK_TO_1_WHEN_IDLE	(1 << 1)
/**@}*/
#define SPI_CR1_CPOL			(1 << 1)

/* CPHA: Clock phase */
/****************************************************************************/
/** @defgroup spi_cpha SPI clock phase
@ingroup spi_defines

@{*/
#define SPI_CR1_CPHA_CLK_TRANSITION_1	(0 << 0)
#define SPI_CR1_CPHA_CLK_TRANSITION_2	(1 << 0)
/**@}*/
#define SPI_CR1_CPHA			(1 << 0)

/* --- SPI_CR2 values ------------------------------------------------------ */

/* Bits [15:8]: Reserved. Forced to 0 by hardware. Used on F3. */

/* TXEIE: Tx buffer empty interrupt enable */
#define SPI_CR2_TXEIE			(1 << 7)

/* RXNEIE: Rx buffer not empty interrupt enable */
#define SPI_CR2_RXNEIE			(1 << 6)

/* ERRIE: Error interrupt enable */
#define SPI_CR2_ERRIE			(1 << 5)

/* Bits [4:3]: Reserved. Forced to 0 by hardware. */

/* SSOE: SS output enable */
/* Note: Not used in I2S mode. */
#define SPI_CR2_SSOE			(1 << 2)

/* TXDMAEN: Tx buffer DMA enable */
#define SPI_CR2_TXDMAEN			(1 << 1)

/* RXDMAEN: Rx buffer DMA enable */
#define SPI_CR2_RXDMAEN			(1 << 0)

/* --- SPI_SR values ------------------------------------------------------- */

/* Bits [15:8]: Reserved. Forced to 0 by hardware. Used on F3. */

/* BSY: Busy flag */
#define SPI_SR_BSY			(1 << 7)

/* OVR: Overrun flag */
#define SPI_SR_OVR			(1 << 6)

/* MODF: Mode fault */
/* Note: Not used in I2S mode. */
#define SPI_SR_MODF			(1 << 5)

/* CRCERR: CRC error flag */
/* Note: Not used in I2S mode. */
#define SPI_SR_CRCERR			(1 << 4)

/* UDR: Underrun flag */
/* Note: Not used in SPI mode. */
#define SPI_SR_UDR			(1 << 3)

/* CHSIDE: Channel side */
/* Note: Not used in SPI mode. No meaning in PCM mode. */
#define SPI_SR_CHSIDE			(1 << 2)

/* TXE: Transmit buffer empty */
#define SPI_SR_TXE			(1 << 1)

/* RXNE: Receive buffer not empty */
#define SPI_SR_RXNE			(1 << 0)

/* --- SPI_DR values ------------------------------------------------------- */

/* SPI_DR[15:0]: Data Register. */

/* --- SPI_CRCPR values ---------------------------------------------------- */

/* Note: Not used in I2S mode. */
/* SPI_CRCPR [15:0]: CRC Polynomial Register. */

/* --- SPI_RXCRCR values --------------------------------------------------- */

/* Note: Not used in I2S mode. */
/* SPI_RXCRCR [15:0]: RX CRC Register. */

/* --- SPI_TXCRCR values --------------------------------------------------- */

/* Note: Not used in I2S mode. */
/* SPI_TXCRCR [15:0]: TX CRC Register. */

/* --- SPI_I2SCFGR values -------------------------------------------------- */

/* Note: None of these bits are used in SPI mode. */

/* Bits [15:12]: Reserved. Forced to 0 by hardware. */

/* I2SMOD: I2S mode selection */
#define SPI_I2SCFGR_I2SMOD			(1 << 11)

/* I2SE: I2S enable */
#define SPI_I2SCFGR_I2SE			(1 << 10)

/* I2SCFG[9:8]: I2S configuration mode */
#define SPI_I2SCFGR_I2SCFG_LSB			8
#define SPI_I2SCFGR_I2SCFG_SLAVE_TRANSMIT	0x0
#define SPI_I2SCFGR_I2SCFG_SLAVE_RECEIVE	0x1
#define SPI_I2SCFGR_I2SCFG_MASTER_TRANSMIT	0x2
#define SPI_I2SCFGR_I2SCFG_MASTER_RECEIVE	0x3

/* PCMSYNC: PCM frame synchronization */
#define SPI_I2SCFGR_PCMSYNC			(1 << 7)

/* Bit 6: Reserved. Forced to 0 by hardware. */

/* I2SSTD[5:4]: I2S standard selection */
#define SPI_I2SCFGR_I2SSTD_LSB			4
#define SPI_I2SCFGR_I2SSTD_I2S_PHILIPS		0x0
#define SPI_I2SCFGR_I2SSTD_MSB_JUSTIFIED	0x1
#define SPI_I2SCFGR_I2SSTD_LSB_JUSTIFIED	0x2
#define SPI_I2SCFGR_I2SSTD_PCM			0x3

/* CKPOL: Steady state clock polarity */
#define SPI_I2SCFGR_CKPOL			(1 << 3)

/* DATLEN[2:1]: Data length to be transferred */
#define SPI_I2SCFGR_DATLEN_LSB			1
#define SPI_I2SCFGR_DATLEN_16BIT		0x0
#define SPI_I2SCFGR_DATLEN_24BIT		0x1
#define SPI_I2SCFGR_DATLEN_32BIT		0x2

/* CHLEN: Channel length */
#define SPI_I2SCFGR_CHLEN			(1 << 0)

/* --- SPI_I2SPR values ---------------------------------------------------- */

/* Note: None of these bits are used in SPI mode. */

/* Bits [15:10]: Reserved. Forced to 0 by hardware. */

/* MCKOE: Master clock output enable */
#define SPI_I2SPR_MCKOE				(1 << 9)

/* ODD: Odd factor for the prescaler */
#define SPI_I2SPR_ODD				(1 << 8)

/* I2SDIV[7:0]: I2S linear prescaler */
/* 0 and 1 are forbidden values */


#endif // SPI_REG_H
