/**
 * @file halComCfg.h
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

#ifndef __HAL_COMMON_Config_H__
#define __HAL_COMMON_Config_H__

#include "halComType.h"

/** 模块定义 **/
#define HAL_Module_DIO (0)

/** 命令定义 **/
#define DIO_SetLevelLow (0)
#define DIO_SetLevelHigh (1)
#define DIO_SetDirectionIn (2)
#define DIO_SetDirectionOut (3)
#define DIO_SetDirectionZ (4)

#endif /* __HAL_COMMON_Config_H__ */

#ifdef __cplusplus
}
#endif /* __cplusplus */
