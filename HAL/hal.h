/**
 * @file hal.h
 * @author Zheng Yu (user_zheng_yu@163.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#ifndef __HAL_H__
#define __HAL_H__

#include "halComType.h"
#include "halComCfg.h"

HAL_ComReturnType HAL_Init(const HAL_ConfigType *pConfig);

HAL_ComReturnType HAL_DeInit(void);

HAL_ComReturnType HAL_Control(uint8_t module, uint32_t command, void *args);

HAL_ComReturnType HAL_RegisterNotifycation(uint8_t module, HAL_ComCallBack CallBack);

void HAL_MainFunction(void);

#endif /* __HAL_H__ */

#ifdef __cplusplus
}
#endif /* __cplusplus */
