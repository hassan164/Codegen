/* ###################################################################
**     Filename    : Events.c
**     Project     : KL27Chainsaw
**     Processor   : MKL27Z64VLH4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : Keil ARM C/C++ Compiler
**     Date/Time   : 2016-11-11, 11:57, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "Events.h"
#include "controllers_forgeneration.h"
#include "controllers_forgeneration_private.h"
#include "controllers_forgeneration_types.h"
#include "rtwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

#ifdef tpmTmr1_IDX
/*
** ===================================================================
**     Interrupt handler : TPM0_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
	
real_T 	mode = 1;
real_T wc[] = {5000, 10300};
real_T actuator_pos[] = { ((75 * 3.14)/180) , ((70 * 3.14)/180) };
real_T actuator_speed[] = { 1 , 0 };
real_T result = 0;
int element = 0;
int counter = 0;
uint32_t adc_val = 0;
uint32_t dutyC = 0;

uint32_t new_captureValue = 0;
uint32_t old_captureValue = 0;
uint32_t time = 0;

uint32_t TPM0_second_tick_value = 0;
uint32_t TPM0_first_tick_value = 0;
uint32_t tpm0_IRQ_time = 0;

uint32_t TPM2_second_tick_value = 0;
uint32_t TPM2_first_tick_value = 0;
uint32_t tpm2_IRQ_time = 0;

uint32_t PORTBCDE_second_tick_value = 0;
uint32_t PORTBCDE_first_tick_value = 0;
uint32_t PORTBCDE_IRQ_time = 0;

uint32_t gpio3_input_value = 0;
uint32_t gpio4_input_value = 0;
uint32_t valve_count = 0;

void TPM0_IRQHandler(void)
{
	TPM0_first_tick_value = TPM2_CNT;
  TPM_DRV_IRQHandler(tpmTmr1_IDX);
  /* Write your code here ... */
//	GPIO_HAL_TogglePinOutput(PTA_BASE_PTR, 13);
	if(counter < 25)
		element = 0;
	else
		element = 1;
	
	result = controllers_forgeneration_custom(mode, wc[element], actuator_pos[element], actuator_speed[element]);
	
	counter++;
//	TPM1_C0V = (TPM1_C0V + 10)%TPM1_MOD;
		
#ifdef CONTROL_DEBUG	
	if (result <= 6 && result >= 1){
		GPIO_HAL_ClearPinOutput(PTA_BASE_PTR, 13);	//BLUE LED
		GPIO_HAL_SetPinOutput(PTB_BASE_PTR, 18);
		GPIO_HAL_SetPinOutput(PTB_BASE_PTR, 19);
		TPM1_C0V = 0x300;
		dutyC  = TPM1_C0V;
	}
	else if (result < 1 && result >= -2){
		GPIO_HAL_ClearPinOutput(PTB_BASE_PTR, 19);	// GREEN LED
		GPIO_HAL_SetPinOutput(PTB_BASE_PTR, 18);
		GPIO_HAL_SetPinOutput(PTA_BASE_PTR, 13);
		TPM1_C0V = 0xEF;
		dutyC  = TPM1_C0V;
	}
	if (result < -2 && result >= -6){
		GPIO_HAL_ClearPinOutput(PTB_BASE_PTR, 18);	// RED LED
		GPIO_HAL_SetPinOutput(PTB_BASE_PTR, 19);
		GPIO_HAL_SetPinOutput(PTA_BASE_PTR, 13);
		TPM1_C0V = 0x0;
		dutyC  = TPM1_C0V;
	}
#endif
	adc_val = ADC0_RA;
	
	TPM0_second_tick_value = TPM2_CNT;
	if(TPM0_second_tick_value>=TPM0_first_tick_value){
		// The maximum value is 0xFFFF or 65535
		tpm0_IRQ_time = (TPM0_second_tick_value - TPM0_first_tick_value) & 0xFFFF;
	}
	else{
		tpm0_IRQ_time = (0xFFFFFFFF+(TPM0_second_tick_value - TPM0_first_tick_value)) & 0xFFFF;
	}
	//Check
	if(tpm0_IRQ_time >= 0x5B){
		GPIO_HAL_TogglePinOutput(PTB_BASE_PTR, 19);		// green
	}
}
#else
  /* This IRQ handler is not used by tpmTmr1 component. The purpose may be
   * that the component has been removed or disabled. It is recommended to 
   * remove this handler because Processor Expert cannot modify it according to 
   * possible new request (e.g. in case that another component uses this
   * interrupt vector). */
  #warning This IRQ handler is not used by tpmTmr1 component.\
           It is recommended to remove this because Processor Expert cannot\
           modify it according to possible new request.
#endif

#ifdef tpmTmr2_IDX
/*
** ===================================================================
**     Interrupt handler : TPM1_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TPM1_IRQHandler(void)
{
  TPM_DRV_IRQHandler(tpmTmr2_IDX);
  /* Write your code here ... */
