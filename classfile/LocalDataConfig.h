//
//  LocalDataConfig.h
//  game1
//  使用结构体来进行游戏属性存储会比较方便快捷
//
//  Created by 俊盟科技1 on 8/22/14.
//
//

#ifndef game1_LocalDataConfig_h
#define game1_LocalDataConfig_h
#include "cocos2d.h"
using namespace std;

//示例宏定义，不使用时可删除
#define ktestWar 1

struct tab_bosslevelEffectDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int Level = 0;        //等级 
    int EffectCount = 0;        //射击效果数 
};
typedef struct tab_bosslevelEffectDataStruct Configtab_bosslevelEffectDataST;

struct tab_bossShootEffectDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int InGameName = 0;        //名字索引 
    int LastTime = 0;        //持续秒数 
};
typedef struct tab_bossShootEffectDataStruct Configtab_bossShootEffectDataST;

struct tab_CharacterAttrDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int Level = 0;        //等级 
    int Type = 0;        //类型 
    int InGameName = 0;        //名字索引 
    int TrainCost = 0;        //花费 
    int UpgradeCost = 0;        //升级 
    int UpgradeTime = 0;        //升级时间（分钟） 
    int UpdateDiamond = 0;        //直接升级需求钻石 
    int Hurt = 0;        //伤害 
    int Velocity = 0;        //攻击速度 
    int Hp = 0;        //血量 
    int CostUnit = 0;        //花费单位 
    int FightCapacity = 0;        //战斗力 
};
typedef struct tab_CharacterAttrDataStruct Configtab_CharacterAttrDataST;

struct tab_CharacterContainerDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int Type = 0;        //类型 
    int HowmanyGrids = 0;        //兵种所占格子数 
};
typedef struct tab_CharacterContainerDataStruct Configtab_CharacterContainerDataST;

struct tab_CharacterMovePatternsDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int Type = 0;        //角色类型 
    int Stable = 0;        //固定 
    int Left = 0;        //左 
    int Right = 0;        //右 
    int Up = 0;        //上 
    int Down = 0;        //下 
    int TowardPlayer = 0;        //向攻击者移动 
};
typedef struct tab_CharacterMovePatternsDataStruct Configtab_CharacterMovePatternsDataST;

struct tab_CharacterShootPatternsDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int Type = 0;        //角色类型 
    int LightBullet = 0;        //轻型子弹 
    int HeavyBullet = 0;        //重型子弹 
    int Missile = 0;        //导弹 
    int Nightning = 0;        //闪电 
    int Fog = 0;        //喷雾 
    int Wind = 0;        //吹风 
    int Archibald = 0;        //高射炮弹 
};
typedef struct tab_CharacterShootPatternsDataStruct Configtab_CharacterShootPatternsDataST;

struct tab_characterUnitsDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int UnitCount = 0;        //所占单元数 
};
typedef struct tab_characterUnitsDataStruct Configtab_characterUnitsDataST;

struct tab_ChooseAttackerDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int Level = 0;        //等级 
    int NeedCoins = 0;        //所需金币数 
};
typedef struct tab_ChooseAttackerDataStruct Configtab_ChooseAttackerDataST;

struct tab_FogChamberLevelAttrDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int Level = 0;        //等级 
    int FogHeight = 0;        //雾气的高度 
    int showTime = 0;        //显示的秒数 
};
typedef struct tab_FogChamberLevelAttrDataStruct Configtab_FogChamberLevelAttrDataST;

struct tab_GoldenTreeDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int Level = 0;        //等级 
    int InGameName = 0;        //名字索引 
    int TrainCost = 0;        //花费 
    int UpgradeCost = 0;        //升级 
    int UpgradeTime = 0;        //升级时间（分钟） 
    int UpdateDiamond = 0;        //直接升级需求钻石 
    int CoinsPerHour = 0;        //每小时生成金币数 
};
typedef struct tab_GoldenTreeDataStruct Configtab_GoldenTreeDataST;

struct tab_InitialValuesDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int InitCoins = 0;        //初始金币数 
    int InitDiamonds = 0;        //初始钻石数 
};
typedef struct tab_InitialValuesDataStruct Configtab_InitialValuesDataST;

struct tab_InvisibilitySkillDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int Level = 0;        //等级 
    int InGameName = 0;        //名字索引 
    int TrainCost = 0;        //花费 
    int UpgradeCost = 0;        //升级 
    int UpgradeTime = 0;        //升级时间（分钟） 
    int UpdateDiamond = 0;        //直接升级需求钻石 
    int HideSeconds = 0;        //隐身秒数 
};
typedef struct tab_InvisibilitySkillDataStruct Configtab_InvisibilitySkillDataST;

struct tab_LevelBuyContainersDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int Level = 0;        //等级 
    int CanBuyBarrack = 0;        //能购买兵营数 
    int CanBuyAirport = 0;        //能购买机场数 
};
typedef struct tab_LevelBuyContainersDataStruct Configtab_LevelBuyContainersDataST;

