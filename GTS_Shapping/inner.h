#pragma once
//////////////////////////////////////////////////////////////////////////
//本头文件包含未明确开放给用户使用的指令
//////////////////////////////////////////////////////////////////////////

/*-----------------------------------------------------------*/
/* Old Watch                                                */
/*-----------------------------------------------------------*/
#define WATCH_LIST_MAX                                  (8)
#define WATCH_LENGTH_MAX                                (32)
#define WATCH_FIFO_SIZE                                 (0x1E0)       // 480 word

#define WATCH_ADDRESS_TYPE_PRF_POS						(0)
#define WATCH_ADDRESS_TYPE_PRF_VEL						(1)
#define WATCH_ADDRESS_TYPE_ENC_POS						(2)
#define WATCH_ADDRESS_TYPE_ENC_VEL						(3)
#define WATCH_ADDRESS_TYPE_AXIS_PRF_POS					(4)
#define WATCH_ADDRESS_TYPE_AXIS_PRF_VEL					(5)
#define WATCH_ADDRESS_TYPE_AXIS_ENC_POS					(6)
#define WATCH_ADDRESS_TYPE_AXIS_ENC_VEL					(7)
#define WATCH_ADDRESS_TYPE_DAC							(8)
#define WATCH_ADDRESS_TYPE_LMT_POS						(9)
#define WATCH_ADDRESS_TYPE_LMT_NEG						(10)
#define WATCH_ADDRESS_TYPE_ALARM						(11)
#define WATCH_ADDRESS_TYPE_HOME							(12)
#define WATCH_ADDRESS_TYPE_GPI							(13)
#define WATCH_ADDRESS_TYPE_ENABLE						(14)
#define WATCH_ADDRESS_TYPE_CLEAR						(15)
#define WATCH_ADDRESS_TYPE_GPO							(16)
#define WATCH_ADDRESS_TYPE_CLOCK						(17)
#define WATCH_ADDRESS_TYPE_FLASH_BUFFER					(18)
#define WATCH_ADDRESS_TYPE_CRD_VEL						(19)
#define WATCH_ADDRESS_TYPE_ARRIVE						(20)
#define WATCH_ADDRESS_TYPE_POS_LOOP_ERROR				(21)
#define WATCH_ADDRESS_TYPE_POS_LOOP_OUTPUT				(22)
#define WATCH_ADDRESS_TYPE_POS_LOOP_INTERGRAL			(23)
#define WATCH_ADDRESS_TYPE_VEL_LOOP_ERROR				(24)
#define WATCH_ADDRESS_TYPE_VEL_LOOP_INTERGRAL			(25)
#define WATCH_ADDRESS_TYPE_SPRING_OFFSET				(26)
#define WATCH_ADDRESS_TYPE_BEFORE_SPRING				(27)
#define WATCH_ADDRESS_TYPE_AFTER_SPRING					(28)
#define WATCH_ADDRESS_TYPE_OBSERVER_LOWPASS_OUTPUT		(29)
#define WATCH_ADDRESS_TYPE_OBSERVER_OUTPUT_PRE			(30)
#define WATCH_ADDRESS_TYPE_OBSERVER_TORQUE_CMD_PRE		(31)
#define WATCH_ADDRESS_TYPE_OBSERVER_VEL_FEEDBACK_INTERGRAL		(32)
#define WATCH_ADDRESS_TYPE_OBSERVER_VEL_ERR_FEEDBACK_INTERGRAL	(33)

#define WATCH_ADDRESS_TYPE_ADC							(40)

#define WATCH_ADDRESS_TYPE_SCAN_SEGMENT_NUMBER			(200)

#define WATCH_ADDRESS_TYPE_SCAN_PRF_VEL					(210)

#define WATCH_ADDRESS_TYPE_SCAN_CRD_POS_X				(220)
#define WATCH_ADDRESS_TYPE_SCAN_CRD_POS_Y				(221)

#define WATCH_ADDRESS_TYPE_LASER_HSIO					(230)

#define WATCH_ADDRESS_TYPE_LASER_POWER					(240)

typedef struct Watch
{
	short count;
	short interval;
	unsigned long address[WATCH_LIST_MAX];
	short length[WATCH_LIST_MAX];
	unsigned long threshold;
} TWatch;

GT_API GT_SetWatch(TWatch *pWatch);
GT_API GT_StartWatch(void);
GT_API GT_StartWatchStatic(void);
GT_API GT_StopWatch(void);
GT_API GT_StopWatchStatic(void);
GT_API GT_LoadWatchFifo(short fifo,short *pBuf);
GT_API GT_GetWatchFifo(short *pFifo);
GT_API GT_GetWatchAddress(short type,short index,unsigned long *pAddress,short count=1);
GT_API GT_GetWatchSts(short *pRun,unsigned long *pCount);
GT_API GT_GetWatchData(unsigned long offset,short *pData,short count=1);

