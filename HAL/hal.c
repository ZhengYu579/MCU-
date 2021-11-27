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

// #ifdef __cplusplus
// extern "C"
// {
// #endif /* __cplusplus */

#ifndef __HAL_C__
#define __HAL_C__

#include "halComType.h"
#include "halComCfg.h"

static HAL_ConfigType *pHAL = NULL;

HAL_ComReturnType HAL_Init(const HAL_ConfigType *pConfig)
{
    HAL_ComReturnType ret = HAL_Fail;
    uint8_t i = 0;

    if(NULL != pConfig)
    {
        pHAL = (HAL_ConfigType*)pConfig;

        for(i = 0;i < pHAL->HalModule_Num; i++)
        {
            if(NULL != pHAL->pModules[i]->Init)
            {
                ret = pHAL->pModules[i]->Init();
            }
        }
    }
    return ret;
}

HAL_ComReturnType HAL_DeInit(void);

HAL_ComReturnType HAL_Control(uint8_t module, uint32_t command, void *args);

HAL_ComReturnType HAL_RegisterNotifycation(uint8_t module, HAL_ComCallBack CallBack);

void HAL_MainFunction(void);

#endif /* __HAL_C__ */

// #ifdef __cplusplus
// }
// #endif /* __cplusplus */

