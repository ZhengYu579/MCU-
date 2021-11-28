/**
 * @file hal_dio.h
 * @author Zheng Yu (user_zheng_yu@163.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __HAL_DIO_H__
#define __HAL_DIO_H__

#include "halComType.h"
#include "halComCfg.h"

#ifdef HAL_Module_DIO

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

HAL_ComReturnType HAL_DIO_Init(void);

HAL_ComReturnType HAL_DIO_DeInit(void);

void HAL_DIO_MainFunction(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* HAL_Module_DIO */

#endif /* __HAL_DIO_H__ */
