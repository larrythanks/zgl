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
 * \brief book`s view_zigbee driver for AM824
 *
 * \internal
 * \par Modification history
 * - 1.00 18-09-26  ipk, first implementation
 * \endinternal
 */
#ifndef __VIEW_ZIGBEE_H__
#define __VIEW_ZIGBEE_H__

#include "ametal.h"
#include "mvc.h"
#include "model_bool.h"
#include "am_zm516x.h"

//????zigbee??ͼ??
typedef struct _view_zigbee{
    observer_t         isa;
    am_zm516x_handle_t zm516x_handle;
}view_zigbee_t;


int view_zigbee_init (view_zigbee_t *p_view_zigbee,am_zm516x_handle_t  zm516x_handle);

#endif /* __VIEW_ZIGBEE_H__ */
/* end of file */