//GPIO_HAL_TogglePinOutput(PTA_BASE_PTR, 13);
}
#else
  /* This IRQ handler is not used by tpmTmr2 component. The purpose may be
   * that the component has been removed or disabled. It is recommended to 
   * remove this handler because Processor Expert cannot modify it according to 
   * possible new request (e.g. in case that another component uses this
   * interrupt vector). */
  #warning This IRQ handler is not used by tpmTmr2 component.\
           It is recommended to remove this because Processor Expert cannot\
           modify it according to possible new request.
#endif

/*
** ===================================================================
**     Interrupt handler : ADC0_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void ADC0_IRQHandler(void)
{
  /* Write your code here ... */
}

#ifdef tpmTmr3_IDX
/*
** ===================================================================
**     Interrupt handler : TPM2_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TPM2_IRQHandler(void)
{
	TPM2_first_tick_value = TPM2_CNT;
	
  TPM_DRV_IRQHandler(tpmTmr3_IDX);
  /* Write your code here ... */
//	GPIO_HAL_TogglePinOutput(PTA_BASE_PTR, 13);
	
	new_captureValue = TPM2_C0V;
	if(new_captureValue>=old_captureValue){
		// The maximum value is 0xFFFF or 65535
		time = (new_captureValue - old_captureValue) & 0xFFFF;
	}
	else{
		time = (0xFFFFFFFF+(new_captureValue - old_captureValue)) & 0xFFFF;
	}
	
	old_captureValue = new_captureValue;
	GPIO_HAL_TogglePinOutput(PTB_BASE_PTR, 18);	//red
	
	TPM2_second_tick_value = TPM2_CNT;
	if(TPM2_second_tick_value>=TPM2_first_tick_value){
		// The maximum value is 0xFFFF or 65535
		tpm2_IRQ_time = (TPM2_second_tick_value - TPM2_first_tick_value) & 0xFFFF;
	}
	else{
		tpm2_IRQ_time = (0xFFFFFFFF+(TPM2_second_tick_value - TPM2_first_tick_value)) & 0xFFFF;
	}
}
#else
  /* This IRQ handler is not used by tpmTmr3 component. The purpose may be
   * that the component has been removed or disabled. It is recommended to 
   * remove this handler because Processor Expert cannot modify it according to 
   * possible new request (e.g. in case that another component uses this
   * interrupt vector). */
  #warning This IRQ handler is not used by tpmTmr3 component.\
           It is recommended to remove this because Processor Expert cannot\
           modify it according to possible new request.
#endif

/*
** ===================================================================
**     Interrupt handler : PORTA_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/*
** ===================================================================
**     Interrupt handler : PORTBCDE_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void PORTBCDE_IRQHandler(void)
{
	PORTBCDE_first_tick_value = TPM2_CNT;
	// Checking if there has been an interrupt event for PORTC_0
  if(PORTC_PCR1 & (1<<24)){
			/* Clear interrupt flag.*/
		PORT_HAL_ClearPortIntFlag(PORTC_BASE_PTR);
		/* Write your code here ... */
		gpio3_input_value = ((PTC_BASE_PTR->PDIR)>>2) & 0x1;
		gpio4_input_value = ((PTC_BASE_PTR->PDIR)>>1) & 0x1;
		if(gpio3_input_value == gpio4_input_value){
			valve_count++;
		}
		else{
			valve_count--;
		}
		GPIO_HAL_ClearPinOutput(PTB_BASE_PTR, 19);	// GREEN LED
		GPIO_HAL_SetPinOutput(PTB_BASE_PTR, 18);
	}
	
	// Checking if there has been an interrupt event for PORTC_1
	if(PORTC_PCR2 & (1<<24)){
			/* Clear interrupt flag.*/
		PORT_HAL_ClearPortIntFlag(PORTC_BASE_PTR);
		/* Write your code here ... */
		gpio3_input_value = ((PTC_BASE_PTR->PDIR)>>2) & 0x1; // checking value of portC pin 2
		gpio4_input_value = ((PTC_BASE_PTR->PDIR)>>1) & 0x1; // checking value of portC pin 1
		if(gpio3_input_value == gpio4_input_value){
		valve_count--;
		}
		else{
		valve_count++;
		}
		GPIO_HAL_ClearPinOutput(PTB_BASE_PTR, 18);	// RED LED
		GPIO_HAL_SetPinOutput(PTB_BASE_PTR, 19);
	}
	
	PORTBCDE_second_tick_value = TPM2_CNT;
	if(PORTBCDE_second_tick_value>=PORTBCDE_first_tick_value){
		// The maximum value is 0xFFFF or 65535
		PORTBCDE_IRQ_time = (PORTBCDE_second_tick_value - PORTBCDE_first_tick_value) & 0xFFFF;
	}
	else{
		PORTBCDE_IRQ_time = (0xFFFFFFFF+(PORTBCDE_second_tick_value - PORTBCDE_first_tick_value)) & 0xFFFF;
	}
}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

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
