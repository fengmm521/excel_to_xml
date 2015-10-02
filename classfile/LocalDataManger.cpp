//
//  LocalDataManger.cpp
//  game1
//
//  Created by 俊盟科技1 on 8/22/14.
//
//

#include "LocalDataManger.h"
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "rapidxml_print.hpp"
#include "LocalFileManger.h"
using namespace rapidxml;
using namespace cocos2d;
static LocalDataManger *s_sharedLocalDataManger = nullptr;

LocalDataManger *LocalDataManger::sharedLocalDataManger()
{
    if (s_sharedLocalDataManger == nullptr)
    {
        s_sharedLocalDataManger = new LocalDataManger();
        if (!s_sharedLocalDataManger || !s_sharedLocalDataManger->init())
        {
            CC_SAFE_DELETE(s_sharedLocalDataManger);
        }
    }
    return s_sharedLocalDataManger;
}

void LocalDataManger::destroyInstance()
{
    
    CC_SAFE_RELEASE_NULL(s_sharedLocalDataManger);
}

LocalDataManger::LocalDataManger(void)
{
  
}

LocalDataManger::~LocalDataManger(void)
{
   
}


bool LocalDataManger::init()
{
    bool bRet = false;
    do
    {
        maptab_bosslevelEffectData.clear();
        maptab_bossShootEffectData.clear();
        maptab_CharacterAttrData.clear();
        maptab_CharacterContainerData.clear();
        maptab_CharacterMovePatternsData.clear();
        maptab_CharacterShootPatternsData.clear();
        maptab_characterUnitsData.clear();
        maptab_ChooseAttackerData.clear();
        maptab_FogChamberLevelAttrData.clear();
        maptab_GoldenTreeData.clear();
        maptab_InitialValuesData.clear();
        maptab_InvisibilitySkillData.clear();
        maptab_LevelBuyContainersData.clear();
        maptab_LevelLockedCharactersData.clear();
        maptab_MissileLevelAttrData.clear();
        maptab_PlaneShootEffectData.clear();
        maptab_PowerupRuleData.clear();
        maptab_ScoreRuleData.clear();
        maptab_SetmapUnitLimitData.clear();
        maptab_ShieldSkillData.clear();
        maptab_ShieldTimeAttrData.clear();
        maptab_SkillLastTimeData.clear();
        maptab_UnitContainerData.clear();
        maptab_VoltageTowerLevelAttrData.clear();
        maptab_WindMillLevelAttrData.clear();
#if 1
        readConfigtab_bosslevelEffectData();
        readConfigtab_bossShootEffectData();
        readConfigtab_CharacterAttrData();
        readConfigtab_CharacterContainerData();
        readConfigtab_CharacterMovePatternsData();
        readConfigtab_CharacterShootPatternsData();
        readConfigtab_characterUnitsData();
        readConfigtab_ChooseAttackerData();
        readConfigtab_FogChamberLevelAttrData();
        readConfigtab_GoldenTreeData();
        readConfigtab_InitialValuesData();
        readConfigtab_InvisibilitySkillData();
        readConfigtab_LevelBuyContainersData();
        readConfigtab_LevelLockedCharactersData();
        readConfigtab_MissileLevelAttrData();
        readConfigtab_PlaneShootEffectData();
        readConfigtab_PowerupRuleData();
        readConfigtab_ScoreRuleData();
        readConfigtab_SetmapUnitLimitData();
        readConfigtab_ShieldSkillData();
        readConfigtab_ShieldTimeAttrData();
        readConfigtab_SkillLastTimeData();
        readConfigtab_UnitContainerData();
        readConfigtab_VoltageTowerLevelAttrData();
        readConfigtab_WindMillLevelAttrData();
#endif
        bRet = true;
    }
    while (0);
    
    return bRet;
}
//tab_bosslevelEffect
void LocalDataManger::readConfigtab_bosslevelEffectData()
{
    if(!maptab_bosslevelEffectData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_bosslevelEffect.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *Levelx = node->first_node("Level");
        xml_node<> *EffectCountx = node->first_node("EffectCount");
        Configtab_bosslevelEffectDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.Level = atoi(Levelx->value());
        st.EffectCount = atoi(EffectCountx->value());

        maptab_bosslevelEffectData[st.ID] = st;
    }
}
Configtab_bosslevelEffectDataST LocalDataManger::getConfigtab_bosslevelEffectDataST(int ID)
{
    return maptab_bosslevelEffectData[ID];
}

