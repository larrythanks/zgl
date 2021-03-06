/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2015 Guangzhou ZHIYUAN Electronics Stock Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
* e-mail:      ametal.support@zlg.cn
*******************************************************************************/

/**
 * \file
 * \brief LPC84X IOCON (IO????) Ӳ??????ʵ??
 * 
 * \internal
 * \par Modification History
 * - 1.01 15-11-24  mem, modified.
 * - 1.00 15-07-29  zxl, first implementation.
 * \endinternal
 */

#include "ametal.h"
#include "hw/amhw_lpc82x_iocon.h"

/**
 * \brief LPC82x IOCON[56] ?Ĵ?????????PIO0_m????˳??
 */
typedef enum amhw_lpc84x_iocon_pio {
    AMHW_LPC84X_IOCON_PIO0_17 = 0,
    AMHW_LPC84X_IOCON_PIO0_13,
    AMHW_LPC84X_IOCON_PIO0_12,
    AMHW_LPC84X_IOCON_PIO0_5,
    AMHW_LPC84X_IOCON_PIO0_4,
    AMHW_LPC84X_IOCON_PIO0_3,
    AMHW_LPC84X_IOCON_PIO0_2,
    AMHW_LPC84X_IOCON_PIO0_11,
    AMHW_LPC84X_IOCON_PIO0_10,
    AMHW_LPC84X_IOCON_PIO0_16,
    AMHW_LPC84X_IOCON_PIO0_15,
    AMHW_LPC84X_IOCON_PIO0_1,
    RESERVED0,
    AMHW_LPC84X_IOCON_PIO0_9,
    AMHW_LPC84X_IOCON_PIO0_8,
    AMHW_LPC84X_IOCON_PIO0_7,
    AMHW_LPC84X_IOCON_PIO0_6,
    AMHW_LPC84X_IOCON_PIO0_0,
    AMHW_LPC84X_IOCON_PIO0_14,
    RESERVED1,
    AMHW_LPC84X_IOCON_PIO0_28,
    AMHW_LPC84X_IOCON_PIO0_27,
    AMHW_LPC84X_IOCON_PIO0_26,
    AMHW_LPC84X_IOCON_PIO0_25,
    AMHW_LPC84X_IOCON_PIO0_24,
    AMHW_LPC84X_IOCON_PIO0_23,
    AMHW_LPC84X_IOCON_PIO0_22,
    AMHW_LPC84X_IOCON_PIO0_21,
    AMHW_LPC84X_IOCON_PIO0_20,
    AMHW_LPC84X_IOCON_PIO0_19,
    AMHW_LPC84X_IOCON_PIO0_18,
	AMHW_LPC84X_IOCON_PIO1_8,
	AMHW_LPC84X_IOCON_PIO1_9,
	AMHW_LPC84X_IOCON_PIO1_12,
	AMHW_LPC84X_IOCON_PIO1_13,
	AMHW_LPC84X_IOCON_PIO0_31,
	AMHW_LPC84X_IOCON_PIO1_0,
	AMHW_LPC84X_IOCON_PIO1_1,
	AMHW_LPC84X_IOCON_PIO1_2,
	AMHW_LPC84X_IOCON_PIO1_14,
	AMHW_LPC84X_IOCON_PIO1_15,
	AMHW_LPC84X_IOCON_PIO1_3,
	AMHW_LPC84X_IOCON_PIO1_4,
	AMHW_LPC84X_IOCON_PIO1_5,
	AMHW_LPC84X_IOCON_PIO1_16,
	AMHW_LPC84X_IOCON_PIO1_17,
	AMHW_LPC84X_IOCON_PIO1_6,
	AMHW_LPC84X_IOCON_PIO1_18,
	AMHW_LPC84X_IOCON_PIO1_19,
	AMHW_LPC84X_IOCON_PIO1_7,
	AMHW_LPC84X_IOCON_PIO0_29,
	AMHW_LPC84X_IOCON_PIO0_30,
	AMHW_LPC84X_IOCON_PIO1_20,
	AMHW_LPC84X_IOCON_PIO1_21,
	AMHW_LPC84X_IOCON_PIO1_11,
	AMHW_LPC84X_IOCON_PIO1_10
} amhw_lpc82x_iocon_pio_t;

