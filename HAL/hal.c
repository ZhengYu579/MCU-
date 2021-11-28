/**
 * @file hal.c
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

#ifndef __HAL_C__
#define __HAL_C__

#include "hal.h"

static HAL_ConfigType *pHAL = NULL;

HAL_ComReturnType HAL_Init(const HAL_ConfigType *pConfig)
{
    HAL_ComReturnType ret = HAL_Fail;
    uint8_t i = 0;

    if (NULL != pConfig)
    {
        pHAL = (HAL_ConfigType *)pConfig;

        for (i = 0; i < pHAL->HalModule_Num; i++)
        {
            if (NULL != pHAL->pModules[i]->Init)
            {
                ret = pHAL->pModules[i]->Init();
            }
        }
    }
    return ret;
}

HAL_ComReturnType HAL_DeInit(void)
{
    HAL_ComReturnType ret = HAL_Fail;
    uint8_t i = 0;

    if (NULL != pHAL)
    {
        for (i = 0; i < pHAL->HalModule_Num; i++)
        {
            if (NULL != pHAL->pModules[i]->DeInit)
            {
                ret = pHAL->pModules[i]->DeInit();
            }
        }

        pHAL = NULL;
    }
    return ret;
}

HAL_ComReturnType HAL_Control(uint8_t module, uint32_t command, void *args)
{
    HAL_ComReturnType ret = HAL_Fail;

    if (NULL != pHAL)
    {
        if (module < pHAL->HalModule_Num)
        {
            if (NULL != pHAL->pModules[module]->Control)
            {
                ret = pHAL->pModules[module]->Control(command, args);
            }
        }
    }
    return ret;
}

HAL_ComReturnType HAL_RegisterNotifycation(uint8_t module, HAL_ComCallBack CallBack)
{
    HAL_ComReturnType ret = HAL_Fail;

    if (NULL != pHAL)
    {
        if (module < pHAL->HalModule_Num)
        {
            if (NULL != CallBack)
            {
                pHAL->pModules[module]->notifycation->func = CallBack;
                ret = HAL_SUC;
            }
        }
    }
    return ret;
}

void HAL_MainFunction(void)
{
    uint8_t i = 0;

    if (NULL != pHAL)
    {
        for (i = 0; i < pHAL->HalModule_Num; i++)
        {
            if (NULL != pHAL->pModules[i]->MainFunction)
            {
                pHAL->pModules[i]->MainFunction();
            }
        }
    }
}

#endif /* __HAL_C__ */

#ifdef __cplusplus
}
#endif /* __cplusplus */
