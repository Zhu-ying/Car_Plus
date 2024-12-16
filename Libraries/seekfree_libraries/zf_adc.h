/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897(已满)  三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		adc
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ790875685)
 * @version    		查看doc内version文件 版本说明
 * @Software 		MDK FOR C251 V5.60
 * @Target core		STC32G12K128
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-4-14
 ********************************************************************************************************************/

#ifndef __ZF_ADC_H
#define __ZF_ADC_H

#include "common.h"

//此枚举定义不允许用户修改
/*
这个枚举ADCN_enum定义了一个集合，用于表示STM32微控制器上的ADC（模拟/数字转换器）通道与特定的GPIO引脚的对应关系。
每个枚举值代表一个特定的ADC通道，这些通道可以被配置来读取与之相连的GPIO引脚的模拟信号。

以下是枚举中每个值的含义：
ADC_P10到ADC_P17：这些枚举值代表与GPIO端口P的第10至第17号引脚（即P1_0至P1_7）相连的ADC通道。这些通道可以用于读取连接到这些GPIO引脚的模拟信号。
ADC_P00到ADC_P06：这些枚举值代表与GPIO端口P的第0至第6号引脚（即P0_0至P0_6）相连的ADC通道。
ADC_POWR：这个枚举值代表一个内部ADC通道，用于读取内部参考电压（1.19V）。在STM32中，通常有一些内部通道用于读取温度、电池电压等内部信号。
枚举的使用可以让代码更加清晰和易于管理，因为它提供了一个易于理解的名称来代替直接使用数字。例如，如果你想配置ADC来读取P1_0引脚的模拟信号，
你可以使用ADC_P10而不是直接使用数字0。
在实际编程中，这个枚举可以用来索引ADC通道数组或作为函数参数，以便于配置和读取特定的ADC通道。
*/

/*枚举1：引脚代替枚举*/
typedef enum
{
    ADC_P10 = 0     , 
    ADC_P11         , 
    ADC_P12         ,	//STC16F没有这个引脚，仅做站位使用
	ADC_P13         , 
    ADC_P14         , 
	ADC_P15         , 
	ADC_P16         , 
	ADC_P17         , 
	
	ADC_P00         , 
	ADC_P01         , 
	ADC_P02        	, 
	ADC_P03        	, 
	ADC_P04        	, 
	ADC_P05        	, 
	ADC_P06        	, 
	ADC_POWR = 0x0f	, //内部AD 1.19V
} ADCN_enum;


/*
这个枚举ADC_SPEED_enum定义了ADC（模拟/数字转换器）的时钟分频选项。在微控制器中，ADC模块需要一个时钟源来进行模拟信号的采样和转换。
通常，这个时钟源来自于系统的主时钟（SYSclk），但是ADC工作时需要一个较慢的时钟，因此需要对系统时钟进行分频。

枚举中的每个值代表了不同的分频比例，这些比例决定了ADC时钟的速度。以下是每个值的含义：

ADC_SYSclk_DIV_2 到 ADC_SYSclk_DIV_32：这些枚举值分别表示系统时钟被分频为原来的2倍、4倍、6倍...直到32倍。每个值对应一个分频系数，用于配置ADC时钟。

选择不同的分频比例会影响ADC的采样率和转换速度。较大的分频比例（即较小的ADC时钟频率）可以提供更高的分辨率和更好的抗噪声性能，但会降低采样率和转换速度。反之，较小的分频比例可以提高采样率和转换速度，但可能会牺牲一些分辨率和抗噪声性能。

在配置ADC时，你需要根据你的应用需求选择合适的分频比例。例如，如果你需要快速响应，可能需要选择一个较小的分频比例；如果你需要更高的分辨率，可能需要选择一个较大的分频比例。

在代码中使用这个枚举，可以确保开发者选择一个预定义的、系统支持的分频比例，而不是直接操作分频寄存器，这样可以减少配置错误并提高代码的可读性。*/
//此枚举定义不允许用户修改
typedef enum
{
	ADC_SYSclk_DIV_2 = 0,
	ADC_SYSclk_DIV_4,
	ADC_SYSclk_DIV_6,
	ADC_SYSclk_DIV_8,
	ADC_SYSclk_DIV_10,
	ADC_SYSclk_DIV_12,
	ADC_SYSclk_DIV_14,
	ADC_SYSclk_DIV_16,
	ADC_SYSclk_DIV_18,
	ADC_SYSclk_DIV_20,
	ADC_SYSclk_DIV_22,
	ADC_SYSclk_DIV_24,
	ADC_SYSclk_DIV_26,
	ADC_SYSclk_DIV_28,
	ADC_SYSclk_DIV_30,
	ADC_SYSclk_DIV_32,
} ADC_SPEED_enum;


//此枚举定义不允许用户修改
typedef enum    // 枚举ADC通道
{

    ADC_12BIT=0,    //12位分辨率
	ADC_11BIT,		//11位分辨率
	ADC_10BIT,		//10位分辨率
	ADC_9BIT,    	//9位分辨率
	ADC_8BIT,     	//8位分辨率

}ADCRES_enum;

void adc_init(ADCN_enum adcn,ADC_SPEED_enum speed);
uint16 adc_once(ADCN_enum adcn,ADCRES_enum resolution);
//uint16 adc_mean_filter(ADCN_enum adcn, uint8 count);


#endif