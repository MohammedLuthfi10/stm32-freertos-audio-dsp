/**
 * @file      timer_reg.h
 * @brief     Register definitions for the STM32F4xx Timer peripherals.
 */
#ifndef TIMER_REG_H
#define TIMER_REG_H

#include <stdint.h>

#ifdef __cplusplus
  #define   __I     volatile
#else
  #define   __I     volatile const
#endif
#define     __O     volatile
#define     __IO    volatile

/**
 * @brief Structure type to access a general-purpose timer (e.g., TIM2-5).
 */
typedef struct {
    __IO uint32_t CR1;      /*!< Offset: 0x00, Control register 1 */
    __IO uint32_t CR2;      /*!< Offset: 0x04, Control register 2 */
    __IO uint32_t SMCR;     /*!< Offset: 0x08, Slave mode control register */
    __IO uint32_t DIER;     /*!< Offset: 0x0C, DMA/Interrupt enable register */
    __IO uint32_t SR;       /*!< Offset: 0x10, Status register */
    __O  uint32_t EGR;      /*!< Offset: 0x14, Event generation register */
    __IO uint32_t CCMR1;    /*!< Offset: 0x18, Capture/compare mode register 1 */
    __IO uint32_t CCMR2;    /*!< Offset: 0x1C, Capture/compare mode register 2 */
    __IO uint32_t CCER;     /*!< Offset: 0x20, Capture/compare enable register */
    __IO uint32_t CNT;      /*!< Offset: 0x24, Counter */
    __IO uint32_t PSC;      /*!< Offset: 0x28, Prescaler */
    __IO uint32_t ARR;      /*!< Offset: 0x2C, Auto-reload register */
    __IO uint32_t RCR;      /*!< Offset: 0x30, Repetition counter register (TIM1/8) */
    __IO uint32_t CCR1;     /*!< Offset: 0x34, Capture/compare register 1 */
    __IO uint32_t CCR2;     /*!< Offset: 0x38, Capture/compare register 2 */
    __IO uint32_t CCR3;     /*!< Offset: 0x3C, Capture/compare register 3 */
    __IO uint32_t CCR4;     /*!< Offset: 0x40, Capture/compare register 4 */
    __IO uint32_t BDTR;     /*!< Offset: 0x44, Break and dead-time register (TIM1/8) */
    __IO uint32_t DCR;      /*!< Offset: 0x48, DMA control register */
    __IO uint32_t DMAR;     /*!< Offset: 0x4C, DMA address for full transfer */
    __IO uint32_t OR;       /*!< Offset: 0x50, Option register */
} timer_reg_map_t;

/* --- TIM2_OR values ---------------------------------------------------- */

/* ITR1_RMP */
/****************************************************************************/
/** @defgroup tim2_opt_trigger_remap TIM2_OR Timer 2 Option Register Internal
Trigger 1 Remap

Only available in F2 and F4 series.
@ingroup timer_defines

@{*/
/** Internal Trigger 1 remapped to timer 8 trigger out */
#define TIM2_OR_ITR1_RMP_TIM8_TRGOU	(0x0 << 10)
/** Internal Trigger 1 remapped to PTP trigger out */
#define TIM2_OR_ITR1_RMP_PTP		(0x1 << 10)
/** Internal Trigger 1 remapped to USB OTG FS SOF */
#define TIM2_OR_ITR1_RMP_OTG_FS_SOF	(0x2 << 10)
/** Internal Trigger 1 remapped to USB OTG HS SOF */
#define TIM2_OR_ITR1_RMP_OTG_HS_SOF	(0x3 << 10)
/**@}*/
#define TIM2_OR_ITR1_RMP_MASK		(0x3 << 10)

/* --- TIM5_OR values ---------------------------------------------------- */

/* ITR4_RMP */
/****************************************************************************/
/** @defgroup tim5_opt_trigger_remap TIM5_OR Timer 5 Option Register Internal Trigger 4 Remap

Only available in F2 and F4 series.
@ingroup timer_defines

@{*/
/** Internal Trigger 4 remapped to GPIO (see reference manual) */
#define TIM5_OR_TI4_RMP_GPIO		(0x0 << 6)
/** Internal Trigger 4 remapped to LSI internal clock */
#define TIM5_OR_TI4_RMP_LSI		(0x1 << 6)
/** Internal Trigger 4 remapped to LSE internal clock */
#define TIM5_OR_TI4_RMP_LSE		(0x2 << 6)
/** Internal Trigger 4 remapped to RTC output event */
#define TIM5_OR_TI4_RMP_RTC		(0x3 << 6)
/**@}*/
#define TIM5_OR_TI4_RMP_MASK		(0x3 << 6)


/* --- TIMx_CR1 values ----------------------------------------------------- */

/****************************************************************************/
/*tim_x_cr1_cdr TIMx_CR1 CKD[1:0] Clock Division Ratio
*/
/* CKD[1:0]: Clock division */
#define TIM_CR1_CKD_CK_INT		(0x0 << 8)
#define TIM_CR1_CKD_CK_INT_MUL_2	(0x1 << 8)
#define TIM_CR1_CKD_CK_INT_MUL_4	(0x2 << 8)
#define TIM_CR1_CKD_CK_INT_MASK		(0x3 << 8)


