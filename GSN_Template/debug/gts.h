#pragma once

#define GT_API extern "C" short __stdcall

/*-----------------------------------------------------------*/
/* Channel of Command                                        */
/*-----------------------------------------------------------*/
#define CHANNEL_HOST                   (0)
#define CHANNEL_UART                   (1)
#define CHANNEL_SIM                    (2)
#define CHANNEL_ETHER                  (3)
#define CHANNEL_RS232                  (4)
#define CHANNEL_PCIE                   (5)
#define CHANNEL_RINGNET                  (6)

/*-----------------------------------------------------------*/
/* Error Code                                                */
/*-----------------------------------------------------------*/

#define CMD_SUCCESS                     (0)

#define CMD_ERROR_READ_LEN             (-2)    /* ��ȡ���ݳ��ȴ��� */
#define CMD_ERROR_READ_CHECKSUM        (-3)    /* ��ȡ����У��ʹ��� */

#define CMD_ERROR_WRITE_BLOCK          (-4)    /* д�����ݿ���� */
#define CMD_ERROR_READ_BLOCK           (-5)    /* ��ȡ���ݿ���� */

#define CMD_ERROR_OPEN                 (-6)    /* ���豸���� */
#define CMD_ERROR_CLOSE                (-6)    /* �ر��豸���� */
#define CMD_ERROR_DSP_BUSY             (-7)    /* DSPæ */

#define CMD_LOCK_ERROR                 (-8)    /*���߳���Դæ*/
#define CMD_DMA_ERROR                  (-9)    // DMA�������
#define CMD_COMM_ERROR                 (-10)    /*pcieͨѶʧ��*/
#define CMD_LOAD_RINGNET_DLL_ERROR     (-11)    /*�Ȼ��������ʧ��*/
#define CMD_RINGNET_STIME_ERROR        (-12)    /*�Ȼ��������ʧ��*/

#define CMD_RINGNET_ENC0_ERROR         (-13)    /*core1��������ʼ��ʧ��*/

#define CMD_RINGNET_ENC1_ERROR         (-14)   /*core2��������ʼ��ʧ��*/

#define CMD_LOAD_RINGNET_ERROR         (-17)    /*�Ȼ�����API����ʧ��*/
#define CMD_MCVERSION_MATCH_ERROR      (-15)   /*�Ȼ���ƥ��ʧ�ܣ���Ҫ���¿�*/
#define CMD_LOCK_NULL				   (-20)   /*���̱߳����򿪾��ʧ��*/
#define CMD_MCVERSION_MATCH_WARNING    (15)   /*�˿ذ汾ƥ��ʧ�ܣ�ĳЩ���ܲ��߱�*/
#define CMD_DSPVERSION_MATCH_WARNING   (16)   /*�˿�DSP�汾����,���߱��汾ƥ�书��*/

#define CMD_FILE_MATCH_WARNING         (17)   /*�����ļ���ʽ�����ڲ�ƥ��*/

#define CMD_ERROR_EXECUTE               1
#define CMD_ERROR_VERSION_NOT_MATCH     3
#define CMD_ERROR_PARAMETER             7
#define CMD_ERROR_UNKNOWN               8    /* unspported command */

#define MC_NONE                         (-1)

#define MC_LIMIT_POSITIVE               (0)
#define MC_LIMIT_NEGATIVE               (1)
#define MC_ALARM                        (2)
#define MC_HOME                         (3)
#define MC_GPI                          (4)
#define MC_ARRIVE                       (5)
#define MC_EGPI0                     (6)
// #define MC_EGPI1                     (7)
// #define MC_EGPI2                     (8)
#define MC_MPG                          (9)

#define MC_ENABLE                       (10)
#define MC_CLEAR                        (11)
#define MC_GPO                          (12)
// #define MC_EGPO0                     (13)
// #define MC_EGPO1                     (14)
#define MC_AU_ADC						(17)
#define MC_HSO                          (18)
#define MC_AU_DAC						(19)


#define MC_DAC                          (20)
#define MC_STEP                         (21)
#define MC_PULSE                        (22)
#define MC_ENCODER                      (23)
#define MC_ADC                          (24)

#define MC_AU_ENCODER                   (26)

#define MC_ABS_ENCODER                  (29)

#define MC_AXIS                         (30)
#define MC_PROFILE                      (31)
#define MC_CONTROL                      (32)

#define MC_TRIGGER                      (40)

#define MC_AU_TRIGGER			(44)

#define MC_TERMINAL                     (50)
#define MC_MPG_ENCODER				    (53)
#define MC_EXT_MODULE                   (60)
#define MC_EXT_DI                       (61)
#define MC_EXT_DO                       (62)
#define MC_EXT_AI                       (63)
#define MC_EXT_AO                       (64)

#define MC_SCAN_CRD                     (70)
#define MC_LASER		        (71)
#define MC_LASER_AO		        (72)

#define MC_POS_COMPARE                  (80)

#define MC_WATCH_VAR                    (200)
#define MC_WATCH_EVENT                  (201)

typedef struct  
{
	short year;
	short month;
	short day;
	short version;
	short user;
	short reserve1;
	short reserve2;
	short chip;
} TVersion;

#define CORE_MODE_TIMER					(0)
#define CORE_MODE_SYNCH					(1)
#define CORE_MODE_EXTERNAL				(2)

#define CORE_TASK_DEFAULT				(0)
#define CORE_TASK_DLM					(1)

#define SKIP_MODULE_SCAN				(0x001)
#define SKIP_MODULE_POS_COMPARE			(0x002)
#define SKIP_MODULE_CRD					(0x004)

#define SKIP_MODULE_PLC					(0x010)
#define SKIP_MODULE_DLM					(0x020)

#define SKIP_MODULE_AXIS_CALCULATE		(0x100)

#define SKIP_MODULE_WATCH				(0x800)

typedef enum
{
	TIME_ELAPSE_PROFILE = 1000,

	TIME_ELAPSE_INTERRUPT_ERROR_COUNT = 1100,

	TIME_ELAPSE_HOST_COMMAND_EXECUTE = 1220,
	TIME_ELAPSE_ETHER_COMMAND_EXECUTE,

	TIME_ELAPSE_PROFILE_CALCULATE = 6000,

	TIME_ELAPSE_SCAN = 18000,

	TIME_ELAPSE_AXIS_CHECK = 20000,
	TIME_ELAPSE_AXIS_CALCULATE,
	TIME_ELAPSE_AXIS_FILTER,

	TIME_ELAPSE_ENCODER = 30000,

	TIME_ELAPSE_DI = 31000,

	TIME_ELAPSE_DO = 32000,

	TIME_ELAPSE_AI = 33000,

	TIME_ELAPSE_AO = 34000,

	TIME_ELAPSE_TRIGGER = 38000,

	TIME_ELAPSE_CONTROL = 40000,

	TIME_ELAPSE_WATCH = 52000,

	TIME_ELAPSE_TERMINAL = 53000,

	TIME_ELAPSE_TERMINAL_OPERATION = 53001,

	TIME_ELAPSE_READ_ADC = 54000,

} ETimeElapse;

typedef struct Pid
{
	double kp;
	double ki;
	double kd;
	double kvff;
	double kaff;
	long   integralLimit;
	long   derivativeLimit;
	short  limit;
} TPid;

