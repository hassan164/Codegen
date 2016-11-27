/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : tpmTmr2.h
**     Project     : KL27Chainsaw
**     Processor   : MKL27Z64VLH4
**     Component   : fsl_tpm
**     Version     : Component 1.3.0, Driver 01.00, CPU db: 3.00.000
**     Repository  : KSDK 1.3.0
**     Compiler    : Keil ARM C/C++ Compiler
**     Date/Time   : 2016-11-11, 14:46, # CodeGen: 7
**     Contents    :
**         TPM_DRV_Init                  - tpm_status_t TPM_DRV_Init(uint32_t instance,const tpm_general_config_t * info);
**         TPM_DRV_PwmStop               - void TPM_DRV_PwmStop(uint32_t instance,tpm_pwm_param_t * param,uint8_t channel);
**         TPM_DRV_PwmStart              - tpm_status_t TPM_DRV_PwmStart(uint32_t instance,tpm_pwm_param_t *...
**         TPM_DRV_SetTimeOverflowIntCmd - void TPM_DRV_SetTimeOverflowIntCmd(uint32_t instance,bool overflowEnable);
**         TPM_DRV_SetChnIntCmd          - void TPM_DRV_SetChnIntCmd(uint32_t instance,uint8_t channelNum,bool enable);
**         TPM_DRV_SetClock              - void TPM_DRV_SetClock(uint32_t instance,tpm_clock_mode_t clock,tpm_clock_ps_t...
**         TPM_DRV_GetClock              - uint32_t TPM_DRV_GetClock(uint32_t instance);
**         TPM_DRV_CounterStart          - void TPM_DRV_CounterStart(uint32_t instance,tpm_counting_mode_t...
**         TPM_DRV_CounterStop           - void TPM_DRV_CounterStop(uint32_t instance);
**         TPM_DRV_CounterRead           - uint32_t TPM_DRV_CounterRead(uint32_t instance);
**         TPM_DRV_InputCaptureEnable    - void TPM_DRV_InputCaptureEnable(uint32_t instance,uint8_t...
**         TPM_DRV_GetChnVal             - uint32_t TPM_DRV_GetChnVal(uint32_t instance,uint8_t channel);
**         TPM_DRV_OutputCompareEnable   - void TPM_DRV_OutputCompareEnable(uint32_t instance,uint8_t...
**         TPM_DRV_Deinit                - void TPM_DRV_Deinit(uint32_t instance);
**         TPM_DRV_IRQHandler            - void TPM_DRV_IRQHandler(uint32_t instance);
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file tpmTmr2.h
** @version 01.00
*/         
/*!
**  @addtogroup tpmTmr2_module tpmTmr2 module documentation
**  @{
*/         
#ifndef __tpmTmr2_H
#define __tpmTmr2_H
/* MODULE tpmTmr2. */

/* Include inherited beans */
#include "clockMan1.h"
#include "Cpu.h"

/*! @brief Device instance number */
#define tpmTmr2_IDX TPM1_IDX
/*! @brief Device instance number for backward compatibility */
#define FSL_TPMTMR2 tpmTmr2_IDX

/*! @brief Basic configuration declaration */
extern const tpm_general_config_t tpmTmr2_InitConfig0;
    
/*! @brief PWM channels configuration declaration */
extern tpm_pwm_param_t tpmTmr2_ChnConfig0;
    

#endif
/* ifndef __tpmTmr2_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