/*-----------------------------------------------------------*/
/* Flash Operation                                           */
/*-----------------------------------------------------------*/
typedef struct
{
	short vender;
	short deviceSizeExp;
	short eraseBlockRegion;
	short sector[4];
	short density[4];
} TFlashInfo;


GT_API GT_FlashToSdram(long *pRetry=NULL);
GT_API GT_SdramToFlash(long *pRetry=NULL);
GT_API GT_SdramToFlash2(long *pRetry=NULL);

GT_API GT_TestSdram(void);
GT_API GT_SetMemory(unsigned long address,short count,short *pData);
GT_API GT_GetMemory(unsigned long address,short count,short *pData);
GT_API GT_LoadWatchConfig(char *pFile);
GT_API GT_FlashQuery(TFlashInfo *pFlashInfo);
GT_API GT_FlashReadId(short *pMid,short *pDid);
GT_API GT_FlashBlockErase(unsigned long offset);
GT_API GT_FlashRead(unsigned long offset,short count,short *pData);
GT_API GT_FlashProgram(unsigned long offset,short count,short *pData,long *pRetry=NULL);
GT_API GT_FlashSetReg(short chip,short index,short value);
GT_API GT_FlashGetReg(short chip,short index,short *pValue);
GT_API GT_FlashSelect(short chip,short port,short module);
GT_API GT_SetRetainValue(unsigned long address,short count,short *pData);
GT_API GT_GetRetainValue(unsigned long address,short count,short *pData);

GT_API GTN_FlashToSdram(short core,long *pRetry);
GT_API GTN_SdramToFlash(short core,long *pRetry);

GT_API GTN_FlashQuery(short core,TFlashInfo *pFlashInfo);
GT_API GTN_FlashReadId(short core,short *pMid,short *pDid);
GT_API GTN_FlashBlockErase(short core,unsigned long offset);
GT_API GTN_FlashRead(short core,unsigned long offset,short count,short *pData);
GT_API GTN_FlashProgram(short core,unsigned long offset,short count,short *pData,long *pRetry=NULL);
GT_API GTN_FlashSetReg(short core,short chip,short index,short value);
GT_API GTN_FlashGetReg(short core,short chip,short index,short *pValue);
GT_API GTN_FlashSelect(short core,short chip,short port,short module);

GT_API GT_GetFlashPassword(unsigned short *pPassword);
GT_API GT_CheckFlashPassword(void);

GT_API GT_CheckPassword(char *pPassword);
GT_API GT_ModifyPassword(char *pOldPassword,char *pNewPassword);

/*-----------------------------------------------------------*/
/* New Watch                                                  */
/*-----------------------------------------------------------*/
#define MC_WATCH_VAR                    (200)
#define MC_WATCH_EVENT                  (201)


#define WATCH_VAR_CLOCK						(1200)
#define WATCH_VAR_PRF_LOOP					(1201)

#define WATCH_VAR_SKIP_MODULE				(1211)
#define WATCH_VAR_TEST_MODE					(1212)

#define WATCH_VAR_COMMAND_CODE				(1220)
#define WATCH_VAR_COMMAND_DATA				(1221)
#define WATCH_VAR_COMMAND_COUNT				(1222)
#define WATCH_VAR_COMMAND_READ_FLAG 		(1223)

#define WATCH_VAR_LINK_PORT_TX_USE			(1660)
#define WATCH_VAR_LINK_PORT_TX_REQUIRE		(1661)

#define WATCH_VAR_PRF_POS					(20010)
#define WATCH_VAR_PRF_VEL					(6001)
#define WATCH_VAR_PRF_ACC					(6002)

#define WATCH_VAR_PRF_RUN					(6200)

#define WATCH_VAR_PT_PRF_POS_F64			(6650)

#define WATCH_VAR_CRD_PRF_POS				(8000)
#define WATCH_VAR_CRD_PRF_VEL				(8001)
#define WATCH_VAR_CRD_PRF_ACC				(8002)

#define WATCH_VAR_CRD_RUN					(8200)

#define WATCH_VAR_CRD_SEGMENT_NUMBER		(8202)
#define WATCH_VAR_CRD_SEGMENT_NUMBER_USER	(8203)
#define WATCH_VAR_CRD_COMMAND_RECEIVE		(8204)
#define WATCH_VAR_CRD_COMMAND_EXECUTE		(8205)

#define WATCH_VAR_POS_COMPARE_COMMAND_RECEIVE	(17422)
#define WATCH_VAR_POS_COMPARE_COMMAND_SEND		(17423)
#define WATCH_VAR_POS_COMPARE_COMMAND_LEFT		(17424)
#define WATCH_VAR_POS_COMPARE_COMMAND_TX		(17425)

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

