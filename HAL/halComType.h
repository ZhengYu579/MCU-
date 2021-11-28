/**
 * @file halComType.h
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

#ifndef __HAL_COMMON_TYPE_H__
#define __HAL_COMMON_TYPE_H__

#include <stdint.h>
#include <stdlib.h>

#ifndef NULL
#define NULL (void*)0
#endif

/**
 * @brief HAL层共通返回状态类型
 * 
 */
typedef enum
{
    HAL_SUC = 0,    ///< 成功
    HAL_Fail        ///< 失败
} HAL_ComReturnType;

/**
 * @brief HAL层共通回调函数指针类型
 * 
 */
typedef HAL_ComReturnType (*HAL_ComCallBack)(uint32_t notifyCategory, void *arg);

typedef struct
{
    HAL_ComCallBack func;
    void *moduleData;
}HAL_ModuleNotifyType;

/**
 * @brief HAL层模块配置类型
 * 
 */
typedef struct
{
    HAL_ComReturnType (*Init)(void);                    ///< 初始化函数指针
    HAL_ComReturnType (*DeInit)(void);                  ///< 反初始化函数指针
    HAL_ComReturnType (*Control)(uint32_t, void *);     ///< 控制函数指针
    void (*MainFunction)(void);                         ///< 主功能函数指针
    HAL_ModuleNotifyType *notifycation;                 ///< 通知结构体
} HAL_ModuleConfigType;

/**
 * @brief HAL层配置类型
 * 
 */
typedef struct
{
    uint8_t HalModule_Num;              ///< HAL层模块数量
    HAL_ModuleConfigType **pModules;    ///< HAL层模块配置列表
} HAL_ConfigType;

#endif /* __HAL_COMMON_TYPE_H__ */

#ifdef __cplusplus
}
#endif /* __cplusplus */