/* ARPE: Auto-reload preload enable */
#define TIM_CR1_ARPE			(1 << 7)

/* CMS[1:0]: Center-aligned mode selection */
/****************************************************************************/
/** @defgroup tim_x_cr1_cms TIMx_CR1 CMS[1:0]: Center-aligned Mode Selection
@{*/
#define TIM_CR1_CMS_EDGE		(0x0 << 5)
#define TIM_CR1_CMS_CENTER_1		(0x1 << 5)
#define TIM_CR1_CMS_CENTER_2		(0x2 << 5)
#define TIM_CR1_CMS_CENTER_3		(0x3 << 5)
#define TIM_CR1_CMS_MASK		(0x3 << 5)
/**@}*/

/* DIR: Direction */
/****************************************************************************/
/* tim_x_cr1_dir TIMx_CR1 DIR: Direction
*/
#define TIM_CR1_DIR_UP			(0 << 4)
#define TIM_CR1_DIR_DOWN		(1 << 4)
/**@}*/

/* OPM: One pulse mode */
#define TIM_CR1_OPM			(1 << 3)

/* URS: Update request source */
#define TIM_CR1_URS			(1 << 2)

/* UDIS: Update disable */
#define TIM_CR1_UDIS			(1 << 1)

/* CEN: Counter enable */
#define TIM_CR1_CEN			(1 << 0)

/* --- TIMx_CR2 values ----------------------------------------------------- */

/****************************************************************************/
/** @defgroup tim_x_cr2_ois TIMx_CR2_OIS: Force Output Idle State Control Values
@{*/
/* OIS4:*//** Output idle state 4 (OC4 output) */
#define TIM_CR2_OIS4			(1 << 14)

/* OIS3N:*//** Output idle state 3 (OC3N output) */
#define TIM_CR2_OIS3N			(1 << 13)

/* OIS3:*//** Output idle state 3 (OC3 output) */
#define TIM_CR2_OIS3			(1 << 12)

/* OIS2N:*//** Output idle state 2 (OC2N output) */
#define TIM_CR2_OIS2N			(1 << 11)

/* OIS2:*//** Output idle state 2 (OC2 output) */
#define TIM_CR2_OIS2			(1 << 10)

/* OIS1N:*//** Output idle state 1 (OC1N output) */
#define TIM_CR2_OIS1N			(1 << 9)

/* OIS1:*//** Output idle state 1 (OC1 output) */
#define TIM_CR2_OIS1			(1 << 8)
#define TIM_CR2_OIS_MASK		(0x7f << 8)
/**@}*/

/* TI1S: TI1 selection */
#define TIM_CR2_TI1S			(1 << 7)

/* MMS[2:0]: Master mode selection */
/****************************************************************************/
/** @defgroup tim_mastermode TIMx_CR2 MMS[6:4]: Master Mode Selection
@{*/
#define TIM_CR2_MMS_RESET		(0x0 << 4)
#define TIM_CR2_MMS_ENABLE		(0x1 << 4)
#define TIM_CR2_MMS_UPDATE		(0x2 << 4)
#define TIM_CR2_MMS_COMPARE_PULSE	(0x3 << 4)
#define TIM_CR2_MMS_COMPARE_OC1REF	(0x4 << 4)
#define TIM_CR2_MMS_COMPARE_OC2REF	(0x5 << 4)
#define TIM_CR2_MMS_COMPARE_OC3REF	(0x6 << 4)
#define TIM_CR2_MMS_COMPARE_OC4REF	(0x7 << 4)
#define TIM_CR2_MMS_MASK		(0x7 << 4)
/**@}*/

/* CCDS: Capture/compare DMA selection */
#define TIM_CR2_CCDS			(1 << 3)

/* CCUS: Capture/compare control update selection */
#define TIM_CR2_CCUS			(1 << 2)

/* CCPC: Capture/compare preload control */
#define TIM_CR2_CCPC			(1 << 0)

/* --- TIMx_SMCR values ---------------------------------------------------- */

/* ETP: External trigger polarity */
#define TIM_SMCR_ETP			(1 << 15)

/* ECE: External clock enable */
#define TIM_SMCR_ECE			(1 << 14)

/* ETPS[1:0]: External trigger prescaler */
#define TIM_SMCR_ETPS_OFF		(0x0 << 12)
#define TIM_SMCR_ETPS_ETRP_DIV_2	(0x1 << 12)
#define TIM_SMCR_ETPS_ETRP_DIV_4	(0x2 << 12)
#define TIM_SMCR_ETPS_ETRP_DIV_8	(0x3 << 12)
#define TIM_SMCR_ETPS_MASK		(0X3 << 12)