struct tab_LevelLockedCharactersDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int Level = 0;        //等级 
    int Solider = 0;        //能否购买 
    int  Tank = 0;        //能否购买 
    int Archibald = 0;        //能否购买 
    int Kamikaze = 0;        //能否购买 
    int Missile = 0;        //能否购买 
    int VoltageTower = 0;        //能否购买 
    int windmill = 0;        //能否购买 
    int fogChamber = 0;        //能否购买 
};
typedef struct tab_LevelLockedCharactersDataStruct Configtab_LevelLockedCharactersDataST;

struct tab_MissileLevelAttrDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int Level = 0;        //等级 
    int FollowupTime = 0;        //跟踪攻击者持续时间 
};
typedef struct tab_MissileLevelAttrDataStruct Configtab_MissileLevelAttrDataST;

struct tab_PlaneShootEffectDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int Type = 0;        //角色类型 
    int EffectNo = 0;        //动画编号 
};
typedef struct tab_PlaneShootEffectDataStruct Configtab_PlaneShootEffectDataST;

struct tab_PowerupRuleDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int Level = 0;        //等级 
    int Coins = 0;        //掉落金币概率 
    int CoinLowBound = 0;        //掉落金币数量下限 
    int CoinUpperBound = 0;        //掉落金币数量上限 
    int LifePoints = 0;        //掉落生命值概率 
    int LifeLowBound = 0;        //掉落生命值数量下限 
    int LifeUpperBound = 0;        //掉落生命值数量上限 
    int Bomb = 0;        //掉落炸弹概率 
    int Shield = 0;        //掉落防护罩概率 
    int Life = 0;        //主机数量加1概率 
};
typedef struct tab_PowerupRuleDataStruct Configtab_PowerupRuleDataST;

struct tab_ScoreRuleDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int ScoreAddPerPoint = 0;        //伤害对方加分数量 
    int ScoreAddWin = 0;        //获胜后加分数量 
    int CoinsAddWin = 0;        //获胜后增加金币百分比 
    int ScoreSubPerPoint = 0;        //防御时自己减分数量 
    int ScoreSubLose = 0;        //失败后减分数量 
    int CoinsSubLose = 0;        //失败后减少金币百分比 
};
typedef struct tab_ScoreRuleDataStruct Configtab_ScoreRuleDataST;

struct tab_SetmapUnitLimitDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int Level = 0;        //等级 
    int InGameName = 0;        //名字索引 
    int UnitLimits = 0;        //单元上限 
};
typedef struct tab_SetmapUnitLimitDataStruct Configtab_SetmapUnitLimitDataST;

struct tab_ShieldSkillDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int Level = 0;        //等级 
    int InGameName = 0;        //名字索引 
    int TrainCost = 0;        //花费 
    int UpgradeCost = 0;        //升级 
    int UpgradeTime = 0;        //升级时间（分钟） 
    int UpdateDiamond = 0;        //直接升级需求钻石 
    int DefenseAdd = 0;        //增加防御值 
};
typedef struct tab_ShieldSkillDataStruct Configtab_ShieldSkillDataST;

struct tab_ShieldTimeAttrDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int InGameName = 0;        //名字索引 
    int Cost = 0;        //花费钻石数 
    int CoinsMulti = 0;        //获得金币倍数 
};
typedef struct tab_ShieldTimeAttrDataStruct Configtab_ShieldTimeAttrDataST;

struct tab_SkillLastTimeDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int LastTime = 0;        //持续秒数 
};
typedef struct tab_SkillLastTimeDataStruct Configtab_SkillLastTimeDataST;

struct tab_UnitContainerDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int Level = 0;        //等级 
    int Type = 0;        //类型 
    int InGameName = 0;        //名字索引 
    int TrainCost = 0;        //花费 
    int UpgradeCost = 0;        //升级 
    int UpgradeTime = 0;        //升级时间（分钟） 
    int UpdateDiamond = 0;        //直接升级需求钻石 
    int UnitCount = 0;        //容纳单元数 
};
typedef struct tab_UnitContainerDataStruct Configtab_UnitContainerDataST;

struct tab_VoltageTowerLevelAttrDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int Level = 0;        //等级 
    int ShootDist = 0;        //射击距离 
};
typedef struct tab_VoltageTowerLevelAttrDataStruct Configtab_VoltageTowerLevelAttrDataST;

struct tab_WindMillLevelAttrDataStruct
{
    int ID = 0;       //Id 
    string Comment = "";        //描述 
    int Level = 0;        //等级 
    int LetPlaneMoves = 0;        //推动飞机移动距离 
};
typedef struct tab_WindMillLevelAttrDataStruct Configtab_WindMillLevelAttrDataST;


#endif