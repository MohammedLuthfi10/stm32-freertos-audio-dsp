/**
 * @file      timer.h
 * @brief     Public API for the portable Timer driver.
 * @author    Your Name
 * @date      2023-10-27
 *
 * @details   This file defines the user-facing functions for configuring and
 *            controlling a general-purpose timer for periodic tasks.
 */

#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* --- Opaque Handle Definition --- */

/**
 * @brief Opaque handle representing a configured Timer instance.
 */
typedef struct timer_handle_t* timer_handle_t;

/* --- Public Configuration Types --- */

/**
 * @brief Configuration structure for Timer initialization.
 * @details This configures the timer as a basic up-counting periodic timer.
 *          The timer frequency will be (peripheral_clock / (prescaler + 1)).
 *          The update event (interrupt) frequency will be (timer_frequency / (period + 1)).
 */
/* 1. Base Configuration (Used by ALL timers) */
typedef struct {
    uint32_t Prescaler;       // Sets TIMx_PSC
    uint32_t CounterMode;     // Up, Down, Center-Aligned (TIMx_CR1: DIR, CMS)
    uint32_t Period;          // Sets TIMx_ARR (the "top" value)
    uint32_t ClockDivision;   // Sets TIMx_CR1: CKD
    uint32_t RepetitionCounter; // Sets TIMx_RCR (Advanced Timers ONLY)
    uint32_t AutoReloadPreload; // Enable/Disable (TIMx_CR1: ARPE)
} TIM_Base_Init_t;

/* 2. Output Compare / PWM Channel Configuration (GP & Advanced) */
typedef struct {
    uint32_t OCMode;          // PWM1, PWM2, etc. (TIMx_CCMRx: OCxM)
    uint32_t Pulse;           // Sets TIMx_CCRx (the "compare" value)
    uint32_t OCPolarity;      // Active High/Low (TIMx_CCER: CCxP)
    uint32_t OCNPolarity;     // Complementary Polarity (Advanced ONLY)
    uint32_t OCIdleState;     // (Advanced ONLY)
    uint32_t OCNIdleState;    // (Advanced ONLY)
} TIM_OC_Init_t;

/* 3. Input Capture Channel Configuration (GP & Advanced) */
typedef struct {
    uint32_t ICPolarity;      // Rising, Falling, Both (TIMx_CCER: CCxP, CCxNP)
    uint32_t ICSelection;     // Direct, Indirect (TIMx_CCMRx: CCxS)
    uint32_t ICPrescaler;     // (TIMx_CCMRx: ICxPSC)
    uint32_t ICFilter;        // 0-15 (TIMx_CCMRx: ICxF)
} TIM_IC_Init_t;

/* --- Public API Functions --- */

/**
 * @brief Initializes and configures a general-purpose timer.
 *
 * @param[in] instance_num The hardware instance number (e.g., 2 for TIM2).
 * @param[in] config Pointer to the configuration structure for the timer.
 *
 * @return A handle to the configured timer, or NULL on failure.
 */
timer_handle_t timer_init(uint8_t instance_num, const timer_config_t* config);

/**
 * @brief De-initializes a timer instance.
 *
 * @param[in,out] p_handle Pointer to the handle to de-initialize.
 */
void timer_deinit(timer_handle_t* p_handle);

/**
 * @brief Starts the timer counter.
 * @param[in] handle The handle to the timer instance.
 */
void timer_start(timer_handle_t handle);

/**
 * @brief Stops the timer counter.
 * @param[in] handle The handle to the timer instance.
 */
void timer_stop(timer_handle_t handle);

/**
 * @brief Gets the current value of the timer's counter.
 * @param[in] handle The handle to the timer instance.
 * @return The current 16-bit or 32-bit counter value.
 */
uint32_t timer_get_counter(timer_handle_t handle);

/**
 * @brief Enables the update interrupt for the timer.
 * @details The update interrupt is typically generated on counter overflow.
 * @param[in] handle The handle to the timer instance.
 */
void timer_enable_update_interrupt(timer_handle_t handle);

/**
 * @brief Disables the update interrupt for the timer.
 * @param[in] handle The handle to the timer instance.
 */
void timer_disable_update_interrupt(timer_handle_t handle);

/**
 * @brief Clears the update interrupt flag.
 * @details This function should be called inside the timer's interrupt service
 *          routine (ISR) to clear the hardware flag.
 * @param[in] handle The handle to the timer instance.
 * @return true if the update flag was set before clearing, false otherwise.
 */
bool timer_is_update_interrupt_flag_set(timer_handle_t handle);

/**
 * @brief Clears the update interrupt flag.
 * @param[in] handle The handle to the timer instance.
 */
void timer_clear_update_interrupt_flag(timer_handle_t handle);

#endif // TIMER_H