/* ETF[3:0]: External trigger filter */
#define TIM_SMCR_ETF_OFF		(0x0 << 8)
#define TIM_SMCR_ETF_CK_INT_N_2		(0x1 << 8)
#define TIM_SMCR_ETF_CK_INT_N_4		(0x2 << 8)
#define TIM_SMCR_ETF_CK_INT_N_8		(0x3 << 8)
#define TIM_SMCR_ETF_DTS_DIV_2_N_6	(0x4 << 8)
#define TIM_SMCR_ETF_DTS_DIV_2_N_8	(0x5 << 8)
#define TIM_SMCR_ETF_DTS_DIV_4_N_6	(0x6 << 8)
#define TIM_SMCR_ETF_DTS_DIV_4_N_8	(0x7 << 8)
#define TIM_SMCR_ETF_DTS_DIV_8_N_6	(0x8 << 8)
#define TIM_SMCR_ETF_DTS_DIV_8_N_8	(0x9 << 8)
#define TIM_SMCR_ETF_DTS_DIV_16_N_5	(0xA << 8)
#define TIM_SMCR_ETF_DTS_DIV_16_N_6	(0xB << 8)
#define TIM_SMCR_ETF_DTS_DIV_16_N_8	(0xC << 8)
#define TIM_SMCR_ETF_DTS_DIV_32_N_5	(0xD << 8)
#define TIM_SMCR_ETF_DTS_DIV_32_N_6	(0xE << 8)
#define TIM_SMCR_ETF_DTS_DIV_32_N_8	(0xF << 8)
#define TIM_SMCR_ETF_MASK		(0xF << 8)

/* MSM: Master/slave mode */
#define TIM_SMCR_MSM			(1 << 7)

/* TS[2:0]: Trigger selection */
/** @defgroup tim_ts TIMx_SMCR TS Trigger selection
@{*/
/** Internal Trigger 0 (ITR0) */
#define TIM_SMCR_TS_ITR0		(0x0 << 4)
/** Internal Trigger 1 (ITR1) */
#define TIM_SMCR_TS_ITR1		(0x1 << 4)
/** Internal Trigger 2 (ITR2) */
#define TIM_SMCR_TS_ITR2		(0x2 << 4)
/** Internal Trigger 3 (ITR3) */
#define TIM_SMCR_TS_ITR3		(0x3 << 4)
/** TI1 Edge Detector (TI1F_ED) */
#define TIM_SMCR_TS_TI1F_ED		(0x4 << 4)
/** Filtered Timer Input 1 (TI1FP1) */
#define TIM_SMCR_TS_TI1FP1		(0x5 << 4)
/** Filtered Timer Input 2 (TI2FP2) */
#define TIM_SMCR_TS_TI2FP2		(0x6 << 4)
/** External Trigger input (ETRF) */
#define TIM_SMCR_TS_ETRF		(0x7 << 4)
#define TIM_SMCR_TS_MASK		(0x7 << 4)
/**@}*/

/* SMS[2:0]: Slave mode selection */
/** @defgroup tim_sms TIMx_SMCR SMS Slave mode selection
@{*/
/** Slave mode disabled */
#define TIM_SMCR_SMS_OFF		(0x0 << 0)
/** Encoder mode 1 - Counter counts up/down on TI2FP2 edge depending on TI1FP1
level. */
#define TIM_SMCR_SMS_EM1		(0x1 << 0)
/** Encoder mode 2 - Counter counts up/down on TI1FP1 edge depending on TI2FP2
level. */
#define TIM_SMCR_SMS_EM2		(0x2 << 0)
/** Encoder mode 3 - Counter counts up/down on both TI1FP1 and TI2FP2 edges
depending on the level of the complementary input. */
#define TIM_SMCR_SMS_EM3		(0x3 << 0)
/** Reset Mode - Rising edge of the selected trigger input (TRGI) reinitializes
 * the counter and generates an update of the registers.
 */
#define TIM_SMCR_SMS_RM			(0x4 << 0)
/** Gated Mode - The counter clock is enabled when the trigger input (TRGI) is
 * high.
 */
#define TIM_SMCR_SMS_GM			(0x5 << 0)
/**  Trigger Mode - The counter starts at a rising edge of the trigger TRGI. */
#define TIM_SMCR_SMS_TM			(0x6 << 0)
/** External Clock Mode 1 - Rising edges of the selected trigger (TRGI) clock
 * the counter.
 */
#define TIM_SMCR_SMS_ECM1		(0x7 << 0)
#define TIM_SMCR_SMS_MASK		(0x7 << 0)
/**@}*/

/* --- TIMx_DIER values ---------------------------------------------------- */

/****************************************************************************/
/** @defgroup tim_irq_enable TIMx_DIER Timer DMA and Interrupt Enable Values
@{*/
/* TDE:*//** Trigger DMA request enable */
#define TIM_DIER_TDE			(1 << 14)

/* COMDE:*//** COM DMA request enable */
#define TIM_DIER_COMDE			(1 << 13)

/* CC4DE:*//** Capture/Compare 4 DMA request enable */
#define TIM_DIER_CC4DE			(1 << 12)

