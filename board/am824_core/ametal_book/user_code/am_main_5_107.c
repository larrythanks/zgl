/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief 程序清单5.107
 *
 * \note 该历程需要用到miniport拓展板,可以用LED看效果
 * 
 * \internal
 * \par Modification history
 * - 1.00 18-09-17  adw, first implementation
 * \endinternal
 */
#include "ametal.h"
#include "am_lpc82x_inst_init.h"
#include "am_uart.h "
#include "am_vdebug.h"
static int __uart_rxchar_put (void *p_arg, char ch)
{
    // 将接收的数据ch保存下来?
    return AM_OK;
}

int am_main (void)
{
    am_uart_handle_t uart_handle = am_lpc82x_usart0_inst_init();
    am_uart_callback_set(
        uart_handle, AM_UART_CALLBACK_RXCHAR_PUT, __uart_rxchar_put, NULL);
    while(1) {
    }
}



/* end of file */