#define WATCH_VAR_AXIS_PRF_POS				(20000)
#define WATCH_VAR_AXIS_PRF_VEL				(20001)
#define WATCH_VAR_AXIS_PRF_ACC				(20002)

#define WATCH_VAR_AXIS_PRF_POS_OTHER		(20004)
#define WATCH_VAR_AXIS_PRF_VEL_OTHER		(20005)

#define WATCH_VAR_AXIS_PRF_VEL_FILTER		(20011)

#define WATCH_VAR_AXIS_STATUS		        (20100)

#define WATCH_VAR_ENC_POS					(30000)

#define WATCH_VAR_GPI						(31000)
#define WATCH_VAR_LIMIT_POSITIVE			(31010)
#define WATCH_VAR_LIMIT_NEGATIVE			(31020)
#define WATCH_VAR_ALARM   		        	(31030)
#define WATCH_VAR_HOME             			(31040)
#define WATCH_VAR_ARRIVE           			(31050)

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

#define WATCH_VAR_WATCH_TIME				(52001)

#define WATCH_VAR_INT32						(52020)
#define WATCH_VAR_INT64						(52021)
#define WATCH_VAR_FLOAT						(52022)
#define WATCH_VAR_DOUBLE					(52023)

#define WATCH_VAR_TERMINAL_LIMIT_POSITIVE	(53000)
#define WATCH_VAR_TERMINAL_LIMIT_NEGATIVE	(53001)
#define WATCH_VAR_TERMINAL_ALARM			(53002)
#define WATCH_VAR_TERMINAL_HOME				(53003)
#define WATCH_VAR_TERMINAL_GPI				(53004)
#define WATCH_VAR_TERMINAL_ARRIVE			(53005)

#define WATCH_VAR_TERMINAL_MPG				(53009)
#define WATCH_VAR_TERMINAL_ENABLE			(53010)
#define WATCH_VAR_TERMINAL_CLEAR			(53011)
#define WATCH_VAR_TERMINAL_GPO				(53012)

#define WATCH_VAR_TERMINAL_DAC				(53020)

#define WATCH_VAR_TERMINAL_PULSE			(53022)
#define WATCH_VAR_TERMINAL_ENCODER			(53023)
#define WATCH_VAR_TERMINAL_ADC				(53024)

#define WATCH_VAR_TERMINAL_AU_ENCODER		(53026)

#define WATCH_VAR_TERMINAL_PRF_POS			(53030)

#define WATCH_VAR_TERMINAL_TRIGGER_POSITION	(53040)
#define WATCH_VAR_TERMINAL_TRIGGER_STATUS	(53041)

#define WATCH_VAR_TERMINAL_COMMAND			(53100)
#define WATCH_VAR_TERMINAL_STATUS			(53101)

typedef struct
{
	short enable;						// 采集使能
	short run;							// 采集状态
	unsigned long time;					// 采集次数
	unsigned long head;					// 头指针
	unsigned long threshold;			// 最多容纳采集次数

	short interval;						// 采集间隔
	short mode;							// 采集模式
	unsigned short countBeforeEvent;	// 事件触发之前的采集数量
	unsigned short countAfterEvent;		// 事件触发以后的采集数量
	unsigned short varCount;			// 采集变量数量
	unsigned short eventCount;			// 采集事件数量
} TWatchInfo;

typedef struct
{
	short width;
	short precision;
	char seperator;
	short hex;
} TWatchFormat;

GT_API GT_GetWatchInfo(TWatchInfo *pInfo);
GT_API GT_SetWatchFormat(const TWatchFormat *pFormat);
GT_API GT_GetWatchFormat(TWatchFormat *pFormat);
GT_API GT_GetWatchInfoEx(short group,TWatchInfo *pInfo);
GT_API GT_SetWatchFormatEx(short group,const TWatchFormat *pFormat);
GT_API GT_GetWatchFormatEx(short group,TWatchFormat *pFormat);

GT_API GTN_GetWatchInfo(short core,TWatchInfo *pInfo);
GT_API GTN_SetWatchFormat(short core,const TWatchFormat *pFormat);
GT_API GTN_GetWatchFormat(short core,TWatchFormat *pFormat);
GT_API GTN_SetWatchFormatEx(short core,short group,const TWatchFormat *pFormat);
GT_API GTN_GetWatchFormatEx(short core,short group,TWatchFormat *pFormat);
GT_API GTN_GetWatchInfoEx(short core,short group,TWatchInfo *pInfo);

#define WATCH_GROUP_TIMER					(0)
#define WATCH_GROUP_BACKGROUND				(1)

#define WATCH_LOAD_MODE_NONE				(0)
#define WATCH_LOAD_MODE_BOOT				(2)
#define WATCH_LOAD_MODE_RUN					(3)