/* CC3DE:*//** Capture/Compare 3 DMA request enable */
#define TIM_DIER_CC3DE			(1 << 11)

/* CC2DE:*//** Capture/Compare 2 DMA request enable */
#define TIM_DIER_CC2DE			(1 << 10)

/* CC1DE:*//** Capture/Compare 1 DMA request enable */
#define TIM_DIER_CC1DE			(1 << 9)

/* UDE*//**: Update DMA request enable */
#define TIM_DIER_UDE			(1 << 8)

/* BIE:*//** Break interrupt enable */
#define TIM_DIER_BIE			(1 << 7)

/* TIE:*//** Trigger interrupt enable */
#define TIM_DIER_TIE			(1 << 6)

/* COMIE:*//** COM interrupt enable */
#define TIM_DIER_COMIE			(1 << 5)

/* CC4IE:*//** Capture/compare 4 interrupt enable */
#define TIM_DIER_CC4IE			(1 << 4)

/* CC3IE:*//** Capture/compare 3 interrupt enable */
#define TIM_DIER_CC3IE			(1 << 3)

/* CC2IE:*//** Capture/compare 2 interrupt enable */
#define TIM_DIER_CC2IE			(1 << 2)

/* CC1IE:*//** Capture/compare 1 interrupt enable */
#define TIM_DIER_CC1IE			(1 << 1)

/* UIE:*//** Update interrupt enable */
#define TIM_DIER_UIE			(1 << 0)
/**@}*/

/* --- TIMx_SR values ------------------------------------------------------ */
/****************************************************************************/
/** @defgroup tim_sr_values TIMx_SR Timer Status Register Flags
@{*/

/* CC4OF:*//** Capture/compare 4 overcapture flag */
#define TIM_SR_CC4OF			(1 << 12)

/* CC3OF:*//** Capture/compare 3 overcapture flag */
#define TIM_SR_CC3OF			(1 << 11)

/* CC2OF:*//** Capture/compare 2 overcapture flag */
#define TIM_SR_CC2OF			(1 << 10)

/* CC1OF:*//** Capture/compare 1 overcapture flag */
#define TIM_SR_CC1OF			(1 << 9)

/* BIF:*//** Break interrupt flag */
#define TIM_SR_BIF			(1 << 7)

/* TIF:*//** Trigger interrupt flag */
#define TIM_SR_TIF			(1 << 6)

/* COMIF:*//** COM interrupt flag */
#define TIM_SR_COMIF			(1 << 5)

/* CC4IF:*//** Capture/compare 4 interrupt flag */
#define TIM_SR_CC4IF			(1 << 4)

/* CC3IF:*//** Capture/compare 3 interrupt flag */
#define TIM_SR_CC3IF			(1 << 3)

/* CC2IF:*//** Capture/compare 2 interrupt flag */
#define TIM_SR_CC2IF			(1 << 2)

/* CC1IF:*//** Capture/compare 1 interrupt flag */
#define TIM_SR_CC1IF			(1 << 1)

/* UIF:*//** Update interrupt flag */
#define TIM_SR_UIF			(1 << 0)
/**@}*/

/* --- TIMx_EGR values ----------------------------------------------------- */

/****************************************************************************/
/** @defgroup tim_event_gen TIMx_EGR Timer Event Generator Values
@{*/

/* BG:*//** Break generation */
#define TIM_EGR_BG			(1 << 7)

/* TG:*//** Trigger generation */
#define TIM_EGR_TG			(1 << 6)

/* COMG:*//** Capture/compare control update generation */
#define TIM_EGR_COMG			(1 << 5)

/* CC4G:*//** Capture/compare 4 generation */
#define TIM_EGR_CC4G			(1 << 4)

/* CC3G:*//** Capture/compare 3 generation */
#define TIM_EGR_CC3G			(1 << 3)

/* CC2G:*//** Capture/compare 2 generation */
#define TIM_EGR_CC2G			(1 << 2)

/* CC1G:*//** Capture/compare 1 generation */
#define TIM_EGR_CC1G			(1 << 1)

/* UG:*//** Update generation */
#define TIM_EGR_UG			(1 << 0)
/**@}*/

/* --- TIMx_CCMR1 values --------------------------------------------------- */

/* --- Output compare mode --- */

/* OC2CE: Output compare 2 clear enable */
#define TIM_CCMR1_OC2CE			(1 << 15)

/* OC2M[2:0]: Output compare 2 mode */
#define TIM_CCMR1_OC2M_FROZEN		(0x0 << 12)
#define TIM_CCMR1_OC2M_ACTIVE		(0x1 << 12)
#define TIM_CCMR1_OC2M_INACTIVE		(0x2 << 12)
#define TIM_CCMR1_OC2M_TOGGLE		(0x3 << 12)
#define TIM_CCMR1_OC2M_FORCE_LOW	(0x4 << 12)
#define TIM_CCMR1_OC2M_FORCE_HIGH	(0x5 << 12)
#define TIM_CCMR1_OC2M_PWM1		(0x6 << 12)
#define TIM_CCMR1_OC2M_PWM2		(0x7 << 12)
#define TIM_CCMR1_OC2M_MASK		(0x7 << 12)

