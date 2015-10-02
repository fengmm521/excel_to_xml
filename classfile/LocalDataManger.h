//
//  LocalDataManger.h
//  game1
//  C++单例类模板，非线程安全单例类，并且实例化后会常注内存
//
//  Created by 俊盟科技1 on 8/22/14.
//
//  本地数据管理类
//

#ifndef __game1__LocalDataManger__
#define __game1__LocalDataManger__

#include "cocos2d.h"
#include "LocalDataConfig.h"
using namespace std;
class LocalDataManger:public cocos2d::Ref
{
public:
    static LocalDataManger* sharedLocalDataManger();
    static void destroyInstance();
private:
    /**
     * @js ctor
     */
    LocalDataManger(void);
    /**
     * @js NA
     * @lua NA
     */
    ~LocalDataManger(void);
    
    map<int,Configtab_bosslevelEffectDataST>  maptab_bosslevelEffectData;
    map<int,Configtab_bossShootEffectDataST>  maptab_bossShootEffectData;
    map<int,Configtab_CharacterAttrDataST>  maptab_CharacterAttrData;
    map<int,Configtab_CharacterContainerDataST>  maptab_CharacterContainerData;
    map<int,Configtab_CharacterMovePatternsDataST>  maptab_CharacterMovePatternsData;
    map<int,Configtab_CharacterShootPatternsDataST>  maptab_CharacterShootPatternsData;
    map<int,Configtab_characterUnitsDataST>  maptab_characterUnitsData;
    map<int,Configtab_ChooseAttackerDataST>  maptab_ChooseAttackerData;
    map<int,Configtab_FogChamberLevelAttrDataST>  maptab_FogChamberLevelAttrData;
    map<int,Configtab_GoldenTreeDataST>  maptab_GoldenTreeData;
    map<int,Configtab_InitialValuesDataST>  maptab_InitialValuesData;
    map<int,Configtab_InvisibilitySkillDataST>  maptab_InvisibilitySkillData;
    map<int,Configtab_LevelBuyContainersDataST>  maptab_LevelBuyContainersData;
    map<int,Configtab_LevelLockedCharactersDataST>  maptab_LevelLockedCharactersData;
    map<int,Configtab_MissileLevelAttrDataST>  maptab_MissileLevelAttrData;
    map<int,Configtab_PlaneShootEffectDataST>  maptab_PlaneShootEffectData;
    map<int,Configtab_PowerupRuleDataST>  maptab_PowerupRuleData;
    map<int,Configtab_ScoreRuleDataST>  maptab_ScoreRuleData;
    map<int,Configtab_SetmapUnitLimitDataST>  maptab_SetmapUnitLimitData;
    map<int,Configtab_ShieldSkillDataST>  maptab_ShieldSkillData;
    map<int,Configtab_ShieldTimeAttrDataST>  maptab_ShieldTimeAttrData;
    map<int,Configtab_SkillLastTimeDataST>  maptab_SkillLastTimeData;
    map<int,Configtab_UnitContainerDataST>  maptab_UnitContainerData;
    map<int,Configtab_VoltageTowerLevelAttrDataST>  maptab_VoltageTowerLevelAttrData;
    map<int,Configtab_WindMillLevelAttrDataST>  maptab_WindMillLevelAttrData;

    string getXmlFile(string path);
public:
    
    /**
     * Init LocalDataManger
     */
    virtual bool init();

    void readConfigtab_bosslevelEffectData();
    Configtab_bosslevelEffectDataST  getConfigtab_bosslevelEffectDataST(int ID);

    void readConfigtab_bossShootEffectData();
    Configtab_bossShootEffectDataST  getConfigtab_bossShootEffectDataST(int ID);

    void readConfigtab_CharacterAttrData();
    Configtab_CharacterAttrDataST  getConfigtab_CharacterAttrDataST(int ID);

    void readConfigtab_CharacterContainerData();
    Configtab_CharacterContainerDataST  getConfigtab_CharacterContainerDataST(int ID);

    void readConfigtab_CharacterMovePatternsData();
    Configtab_CharacterMovePatternsDataST  getConfigtab_CharacterMovePatternsDataST(int ID);

    void readConfigtab_CharacterShootPatternsData();
    Configtab_CharacterShootPatternsDataST  getConfigtab_CharacterShootPatternsDataST(int ID);

    void readConfigtab_characterUnitsData();
    Configtab_characterUnitsDataST  getConfigtab_characterUnitsDataST(int ID);

    void readConfigtab_ChooseAttackerData();
    Configtab_ChooseAttackerDataST  getConfigtab_ChooseAttackerDataST(int ID);

    void readConfigtab_FogChamberLevelAttrData();
    Configtab_FogChamberLevelAttrDataST  getConfigtab_FogChamberLevelAttrDataST(int ID);

    void readConfigtab_GoldenTreeData();
    Configtab_GoldenTreeDataST  getConfigtab_GoldenTreeDataST(int ID);

    void readConfigtab_InitialValuesData();
    Configtab_InitialValuesDataST  getConfigtab_InitialValuesDataST(int ID);

    void readConfigtab_InvisibilitySkillData();
    Configtab_InvisibilitySkillDataST  getConfigtab_InvisibilitySkillDataST(int ID);

    void readConfigtab_LevelBuyContainersData();
    Configtab_LevelBuyContainersDataST  getConfigtab_LevelBuyContainersDataST(int ID);

    void readConfigtab_LevelLockedCharactersData();
    Configtab_LevelLockedCharactersDataST  getConfigtab_LevelLockedCharactersDataST(int ID);

    void readConfigtab_MissileLevelAttrData();
    Configtab_MissileLevelAttrDataST  getConfigtab_MissileLevelAttrDataST(int ID);

    void readConfigtab_PlaneShootEffectData();
    Configtab_PlaneShootEffectDataST  getConfigtab_PlaneShootEffectDataST(int ID);

    void readConfigtab_PowerupRuleData();
    Configtab_PowerupRuleDataST  getConfigtab_PowerupRuleDataST(int ID);

    void readConfigtab_ScoreRuleData();
    Configtab_ScoreRuleDataST  getConfigtab_ScoreRuleDataST(int ID);

    void readConfigtab_SetmapUnitLimitData();
    Configtab_SetmapUnitLimitDataST  getConfigtab_SetmapUnitLimitDataST(int ID);

    void readConfigtab_ShieldSkillData();
    Configtab_ShieldSkillDataST  getConfigtab_ShieldSkillDataST(int ID);

    void readConfigtab_ShieldTimeAttrData();
    Configtab_ShieldTimeAttrDataST  getConfigtab_ShieldTimeAttrDataST(int ID);

    void readConfigtab_SkillLastTimeData();
    Configtab_SkillLastTimeDataST  getConfigtab_SkillLastTimeDataST(int ID);

    void readConfigtab_UnitContainerData();
    Configtab_UnitContainerDataST  getConfigtab_UnitContainerDataST(int ID);

    void readConfigtab_VoltageTowerLevelAttrData();
    Configtab_VoltageTowerLevelAttrDataST  getConfigtab_VoltageTowerLevelAttrDataST(int ID);

    void readConfigtab_WindMillLevelAttrData();
    Configtab_WindMillLevelAttrDataST  getConfigtab_WindMillLevelAttrDataST(int ID);

    
};

#endif /* defined(__game1__LocalDataManger__) */