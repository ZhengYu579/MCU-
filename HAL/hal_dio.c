/**
 * @file hal_dio.c
 * @author Zheng Yu (user_zheng_yu@163.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __HAL_DIO_C__
#define __HAL_DIO_C__

#include "hal_dio.h"

#ifdef HAL_Module_DIO

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

static HAL_ComReturnType HAL_DIO_Control(uint32_t cmd, void *args);

static HAL_ModuleNotifyType HAL_DIO_NotifyCfg =
{
    NULL,
    NULL,
};

const HAL_ModuleConfigType HAL_DIO_Config =
{
    HAL_DIO_Init,
    HAL_DIO_DeInit,
    HAL_DIO_Control,
    HAL_DIO_MainFunction,
    &HAL_DIO_NotifyCfg
};

HAL_ComReturnType HAL_DIO_Init(void)
{
    HAL_ComReturnType ret = HAL_Fail;

    //TODO 驱动初始化

    return ret;
}

HAL_ComReturnType HAL_DIO_DeInit(void)
{
    HAL_ComReturnType ret = HAL_Fail;

    //TODO 驱动反初始化

    return ret;
}

static HAL_ComReturnType HAL_DIO_Control(uint32_t cmd, void *args)
{
    HAL_ComReturnType ret = HAL_Fail;

    //TODO 驱动控制
    switch (cmd)
    {
    case 0/* constant-expression */:
        /* code */
        break;

    default:
        break;
    }

    return ret;
}

void HAL_DIO_MainFunction(void)
{
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* HAL_Module_DIO */

#endif /* __HAL_DIO_C__ */