/* OC2PE: Output compare 2 preload enable */
#define TIM_CCMR1_OC2PE			(1 << 11)

/* OC2FE: Output compare 2 fast enable */
#define TIM_CCMR1_OC2FE			(1 << 10)

/* CC2S[1:0]: Capture/compare 2 selection */
/* Note: CC2S bits are writable only when the channel is OFF (CC2E = 0 in
 * TIMx_CCER). */
#define TIM_CCMR1_CC2S_OUT		(0x0 << 8)
#define TIM_CCMR1_CC2S_IN_TI2		(0x1 << 8)
#define TIM_CCMR1_CC2S_IN_TI1		(0x2 << 8)
#define TIM_CCMR1_CC2S_IN_TRC		(0x3 << 8)
#define TIM_CCMR1_CC2S_MASK		(0x3 << 8)

/* OC1CE: Output compare 1 clear enable */
#define TIM_CCMR1_OC1CE                 (1 << 7)

/* OC1M[2:0]: Output compare 1 mode */
#define TIM_CCMR1_OC1M_FROZEN		(0x0 << 4)
#define TIM_CCMR1_OC1M_ACTIVE		(0x1 << 4)
#define TIM_CCMR1_OC1M_INACTIVE		(0x2 << 4)
#define TIM_CCMR1_OC1M_TOGGLE		(0x3 << 4)
#define TIM_CCMR1_OC1M_FORCE_LOW	(0x4 << 4)
#define TIM_CCMR1_OC1M_FORCE_HIGH	(0x5 << 4)
#define TIM_CCMR1_OC1M_PWM1		(0x6 << 4)
#define TIM_CCMR1_OC1M_PWM2		(0x7 << 4)
#define TIM_CCMR1_OC1M_MASK		(0x7 << 4)

/* OC1PE: Output compare 1 preload enable */
#define TIM_CCMR1_OC1PE			(1 << 3)

/* OC1FE: Output compare 1 fast enable */
#define TIM_CCMR1_OC1FE			(1 << 2)

/* CC1S[1:0]: Capture/compare 1 selection */
/* Note: CC2S bits are writable only when the channel is OFF (CC2E = 0 in
 * TIMx_CCER). */
#define TIM_CCMR1_CC1S_OUT		(0x0 << 0)
#define TIM_CCMR1_CC1S_IN_TI2		(0x2 << 0)
#define TIM_CCMR1_CC1S_IN_TI1		(0x1 << 0)
#define TIM_CCMR1_CC1S_IN_TRC		(0x3 << 0)
#define TIM_CCMR1_CC1S_MASK		(0x3 << 0)

/* --- Input capture mode --- */

/* IC2F[3:0]: Input capture 2 filter */
#define TIM_CCMR1_IC2F_OFF		(0x0 << 12)
#define TIM_CCMR1_IC2F_CK_INT_N_2	(0x1 << 12)
#define TIM_CCMR1_IC2F_CK_INT_N_4	(0x2 << 12)
#define TIM_CCMR1_IC2F_CK_INT_N_8	(0x3 << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_2_N_6	(0x4 << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_2_N_8	(0x5 << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_4_N_6	(0x6 << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_4_N_8	(0x7 << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_8_N_6	(0x8 << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_8_N_8	(0x9 << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_16_N_5	(0xA << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_16_N_6	(0xB << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_16_N_8	(0xC << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_32_N_5	(0xD << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_32_N_6	(0xE << 12)
#define TIM_CCMR1_IC2F_DTF_DIV_32_N_8	(0xF << 12)
#define TIM_CCMR1_IC2F_MASK		(0xF << 12)

/* IC2PSC[1:0]: Input capture 2 prescaler */
#define TIM_CCMR1_IC2PSC_OFF		(0x0 << 10)
#define TIM_CCMR1_IC2PSC_2		(0x1 << 10)
#define TIM_CCMR1_IC2PSC_4		(0x2 << 10)
#define TIM_CCMR1_IC2PSC_8		(0x3 << 10)
#define TIM_CCMR1_IC2PSC_MASK		(0x3 << 10)

/* IC1F[3:0]: Input capture 1 filter */
#define TIM_CCMR1_IC1F_OFF		(0x0 << 4)
#define TIM_CCMR1_IC1F_CK_INT_N_2	(0x1 << 4)
#define TIM_CCMR1_IC1F_CK_INT_N_4	(0x2 << 4)
#define TIM_CCMR1_IC1F_CK_INT_N_8	(0x3 << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_2_N_6	(0x4 << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_2_N_8	(0x5 << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_4_N_6	(0x6 << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_4_N_8	(0x7 << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_8_N_6	(0x8 << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_8_N_8	(0x9 << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_16_N_5	(0xA << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_16_N_6	(0xB << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_16_N_8	(0xC << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_32_N_5	(0xD << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_32_N_6	(0xE << 4)
#define TIM_CCMR1_IC1F_DTF_DIV_32_N_8	(0xF << 4)
#define TIM_CCMR1_IC1F_MASK		(0xF << 4)