/*-----------------------------------------------------------*/
/* Basic function                                            */
/*-----------------------------------------------------------*/
GT_API GT_SetCardNo(short index);
GT_API GT_GetCardNo(short *pIndex);
GT_API GT_Open(short channel=0,short param=1);
GT_API GT_Close(void);
GT_API GT_SetCore(short core);
GT_API GT_GetCore(short *pCore);
GT_API GT_GetVersion(char **pVersion);
GT_API GT_GetVersionEx(short type,TVersion *pVersion);
GT_API GT_Reset();
GT_API GT_GetClock(unsigned long *pClock,unsigned long *pLoop=NULL);
GT_API GT_GetClockHighPrecision(unsigned long *pClock);
GT_API GT_ClearTime(ETimeElapse item);
GT_API GT_GetTime(ETimeElapse item,unsigned long *pTime,unsigned long *pTimeMax,unsigned long *pValue=NULL);
GT_API GT_GetSts(short axis,long *pSts,short count=1,unsigned long *pClock=NULL);
GT_API GT_ClrSts(short axis,short count=1);
GT_API GT_AxisOn(short axis);
GT_API GT_AxisOff(short axis);
GT_API GT_MultiAxisOn(unsigned long mask);
GT_API GT_MultiAxisOff(unsigned long mask);
GT_API GT_SetAxisOnDelayTime(unsigned short ms);
GT_API GT_GetAxisOnDelayTime(unsigned short *pMs);
GT_API GT_Stop(long mask,long option);
GT_API GT_SetPrfPos(short profile,long prfPos);
GT_API GT_SynchAxisPos(long mask);
GT_API GT_ZeroPos(short axis,short count=1);
GT_API GT_GetLimitStatus(short axis,short *pLimitPositive,short *pLimitNegative);
GT_API GT_SetSoftLimitMode(short axis,short mode);
GT_API GT_GetSoftLimitMode(short axis,short *pMode);
GT_API GT_SetSoftLimit(short axis,long positive,long negative);
GT_API GT_GetSoftLimit(short axis,long *pPositive,long *pNegative);
GT_API GT_SetAxisBand(short axis,long band,long time);
GT_API GT_GetAxisBand(short axis,long *pBand,long *pTime);
GT_API GT_GetPrfPos(short profile,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetPrfVel(short profile,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetPrfAcc(short profile,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetPrfMode(short profile,long *pValue, short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisPrfPos(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisPrfPosCompensate(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisPrfVel(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisPrfAcc(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisEncPos(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisEncVel(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisEncAcc(short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAxisError(short axis,double *pValue, short count=1,unsigned long *pClock=NULL);
GT_API GT_SetControlFilter(short control,short index);
GT_API GT_GetControlFilter(short control,short *pIndex);
GT_API GT_SetControlSuperimposed(short control,short superimposedType,short superimposedIndex);
GT_API GT_GetControlSuperimposed(short control,short *pSuperimposedType,short *pSuperimposedIndex);
GT_API GT_SetPid(short control,short index,TPid *pPid);
GT_API GT_GetPid(short control,short index,TPid *pPid);
GT_API GT_SetKvffFilter(short control,short index,short kvffFilterExp,double accMax);
GT_API GT_GetKvffFilter(short control,short index,short *pKvffFilterExp,double *pAccMax);
GT_API GT_Delay(unsigned short ms);
GT_API GT_DelayHighPrecision(unsigned short profile);

GT_API GTN_Open(short channel=5,short param=1);
GT_API GTN_OpenRingNet(short channel=5,short param=1,char *pFile=NULL,short index=1,long count=1);
GT_API GTN_Close(void);
GT_API GTN_GetChannel(short *pChannel);
GT_API GTN_GetVersion(short core,char **pVersion);
GT_API GTN_GetVersionEx(short core,short type,TVersion *pVersion);
GT_API GTN_SetVersion(short core,short type,TVersion *pVersion);
GT_API GTN_Reset(short core);
GT_API GTN_GetClock(short core,unsigned long *pClock,unsigned long *pLoop=NULL);
GT_API GTN_GetClockHighPrecision(short core,unsigned long *pClock);
GT_API GTN_ClearTime(short core,ETimeElapse item);
GT_API GTN_GetTime(short core,ETimeElapse item,unsigned long *pTime,unsigned long *pTimeMax,unsigned long *pValue=NULL);
GT_API GTN_SetCoreMode(short core,short mode);
GT_API GTN_GetCoreMode(short core,short *pMode);
GT_API GTN_SetCoreShare(short core,short type,short index,short count);
GT_API GTN_GetCoreShare(short core,short type,short *pIndex,short *pCount);
GT_API GTN_SetCoreTask(short core,short task);
GT_API GTN_GetCoreTask(short core,short *pTask);
GT_API GTN_GetResMax(short core,short type,short *pCount);
GT_API GTN_SetResCount(short core,short type,short count);
GT_API GTN_GetResCount(short core,short type,short *pCount);
GT_API GTN_GetSts(short core,short axis,long *pSts,short count=1,unsigned long *pClock=NULL);
GT_API GTN_ClrSts(short core,short axis,short count=1);
GT_API GTN_AxisOn(short core,short axis);
GT_API GTN_AxisOff(short core,short axis);
GT_API GTN_MultiAxisOn(short core,unsigned long mask);
GT_API GTN_MultiAxisOff(short core,unsigned long mask);
GT_API GTN_SetAxisOnDelayTime(short core,unsigned short delayTime);
GT_API GTN_GetAxisOnDelayTime(short core,unsigned short *pDelayTime);
GT_API GTN_Stop(short core,long mask,long option);
GT_API GTN_SetPrfPos(short core,short profile,long prfPos);
GT_API GTN_SynchAxisPos(short core,long mask);
GT_API GTN_ZeroPos(short core,short axis,short count=1);
GT_API GTN_GetLimitStatus(short core,short axis,short *pLimitPositive,short *pLimitNegative);
GT_API GTN_SetSoftLimitMode(short core,short axis,short mode);
GT_API GTN_GetSoftLimitMode(short core,short axis,short *pMode);
GT_API GTN_SetSoftLimit(short core,short axis,long positive,long negative);
GT_API GTN_GetSoftLimit(short core,short axis,long *pPositive,long *pNegative);
GT_API GTN_SetAxisBand(short core,short axis,long band,long time);
GT_API GTN_GetAxisBand(short core,short axis,long *pBand,long *pTime);
GT_API GTN_GetPrfPos(short core,short profile,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetPrfVel(short core,short profile,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetPrfAcc(short core,short profile,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetPrfMode(short core,short profile,long *pValue, short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAxisPrfPos(short core,short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAxisPrfPosCompensate(short core,short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAxisPrfVel(short core,short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAxisPrfAcc(short core,short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAxisEncPos(short core,short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAxisEncVel(short core,short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAxisEncAcc(short core,short axis,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAxisError(short core,short axis,double *pValue, short count=1,unsigned long *pClock=NULL);
GT_API GTN_SetControlFilter(short core,short control,short index);
GT_API GTN_GetControlFilter(short core,short control,short *pIndex);
GT_API GTN_SetControlSuperimposed(short core,short control,short superimposedType,short superimposedIndex);
GT_API GTN_GetControlSuperimposed(short core,short control,short *pSuperimposedType,short *pSuperimposedIndex);
GT_API GTN_SetPid(short core,short control,short index,TPid *pPid);
GT_API GTN_GetPid(short core,short control,short index,TPid *pPid);
GT_API GTN_SetKvffFilter(short core,short control,short index,short kvffFilterExp,double accMax);
GT_API GTN_GetKvffFilter(short core,short control,short index,short *pKvffFilterExp,double *pAccMax);
GT_API GTN_Delay(short core,unsigned short ms);
GT_API GTN_DelayHighPrecision(short core,unsigned short profile);


#define STEP_DIR                        (0)
#define STEP_PULSE                      (1)
#define STEP_ORTHOGONAL                 (2)

GT_API GT_LoadConfig(char *pFile);
GT_API GT_AlarmOff(short axis);
GT_API GT_AlarmOn(short axis);
GT_API GT_LmtsOn(short axis,short limitType=-1);
GT_API GT_LmtsOff(short axis,short limitType=-1);
GT_API GT_StepDir(short step);
GT_API GT_StepPulse(short step);
GT_API GT_StepOrthogonal(short step);
GT_API GT_SetMtrBias(short dac,short bias);
GT_API GT_GetMtrBias(short dac,short *pBias);
GT_API GT_SetMtrLmt(short dac,short limit);
GT_API GT_GetMtrLmt(short dac,short *pLimit);
GT_API GT_EncOn(short encoder);
GT_API GT_EncOff(short encoder);
GT_API GT_SetPosErr(short control,long error);
GT_API GT_GetPosErr(short control,long *pError);
GT_API GT_SetStopDec(short profile,double decSmoothStop,double decAbruptStop);
GT_API GT_GetStopDec(short profile,double *pDecSmoothStop,double *pDecAbruptStop);
GT_API GT_CtrlMode(short axis,short mode);
GT_API GT_SetStopIo(short axis,short stopType,short inputType,short inputIndex);
GT_API GT_SetAdcFilterPrm(short adc,double k);
GT_API GT_GetAdcFilterPrm(short adc,double *pk);
GT_API GT_SetAxisPrfVelFilter(short axis,short filterNumExp);
GT_API GT_GetAxisPrfVelFilter(short axis,short *pFilterNumExp);
GT_API GT_SetAxisEncVelFilter(short axis,short filterNumExp);
GT_API GT_GetAxisEncVelFilter(short axis,short *pFilterNumExp);
GT_API GT_SetProfileScale(short i,long alpha,long beta);
GT_API GT_GetProfileScale(short i,long *pAlhpa,long *pBeta);
GT_API GT_SetEncoderScale(short i,long alpha,long beta);
GT_API GT_GetEncoderScale(short i,long *pAlhpa,long *pBeta);

GT_API GTN_LoadConfig(short core,char *pFile);
GT_API GTN_AlarmOn(short core,short axis);
GT_API GTN_AlarmOff(short core,short axis);
GT_API GTN_LmtsOn(short core,short axis,short limitType=-1);
GT_API GTN_LmtsOff(short core,short axis,short limitType=-1);
GT_API GTN_StepDir(short core,short step);
GT_API GTN_StepPulse(short core,short step);
GT_API GTN_StepOrthogonal(short core,short step);
GT_API GTN_SetMtrBias(short core,short dac,short bias);
GT_API GTN_GetMtrBias(short core,short dac,short *pBias);
GT_API GTN_SetMtrLmt(short core,short dac,short limit);
GT_API GTN_GetMtrLmt(short core,short dac,short *pLimit);
GT_API GTN_SetSense(short core,short dataType,short dataIndex,short value);
GT_API GTN_GetSense(short core,short dataType,short dataIndex,short *pValue);
GT_API GTN_EncOn(short core,short encoder);
GT_API GTN_EncOff(short core,short encoder);
GT_API GTN_SetPosErr(short core,short control,long error);
GT_API GTN_GetPosErr(short core,short control,long *pError);
GT_API GTN_SetAxisPosErrLimit(short core,short axis,long errorLimit);
GT_API GTN_GetAxisPosErrLimit(short core,short axis,long *pErrorLimit);
GT_API GTN_SetStopDec(short core,short profile,double decSmoothStop,double decAbruptStop);
GT_API GTN_GetStopDec(short core,short profile,double *pDecSmoothStop,double *pDecAbruptStop);
GT_API GTN_CtrlMode(short core,short axis,short mode);
GT_API GTN_SetStopIo(short core,short axis,short stopType,short inputType,short inputIndex);
GT_API GTN_SetAdcFilterPrm(short core,short adc,double k);
GT_API GTN_GetAdcFilterPrm(short core,short adc,double *pk);
GT_API GTN_SetAxisPrfVelFilter(short core,short axis,short filterNumExp);
GT_API GTN_GetAxisPrfVelFilter(short core,short axis,short *pFilterNumExp);
GT_API GTN_SetAxisEncVelFilter(short core,short axis,short filterNumExp);
GT_API GTN_GetAxisEncVelFilter(short core,short axis,short *pFilterNumExp);
GT_API GTN_SetProfileScale(short core,short i,long alpha,long beta);
GT_API GTN_GetProfileScale(short core,short i,long *pAlhpa,long *pBeta);
GT_API GTN_SetEncoderScale(short core,short i,long alpha,long beta);
GT_API GTN_GetEncoderScale(short core,short i,long *pAlhpa,long *pBeta);
GT_API GTN_SetAuEncoderScale(short core,short i,long alpha,long beta);
GT_API GTN_GetAuEncoderScale(short core,short i,long *pAlhpa,long *pBeta);

/*-----------------------------------------------------------*/
/* Capture and Triggr                                        */
/*-----------------------------------------------------------*/
#define CAPTURE_HOME                    (1)
#define CAPTURE_INDEX                   (2)
#define CAPTURE_PROBE                   (3)
#define CAPTURE_HSIO0                   (6)
#define CAPTURE_HSIO1                   (7)
#define CAPTURE_POSCOMPARE              (6)

typedef struct Trigger
{
	short encoder;
	short probeType;
	short probeIndex;
	short sense;
	long  offset;
	unsigned long loop;
	short windowOnly;
	long firstPosition;
	long lastPosition;
}TTrigger;

typedef struct TriggerEx
{
	short latchType;
	short latchIndex;
	short probeType;
	short probeIndex;
	short sense;
	long  offset;
	unsigned long loop;
	short windowOnly;
	long firstPosition;
	long lastPosition;
}TTriggerEx;

typedef struct TriggerAlign
{
	short encoder;
	short probeType;
	short probeIndex;
	short sense;
	long offset;
	unsigned long loop;
	short windowOnly;
	short pad2;
	long firstPosition;
	long lastPosition;
}TTriggerAlign;

typedef struct TriggerStatus
{
	short execute;
	short done;
	long position;
}TTriggerStatus;

typedef struct TriggerStatusEx
{
	short execute;
	short done;
	long position;
	unsigned long clock;
	unsigned long loopCount;
}TTriggerStatusEx;


GT_API GT_SetTrigger(short i,TTrigger *pTrigger);
GT_API GT_GetTrigger(short i,TTrigger *pTrigger);
GT_API GT_GetTriggerStatus(short i,TTriggerStatus *pTriggerStatus,short count=1);
GT_API GT_ClearTriggerStatus(short i);
GT_API GT_SetCaptureMode(short encoder,short mode);
GT_API GT_GetCaptureMode(short encoder,short *pMode,short count=1);
GT_API GT_GetCaptureStatus(short encoder,short *pStatus,long *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_SetCaptureSense(short encoder,short mode,short sense);
GT_API GT_ClearCaptureStatus(short encoder);
GT_API GT_SetCaptureRepeat(short encoder,short count);
GT_API GT_GetCaptureRepeatStatus(short encoder,short *pCount);
GT_API GT_GetCaptureRepeatPos(short encoder,long *pValue,short startNum,short count);
GT_API GT_SetCaptureRepeatFifoMode(short encoder,short mode);
GT_API GT_GetCaptureRepeatFifoMode(short encoder,short *pMode);


GT_API GTN_SetAuTrigger(short core,short i,TTriggerEx *pTrigger);
GT_API GTN_GetAuTrigger(short core,short i,TTriggerEx *pTrigger);
GT_API GTN_ClearAuTriggerStatus(short core,short i);
GT_API GTN_GetAuTriggerStatus(short core,short i,TTriggerStatusEx *pTriggerStatusEx,short count=1);


GT_API GTN_SetTrigger(short core,short i,TTrigger *pTrigger);
GT_API GTN_GetTrigger(short core,short i,TTrigger *pTrigger);
GT_API GTN_SetTriggerEx(short core,short i,TTriggerEx *pTrigger);
GT_API GTN_GetTriggerEx(short core,short i,TTriggerEx *pTrigger);
GT_API GTN_GetTriggerStatus(short core,short i,TTriggerStatus *pTriggerStatus,short count=1);
GT_API GTN_GetTriggerStatusEx(short core,short i,TTriggerStatusEx *pTriggerStatusEx,short count=1);
GT_API GTN_ClearTriggerStatus(short core,short i);
GT_API GTN_DisableTrigger(short core,short i);
GT_API GTN_SetCaptureMode(short core,short encoder,short mode);
GT_API GTN_GetCaptureMode(short core,short encoder,short *pMode,short count=1);
GT_API GTN_GetCaptureStatus(short core,short encoder,short *pStatus,long *pValue,short count,unsigned long *pClock);
GT_API GTN_SetCaptureSense(short core,short encoder,short mode,short sense);
GT_API GTN_ClearCaptureStatus(short core,short encoder);
GT_API GTN_SetCaptureRepeat(short core,short encoder,short count);
GT_API GTN_GetCaptureRepeatStatus(short core,short encoder,short *pCount);
GT_API GTN_GetCaptureRepeatPos(short core,short encoder,long *pValue,short startNum,short count);
GT_API GTN_SetCaptureRepeatFifoMode(short core,short encoder,short mode);
GT_API GTN_GetCaptureRepeatFifoMode(short core,short encoder,short *pMode);

typedef struct
{
	short fifoFull;
	short pad1[3];
	double pad2[2];
}TLatchValueInfo;

typedef struct TriggerPrm
{
	short latchType;
	short latchIndex;
	short probeType;
	short probeIndex;
	short sense;
	short loopType;
	long  offset;
	unsigned long loop;
	short windowOnly;
	short pad1;
	long firstPosition;
	long lastPosition;
	short fifoMode;
	short pad2[3];
	double pad3;
}TTriggerPrm;

GT_API GTN_SetTriggerPrm(short core,short i,TTriggerPrm *pTriggerPrm);
GT_API GTN_GetTriggerPrm(short core,short i,TTriggerPrm *pTriggerPrm);
GT_API GTN_GetTriggerLatchValue(short core,short i,long count,long *pValue,long *pCount,TLatchValueInfo *pInfo);

#define TRIGGER_DELTA_MODE_DEFAULT            (0)

#define TRIGGER_DELTA_CHECKPOINT_MODE_AUTO    (0)
#define TRIGGER_DELTA_CHECKPOINT_MODE_MANUAL  (1)

typedef struct Checkpoint
{
	short mode;
	long offset;
	short fifoIndex;
	unsigned long crossCount;
	short fifoDataCount;
	short dataReady;
	long data;
	short dataIndex;
} TCheckpoint;

typedef struct TriggerDeltaPrm
{
	short mode;
	short dir;
	short triggerIndex[2];
} TTriggerDeltaPrm;

typedef struct TriggerDelta
{
	short enable;
	short checkpointCount;
	short fifoDataCount;
	short lostCount;
}TTriggerDeltaInfo;

GT_API GT_ClearTriggerDelta(short index,short mode=0);
GT_API GT_AddTriggerDeltaCheckpoint(short index,short mode,long offset,short fifo=0,short *pIndex=NULL);
GT_API GT_ReadTriggerDeltaCheckpointData(short index,short checkpointIndex,long *pBuf,short count,short *pReadCount);
GT_API GT_WriteTriggerDeltaCheckpointData(short index,short checkpointIndex,long *pBuf,short count,short *pWriteCount);
GT_API GT_SetTriggerDeltaPrm(short index,TTriggerDeltaPrm *pPrm);
GT_API GT_GetTriggerDeltaPrm(short index,TTriggerDeltaPrm *pPrm);
GT_API GT_GetTriggerDeltaCheckpoint(short index,short checkpointIndex,TCheckpoint *pCheckpoint);
GT_API GT_GetTriggerDeltaInfo(short index,TTriggerDeltaInfo *pTriggerDelta);
GT_API GT_TriggerDeltaOn(short index);
GT_API GT_TriggerDeltaOff(short index);

GT_API GTN_ClearTriggerDelta(short core,short index,short mode=0);
GT_API GTN_AddTriggerDeltaCheckpoint(short core,short index,short mode,long offset,short fifo=0,short *pIndex=NULL);
GT_API GTN_ReadTriggerDeltaCheckpointData(short core,short index,short checkpointIndex,long *pBuf,short count,short *pReadCount);
GT_API GTN_WriteTriggerDeltaCheckpointData(short core,short index,short checkpointIndex,long *pBuf,short count,short *pWriteCount);
GT_API GTN_SetTriggerDeltaPrm(short core,short index,TTriggerDeltaPrm *pPrm);
GT_API GTN_GetTriggerDeltaPrm(short core,short index,TTriggerDeltaPrm *pPrm);
GT_API GTN_GetTriggerDeltaCheckpoint(short core,short index,short checkpointIndex,TCheckpoint *pCheckpoint);
GT_API GTN_GetTriggerDeltaInfo(short core,short index,TTriggerDeltaInfo *pTriggerDelta);
GT_API GTN_TriggerDeltaOn(short core,short index);
GT_API GTN_TriggerDeltaOff(short core,short index);

GT_API GT_LinkCaptureOffset(short encoder,short source);
GT_API GT_SetCaptureOffset(short encoder,long *pOffset,short count,long loop);
GT_API GT_GetCaptureOffset(short encoder,long *pOffset,short *pCount,long *pLoop);
GT_API GT_GetCaptureOffsetStatus(short encoder,short *pCount,long *pLoop,long *pCapturePos);

GT_API GT_SetCaptureEncoder(short trigger,short encoder);
GT_API GT_GetCaptureWidth(short trigger,short *pWidth,short count);

GT_API GTN_LinkCaptureOffset(short core,short encoder,short source);
GT_API GTN_SetCaptureOffset(short core,short encoder,long *pOffset,short count,long loop);
GT_API GTN_GetCaptureOffset(short core,short encoder,long *pOffset,short *pCount,long *pLoop);
GT_API GTN_GetCaptureOffsetStatus(short core,short encoder,short *pCount,long *pLoop,long *pCapturePos);

/*-----------------------------------------------------------*/
/* Basic Motion                                              */
/*-----------------------------------------------------------*/
typedef struct TrapPrm
{
	double acc;
	double dec;
	double velStart;
	short  smoothTime;
} TTrapPrm;

GT_API GT_Update(long mask);
GT_API GT_SetPos(short profile,long pos);
GT_API GT_GetPos(short profile,long *pPos);
GT_API GT_SetVel(short profile,double vel);
GT_API GT_GetVel(short profile,double *pVel);

GT_API GT_PrfTrap(short profile);
GT_API GT_SetTrapPrm(short profile,TTrapPrm *pPrm);
GT_API GT_GetTrapPrm(short profile,TTrapPrm *pPrm);

GT_API GTN_Update(short core,long mask);
GT_API GTN_SetPos(short core,short profile,long pos);
GT_API GTN_GetPos(short core,short profile,long *pPos);
GT_API GTN_SetVel(short core,short profile,double vel);
GT_API GTN_GetVel(short core,short profile,double *pVel);

GT_API GTN_PrfTrap(short core,short profile);
GT_API GTN_SetTrapPrm(short core,short profile,TTrapPrm *pPrm);
GT_API GTN_GetTrapPrm(short core,short profile,TTrapPrm *pPrm);

typedef struct JogPrm
{
	double acc;
	double dec;
	double smooth;
} TJogPrm;

GT_API GT_PrfJog(short profile);
GT_API GT_SetJogPrm(short profile,TJogPrm *pPrm);
GT_API GT_GetJogPrm(short profile,TJogPrm *pPrm);

GT_API GTN_PrfJog(short core,short profile);
GT_API GTN_SetJogPrm(short core,short profile,TJogPrm *pPrm);
GT_API GTN_GetJogPrm(short core,short profile,TJogPrm *pPrm);

#define PT_MODE_STATIC                  0
#define PT_MODE_DYNAMIC                 1

#define PT_SEGMENT_NORMAL               0
#define PT_SEGMENT_EVEN                 1
#define PT_SEGMENT_STOP                 2

typedef struct  
{
	double prfPos;
	long loop;
	short mode;
	short fifoUse;
	short fifoPlace;
	short segmentNumber;
	unsigned long segmentReceive[2];
	unsigned long segmentExecute[2];
	unsigned long bufferReceive[2];
	unsigned long bufferExecute[2];
} TPtInfo;

GT_API GT_PrfPt(short profile,short mode=PT_MODE_STATIC);
GT_API GT_SetPtLoop(short profile,long loop);
GT_API GT_GetPtLoop(short profile,long *pLoop);
GT_API GT_PtSpace(short profile,short *pSpace,short fifo=0);
GT_API GT_PtSpaceEx(short profile,short *pSpace,short *pListSpace,short fifo=0);
GT_API GT_PtData(short profile,double pos,long time,short type=PT_SEGMENT_NORMAL,short fifo=0);
GT_API GT_PtClear(short profile,short fifo=0);
GT_API GT_PtStart(long mask,long option=0);
GT_API GT_SetPtMemory(short profile,short memory);
GT_API GT_GetPtMemory(short profile,short *pMemory);
GT_API GT_SetPtPrecisionMode(short profile,short precisionMode);
GT_API GT_GetPtPrecisionMode(short profile,short *pPrecisionMode);
GT_API GT_GetPtInfo(short profile,TPtInfo *pPtInfo);
GT_API GT_SetPtLink(short profile,short fifo,short list);
GT_API GT_GetPtLink(short profile,short fifo,short *pList);
GT_API GT_PtDoBit(short profile,short doType,short index,short value,short fifo=0);
GT_API GT_PtAo(short profile,short aoType,short index,double value,short fifo=0);
//GT_API GTN_PosCurrFeedForward(short core,short profile,double pos,long time,short torque,short type,short fifo=0);

GT_API GTN_PrfPt(short core,short profile,short mode=PT_MODE_STATIC);
GT_API GTN_SetPtLoop(short core,short profile,long loop);
GT_API GTN_GetPtLoop(short core,short profile,long *pLoop);
GT_API GTN_PtSpace(short core,short profile,short *pSpace,short fifo=0);
GT_API GTN_PtSpaceEx(short core,short profile,short *pSpace,short *pListSpace,short fifo=0);
GT_API GTN_PtData(short core,short profile,double pos,long time,short type=PT_SEGMENT_NORMAL,short fifo=0);
GT_API GTN_PtClear(short core,short profile,short fifo=0);
GT_API GTN_PtStart(short core,long mask,long option=0);
GT_API GTN_SetPtMemory(short core,short profile,short memory);
GT_API GTN_GetPtMemory(short core,short profile,short *pMemory);
GT_API GTN_SetPtPrecisionMode(short core,short profile,short precisionMode);
GT_API GTN_GetPtPrecisionMode(short core,short profile,short *pPrecisionMode);
GT_API GTN_GetPtInfo(short core,short profile,TPtInfo *pPtInfo);
GT_API GTN_SetPtLink(short core,short profile,short fifo,short list);
GT_API GTN_GetPtLink(short core,short profile,short fifo,short *pList);
GT_API GTN_PtDoBit(short core,short profile,short doType,short index,short value,short fifo=0);
GT_API GTN_PtAo(short core,short profile,short aoType,short index,double value,short fifo=0);


typedef struct TPvtTableMovePrm
{	
	short tableId;
	long distance;					
	double vm;						
	double am;						
	double jm;						
	double time;					
} TPvtTableMovePrm;

GT_API GT_PrfPvt(short profile);
GT_API GT_SetPvtLoop(short profile,long loop);
GT_API GT_GetPvtLoop(short profile,long *pLoopCount,long *pLoop);
GT_API GT_PvtStatus(short profile,short *pTableId,double *pTime,short count=1);
GT_API GT_PvtStart(long mask);
GT_API GT_PvtTableSelect(short profile,short tableId);

GT_API GT_PvtTable(short tableId,long count,double *pTime,double *pPos,double *pVel);
GT_API GT_PvtTableEx(short tableId,long count,double *pTime,double *pPos,double *pVelBegin,double *pVelEnd);
GT_API GT_PvtTableComplete(short tableId,long count,double *pTime,double *pPos,double *pA,double *pB,double *pC,double velBegin=0,double velEnd=0);
GT_API GT_PvtTablePercent(short tableId,long count,double *pTime,double *pPos,double *pPercent,double velBegin=0);
GT_API GT_PvtPercentCalculate(long n,double *pTime,double *pPos,double *pPercent,double velBegin,double *pVel);
GT_API GT_PvtTableContinuous(short tableId,long count,double *pPos,double *pVel,double *pPercent,double *pVelMax,double *pAcc,double *pDec,double timeBegin);
GT_API GT_PvtTableContinuousEx(short tableId,long n,double *pPos,double *pVel,double *pAccPercent,double *pDecPercent,double *pVelMax,double *pAcc,double *pDec,double timeBegin);
GT_API GT_PvtContinuousCalculate(long n,double *pPos,double *pVel,double *pPercent,double *pVelMax,double *pAcc,double *pDec,double *pTime);

GT_API GT_PvtTableMove(short tableId,long distance,double vm,double am,double jm,double *pTime=NULL);
GT_API GT_PvtTableMove2(short tableId,long distance,double vm,double am,double jm,double *pTime=NULL);
GT_API GT_PvtTableMovePercent(short tableId,long distance,double vm,
							  double acc,double pa1,double pa2,
							  double dec,double pd1,double pd2,
							  double *pVel=NULL,double *pAcc=NULL,double *pDec=NULL,double *pTime=NULL);
GT_API GT_PvtTableMovePercentEx(short tableId,long distance,double vm,
								double acc,double pa1,double pa2,double ma,
								double dec,double pd1,double pd2,double md,
								double *pVel=NULL,double *pAcc=NULL,double *pDec=NULL,double *pTime=NULL);

GT_API GT_PvtTableMoveTogether(short tableCount,TPvtTableMovePrm *pPvtTableMovePrm);

GT_API GTN_PrfPvt(short core,short profile);
GT_API GTN_SetPvtLoop(short core,short profile,long loop);
GT_API GTN_GetPvtLoop(short core,short profile,long *pLoopCount,long *pLoop);
GT_API GTN_PvtStatus(short core,short profile,short *pTableId,double *pTime,short count=1);
GT_API GTN_PvtStart(short core,long mask);
GT_API GTN_PvtTableSelect(short core,short profile,short tableId);

GT_API GTN_PvtTable(short core,short tableId,long count,double *pTime,double *pPos,double *pVel);
GT_API GTN_PvtTableEx(short core,short tableId,long count,double *pTime,double *pPos,double *pVelBegin,double *pVelEnd);
GT_API GTN_PvtTableComplete(short core,short tableId,long count,double *pTime,double *pPos,double *pA,double *pB,double *pC,double velBegin=0,double velEnd=0);
GT_API GTN_PvtTablePercent(short core,short tableId,long count,double *pTime,double *pPos,double *pPercent,double velBegin=0);
GT_API GTN_PvtPercentCalculate(short core,long n,double *pTime,double *pPos,double *pPercent,double velBegin,double *pVel);
GT_API GTN_PvtTableContinuous(short core,short tableId,long count,double *pPos,double *pVel,double *pPercent,double *pVelMax,double *pAcc,double *pDec,double timeBegin);
GT_API GTN_PvtContinuousCalculate(short core,long n,double *pPos,double *pVel,double *pPercent,double *pVelMax,double *pAcc,double *pDec,double *pTime);

GT_API GTN_PvtTableMove(short core,short tableId,long distance,double vm,double am,double jm,double *pTime=NULL);
GT_API GTN_PvtTableMove2(short core,short tableId,long distance,double vm,double am,double jm,double *pTime=NULL);
GT_API GTN_PvtTableMovePercent(short core,short tableId,long distance,double vm,
							   double acc,double pa1,double pa2,
							   double dec,double pd1,double pd2,
							   double *pVel=NULL,double *pAcc=NULL,double *pDec=NULL,double *pTime=NULL);
GT_API GTN_PvtTableMovePercentEx(short core,short tableId,long distance,double vm,
								 double acc,double pa1,double pa2,double ma,
								 double dec,double pd1,double pd2,double md,
								 double *pVel=NULL,double *pAcc=NULL,double *pDec=NULL,double *pTime=NULL);

GT_API GTN_PvtTableMoveTogether(short core,short tableCount,TPvtTableMovePrm *pPvtTableMovePrm);


#define GEAR_MASTER_ENCODER             1
#define GEAR_MASTER_PROFILE             2
#define GEAR_MASTER_AXIS                3
#define GEAR_MASTER_AU_ENCODER          4

#define GEAR_MASTER_ENCODER_OTHER       101
#define GEAR_MASTER_AXIS_OTHER          103

#define GEAR_EVENT_START                1
#define GEAR_EVENT_PASS                 2
#define GEAR_EVENT_AREA                 5

GT_API GT_PrfGear(short profile,short dir=0);
GT_API GT_SetGearMaster(short profile,short masterIndex,short masterType=GEAR_MASTER_PROFILE,short masterItem=0);
GT_API GT_GetGearMaster(short profile,short *pMasterIndex,short *pMasterType=NULL,short *pMasterItem=NULL);
GT_API GT_SetGearRatio(short profile,long masterEven,long slaveEven,long masterSlope=0);
GT_API GT_GetGearRatio(short profile,long *pMasterEven,long *pSlaveEven,long *pMasterSlope=NULL);
GT_API GT_GearStart(long mask);
GT_API GT_SetGearEvent(short profile,short event,long startPara0,long startPara1);
GT_API GT_GetGearEvent(short profile,short *pEvent,long *pStartPara0,long *pStartPara1);

GT_API GTN_PrfGear(short core,short profile,short dir=0);
GT_API GTN_SetGearMaster(short core,short profile,short masterIndex,short masterType=GEAR_MASTER_PROFILE,short masterItem=0);
GT_API GTN_GetGearMaster(short core,short profile,short *pMasterIndex,short *pMasterType=NULL,short *pMasterItem=NULL);
GT_API GTN_SetGearRatio(short core,short profile,long masterEven,long slaveEven,long masterSlope=0);
GT_API GTN_GetGearRatio(short core,short profile,long *pMasterEven,long *pSlaveEven,long *pMasterSlope=NULL);
GT_API GTN_GearStart(short core,long mask);
GT_API GTN_SetGearEvent(short core,short profile,short event,long startPara0,long startPara1);
GT_API GTN_GetGearEvent(short core,short profile,short *pEvent,long *pStartPara0,long *pStartPara1);

#define FOLLOW_SWITCH_SEGMENT			(1)
#define FOLLOW_SWITCH_TABLE				(2)

#define FOLLOW_MASTER_ENCODER           (1)
#define FOLLOW_MASTER_PROFILE           (2)
#define FOLLOW_MASTER_AXIS              (3)
#define FOLLOW_MASTER_AU_ENCODER        (4)

#define FOLLOW_MASTER_ENCODER_OTHER     (101)
#define FOLLOW_MASTER_AXIS_OTHER        (103)

#define FOLLOW_EVENT_START              (1)
#define FOLLOW_EVENT_PASS               (2)

#define FOLLOW_SEGMENT_NORMAL           (0)
#define FOLLOW_SEGMENT_EVEN             (1)
#define FOLLOW_SEGMENT_STOP             (2)
#define FOLLOW_SEGMENT_CONTINUE         (3)

GT_API GT_PrfFollow(short profile,short dir=0);
GT_API GT_SetFollowMaster(short profile,short masterIndex,short masterType=FOLLOW_MASTER_PROFILE,short masterItem=0);
GT_API GT_GetFollowMaster(short profile,short *pMasterIndex,short *pMasterType=NULL,short *pMasterItem=NULL);
GT_API GT_SetFollowLoop(short profile,long loop);
GT_API GT_GetFollowLoop(short profile,long *pLoop);
GT_API GT_SetFollowEvent(short profile,short event,short masterDir,long pos=0);
GT_API GT_GetFollowEvent(short profile,short *pEvent,short *pMasterDir,long *pPos=NULL);
GT_API GT_FollowSpace(short profile,short *pSpace,short fifo=0);
GT_API GT_FollowData(short profile,long masterSegment,double slaveSegment,short type=FOLLOW_SEGMENT_NORMAL,short fifo=0);
GT_API GT_FollowClear(short profile,short fifo=0);
GT_API GT_FollowStart(long mask,long option=0);
GT_API GT_FollowSwitch(long mask);
GT_API GT_SetFollowMemory(short profile,short memory);
GT_API GT_GetFollowMemory(short profile,short *pMemory);
GT_API GT_GetFollowStatus(short profile,short *pFifoNum,short *pSwitchStatus);
GT_API GT_SetFollowPhasing(short profile,short profilePhasing);
GT_API GT_GetFollowPhasing(short profile,short *pProfilePhasing);

GT_API GT_PrfFollowEx(short profile,short dir=0);
GT_API GT_SetFollowMasterEx(short profile,short masterIndex,short masterType=FOLLOW_MASTER_PROFILE,short masterItem=0);
GT_API GT_GetFollowMasterEx(short profile,short *pMasterIndex,short *pMasterType=NULL,short *pMasterItem=NULL);
GT_API GT_SetFollowLoopEx(short profile,long loop);
GT_API GT_GetFollowLoopEx(short profile,long *pLoop);
GT_API GT_SetFollowEventEx(short profile,short event,short masterDir,long pos=0);
GT_API GT_GetFollowEventEx(short profile,short *pEvent,short *pMasterDir,long *pPos=NULL);
GT_API GT_FollowSpaceEx(short profile,short *pSpace,short fifo=0);
GT_API GT_FollowDataPercentEx(short profile,double masterSegment,double slaveSegment,short type=FOLLOW_SEGMENT_NORMAL,short percent=0,short fifo=0);
GT_API GT_FollowClearEx(short profile,short fifo=0);
GT_API GT_FollowStartEx(long mask,long option=0);
GT_API GT_FollowSwitchEx(long mask);
GT_API GT_SetFollowMemoryEx(short profile,short memory);
GT_API GT_GetFollowMemoryEx(short profile,short *pMemory);
GT_API GT_GetFollowStatusEx(short profile,short *pFifoNum,short *pSwitchStatus);
GT_API GT_SetFollowPhasingEx(short profile,short profilePhasing);
GT_API GT_GetFollowPhasingEx(short profile,short *pProfilePhasing);
GT_API GT_FollowSwitchNowEx(short profile,short method,short buffer=0,short fifo=0);
GT_API GT_FollowDataPercent2Ex(short profile,double masterSegment,double slaveSegment,double velBeginRatio,double velEndRatio,short percent=100,short *pPercent1=NULL,short fifo=0);
GT_API GT_GetFollowDataPercent2Ex(double masterPos,double v1,double v2,double p,double p1,double *pSlavePos);
GT_API GT_FollowDoBitEx(short profile,short doType,short index,short value,short fifo=0);
GT_API GT_FollowDelayEx(short profile,unsigned long delayTime,short fifo=0);
GT_API GT_FollowDiBitEx(short profile,short diType,short index,short value,unsigned long time=0,short fifo=0);

GT_API GTN_PrfFollow(short core,short profile,short dir=0);
GT_API GTN_SetFollowMaster(short core,short profile,short masterIndex,short masterType=FOLLOW_MASTER_PROFILE,short masterItem=0);
GT_API GTN_GetFollowMaster(short core,short profile,short *pMasterIndex,short *pMasterType=NULL,short *pMasterItem=NULL);
GT_API GTN_SetFollowLoop(short core,short profile,long loop);
GT_API GTN_GetFollowLoop(short core,short profile,long *pLoop);
GT_API GTN_SetFollowEvent(short core,short profile,short event,short masterDir,long pos=0);
GT_API GTN_GetFollowEvent(short core,short profile,short *pEvent,short *pMasterDir,long *pPos=NULL);
GT_API GTN_FollowSpace(short core,short profile,short *pSpace,short fifo=0);
GT_API GTN_FollowData(short core,short profile,long masterSegment,double slaveSegment,short type=FOLLOW_SEGMENT_NORMAL,short fifo=0);
GT_API GTN_FollowClear(short core,short profile,short fifo=0);
GT_API GTN_FollowStart(short core,long mask,long option=0);
GT_API GTN_FollowSwitch(short core,long mask);
GT_API GTN_SetFollowMemory(short core,short profile,short memory);
GT_API GTN_GetFollowMemory(short core,short profile,short *pMemory);
GT_API GTN_GetFollowStatus(short core,short profile,short *pFifoNum,short *pSwitchStatus);
GT_API GTN_SetFollowPhasing(short core,short profile,short profilePhasing);
GT_API GTN_GetFollowPhasing(short core,short profile,short *pProfilePhasing);

GT_API GTN_PrfFollowEx(short core,short profile,short dir=0);
GT_API GTN_SetFollowMasterEx(short core,short profile,short masterIndex,short masterType=FOLLOW_MASTER_PROFILE,short masterItem=0);
GT_API GTN_GetFollowMasterEx(short core,short profile,short *pMasterIndex,short *pMasterType=NULL,short *pMasterItem=NULL);
GT_API GTN_SetFollowLoopEx(short core,short profile,long loop);
GT_API GTN_GetFollowLoopEx(short core,short profile,long *pLoop);
GT_API GTN_SetFollowEventEx(short core,short profile,short event,short masterDir,long pos=0);
GT_API GTN_GetFollowEventEx(short core,short profile,short *pEvent,short *pMasterDir,long *pPos=NULL);
GT_API GTN_FollowSpaceEx(short core,short profile,short *pSpace,short fifo=0);
GT_API GTN_FollowDataPercentEx(short core,short profile,double masterSegment,double slaveSegment,short type=FOLLOW_SEGMENT_NORMAL,short percent=0,short fifo=0);
GT_API GTN_FollowClearEx(short core,short profile,short fifo=0);
GT_API GTN_FollowStartEx(short core,long mask,long option=0);
GT_API GTN_FollowSwitchEx(short core,long mask);
GT_API GTN_SetFollowMemoryEx(short core,short profile,short memory);
GT_API GTN_GetFollowMemoryEx(short core,short profile,short *pMemory);
GT_API GTN_GetFollowStatusEx(short core,short profile,short *pFifoNum,short *pSwitchStatus);
GT_API GTN_SetFollowPhasingEx(short core,short profile,short profilePhasing);
GT_API GTN_GetFollowPhasingEx(short core,short profile,short *pProfilePhasing);
GT_API GTN_FollowSwitchNowEx(short core,short profile,short method,short buffer=0,short fifo=0);
GT_API GTN_FollowDataPercent2Ex(short core,short profile,double masterSegment,double slaveSegment,double velBeginRatio,double velEndRatio,short percent=100,short *pPercent1=NULL,short fifo=0);
GT_API GTN_GetFollowDataPercent2Ex(short core,double masterPos,double v1,double v2,double p,double p1,double *pSlavePos);
GT_API GTN_FollowDoBitEx(short core,short profile,short doType,short index,short value,short fifo=0);
GT_API GTN_FollowDelayEx(short core,short profile,unsigned long delayTime,short fifo=0);
GT_API GTN_FollowDiBitEx(short core,short profile,short diType,short index,short value,unsigned long time=0,short fifo=0);

GT_API GT_SetFollowVirtualSeg(short profile,short segment,short axis,short fifo);
GT_API GT_GetFollowVirtualSeg(short profile,short *pSegment,short *pAxis,short fifo);

GT_API GT_GetFollowVirtualErr(short profile,double *pVirtualErr);
GT_API GT_ClearFollowVirtualErr(short profile);

typedef struct
{
	long pos;
	double vel;
	double acc;
	double dec;
	short percent;
} TMoveAbsolutePrm;

GT_API GT_MoveAbsolute(short profile,TMoveAbsolutePrm *pPrm);
GT_API GT_GetMoveAbsolute(short profile,TMoveAbsolutePrm *pPrm);

GT_API GTN_MoveAbsolute(short core,short profile,TMoveAbsolutePrm *pPrm);
GT_API GTN_GetMoveAbsolute(short core,short profile,TMoveAbsolutePrm *pPrm);

typedef struct  
{
	short source;
	short enable;
	short x;
	short y;
	double theta;		// degree
} TTransformOrthogonal;

GT_API GT_SetTransformOrthogonal(short index,TTransformOrthogonal *pOrthogonal);
GT_API GT_GetTransformOrthogonal(short index,TTransformOrthogonal *pOrthogonal);
GT_API GT_GetTransformOrthogonalPosition(short index,double *pPositionX,double *pPositionY);

GT_API GTN_SetTransformOrthogonal(short core,short index,TTransformOrthogonal *pOrthogonal);
GT_API GTN_GetTransformOrthogonal(short core,short index,TTransformOrthogonal *pOrthogonal);
GT_API GTN_GetTransformOrthogonalPosition(short core,short index,double *pPositionX,double *pPositionY);

/*-----------------------------------------------------------*/
/* Home                                                      */
/*-----------------------------------------------------------*/
#define HOME_STAGE_IDLE						(0)
#define HOME_STAGE_START					(1)

#define HOME_STAGE_SEARCH_LIMIT				(10)
#define HOME_STAGE_SEARCH_LIMIT_STOP		(11)

#define HOME_STAGE_SEARCH_LIMIT_ESCAPE		(13)

#define HOME_STAGE_SEARCH_LIMIT_RETURN		(15)
#define HOME_STAGE_SEARCH_LIMIT_RETURN_STOP	(16)

#define HOME_STAGE_SEARCH_HOME				(20)

#define HOME_STAGE_SEARCH_HOME_RETURN		(25)

#define HOME_STAGE_SEARCH_INDEX				(30)

#define HOME_STAGE_SEARCH_GPI				(40)

#define HOME_STAGE_SEARCH_GPI_RETURN		(45)

#define HOME_STAGE_GO_HOME					(80)

#define HOME_STAGE_END						(100)

#define HOME_ERROR_NONE						(0)
#define HOME_ERROR_NOT_TRAP_MODE			(1)
#define HOME_ERROR_DISABLE					(2)
#define HOME_ERROR_ALARM					(3)
#define HOME_ERROR_STOP						(4)
#define HOME_ERROR_STAGE					(5)
#define HOME_ERROR_HOME_MODE				(6)
#define HOME_ERROR_SET_CAPTURE_HOME			(7)
#define HOME_ERROR_NO_HOME					(8)
#define HOME_ERROR_SET_CAPTURE_INDEX		(9)
#define HOME_ERROR_NO_INDEX					(10)

#define HOME_MODE_LIMIT						(10)
#define HOME_MODE_LIMIT_HOME				(11)
#define HOME_MODE_LIMIT_INDEX				(12)
#define HOME_MODE_LIMIT_HOME_INDEX			(13)

#define HOME_MODE_HOME						(20)

#define HOME_MODE_HOME_INDEX				(22)

#define HOME_MODE_INDEX						(30)

typedef struct
{
	short mode;
	short moveDir;
	short indexDir;
	short edge;
	short triggerIndex;
	short pad1[3];
	double velHigh;
	double velLow;
	double acc;
	double dec;
	short smoothTime;
	short pad2[3];
	long homeOffset;
	long searchHomeDistance;
	long searchIndexDistance;
	long escapeStep;	
	long pad3[2];		
} THomePrm;

typedef struct
{
	short run;
	short stage;
	short error;
	short pad1;
	long capturePos;
	long targetPos;
} THomeStatus;

GT_API GT_GoHome(short axis,THomePrm *pHomePrm);
GT_API GT_GetHomePrm(short profile,THomePrm *pHomePrm);
GT_API GT_GetHomeStatus(short profile,THomeStatus *pHomeStatus);

GT_API GTN_GoHome(short core,short axis,THomePrm *pHomePrm);
GT_API GTN_GetHomePrm(short core,short axis,THomePrm *pHomePrm);
GT_API GTN_GetHomeStatus(short core,short axis,THomeStatus *pHomeStatus);

GT_API GT_HandwheelInit(short mode=0);
GT_API GT_SetHandwheelStopDec(short slave,double decSmoothStop,double decAbruptStop);
GT_API GT_StartHandwheel(short slave,short master,short masterEven,short slaveEven,short intervalTime,double acc,double dec,double vel,short stopWaitTime);
GT_API GT_EndHandwheel(short slave);

GT_API GTN_HandwheelInit(short core,short mode=0);
GT_API GTN_SetHandwheelStopDec(short core,short slave,double decSmoothStop,double decAbruptStop);
GT_API GTN_StartHandwheel(short core,short slave,short master,short masterEven,short slaveEven,short intervalTime,double acc,double dec,double vel,short stopWaitTime);
GT_API GTN_EndHandwheel(short core,short slave);

/*-----------------------------------------------------------*/
/* PLC                                                       */
/*-----------------------------------------------------------*/
#define PLC_THREAD_MAX					(32)
#define PLC_PAGE_MAX					(32)
#define PLC_LOCAL_VAR_MAX				(1024)
#define PLC_ACCESS_VAR_COUNT_MAX        (8)

#define PLC_TIMER_TT					(0)
#define PLC_TIMER_TF					(1)
#define PLC_TIMER_TTF					(2)

#define PLC_COUNTER_EQ					(0)
#define PLC_COUNTER_LE					(1)
#define PLC_COUNTER_GE					(2)

#define PLC_COUNTER_EDGE_UP				(0)
#define PLC_COUNTER_EDGE_DOWN			(1)
#define PLC_COUNTER_EDGE_UP_DOWN		(2)

#define PLC_FLANK_UP					(0)
#define PLC_FLANK_DOWN					(1)
#define PLC_FLANK_UP_DOWN				(2)

typedef enum
{
	PLC_BIND_NONE,
	PLC_BIND_DI,
	PLC_BIND_DO,
	PLC_BIND_TIMER,
	PLC_BIND_COUNTER,
	PLC_BIND_FLANK,
	PLC_BIND_SRFF,
} EPlcBind;

typedef struct VarInfo
{
	short id;
	short dataType;
	char  name[32];
} TVarInfo;

typedef struct
{
	short diType;
	short index;
	short reverse;
} TBindDi;

typedef struct
{
	short doType;
	short index;
	short reverse;
} TBindDo;

typedef struct
{
	short timerType;
	long delay;
	short inputVarId;
} TBindTimer;

typedef struct
{
	short counterType;
	short edge;
	long init;
	long target;
	long begin;
	long end;
	short dir;
	long unit;
	short inputVarId;
	short resetVarId;
} TBindCounter;

typedef struct
{
	short flankType;
	short inputVarId;
} TBindFlank;

typedef struct
{
	short setVarId;
	short resetVarId;
} TBindSrff;

typedef struct CompileInfo
{
	char  *pFileName;
	short *pLineNo;
	char  *pMessage;
} TCompileInfo;

typedef struct ThreadSts
{
	short  run;
	short  error;
	double result;
	short  line;
} TThreadSts;

GT_API GT_Compile(char *pFileName,TCompileInfo *pWrongInfo);
GT_API GT_Download(char *pFileName);
GT_API GT_GetFunId(char *pFunName,short *pFunId);
GT_API GT_GetVarId(char *pFunName,char *pVarName,TVarInfo *pVarInfo);
GT_API GT_Bind(short thread,short funId,short page);
GT_API GT_RunThread(short thread);
GT_API GT_RunThreadPeriod(short thread,short ms,short priority=4);
GT_API GT_StopThread(short thread);
GT_API GT_PauseThread(short thread);
GT_API GT_GetThreadSts(short thread,TThreadSts *pThreadSts);
GT_API GT_GetThreadTime(short thread,short *pPeriod,double *pExecuteTime,double *pExecuteTimeMax);
GT_API GT_SetVarValue(short page,TVarInfo *pVarInfo,double *pValue,short count=1);
GT_API GT_GetVarValue(short page,TVarInfo *pVarInfo,double *pValue,short count=1);

GT_API GT_UnbindVar(short thread);
GT_API GT_BindDi(short thread,TVarInfo *pVarInfo,TBindDi *pBindDi);
GT_API GT_BindDo(short thread,TVarInfo *pVarInfo,TBindDo *pBindDo);
GT_API GT_BindTimer(short thread,TVarInfo *pVarInfo,TBindTimer *pBindTimer);
GT_API GT_BindCounter(short thread,TVarInfo *pVarInfo,TBindCounter *pBindCounter);
GT_API GT_BindFlank(short thread,TVarInfo *pVarInfo,TBindFlank *pBindFlank);
GT_API GT_BindSrff(short thread,TVarInfo *pVarInfo,TBindSrff *pBindSrff);

GT_API GT_GetBindDi(TVarInfo *pVarInfo,TBindDi *pBindDi);
GT_API GT_GetBindDo(TVarInfo *pVarInfo,TBindDo *pBindDo);
GT_API GT_GetBindTimer(TVarInfo *pVarInfo,TBindTimer *pBindTimer,long *pCount);
GT_API GT_GetBindCounter(TVarInfo *pVarInfo,TBindCounter *pBindCounter,long *pUnitCount,long *pCount);
GT_API GT_GetBindFlank(TVarInfo *pVarInfo,TBindFlank *pBindFlank);
GT_API GT_GetBindSrff(TVarInfo *pVarInfo,TBindSrff *pBindSrff);

GT_API GTN_Compile(char *pFileName,TCompileInfo *pWrongInfo);
GT_API GTN_Download(short core,char *pFileName);
GT_API GTN_GetFunId(char *pFunName,short *pFunId);
GT_API GTN_GetVarId(char *pFunName,char *pVarName,TVarInfo *pVarInfo);
GT_API GTN_Bind(short core,short thread,short funId,short page);
GT_API GTN_RunThread(short core,short thread);
GT_API GTN_RunThreadPeriod(short core,short thread,short ms,short priority=4);
GT_API GTN_StepThread(short core,short thread);
GT_API GTN_StopThread(short core,short thread);
GT_API GTN_PauseThread(short core,short thread);
GT_API GTN_GetThreadSts(short core,short thread,TThreadSts *pThreadSts);
GT_API GTN_GetThreadTime(short core,short thread,short *pPeriod,double *pExecuteTime,double *pExecuteTimeMax);
GT_API GTN_SetVarValue(short core,short page,TVarInfo *pVarInfo,double *pValue,short count=1);
GT_API GTN_GetVarValue(short core,short page,TVarInfo *pVarInfo,double *pValue,short count=1);

GT_API GTN_UnbindVar(short core,short thread);
GT_API GTN_BindDi(short core,short thread,TVarInfo *pVarInfo,TBindDi *pBindDi);
GT_API GTN_BindDo(short core,short thread,TVarInfo *pVarInfo,TBindDo *pBindDo);
GT_API GTN_BindTimer(short core,short thread,TVarInfo *pVarInfo,TBindTimer *pBindTimer);
GT_API GTN_BindCounter(short core,short thread,TVarInfo *pVarInfo,TBindCounter *pBindCounter);
GT_API GTN_BindFlank(short core,short thread,TVarInfo *pVarInfo,TBindFlank *pBindFlank);
GT_API GTN_BindSrff(short core,short thread,TVarInfo *pVarInfo,TBindSrff *pBindSrff);

GT_API GTN_GetBindDi(short core,TVarInfo *pVarInfo,TBindDi *pBindDi);
GT_API GTN_GetBindDo(short core,TVarInfo *pVarInfo,TBindDo *pBindDo);
GT_API GTN_GetBindTimer(short core,TVarInfo *pVarInfo,TBindTimer *pBindTimer,long *pCount);
GT_API GTN_GetBindCounter(short core,TVarInfo *pVarInfo,TBindCounter *pBindCounter,long *pUnitCount,long *pCount);
GT_API GTN_GetBindFlank(short core,TVarInfo *pVarInfo,TBindFlank *pBindFlank);
GT_API GTN_GetBindSrff(short core,TVarInfo *pVarInfo,TBindSrff *pBindSrff);

GT_API GTN_GetBindDiCount(short core,short thread,short *pCount);
GT_API GTN_GetBindDoCount(short core,short thread,short *pCount);
GT_API GTN_GetBindTimerCount(short core,short thread,short *pCount);
GT_API GTN_GetBindCounterCount(short core,short thread,short *pCount);
GT_API GTN_GetBindFlankCount(short core,short thread,short *pCount);
GT_API GTN_GetBindSrffCount(short core,short thread,short *pCount);

GT_API GTN_GetBindDiInfo(short core,short thread,short index,short *pVar,TBindDi *pBindDi);
GT_API GTN_GetBindDoInfo(short core,short thread,short index,short *pVar,TBindDo *pBindDo);
GT_API GTN_GetBindTimerInfo(short core,short thread,short index,short *pVar,TBindTimer *pBindTimer);
GT_API GTN_GetBindCounterInfo(short core,short thread,short index,short *pVar,TBindCounter *pBindCounter);
GT_API GTN_GetBindFlankInfo(short core,short thread,short index,short *pVar,TBindFlank *pBindFlank);
GT_API GTN_GetBindSrffInfo(short core,short thread,short index,short *pVar,TBindSrff *pBindSrff);

typedef struct ThreadStatus
{
	short link;
	unsigned long  address;
	short size;
	unsigned long  page;
	short delay;
	short priority;
	short ptr;
	short status;
	short error;
	short result[4];
	short resultType;
	short breakpoint;
	short period;
	short count;
	short function;
} TThreadStatus;

GT_API GT_ClearPlc(void);
GT_API GT_LoadPlc(short id,short returnType);
GT_API GT_LoadPlcCommand(short id,short count,short *pData);
GT_API GT_StepThread(short thread);
GT_API GT_RunThreadToBreakpoint(short thread,short line);
GT_API GT_GetThread(short thread,TThreadStatus *pThread);

GT_API GTN_StepThread(short core,short thread);

/*-----------------------------------------------------------*/
/* Interpolation                                             */
/*-----------------------------------------------------------*/
#define INTERPOLATION_AXIS_MAX                   (8)

#define CRD_OPERATION_DATA_EXT_MAX               (2)


#define CRD_BUFFER_MODE_DYNAMIC_DEFAULT          (0)
#define CRD_BUFFER_MODE_DYNAMIC_KEEP             (1)

#define CRD_BUFFER_MODE_STATIC_INPUT             (11)
#define CRD_BUFFER_MODE_STATIC_READY             (12)
#define CRD_BUFFER_MODE_STATIC_START             (13)

#define INTERPOLATION_CIRCLE_PLAT_XY             (0)
#define INTERPOLATION_CIRCLE_PLAT_YZ             (1)
#define INTERPOLATION_CIRCLE_PLAT_ZX             (2)

#define INTERPOLATION_HELIX_CIRCLE_XY_LINE_Z     (0)
#define INTERPOLATION_HELIX_CIRCLE_YZ_LINE_X     (1)
#define INTERPOLATION_HELIX_CIRCLE_ZX_LINE_Y     (2)

#define INTERPOLATION_CIRCLE_DIR_CW              (0)
#define INTERPOLATION_CIRCLE_DIR_CCW             (1)

typedef struct CrdPrm
{
	short dimension;
	short profile[8];
	double synVelMax;
	double synAccMax;
	short evenTime;  
	short setOriginFlag; 
	long originPos[8];   
}TCrdPrm;

typedef struct CrdBufOperation
{
	short flag;              
	unsigned short delay;    
	short doType;            
	unsigned short doMask;   
	unsigned short doValue;  
	unsigned short dataExt[CRD_OPERATION_DATA_EXT_MAX];
}TCrdBufOperation;

typedef struct CrdData
{
	short motionType;              
	short circlePlat;              
	long pos[INTERPOLATION_AXIS_MAX];   
	double radius;                      
	short circleDir;                       
	double center[3];                           
	double vel;                                  
	double acc;                                  
	short velEndZero;                            
	TCrdBufOperation operation;                  

	double cos[INTERPOLATION_AXIS_MAX];           
	double velEnd;                                
	double velEndAdjust;                          
	double r;                                     
}TCrdData;

typedef struct  
{
	double time;
	long segmentUsed;
	long segmentHead;
	long segmentTail;
} TCrdTime;

typedef struct  
{
	short crdAxis;
	short masterIndex;
	short masterType;
} TBufFollowMaster;

typedef struct  
{
	long masterPos;
	long pad;
} TBufFollowEventCross;

typedef struct  
{
	short triggerIndex;
	long triggerOffset;
	long pad;
} TBufFollowEventTrigger;

typedef struct  
{
	double velRatioMax;
	double accRatioMax;
	long masterLead;
	long masterEven;
	long slaveEven;
	short dir;
	short smoothPercent;
	short synchAlign;
} TCrdFollowPrm;

typedef struct  
{
	short stage;
	double slavePos;
	double slaveVel;
	long masterFrameWidth;
	long masterFrameIndex;
	unsigned long loopCount;
} TCrdFollowStatus;

GT_API GT_SetCrdPrm(short crd,TCrdPrm *pCrdPrm);
GT_API GT_GetCrdPrm(short crd,TCrdPrm *pCrdPrm);
GT_API GT_CrdSpace(short crd,long *pSpace,short fifo=0);
GT_API GT_CrdData(short crd,TCrdData *pCrdData,short fifo=0);

GT_API GT_LnXY(short crd,long x,long y,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYOverride2(short crd,long x,long y,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYWN(short crd,long x,long y,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_LnXYOverride2WN(short crd,long x,long y,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_LnXYG0(short crd,long x,long y,double synVel,double synAcc,short fifo=0);
GT_API GT_LnXYG0Override2(short crd,long x,long y,double synVel,double synAcc,short fifo=0);
GT_API GT_LnXYG0WN(short crd,long x,long y,double synVel,double synAcc,long segNum=0,short fifo=0);
GT_API GT_LnXYG0Override2WN(short crd,long x,long y,double synVel,double synAcc,long segNum=0,short fifo=0);


GT_API GT_LnXYZ(short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYZOverride2(short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYZWN(short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_LnXYZOverride2WN(short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_LnXYZG0(short crd,long x,long y,long z,double synVel,double synAcc,short fifo=0);
GT_API GT_LnXYZG0Override2(short crd,long x,long y,long z,double synVel,double synAcc,short fifo=0);
GT_API GT_LnXYZG0WN(short crd,long x,long y,long z,double synVel,double synAcc,long segNum=0,short fifo=0);
GT_API GT_LnXYZG0Override2WN(short crd,long x,long y,long z,double synVel,double synAcc,long segNum=0,short fifo=0);

GT_API GT_LnXYZA(short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYZAOverride2(short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYZAWN(short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_LnXYZAOverride2WN(short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_LnXYZAG0(short crd,long x,long y,long z,long a,double synVel,double synAcc,short fifo=0);
GT_API GT_LnXYZAG0Override2(short crd,long x,long y,long z,long a,double synVel,double synAcc,short fifo=0);
GT_API GT_LnXYZAG0WN(short crd,long x,long y,long z,long a,double synVel,double synAcc,long segNum=0,short fifo=0);
GT_API GT_LnXYZAG0Override2WN(short crd,long x,long y,long z,long a,double synVel,double synAcc,long segNum=0,short fifo=0);

GT_API GT_LnXYZACUVW(short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYZACUVWWN(short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_LnXYZACUVWOverride2(short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_LnXYZACUVWOverride2WN(short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_ArcXYR(short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcXYROverride2(short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcXYRWN(short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcXYROverride2WN(short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_ArcXYC(short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcXYCOverride2(short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcXYCWN(short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcXYCOverride2WN(short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_ArcYZR(short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcYZROverride2(short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcYZRWN(short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcYZROverride2WN(short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_ArcYZC(short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcYZCOverride2(short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcYZCWN(short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcYZCOverride2WN(short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_ArcZXR(short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcZXROverride2(short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcZXRWN(short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcZXROverride2WN(short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_ArcZXC(short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcZXCOverride2(short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_ArcZXCWN(short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_ArcZXCOverride2WN(short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);


GT_API GT_ArcXYZ(short crd,long x,long y,long z,double interX,double interY,double interZ,double synVel,double synAcc,double velEnd,short fifo=0);
GT_API GT_ArcXYZWN(short crd,long x,long y,long z,double interX,double interY,double interZ,double synVel,double synAcc,double velEnd,long segNum,short fifo=0);
GT_API GT_ArcXYZOverride2WN(short crd,long x,long y,long z,double interX,double interY,double interZ,double synVel,double synAcc,double velEnd,long segNum,short fifo=0);


GT_API GT_HelixXYRZ(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd,short fifo=0);
GT_API GT_HelixXYRZOverride2(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixXYRZWN(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixXYRZOverride2WN(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_HelixXYCZ(short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixXYCZOverride2(short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixXYCZWN(short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixXYCZOverride2WN(short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_HelixYZRX(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixYZRXOverride2(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixYZRXWN(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixYZRXOverride2WN(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_HelixYZCX(short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixYZCXOverride2(short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixYZCXWN(short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixYZCXOverride2WN(short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_HelixZXRY(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixZXRYOverride2(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixZXRYWN(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixZXRYOverride2WN(short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_HelixZXCY(short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixZXCYOverride2(short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GT_HelixZXCYWN(short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GT_HelixZXCYOverride2WN(short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GT_BufIO(short crd,unsigned short doType,unsigned short doMask,unsigned short doValue,short fifo=0);
GT_API GT_BufDelay(short crd,unsigned short delayTime,short fifo=0);
GT_API GT_BufDA(short crd,short chn,short daValue,short fifo=0);
GT_API GT_BufLmtsOn(short crd,short axis,short limitType,short fifo=0);
GT_API GT_BufLmtsOff(short crd,short axis,short limitType,short fifo=0);
GT_API GT_BufSetStopIo(short crd,short axis,short stopType,short inputType,short inputIndex,short fifo=0);
GT_API GT_BufMove(short crd,short moveAxis,long pos,double vel,double acc,short modal,short fifo=0);
GT_API GT_BufGear(short crd,short gearAxis,long pos,short fifo=0);
GT_API GT_BufGearPercent(short crd,short gearAxis,long pos,short accPercent,short decPercent,short fifo=0);
GT_API GT_BufStopMotion(short crd,short fifo=0);
GT_API GT_BufSetVarValue(short crd,short pageId,TVarInfo *pVarInfo,double value,short fifo=0);
GT_API GT_BufJumpNextSeg(short crd,short axis,short limitType,short fifo=0);
GT_API GT_BufSynchPrfPos(short crd,short encoder,short profile,short fifo=0);
GT_API GT_BufVirtualToActual(short crd,short fifo=0);
GT_API GT_CrdStart(short mask,short option);
GT_API GT_CrdStartStep(short mask,short option);
GT_API GT_CrdStepMode(short mask,short option);
GT_API GT_SetOverride(short crd,double synVelRatio);
GT_API GT_SetOverride2(short crd,double synVelRatio);
GT_API GT_InitLookAhead(short crd,short fifo,double T,double accMax,short n,TCrdData *pLookAheadBuf);
GT_API GT_GetLookAheadSpace(short crd,long *pSpace,short fifo=0);
GT_API GT_GetLookAheadSegCount(short crd,long *pSegCount,short fifo=0);
GT_API GT_CrdClear(short crd,short fifo);
GT_API GT_CrdStatus(short crd,short *pRun,long *pSegment,short fifo=0);
GT_API GT_SetUserSegNum(short crd,long segNum,short fifo=0);
GT_API GT_GetUserSegNum(short crd,long *pSegment,short fifo=0);
GT_API GT_GetUserSegNumWN(short crd,long *pSegment,short fifo=0);
GT_API GT_GetRemainderSegNum(short crd,long *pSegment,short fifo=0);
GT_API GT_SetCrdStopDec(short crd,double decSmoothStop,double decAbruptStop);
GT_API GT_GetCrdStopDec(short crd,double *pDecSmoothStop,double *pDecAbruptStop);
GT_API GT_SetCrdLmtStopMode(short crd,short lmtStopMode);
GT_API GT_GetCrdLmtStopMode(short crd,short *pLmtStopMode);
GT_API GT_GetUserTargetVel(short crd,double *pTargetVel);
GT_API GT_GetSegTargetPos(short crd,long *pTargetPos);
GT_API GT_GetCrdPos(short crd,double *pPos);
GT_API GT_GetCrdVel(short crd,double *pSynVel);
GT_API GT_BufLaserOn(short crd,short fifo=0,short channel=0);
GT_API GT_BufLaserOff(short crd,short fifo=0,short channel=0);
GT_API GT_BufLaserPrfCmd(short crd,double laserPower,short fifo=0,short channel=0);

GT_API GT_SetG0Mode(short crd,short mode);
GT_API GT_GetG0Mode(short crd,short *pMode);

GT_API GT_SetCrdMapBase(short crd,short base);
GT_API GT_GetCrdMapBase(short crd,short *pBase);
GT_API GT_SetCrdBufferMode(short crd,  short bufferMode,short fifo=0);
GT_API GT_GetCrdBufferMode(short crd,short *pBufferMode,short fifo=0);
GT_API GT_GetCrdSegmentTime(short crd,long segmentIndex,double *pSegmentTime,long *pSegmentNumber,short fifo=0);
GT_API GT_GetCrdTime(short crd,TCrdTime *pTime,short fifo=0);

GT_API GT_BufFollowMaster(short crd,TBufFollowMaster *pBufFollowMaster,short fifo=0);
GT_API GT_BufFollowEventCross(short crd,TBufFollowEventCross *pEventCross,short fifo=0);
GT_API GT_BufFollowEventTrigger(short crd,TBufFollowEventTrigger *pEventTrigger,short fifo=0);
GT_API GT_BufFollowStart(short crd,long masterSegment,long slaveSegment,long masterFrameWidth,short fifo=0);
GT_API GT_BufFollowNext(short crd,long width,short fifo=0);
GT_API GT_BufFollowReturn(short crd,double vel,double acc,short smoothPercent,short fifo=0);
GT_API GT_BufLaserFollowMode(short crd,short source,short fifo,short channel,double startPower=0);
GT_API GT_BufLaserFollowRatio(short crd,double ratio,double minPower,double maxPower,short fifo,short channel);
GT_API GT_BufLaserFollowOff(short crd,short fifo,short channel);
GT_API GT_BufLaserFollowSpline(short crd,short tableId,double minPower,double maxPower,short fifo,short channel);
GT_API GT_BufLaserFollowTable(short crd,short tableId,double minPower,double maxPower,short fifo,short channel);


GT_API GTN_SetCrdPrm(short core,short crd,TCrdPrm *pCrdPrm);
GT_API GTN_GetCrdPrm(short core,short crd,TCrdPrm *pCrdPrm);
GT_API GTN_CrdSpace(short core,short crd,long *pSpace,short fifo=0);
GT_API GTN_CrdData(short core,short crd,TCrdData *pCrdData,short fifo=0);

GT_API GTN_LnXY(short core,short crd,long x,long y,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_LnXYOverride2(short core,short crd,long x,long y,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_LnXYWN(short core,short crd,long x,long y,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_LnXYOverride2WN(short core,short crd,long x,long y,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_LnXYG0(short core,short crd,long x,long y,double synVel,double synAcc,short fifo=0);
GT_API GTN_LnXYG0Override2(short core,short crd,long x,long y,double synVel,double synAcc,short fifo=0);
GT_API GTN_LnXYG0WN(short core,short crd,long x,long y,double synVel,double synAcc,long segNum=0,short fifo=0);
GT_API GTN_LnXYG0Override2WN(short core,short crd,long x,long y,double synVel,double synAcc,long segNum=0,short fifo=0);

GT_API GTN_LnXYZ(short core,short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_LnXYZOverride2(short core,short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_LnXYZWN(short core,short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_LnXYZOverride2WN(short core,short crd,long x,long y,long z,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_LnXYZG0(short core,short crd,long x,long y,long z,double synVel,double synAcc,short fifo=0);
GT_API GTN_LnXYZG0Override2(short core,short crd,long x,long y,long z,double synVel,double synAcc,short fifo=0);
GT_API GTN_LnXYZG0WN(short core,short crd,long x,long y,long z,double synVel,double synAcc,long segNum=0,short fifo=0);
GT_API GTN_LnXYZG0Override2WN(short core,short crd,long x,long y,long z,double synVel,double synAcc,long segNum=0,short fifo=0);

GT_API GTN_LnXYZA(short core,short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_LnXYZAOverride2(short core,short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_LnXYZAWN(short core,short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_LnXYZAOverride2WN(short core,short crd,long x,long y,long z,long a,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_LnXYZAG0(short core,short crd,long x,long y,long z,long a,double synVel,double synAcc,short fifo=0);
GT_API GTN_LnXYZAG0Override2(short core,short crd,long x,long y,long z,long a,double synVel,double synAcc,short fifo=0);
GT_API GTN_LnXYZAG0WN(short core,short crd,long x,long y,long z,long a,double synVel,double synAcc,long segNum=0,short fifo=0);
GT_API GTN_LnXYZAG0Override2WN(short core,short crd,long x,long y,long z,long a,double synVel,double synAcc,long segNum=0,short fifo=0);

GT_API GTN_LnXYZACUVW(short core,short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_LnXYZACUVWOverride2(short core,short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_LnXYZACUVWWN(short core,short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_LnXYZACUVWOverride2WN(short core,short crd,long *pPos,short posMask,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_ArcXYR(short core,short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcXYROverride2(short core,short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcXYRWN(short core,short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_ArcXYROverride2WN(short core,short crd,long x,long y,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_ArcXYC(short core,short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcXYCOverride2(short core,short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcXYCWN(short core,short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_ArcXYCOverride2WN(short core,short crd,long x,long y,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_ArcYZR(short core,short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcYZROverride2(short core,short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcYZRWN(short core,short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_ArcYZROverride2WN(short core,short crd,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_ArcYZC(short core,short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcYZCOverride2(short core,short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcYZCWN(short core,short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_ArcYZCOverride2WN(short core,short crd,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_ArcZXR(short core,short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcZXROverride2(short core,short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcZXRWN(short core,short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_ArcZXROverride2WN(short core,short crd,long z,long x,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_ArcZXC(short core,short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcZXCOverride2(short core,short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_ArcZXCWN(short core,short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_ArcZXCOverride2WN(short core,short crd,long z,long x,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_HelixXYRZ(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd,short fifo=0);
GT_API GTN_HelixXYRZOverride2(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixXYRZWN(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_HelixXYRZOverride2WN(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_HelixXYCZ(short core,short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixXYCZOverride2(short core,short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixXYCZWN(short core,short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_HelixXYCZOverride2WN(short core,short crd,long x,long y,long z,double xCenter,double yCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_HelixYZRX(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixYZRXOverride2(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixYZRXWN(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_HelixYZRXOverride2WN(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_HelixYZCX(short core,short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixYZCXOverride2(short core,short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixYZCXWN(short core,short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_HelixYZCXOverride2WN(short core,short crd,long x,long y,long z,double yCenter,double zCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_HelixZXRY(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixZXRYOverride2(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixZXRYWN(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_HelixZXRYOverride2WN(short core,short crd,long x,long y,long z,double radius,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_HelixZXCY(short core,short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixZXCYOverride2(short core,short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,short fifo=0);
GT_API GTN_HelixZXCYWN(short core,short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);
GT_API GTN_HelixZXCYOverride2WN(short core,short crd,long x,long y,long z,double zCenter,double xCenter,short circleDir,double synVel,double synAcc,double velEnd=0,long segNum=0,short fifo=0);

GT_API GTN_BufIO(short core,short crd,unsigned short doType,unsigned short doMask,unsigned short doValue,short fifo=0);
GT_API GTN_BufDelay(short core,short crd,unsigned short delayTime,short fifo=0);
GT_API GTN_BufDA(short core,short crd,short chn,short daValue,short fifo=0);
GT_API GTN_BufLmtsOn(short core,short crd,short axis,short limitType,short fifo=0);
GT_API GTN_BufLmtsOff(short core,short crd,short axis,short limitType,short fifo=0);
GT_API GTN_BufSetStopIo(short core,short crd,short axis,short stopType,short inputType,short inputIndex,short fifo=0);
GT_API GTN_BufMove(short core,short crd,short moveAxis,long pos,double vel,double acc,short modal,short fifo=0);
GT_API GTN_BufGear(short core,short crd,short gearAxis,long pos,short fifo=0);
GT_API GTN_BufGearPercent(short core,short crd,short gearAxis,long pos,short accPercent,short decPercent,short fifo=0);
GT_API GTN_BufStopMotion(short core,short crd,short fifo=0);
GT_API GTN_BufSetVarValue(short core,short crd,short pageId,TVarInfo *pVarInfo,double value,short fifo=0);
GT_API GTN_BufJumpNextSeg(short core,short crd,short axis,short limitType,short fifo=0);
GT_API GTN_BufSynchPrfPos(short core,short crd,short encoder,short profile,short fifo=0);
GT_API GTN_BufVirtualToActual(short core,short crd,short fifo=0);
GT_API GTN_BufEnableDoBitPulse(short core,short crd,short doType,short doIndex,unsigned short highLevelTime,unsigned short lowLevelTime,long pulseNum,short firstLevel,short fifo);
GT_API GTN_BufDisableDoBitPulse(short core,short crd,short doType,short doIndex,short fifo);

GT_API GTN_CrdStart(short core,short mask,short option);
GT_API GTN_CrdStartStep(short core,short mask,short option);
GT_API GTN_CrdStepMode(short core,short mask,short option);
GT_API GTN_SetOverride(short core,short crd,double synVelRatio);
GT_API GTN_SetOverride2(short core,short crd,double synVelRatio);
GT_API GTN_InitLookAhead(short core,short crd,short fifo,double T,double accMax,short n,TCrdData *pLookAheadBuf);
GT_API GTN_GetLookAheadSpace(short core,short crd,long *pSpace,short fifo=0);
GT_API GTN_GetLookAheadSegCount(short core,short crd,long *pSegCount,short fifo=0);
GT_API GTN_CrdClear(short core,short crd,short fifo);
GT_API GTN_CrdStatus(short core,short crd,short *pRun,long *pSegment,short fifo=0);
GT_API GTN_SetUserSegNum(short core,short crd,long segNum,short fifo=0);
GT_API GTN_GetUserSegNum(short core,short crd,long *pSegment,short fifo=0);
GT_API GTN_GetUserSegNumWN(short core,short crd,long *pSegment,short fifo=0);
GT_API GTN_GetRemainderSegNum(short core,short crd,long *pSegment,short fifo=0);
GT_API GTN_SetCrdStopDec(short core,short crd,double decSmoothStop,double decAbruptStop);
GT_API GTN_GetCrdStopDec(short core,short crd,double *pDecSmoothStop,double *pDecAbruptStop);
GT_API GTN_SetCrdLmtStopMode(short core,short crd,short lmtStopMode);
GT_API GTN_GetCrdLmtStopMode(short core,short crd,short *pLmtStopMode);
GT_API GTN_GetUserTargetVel(short core,short crd,double *pTargetVel);
GT_API GTN_GetSegTargetPos(short core,short crd,long *pTargetPos);
GT_API GTN_GetCrdPos(short core,short crd,double *pPos);
GT_API GTN_GetCrdVel(short core,short crd,double *pSynVel);
GT_API GTN_BufLaserOn(short core,short crd,short fifo=0,short channel=0);
GT_API GTN_BufLaserOff(short core,short crd,short fifo=0,short channel=0);
GT_API GTN_BufLaserPrfCmd(short core,short crd,double laserPower,short fifo=0,short channel=0);

GT_API GTN_BufLaserFollowMode(short core,short crd,short source,short fifo,short channel,double startPower);
GT_API GTN_BufLaserFollowRatio(short core,short crd,double ratio,double minPower,double maxPower,short fifo,short channel);
GT_API GTN_BufLaserFollowOff(short core,short crd,short fifo,short channel);
GT_API GTN_BufLaserFollowSpline(short core,short crd,short tableId,double minPower,double maxPower,short fifo,short channel);
GT_API GTN_BufLaserFollowTable(short core,short crd,short tableId,double minPower,double maxPower,short fifo,short channel);

GT_API GTN_BufFollowMaster(short core,short crd,TBufFollowMaster *pBufFollowMaster,short fifo=0);
GT_API GTN_BufFollowEventCross(short core,short crd,TBufFollowEventCross *pEventCross,short fifo=0);
GT_API GTN_BufFollowEventTrigger(short core,short crd,TBufFollowEventTrigger *pEventTrigger,short fifo=0);
GT_API GTN_BufFollowStart(short core,short crd,long masterSegment,long slaveSegment,long masterFrameWidth,short fifo=0);
GT_API GTN_BufFollowNext(short core,short crd,long width,short fifo=0);
GT_API GTN_BufFollowReturn(short core,short crd,double vel,double acc,short smoothPercent,short fifo=0);

GT_API GTN_SetG0Mode(short core,short crd,short mode);
GT_API GTN_GetG0Mode(short core,short crd,short *pMode);

GT_API GTN_SetCrdMapBase(short core,short crd,short base);
GT_API GTN_GetCrdMapBase(short core,short crd,short *pBase);
GT_API GTN_SetCrdBufferMode(short core,short crd,  short bufferMode,short fifo=0);
GT_API GTN_GetCrdBufferMode(short core,short crd,short *pBufferMode,short fifo=0);
GT_API GTN_GetCrdSegmentTime(short core,short crd,long segmentIndex,double *pSegmentTime,long *pSegmentNumber,short fifo=0);
GT_API GTN_GetCrdTime(short core,short crd,TCrdTime *pTime,short fifo=0);

GT_API GT_GetCmdCount(short crd,short *pResult,short fifo);


/*-----------------------------------------------------------*/
/* Compensate                                                */
/*-----------------------------------------------------------*/
GT_API GT_SetBacklash(short axis,long value,double changeValue,long dir);
GT_API GT_GetBacklash(short axis,long *pValue,double *pChangeValue,long *pDir);
GT_API GT_SetLeadScrewComp(short axis,short n,long startPos,long lenPos,long *pPositive,long *pNegative);
GT_API GT_EnableLeadScrewComp(short axis,short mode);
GT_API GT_SetLeadScrewCrossComp(short axis,short n,long startPos,long lenPos,long *pPositive,long *pNegative,short link);
GT_API GT_EnableLeadScrewCrossComp(short axis,short mode);
GT_API GT_GetCompensate(short axis,double *pPitchError,double *pCrossError,double *pBacklashError,double *pEncPos,double *pPrfPos);

GT_API GTN_SetBacklash(short core,short axis,long value,double changeValue,long dir);
GT_API GTN_GetBacklash(short core,short axis,long *pValue,double *pChangeValue,long *pDir);
GT_API GTN_SetLeadScrewComp(short core,short axis,short n,long startPos,long lenPos,long *pPositive,long *pNegative);
GT_API GTN_EnableLeadScrewComp(short core,short axis,short mode);
GT_API GTN_SetLeadScrewCrossComp(short core,short axis,short n,long startPos,long lenPos,long *pPositive,long *pNegative,short link);
GT_API GTN_EnableLeadScrewCrossComp(short core,short axis,short mode);
GT_API GTN_GetCompensate(short core,short axis,double *pPitchError,double *pCrossError,double *pBacklashError,double *pEncPos,double *pPrfPos);


typedef struct
{
	short n;
	long startPos;
	long lenPos;
	long *pCompPos;
	long *pCompNeg;
} TLeadScrewPrm;

GT_API GT_SetLeadScrewTable(short axis,TLeadScrewPrm *pPrm);
GT_API GT_EnableLeadScrewTable(short axis,long error=0);
GT_API GT_DisableLeadScrewTable(short axis);
GT_API GT_GetLeadScrewTablePrfPosCount(long encPos,TLeadScrewPrm *pPrm,short *pCountPositive,short *pCountNegative);
GT_API GT_GetLeadScrewTablePrfPosPositive(long encPos,TLeadScrewPrm *pPrm,short index,long *pPrfPosPositive);
GT_API GT_GetLeadScrewTablePrfPosNegative(long encPos,TLeadScrewPrm *pPrm,short index,long *pPrfPosNegative);

GT_API GTN_SetLeadScrewTable(short core,short axis,TLeadScrewPrm *pPrm);
GT_API GTN_EnableLeadScrewTable(short core,short axis,long error=0);
GT_API GTN_DisableLeadScrewTable(short core,short axis);
GT_API GTN_GetLeadScrewTablePrfPosCount(short core,long encPos,TLeadScrewPrm *pPrm,short *pCountPositive,short *pCountNegative);
GT_API GTN_GetLeadScrewTablePrfPosPositive(short core,long encPos,TLeadScrewPrm *pPrm,short index,long *pPrfPosPositive);
GT_API GTN_GetLeadScrewTablePrfPosNegative(short core,long encPos,TLeadScrewPrm *pPrm,short index,long *pPrfPosNegative);

typedef struct
{
	short count[2];                               
	long posBegin[2];                           
	long step[2];                               
} TCompensate2DTable;

typedef struct
{
	short enable;                                  
	short tableIndex;                              
	short axisType[2];                             
	short axisIndex[2];                            
} TCompensate2D;

GT_API GT_SetCompensate2DTable(short tableIndex,TCompensate2DTable *pTable,long *pData,short extend);
GT_API GT_GetCompensate2DTable(short tableIndex,TCompensate2DTable *pTable,short *pExtend);
GT_API GT_SetCompensate2D(short axis,TCompensate2D *pComp2d);
GT_API GT_GetCompensate2D(short axis,TCompensate2D *pComp2d);
GT_API GT_GetCompensate2DValue(short axis,double *pValue);

GT_API GTN_SetCompensate2DTable(short core,short tableIndex,TCompensate2DTable *pTable,long *pData,short extend);
GT_API GTN_GetCompensate2DTable(short core,short tableIndex,TCompensate2DTable *pTable,short *pExtend);
GT_API GTN_SetCompensate2D(short core,short axis,TCompensate2D *pComp2d);
GT_API GTN_GetCompensate2D(short core,short axis,TCompensate2D *pComp2d);
GT_API GTN_GetCompensate2DValue(short core,short axis,double *pValue);

/*-----------------------------------------------------------*/
/* IO and Encoder                                            */
/*-----------------------------------------------------------*/
GT_API GT_SetDo(short doType,long value);
GT_API GT_SetDoBit(short doType,short doIndex,short value);
GT_API GT_GetDo(short doType,long *pValue);
GT_API GT_SetDoBitReverse(short doType,short doIndex,short value,short reverseTime);
GT_API GT_GetDi(short diType,long *pValue);
GT_API GT_GetDiReverseCount(short diType,short diIndex,unsigned long *pReverseCount,short count=1);
GT_API GT_SetDiReverseCount(short diType,short diIndex,unsigned long *pReverseCount,short count=1);
GT_API GT_GetDiRaw(short diType,long *pValue);
GT_API GT_GetDiEx(short diType,long *pValue,short count);

GT_API GT_SetDac(short dac,short *pValue,short count=1);
GT_API GT_GetDac(short dac,short *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAdc(short adc,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAdcValue(short adc,short *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAuAdc(short adc,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAuAdcValue(short adc,short *pValue,short count=1,unsigned long *pClock=NULL);

GT_API GT_SetEncPos(short encoder,long encPos);
GT_API GT_GetEncPos(short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetEncPosPre(short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetEncVel(short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);

GT_API GT_SetPlsPos(short encoder,long encPos);
GT_API GT_GetPlsPos(short pulse,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetPlsVel(short pulse,double *pValue,short count=1,unsigned long *pClock=NULL);

GT_API GT_SetAuEncPos(short encoder,long encPos);
GT_API GT_GetAuEncPos(short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GT_GetAuEncVel(short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);


GT_API GTN_SetDo(short core,short doType,long value);
GT_API GTN_SetDoEx(short core,short doType,long *pValue,short count);
GT_API GTN_SetDoBit(short core,short doType,short doIndex,short value);
GT_API GTN_GetDo(short core,short doType,long *pValue);
GT_API GTN_GetDoEx(short core,short doType,long *pValue,short count);
GT_API GTN_SetDoBitReverse(short core,short doType,short doIndex,short value,short reverseTime);
GT_API GTN_EnableDoBitPulse(short core,short doType,short doIndex,unsigned short highLevelTime,unsigned short lowLevelTime,long pulseNum,short firstLevel);
GT_API GTN_DisableDoBitPulse(short core,short doType,short doIndex);
GT_API GTN_GetDi(short core,short diType,long *pValue);
GT_API GTN_GetDiReverseCount(short core,short diType,short diIndex,unsigned long *pReverseCount,short count=1);
GT_API GTN_SetDiReverseCount(short core,short diType,short diIndex,unsigned long *pReverseCount,short count=1);
GT_API GTN_GetDiRaw(short core,short diType,long *pValue);
GT_API GTN_GetDiEx(short core,short diType,long *pValue,short count);

GT_API GTN_WriteAo(short core,long aoType,short aoIndex,double *pValue,short count =1);
GT_API GTN_SetDac(short core,short dac,short *pValue,short count=1);
GT_API GTN_GetDac(short core,short dac,short *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_SetAuDac(short core,short dac,short *pValue,short count=1);
GT_API GTN_GetAuDac(short core,short dac,short *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAdc(short core,short adc,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAdcValue(short core,short adc,short *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAuAdc(short core,short adc,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAuAdcValue(short core,short adc,short *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetEncLineNum(short core,short encoder,long *pLineNum,short count,unsigned long *pClock);
GT_API GTN_GetEncType(short core,short encoder,short *pType,short count,unsigned long *pClock);
GT_API GTN_SetEncPos(short core,short encoder,long encPos);
GT_API GTN_GetEncPos(short core,short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetEncPosPre(short core,short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetEncVel(short core,short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);

GT_API GTN_SetPlsPos(short core,short encoder,long encPos);
GT_API GTN_GetPlsPos(short core,short pulse,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetPlsVel(short core,short pulse,double *pValue,short count=1,unsigned long *pClock=NULL);

GT_API GTN_SetAuEncPos(short core,short encoder,long encPos);
GT_API GTN_GetAuEncPos(short core,short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);
GT_API GTN_GetAuEncVel(short core,short encoder,double *pValue,short count=1,unsigned long *pClock=NULL);

GT_API GTN_GetAbsEncPos(short core,short encoder,long *pValue,short mode=0,short param=0);

/*-----------------------------------------------------------*/
/* ExtModule                                                 */
/*-----------------------------------------------------------*/
GT_API GTN_ExtModuleInit(short core,short method=1);
GT_API GTN_SetILinkManuMode(short core,short station);
GT_API GTN_GetILinkManuId(short core,short station,short autoId,short *manuId);
GT_API GTN_GetILinkAutoId(short core,short station,short manuId,short *autoId);
GT_API GTN_SetExtDoBit(short core,short doIndex,short value);
GT_API GTN_GetExtDoBit(short core,short doIndex,short *pValue);
GT_API GTN_SetExtDo(short core,short doIndex,long value,long mask);
GT_API GTN_GetExtDo(short core,short doIndex,long *pValue);
GT_API GTN_GetExtDi(short core,short diIndex,long *pValue);
GT_API GTN_SetExtAoValue(short core,short index,short *pValue,short count=1);
GT_API GTN_GetExtAiValue(short core,short index,short *pValue,short count=1);
GT_API GTN_SetExtAo(short core,short index,double *pValue,short count=1);
GT_API GTN_GetExtAo(short core,short index,double *pValue,short count=1);
GT_API GTN_GetExtAi(short core,short index,double *pValue,short count=1);

GT_API GTN_SetILinkDo(short core,short station,short module,unsigned short data,unsigned short mask);
GT_API GTN_GetILinkDi(short core,short station,short module,unsigned short *data);
GT_API GTN_SetILinkAo(short core,short station,short module,short channel,double data);
GT_API GTN_GetILinkAi(short core,short station,short module,short channel,double *data);

/*-----------------------------------------------------------*/
/* Pos Compare                                               */
/*-----------------------------------------------------------*/
#define POS_COMPARE_MODE_FIFO         (0)
#define POS_COMPARE_MODE_LINEAR       (1)
#define POS_COMPARE_MODE_EQUIDISTANT         (2)

#define POS_COMPARE_OUTPUT_PULSE      (0)
#define POS_COMPARE_OUTPUT_LEVEL      (1)

#define POS_COMPARE_SOURCE_ENCODER    (0)
#define POS_COMPARE_SOURCE_PULSE      (1)


typedef struct
{
	short mode;                       
	short dimension;                  
	short sourceMode;                 
	short sourceX;                    
	short sourceY;                    
	short outputMode;                 
	short outputCounter;              
	unsigned short outputPulseWidth;  
	unsigned short errorBand;         
} TPosCompareMode;

typedef struct
{
	unsigned long count;
	unsigned short hso;
	unsigned short gpo;

	long startPos;
	long interval;
} TPosCompareLinear;

typedef struct
{
	unsigned long count;
	unsigned short hso;
	unsigned short gpo;

	long startPosX;
	long startPosY;
	long intervalX;
	long intervalY;
} TPosCompareLinear2D;


typedef struct
{
	long pos;
	unsigned short hso;
	unsigned short gpo;
	unsigned long segmentNumber;
} TPosCompareData;

typedef struct
{
	long posX;
	long posY;
	unsigned short hso;
	unsigned short gpo;
	unsigned long segmentNumber;
} TPosCompareData2D;

typedef struct
{
	unsigned short mode;      
	unsigned short run;
	unsigned short space;
	unsigned long pulseCount;
	unsigned short hso;
	unsigned short gpo;
	unsigned long segmentNumber;
} TPosCompareStatus;

typedef struct
{
	unsigned short config;
	unsigned short fifoEmpty;
	unsigned short head;
	unsigned short tail;
	unsigned long commandReceive;
	unsigned long commandSend;
	long posX;
	long posY;
} TPosCompareInfo;

typedef struct
{
	unsigned long count;
	unsigned short hso;
	unsigned short gpo;
	long startPosX;
	long startPosY;
	long syncPos;
	long time;
	short reserve[20];
} TPosComparePsoPrm;


typedef struct
{
	short mode;                      
	unsigned short count;            
	short highLevel;
	short lowLevel;
	short resver[20];
} TPosCompareContinueMode;

GT_API GT_PosCompareStart(short core,short index);
GT_API GT_PosCompareStop(short core,short index);
GT_API GT_PosCompareClear(short core,short index);
GT_API GT_PosCompareStatus(short core,short index,TPosCompareStatus *pStatus);
GT_API GT_PosCompareData(short core,short index,TPosCompareData *pData);
GT_API GT_PosCompareData2D(short core,short index,TPosCompareData2D *pData);
GT_API GT_SetPosCompareMode(short core,short index,TPosCompareMode *pMode);
GT_API GT_GetPosCompareMode(short core,short index,TPosCompareMode *pMode);
GT_API GT_SetPosCompareLinear(short core,short index,TPosCompareLinear *pLinear);
GT_API GT_GetPosCompareLinear(short core,short index,TPosCompareLinear *pLinear);
GT_API GT_SetPosCompareLinear2D(short core,short index,TPosCompareLinear2D *pLinear);
GT_API GT_GetPosCompareLinear2D(short core,short index,TPosCompareLinear2D *pLinear);
GT_API GT_PosCompareInfo(short core,short index,TPosCompareInfo *pInfo);
GT_API GT_SetPosComparePsoPrm(short core,short index,TPosComparePsoPrm *pPrm);
GT_API GT_GetPosComparePsoPrm(short core,short index,TPosComparePsoPrm *pPrm);

GT_API GTN_PosCompareStart(short core,short index);
GT_API GTN_PosCompareStop(short core,short index);
GT_API GTN_PosCompareClear(short core,short index);
GT_API GTN_PosCompareStatus(short core,short index,TPosCompareStatus *pStatus);
GT_API GTN_PosCompareData(short core,short index,TPosCompareData *pData);
GT_API GTN_PosCompareData2D(short core,short index,TPosCompareData2D *pData);
GT_API GTN_SetPosCompareMode(short core,short index,TPosCompareMode *pMode);
GT_API GTN_GetPosCompareMode(short core,short index,TPosCompareMode *pMode);
GT_API GTN_SetPosCompareContinueMode(short core,short index,TPosCompareContinueMode *pMode);
GT_API GTN_GetPosCompareContinueMode(short core,short index,TPosCompareContinueMode *pMode);
GT_API GTN_SetPosCompareLinear(short core,short index,TPosCompareLinear *pLinear);
GT_API GTN_GetPosCompareLinear(short core,short index,TPosCompareLinear *pLinear);
GT_API GTN_SetPosCompareLinear2D(short core,short index,TPosCompareLinear2D *pLinear);
GT_API GTN_GetPosCompareLinear2D(short core,short index,TPosCompareLinear2D *pLinear);
GT_API GTN_PosCompareInfo(short core,short index,TPosCompareInfo *pInfo);
GT_API GTN_PosCompareHsOn(short core,short index,short link,unsigned short threshold);
GT_API GTN_PosCompareHsOff(short core,short index);
GT_API GTN_PosCompareSpace(short core,short index,unsigned short *pSpace);
GT_API GTN_SetPosComparePsoPrm(short core,short index,TPosComparePsoPrm *pPrm);
GT_API GTN_GetPosComparePsoPrm(short core,short index,TPosComparePsoPrm *pPrm);
GT_API GTN_SetPosCompareStartLevel(short core,short index,short type,short startLevel);

#define COMPARE_SEND_DATA_MAX			(30)			        
#define COMPARE_DATA_MAX				(4096)		            
#define COMPARE_STEP_MAX				(0x1fff)		        
#define COMPARE_MAX_NUM					(0x3fffffff)


/*-----------------------------------------------------------*/
/* Laser and Scan                                            */
/*-----------------------------------------------------------*/
#define FIFO_MODE_STATIC                  (0)
#define FIFO_MODE_DYNAMIC                 (1)

#define SCAN_STATUS_WAIT                  (0)
#define SCAN_STATUS_RUN	                  (1)
#define SCAN_STATUS_DONE                  (2)

struct TScanInit
{
	int lookAheadNum;            
	double time;                  
	double radiusRatio;           
};

typedef struct
{
	unsigned long segmentNumber;
	unsigned short commandNumber;
	unsigned short prfVel;
	unsigned short fifoEmpty;
	unsigned short head;
	unsigned short tail;
	unsigned long commandReceive;
	unsigned long commandSend;
	unsigned long reserve[6];
} TScanInfo;

typedef struct 
{
	short enable;
	short superposeSrc;
	short superposeAxisX;
	short superposeAxisY;
	double xCoefficient;
	double yCoefficient;
}TScanPosSuperposeParameter;

typedef struct
{
	unsigned short hso;
	unsigned short powerMode;
	unsigned short power;
	unsigned short powerMax;
	unsigned short powerMin;
	unsigned short frequency;
	unsigned short pulseWidth;
} TLaserInfo;

typedef struct
{
	short n;
	double startVel;
	double power;
}TLaserPowerPrm;

typedef struct
{
	short n;
	double startVel;
	double velStep;
	double *power;
}TLaserPowerTable;

typedef struct
{
	short corrX[65][65];
	short corrY[65][65];
}TScanCorrectionTableData;


GT_API GT_LaserAo(short value,unsigned short laserChannel=0);
GT_API GT_SetHSIOOpt(unsigned short value,short channel=0);
GT_API GT_GetHSIOOpt(unsigned short *pValue,short channel=0);
GT_API GT_SetLaserMode(unsigned short laserMode);
GT_API GT_LaserPowerMode(short laserPowerMode,double maxValue,double minValue,short laserChannel=0,short delayMode=1);
GT_API GT_LaserPrfCmd(double power,unsigned short laserChannel=0);
GT_API GT_LaserOutFrq(double outFrq,unsigned short laserChannel=0);
GT_API GT_SetPulseWidth(unsigned short width,unsigned short laserChannel=0);
GT_API GT_SetLevelDelay(unsigned short highLevelDelay,unsigned short lowLevelDelay,unsigned short laserChannel=0);
GT_API GT_LaserInfo(TLaserInfo *pLaserInfo,short crd=0);

GT_API GTN_ScanInit(short core,TScanInit *pScanInit=NULL,double jumpAcc=0,double markAcc=0,short scan=1);
GT_API GTN_ScanCrdDataEnd(short core,short scan=1);
GT_API GTN_SetScanLaserLink(short core,short link,short scan=1);
GT_API GTN_GetScanLaserLink(short core,short *pLink,short scan=1);
GT_API GTN_SetScanMode(short core,short mode,short scan=1);
GT_API GTN_GetScanMode(short core,short *pMode,short scan=1);
GT_API GTN_ClearScanStatus(short core,short scan=1);
GT_API GTN_ScanGetCrdPos(short core,short *pPos,short scan=1);
GT_API GTN_ScanJump(short core,short x,short y,double vel,short scan=1);
GT_API GTN_ScanJumpPoint(short core,short x,short y,double vel,long motionDelayTime,long laserDelayTime,short scan=1);
GT_API GTN_ScanTimeJump(short core,short x,short y,unsigned short time,short scan=1);
GT_API GTN_ScanTimeJumpPoint(short core,short x,short y,unsigned short time,long motionDelayTime,long laserDelayTime,short scan=1);
GT_API GTN_ScanMark(short core,short x,short y,double vel,short scan=1);
GT_API GTN_ScanTimeMark(short core,short x,short y,unsigned short time,short scan=1);
GT_API GTN_ScanBufLaserPrfCmd(short core,double laserPower,short scan=1);
GT_API GTN_ScanBufIO(short core,unsigned short doType,unsigned short doMask,unsigned short doValue,short scan=1);
GT_API GTN_ScanBufDelay(short core,long time,short scan=1);
GT_API GTN_ScanBufDA(short core,unsigned short chn,short value,short scan=1);
GT_API GTN_ScanBufAO(short core,unsigned short chn,double voltage,short scan=1);
GT_API GTN_ScanBufLaserDelay(short core,short laserOnDelay,short laserOffDelay,short scan=1);
GT_API GTN_ScanBufLaserOutFrq(short core,double outFrq,short scan=1);
GT_API GTN_ScanBufSetPulseWidth(short core,unsigned short width,short scan=1);
GT_API GTN_ScanBufLaserOn(short core,short scan=1);
GT_API GTN_ScanBufLaserOff(short core,short scan=1);
GT_API GTN_ScanBufStop(short core,short scan=1);
GT_API GTN_ScanLaserIntervalOnList(short core,long time,short scan=1);
GT_API GTN_SetScanDelayTime(short core,unsigned short maxJumpDelay,unsigned short markDelay,unsigned short multiMarkDelayConst,short scan=1);
GT_API GTN_SetScanDelayMode(short core,short multiMarkDelayMode,unsigned short multiMarkLaserOffDelay,unsigned short minJumpDelay,unsigned short jumpDelayLengthLimit,short scan=1);
GT_API GTN_ScanStop(short core,short stopType,short scan=1);
GT_API GTN_ScanCrdSpace(short core,short *pSpace,short scan=1);
GT_API GTN_ScanCrdStart(short core,short scan=1);
GT_API GTN_ScanCrdClear(short core,short scan=1);
GT_API GTN_ScanCrdStatus(short core,short *pRun,short *pCmdId,short scan=1);

GT_API GTN_SetScanPosSuperposeParameter(short core,short crd,TScanPosSuperposeParameter param);
GT_API GTN_ScanSetCorrectionTable(short core,short crd,TScanCorrectionTableData *pParam);;
GT_API GTN_ScanCorrectionOn(short core,short scan);
GT_API GTN_ScanCorrectionOff(short core,short scan);
GT_API GTN_ScanGenerateCorrectionTable(short core,double paraX,double paraY,short rangeX,short rangeY,TScanCorrectionTableData *pParam);

GT_API GTN_LaserOn(short core,short channel=0);
GT_API GTN_LaserOff(short core,short channel=0);
GT_API GTN_LaserOnStatus(short core,unsigned short *pValue,short channel=0);
GT_API GTN_LaserPowerMode(short core,short laserPowerMode,double maxValue,double minValue,short channel=0);
GT_API GTN_LaserPrfCmd(short core,double power,short channel=0);
GT_API GTN_LaserOutFrq(short core,double outFrq,short channel=0);
GT_API GTN_SetPulseWidth(short core,unsigned short width,short channel=0);
GT_API GTN_SetLevelDelay(short core,unsigned long highLevelDelay,unsigned long lowLevelDelay,short channel=0);
GT_API GTN_LaserInfo(short core,TLaserInfo *pLaserInfo,short channel=0);


GT_API GTN_ScanInfo(short core,TScanInfo *pScanInfo,short crd=1);
GT_API GTN_ScanHsOn(short core,short crd=1,short link=1,unsigned short threshold=200);
GT_API GTN_ScanHsOff(short core,short crd=1);

GT_API GTN_ScanLaserOn(short core,short scan=1);
GT_API GTN_ScanLaserOff(short core,short scan=1);
GT_API GTN_ScanLaserOnStatus(short core,unsigned short *pValue,short scan=1);
GT_API GTN_ScanSetLaserMode(short core,unsigned short laserMode, short scan=1);
GT_API GTN_ScanLaserPowerMode(short core,short laserPowerMode,double maxValue,double minValue, short scan=1);
GT_API GTN_ScanLaserPrfCmd(short core,double power, short scan=1);
GT_API GTN_ScanLaserOutFrq(short core,double outFrq, short scan=1);
GT_API GTN_ScanSetPulseWidth(short core,unsigned short width, short scan=1);
GT_API GTN_ScanSetLevelDelay(short core,unsigned short highLevelDelay,unsigned short lowLevelDelay, short scan=1);
GT_API GTN_ScanLaserInfo(short core,TLaserInfo *pLaserInfo, short scan=1);

/*-----------------------------------------------------------*/
/* DLM                                                       */
/*-----------------------------------------------------------*/
#define DLM_FUNCTION_EVENT							(0)
#define DLM_FUNCTION_TIMER							(1)
#define DLM_FUNCTION_BACKGROUND						(2)
#define DLM_FUNCTION_COMMAND						(3)

#define DLM_FUNCTION_PROCEDURE						(7)

#define DLM_FUNCTION_PROFILE_EVENT					(8)
#define DLM_FUNCTION_PROFILE						(9)
#define DLM_FUNCTION_PROFILE_SUPERIMPOSED			(10)
#define DLM_FUNCTION_PROFILE_FILTER					(11)

#define DLM_FUNCTION_SERVO_EVENT					(16)
#define DLM_FUNCTION_SERVO							(17)
#define DLM_FUNCTION_SERVO_SUPERIMPOSED				(18)
#define DLM_FUNCTION_SERVO_FILTER					(19)

#define DLM_LOAD_MODE_NONE							(0)
#define DLM_LOAD_MODE_COMMAND						(1)
#define DLM_LOAD_MODE_BOOT							(2)
#define DLM_LOAD_MODE_RUN							(3)

typedef struct TDlmStatus
{
	long version;
	long date;
	short enable;
	long function;
} TDlmStatus;

typedef struct TDlmFunction
{
	short function;
	short enable;
	long value;
} TDlmFunction;

GT_API GT_LoadDlm(long vender,long module,char *fileName,short *pId);
GT_API GT_ProgramDlm(short id,short loadMode);
GT_API GT_GetDlmLoadMode(short id,short *pLoadMode);
GT_API GT_RunDlm(short id);
GT_API GT_StopDlm(short id);
GT_API GT_GetDlmStatus(short id,TDlmStatus *pStatus);
GT_API GT_SetDlmFunction(short id,TDlmFunction *pFunction);
GT_API GT_GetDlmFunction(short id,TDlmFunction *pFunction);

GT_API GT_DlmCommandInit(short code,long index);
GT_API GT_DlmCommandAdd16(short value);
GT_API GT_DlmCommandAdd32(long value);
GT_API GT_DlmCommandAddFloat(float value);
GT_API GT_DlmCommandAddDouble(double value);
GT_API GT_SendDlmCommand(short id,short *pReturnValue);
GT_API GT_DlmCommandGet16(short *pValue);
GT_API GT_DlmCommandGet32(long *pValue);
GT_API GT_DlmCommandGetFloat(float *pValue);
GT_API GT_DlmCommandGetDouble(double *pValue);

GT_API GTN_LoadDlm(short core,long vender,long module,char *fileName,short *pId);
GT_API GTN_ProgramDlm(short core,short id,short loadMode);
GT_API GTN_GetDlmLoadMode(short core,short id,short *pLoadMode);
GT_API GTN_RunDlm(short core,short id);
GT_API GTN_StopDlm(short core,short id);
GT_API GTN_GetDlmStatus(short core,short id,TDlmStatus *pStatus);
GT_API GTN_SetDlmFunction(short core,short id,TDlmFunction *pFunction);
GT_API GTN_GetDlmFunction(short core,short id,TDlmFunction *pFunction);

GT_API GTN_DlmCommandInit(short core,short code,long index);
GT_API GTN_DlmCommandAdd16(short core,short value);
GT_API GTN_DlmCommandAdd32(short core,long value);
GT_API GTN_DlmCommandAddFloat(short core,float value);
GT_API GTN_DlmCommandAddDouble(short core,double value);
GT_API GTN_SendDlmCommand(short core,short id,short *pReturnValue);
GT_API GTN_DlmCommandGet16(short core,short *pValue);
GT_API GTN_DlmCommandGet32(short core,long *pValue);
GT_API GTN_DlmCommandGetFloat(short core,float *pValue);
GT_API GTN_DlmCommandGetDouble(short core,double *pValue);
/*-----------------------------------------------------------*/
/* Event-Task                                                */
/*-----------------------------------------------------------*/
#define TASK_SET_DO_BIT							(0x1101)
#define TASK_SET_DAC							(0x1120)

#define TASK_STOP								(0x1303)

#define TASK_UPDATE_POS							(0x2002)
#define TASK_UPDATE_VEL							(0x2004)
#define TASK_UPDATE_DISTANCE					(0x2022)

#define TASK_PT_START							(0x2306)
#define TASK_PVT_START							(0x2346)
#define TASK_MOVE_ABSOLUTE						(0x2500)

#define TASK_GEAR_START							(0x3005)

#define TASK_FOLLOW_START						(0x310A)
#define TASK_FOLLOW_SWITCH						(0x310B)

#define TASK_CRD_START							(0x4004)
#define TASK_CRD_OVERRIDE						(0x4006)
#define TASK_SCAN_START							(0x4102)

#define TASK_MOVE_ESCAPE						(0x5000)

#define TASK_SET_DO_BIT_MODE_NONE				(0)
#define TASK_SET_DO_BIT_MODE_TIME				(10)
#define TASK_SET_DO_BIT_MODE_DISTANCE			(20)

typedef struct
{
	unsigned short type;
	unsigned short index;
	unsigned short id;
} TWatchVar;

typedef struct  
{
	short doType;
	short doIndex;
	short doValue;
	short mode;
	long parameter[8];
} TTaskSetDoBit;

typedef struct  
{
	short dac;
	short value;
} TTaskSetDac;

typedef struct  
{
	long mask;
	long option;
} TTaskStop;

typedef struct  
{
	short type;
	short index;
	short operation;
	short data[20];
} TTaskFifoOperation;

typedef struct  
{
	short profile;
	long pos;
} TTaskUpdatePos;

typedef struct  
{
	short profile;
	short triggerIndex;
	long distance;
} TTaskUpdateDistance;

typedef struct  
{
	short profile;
	double vel;
} TTaskUpdateVel;

typedef struct  
{
	long mask;
	long option;
} TTaskPtStart;

typedef struct  
{
	long mask;
} TTaskPvtStart;

typedef struct  
{
	long mask;
} TTaskGearStart;

typedef struct
{
	long mask;
	long option;
} TTaskFollowStart;

typedef struct
{
	long mask;
} TTaskFollowSwitch;

typedef struct  
{
	short profile;
	long pos;
	double vel;
	double acc;
	double dec;
	short percent;
} TTaskMoveAbsolute;

typedef struct  
{
	short mask;
	short option;
} TTaskCrdStart;

typedef struct  
{
	short crd;
	double synVelOverride;
} TTaskCrdOverride;

typedef struct  
{
	short port;
	short index;
	short count;
} TTaskScanStart;

typedef struct  
{
	unsigned long loop;
	TWatchVar var;
	unsigned short condition;
	double value;
} TEvent;

GT_API GT_ClearEvent(void);
GT_API GT_ClearTask(void);
GT_API GT_ClearEventTaskLink(void);
GT_API GT_AddEvent(TEvent *pEvent,short *pEventIndex);
GT_API GT_AddTask(short taskType,void *pTaskData,short *pTaskIndex);
GT_API GT_AddEventTaskLink(short eventIndex,short taskIndex,short *pLinkIndex);
GT_API GT_GetEventCount(short *pCount);
GT_API GT_GetEvent(short eventIndex,TEvent *pEvent);
GT_API GT_GetEventLoop(short eventIndex,unsigned long *pCount);
GT_API GT_GetTaskCount(short *pCount);
GT_API GT_GetTask(short taskIndex,short *pTaskType,void *pTaskData);
GT_API GT_GetEventTaskLinkCount(short *pCount);
GT_API GT_GetEventTaskLink(short linkIndex,short *pEventIndex,short *pTaskIndex);
GT_API GT_EventOn(short eventIndex,short count);
GT_API GT_EventOff(short eventIndex,short count);

GT_API GTN_ClearEvent(short core);
GT_API GTN_ClearTask(short core);
GT_API GTN_ClearEventTaskLink(short core);
GT_API GTN_AddEvent(short core,TEvent *pEvent,short *pEventIndex);
GT_API GTN_AddTask(short core,short taskType,void *pTaskData,short *pTaskIndex);
GT_API GTN_AddEventTaskLink(short core,short eventIndex,short taskIndex,short *pLinkIndex);
GT_API GTN_GetEventCount(short core,short *pCount);
GT_API GTN_GetEvent(short core,short eventIndex,TEvent *pEvent);
GT_API GTN_GetEventLoop(short core,short eventIndex,unsigned long *pEventLoop);
GT_API GTN_GetTaskCount(short core,short *pCount);
GT_API GTN_GetTask(short core,short taskIndex,short *pTaskType,void *pTaskData);
GT_API GTN_GetEventTaskLinkCount(short core,short *pCount);
GT_API GTN_GetEventTaskLink(short core,short linkIndex,short *pEventIndex,short *pTaskIndex);
GT_API GTN_EventOn(short core,short eventIndex,short count);
GT_API GTN_EventOff(short core,short eventIndex,short count);

/*--------- -------------------------------------------------*/
/* Gantry                                                    */
/*-----------------------------------------------------------*/
#define GANTRY_MODE_NONE								(-1)
#define GANTRY_MODE_OPEN_LOOP_GANTRY					(1)
#define GANTRY_MODE_DECOUPLE_POSITION_LOOP				(2)

GT_API GT_SetGantryMode(short group,short master,short slave,short mode,long syncErrorLimit=1000);
GT_API GT_GetGantryMode(short group,short *pMaster,short *pSlave,short *pMode,long *pSyncErrorLimit);
GT_API GT_SetGantryPid(short group,TPid *pGantryPid,TPid *pYawPid);
GT_API GT_GetGantryPid(short group,TPid *pGantryPid,TPid *pYawPid);
GT_API GT_GantryAxisOn(short group);
GT_API GT_GantryAxisOff(short group);

GT_API GTN_SetGantryMode(short core,short group,short master,short slave,short mode,long syncErrorLimit=1000);
GT_API GTN_GetGantryMode(short core,short group,short *pMaster,short *pSlave,short *pMode,long *pSyncErrorLimit);
GT_API GTN_SetGantryPid(short core,short group,TPid *pGantryPid,TPid *pYawPid);
GT_API GTN_GetGantryPid(short core,short group,TPid *pGantryPid,TPid *pYawPid);
GT_API GTN_GantryAxisOn(short core,short group);
GT_API GTN_GantryAxisOff(short core,short group);


typedef struct SecondOrderFilterPara
{
	short active;

	double a0;
	double a1;
	double a2;

	double b1;
	double b2;

} TSecondOrderFilterPara;

#define TYPE_CONTROL_OUTPUT_FILTER			1
#define TYPE_YAW_CONTROL_OUTPUT_FILTER		2
#define FILTER_COUNT_MAX					2

GT_API GT_SetSecondOrderFilterPara(short control,short type,short index,TSecondOrderFilterPara *pFilterPrm);
GT_API GT_GetSecondOrderFilterPara(short control,short type,short index,TSecondOrderFilterPara *pFilterPrm);

GT_API GTN_SetSecondOrderFilterPara(short core,short control,short type,short index,TSecondOrderFilterPara *pFilterPrm);
GT_API GTN_GetSecondOrderFilterPara(short core,short control,short type,short index,TSecondOrderFilterPara *pFilterPrm);

typedef struct _OCA_CTRL_GEN_
{
	short  s16Gain;
	short  s16Offset;
	double dFrq;
	long   u32RunPeriod;
	short  u16SigType;
} OCA_CTRL_GEN;

typedef struct ExcitationPara
{
	short gain;
	short offset;
	short frq;		// hz
	double runTime;	// s
} TExcitationPara;

typedef struct ExcitationTrapPara
{
	double vel;
	double acc;
	double dec;
	double runTime;	// s
} TExcitationTrpPara;

#define NO_EXCIT						(0xff)
#define OPEN_LOOP_EXCIT					(1)
#define SIGNAL_TYPE_STEP				(3)
#define SIGNAL_TYPE_SIN					(0x10)
#define SIGNAL_TYPE_TRAP				(0x11)
#define SIGNAL_TYPE_NOTHING				(0xFF)


GT_API GT_SetGenerator(OCA_CTRL_GEN *pGenStr);
GT_API GT_GetGenerator(OCA_CTRL_GEN *pGenStr);
GT_API GT_StepResponse(short control,short gain, double time);
GT_API GT_SetExctLoopMode(short control,short exciteLoopMode);
GT_API GT_GetExctLoopMode(short control,short *pExciteLoopMode);
GT_API GT_SetExcitation(short axis,short object,short type,void * pParameter);

GT_API GTN_SetGenerator(short core,OCA_CTRL_GEN *pGenStr);
GT_API GTN_SetGenerator(short core,OCA_CTRL_GEN *pGenStr);
GT_API GTN_StepResponse(short core,short control,short gain,double time);
GT_API GTN_SetExctLoopMode(short core,short control,short exciteLoopMode);
GT_API GTN_GetExctLoopMode(short core,short control,short *pExciteLoopMode);

GT_API GTN_SetExcitation(short core,short axis,short object,short type,void * pParameter);

/*-----------------------------------------------------------*/
/* DMA                                                       */
/*-----------------------------------------------------------*/
GT_API GT_CrdHsOn(short crd,short fifo,short link=1,unsigned short threshold=200,short lookAheadInMc=0);
GT_API GT_CrdHsOff(short crd,short fifo);

GT_API GTN_CrdHsOn(short core,short crd,short fifo,short link=1,unsigned short threshold=200,short lookAheadInMc=0);
GT_API GTN_CrdHsOff(short core,short crd,short fifo);

/*-----------------------------------------------------------*/
/* Others                                                    */
/*-----------------------------------------------------------*/
GT_API GTN_SetRetainValue(short core,unsigned long address,short count,short *pData);
GT_API GTN_GetRetainValue(short core,unsigned long address,short count,short *pData);

GT_API GTN_SetGPIOConfig(short core,short effectiveLevel,short direction);
GT_API GTN_SetPrfTorque(short core,short axis,short prfTorque);
GT_API GTN_GetAtlTorque(short core,short axis,short *atlTorque);
GT_API GTN_PosCurrFeedForward(short core,short profile,double pos,long gtime,short torque,short gtype,short fifo=0);
GT_API GTN_SetMotionMode(short core,short axis,short motionMode);
GT_API GTN_GetMotionMode(short core,short axis,short *motionMode);

GT_API GTN_SetProfileTime(short core,long profileTime,long delay,long stepCoef);
GT_API GTN_GetProfileTime(short core,long *pProfileTime,long *pDelay,long *pStepCoef);
GT_API GTN_SetCoreTime(short core,long profileTime,long delay,long stepCoef);
GT_API GTN_GetCoreTime(short core,long *pProfileTime,long *pDelay,long *pStepCoef);

typedef struct ControlInfo
{
	double refPos;
	double refPosFilter;
	double refPosFilter2;
	double cntPos;
	double cntPosFilter;

	double error;
	double refVel;
	double refAcc;

	short value;
	short valueFilter;

	short offset;
} TControlInfo;

typedef struct
{
	unsigned long notify;
	unsigned long receive;
	unsigned long execute;
	unsigned long retry;
	unsigned long receiveError;
	unsigned long echo;
} TCommandCount;

GT_API GT_ClearCommandCount(void);
GT_API GT_GetCommandCount(TCommandCount *pCommandCount);
GT_API GT_SetServoTime(long servoTime,long delay,long stepCoef);
GT_API GT_GetServoTime(long *pServoTime,long *pDelay,long *pStepCoef);
GT_API GT_GetControlInfo(short control,TControlInfo *pControlInfo);

GT_API GTN_ClearCommandCount(short core);
GT_API GTN_GetCommandCount(short core,TCommandCount *pCommandCount);
GT_API GTN_SetServoTime(short core,long servoTime,long delay,long stepCoef);
GT_API GTN_GetServoTime(short core,long *pServoTime,long *pDelay,long *pStepCoef);
GT_API GTN_GetControlInfo(short core,short control,TControlInfo *pControlInfo);

GT_API GT_SetLongVar(short index,long value);
GT_API GT_GetLongVar(short index,long *pValue);
GT_API GT_SetDoubleVar(short index,double value);
GT_API GT_GetDoubleVar(short index,double *pValue);

GT_API GT_GetBufWaitDiStatus(short crd,short *pDiType,unsigned short *pDiIndex,unsigned short *pLevel, short *pContinueTime,long *pOverTime,short *pFlagMode,long *pSegNum,short *pEnable,long *pCount,short fifo);
GT_API GT_GetBufWaitLongVarStatus(short crd,short *pIndex,long *pValue,short *pFlagMode,long *pSegNum,short *pEnable,short *pStatus,short fifo);
GT_API GT_ClearBufWaitStatus(short crd,short fifo);

GT_API GT_BufWaitDi(short crd, short diType, unsigned short diIndex,unsigned short level, short continueTime, long overTime, short flagMode,long segNum, short fifo);
GT_API GT_BufWaitLongVar(short crd, short index, long value, long overTime, short flagMode, long segNum, short fifo);

GT_API GTN_SetLongVar(short core,short index,long value);
GT_API GTN_GetLongVar(short core,short index,long *pValue);
GT_API GTN_SetDoubleVar(short core,short index,double value);
GT_API GTN_GetDoubleVar(short core,short index,double *pValue);

GT_API GTN_GetBufWaitDiStatus(short core,short crd,short *pDiType,unsigned short *pDiIndex,unsigned short *pLevel, short *pContinueTime,long *pOverTime,short *pFlagMode,long *pSegNum,short *pEnable,long *pCount,short fifo);
GT_API GTN_GetBufWaitLongVarStatus(short core,short crd,short *pIndex,long *pValue,short *pFlagMode,long *pSegNum,short *pEnable,short *pStatus,short fifo);
GT_API GTN_ClearBufWaitStatus(short core,short crd,short fifo);
GT_API GTN_BufWaitDi(short core,short crd, short diType, unsigned short diIndex,unsigned short level, short continueTime, long overTime, short flagMode,long segNum, short fifo);
GT_API GTN_BufWaitLongVar(short core,short crd, short index,long value,long overTime,short flagMode,long segNum,short fifo);

GT_API GT_SetAxisMotionSmooth(short axis,double time,double k);
GT_API GT_GetAxisMotionSmooth(short axis,double *pTime,double *pK);
GT_API GTN_SetAxisMotionSmooth(short core,short axis,double time,double k);
GT_API GTN_GetAxisMotionSmooth(short core,short axis,double *pTime,double *pK);

GT_API GT_BufDoBit(short crd,unsigned short doType,unsigned short index,short value,short fifo);
GT_API GTN_BufDoBit(short core,short crd,unsigned short doType,unsigned short index,short value,short fifo);
GT_API GTN_BufDoBitDelay(short core,short crd,unsigned short doType,unsigned short index,short value,long delayTime,short fifo);

GT_API GT_SetCrdJerk(short crd,double jerkMax);
GT_API GT_GetCrdJerk(short crd,double *pJerkMax);
GT_API GTN_SetCrdJerk(short core,short crd,double jerkMax);
GT_API GTN_GetCrdJerk(short core,short crd,double *pJerkMax);
GT_API GT_SetCrdJerkTime(short crd,double jerkTime,double coef);
GT_API GT_GetCrdJerkTime(short crd,double *pJerkTime,double *pCoef);
GT_API GTN_SetCrdJerkTime(short core,short crd,double jerkTime,double coef);
GT_API GTN_GetCrdJerkTime(short core,short crd,double *pJerkTime,double *pCoef);
typedef struct  
{
	short percent;
	short accStartPercent;
	short decEndPercent;
	double reserve;
} TCrdSmooth;
GT_API GT_SetCrdSmooth(short crd,TCrdSmooth *pCrdSmooth);
GT_API GT_GetCrdSmooth(short crd,TCrdSmooth *pCrdSmooth);
GT_API GT_SetCrdSmoothTime(short crd,short smoothType,double *pPrm);
GT_API GT_GetCrdSmoothTime(short crd,short *pSmoothType,double *pPrm);
GT_API GTN_SetCrdSmooth(short core,short crd,TCrdSmooth *pCrdSmooth);
GT_API GTN_GetCrdSmooth(short core,short crd,TCrdSmooth *pCrdSmooth);
GT_API GTN_SetCrdSmoothTime(short core,short crd,short smoothType,double *pPrm);
GT_API GTN_GetCrdSmoothTime(short core,short crd,short *pSmoothType,double *pPrm);

//////////////////////////////////////////////////////////////////////////
//Standard Home
//////////////////////////////////////////////////////////////////////////

#define STANDARD_HOME_STAGE_IDLE  (0) //δ������ԭ��
#define STANDARD_HOME_STAGE_START (1) //������ԭ��
#define STANDARD_HOME_STAGE_SEARCH_HOME (20) //��������Home
#define STANDARD_HOME_STAGE_SEARCH_INDEX  (30) //��������Index
#define STANDARD_HOME_STAGE_GO_HOME       (80) //�����˶���ԭ��
#define STANDARD_HOME_STAGE_END           (100) //��ԭ�����
#define STANDARD_HOME_STAGE_START_CHECK (-1) //������ԭ��ǰ�Լ�
#define STANDARD_HOME_STAGE_CHECKING (-2) //�Լ���


#define STANDARD_HOME_ERROR_NONE		(0) //δ��������
#define STANDARD_HOME_ERROR_DISABLE	(10) //ִ�л�ԭ�����δʹ��
#define STANDARD_HOME_ERROR_ALARM		(20) //ִ�л�ԭ����ᱨ��
#define STANDARD_HOME_ERROR_STOP		(30) //δ��ɻ�ԭ�㣬��ֹͣ�˶�
#define STANDARD_HOME_ERROR_ON_LIMIT   (40) //��������λ�޷�����
#define STANDARD_HOME_ERROR_NO_HOME	(50) //δ�ҵ�Home
#define STANDARD_HOME_ERROR_NO_INDEX  (60) //δ�ҵ�Index
#define STANDARD_HOME_ERROR_NO_LIMIT (70) //δ�ҵ���λ
#define STANDARD_HOME_ERROR_ENCODER_DIR_SCALE (-1) //�滮����������������෴���ߵ�����һ��


typedef struct  
{
	short mode;		 // ��ԭ��ģʽȡֵ��Χ1~36
	double highSpeed; // ����Home���ٶȣ���λpulse/ms
	double lowSpeed;	 // ����Index���ٶȣ���λpulse/ms
	double acc;		 // ������ٶȣ���λpulse/ms^2
	long offset;       // ����ƫ��������λpulse
	short check; // �Ƿ������Լ칦�ܣ�1-���ã�����ֵ-������
	short autoZeroPos; // ��������Ƿ��Զ����㣬1-�Զ����㣬����ֵ-������
	long motorStopDelay; //�����λ��ʱ����λ����������
	short pad1[3];	 // ����������Ҫ���ã�
} TStandardHomePrm;

typedef struct  
{
	short run;     // �����ڽ��л�ԭ�㣬0����ֹͣ�˶���1-���ڻ�ԭ��
	short stage;   // ��ԭ���˶��Ľ׶�
	short error;    // ��ԭ����̵ķ����Ĵ���
	short pad1[3];       // �������޾��庬�壩
	long capturePos;  // ����Home��Indexʱ�̵ı�����λ��
	long targetPos;    // ��Ҫ�˶�����Ŀ��λ�ã�ԭ��λ�û���ԭ��λ��+ƫ��������������Limitʱ��������Home��Indexʱ�����õ���������Ϊ0����ô��ֵ��ʾΪ805306368
} TStandardHomeStatus;

GT_API GT_ExecuteStandardHome(short axis,TStandardHomePrm *pHomePrm);
GT_API GT_GetStandardHomePrm(short axis,TStandardHomePrm *pHomePrm);
GT_API GT_GetStandardHomeStatus(short axis,TStandardHomeStatus *pHomeStatus);

GT_API GTN_ExecuteStandardHome(short core,short axis,TStandardHomePrm *pHomePrm);
GT_API GTN_GetStandardHomePrm(short core,short axis,TStandardHomePrm *pHomePrm);
GT_API GTN_GetStandardHomeStatus(short core,short axis,TStandardHomeStatus *pHomeStatus);

typedef struct
{
	unsigned long onCount;
	unsigned long offCount;
	unsigned long onCountInFpga;
	unsigned long offCountInFpga;
	unsigned long pad[4];
}TLaserOnOffCount;

GT_API GTN_GetLaserOnOffCount(short core,short channel,TLaserOnOffCount *pLaserCount);
GT_API GTN_ClearLaserOnOffCount(short core,short channel);

GT_API GTN_BufPosComparePsoPrm(short core,short crd,short index,TPosComparePsoPrm *pPrm,short fifo);

GT_API GT_SetAxisInputShaping(short axis,short enable,short count,double k);
GT_API GTN_SetAxisInputShaping(short core,short axis,short enable,short count,double k);

GT_API GT_SetGantrySynchErrorCompensate2DTable(short tableIndex,TCompensate2DTable *pTable,long *pData,short extend);
GT_API GT_GetGantrySynchErrorCompensate2DTable(short tableIndex,TCompensate2DTable *pTable,short *pExtend);
GT_API GT_SetGantrySynchErrorCompensate2D(short group,TCompensate2D *pComp2d);
GT_API GT_GetGantrySynchErrorCompensate2D(short group,TCompensate2D *pComp2d);
GT_API GT_GetGantrySynchErrorCompensate2DValue(short group,double *pValue);
GT_API GTN_SetGantrySynchErrorCompensate2DTable(short core,short tableIndex,TCompensate2DTable *pTable,long *pData,short extend);
GT_API GTN_SetGantrySynchErrorCompensate2D(short core,short group,TCompensate2D *pComp2d);

GT_API GTN_SetLaserFollowTable(short core,short tableId,long n,double *pVel,double *pPower,short channel);
GT_API GT_LaserFollowOff(short crd,short fifo,short channel);
GT_API GTN_LaserFollowOff(short core,short crd,short fifo,short channel);

typedef struct
{
	short type;
	short enable;
	short flagMode;
	short diType;
	short diIndex;
	short diValue;
	unsigned short continueTime;
	unsigned short trigDelay;
	unsigned long overTime;
	unsigned long counter;
	long longVar;
	long segNum;
	short stop;
	short overTimeStop;
	short pad1[2];
}TBufWaitDiStatusEx;
GT_API GTN_GetBufWaitDiStatusEx(short core,short crd,short fifo,TBufWaitDiStatusEx *pStatus);

GT_API GTN_SetPosCompareFifoMode(short core,short index,short mode);
GT_API GTN_GetPosCompareFifoMode(short core,short index,short *pMode);
GT_API GTN_GetPosCompareLatchValue(short core,short index,long count,long *pDataX,long *pDataY,long *pCount,TLatchValueInfo *pInfo);


typedef struct
{
	unsigned long profileMask;
	long offset;
	double vel;
	double acc;
}TTaskMoveEscape;

typedef struct
{
	short eventHit;
	short pad1[3];
	long pad2[2];
	double pad3[2];
}TEventStatus;

typedef struct
{
	short start;
	short execute;
	short pad1[2];
	long pad2[2];
	double pad3[2];
}TaskStatus;

GT_API GTN_GetEventStatus(short core,short index,TEventStatus *pStatus);
GT_API GTN_GetTaskStatus(short core,short index,TaskStatus *pStatus);
GT_API GTN_SetTriggerMoveEscape(short core,short trigger,TTaskMoveEscape *pPrm);

GT_API GTN_GetCrdHsPrm(short core,short crd,short fifo,short *pEnable,short *pLink,unsigned short *pThreshold,short *pLookAheadInMc);

GT_API GTN_SetPrfPosEx(short core,short profile,double pos);
GT_API GTN_SetEncPosEx(short core,short encoder,double pos);
GT_API GTN_GetDiBit(short core,short diType,short diIndex,short *pValue);
typedef struct
{
	double pos;
	double vel;
	double reserve[2];
	long di;
	long reserve1[3];
}TMpgInfo;
GT_API GTN_ReadMpgInfo(short core,short mpg,TMpgInfo *pMpgInfo);
GT_API GTN_WriteMpgPos(short core,short mpg,double *pPos,short count=1);
GT_API GTN_ReadAuEncPos(short core,short encoder,double *pPos,short count=1);
GT_API GTN_WriteAuEncPos(short core,short encoder,double *pPos,short count=1);
GT_API GT_OpenExtMdl(char *pDllName);
GT_API GT_CloseExtMdl();
GT_API GT_LoadExtConfig(char *pFileName);
GT_API GT_ResetExtMdl();
GT_API GTN_DeleteEvent(short core,short eventIndex);
GT_API GTN_DeleteTask(short core,short taskIndex);
GT_API GTN_DeleteEventTaskLink(short core,short linkIndex);
GT_API GTN_SetEvent(short core,TEvent *pEvent,short eventIndex);
GT_API GTN_SetTask(short core,short taskType,void *pTaskData,short taskIndex);
GT_API GTN_SetEventTaskLink(short core,short eventIndex,short taskIndex,short linkIndex);
GT_API GTN_ClearMcStatus(short core);
GT_API GTN_SetMcInfo(short core,long info,long index,unsigned long data);
GT_API GTN_GetMcInfo(short core,long info,long index,unsigned long *pData);
GT_API GTN_GetRNMasterInfo(short core,unsigned short *pPhyId,unsigned short *pType,unsigned short *pInfo);
GT_API GTN_SetRNMasterInfo(short core,unsigned short phyId,unsigned short type,unsigned short info);
GT_API GTN_RN_MltPcPduRd(short core,unsigned char* pData, unsigned char des_id,unsigned short byte_start_offset,unsigned short byte_num);
GT_API GTN_RN_MltPcPduRdUpdate(short core,unsigned char des_id);
GT_API GTN_RN_MltPcPduWr(short core,unsigned char* pData, unsigned char des_id, unsigned short byte_start_offset,unsigned short byte_num);
GT_API GTN_RN_MltPcPduWrUpdate(short core,unsigned char des_id);

typedef struct
{
	short run;
	short mode;
	double power;
	double frequency;
	double pulseWidth;
	double pad1[9];
	short pad2[8];
} TLaserStatus;
GT_API GTN_GetLaserStatus(short core,short channel,TLaserStatus *pStatus);

typedef struct 
{
	short list;
	short reserve1[2];
	short modal;
	long segNum;
	long reserve2[3];
	double reserve3[4];
}TListInfo;

typedef struct  
{
	short execute;
	short empty;
	short reserve1[4];
	short command;
	short direction;
	long executeSegNum;
	long reserve2[7];
} TCommandListStatus;

GT_API GTN_GetCommandListSpace(short core,short list,long *pSpace);
GT_API GTN_GetCommandListStatus(short core,short list,TCommandListStatus *pStatus);
GT_API GTN_ClearCommandListData(short core,short list);
GT_API GTN_StartCommandList(short core,short list,TListInfo *pListInfo=NULL);
GT_API GTN_StartMultiCommandList(short core,unsigned long mask,TListInfo *pListInfo=NULL);
GT_API GTN_StopCommandList(short core,short index,short stopMode,TListInfo *pListInfo=NULL);
GT_API GTN_StopMultiCommandList(short core,unsigned long mask,short stopMode,TListInfo *pListInfo=NULL);

typedef struct  
{
	TWatchVar var;
	unsigned short condition;
	double value;
} TWatchCondition;

typedef struct  
{
	unsigned short operation;
	unsigned short varType;
	unsigned short result;
	unsigned short lhs;
	unsigned short rhs;
} TVarCalculate;

typedef struct 
{
	short varIndex;
	short reserve[3];
	TWatchCondition watchCondition;
} TVarCondition;

typedef struct  
{
	long time;				// ��ʱʱ��
	short timeOutDo;			// ��ʱ�����Ϊ
	short revers1;
	double reverse2[4];			// 
} TWaitTimeout;

GT_API GTN_SetVarBoolCondition(short core,short varIndex,TWatchCondition *pWatchCondition);
GT_API GTN_LoadVarCalculate(short core,TVarCalculate *pVarCalculate,short count,TListInfo *pListInfo=NULL);
GT_API GTN_GetWaitForConditionNow(short core,short list,TWatchCondition *pWatchCondition,short *pConditionCount,short *pOperation,TWaitTimeout *pTimeout);
GT_API GTN_MoveTrap(short core,short profile,double pos,double vel,TTrapPrm *pPrm,TListInfo *pList=NULL);
GT_API GTN_SetVarCondition(short core,TVarCondition *pVarCondition,short count,TListInfo *pListInfo=NULL);
GT_API GTN_WaitForCondition(short core,TWatchCondition *pWatchCondition,short conditionCount,short operation,TWaitTimeout *pTimeout,TListInfo *pListInfo=NULL);
#define DIGITAL_OUTPUT_MODE_NORMAL                    (0)
#define DIGITAL_OUTPUT_MODE_REVERSE_TIME              (10)

typedef struct
{
	double time;
	double reserve[9];
}TDoReverseParameter;

typedef union
{
	TDoReverseParameter doReverse;
	double data[10];
}TDigitalOutputMode;

typedef struct
{
	short mode;              //Do���ģʽ
	short doType;
	short doIndex;
	short doValue;
	short reverse1[4];
	long  reserve2[2];
	TDigitalOutputMode prm;
}TDigitalOutputBit;

typedef struct
{
	double delayTime;
	short reserve1[4];
	long reserve2[2];
	double reserve3[2];
}TDelay;

GT_API GTN_WriteDigitalOutputBit(short core,TDigitalOutputBit *pDoBit,TListInfo *pListInfo=NULL);
GT_API GTN_SetDelay(short core,TDelay *pDelay,TListInfo *pListInfo);


typedef struct
{
	short  count;
	short  reverse1[3];
	double alpha[4];
	double beta[4];
}TProfileScale;
GT_API GTN_SetAxisScale(short core,short profile,TProfileScale *pScale,TListInfo *pListInfo=NULL);
GT_API GTN_GetAxisScale(short core,short profile,TProfileScale *pScale);

GT_API GTN_GetTrapSts(short core,short profile,short *prfsts);
GT_API GTN_ClearTrapSts(short core,short profile);

/*-----------------------------------------------------------*/
/* New Watch  Code                                           */
/*-----------------------------------------------------------*/
#define WATCH_GROUP_TIMER					(0)
#define WATCH_GROUP_BACKGROUND				(1)

#define WATCH_MODE_STATIC					(0)
#define WATCH_MODE_LOOP						(1)
#define WATCH_MODE_DYNAMIC					(2)

#define WATCH_EVENT_MAX						(8)

#define WATCH_EVENT_RUN						(1)
#define WATCH_EVENT_START					(10)
#define WATCH_EVENT_STOP					(20)
#define WATCH_EVENT_OFF						(30)

#define WATCH_CONDITION_NONE				(0)

#define WATCH_CONDITION_EQ					(1)
#define WATCH_CONDITION_NE					(2)
#define WATCH_CONDITION_GE					(3)
#define WATCH_CONDITION_LE					(4)

#define WATCH_CONDITION_CHANGE_TO			(11)
#define WATCH_CONDITION_CHANGE				(12)
#define WATCH_CONDITION_UP					(13)
#define WATCH_CONDITION_DOWN				(14)
#define WATCH_CONDITION_CHANGE_BEYOND		(15)
#define WATCH_CONDITION_CHANGE_MAX			(16)

#define WATCH_CONDITION_REMAIN_AT			(21)
#define WATCH_CONDITION_REMAIN				(22)
#define WATCH_CONDITION_CROSS_POSITIVE		(23)
#define WATCH_CONDITION_CROSS_NEGATIVE		(24)

#define WATCH_CONDITION_NEAREST				(31)
#define WATCH_CONDITION_DELTA				(32)


#define WATCH_VAR_NONE						(0)

#define WATCH_VAR_UUID						(1000)

#define WATCH_VAR_POWER_ON_COUNT			(1060)

#define WATCH_VAR_DSP_PROGRAM_COUNT			(1070)

#define WATCH_VAR_DSP_TEMPERATURE			(1072)

#define WATCH_VAR_FPGA_PROGRAM_COUNT		(1080)

#define WATCH_VAR_CLOCK						(1200)
#define WATCH_VAR_PRF_LOOP					(1201)
#define WATCH_VAR_PRF_PERIOD				(1205)
#define WATCH_VAR_PRF_TIME					(1206)

#define WATCH_VAR_SKIP_MODULE				(1211)
#define WATCH_VAR_TEST_MODE					(1212)

#define WATCH_VAR_COMMAND_CODE				(1220)
#define WATCH_VAR_COMMAND_DATA				(1221)
#define WATCH_VAR_COMMAND_COUNT				(1222)
#define WATCH_VAR_COMMAND_READ_FLAG			(1223)

#define WATCH_VAR_LINK_PORT_TX_USE			(1660)
#define WATCH_VAR_LINK_PORT_TX_REQUIRE		(1661)
#define WATCH_VAR_LINKPORT_TX_STATUS		(1662)
#define WATCH_VAR_LINKPORT_TX_ERROR_COUNT	(1663)
#define WATCH_VAR_LINKPORT_TX_SKIP_MAX		(1664)

#define WATCH_VAR_SPORT_STATUS				(1682)
#define WATCH_VAR_SPORT_ERROR_COUNT			(1683)


#define WATCH_VAR_PRF_POS					(6000)
#define WATCH_VAR_PRF_VEL					(6001)
#define WATCH_VAR_PRF_ACC					(6002)
#define WATCH_VAR_PRF_POS_RAW				(6003)
#define WATCH_VAR_PRF_VEL_RAW				(6004)

#define WATCH_VAR_PRF_VEL_F32				(6011)
#define WATCH_VAR_PRF_ACC_F32				(6012)
#define WATCH_VAR_PRF_JERK_F32				(6013)

#define WATCH_VAR_PRF_VEL_64				(6021)

#define WATCH_VAR_PRF_RUN					(6200)

// 6600 Trap

#define WATCH_VAR_PT_PRF_POS_F64			(6650)
#define WATCH_VAR_PT_SPACE					(6660)
#define WATCH_VAR_PT_RECEIVE				(6662)
#define WATCH_VAR_PT_EXECUTE				(6663)

#define WATCH_VAR_TRAP_TOTAL_TIME           (6670)
#define WATCH_VAR_TRAP_REMAIN_TIME          (6671)

// 6700 PVT

// 6750 Follow

// 7000 MoveAbsolute
#define WATCH_VAR_MOVE_ABSOLUTE_DONE		(7008)

// 7050 MoveVelocity
#define WATCH_VAR_MOVE_VELOCITY_IN_VELOCITY	(7058)

#define WATCH_VAR_CRD_PRF_POS				(8000)
#define WATCH_VAR_CRD_PRF_VEL				(8001)
#define WATCH_VAR_CRD_PRF_ACC				(8002)
#define WATCH_VAR_CRD_PRF_VEL_RAW			(8003)

#define WATCH_VAR_CRD_PRF_TEMP_DATA         (8010)

#define WATCH_VAR_CRD_RUN					(8200)

#define WATCH_VAR_CRD_SEGMENT_NUMBER		(8202)
#define WATCH_VAR_CRD_SEGMENT_NUMBER_USER	(8203)
#define WATCH_VAR_CRD_COMMAND_RECEIVE		(8204)
#define WATCH_VAR_CRD_COMMAND_EXECUTE		(8205)

#define WATCH_VAR_CRD_FOLLOW_SLAVE_POS		(8600)
#define WATCH_VAR_CRD_FOLLOW_SLAVE_VEL		(8601)

#define WATCH_VAR_CRD_FOLLOW_STAGE			(8610)

#define WATCH_VAR_CONTOUR_PEDAL_POS			(8800)
#define WATCH_VAR_CONTOUR_PRF_POS			(8801)
#define WATCH_VAR_CONTOUR_PRF_POS_SHAPING	(8802)
#define WATCH_VAR_CONTOUR_ENC_POS			(8803)
#define WATCH_VAR_CONTOUR_DAC               (8804)

#define WATCH_VAR_CONTOUR_FIFO_POINT_COUNT	(8808)
#define WATCH_VAR_CONTOUR_FIFO_POINT_MAX	(8809)

#define WATCH_VAR_LIST_EXECUTE				(9240)
#define WATCH_VAR_LIST_SEG_NUM              (9250)

#define WATCH_VAR_POS_COMPARE_COMMAND_RECEIVE	(17422)
#define WATCH_VAR_POS_COMPARE_COMMAND_SEND		(17423)
#define WATCH_VAR_POS_COMPARE_COMMAND_LEFT		(17424)
#define WATCH_VAR_POS_COMPARE_COMMAND_TX		(17425)
#define WATCH_VAR_POS_COMPARE_PULSE_COUNT		(17426)
#define WATCH_VAR_POS_COMPARE_PSO_ON_OFF		(17427)

#define WATCH_VAR_SCAN_PRF_POS				(18000)
#define WATCH_VAR_SCAN_PRF_VEL				(18001)
#define WATCH_VAR_SCAN_PRF_ACC				(18002)

#define WATCH_VAR_SCAN_PRF_POS_X			(18010)
#define WATCH_VAR_SCAN_PRF_POS_Y			(18020)

#define WATCH_VAR_SCAN_RUN					(18200)

#define WATCH_VAR_SCAN_SEGMENT_NUMBER		(18202)

#define WATCH_VAR_SCAN_COMMAND_RECEIVE		(18422)
#define WATCH_VAR_SCAN_COMMAND_SEND			(18423)
#define WATCH_VAR_SCAN_COMMAND_LEFT			(18424)
#define WATCH_VAR_SCAN_COMMAND_TX			(18425)

#define WATCH_VAR_LASER_HSIO				(18600)
#define WATCH_VAR_LASER_POWER				(18601)
#define WATCH_VAR_LASER_WORK_RATIO			(18602)

#define WATCH_VAR_AXIS_PRF_POS				(20000)
#define WATCH_VAR_AXIS_PRF_VEL				(20001)
#define WATCH_VAR_AXIS_PRF_ACC				(20002)

#define WATCH_VAR_AXIS_PRF_POS_OTHER		(20004)
#define WATCH_VAR_AXIS_PRF_VEL_OTHER		(20005)

#define WATCH_VAR_AXIS_PRF_POS_FILTER		(20010)
#define WATCH_VAR_AXIS_PRF_VEL_FILTER		(20011)

#define WATCH_VAR_AXIS_TEMP_PRF_POS_FILTER  (20012)
#define WATCH_VAR_AXIS_PRF_POS_FILTER_BEFORE_COMP (20013)

#define WATCH_VAR_AXIS_PRF_VEL_64			(20021)

#define WATCH_VAR_AXIS_STATUS		        (20100)

#define WATCH_VAR_AXIS_RUN		            (20200)

#define WATCH_VAR_AXIS_ENC_POS_FILTER		(20310)
#define WATCH_VAR_AXIS_ENC_VEL_FILTER		(20311)

#define WATCH_VAR_AXIS_ENC_VEL_64_FILTER	(20321)

#define WATCH_VAR_DRIVER_ACT_VEL			(20400)
#define WATCH_VAR_STIMULATE_DATA			(20401)
#define WATCH_VAR_DRIVER_CURRENT_KVFF		(20402)

#define WATCH_VAR_CONTROL_ERROR				(20500)

#define WATCH_VAR_BACKLASH_VALUE			(21000)
#define WATCH_VAR_LEADSCREW_VALUE			(21001)
#define WATCH_VAR_FRICTION_VALUE			(21003)

#define WATCH_VAR_ENC_POS					(30000)
#define WATCH_VAR_ENC_VEL					(30001)
#define WATCH_VAR_AU_ENC_POS				(30002)
#define WATCH_VAR_AU_ENC_VEL				(30003)

#define WATCH_VAR_PULSE_POS					(30010)

#define WATCH_VAR_ENC_VEL_64				(30021)
#define WATCH_VAR_AU_ENC_VEL_64				(30022)
#define WATCH_VAR_ENC_VEL_64_1MS			(30023)
#define WATCH_VAR_AU_ENC_VEL_64_1MS			(30024)

#define WATCH_VAR_GPI						(31000)
#define WATCH_VAR_LIMIT_POSITIVE			(31010)
#define WATCH_VAR_LIMIT_NEGATIVE			(31020)
#define WATCH_VAR_ALARM   		        	(31030)
#define WATCH_VAR_HOME             			(31040)
#define WATCH_VAR_ARRIVE           			(31050)
#define WATCH_VAR_BANK_GPI					(31060)

#define WATCH_VAR_GPO						(32000)
#define WATCH_VAR_ENABLE					(32010)
#define WATCH_VAR_CLEAR 					(32020)

#define WATCH_VAR_AI     					(33000)

#define WATCH_VAR_AO     					(34000)

#define WATCH_VAR_TRIGGER_EXECUTE			(38000)
#define WATCH_VAR_TRIGGER_STATUS			(38001)
#define WATCH_VAR_TRIGGER_POSITION			(38002)

#define WATCH_VAR_TRIGGER_COUNT				(38010)

#define WATCH_VAR_TRIGGER_NOTIFY_ENABLE			(38020)
#define WATCH_VAR_TRIGGER_NOTIFY_STATUS_ECHO	(38021)
#define WATCH_VAR_TRIGGER_NOTIFY_CLEAR_WAIT		(38022)

#define WATCH_VAR_TRIGGER_DELTA_CROSS_COUNT		(38110)


#define WATCH_VAR_POS_LOOP_ERROR			(40000)
#define WATCH_VAR_POS_LOOP_REF_POS			(40001)
#define WATCH_VAR_POS_LOOP_FILTER_VALUE		(40002)

#define WATCH_VAR_FIR_POS_IN				(48000)
#define WATCH_VAR_FIR_POS_OUT				(48001)

#define WATCH_VAR_WATCH_ENABLE				(52000)
#define WATCH_VAR_WATCH_TIME				(52001)
#define WATCH_VAR_WATCH_EVENT_VALUE_WORK	(52002)

#define WATCH_VAR_INT32						(52020)
#define WATCH_VAR_INT64						(52021)
#define WATCH_VAR_FLOAT						(52022)
#define WATCH_VAR_DOUBLE					(52023)
#define WATCH_VAR_BOOL						(52024)


#define WATCH_VAR_TERMINAL_LIMIT_POSITIVE		(53000)
#define WATCH_VAR_TERMINAL_LIMIT_NEGATIVE		(53001)
#define WATCH_VAR_TERMINAL_ALARM				(53002)
#define WATCH_VAR_TERMINAL_HOME					(53003)
#define WATCH_VAR_TERMINAL_GPI					(53004)
#define WATCH_VAR_TERMINAL_ARRIVE				(53005)
#define WATCH_VAR_TERMINAL_MPG					(53009)

#define WATCH_VAR_TERMINAL_ENABLE				(53010)
#define WATCH_VAR_TERMINAL_CLEAR				(53011)
#define WATCH_VAR_TERMINAL_GPO					(53012)

#define WATCH_VAR_TERMINAL_DAC					(53020)

#define WATCH_VAR_TERMINAL_PULSE				(53022)
#define WATCH_VAR_TERMINAL_ENCODER				(53023)
#define WATCH_VAR_TERMINAL_ADC					(53024)

#define WATCH_VAR_TERMINAL_AU_ENCODER			(53026)

#define WATCH_VAR_TERMINAL_PRF_POS				(53030)

#define WATCH_VAR_TERMINAL_TRIGGER_POSITION	    (53040)
#define WATCH_VAR_TERMINAL_TRIGGER_STATUS	    (53041)

#define WATCH_VAR_TERMINAL_COMMAND				(53100)
#define WATCH_VAR_TERMINAL_STATUS				(53101)

#define WATCH_VAR_EVENT_HIT						(60000)
#define WATCH_VAR_TASK_START					(61000)
#define WATCH_VAR_TASK_WORK						(61001)


#define VAR_FORMAT_INT						(1)
#define VAR_FORMAT_FLOAT					(2)
#define VAR_FORMAT_DOUBLE					(3)

#define WATCH_LOAD_MODE_NONE				(0)
#define WATCH_LOAD_MODE_BOOT				(2)
#define WATCH_LOAD_MODE_RUN					(3)



#define VAR_CALCULATE_MAX					(32)

#define VAR_CALCULATE_NONE					(0)
#define VAR_CALCULATE_OR					(1)
#define VAR_CALCULATE_AND					(3)
#define VAR_CALCULATE_NOT					(5)

#define VAR_CALCULATE_ADD					(11)
#define VAR_CALCULATE_SUB					(12)
#define VAR_CALCULATE_MUL					(13)
#define VAR_CALCULATE_DIV					(14)

GT_API GTN_LoadReadHsConfig(short core,char *pFile);
GT_API GTN_ReadHsOn(short core,short enable,short mode,double interval);

typedef struct
{
	short mode;
	short pad0;
	long band;		//�������жϵ�λ����
	long time;		//�������жϵ�λʱ��
	long pad1[2];
}TAxisArrivePrm;
GT_API GTN_GetStsEx(short core,short axis,long *pSts,short count=1,unsigned long *pClock=NULL);
GT_API GTN_SetAxisArriveMode(short core,short axis,TAxisArrivePrm *pPrm);
GT_API GTN_GetAxisArriveMode(short core,short axis,TAxisArrivePrm *pPrm);

typedef struct
{
	short runEmpty;
	long segUseCount;
	long segReceiveCount;
	short pad1[2];
	long pad2[2];
	double pad3[2];
}TCrdStatusEx;

GT_API GT_CrdStatusEx(short crd,TCrdStatusEx *pCrdStatus,short fifo);
GT_API GTN_CrdStatusEx(short core,short crd,TCrdStatusEx *pCrdStatus,short fifo);

GT_API GTN_SetCrdMPGMode(short core,short crd,short enable,short master,long masterEven,long slaveEven,short filterTime,short mode);
GT_API GTN_GetCrdMPGMode(short core,short crd,short *pEnable,short *pMaster,long *pMasterEven,long *pSlaveEven,short *pFilterTime,short *pMode,short *pFifoEnd);

typedef struct  
{
	double pos;
	double vel;
	double velEnd;
	double acc;
	double dec;
	short  direction;
	short overrideSelect;
	short reserve[2];
} TMoveContinuousAbsolutePrm;

GT_API GTN_MoveContinuousAbsolute(short core,short profile,TMoveContinuousAbsolutePrm *pPrm,TListInfo *pListInfo=NULL,short group=0);

GT_API GTN_SetReadHs(short core,short enable,short mode,short interval);
GT_API GTN_ReadHsReadBuffer(short core,short *pData,long count);

GT_API GTN_RN_GeneralCommand(short core,short stationId,long cmdId,long prmSizeCount,void *pPrm,long resultSizeCount,void *pResult);

typedef struct  
{	
	char keyValue[32];		// ԭʼ��Կ
	char randomIn[32];
	short block;			// �ڼ���block,32bytesһ��block,����
	char data[32];			// ��ȡ���Ļ���д��ȥ���µ�����
	short sts;
}TEncryptOperatePrm;
GT_API GTN_WriteUserSlotDataEncrypt(short core,short slotIndex,TEncryptOperatePrm *pWritePrm);
GT_API GTN_ReadUserSlotDataEncrypt(short core,short slotIndex,TEncryptOperatePrm *pReadPrm);

GT_API GTN_EncryptionFunConfig(short core,short slotIndex,char *pOldKey,char *pNewKey,char *pUserData,short *pSts,short *pConfigured);

typedef struct  
{
	short mode;	    //�˶�����,0-��λ��6-PVT������������ʱ��֧��
	short enable;   //�Ƿ�ʹ�ܣ�0-��ʹ�ܣ�1-ʹ��
	short trigger;	//trigger������ȡֵ��1��ʼ
	short pad1;		//����
	long distance;	//����ʱƫ�����������ɸ�����λ������
	long posLimit;  //���¹滮�󣬴���λ��+ƫ�������ܳ�����ֵ
	double vel;     //Ŀ���ٶȣ����¹滮��Ŀ���ٶȣ���λ������/ms
	double acc;     //��Ҫ����ʱ�ļ��ٶȣ���λ������/ms
	double dec;		//�˶�������ƫ�����ļ��ٶȣ���λ������/ms
	double percent;	//���ٶ�S������ʱ��ٷֱȣ�����60��ʾ60%
	double reserve[4];
}TTriggerProfilePrm;

typedef struct
{
	short mode;
	short enable;
	short execute;			//�Ƿ�ִ����,0-δִ�У�1-ִ��
	short status;			//ִ�й����е�״̬������Ϊ0���쳣�򷵻ش�����
	long endPos;			//�յ�λ�ã�����+ƫ������
	long reserve[7];
}TTriggerProfileStatus;

GT_API GTN_SetTriggerProfilePrm(short core,short profile,TTriggerProfilePrm *pPrm);
GT_API GTN_GetTriggerProfileStatus(short core,short profile,TTriggerProfileStatus *pSts);

GT_API GTN_LmtsOnEx(short core,short axis,short limitType,short limitMode);
GT_API GTN_LmtsOffEx(short core,short axis,short limitType,short limitMode);

GT_API GTN_PrintLogInfo(short core,const char *pFileName,long start,long count);
GT_API GTN_PrintMcStsInfo(short core,const char *pFileName,short type,short index,short count);
GT_API GTN_PrintCommandInfo(short core,const char *pFileName,long start,long count);

typedef struct  
{
	short value;
}TMovePosPercent;

typedef struct  
{
	short value;
}TMovePosSmoothTime;

typedef union
{
	TMovePosPercent percent;
	TMovePosSmoothTime smoothTime;
	double value[2];
}TMovePosUnion;

typedef struct  
{
	double pos;
	double vel;
	double acc;
	double dec;
	short direction;
	short overrideSelect;
	short pad;
	short mode;
	TMovePosUnion data;
}TMovePosParameter;

typedef struct  
{
	double pos[2];
	double vel[2];
	double acc;
	double dec;
	short direction;
	short overrideSelect;
	short pad;
	short mode;
	TMovePosUnion data;
}TMovePosTwoSegmentParameter;

typedef struct  
{
	short profile;
	short pad1[3];
	double pos;
	double vel;
	double acc;
	double dec;
	short direction;
	short overrideSelect;
	short pad2;
	short mode;
	TMovePosUnion data;
}TMultiMovePosParameter;

typedef struct  
{
	short profile;
	short pad1[3];
	double pos[2];
	double vel[2];
	double acc;
	double dec;
	short direction;
	short overrideSelect;
	short pad2;
	short mode;
	TMovePosUnion data;
}TMultiMovePosTwoSegmentParameter;
GT_API GTN_MovePos(short core,short profile,TMovePosParameter *pMovePos,TListInfo *pListInfo=NULL,short group=0);
GT_API GTN_MovePosTwoSegment(short core,short profile,TMovePosTwoSegmentParameter *pMovePos,TListInfo *pListInfo=NULL,short group=0);