/**
 * \brief LPC82x (PIO0_0~PIO0_28) ???????üĴ???ƫ?Ʊ?
 *
 *        offset = amhw_lpc82x_iocon_offset_pin[PIO_15] : PIO_15???żĴ???ƫ??
 *        pio[offset]                                   : ????PIO_15?ļĴ???
 */
const uint8_t amhw_lpc84x_iocon_offset_pin[] = {
    AMHW_LPC84X_IOCON_PIO0_0,
    AMHW_LPC84X_IOCON_PIO0_1,
    AMHW_LPC84X_IOCON_PIO0_2,
    AMHW_LPC84X_IOCON_PIO0_3,
    AMHW_LPC84X_IOCON_PIO0_4,
    AMHW_LPC84X_IOCON_PIO0_5,
    AMHW_LPC84X_IOCON_PIO0_6,
    AMHW_LPC84X_IOCON_PIO0_7,
    AMHW_LPC84X_IOCON_PIO0_8,
    AMHW_LPC84X_IOCON_PIO0_9,
    AMHW_LPC84X_IOCON_PIO0_10,
    AMHW_LPC84X_IOCON_PIO0_11,
    AMHW_LPC84X_IOCON_PIO0_12,
    AMHW_LPC84X_IOCON_PIO0_13,
    AMHW_LPC84X_IOCON_PIO0_14,
    AMHW_LPC84X_IOCON_PIO0_15,
    AMHW_LPC84X_IOCON_PIO0_16,
    AMHW_LPC84X_IOCON_PIO0_17,
    AMHW_LPC84X_IOCON_PIO0_18,
    AMHW_LPC84X_IOCON_PIO0_19,
    AMHW_LPC84X_IOCON_PIO0_20,
    AMHW_LPC84X_IOCON_PIO0_21,
    AMHW_LPC84X_IOCON_PIO0_22,
    AMHW_LPC84X_IOCON_PIO0_23,
    AMHW_LPC84X_IOCON_PIO0_24,
    AMHW_LPC84X_IOCON_PIO0_25,
    AMHW_LPC84X_IOCON_PIO0_26,
    AMHW_LPC84X_IOCON_PIO0_27,
    AMHW_LPC84X_IOCON_PIO0_28,
	AMHW_LPC84X_IOCON_PIO0_29,
	AMHW_LPC84X_IOCON_PIO0_30,
	AMHW_LPC84X_IOCON_PIO0_31,
	AMHW_LPC84X_IOCON_PIO1_0,
	AMHW_LPC84X_IOCON_PIO1_1,
	AMHW_LPC84X_IOCON_PIO1_2,
	AMHW_LPC84X_IOCON_PIO1_3,
	AMHW_LPC84X_IOCON_PIO1_4,
	AMHW_LPC84X_IOCON_PIO1_5,
	AMHW_LPC84X_IOCON_PIO1_6,
	AMHW_LPC84X_IOCON_PIO1_7,
	AMHW_LPC84X_IOCON_PIO1_8,
	AMHW_LPC84X_IOCON_PIO1_9,
	AMHW_LPC84X_IOCON_PIO1_10,
	AMHW_LPC84X_IOCON_PIO1_11,
	AMHW_LPC84X_IOCON_PIO1_12,
	AMHW_LPC84X_IOCON_PIO1_13,
	AMHW_LPC84X_IOCON_PIO1_14,
	AMHW_LPC84X_IOCON_PIO1_15,
	AMHW_LPC84X_IOCON_PIO1_16,
	AMHW_LPC84X_IOCON_PIO1_17,
	AMHW_LPC84X_IOCON_PIO1_18,
	AMHW_LPC84X_IOCON_PIO1_19,
	AMHW_LPC84X_IOCON_PIO1_20,
	AMHW_LPC84X_IOCON_PIO1_21,
};

/* end of file */
