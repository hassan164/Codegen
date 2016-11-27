/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controllers_forgeneration.c
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

#include "controllers_forgeneration.h"
#include "controllers_forgeneration_private.h"

/* Block states (auto storage) */
DW_controllers_forgeneration_T controllers_forgeneration_DW;

/* Real-time model */
RT_MODEL_controllers_forgener_T controllers_forgeneration_M_;
RT_MODEL_controllers_forgener_T *const controllers_forgeneration_M =
  &controllers_forgeneration_M_;

/* Model step function */
real_T controllers_forgeneration_custom(real_T arg_mode, real_T arg_wc, real_T
  arg_actuator_pos, real_T arg_actuator_speed)
{
  /* local block i/o variables */
  real_T rtb_HinfinitycontrollerRUNNING;
  real_T rtb_HinfinitycontrollerIDLE;
  real_T rtb_idleerrorgain;
  real_T rtb_runerrorgain;
  real_T rtb_ref;
  real_T rtb_FilterCoefficient;
  real_T rtb_controller;

  /* specified return value */
  real_T arg_actuator_voltage;

  /* MATLAB Function: '<Root>/mode to ref' incorporates:
   *  Inport: '<Root>/mode'
   */
  /*  1: running mode */
  /*  0: idle mode (actually anything else than 1 works) */
  /* MATLAB Function 'mode to ref': '<S2>:1' */
  /* '<S2>:1:6' if mode == 1 */
  if (arg_mode == 1.0) {
    /* '<S2>:1:7' ref = 10300; */
    rtb_ref = 10300.0;
  } else {
    /* '<S2>:1:8' else */
    /* '<S2>:1:9' ref = 2200; */
    rtb_ref = 2200.0;
  }

  /* End of MATLAB Function: '<Root>/mode to ref' */

  /* MATLAB Function: '<S1>/controller mode selector' */
  /*  Changes the controller according to the state of the system */
  /*  1: running mode */
  /*  2: idle mode */
  /*  3: PID (not used right now) */
  /*  4: constant input if we desire to implement some "safety" feature */
  /* MATLAB Function 'Hybrid Hinf controller/controller mode selector': '<S4>:1' */
  /* '<S4>:1:9' if ref<4000 */
  if (rtb_ref < 4000.0) {
    /* '<S4>:1:10' controller = 2; */
    rtb_controller = 2.0;
  } else {
    /* '<S4>:1:11' else */
    /* '<S4>:1:12' controller = 1; */
    rtb_controller = 1.0;
  }

  /* End of MATLAB Function: '<S1>/controller mode selector' */

  /* DiscreteStateSpace: '<S1>/Hinfinity controller RUNNING' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 =
        controllers_forgeneratio_ConstP.HinfinitycontrollerRUNNING_C;
      const real_T *xd =
        &controllers_forgeneration_DW.HinfinitycontrollerRUNNING_DSTA[0];
      real_T *y0 = &rtb_HinfinitycontrollerRUNNING;
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }
  }

  /* DiscreteStateSpace: '<S1>/Hinfinity controller IDLE' */
  {
    {
      static const int_T colCidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pCidx = &colCidxRow0[0];
      const real_T *pC0 =
        controllers_forgeneratio_ConstP.HinfinitycontrollerIDLE_C;
      const real_T *xd =
        &controllers_forgeneration_DW.HinfinitycontrollerIDLE_DSTATE[0];
      real_T *y0 = &rtb_HinfinitycontrollerIDLE;
      int_T numNonZero = 4;
      *y0 = (*pC0++) * xd[*pCidx++];
      while (numNonZero--) {
        *y0 += (*pC0++) * xd[*pCidx++];
      }
    }
  }

  /* Sum: '<S1>/Sum' incorporates:
   *  Inport: '<Root>/wc'
   */
  rtb_ref -= arg_wc;

  /* Gain: '<S3>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S3>/Filter'
   *  Gain: '<S3>/Derivative Gain'
   *  Sum: '<S3>/SumD'
   */
  rtb_FilterCoefficient = (1.1E-5 * rtb_ref -
    controllers_forgeneration_DW.Filter_DSTATE) * 100.0;

  /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  DiscreteIntegrator: '<S3>/Integrator'
   *  Gain: '<S3>/Proportional Gain'
   *  Sum: '<S3>/Sum'
   */
  switch ((int32_T)rtb_controller) {
   case 1:
    rtb_controller = rtb_HinfinitycontrollerRUNNING;
    break;

   case 2:
    rtb_controller = rtb_HinfinitycontrollerIDLE;
    break;

   case 3:
    rtb_controller = (0.0007 * rtb_ref +
                      controllers_forgeneration_DW.Integrator_DSTATE) +
      rtb_FilterCoefficient;
    break;

   case 4:
    rtb_controller = 0.14;
    break;

   default:
    rtb_controller = 0.0;
    break;
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch' */

  /* Gain: '<Root>/LQR Gain' incorporates:
   *  Gain: '<Root>/level to rad'
   *  Inport: '<Root>/actuator_pos'
   *  Inport: '<Root>/actuator_speed'
   *  Saturate: '<Root>/Saturation 0-1'
   *  Sum: '<Root>/Sum'
   */
  if (rtb_controller > 1.0) {
    rtb_controller = 1.0;
  } else {
    if (rtb_controller < 0.0) {
      rtb_controller = 0.0;
    }
  }

  rtb_controller = (1.3089969389957472 * rtb_controller - arg_actuator_pos) *
    22.499082283342613 + (0.0 - arg_actuator_speed) * 0.026802074930869533;

  /* End of Gain: '<Root>/LQR Gain' */

  /* Saturate: '<Root>/6V Saturation' */
  if (rtb_controller > 6.0) {
    /* Outport: '<Root>/actuator_voltage' */
    arg_actuator_voltage = 6.0;
  } else if (rtb_controller < -6.0) {
    /* Outport: '<Root>/actuator_voltage' */
    arg_actuator_voltage = -6.0;
  } else {
    /* Outport: '<Root>/actuator_voltage' */
    arg_actuator_voltage = rtb_controller;
  }

  /* End of Saturate: '<Root>/6V Saturation' */

  /* Gain: '<S1>/idle error gain ' */
  rtb_idleerrorgain = 0.00034482758620689653 * rtb_ref;

  /* Gain: '<S1>/run error gain' */
  rtb_runerrorgain = 0.00011111111111111112 * rtb_ref;

  /* Update for DiscreteStateSpace: '<S1>/Hinfinity controller RUNNING' */
  {
    real_T xnew[5];

    {
      static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 =
        controllers_forgeneratio_ConstP.HinfinitycontrollerRUNNING_A;
      const real_T *xd =
        &controllers_forgeneration_DW.HinfinitycontrollerRUNNING_DSTA[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 4;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (0.15965022027399806)*rtb_runerrorgain;

    {
      static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA5 =
        &controllers_forgeneratio_ConstP.HinfinitycontrollerRUNNING_A[5];
      const real_T *xd =
        &controllers_forgeneration_DW.HinfinitycontrollerRUNNING_DSTA[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 4;
      *pxnew1 = (*pA5++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA5++) * xd[*pAidx++];
      }
    }

    xnew[1] += (1.0742384944755043E-6)*rtb_runerrorgain;

    {
      static const int_T colAidxRow2[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA10 =
        &controllers_forgeneratio_ConstP.HinfinitycontrollerRUNNING_A[10];
      const real_T *xd =
        &controllers_forgeneration_DW.HinfinitycontrollerRUNNING_DSTA[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 4;
      *pxnew2 = (*pA10++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA10++) * xd[*pAidx++];
      }
    }

    xnew[2] += (0.00052822515983540512)*rtb_runerrorgain;

    {
      static const int_T colAidxRow3[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA15 =
        &controllers_forgeneratio_ConstP.HinfinitycontrollerRUNNING_A[15];
      const real_T *xd =
        &controllers_forgeneration_DW.HinfinitycontrollerRUNNING_DSTA[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 4;
      *pxnew3 = (*pA15++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA15++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.003338175258822817)*rtb_runerrorgain;

    {
      static const int_T colAidxRow4[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA20 =
        &controllers_forgeneratio_ConstP.HinfinitycontrollerRUNNING_A[20];
      const real_T *xd =
        &controllers_forgeneration_DW.HinfinitycontrollerRUNNING_DSTA[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 4;
      *pxnew4 = (*pA20++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA20++) * xd[*pAidx++];
      }
    }

    xnew[4] += (0.0015482113217704023)*rtb_runerrorgain;
    (void) memcpy(&controllers_forgeneration_DW.HinfinitycontrollerRUNNING_DSTA
                  [0], xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteStateSpace: '<S1>/Hinfinity controller IDLE' */
  {
    real_T xnew[5];

    {
      static const int_T colAidxRow0[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow0[0];
      const real_T *pA0 =
        controllers_forgeneratio_ConstP.HinfinitycontrollerIDLE_A;
      const real_T *xd =
        &controllers_forgeneration_DW.HinfinitycontrollerIDLE_DSTATE[0];
      real_T *pxnew0 = &xnew[0];
      int_T numNonZero = 4;
      *pxnew0 = (*pA0++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew0 += (*pA0++) * xd[*pAidx++];
      }
    }

    xnew[0] += (0.16377449086220841)*rtb_idleerrorgain;

    {
      static const int_T colAidxRow1[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow1[0];
      const real_T *pA5 =
        &controllers_forgeneratio_ConstP.HinfinitycontrollerIDLE_A[5];
      const real_T *xd =
        &controllers_forgeneration_DW.HinfinitycontrollerIDLE_DSTATE[0];
      real_T *pxnew1 = &xnew[1];
      int_T numNonZero = 4;
      *pxnew1 = (*pA5++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew1 += (*pA5++) * xd[*pAidx++];
      }
    }

    xnew[1] += (6.5824514162831629E-7)*rtb_idleerrorgain;

    {
      static const int_T colAidxRow2[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow2[0];
      const real_T *pA10 =
        &controllers_forgeneratio_ConstP.HinfinitycontrollerIDLE_A[10];
      const real_T *xd =
        &controllers_forgeneration_DW.HinfinitycontrollerIDLE_DSTATE[0];
      real_T *pxnew2 = &xnew[2];
      int_T numNonZero = 4;
      *pxnew2 = (*pA10++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew2 += (*pA10++) * xd[*pAidx++];
      }
    }

    xnew[2] += (3.8315356204695665E-5)*rtb_idleerrorgain;

    {
      static const int_T colAidxRow3[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow3[0];
      const real_T *pA15 =
        &controllers_forgeneratio_ConstP.HinfinitycontrollerIDLE_A[15];
      const real_T *xd =
        &controllers_forgeneration_DW.HinfinitycontrollerIDLE_DSTATE[0];
      real_T *pxnew3 = &xnew[3];
      int_T numNonZero = 4;
      *pxnew3 = (*pA15++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew3 += (*pA15++) * xd[*pAidx++];
      }
    }

    xnew[3] += (0.0017734491603174354)*rtb_idleerrorgain;

    {
      static const int_T colAidxRow4[5] = { 0, 1, 2, 3, 4 };

      const int_T *pAidx = &colAidxRow4[0];
      const real_T *pA20 =
        &controllers_forgeneratio_ConstP.HinfinitycontrollerIDLE_A[20];
      const real_T *xd =
        &controllers_forgeneration_DW.HinfinitycontrollerIDLE_DSTATE[0];
      real_T *pxnew4 = &xnew[4];
      int_T numNonZero = 4;
      *pxnew4 = (*pA20++) * xd[*pAidx++];
      while (numNonZero--) {
        *pxnew4 += (*pA20++) * xd[*pAidx++];
      }
    }

    xnew[4] += (1.5603400351805468)*rtb_idleerrorgain;
    (void) memcpy(&controllers_forgeneration_DW.HinfinitycontrollerIDLE_DSTATE[0],
                  xnew,
                  sizeof(real_T)*5);
  }

  /* Update for DiscreteIntegrator: '<S3>/Integrator' incorporates:
   *  Gain: '<S3>/Integral Gain'
   */
  controllers_forgeneration_DW.Integrator_DSTATE += 0.00028 * rtb_ref * 0.04;

  /* Update for DiscreteIntegrator: '<S3>/Filter' */
  controllers_forgeneration_DW.Filter_DSTATE += 0.04 * rtb_FilterCoefficient;
  return arg_actuator_voltage;
}

/* Model initialize function */
void controllers_forgeneration_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(controllers_forgeneration_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&controllers_forgeneration_DW, 0,
                sizeof(DW_controllers_forgeneration_T));
}

/* Model terminate function */
void controllers_forgeneration_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
