/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controllers_forgeneration.h
 *
 * Code generated for Simulink model 'controllers_forgeneration'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Thu Nov 10 16:49:40 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controllers_forgeneration_h_
#define RTW_HEADER_controllers_forgeneration_h_
#include <string.h>
#include <stddef.h>
#ifndef controllers_forgeneration_COMMON_INCLUDES_
# define controllers_forgeneration_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* controllers_forgeneration_COMMON_INCLUDES_ */

#include "controllers_forgeneration_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T HinfinitycontrollerRUNNING_DSTA[5];/* '<S1>/Hinfinity controller RUNNING' */
  real_T HinfinitycontrollerIDLE_DSTATE[5];/* '<S1>/Hinfinity controller IDLE' */
  real_T Integrator_DSTATE;            /* '<S3>/Integrator' */
  real_T Filter_DSTATE;                /* '<S3>/Filter' */
} DW_controllers_forgeneration_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: HinfinitycontrollerRUNNING_A
   * Referenced by: '<S1>/Hinfinity controller RUNNING'
   */
  real_T HinfinitycontrollerRUNNING_A[25];

  /* Computed Parameter: HinfinitycontrollerRUNNING_C
   * Referenced by: '<S1>/Hinfinity controller RUNNING'
   */
  real_T HinfinitycontrollerRUNNING_C[5];

  /* Computed Parameter: HinfinitycontrollerIDLE_A
   * Referenced by: '<S1>/Hinfinity controller IDLE'
   */
  real_T HinfinitycontrollerIDLE_A[25];

  /* Computed Parameter: HinfinitycontrollerIDLE_C
   * Referenced by: '<S1>/Hinfinity controller IDLE'
   */
  real_T HinfinitycontrollerIDLE_C[5];
} ConstP_controllers_forgenerat_T;

/* Real-time Model Data Structure */
struct tag_RTM_controllers_forgenera_T {
  const char_T * volatile errorStatus;
};

/* Block states (auto storage) */
extern DW_controllers_forgeneration_T controllers_forgeneration_DW;

/* Constant parameters (auto storage) */
extern const ConstP_controllers_forgenerat_T controllers_forgeneratio_ConstP;

/* Model entry point functions */
extern void controllers_forgeneration_initialize(void);
extern void controllers_forgeneration_terminate(void);

/* Customized model step function */
extern real_T controllers_forgeneration_custom(real_T arg_mode, real_T arg_wc,
  real_T arg_actuator_pos, real_T arg_actuator_speed);

/* Real-time Model object */
extern RT_MODEL_controllers_forgener_T *const controllers_forgeneration_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S1>/Zero-Order Hold' : Eliminated since input and output rates are identical
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'controllers_forgeneration'
 * '<S1>'   : 'controllers_forgeneration/Hybrid Hinf controller'
 * '<S2>'   : 'controllers_forgeneration/mode to ref'
 * '<S3>'   : 'controllers_forgeneration/Hybrid Hinf controller/PID Controller'
 * '<S4>'   : 'controllers_forgeneration/Hybrid Hinf controller/controller mode selector'
 */
#endif                                 /* RTW_HEADER_controllers_forgeneration_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