/* IC1PSC[1:0]: Input capture 1 prescaler */
#define TIM_CCMR1_IC1PSC_OFF		(0x0 << 2)
#define TIM_CCMR1_IC1PSC_2		(0x1 << 2)
#define TIM_CCMR1_IC1PSC_4		(0x2 << 2)
#define TIM_CCMR1_IC1PSC_8		(0x3 << 2)
#define TIM_CCMR1_IC1PSC_MASK		(0x3 << 2)

/* --- TIMx_CCMR2 values --------------------------------------------------- */

/* --- Output compare mode --- */

/* OC4CE: Output compare 4 clear enable */
#define TIM_CCMR2_OC4CE			(1 << 15)

/* OC4M[2:0]: Output compare 4 mode */
#define TIM_CCMR2_OC4M_FROZEN		(0x0 << 12)
#define TIM_CCMR2_OC4M_ACTIVE		(0x1 << 12)
#define TIM_CCMR2_OC4M_INACTIVE		(0x2 << 12)
#define TIM_CCMR2_OC4M_TOGGLE		(0x3 << 12)
#define TIM_CCMR2_OC4M_FORCE_LOW	(0x4 << 12)
#define TIM_CCMR2_OC4M_FORCE_HIGH	(0x5 << 12)
#define TIM_CCMR2_OC4M_PWM1		(0x6 << 12)
#define TIM_CCMR2_OC4M_PWM2		(0x7 << 12)
#define TIM_CCMR2_OC4M_MASK		(0x7 << 12)

/* OC4PE: Output compare 4 preload enable */
#define TIM_CCMR2_OC4PE			(1 << 11)

/* OC4FE: Output compare 4 fast enable */
#define TIM_CCMR2_OC4FE			(1 << 10)

/* CC4S[1:0]: Capture/compare 4 selection */
/* Note: CC2S bits are writable only when the channel is OFF (CC2E = 0 in
 * TIMx_CCER). */
#define TIM_CCMR2_CC4S_OUT		(0x0 << 8)
#define TIM_CCMR2_CC4S_IN_TI4		(0x1 << 8)
#define TIM_CCMR2_CC4S_IN_TI3		(0x2 << 8)
#define TIM_CCMR2_CC4S_IN_TRC		(0x3 << 8)
#define TIM_CCMR2_CC4S_MASK		(0x3 << 8)

/* OC3CE: Output compare 3 clear enable */
#define TIM_CCMR2_OC3CE			(1 << 7)

/* OC3M[2:0]: Output compare 3 mode */
#define TIM_CCMR2_OC3M_FROZEN		(0x0 << 4)
#define TIM_CCMR2_OC3M_ACTIVE		(0x1 << 4)
#define TIM_CCMR2_OC3M_INACTIVE		(0x2 << 4)
#define TIM_CCMR2_OC3M_TOGGLE		(0x3 << 4)
#define TIM_CCMR2_OC3M_FORCE_LOW	(0x4 << 4)
#define TIM_CCMR2_OC3M_FORCE_HIGH	(0x5 << 4)
#define TIM_CCMR2_OC3M_PWM1		(0x6 << 4)
#define TIM_CCMR2_OC3M_PWM2		(0x7 << 4)
#define TIM_CCMR2_OC3M_MASK		(0x7 << 4)

/* OC3PE: Output compare 3 preload enable */
#define TIM_CCMR2_OC3PE			(1 << 3)

/* OC3FE: Output compare 3 fast enable */
#define TIM_CCMR2_OC3FE			(1 << 2)

/* CC3S[1:0]: Capture/compare 3 selection */
/* Note: CC2S bits are writable only when the channel is OFF (CC2E = 0 in
 * TIMx_CCER). */
#define TIM_CCMR2_CC3S_OUT		(0x0 << 0)
#define TIM_CCMR2_CC3S_IN_TI3		(0x1 << 0)
#define TIM_CCMR2_CC3S_IN_TI4		(0x2 << 0)
#define TIM_CCMR2_CC3S_IN_TRC		(0x3 << 0)
#define TIM_CCMR2_CC3S_MASK		(0x3 << 0)

/* --- Input capture mode --- */

/* IC4F[3:0]: Input capture 4 filter */
#define TIM_CCMR2_IC4F_OFF		(0x0 << 12)
#define TIM_CCMR2_IC4F_CK_INT_N_2	(0x1 << 12)
#define TIM_CCMR2_IC4F_CK_INT_N_4	(0x2 << 12)
#define TIM_CCMR2_IC4F_CK_INT_N_8	(0x3 << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_2_N_6	(0x4 << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_2_N_8	(0x5 << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_4_N_6	(0x6 << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_4_N_8	(0x7 << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_8_N_6	(0x8 << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_8_N_8	(0x9 << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_16_N_5	(0xA << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_16_N_6	(0xB << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_16_N_8	(0xC << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_32_N_5	(0xD << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_32_N_6	(0xE << 12)
#define TIM_CCMR2_IC4F_DTF_DIV_32_N_8	(0xF << 12)
#define TIM_CCMR2_IC4F_MASK		(0xF << 12)

