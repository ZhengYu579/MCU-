#include <stdio.h>
#include "HAL/hal.h"

#define HAL_Module_Num (1)

extern const HAL_ModuleConfigType HAL_DIO_Config;

const HAL_ModuleConfigType *moduleList[HAL_Module_Num] =
{
    &HAL_DIO_Config,
};

const HAL_ConfigType HAL_Config =
{
    HAL_Module_Num,
    (HAL_ModuleConfigType**)moduleList
};

int main()
{
    HAL_Init(&HAL_Config);
    return 0;
}