#define WATCH_MODE_STATIC					(0)
#define WATCH_MODE_LOOP						(1)
#define WATCH_MODE_DYNAMIC					(2)

#define WATCH_EVENT_RUN						(1)
#define WATCH_EVENT_START					(10)
#define WATCH_EVENT_STOP					(20)
#define WATCH_EVENT_OFF						(30)

#define WATCH_CONDITION_EQ					(1)
#define WATCH_CONDITION_NE					(2)
#define WATCH_CONDITION_GE					(3)
#define WATCH_CONDITION_LE					(4)

#define WATCH_CONDITION_CHANGE_TO			(11)
#define WATCH_CONDITION_CHANGE				(12)
#define WATCH_CONDITION_UP					(13)
#define WATCH_CONDITION_DOWN				(14)

#define WATCH_CONDITION_REMAIN_AT			(21)
#define WATCH_CONDITION_REMAIN				(22)
#define WATCH_CONDITION_CROSS_POSITIVE		(23)
#define WATCH_CONDITION_CROSS_NEGATIVE		(24)

#define WATCH_CONDITION_NEAREST				(31)
#define WATCH_CONDITION_DELTA				(32)

//typedef struct
//{
//	unsigned short type;
//	unsigned short index;
//	unsigned short id;
//} TWatchVar;

typedef struct
{
	unsigned short type;
	unsigned short loop;
	unsigned short watchCount;
	TWatchVar var;
	unsigned short condition;
	double value;
} TWatchEvent;

typedef struct
{
	unsigned long *pAddress;
	unsigned short length;
	short fraction;
	unsigned short format;
	unsigned short hex;
	unsigned short sign;
	unsigned short bit;
} TWatchVarInfo;

GT_API GT_SetWatchGroup(short group);
GT_API GT_GetWatchGroup(short *pGroup);
GT_API GT_PrintWatch(const char *pFileName,long start=0,unsigned long printCount=0);
GT_API GT_ReadWatch(short varIndex,double *pBuffer,unsigned long bufferSize,unsigned long *pReadCount);
GT_API GT_ProgramWatch(short loadMode);
GT_API GT_GetWatchLoadMode(short group,short *pLoadMode);
GT_API GT_GetMcVar(const TWatchVar *pVar,double *pValue);

GT_API GT_ClearWatch(short mode=0);
GT_API GT_AddWatchVar(const TWatchVar *pVar);
GT_API GT_AddWatchEvent(const TWatchEvent *pEvent);
GT_API GT_WatchOn(short interval=0,short mode=WATCH_MODE_STATIC,unsigned short count=0);
GT_API GT_WatchOff(void);

GT_API GT_GetWatchEvent(short index,TWatchEvent *pEvent);
GT_API GT_GetWatchVar(short index,TWatchVar *pVar,TWatchVarInfo *pVarInfo);
GT_API GT_SetWatchModeEx(short group,short mode);
GT_API GT_SetWatchIntervalEx(short group,short interval);

GT_API GTN_SetWatchGroup(short core,short group);
GT_API GTN_GetWatchGroup(short core,short *pGroup);
GT_API GTN_LoadWatchConfig(short core,char *pFile);
GT_API GTN_SaveWatchConfig(short core,short group,char *pFile);
GT_API GTN_PrintWatch(short core,const char *pFileName,long start=0,unsigned long printCount=0);
GT_API GTN_ReadWatch(short core,short varIndex,double *pBuffer,unsigned long bufferSize,unsigned long *pReadCount);
GT_API GTN_ProgramWatch(short core,short loadMode);
GT_API GTN_GetWatchLoadMode(short core,short group,short *pLoadMode);
GT_API GTN_GetMcVar(short core,const TWatchVar *pVar,double *pValue);

GT_API GTN_ClearWatch(short core,short mode=0);
GT_API GTN_AddWatchVar(short core,const TWatchVar *pVar);
GT_API GTN_AddWatchEvent(short core,const TWatchEvent *pEvent);
GT_API GTN_WatchOn(short core,short interval=0,short mode=WATCH_MODE_STATIC,unsigned short count=0);
GT_API GTN_WatchOff(short core);

GT_API GTN_GetWatchEvent(short core,short index,TWatchEvent *pEvent);
GT_API GTN_GetWatchVar(short core,short index,TWatchVar *pVar,TWatchVarInfo *pVarInfo);
GT_API GTN_SetWatchModeEx(short core,short group,short mode);
GT_API GTN_SetWatchIntervalEx(short core,short group,short interval);

/*-----------------------------------------------------------*/
/* Others                                                    */
/*-----------------------------------------------------------*/
GT_API GTN_SetUuid(short core,char *pCode,short count);