//tab_bossShootEffect
void LocalDataManger::readConfigtab_bossShootEffectData()
{
    if(!maptab_bossShootEffectData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_bossShootEffect.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *InGameNamex = node->first_node("InGameName");
        xml_node<> *LastTimex = node->first_node("LastTime");
        Configtab_bossShootEffectDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.InGameName = atoi(InGameNamex->value());
        st.LastTime = atoi(LastTimex->value());

        maptab_bossShootEffectData[st.ID] = st;
    }
}
Configtab_bossShootEffectDataST LocalDataManger::getConfigtab_bossShootEffectDataST(int ID)
{
    return maptab_bossShootEffectData[ID];
}

//tab_CharacterAttr
void LocalDataManger::readConfigtab_CharacterAttrData()
{
    if(!maptab_CharacterAttrData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_CharacterAttr.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *Levelx = node->first_node("Level");
        xml_node<> *Typex = node->first_node("Type");
        xml_node<> *InGameNamex = node->first_node("InGameName");
        xml_node<> *TrainCostx = node->first_node("TrainCost");
        xml_node<> *UpgradeCostx = node->first_node("UpgradeCost");
        xml_node<> *UpgradeTimex = node->first_node("UpgradeTime");
        xml_node<> *UpdateDiamondx = node->first_node("UpdateDiamond");
        xml_node<> *Hurtx = node->first_node("Hurt");
        xml_node<> *Velocityx = node->first_node("Velocity");
        xml_node<> *Hpx = node->first_node("Hp");
        xml_node<> *CostUnitx = node->first_node("CostUnit");
        xml_node<> *FightCapacityx = node->first_node("FightCapacity");
        Configtab_CharacterAttrDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.Level = atoi(Levelx->value());
        st.Type = atoi(Typex->value());
        st.InGameName = atoi(InGameNamex->value());
        st.TrainCost = atoi(TrainCostx->value());
        st.UpgradeCost = atoi(UpgradeCostx->value());
        st.UpgradeTime = atoi(UpgradeTimex->value());
        st.UpdateDiamond = atoi(UpdateDiamondx->value());
        st.Hurt = atoi(Hurtx->value());
        st.Velocity = atoi(Velocityx->value());
        st.Hp = atoi(Hpx->value());
        st.CostUnit = atoi(CostUnitx->value());
        st.FightCapacity = atoi(FightCapacityx->value());

        maptab_CharacterAttrData[st.ID] = st;
    }
}
Configtab_CharacterAttrDataST LocalDataManger::getConfigtab_CharacterAttrDataST(int ID)
{
    return maptab_CharacterAttrData[ID];
}

