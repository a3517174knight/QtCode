
***************************************************************************
			头文件
***************************************************************************
gts.h：基本功能指令（必需的，其它头文件如果没有使用相关功能则可以不包含）
LookAheadEx.h：新前瞻指令
config.h：配置，包括主卡、模块（添加到等环网头文件）
ringnet.h：等环网

头文件使用顺序，一定要把gts.h排在其它之前
***************************************************************************

***************************************************************************
			动态链接库（DLL）
***************************************************************************
gts.dll：基本功能函数库（必需的）
LAFunc.dll：新前瞻相关库
PIFunc.dll：新前瞻相关库
VFunc.dll：新前瞻相关库
gt_rn.dll：网络配置（必需的）

gts.dll、gt_rn.dll、RingNetDmaCfg.rndma、RingNetMapSUB6.rnmap是必需的，一定要
放到程序路径下；如果不使用新前瞻功能则新前瞻相关库无需放到程序路径。

***************************************************************************