/* IC4PSC[1:0]: Input capture 4 prescaler */
#define TIM_CCMR2_IC4PSC_OFF		(0x0 << 10)
#define TIM_CCMR2_IC4PSC_2		(0x1 << 10)
#define TIM_CCMR2_IC4PSC_4		(0x2 << 10)
#define TIM_CCMR2_IC4PSC_8		(0x3 << 10)
#define TIM_CCMR2_IC4PSC_MASK		(0x3 << 10)

/* IC3F[3:0]: Input capture 3 filter */
#define TIM_CCMR2_IC3F_OFF		(0x0 << 4)
#define TIM_CCMR2_IC3F_CK_INT_N_2	(0x1 << 4)
#define TIM_CCMR2_IC3F_CK_INT_N_4	(0x2 << 4)
#define TIM_CCMR2_IC3F_CK_INT_N_8	(0x3 << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_2_N_6	(0x4 << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_2_N_8	(0x5 << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_4_N_6	(0x6 << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_4_N_8	(0x7 << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_8_N_6	(0x8 << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_8_N_8	(0x9 << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_16_N_5	(0xA << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_16_N_6	(0xB << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_16_N_8	(0xC << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_32_N_5	(0xD << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_32_N_6	(0xE << 4)
#define TIM_CCMR2_IC3F_DTF_DIV_32_N_8	(0xF << 4)
#define TIM_CCMR2_IC3F_MASK		(0xF << 4)

/* IC3PSC[1:0]: Input capture 3 prescaler */
#define TIM_CCMR2_IC3PSC_OFF		(0x0 << 2)
#define TIM_CCMR2_IC3PSC_2		(0x1 << 2)
#define TIM_CCMR2_IC3PSC_4		(0x2 << 2)
#define TIM_CCMR2_IC3PSC_8		(0x3 << 2)
#define TIM_CCMR2_IC3PSC_MASK		(0x3 << 2)

/* --- TIMx_CCER values ---------------------------------------------------- */

/* CC4NP: Capture/compare 4 complementary output polarity */
#define TIM_CCER_CC4NP			(1 << 15)

/* CC4P: Capture/compare 4 output polarity */
#define TIM_CCER_CC4P			(1 << 13)

/* CC4E: Capture/compare 4 output enable */
#define TIM_CCER_CC4E			(1 << 12)

/* CC3NP: Capture/compare 3 complementary output polarity */
#define TIM_CCER_CC3NP			(1 << 11)

/* CC3NE: Capture/compare 3 complementary output enable */
#define TIM_CCER_CC3NE			(1 << 10)

/* CC3P: Capture/compare 3 output polarity */
#define TIM_CCER_CC3P			(1 << 9)

/* CC3E: Capture/compare 3 output enable */
#define TIM_CCER_CC3E			(1 << 8)

/* CC2NP: Capture/compare 2 complementary output polarity */
#define TIM_CCER_CC2NP			(1 << 7)

/* CC2NE: Capture/compare 2 complementary output enable */
#define TIM_CCER_CC2NE			(1 << 6)

/* CC2P: Capture/compare 2 output polarity */
#define TIM_CCER_CC2P			(1 << 5)

/* CC2E: Capture/compare 2 output enable */
#define TIM_CCER_CC2E			(1 << 4)

/* CC1NP: Capture/compare 1 complementary output polarity */
#define TIM_CCER_CC1NP			(1 << 3)

/* CC1NE: Capture/compare 1 complementary output enable */
#define TIM_CCER_CC1NE			(1 << 2)

/* CC1P: Capture/compare 1 output polarity */
#define TIM_CCER_CC1P			(1 << 1)

/* CC1E: Capture/compare 1 output enable */
#define TIM_CCER_CC1E			(1 << 0)

/* --- TIMx_CNT values ----------------------------------------------------- */

/* CNT[15:0]: Counter value */

/* --- TIMx_PSC values ----------------------------------------------------- */

/* PSC[15:0]: Prescaler value */

/* --- TIMx_ARR values ----------------------------------------------------- */

/* ARR[15:0]: Prescaler value */

/* --- TIMx_RCR values ----------------------------------------------------- */

/* REP[15:0]: Repetition counter value */

/* --- TIMx_CCR1 values ---------------------------------------------------- */

/* CCR1[15:0]: Capture/compare 1 value */

/* --- TIMx_CCR2 values ---------------------------------------------------- */

/* CCR2[15:0]: Capture/compare 2 value */

/* --- TIMx_CCR3 values ---------------------------------------------------- */

/* CCR3[15:0]: Capture/compare 3 value */

/* --- TIMx_CCR4 values ---------------------------------------------------- */

/* CCR4[15:0]: Capture/compare 4 value */

/* --- TIMx_BDTR values ---------------------------------------------------- */