//tab_CharacterContainer
void LocalDataManger::readConfigtab_CharacterContainerData()
{
    if(!maptab_CharacterContainerData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_CharacterContainer.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *Idx = node->first_node("Id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *Typex = node->first_node("Type");
        xml_node<> *HowmanyGridsx = node->first_node("HowmanyGrids");
        Configtab_CharacterContainerDataST st;

        st.ID = atoi(Idx->value());
        st.Comment = Commentx->value();
        st.Type = atoi(Typex->value());
        st.HowmanyGrids = atoi(HowmanyGridsx->value());

        maptab_CharacterContainerData[st.ID] = st;
    }
}
Configtab_CharacterContainerDataST LocalDataManger::getConfigtab_CharacterContainerDataST(int ID)
{
    return maptab_CharacterContainerData[ID];
}

//tab_CharacterMovePatterns
void LocalDataManger::readConfigtab_CharacterMovePatternsData()
{
    if(!maptab_CharacterMovePatternsData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_CharacterMovePatterns.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *Typex = node->first_node("Type");
        xml_node<> *Stablex = node->first_node("Stable");
        xml_node<> *Leftx = node->first_node("Left");
        xml_node<> *Rightx = node->first_node("Right");
        xml_node<> *Upx = node->first_node("Up");
        xml_node<> *Downx = node->first_node("Down");
        xml_node<> *TowardPlayerx = node->first_node("TowardPlayer");
        Configtab_CharacterMovePatternsDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.Type = atoi(Typex->value());
        st.Stable = atoi(Stablex->value());
        st.Left = atoi(Leftx->value());
        st.Right = atoi(Rightx->value());
        st.Up = atoi(Upx->value());
        st.Down = atoi(Downx->value());
        st.TowardPlayer = atoi(TowardPlayerx->value());

        maptab_CharacterMovePatternsData[st.ID] = st;
    }
}
Configtab_CharacterMovePatternsDataST LocalDataManger::getConfigtab_CharacterMovePatternsDataST(int ID)
{
    return maptab_CharacterMovePatternsData[ID];
}

//tab_CharacterShootPatterns
void LocalDataManger::readConfigtab_CharacterShootPatternsData()
{
    if(!maptab_CharacterShootPatternsData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_CharacterShootPatterns.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *Typex = node->first_node("Type");
        xml_node<> *LightBulletx = node->first_node("LightBullet");
        xml_node<> *HeavyBulletx = node->first_node("HeavyBullet");
        xml_node<> *Missilex = node->first_node("Missile");
        xml_node<> *Nightningx = node->first_node("Nightning");
        xml_node<> *Fogx = node->first_node("Fog");
        xml_node<> *Windx = node->first_node("Wind");
        xml_node<> *Archibaldx = node->first_node("Archibald");
        Configtab_CharacterShootPatternsDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.Type = atoi(Typex->value());
        st.LightBullet = atoi(LightBulletx->value());
        st.HeavyBullet = atoi(HeavyBulletx->value());
        st.Missile = atoi(Missilex->value());
        st.Nightning = atoi(Nightningx->value());
        st.Fog = atoi(Fogx->value());
        st.Wind = atoi(Windx->value());
        st.Archibald = atoi(Archibaldx->value());

        maptab_CharacterShootPatternsData[st.ID] = st;
    }
}
Configtab_CharacterShootPatternsDataST LocalDataManger::getConfigtab_CharacterShootPatternsDataST(int ID)
{
    return maptab_CharacterShootPatternsData[ID];
}

//tab_characterUnits
void LocalDataManger::readConfigtab_characterUnitsData()
{
    if(!maptab_characterUnitsData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_characterUnits.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *UnitCountx = node->first_node("UnitCount");
        Configtab_characterUnitsDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.UnitCount = atoi(UnitCountx->value());

        maptab_characterUnitsData[st.ID] = st;
    }
}
Configtab_characterUnitsDataST LocalDataManger::getConfigtab_characterUnitsDataST(int ID)
{
    return maptab_characterUnitsData[ID];
}

//tab_ChooseAttacker
void LocalDataManger::readConfigtab_ChooseAttackerData()
{
    if(!maptab_ChooseAttackerData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_ChooseAttacker.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *Levelx = node->first_node("Level");
        xml_node<> *NeedCoinsx = node->first_node("NeedCoins");
        Configtab_ChooseAttackerDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.Level = atoi(Levelx->value());
        st.NeedCoins = atoi(NeedCoinsx->value());

        maptab_ChooseAttackerData[st.ID] = st;
    }
}
Configtab_ChooseAttackerDataST LocalDataManger::getConfigtab_ChooseAttackerDataST(int ID)
{
    return maptab_ChooseAttackerData[ID];
}

//tab_FogChamberLevelAttr
void LocalDataManger::readConfigtab_FogChamberLevelAttrData()
{
    if(!maptab_FogChamberLevelAttrData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_FogChamberLevelAttr.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *Levelx = node->first_node("Level");
        xml_node<> *FogHeightx = node->first_node("FogHeight");
        xml_node<> *showTimex = node->first_node("showTime");
        Configtab_FogChamberLevelAttrDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.Level = atoi(Levelx->value());
        st.FogHeight = atoi(FogHeightx->value());
        st.showTime = atoi(showTimex->value());

        maptab_FogChamberLevelAttrData[st.ID] = st;
    }
}
Configtab_FogChamberLevelAttrDataST LocalDataManger::getConfigtab_FogChamberLevelAttrDataST(int ID)
{
    return maptab_FogChamberLevelAttrData[ID];
}

//tab_GoldenTree
void LocalDataManger::readConfigtab_GoldenTreeData()
{
    if(!maptab_GoldenTreeData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_GoldenTree.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *Levelx = node->first_node("Level");
        xml_node<> *InGameNamex = node->first_node("InGameName");
        xml_node<> *TrainCostx = node->first_node("TrainCost");
        xml_node<> *UpgradeCostx = node->first_node("UpgradeCost");
        xml_node<> *UpgradeTimex = node->first_node("UpgradeTime");
        xml_node<> *UpdateDiamondx = node->first_node("UpdateDiamond");
        xml_node<> *CoinsPerHourx = node->first_node("CoinsPerHour");
        Configtab_GoldenTreeDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.Level = atoi(Levelx->value());
        st.InGameName = atoi(InGameNamex->value());
        st.TrainCost = atoi(TrainCostx->value());
        st.UpgradeCost = atoi(UpgradeCostx->value());
        st.UpgradeTime = atoi(UpgradeTimex->value());
        st.UpdateDiamond = atoi(UpdateDiamondx->value());
        st.CoinsPerHour = atoi(CoinsPerHourx->value());

        maptab_GoldenTreeData[st.ID] = st;
    }
}
Configtab_GoldenTreeDataST LocalDataManger::getConfigtab_GoldenTreeDataST(int ID)
{
    return maptab_GoldenTreeData[ID];
}

//tab_InitialValues
void LocalDataManger::readConfigtab_InitialValuesData()
{
    if(!maptab_InitialValuesData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_InitialValues.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *InitCoinsx = node->first_node("InitCoins");
        xml_node<> *InitDiamondsx = node->first_node("InitDiamonds");
        Configtab_InitialValuesDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.InitCoins = atoi(InitCoinsx->value());
        st.InitDiamonds = atoi(InitDiamondsx->value());

        maptab_InitialValuesData[st.ID] = st;
    }
}
Configtab_InitialValuesDataST LocalDataManger::getConfigtab_InitialValuesDataST(int ID)
{
    return maptab_InitialValuesData[ID];
}

//tab_InvisibilitySkill
void LocalDataManger::readConfigtab_InvisibilitySkillData()
{
    if(!maptab_InvisibilitySkillData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_InvisibilitySkill.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *Levelx = node->first_node("Level");
        xml_node<> *InGameNamex = node->first_node("InGameName");
        xml_node<> *TrainCostx = node->first_node("TrainCost");
        xml_node<> *UpgradeCostx = node->first_node("UpgradeCost");
        xml_node<> *UpgradeTimex = node->first_node("UpgradeTime");
        xml_node<> *UpdateDiamondx = node->first_node("UpdateDiamond");
        xml_node<> *HideSecondsx = node->first_node("HideSeconds");
        Configtab_InvisibilitySkillDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.Level = atoi(Levelx->value());
        st.InGameName = atoi(InGameNamex->value());
        st.TrainCost = atoi(TrainCostx->value());
        st.UpgradeCost = atoi(UpgradeCostx->value());
        st.UpgradeTime = atoi(UpgradeTimex->value());
        st.UpdateDiamond = atoi(UpdateDiamondx->value());
        st.HideSeconds = atoi(HideSecondsx->value());

        maptab_InvisibilitySkillData[st.ID] = st;
    }
}
Configtab_InvisibilitySkillDataST LocalDataManger::getConfigtab_InvisibilitySkillDataST(int ID)
{
    return maptab_InvisibilitySkillData[ID];
}

//tab_LevelBuyContainers
void LocalDataManger::readConfigtab_LevelBuyContainersData()
{
    if(!maptab_LevelBuyContainersData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_LevelBuyContainers.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *Levelx = node->first_node("Level");
        xml_node<> *CanBuyBarrackx = node->first_node("CanBuyBarrack");
        xml_node<> *CanBuyAirportx = node->first_node("CanBuyAirport");
        Configtab_LevelBuyContainersDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.Level = atoi(Levelx->value());
        st.CanBuyBarrack = atoi(CanBuyBarrackx->value());
        st.CanBuyAirport = atoi(CanBuyAirportx->value());

        maptab_LevelBuyContainersData[st.ID] = st;
    }
}
Configtab_LevelBuyContainersDataST LocalDataManger::getConfigtab_LevelBuyContainersDataST(int ID)
{
    return maptab_LevelBuyContainersData[ID];
}

//tab_LevelLockedCharacters
void LocalDataManger::readConfigtab_LevelLockedCharactersData()
{
    if(!maptab_LevelLockedCharactersData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_LevelLockedCharacters.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *Levelx = node->first_node("Level");
        xml_node<> *Soliderx = node->first_node("Solider");
        xml_node<> * Tankx = node->first_node(" Tank");
        xml_node<> *Archibaldx = node->first_node("Archibald");
        xml_node<> *Kamikazex = node->first_node("Kamikaze");
        xml_node<> *Missilex = node->first_node("Missile");
        xml_node<> *VoltageTowerx = node->first_node("VoltageTower");
        xml_node<> *windmillx = node->first_node("windmill");
        xml_node<> *fogChamberx = node->first_node("fogChamber");
        Configtab_LevelLockedCharactersDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.Level = atoi(Levelx->value());
        st.Solider = atoi(Soliderx->value());
        st. Tank = atoi( Tankx->value());
        st.Archibald = atoi(Archibaldx->value());
        st.Kamikaze = atoi(Kamikazex->value());
        st.Missile = atoi(Missilex->value());
        st.VoltageTower = atoi(VoltageTowerx->value());
        st.windmill = atoi(windmillx->value());
        st.fogChamber = atoi(fogChamberx->value());

        maptab_LevelLockedCharactersData[st.ID] = st;
    }
}
Configtab_LevelLockedCharactersDataST LocalDataManger::getConfigtab_LevelLockedCharactersDataST(int ID)
{
    return maptab_LevelLockedCharactersData[ID];
}

//tab_MissileLevelAttr
void LocalDataManger::readConfigtab_MissileLevelAttrData()
{
    if(!maptab_MissileLevelAttrData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_MissileLevelAttr.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *Levelx = node->first_node("Level");
        xml_node<> *FollowupTimex = node->first_node("FollowupTime");
        Configtab_MissileLevelAttrDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.Level = atoi(Levelx->value());
        st.FollowupTime = atoi(FollowupTimex->value());

        maptab_MissileLevelAttrData[st.ID] = st;
    }
}
Configtab_MissileLevelAttrDataST LocalDataManger::getConfigtab_MissileLevelAttrDataST(int ID)
{
    return maptab_MissileLevelAttrData[ID];
}

//tab_PlaneShootEffect
void LocalDataManger::readConfigtab_PlaneShootEffectData()
{
    if(!maptab_PlaneShootEffectData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_PlaneShootEffect.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *Typex = node->first_node("Type");
        xml_node<> *EffectNox = node->first_node("EffectNo");
        Configtab_PlaneShootEffectDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.Type = atoi(Typex->value());
        st.EffectNo = atoi(EffectNox->value());

        maptab_PlaneShootEffectData[st.ID] = st;
    }
}
Configtab_PlaneShootEffectDataST LocalDataManger::getConfigtab_PlaneShootEffectDataST(int ID)
{
    return maptab_PlaneShootEffectData[ID];
}

//tab_PowerupRule
void LocalDataManger::readConfigtab_PowerupRuleData()
{
    if(!maptab_PowerupRuleData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_PowerupRule.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *Levelx = node->first_node("Level");
        xml_node<> *Coinsx = node->first_node("Coins");
        xml_node<> *CoinLowBoundx = node->first_node("CoinLowBound");
        xml_node<> *CoinUpperBoundx = node->first_node("CoinUpperBound");
        xml_node<> *LifePointsx = node->first_node("LifePoints");
        xml_node<> *LifeLowBoundx = node->first_node("LifeLowBound");
        xml_node<> *LifeUpperBoundx = node->first_node("LifeUpperBound");
        xml_node<> *Bombx = node->first_node("Bomb");
        xml_node<> *Shieldx = node->first_node("Shield");
        xml_node<> *Lifex = node->first_node("Life");
        Configtab_PowerupRuleDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.Level = atoi(Levelx->value());
        st.Coins = atoi(Coinsx->value());
        st.CoinLowBound = atoi(CoinLowBoundx->value());
        st.CoinUpperBound = atoi(CoinUpperBoundx->value());
        st.LifePoints = atoi(LifePointsx->value());
        st.LifeLowBound = atoi(LifeLowBoundx->value());
        st.LifeUpperBound = atoi(LifeUpperBoundx->value());
        st.Bomb = atoi(Bombx->value());
        st.Shield = atoi(Shieldx->value());
        st.Life = atoi(Lifex->value());

        maptab_PowerupRuleData[st.ID] = st;
    }
}
Configtab_PowerupRuleDataST LocalDataManger::getConfigtab_PowerupRuleDataST(int ID)
{
    return maptab_PowerupRuleData[ID];
}

//tab_ScoreRule
void LocalDataManger::readConfigtab_ScoreRuleData()
{
    if(!maptab_ScoreRuleData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_ScoreRule.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *ScoreAddPerPointx = node->first_node("ScoreAddPerPoint");
        xml_node<> *ScoreAddWinx = node->first_node("ScoreAddWin");
        xml_node<> *CoinsAddWinx = node->first_node("CoinsAddWin");
        xml_node<> *ScoreSubPerPointx = node->first_node("ScoreSubPerPoint");
        xml_node<> *ScoreSubLosex = node->first_node("ScoreSubLose");
        xml_node<> *CoinsSubLosex = node->first_node("CoinsSubLose");
        Configtab_ScoreRuleDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.ScoreAddPerPoint = atoi(ScoreAddPerPointx->value());
        st.ScoreAddWin = atoi(ScoreAddWinx->value());
        st.CoinsAddWin = atoi(CoinsAddWinx->value());
        st.ScoreSubPerPoint = atoi(ScoreSubPerPointx->value());
        st.ScoreSubLose = atoi(ScoreSubLosex->value());
        st.CoinsSubLose = atoi(CoinsSubLosex->value());

        maptab_ScoreRuleData[st.ID] = st;
    }
}
Configtab_ScoreRuleDataST LocalDataManger::getConfigtab_ScoreRuleDataST(int ID)
{
    return maptab_ScoreRuleData[ID];
}

//tab_SetmapUnitLimit
void LocalDataManger::readConfigtab_SetmapUnitLimitData()
{
    if(!maptab_SetmapUnitLimitData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_SetmapUnitLimit.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *Levelx = node->first_node("Level");
        xml_node<> *InGameNamex = node->first_node("InGameName");
        xml_node<> *UnitLimitsx = node->first_node("UnitLimits");
        Configtab_SetmapUnitLimitDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.Level = atoi(Levelx->value());
        st.InGameName = atoi(InGameNamex->value());
        st.UnitLimits = atoi(UnitLimitsx->value());

        maptab_SetmapUnitLimitData[st.ID] = st;
    }
}
Configtab_SetmapUnitLimitDataST LocalDataManger::getConfigtab_SetmapUnitLimitDataST(int ID)
{
    return maptab_SetmapUnitLimitData[ID];
}

//tab_ShieldSkill
void LocalDataManger::readConfigtab_ShieldSkillData()
{
    if(!maptab_ShieldSkillData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_ShieldSkill.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *Levelx = node->first_node("Level");
        xml_node<> *InGameNamex = node->first_node("InGameName");
        xml_node<> *TrainCostx = node->first_node("TrainCost");
        xml_node<> *UpgradeCostx = node->first_node("UpgradeCost");
        xml_node<> *UpgradeTimex = node->first_node("UpgradeTime");
        xml_node<> *UpdateDiamondx = node->first_node("UpdateDiamond");
        xml_node<> *DefenseAddx = node->first_node("DefenseAdd");
        Configtab_ShieldSkillDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.Level = atoi(Levelx->value());
        st.InGameName = atoi(InGameNamex->value());
        st.TrainCost = atoi(TrainCostx->value());
        st.UpgradeCost = atoi(UpgradeCostx->value());
        st.UpgradeTime = atoi(UpgradeTimex->value());
        st.UpdateDiamond = atoi(UpdateDiamondx->value());
        st.DefenseAdd = atoi(DefenseAddx->value());

        maptab_ShieldSkillData[st.ID] = st;
    }
}
Configtab_ShieldSkillDataST LocalDataManger::getConfigtab_ShieldSkillDataST(int ID)
{
    return maptab_ShieldSkillData[ID];
}

//tab_ShieldTimeAttr
void LocalDataManger::readConfigtab_ShieldTimeAttrData()
{
    if(!maptab_ShieldTimeAttrData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_ShieldTimeAttr.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *InGameNamex = node->first_node("InGameName");
        xml_node<> *Costx = node->first_node("Cost");
        xml_node<> *CoinsMultix = node->first_node("CoinsMulti");
        Configtab_ShieldTimeAttrDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.InGameName = atoi(InGameNamex->value());
        st.Cost = atoi(Costx->value());
        st.CoinsMulti = atoi(CoinsMultix->value());

        maptab_ShieldTimeAttrData[st.ID] = st;
    }
}
Configtab_ShieldTimeAttrDataST LocalDataManger::getConfigtab_ShieldTimeAttrDataST(int ID)
{
    return maptab_ShieldTimeAttrData[ID];
}

//tab_SkillLastTime
void LocalDataManger::readConfigtab_SkillLastTimeData()
{
    if(!maptab_SkillLastTimeData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_SkillLastTime.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *LastTimex = node->first_node("LastTime");
        Configtab_SkillLastTimeDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.LastTime = atoi(LastTimex->value());

        maptab_SkillLastTimeData[st.ID] = st;
    }
}
Configtab_SkillLastTimeDataST LocalDataManger::getConfigtab_SkillLastTimeDataST(int ID)
{
    return maptab_SkillLastTimeData[ID];
}

//tab_UnitContainer
void LocalDataManger::readConfigtab_UnitContainerData()
{
    if(!maptab_UnitContainerData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_UnitContainer.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *Levelx = node->first_node("Level");
        xml_node<> *Typex = node->first_node("Type");
        xml_node<> *InGameNamex = node->first_node("InGameName");
        xml_node<> *TrainCostx = node->first_node("TrainCost");
        xml_node<> *UpgradeCostx = node->first_node("UpgradeCost");
        xml_node<> *UpgradeTimex = node->first_node("UpgradeTime");
        xml_node<> *UpdateDiamondx = node->first_node("UpdateDiamond");
        xml_node<> *UnitCountx = node->first_node("UnitCount");
        Configtab_UnitContainerDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.Level = atoi(Levelx->value());
        st.Type = atoi(Typex->value());
        st.InGameName = atoi(InGameNamex->value());
        st.TrainCost = atoi(TrainCostx->value());
        st.UpgradeCost = atoi(UpgradeCostx->value());
        st.UpgradeTime = atoi(UpgradeTimex->value());
        st.UpdateDiamond = atoi(UpdateDiamondx->value());
        st.UnitCount = atoi(UnitCountx->value());

        maptab_UnitContainerData[st.ID] = st;
    }
}
Configtab_UnitContainerDataST LocalDataManger::getConfigtab_UnitContainerDataST(int ID)
{
    return maptab_UnitContainerData[ID];
}

//tab_VoltageTowerLevelAttr
void LocalDataManger::readConfigtab_VoltageTowerLevelAttrData()
{
    if(!maptab_VoltageTowerLevelAttrData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_VoltageTowerLevelAttr.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *Levelx = node->first_node("Level");
        xml_node<> *ShootDistx = node->first_node("ShootDist");
        Configtab_VoltageTowerLevelAttrDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.Level = atoi(Levelx->value());
        st.ShootDist = atoi(ShootDistx->value());

        maptab_VoltageTowerLevelAttrData[st.ID] = st;
    }
}
Configtab_VoltageTowerLevelAttrDataST LocalDataManger::getConfigtab_VoltageTowerLevelAttrDataST(int ID)
{
    return maptab_VoltageTowerLevelAttrData[ID];
}

//tab_WindMillLevelAttr
void LocalDataManger::readConfigtab_WindMillLevelAttrData()
{
    if(!maptab_WindMillLevelAttrData.empty()) {
        return;
    }
    //rapidxml
    string xmlfile = getXmlFile("xml/tab_WindMillLevelAttr.xml");
    log("%s",xmlfile.c_str());
    char* text = const_cast<char*>(xmlfile.c_str());
    xml_document<>  doc;
    doc.parse<0>(text);
    
    xml_node<>* root = doc.first_node();
    for (xml_node<> *node = root->first_node("id"); node != NULL; node = node->next_sibling())
    {
        xml_node<> *idx = node->first_node("id");
        xml_node<> *Commentx = node->first_node("Comment");
        xml_node<> *Levelx = node->first_node("Level");
        xml_node<> *LetPlaneMovesx = node->first_node("LetPlaneMoves");
        Configtab_WindMillLevelAttrDataST st;

        st.ID = atoi(idx->value());
        st.Comment = Commentx->value();
        st.Level = atoi(Levelx->value());
        st.LetPlaneMoves = atoi(LetPlaneMovesx->value());

        maptab_WindMillLevelAttrData[st.ID] = st;
    }
}
Configtab_WindMillLevelAttrDataST LocalDataManger::getConfigtab_WindMillLevelAttrDataST(int ID)
{
    return maptab_WindMillLevelAttrData[ID];
}
string LocalDataManger::getXmlFile(string path)
{
    string file = FileUtils::getInstance()->getStringFromFile(path);
    log("file size is %d",(int)file.size());
    return file;
}