/* MOE: Main output enable */
#define TIM_BDTR_MOE			(1 << 15)

/* AOE: Automatic output enable */
#define TIM_BDTR_AOE			(1 << 14)

/* BKP: Break polarity */
#define TIM_BDTR_BKP			(1 << 13)

/* BKE: Break enable */
#define TIM_BDTR_BKE			(1 << 12)

/* OSSR: Off-state selection of run mode */
#define TIM_BDTR_OSSR			(1 << 11)

/* OSSI: Off-state selection of idle mode */
#define TIM_BDTR_OSSI			(1 << 10)

/* LOCK[1:0]: Lock configuration */
/****************************************************************************/
/** @defgroup tim_lock TIM_BDTR_LOCK Timer Lock Values
@{*/
#define TIM_BDTR_LOCK_OFF		(0x0 << 8)
#define TIM_BDTR_LOCK_LEVEL_1		(0x1 << 8)
#define TIM_BDTR_LOCK_LEVEL_2		(0x2 << 8)
#define TIM_BDTR_LOCK_LEVEL_3		(0x3 << 8)
#define TIM_BDTR_LOCK_MASK		(0x3 << 8)
/**@}*/

/* DTG[7:0]: Dead-time generator set-up */
#define TIM_BDTR_DTG_MASK		0x00FF

/* --- TIMx_DCR values ----------------------------------------------------- */

/* DBL[4:0]: DMA burst length */
#define TIM_BDTR_DBL_MASK		(0x1F << 8)

/* DBA[4:0]: DMA base address */
#define TIM_BDTR_DBA_MASK		(0x1F << 0)

/* --- TIMx_DMAR values ---------------------------------------------------- */

/* DMAB[15:0]: DMA register for burst accesses */

/* --- TIMx convenience defines -------------------------------------------- */

/** Output Compare channel designators */
enum tim_oc_id {
	TIM_OC1 = 0,
	TIM_OC1N,
	TIM_OC2,
	TIM_OC2N,
	TIM_OC3,
	TIM_OC3N,
	TIM_OC4,
};

/** Output Compare mode designators */
enum tim_oc_mode {
	TIM_OCM_FROZEN,
	TIM_OCM_ACTIVE,
	TIM_OCM_INACTIVE,
	TIM_OCM_TOGGLE,
	TIM_OCM_FORCE_LOW,
	TIM_OCM_FORCE_HIGH,
	TIM_OCM_PWM1,
	TIM_OCM_PWM2,
};

/** Input Capture channel designators */
enum tim_ic_id {
	TIM_IC1,
	TIM_IC2,
	TIM_IC3,
	TIM_IC4,
};

/** Input Capture input filter. The frequency used to sample the
input and the number of events needed to validate an output transition.

TIM_IC_CK_INT_N_x No division from the Deadtime and Sampling Clock frequency
(DTF), filter length x
TIM_IC_DTF_DIV_y_N_x Division by y from the DTF, filter length x
 */
enum tim_ic_filter {
	TIM_IC_OFF,
	TIM_IC_CK_INT_N_2,
	TIM_IC_CK_INT_N_4,
	TIM_IC_CK_INT_N_8,
	TIM_IC_DTF_DIV_2_N_6,
	TIM_IC_DTF_DIV_2_N_8,
	TIM_IC_DTF_DIV_4_N_6,
	TIM_IC_DTF_DIV_4_N_8,
	TIM_IC_DTF_DIV_8_N_6,
	TIM_IC_DTF_DIV_8_N_8,
	TIM_IC_DTF_DIV_16_N_5,
	TIM_IC_DTF_DIV_16_N_6,
	TIM_IC_DTF_DIV_16_N_8,
	TIM_IC_DTF_DIV_32_N_5,
	TIM_IC_DTF_DIV_32_N_6,
	TIM_IC_DTF_DIV_32_N_8,
};

/** Input Capture input prescaler.

TIM_IC_PSC_x Input capture is done every x events*/
enum tim_ic_psc {
	TIM_IC_PSC_OFF,
	TIM_IC_PSC_2,
	TIM_IC_PSC_4,
	TIM_IC_PSC_8,
};

/** Input Capture input source.

The direction of the channel (input/output) as well as the input used.
 */
enum tim_ic_input {
	TIM_IC_OUT = 0,
	TIM_IC_IN_TI1 = 1,
	TIM_IC_IN_TI2 = 2,
	TIM_IC_IN_TRC = 3,
	TIM_IC_IN_TI3 = 5,
	TIM_IC_IN_TI4 = 6,
};

/** Slave external trigger polarity */
enum tim_et_pol {
	TIM_ET_RISING,
	TIM_ET_FALLING,
};

/** External clock mode 2 */
enum tim_ecm2_state {
    TIM_ECM2_DISABLED,
    TIM_ECM2_ENABLED,
};

/** Input Capture input polarity */
enum tim_ic_pol {
	TIM_IC_RISING,
	TIM_IC_FALLING,
	TIM_IC_BOTH,
};


#endif // TIMER_REG_H
