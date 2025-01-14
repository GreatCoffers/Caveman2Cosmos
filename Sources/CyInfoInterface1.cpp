#include "CvGameCoreDLL.h"

//
// Python interface for info classes (formerly structs)
// These are simple enough to be exposed directly - no wrappers
//

void CyInfoPythonInterface1()
{
	OutputDebugString("Python Extension Module - CyInfoPythonInterface1\n");

	python::class_<CvInfoBase>("CvInfoBase")

		.def("isGraphicalOnly", &CvInfoBase::isGraphicalOnly, "bool ()")

		.def("getType", &CvInfoBase::getType, "string ()")
		.def("getButton", &CvInfoBase::getButton, "string ()")

		.def("getTextKey", &CvInfoBase::pyGetTextKey, "wstring ()")
		.def("getText", &CvInfoBase::pyGetText, "wstring ()")
		.def("getDescription", &CvInfoBase::pyGetDescription, "wstring ()")
		.def("getDescriptionForm", &CvInfoBase::pyGetDescriptionForm, "wstring ()")
		.def("getCivilopedia", &CvInfoBase::pyGetCivilopedia, "wstring ()")
		.def("getStrategy", &CvInfoBase::pyGetStrategy, "wstring ()")
		.def("getHelp", &CvInfoBase::pyGetHelp, "wstring ()")
		.def("isMatchForLink", &CvInfoBase::isMatchForLink, "bool (string)")
		//.def("getGenericCategory", &CvInfoBase::pyGetGenericCategory, "wstring ()")
		;

	python::class_<CvScalableInfo>("CvScalableInfo")
		.def("setScale", &CvScalableInfo::setScale, "void (float fScale)")
		.def("getScale", &CvScalableInfo::getScale, "float  ()")
		;

	python::class_<CvSpecialistInfo, python::bases<CvInfoBase> >("CvSpecialistInfo")
		.def("getGreatPeopleUnitClass", &CvSpecialistInfo::getGreatPeopleUnitClass, "int ()")
		.def("getGreatPeopleRateChange", &CvSpecialistInfo::getGreatPeopleRateChange, "int ()")
		.def("getMissionType", &CvSpecialistInfo::getMissionType, "int ()")

		.def("isVisible", &CvSpecialistInfo::isVisible, "bool ()")
		
		.def("getYieldChange", &CvSpecialistInfo::getYieldChange, "int (int i)")
		.def("getCommerceChange", &CvSpecialistInfo::getCommerceChange, "int (int i)")
		.def("getExperience", &CvSpecialistInfo::getExperience, "int ()")
		.def("getFlavorValue", &CvSpecialistInfo::getFlavorValue, "int (int i)")

		.def("getTexture", &CvSpecialistInfo::getTexture, "string ()")
/************************************************************************************************/
/* Afforess	                  Start		 03/26/10                                               */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
		.def("isSlave", &CvSpecialistInfo::isSlave, "string ()")
/************************************************************************************************/
/* Afforess	                     END                                                            */
/************************************************************************************************/
		;

	python::class_<CvTechInfo, python::bases<CvInfoBase> >("CvTechInfo")
		.def("getAdvisorType", &CvTechInfo::getAdvisorType, "int ()")
		.def("getAIWeight", &CvTechInfo::getAIWeight, "int ()")
		.def("getAITradeModifier", &CvTechInfo::getAITradeModifier, "int ()")
		.def("getResearchCost", &CvTechInfo::getResearchCost, "int ()")
		.def("getEra", &CvTechInfo::getEra, "int ()")
		.def("getTradeRoutes", &CvTechInfo::getTradeRoutes, "int ()")
		.def("getFeatureProductionModifier", &CvTechInfo::getFeatureProductionModifier, "int ()")
		.def("getWorkerSpeedModifier", &CvTechInfo::getWorkerSpeedModifier, "int ()")
		.def("getFirstFreeUnitClass", &CvTechInfo::getFirstFreeUnitClass, "int ()")
		.def("getHealth", &CvTechInfo::getHealth, "int ()")
		.def("getHappiness", &CvTechInfo::getHappiness, "int ()")
		.def("getFirstFreeTechs", &CvTechInfo::getFirstFreeTechs, "int ()")
		.def("getAssetValue", &CvTechInfo::getAssetValue, "int ()")
		.def("getPowerValue", &CvTechInfo::getPowerValue, "int ()")

		.def("getGridX", &CvTechInfo::getGridX, "int ()")
		.def("getGridY", &CvTechInfo::getGridY, "int ()")

		.def("isRepeat", &CvTechInfo::isRepeat, "bool ()")
		.def("isTrade", &CvTechInfo::isTrade, "bool ()")
		.def("isDisable", &CvTechInfo::isDisable, "bool ()")
		.def("isGoodyTech", &CvTechInfo::isGoodyTech, "bool ()")
		.def("isExtraWaterSeeFrom", &CvTechInfo::isExtraWaterSeeFrom, "bool ()")
		.def("isMapCentering", &CvTechInfo::isMapCentering, "bool ()")
		.def("isMapVisible", &CvTechInfo::isMapVisible, "bool ()")
		.def("isMapTrading", &CvTechInfo::isMapTrading, "bool ()")
		.def("isTechTrading", &CvTechInfo::isTechTrading, "bool ()")
		.def("isGoldTrading", &CvTechInfo::isGoldTrading, "bool ()")
		.def("isOpenBordersTrading", &CvTechInfo::isOpenBordersTrading, "bool ()")
		.def("isDefensivePactTrading", &CvTechInfo::isDefensivePactTrading, "bool ()")
		.def("isPermanentAllianceTrading", &CvTechInfo::isPermanentAllianceTrading, "bool ()")
		.def("isVassalStateTrading", &CvTechInfo::isVassalStateTrading, "bool ()")
		.def("isBridgeBuilding", &CvTechInfo::isBridgeBuilding, "bool ()")
		.def("isIrrigation", &CvTechInfo::isIrrigation, "bool ()")
		.def("isIgnoreIrrigation", &CvTechInfo::isIgnoreIrrigation, "bool ()")
		.def("isWaterWork", &CvTechInfo::isWaterWork, "bool ()")
		.def("isRiverTrade", &CvTechInfo::isRiverTrade, "bool ()")

		.def("getQuote", &CvTechInfo::getQuote, "wstring ()")
		.def("getSound", &CvTechInfo::getSound, "string ()")
		.def("getSoundMP", &CvTechInfo::getSoundMP, "string ()")

		.def("getDomainExtraMoves", &CvTechInfo::getDomainExtraMoves, "int (int i)")
		.def("getFlavorValue", &CvTechInfo::getFlavorValue, "int (int i)")
		.def("getPrereqOrTechs", &CvTechInfo::getPrereqOrTechs, "int (int i)")
		.def("getPrereqAndTechs", &CvTechInfo::getPrereqAndTechs, "int (int i)")

		.def("isCommerceFlexible", &CvTechInfo::isCommerceFlexible, "bool (int i)")
		.def("isTerrainTrade", &CvTechInfo::isTerrainTrade, "bool (int i)")
/************************************************************************************************/
/* Afforess	                  Start		 03/30/10                                               */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
		.def("isEmbassyTrading", &CvTechInfo::isEmbassyTrading, "bool ()")
		.def("isCanPassPeaks", &CvTechInfo::isCanPassPeaks, "bool ()")
		.def("setPrereqOrTech", &CvTechInfo::setPrereqOrTech, "int (int i)")
		.def("setPrereqAndTech", &CvTechInfo::setPrereqAndTech, "int (int i)")
		.def("getUnitClassStrengthChange", &CvTechInfo::getUnitClassStrengthChange, "int (int i)")
/************************************************************************************************/
/* Afforess	                     END                                                            */
/************************************************************************************************/
		.def("getNumPrereqBuildingClasses", &CvTechInfo::getNumPrereqBuildingClasses, "int ()")
		.def("getPrereqBuildingClassType", &CvTechInfo::getPrereqBuildingClassType, "int (int i)")
		.def("getPrereqBuildingClassMinimumRequired", &CvTechInfo::getPrereqBuildingClassMinimumRequired, "int (int i)")
		.def("getNumPrereqOrBuildingClasses", &CvTechInfo::getNumPrereqOrBuildingClasses, "int ()")
		.def("getPrereqOrBuildingClassType", &CvTechInfo::getPrereqOrBuildingClassType, "int (int i)")
		.def("getPrereqOrBuildingClassMinimumRequired", &CvTechInfo::getPrereqOrBuildingClassMinimumRequired, "int (int i)")
		;

	python::class_<CvPromotionInfo, python::bases<CvInfoBase> >("CvPromotionInfo")

		.def("getPrereqPromotion", &CvPromotionInfo::getPrereqPromotion, "int ()")
		.def("getPrereqOrPromotion1", &CvPromotionInfo::getPrereqOrPromotion1, "int ()")
		.def("getPrereqOrPromotion2", &CvPromotionInfo::getPrereqOrPromotion2, "int ()")
		.def("getActionInfoIndex", &CvPromotionInfo::getActionInfoIndex, "int ()")

		.def("getTechPrereq", &CvPromotionInfo::getTechPrereq, "int ()")
		.def("getStateReligionPrereq", &CvPromotionInfo::getStateReligionPrereq, "int ()")
		.def("getVisibilityChange", &CvPromotionInfo::getVisibilityChange, "int ()")
		.def("getMovesChange", &CvPromotionInfo::getMovesChange, "int ()")
		.def("getMoveDiscountChange", &CvPromotionInfo::getMoveDiscountChange, "int ()")
		.def("getAirRangeChange", &CvPromotionInfo::getAirRangeChange, "int ()")
		.def("getInterceptChange", &CvPromotionInfo::getInterceptChange, "int ()")
		.def("getEvasionChange", &CvPromotionInfo::getEvasionChange, "int ()")
		.def("getWithdrawalChange", &CvPromotionInfo::getWithdrawalChange, "int ()")
		.def("getCargoChange", &CvPromotionInfo::getCargoChange, "int ()")
		.def("getCollateralDamageChange", &CvPromotionInfo::getCollateralDamageChange, "int ()")
		.def("getBombardRateChange", &CvPromotionInfo::getBombardRateChange, "int ()")
		.def("getFirstStrikesChange", &CvPromotionInfo::getFirstStrikesChange, "int ()")
		.def("getChanceFirstStrikesChange", &CvPromotionInfo::getChanceFirstStrikesChange, "int ()")
		.def("getEnemyHealChange", &CvPromotionInfo::getEnemyHealChange, "int ()")
		.def("getNeutralHealChange", &CvPromotionInfo::getNeutralHealChange, "int ()")
		.def("getFriendlyHealChange", &CvPromotionInfo::getFriendlyHealChange, "int ()")
		.def("getSameTileHealChange", &CvPromotionInfo::getSameTileHealChange, "int ()")
		.def("getAdjacentTileHealChange", &CvPromotionInfo::getAdjacentTileHealChange, "int ()")
		.def("getCombatPercent", &CvPromotionInfo::getCombatPercent, "int ()")
		.def("getCityAttackPercent", &CvPromotionInfo::getCityAttackPercent, "int ()")
		.def("getCityDefensePercent", &CvPromotionInfo::getCityDefensePercent, "int ()")
		.def("getHillsAttackPercent", &CvPromotionInfo::getHillsAttackPercent, "int ()")
		.def("getHillsDefensePercent", &CvPromotionInfo::getHillsDefensePercent, "int ()")
		.def("getCommandType", &CvPromotionInfo::getCommandType, "int ()")
		.def("getRevoltProtection", &CvPromotionInfo::getRevoltProtection, "int ()")
		.def("getCollateralDamageProtection", &CvPromotionInfo::getCollateralDamageProtection, "int ()")
		.def("getPillageChange", &CvPromotionInfo::getPillageChange, "int ()")
		.def("getUpgradeDiscount", &CvPromotionInfo::getUpgradeDiscount, "int ()")
		.def("getExperiencePercent", &CvPromotionInfo::getExperiencePercent, "int ()")
		.def("getKamikazePercent", &CvPromotionInfo::getKamikazePercent, "int ()")
/*****************************************************************************************************/
/**  Author: TheLadiesOgre                                                                          **/
/**  Date: 16.09.2009                                                                               **/
/**  ModComp: TLOTags                                                                               **/
/**  Reason Added: Expose New Promotions to Python                                                  **/
/**  Notes:                                                                                         **/
/*****************************************************************************************************/
		.def("getAirCombatLimitChange", &CvPromotionInfo::getAirCombatLimitChange, "int ()")
		.def("getCelebrityHappy", &CvPromotionInfo::getCelebrityHappy, "int ()")
		.def("getCollateralDamageLimitChange", &CvPromotionInfo::getCollateralDamageLimitChange, "int ()")
		.def("getCollateralDamageMaxUnitsChange", &CvPromotionInfo::getCollateralDamageMaxUnitsChange, "int ()")
		.def("getCombatLimitChange", &CvPromotionInfo::getCombatLimitChange, "int ()")
		.def("getExtraDropRange", &CvPromotionInfo::getExtraDropRange, "int ()")
		.def("getVictoryHeal", &CvPromotionInfo::getVictoryHeal, "int ()")
/*****************************************************************************************************/
/**  TheLadiesOgre; 16.09.2009; TLOTags                                                             **/
/*****************************************************************************************************/

		.def("isLeader", &CvPromotionInfo::isLeader, "bool ()")
		.def("isBlitz", &CvPromotionInfo::isBlitz, "bool ()")
		.def("isAmphib", &CvPromotionInfo::isAmphib, "bool ()")
		.def("isRiver", &CvPromotionInfo::isRiver, "bool ()")
		.def("isEnemyRoute", &CvPromotionInfo::isEnemyRoute, "bool ()")
		.def("isAlwaysHeal", &CvPromotionInfo::isAlwaysHeal, "bool ()")
		.def("isHillsDoubleMove", &CvPromotionInfo::isHillsDoubleMove, "bool ()")
		.def("isImmuneToFirstStrikes", &CvPromotionInfo::isImmuneToFirstStrikes, "bool ()")
/*****************************************************************************************************/
/**  Author: TheLadiesOgre                                                                          **/
/**  Date: 16.09.2009                                                                               **/
/**  ModComp: TLOTags                                                                               **/
/**  Reason Added: Expose New Promotions to Python                                                  **/
/**  Notes:                                                                                         **/
/*****************************************************************************************************/
		.def("isDefensiveVictoryMove", &CvPromotionInfo::isDefensiveVictoryMove, "bool ()")
		.def("isFreeDrop", &CvPromotionInfo::isFreeDrop, "bool ()")
		.def("isOffensiveVictoryMove", &CvPromotionInfo::isOffensiveVictoryMove, "bool ()")
		.def("isPillageCulture", &CvPromotionInfo::isPillageCulture, "bool ()")
		.def("isPillageEspionage", &CvPromotionInfo::isPillageEspionage, "bool ()")
		.def("isPillageMarauder", &CvPromotionInfo::isPillageMarauder, "bool ()")
		.def("isPillageOnMove", &CvPromotionInfo::isPillageOnMove, "bool ()")
		.def("isPillageOnVictory", &CvPromotionInfo::isPillageOnVictory, "bool ()")
		.def("isPillageResearch", &CvPromotionInfo::isPillageResearch, "bool ()")
/*****************************************************************************************************/
/**  TheLadiesOgre; 16.09.2009; TLOTags                                                             **/
/*****************************************************************************************************/
		
/************************************************************************************************/
/* Afforess Promotion Changes                             12/5/09                               */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
		.def("getNumPromotionOverwrites", &CvPromotionInfo::getNumPromotionOverwrites, "int ()")
		.def("getObsoleteTech", &CvPromotionInfo::getObsoleteTech, "int ()")
/************************************************************************************************/
/* Afforess	                         END                                                        */
/************************************************************************************************/			

		.def("getSound", &CvPromotionInfo::getSound, "string ()")

		// Arrays

		.def("getTerrainAttackPercent", &CvPromotionInfo::getTerrainAttackPercent, "int (int i)")
		.def("getTerrainDefensePercent", &CvPromotionInfo::getTerrainDefensePercent, "int (int i)")
		.def("getFeatureAttackPercent", &CvPromotionInfo::getFeatureAttackPercent, "int (int i)")
		.def("getFeatureDefensePercent", &CvPromotionInfo::getFeatureDefensePercent, "int (int i)")
		.def("getUnitCombatModifierPercent", &CvPromotionInfo::getUnitCombatModifierPercent, "int (int i)")
		.def("getDomainModifierPercent", &CvPromotionInfo::getDomainModifierPercent, "int (int i)")

		.def("getTerrainDoubleMove", &CvPromotionInfo::getTerrainDoubleMove, "bool (int i)")
		.def("getFeatureDoubleMove", &CvPromotionInfo::getFeatureDoubleMove, "bool (int i)")
		.def("getUnitCombat", &CvPromotionInfo::getUnitCombat, "bool (int i)")
		//TB Combat Mods Begin
		.def("getPromotionLine", &CvPromotionInfo::getPromotionLine, "int ()")
		//integers
		.def("getAttackCombatModifierChange", &CvPromotionInfo::getAttackCombatModifierChange, "int ()")
		.def("getDefenseCombatModifierChange", &CvPromotionInfo::getDefenseCombatModifierChange, "int ()")
		.def("getPursuitChange", &CvPromotionInfo::getPursuitChange, "int ()")
		.def("getEarlyWithdrawChange", &CvPromotionInfo::getEarlyWithdrawChange, "int ()")
		.def("getVSBarbsChange", &CvPromotionInfo::getVSBarbsChange, "int ()")
		.def("getArmorChange", &CvPromotionInfo::getArmorChange, "int ()")
		.def("getPunctureChange", &CvPromotionInfo::getPunctureChange, "int ()")
		.def("getOverrunChange", &CvPromotionInfo::getOverrunChange, "int ()")
		.def("getRepelChange", &CvPromotionInfo::getRepelChange, "int ()")
		.def("getFortRepelChange", &CvPromotionInfo::getFortRepelChange, "int ()")
		.def("getUnyieldingChange", &CvPromotionInfo::getUnyieldingChange, "int ()")
		.def("getKnockbackChange", &CvPromotionInfo::getKnockbackChange, "int ()")
		.def("getStrAdjperRndChange", &CvPromotionInfo::getStrAdjperRndChange, "int ()")
		.def("getStrAdjperAttChange", &CvPromotionInfo::getStrAdjperAttChange, "int ()")
		.def("getStrAdjperDefChange", &CvPromotionInfo::getStrAdjperDefChange, "int ()")
		.def("getWithdrawAdjperAttChange", &CvPromotionInfo::getWithdrawAdjperAttChange, "int ()")
		.def("getUnnerveChange", &CvPromotionInfo::getUnnerveChange, "int ()")
		.def("getEncloseChange", &CvPromotionInfo::getEncloseChange, "int ()")
		.def("getLungeChange", &CvPromotionInfo::getLungeChange, "int ()")
		.def("getDynamicDefenseChange", &CvPromotionInfo::getDynamicDefenseChange, "int ()")
		.def("getStrengthChange", &CvPromotionInfo::getStrengthChange, "int ()")
		.def("getLinePriority", &CvPromotionInfo::getLinePriority, "int ()")
		.def("getFortitudeChange", &CvPromotionInfo::getFortitudeChange, "int ()")
		.def("getDamageperTurn", &CvPromotionInfo::getDamageperTurn, "int ()")
		.def("getStrAdjperTurn", &CvPromotionInfo::getStrAdjperTurn, "int ()")
		.def("getWeakenperTurn", &CvPromotionInfo::getWeakenperTurn, "int ()")
		.def("getFrontSupportPercentChange", &CvPromotionInfo::getFrontSupportPercentChange, "int ()")
		.def("getShortRangeSupportPercentChange", &CvPromotionInfo::getShortRangeSupportPercentChange, "int ()")
		.def("getMediumRangeSupportPercentChange", &CvPromotionInfo::getMediumRangeSupportPercentChange, "int ()")
		.def("getLongRangeSupportPercentChange", &CvPromotionInfo::getLongRangeSupportPercentChange, "int ()")
		.def("getFlankSupportPercentChange", &CvPromotionInfo::getFlankSupportPercentChange, "int ()")
		//booleans
		.def("isStampedeChange", &CvPromotionInfo::isStampedeChange, "bool ()")
		.def("isRemoveStampede", &CvPromotionInfo::isRemoveStampede, "bool ()")
		.def("getAnimalIgnoresBordersChange", &CvPromotionInfo::getAnimalIgnoresBordersChange, "int ()")
		.def("isOnslaughtChange", &CvPromotionInfo::isOnslaughtChange, "bool ()")
		.def("isEquipment", &CvPromotionInfo::isEquipment, "bool ()")
		.def("isAffliction", &CvPromotionInfo::isAffliction, "bool ()")
		.def("isParalyze", &CvPromotionInfo::isParalyze, "bool ()")
		//boolean vectors
		.def("getSubCombatChangeType", &CvPromotionInfo::getSubCombatChangeType, "int (int i)")
		.def("getCureAfflictionChangeType", &CvPromotionInfo::getCureAfflictionChangeType, "int (int i)")
		.def("getPrereqBonusType", &CvPromotionInfo::getPrereqBonusType, "int (int i)")
		// int vector utilizing pairing without delayed resolution
		// int vector utilizing struct with delayed resolution
		//.def("getAfflictionFortitudeModifier", &CvPromotionInfo::getAfflictionFortitudeModifier, "int (int iAffliction)")
		//TB Combat Mods End
		//PediaHelp
		.def("getQualifiedUnitCombatType", &CvPromotionInfo::getQualifiedUnitCombatType, "int (int i)")
		.def("getNumQualifiedUnitCombatTypes", &CvPromotionInfo::getNumQualifiedUnitCombatTypes, "int ()")
		.def("isQualifiedUnitCombatType", &CvPromotionInfo::isQualifiedUnitCombatType, "bool (int i)")
		.def("isStatus", &CvPromotionInfo::isStatus, "bool ()")
		;

	python::class_<CvMissionInfo, python::bases<CvInfoBase> >("CvMissionInfo")
		.def("getTime", &CvMissionInfo::getTime, "int ()")

		.def("isSound", &CvMissionInfo::isSound, "bool ()")
		.def("isTarget", &CvMissionInfo::isTarget, "bool ()")
		.def("isBuild", &CvMissionInfo::isBuild, "bool ()")
		.def("getVisible", &CvMissionInfo::getVisible, "bool ()")

		.def("getWaypoint", &CvMissionInfo::getWaypoint, "string ()")
		;

	python::class_<CvActionInfo>("CvActionInfo")
		.def("getMissionData", &CvActionInfo::getMissionData, "int ()")
		.def("getCommandData", &CvActionInfo::getCommandData, "int ()")
		.def("getAutomateType", &CvActionInfo::getAutomateType, "int ()")

		.def("getInterfaceModeType", &CvActionInfo::getInterfaceModeType, "int ()")
		.def("getMissionType", &CvActionInfo::getMissionType, "int ()")
		.def("getCommandType", &CvActionInfo::getCommandType, "int ()")
		.def("getControlType", &CvActionInfo::getControlType, "int ()")

		.def("isConfirmCommand", &CvActionInfo::isConfirmCommand, "bool ()")
		.def("isVisible", &CvActionInfo::isVisible, "bool ()")

		.def("getHotKey", &CvActionInfo::getHotKey, "string ()")
		.def("getButton", &CvActionInfo::getButton, "string ()")
		;

	python::class_<CvUnitInfo, python::bases<CvInfoBase, CvScalableInfo> >("CvUnitInfo")

		.def("getAIWeight", &CvUnitInfo::getAIWeight, "int ()")
		.def("getProductionCost", &CvUnitInfo::getProductionCost, "int ()")
		.def("getHurryCostModifier", &CvUnitInfo::getHurryCostModifier, "int ()")
		.def("getMinAreaSize", &CvUnitInfo::getMinAreaSize, "int ()")
		.def("getMoves", &CvUnitInfo::getMoves, "int ()")
		.def("getAirRange", &CvUnitInfo::getAirRange, "int ()")
		.def("getAirUnitCap", &CvUnitInfo::getAirUnitCap, "int ()")
		.def("getDropRange", &CvUnitInfo::getDropRange, "int ()")
		.def("getNukeRange", &CvUnitInfo::getNukeRange, "int ()")
		.def("getWorkRate", &CvUnitInfo::getWorkRate, "int ()")
		.def("getBaseDiscover", &CvUnitInfo::getBaseDiscover, "int ()")
		.def("getDiscoverMultiplier", &CvUnitInfo::getDiscoverMultiplier, "int ()")
		.def("getBaseHurry", &CvUnitInfo::getBaseHurry, "int ()")
		.def("getHurryMultiplier", &CvUnitInfo::getHurryMultiplier, "int ()")
		.def("getBaseTrade", &CvUnitInfo::getBaseTrade, "int ()")
		.def("getTradeMultiplier", &CvUnitInfo::getTradeMultiplier, "int ()")
		.def("getGreatWorkCulture", &CvUnitInfo::getGreatWorkCulture, "int ()")
		.def("getEspionagePoints", &CvUnitInfo::getEspionagePoints, "int ()")
		.def("getCombat", &CvUnitInfo::getCombat, "int ()")
		.def("setCombat", &CvUnitInfo::setCombat, "void (int)")
		.def("getCombatLimit", &CvUnitInfo::getCombatLimit, "int ()")
		.def("getAirCombat", &CvUnitInfo::getAirCombat, "int ()")
		.def("getAirCombatLimit", &CvUnitInfo::getAirCombatLimit, "int ()")
		.def("getXPValueAttack", &CvUnitInfo::getXPValueAttack, "int ()")
		.def("getXPValueDefense", &CvUnitInfo::getXPValueDefense, "int ()")
		.def("getFirstStrikes", &CvUnitInfo::getFirstStrikes, "int ()")
		.def("getChanceFirstStrikes", &CvUnitInfo::getChanceFirstStrikes, "int ()")
		.def("getInterceptionProbability", &CvUnitInfo::getInterceptionProbability, "int ()")
		.def("getEvasionProbability", &CvUnitInfo::getEvasionProbability, "int ()")
		.def("getWithdrawalProbability", &CvUnitInfo::getWithdrawalProbability, "int ()")
		.def("getCollateralDamage", &CvUnitInfo::getCollateralDamage, "int ()")
		.def("getCollateralDamageLimit", &CvUnitInfo::getCollateralDamageLimit, "int ()")
		.def("getCollateralDamageMaxUnits", &CvUnitInfo::getCollateralDamageMaxUnits, "int ()")
		.def("getCityAttackModifier", &CvUnitInfo::getCityAttackModifier, "int ()")
		.def("getCityDefenseModifier", &CvUnitInfo::getCityDefenseModifier, "int ()")
		.def("getAnimalCombatModifier", &CvUnitInfo::getAnimalCombatModifier, "int ()")
		.def("getHillsAttackModifier", &CvUnitInfo::getHillsAttackModifier, "int ()")
		.def("getHillsDefenseModifier", &CvUnitInfo::getHillsDefenseModifier, "int ()")
		.def("getBombRate", &CvUnitInfo::getBombRate, "int ()")
		.def("getBombardRate", &CvUnitInfo::getBombardRate, "int ()")
		.def("getSpecialCargo", &CvUnitInfo::getSpecialCargo, "int ()")
		.def("getDomainCargo", &CvUnitInfo::getDomainCargo, "int ()")

		.def("getCargoSpace", &CvUnitInfo::getCargoSpace, "int ()")
		.def("getConscriptionValue", &CvUnitInfo::getConscriptionValue, "int ()")
		.def("getCultureGarrisonValue", &CvUnitInfo::getCultureGarrisonValue, "int ()")
		.def("getExtraCost", &CvUnitInfo::getExtraCost, "int ()")
		.def("getAssetValue", &CvUnitInfo::getAssetValue, "int ()")
		.def("getPowerValue", &CvUnitInfo::getPowerValue, "int ()")
		.def("getUnitClassType", &CvUnitInfo::getUnitClassType, "int ()")
		.def("getSpecialUnitType", &CvUnitInfo::getSpecialUnitType, "int ()")
		.def("getUnitCaptureClassType", &CvUnitInfo::getUnitCaptureClassType, "int ()")
		.def("getUnitCombatType", &CvUnitInfo::getUnitCombatType, "int ()")
		.def("getDomainType", &CvUnitInfo::getDomainType, "int ()")
		.def("getDefaultUnitAIType", &CvUnitInfo::getDefaultUnitAIType, "int ()")
		.def("getInvisibleType", &CvUnitInfo::getInvisibleType, "int ()")
		.def("getNumSeeInvisibleTypes", &CvUnitInfo::getNumSeeInvisibleTypes, "int ()")
		.def("getSeeInvisibleType", &CvUnitInfo::getSeeInvisibleType, "int (int)")
		.def("getAdvisorType", &CvUnitInfo::getAdvisorType, "int ()")
/************************************************************************************************/
/* REVDCM                                 02/16/10                                phungus420    */
/*                                                                                              */
/* CanTrain                                                                                     */
/************************************************************************************************/
		.def("getMaxStartEra", &CvUnitInfo::getMaxStartEra, "int ()")
		.def("getForceObsoleteTech", &CvUnitInfo::getForceObsoleteTech, "int ()")
		.def("isStateReligion", &CvUnitInfo::isStateReligion, "bool ()")
		.def("getPrereqGameOption", &CvUnitInfo::getPrereqGameOption, "int ()")
		.def("getNotGameOption", &CvUnitInfo::getNotGameOption, "int ()")
/************************************************************************************************/
/* REVDCM                                  END                                                  */
/************************************************************************************************/
		.def("getHolyCity", &CvUnitInfo::getHolyCity, "int ()")
		.def("getReligionType", &CvUnitInfo::getReligionType, "int ()")
		.def("getStateReligion", &CvUnitInfo::getStateReligion, "int ()")
		.def("getPrereqReligion", &CvUnitInfo::getPrereqReligion, "int ()")
		.def("getPrereqCorporation", &CvUnitInfo::getPrereqCorporation, "int ()")
		.def("getPrereqBuilding", &CvUnitInfo::getPrereqBuilding, "int ()")
		.def("getPrereqOrBuildingsNum", &CvUnitInfo::getPrereqOrBuildingsNum, "int ()")
		.def("getPrereqOrBuilding", &CvUnitInfo::getPrereqOrBuilding, "int (int)")
		.def("getPrereqAndTech", &CvUnitInfo::getPrereqAndTech, "int ()")
		.def("getPrereqAndBonus", &CvUnitInfo::getPrereqAndBonus, "int ()")
		.def("getGroupSize", &CvUnitInfo::getGroupSize, "int ()")
		.def("getGroupDefinitions", &CvUnitInfo::getGroupDefinitions, "int ()")
		.def("getMeleeWaveSize", &CvUnitInfo::getMeleeWaveSize, "int ()")
		.def("getRangedWaveSize", &CvUnitInfo::getRangedWaveSize, "int ()")
		.def("getNumUnitNames", &CvUnitInfo::getNumUnitNames, "int ()")
		.def("getCommandType", &CvUnitInfo::getCommandType, "int ()")

		.def("isFoodProduction", &CvUnitInfo::isFoodProduction, "bool ()")
		.def("isNoBadGoodies", &CvUnitInfo::isNoBadGoodies, "bool ()")
/************************************************************************************************/
/* UNOFFICIAL_PATCH                       03/20/10                       Afforess & jdog5000    */
/*                                                                                              */
/* Bugfix                                                                                       */
/************************************************************************************************/
		.def("isOnlyDefensive", &CvUnitInfo::isOnlyDefensive, "bool ()")
/************************************************************************************************/
/* UNOFFICIAL_PATCH                        END                                                  */
/************************************************************************************************/
		.def("isNoCapture", &CvUnitInfo::isNoCapture, "bool ()")
		.def("isRivalTerritory", &CvUnitInfo::isRivalTerritory, "bool ()")
		.def("isMilitaryHappiness", &CvUnitInfo::isMilitaryHappiness, "bool ()")
		.def("isMilitarySupport", &CvUnitInfo::isMilitarySupport, "bool ()")
		.def("isMilitaryProduction", &CvUnitInfo::isMilitaryProduction, "bool ()")
		.def("isPillage", &CvUnitInfo::isPillage, "bool ()")
		.def("isSpy", &CvUnitInfo::isSpy, "bool ()")
		.def("isSabotage", &CvUnitInfo::isSabotage, "bool ()")
		.def("isDestroy", &CvUnitInfo::isDestroy, "bool ()")
		.def("isStealPlans", &CvUnitInfo::isStealPlans, "bool ()")
		.def("isInvestigate", &CvUnitInfo::isInvestigate, "bool ()")
		.def("isCounterSpy", &CvUnitInfo::isCounterSpy, "bool ()")
		.def("isFound", &CvUnitInfo::isFound, "bool ()")
		.def("isGoldenAge", &CvUnitInfo::isGoldenAge, "bool ()")
		.def("isInvisible", &CvUnitInfo::isInvisible, "bool ()")
		.def("setInvisible", &CvUnitInfo::setInvisible, "void (bool bEnable)")
		.def("isFirstStrikeImmune", &CvUnitInfo::isFirstStrikeImmune, "bool ()")
		.def("isNoDefensiveBonus", &CvUnitInfo::isNoDefensiveBonus, "bool ()")
		.def("isIgnoreBuildingDefense", &CvUnitInfo::isIgnoreBuildingDefense, "bool ()")
		.def("isCanMoveImpassable", &CvUnitInfo::isCanMoveImpassable, "bool ()")
		.def("isCanMoveAllTerrain", &CvUnitInfo::isCanMoveAllTerrain, "bool ()")
		.def("isFlatMovementCost", &CvUnitInfo::isFlatMovementCost, "bool ()")
		.def("isIgnoreTerrainCost", &CvUnitInfo::isIgnoreTerrainCost, "bool ()")
		.def("isNukeImmune", &CvUnitInfo::isNukeImmune, "bool ()")
/************************************************************************************************/
/* REVDCM_OC                              02/16/10                                phungus420    */
/*                                                                                              */
/* Inquisitions                                                                                 */
/************************************************************************************************/
		.def("isInquisitor", &CvUnitInfo::isInquisitor, "bool ()")
/************************************************************************************************/
/* REVDCM_OC                               END                                                  */
/************************************************************************************************/
		.def("isPrereqBonuses", &CvUnitInfo::isPrereqBonuses, "bool ()")
		.def("isPrereqReligion", &CvUnitInfo::isPrereqReligion, "bool ()")
		.def("isMechUnit", &CvUnitInfo::isMechUnit, "bool ()")
		.def("isRenderBelowWater", &CvUnitInfo::isRenderBelowWater, "bool ()")
		.def("isSuicide", &CvUnitInfo::isSuicide, "bool ()")
		.def("isLineOfSight", &CvUnitInfo::isLineOfSight, "bool ()")
		.def("isHiddenNationality", &CvUnitInfo::isHiddenNationality, "bool ()")
		.def("isAlwaysHostile", &CvUnitInfo::isAlwaysHostile, "bool ()")
/*****************************************************************************************************/
/**  Author: TheLadiesOgre                                                                          **/
/**  Date: 21.09.2009                                                                               **/
/**  ModComp: TLOTags                                                                               **/
/**  Reason Added: New Tag Definition                                                               **/
/**  Notes:                                                                                         **/
/*****************************************************************************************************/
		.def("isFreeDrop", &CvUnitInfo::isFreeDrop, "bool ()")
/*****************************************************************************************************/
/**  TheLadiesOgre; 21.09.2009; TLOTags                                                             **/
/*****************************************************************************************************/

/************************************************************************************************/
/* REVOLUTION_MOD                         01/01/08                                jdog5000      */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
		.def("isCanBeRebel", &CvUnitInfo::isCanBeRebel, "bool ()")
		.def("isCanRebelCapture", &CvUnitInfo::isCanRebelCapture, "bool ()")
		.def("isCannotDeffect", &CvUnitInfo::isCannotDefect, "bool ()")
		.def("isCanQuellRebellion", &CvUnitInfo::isCanQuellRebellion, "bool ()")
/************************************************************************************************/
/* REVOLUTION_MOD                          END                                                  */
/************************************************************************************************/

		.def("getUnitMaxSpeed", &CvUnitInfo::getUnitMaxSpeed, "float ()")
		.def("getUnitPadTime", &CvUnitInfo::getUnitPadTime, "float ()")
		
// BUG - Unit Experience - start
		.def("canAcquireExperience", &CvUnitInfo::canAcquireExperience, "int ()")
// BUG - Unit Experience - end

		// Arrays

		.def("getPrereqAndTechs", &CvUnitInfo::getPrereqAndTechs, "int (int i)")
		.def("getPrereqOrBonuses", &CvUnitInfo::getPrereqOrBonuses, "int (int i)")
		//.def("getProductionTraits", &CvUnitInfo::getProductionTraits, "int (int i)")
		.def("getFlavorValue", &CvUnitInfo::getFlavorValue, "int (int i)")
		.def("getTerrainAttackModifier", &CvUnitInfo::getTerrainAttackModifier, "int (int i)")
		.def("getTerrainDefenseModifier", &CvUnitInfo::getTerrainDefenseModifier, "int (int i)")
		.def("getFeatureAttackModifier", &CvUnitInfo::getFeatureAttackModifier, "int (int i)")
		.def("getFeatureDefenseModifier", &CvUnitInfo::getFeatureDefenseModifier, "int (int i)")
		.def("getUnitClassAttackModifier", &CvUnitInfo::getUnitClassAttackModifier, "int (int i)")
		.def("getUnitClassDefenseModifier", &CvUnitInfo::getUnitClassDefenseModifier, "int (int i)")
		.def("getUnitCombatModifier", &CvUnitInfo::getUnitCombatModifier, "int (int i)")
		.def("getDomainModifier", &CvUnitInfo::getDomainModifier, "int (int i)")
		.def("getBonusProductionModifier", &CvUnitInfo::getBonusProductionModifier, "int (int i)")
		.def("getUnitGroupRequired", &CvUnitInfo::getUnitGroupRequired, "int (int i)")
/************************************************************************************************/
/* REVDCM                                 02/16/10                                phungus420    */
/*                                                                                              */
/* CanTrain                                                                                     */
/************************************************************************************************/
		.def("isPrereqOrCivics", &CvUnitInfo::isPrereqOrCivics, "bool (int i)")
		.def("isPrereqBuildingClass", &CvUnitInfo::isPrereqBuildingClass, "bool (int i)")
		.def("getPrereqBuildingClassOverrideTech", &CvUnitInfo::getPrereqBuildingClassOverrideTech, "int (int i)")
		.def("getPrereqBuildingClassOverrideEra", &CvUnitInfo::getPrereqBuildingClassOverrideEra, "int (int i)")
		.def("getForceObsoleteUnitClass", &CvUnitInfo::getForceObsoleteUnitClass, "bool (int i)")
/************************************************************************************************/
/* REVDCM                                  END                                                  */
/************************************************************************************************/
		.def("getUpgradeUnitClass", &CvUnitInfo::getUpgradeUnitClass, "bool (int i)")
		.def("getTargetUnitClass", &CvUnitInfo::getTargetUnitClass, "bool (int i)")
		.def("getTargetUnitCombat", &CvUnitInfo::getTargetUnitCombat, "bool (int i)")
		.def("getDefenderUnitClass", &CvUnitInfo::getDefenderUnitClass, "bool (int i)")
		.def("getDefenderUnitCombat", &CvUnitInfo::getDefenderUnitCombat, "bool (int i)")
		.def("getUnitAIType", &CvUnitInfo::getUnitAIType, "bool (int i)")
		.def("getNotUnitAIType", &CvUnitInfo::getNotUnitAIType, "bool (int i)")
		.def("getBuilds", &CvUnitInfo::getBuilds, "bool (int i)")
		.def("getReligionSpreads", &CvUnitInfo::getReligionSpreads, "int (int i)")
		.def("getCorporationSpreads", &CvUnitInfo::getCorporationSpreads, "int (int i)")
		.def("getTerrainPassableTech", &CvUnitInfo::getTerrainPassableTech, "int (int i)")
		.def("getFeaturePassableTech", &CvUnitInfo::getFeaturePassableTech, "int (int i)")
		.def("getFlankingStrikeUnitClass", &CvUnitInfo::getFlankingStrikeUnitClass, "int (int i)")
		.def("getGreatPeoples", &CvUnitInfo::getGreatPeoples, "bool (int i)")
		.def("getBuildings", &CvUnitInfo::getBuildings, "int (int i)")
		.def("getHasBuilding", &CvUnitInfo::getHasBuilding, "bool (int i)")
		.def("getNumBuildings", &CvUnitInfo::getNumBuildings, "int ()")
		//.def("getTerrainImpassable", &CvUnitInfo::getTerrainImpassable, "bool (int i)")
		//.def("getFeatureImpassable", &CvUnitInfo::getFeatureImpassable, "bool (int i)")
		.def("getTerrainNative", &CvUnitInfo::getTerrainNative, "bool (int i)")
		.def("getFeatureNative", &CvUnitInfo::getFeatureNative, "bool (int i)")
		.def("getFreePromotions", &CvUnitInfo::getFreePromotions, "bool (int i)")
		.def("getLeaderPromotion", &CvUnitInfo::getLeaderPromotion, "int ()")
		.def("getLeaderExperience", &CvUnitInfo::getLeaderExperience, "int ()")
/************************************************************************************************/
/* Afforess	                  Start		 03/10/10                                               */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
		.def("getEarlyArtDefineTag", &CvUnitInfo::getEarlyArtDefineTag, "string (int i, UnitArtStyleTypes eStyle)")
		.def("getClassicalArtDefineTag", &CvUnitInfo::getClassicalArtDefineTag, "string (int i, UnitArtStyleTypes eStyle)")
		.def("getMiddleArtDefineTag", &CvUnitInfo::getMiddleArtDefineTag, "string (int i, UnitArtStyleTypes eStyle)")
		.def("getRennArtDefineTag", &CvUnitInfo::getRennArtDefineTag, "string (int i, UnitArtStyleTypes eStyle)")
		.def("getIndustrialArtDefineTag", &CvUnitInfo::getIndustrialArtDefineTag, "string (int i, UnitArtStyleTypes eStyle)")
		.def("getLateArtDefineTag", &CvUnitInfo::getLateArtDefineTag, "string (int i, UnitArtStyleTypes eStyle)")
		.def("getFutureArtDefineTag", &CvUnitInfo::getFutureArtDefineTag, "string (int i, UnitArtStyleTypes eStyle)")
/************************************************************************************************/
/* Afforess	                     END                                                            */
/************************************************************************************************/
		.def("getUnitNames", &CvUnitInfo::getUnitNames, "string (int i)")
		.def("getArtInfo", &CvUnitInfo::getArtInfo,  python::return_value_policy<python::reference_existing_object>(), "CvArtInfoUnit* (int i, bool bLate)")
		//TB SubCombat Mod begin  TB Combat Mods Begin
		//integers
		.def("getAttackCombatModifier", &CvUnitInfo::getAttackCombatModifier, "int ()")
		.def("getDefenseCombatModifier", &CvUnitInfo::getDefenseCombatModifier, "int ()")
		.def("getPursuit", &CvUnitInfo::getPursuit, "int ()")
		.def("getEarlyWithdraw", &CvUnitInfo::getEarlyWithdraw, "int ()")
		.def("getVSBarbs", &CvUnitInfo::getVSBarbs, "int ()")
		.def("getArmor", &CvUnitInfo::getArmor, "int ()")
		.def("getPuncture", &CvUnitInfo::getPuncture, "int ()")
		.def("getOverrun", &CvUnitInfo::getOverrun, "int ()")
		.def("getRepel", &CvUnitInfo::getRepel, "int ()")
		.def("getFortRepel", &CvUnitInfo::getFortRepel, "int ()")
		.def("getUnyielding", &CvUnitInfo::getUnyielding, "int ()")
		.def("getKnockback", &CvUnitInfo::getKnockback, "int ()")
		.def("getStrAdjperRnd", &CvUnitInfo::getStrAdjperRnd, "int ()")
		.def("getStrAdjperAtt", &CvUnitInfo::getStrAdjperAtt, "int ()")
		.def("getStrAdjperDef", &CvUnitInfo::getStrAdjperDef, "int ()")
		.def("getWithdrawAdjperAtt", &CvUnitInfo::getWithdrawAdjperAtt, "int ()")
		.def("getUnnerve", &CvUnitInfo::getUnnerve, "int ()")
		.def("getEnclose", &CvUnitInfo::getEnclose, "int ()")
		.def("getLunge", &CvUnitInfo::getLunge, "int ()")
		.def("getDynamicDefense", &CvUnitInfo::getDynamicDefense, "int ()")
		.def("getFortitude", &CvUnitInfo::getFortitude, "int ()")
		.def("getFrontSupportPercent", &CvUnitInfo::getFrontSupportPercent, "int ()")
		.def("getShortRangeSupportPercent", &CvUnitInfo::getShortRangeSupportPercent, "int ()")
		.def("getMediumRangeSupportPercent", &CvUnitInfo::getMediumRangeSupportPercent, "int ()")
		.def("getLongRangeSupportPercent", &CvUnitInfo::getLongRangeSupportPercent, "int ()")
		.def("getFlankSupportPercent", &CvUnitInfo::getFlankSupportPercent, "int ()")
		.def("getDamageModifier", &CvUnitInfo::getDamageModifier, "int ()")
		//booleans
		.def("isStampede", &CvUnitInfo::isStampede, "bool ()")
		.def("getAnimalIgnoresBorders", &CvUnitInfo::getAnimalIgnoresBorders, "int ()")
		.def("isOnslaught", &CvUnitInfo::isOnslaught, "bool ()")
		.def("isDealsColdDamage", &CvUnitInfo::isDealsColdDamage, "bool ()")
		.def("isColdImmune", &CvUnitInfo::isColdImmune, "bool ()")
		.def("isAttackOnlyCities", &CvUnitInfo::isAttackOnlyCities, "bool ()")
		.def("isIgnoreNoEntryLevel", &CvUnitInfo::isIgnoreNoEntryLevel, "bool ()")
		.def("isIgnoreZoneofControl", &CvUnitInfo::isIgnoreZoneofControl, "bool ()")
		//boolean vectors
		.def("getSubCombatType", &CvUnitInfo::getSubCombatType, "int (int i)")
		.def("getNumSubCombatTypes", &CvUnitInfo::getNumSubCombatTypes, "int ()")
		.def("isSubCombatType", &CvUnitInfo::isSubCombatType, "int (int i)")
		.def("getCureAfflictionType", &CvUnitInfo::getCureAfflictionType, "int (int i)")
		.def("isQualifiedPromotionType", &CvUnitInfo::isQualifiedPromotionType, "bool (int i)")
		.def("hasUnitCombat", &CvUnitInfo::hasUnitCombat, "bool (UnitCombatTypes eUnitCombat)")
		//TB Combat Mods End  TB SubCombat Mod end
		;

	python::class_<CvSpecialUnitInfo, python::bases<CvInfoBase> >("CvSpecialUnitInfo")
		.def("isValid", &CvSpecialUnitInfo::isValid, "bool ()")
		.def("isCityLoad", &CvSpecialUnitInfo::isCityLoad, "bool ()")

		.def("isCarrierUnitAIType", &CvSpecialUnitInfo::isCarrierUnitAIType, "bool (int i)")
		//.def("getProductionTraits", &CvSpecialUnitInfo::getProductionTraits, "int (int i)")
		;

	python::class_<CvCivicOptionInfo, python::bases<CvInfoBase> >("CvCivicOptionInfo")
		.def("isPolicy", &CvCivicOptionInfo::isPolicy, "bool ()")
		//.def("getTraitNoUpkeep", &CvCivicOptionInfo::getTraitNoUpkeep, "bool (int i)")
		;

	python::class_<CvCivicInfo, python::bases<CvInfoBase> >("CvCivicInfo")

		.def("getCivicOptionType", &CvCivicInfo::getCivicOptionType, "int ()")
		.def("getAnarchyLength", &CvCivicInfo::getAnarchyLength, "int ()")
		.def("getUpkeep", &CvCivicInfo::getUpkeep, "int ()")
		.def("getAIWeight", &CvCivicInfo::getAIWeight, "int ()")
		.def("getGreatPeopleRateModifier", &CvCivicInfo::getGreatPeopleRateModifier, "int ()")
		.def("getGreatGeneralRateModifier", &CvCivicInfo::getGreatGeneralRateModifier, "int ()")
		.def("getDomesticGreatGeneralRateModifier", &CvCivicInfo::getDomesticGreatGeneralRateModifier, "int ()")
		.def("getStateReligionGreatPeopleRateModifier", &CvCivicInfo::getStateReligionGreatPeopleRateModifier, "int ()")
		.def("getDistanceMaintenanceModifier", &CvCivicInfo::getDistanceMaintenanceModifier, "int ()")
		.def("getNumCitiesMaintenanceModifier", &CvCivicInfo::getNumCitiesMaintenanceModifier, "int ()")
		.def("getCorporationMaintenanceModifier", &CvCivicInfo::getCorporationMaintenanceModifier, "int ()")
		.def("getExtraHealth", &CvCivicInfo::getExtraHealth, "int ()")
		.def("getFreeExperience", &CvCivicInfo::getFreeExperience, "int ()")
		.def("getWorkerSpeedModifier", &CvCivicInfo::getWorkerSpeedModifier, "int ()")
		.def("getImprovementUpgradeRateModifier", &CvCivicInfo::getImprovementUpgradeRateModifier, "int ()")
		.def("getMilitaryProductionModifier", &CvCivicInfo::getMilitaryProductionModifier, "int ()")
		.def("getBaseFreeUnits", &CvCivicInfo::getBaseFreeUnits, "int ()")
		.def("getBaseFreeMilitaryUnits", &CvCivicInfo::getBaseFreeMilitaryUnits, "int ()")
		.def("getFreeUnitsPopulationPercent", &CvCivicInfo::getFreeUnitsPopulationPercent, "int ()")
		.def("getFreeMilitaryUnitsPopulationPercent", &CvCivicInfo::getFreeMilitaryUnitsPopulationPercent, "int ()")
		.def("getGoldPerUnit", &CvCivicInfo::getGoldPerUnit, "int ()")
		.def("getGoldPerMilitaryUnit", &CvCivicInfo::getGoldPerMilitaryUnit, "int ()")
		.def("getHappyPerMilitaryUnit", &CvCivicInfo::getHappyPerMilitaryUnit, "int ()")
		.def("getLargestCityHappiness", &CvCivicInfo::getLargestCityHappiness, "int ()")
		.def("getWarWearinessModifier", &CvCivicInfo::getWarWearinessModifier, "int ()")
		.def("getFreeSpecialist", &CvCivicInfo::getFreeSpecialist, "int ()")
		.def("getTradeRoutes", &CvCivicInfo::getTradeRoutes, "int ()")
		.def("getTechPrereq", &CvCivicInfo::getTechPrereq, "int ()")
		.def("getCivicPercentAnger", &CvCivicInfo::getCivicPercentAnger, "int ()")
		.def("getMaxConscript", &CvCivicInfo::getMaxConscript, "int ()")
		.def("getStateReligionHappiness", &CvCivicInfo::getStateReligionHappiness, "int ()")
		.def("getNonStateReligionHappiness", &CvCivicInfo::getNonStateReligionHappiness, "int ()")
		.def("getStateReligionUnitProductionModifier", &CvCivicInfo::getStateReligionUnitProductionModifier, "int ()")
		.def("getStateReligionBuildingProductionModifier", &CvCivicInfo::getStateReligionBuildingProductionModifier, "int ()")
		.def("getStateReligionFreeExperience", &CvCivicInfo::getStateReligionFreeExperience, "int ()")
		.def("getExpInBorderModifier", &CvCivicInfo::getExpInBorderModifier, "bool ()")
/************************************************************************************************/
/* REVOLUTION_MOD                         01/01/08                                jdog5000      */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
		.def("isAllowInquisitions", &CvCivicInfo::isAllowInquisitions, "bool ()")
		.def("isDisallowInquisitions", &CvCivicInfo::isDisallowInquisitions, "bool ()")
		.def("getRevIdxLocal", &CvCivicInfo::getRevIdxLocal, "int ()")
		.def("getRevIdxNational", &CvCivicInfo::getRevIdxNational, "int ()")
		.def("getRevIdxDistanceModifier", &CvCivicInfo::getRevIdxDistanceModifier, "int ()")
		.def("getRevIdxHolyCityGood", &CvCivicInfo::getRevIdxHolyCityGood, "int ()")
		.def("getRevIdxHolyCityBad", &CvCivicInfo::getRevIdxHolyCityBad, "int ()")
		.def("getRevIdxSwitchTo", &CvCivicInfo::getRevIdxSwitchTo, "int ()")
		.def("getRevIdxNationalityMod", &CvCivicInfo::getRevIdxNationalityMod, "float ()")
		.def("getRevIdxBadReligionMod", &CvCivicInfo::getRevIdxBadReligionMod, "float ()")
		.def("getRevIdxGoodReligionMod", &CvCivicInfo::getRevIdxGoodReligionMod, "float ()")
		.def("getRevViolentMod", &CvCivicInfo::getRevViolentMod, "float ()")
		.def("getRevReligiousFreedom", &CvCivicInfo::getRevReligiousFreedom, "int ()")
		.def("getRevLaborFreedom", &CvCivicInfo::getRevLaborFreedom, "int ()")
		.def("getRevEnvironmentalProtection", &CvCivicInfo::getRevEnvironmentalProtection, "int ()")
		.def("getRevDemocracyLevel", &CvCivicInfo::getRevDemocracyLevel, "int ()")

		.def("isCommunism", &CvCivicInfo::isCommunism, "bool ()")
		.def("isFreeSpeech", &CvCivicInfo::isFreeSpeech, "bool ()")
		.def("isCanDoElection", &CvCivicInfo::isCanDoElection, "bool ()")
/************************************************************************************************/
/* REVOLUTION_MOD                          END                                                  */
/************************************************************************************************/

		.def("isMilitaryFoodProduction", &CvCivicInfo::isMilitaryFoodProduction, "bool ()")
		.def("isNoUnhealthyPopulation", &CvCivicInfo::isNoUnhealthyPopulation, "bool ()")
		.def("isBuildingOnlyHealthy", &CvCivicInfo::isBuildingOnlyHealthy, "bool ()")
		.def("isNoForeignTrade", &CvCivicInfo::isNoForeignTrade, "bool ()")
		.def("isNoCorporations", &CvCivicInfo::isNoCorporations, "bool ()")
		.def("isNoForeignCorporations", &CvCivicInfo::isNoForeignCorporations, "bool ()")
		.def("isStateReligion", &CvCivicInfo::isStateReligion, "bool ()")
		.def("isNoNonStateReligionSpread", &CvCivicInfo::isNoNonStateReligionSpread, "bool ()")
		.def("isFreedomFighter", &CvCivicInfo::isFreedomFighter, "bool ()")
		.def("isPolicy", &CvCivicInfo::isPolicy, "bool ()")

		.def("pyGetWeLoveTheKing", &CvCivicInfo::pyGetWeLoveTheKing, "wstring ()")

		// Arrays

		.def("getYieldModifier", &CvCivicInfo::getYieldModifier, "int (int i)")
		.def("getCapitalYieldModifier", &CvCivicInfo::getCapitalYieldModifier, "int (int i)")
		.def("getTradeYieldModifier", &CvCivicInfo::getTradeYieldModifier, "int (int i)")
		.def("getCommerceModifier", &CvCivicInfo::getCommerceModifier, "int (int i)")
		.def("getCapitalCommerceModifier", &CvCivicInfo::getCapitalCommerceModifier, "int (int i)")
		.def("getSpecialistExtraCommerce", &CvCivicInfo::getSpecialistExtraCommerce, "int (int i)")
		.def("getBuildingHappinessChanges", &CvCivicInfo::getBuildingHappinessChanges, "int (int i)")
		.def("getBuildingHealthChanges", &CvCivicInfo::getBuildingHealthChanges, "int (int i)")
		.def("getFeatureHappinessChanges", &CvCivicInfo::getFeatureHappinessChanges, "int (int i)")

		.def("isHurry", &CvCivicInfo::isHurry, "bool (int i)")
		.def("isSpecialBuildingNotRequired", &CvCivicInfo::isSpecialBuildingNotRequired, "bool (int i)")
		.def("isSpecialistValid", &CvCivicInfo::isSpecialistValid, "bool (int i)")

		.def("getImprovementYieldChanges", &CvCivicInfo::getImprovementYieldChanges, "int (int i, int j)")
		;

	python::class_<CvUnitClassInfo, python::bases<CvInfoBase> >("CvUnitClassInfo")
		.def("getMaxGlobalInstances", &CvUnitClassInfo::getMaxGlobalInstances, "int ()")
		.def("getMaxTeamInstances", &CvUnitClassInfo::getMaxTeamInstances, "int ()")
		.def("getMaxPlayerInstances", &CvUnitClassInfo::getMaxPlayerInstances, "int ()")
		.def("getUnlimitedException", &CvUnitClassInfo::isUnlimitedException, "bool ()")
		.def("getInstanceCostModifier", &CvUnitClassInfo::getInstanceCostModifier, "int ()")
		.def("getDefaultUnitIndex", &CvUnitClassInfo::getDefaultUnitIndex, "int ()")
		;

	python::class_<CvBuildingInfo, python::bases<CvInfoBase, CvScalableInfo> >("CvBuildingInfo")

		.def("getBuildingClassType", &CvBuildingInfo::getBuildingClassType, "int ()")
		.def("getVictoryPrereq", &CvBuildingInfo::getVictoryPrereq, "int ()")
		.def("getFreeStartEra", &CvBuildingInfo::getFreeStartEra, "int ()")
		.def("getMaxStartEra", &CvBuildingInfo::getMaxStartEra, "int ()")
		.def("getObsoleteTech", &CvBuildingInfo::getObsoleteTech, "int ()")
		.def("getPrereqAndTech", &CvBuildingInfo::getPrereqAndTech, "int ()")
		.def("getNoBonus", &CvBuildingInfo::getNoBonus, "int ()")
		.def("getPowerBonus", &CvBuildingInfo::getPowerBonus, "int ()")
		.def("getFreeBonus", &CvBuildingInfo::getFreeBonus, "int ()")
		.def("getNumFreeBonuses", &CvBuildingInfo::getNumFreeBonuses, "int ()")
		.def("getNumExtraFreeBonuses", &CvBuildingInfo::getNumExtraFreeBonuses, "int ()")
		.def("getExtraFreeBonus", &CvBuildingInfo::getExtraFreeBonus, "int (int i)")
		.def("getExtraFreeBonusNum", &CvBuildingInfo::getExtraFreeBonusNum, "int (int i)")
		.def("hasExtraFreeBonus", &CvBuildingInfo::hasExtraFreeBonus, "bool (BonusTypes eBonus)")
		.def("getFreeBuildingClass", &CvBuildingInfo::getFreeBuildingClass, "int ()")
		.def("getFreePromotion", &CvBuildingInfo::getFreePromotion, "int ()")
		.def("getCivic", &CvBuildingInfo::getCivicOption, "int ()")
		.def("getAIWeight", &CvBuildingInfo::getAIWeight, "int ()")
		.def("getProductionCost", &CvBuildingInfo::getProductionCost, "int ()")
		.def("getHurryCostModifier", &CvBuildingInfo::getHurryCostModifier, "int ()")
		.def("getHurryAngerModifier", &CvBuildingInfo::getHurryAngerModifier, "int ()")
		.def("getMinAreaSize", &CvBuildingInfo::getMinAreaSize, "int ()")
		.def("getNumCitiesPrereq", &CvBuildingInfo::getNumCitiesPrereq, "int ()")
		.def("getNumTeamsPrereq", &CvBuildingInfo::getNumTeamsPrereq, "int ()")
		.def("getUnitLevelPrereq", &CvBuildingInfo::getUnitLevelPrereq, "int ()")
		.def("getMinLatitude", &CvBuildingInfo::getMinLatitude, "int ()")
		.def("getMaxLatitude", &CvBuildingInfo::getMaxLatitude, "int ()")
		.def("getGreatPeopleRateModifier", &CvBuildingInfo::getGreatPeopleRateModifier, "int ()")
		.def("getGreatGeneralRateModifier", &CvBuildingInfo::getGreatGeneralRateModifier, "int ()")
		.def("getDomesticGreatGeneralRateModifier", &CvBuildingInfo::getDomesticGreatGeneralRateModifier, "int ()")
		.def("getGlobalGreatPeopleRateModifier", &CvBuildingInfo::getGlobalGreatPeopleRateModifier, "int ()")
		.def("getAnarchyModifier", &CvBuildingInfo::getAnarchyModifier, "int ()")
		.def("getGoldenAgeModifier", &CvBuildingInfo::getGoldenAgeModifier, "int ()")
		.def("getGlobalHurryModifier", &CvBuildingInfo::getGlobalHurryModifier, "int ()")
		.def("getFreeExperience", &CvBuildingInfo::getFreeExperience, "int ()")
		.def("getGlobalFreeExperience", &CvBuildingInfo::getGlobalFreeExperience, "int ()")
		.def("getFoodKept", &CvBuildingInfo::getFoodKept, "int ()")
		.def("getAirlift", &CvBuildingInfo::getAirlift, "int ()")
		.def("getAirModifier", &CvBuildingInfo::getAirModifier, "int ()")
		.def("getAirUnitCapacity", &CvBuildingInfo::getAirUnitCapacity, "int ()")
		.def("getNukeModifier", &CvBuildingInfo::getNukeModifier, "int ()")
		.def("getNukeExplosionRand", &CvBuildingInfo::getNukeExplosionRand, "int ()")
		.def("getFreeSpecialist", &CvBuildingInfo::getFreeSpecialist, "int ()")
		.def("getAreaFreeSpecialist", &CvBuildingInfo::getAreaFreeSpecialist, "int ()")
		.def("getGlobalFreeSpecialist", &CvBuildingInfo::getGlobalFreeSpecialist, "int ()")
		.def("getHappiness", &CvBuildingInfo::getHappiness, "int ()")
		.def("getAreaHappiness", &CvBuildingInfo::getAreaHappiness, "int ()")
		.def("getGlobalHappiness", &CvBuildingInfo::getGlobalHappiness, "int ()")
		.def("getStateReligionHappiness", &CvBuildingInfo::getStateReligionHappiness, "int ()")
		.def("getWorkerSpeedModifier", &CvBuildingInfo::getWorkerSpeedModifier, "int ()")
		.def("getMilitaryProductionModifier", &CvBuildingInfo::getMilitaryProductionModifier, "int ()")
		.def("getSpaceProductionModifier", &CvBuildingInfo::getSpaceProductionModifier, "int ()")
		.def("getGlobalSpaceProductionModifier", &CvBuildingInfo::getGlobalSpaceProductionModifier, "int ()")
		.def("getTradeRoutes", &CvBuildingInfo::getTradeRoutes, "int ()")
		.def("getCoastalTradeRoutes", &CvBuildingInfo::getCoastalTradeRoutes, "int ()")
		.def("getGlobalTradeRoutes", &CvBuildingInfo::getGlobalTradeRoutes, "int ()")
		.def("getTradeRouteModifier", &CvBuildingInfo::getTradeRouteModifier, "int ()")
		.def("getForeignTradeRouteModifier", &CvBuildingInfo::getForeignTradeRouteModifier, "int ()")
		.def("getAssetValue", &CvBuildingInfo::getAssetValue, "int ()")
		.def("getPowerValue", &CvBuildingInfo::getPowerValue, "int ()")
		.def("getSpecialBuildingType", &CvBuildingInfo::getSpecialBuildingType, "int ()")
		.def("getAdvisorType", &CvBuildingInfo::getAdvisorType, "int ()")
/************************************************************************************************/
/* REVDCM                                 02/16/10                                phungus420    */
/*                                                                                              */
/* CanConstruct                                                                                 */
/************************************************************************************************/
		.def("getPrereqGameOption", &CvBuildingInfo::getPrereqGameOption, "int ()")
		.def("getNotGameOption", &CvBuildingInfo::getNotGameOption, "int ()")
/************************************************************************************************/
/* REVDCM                                  END                                                  */
/************************************************************************************************/
		.def("getHolyCity", &CvBuildingInfo::getHolyCity, "int ()")
		.def("getReligionType", &CvBuildingInfo::getReligionType, "int ()")
		.def("getStateReligion", &CvBuildingInfo::getStateReligion, "int ()")
		.def("getPrereqReligion", &CvBuildingInfo::getPrereqReligion, "int ()")
		.def("getPrereqCorporation", &CvBuildingInfo::getPrereqCorporation, "int ()")
		.def("getFoundsCorporation", &CvBuildingInfo::getFoundsCorporation, "int ()")
		.def("getGlobalReligionCommerce", &CvBuildingInfo::getGlobalReligionCommerce, "int ()")
		.def("getGlobalCorporationCommerce", &CvBuildingInfo::getGlobalCorporationCommerce, "int ()")
		.def("getPrereqAndBonus", &CvBuildingInfo::getPrereqAndBonus, "int ()")
		.def("getGreatPeopleUnitClass", &CvBuildingInfo::getGreatPeopleUnitClass, "int ()")
		.def("getGreatPeopleRateChange", &CvBuildingInfo::getGreatPeopleRateChange, "int ()")
		.def("getConquestProbability", &CvBuildingInfo::getConquestProbability, "int ()")
		.def("getMaintenanceModifier", &CvBuildingInfo::getMaintenanceModifier, "int ()")
		.def("getWarWearinessModifier", &CvBuildingInfo::getWarWearinessModifier, "int ()")
		.def("getGlobalWarWearinessModifier", &CvBuildingInfo::getGlobalWarWearinessModifier, "int ()")
		.def("getEnemyWarWearinessModifier", &CvBuildingInfo::getEnemyWarWearinessModifier, "int ()")
		.def("getHealRateChange", &CvBuildingInfo::getHealRateChange, "int ()")
		.def("getHealth", &CvBuildingInfo::getHealth, "int ()")
		.def("getAreaHealth", &CvBuildingInfo::getAreaHealth, "int ()")
		.def("getGlobalHealth", &CvBuildingInfo::getGlobalHealth, "int ()")
		.def("getGlobalPopulationChange", &CvBuildingInfo::getGlobalPopulationChange, "int ()")
		.def("getFreeTechs", &CvBuildingInfo::getFreeTechs, "int ()")
		.def("getDefenseModifier", &CvBuildingInfo::getDefenseModifier, "int ()")
		.def("getBombardDefenseModifier", &CvBuildingInfo::getBombardDefenseModifier, "int ()")
		.def("getAllCityDefenseModifier", &CvBuildingInfo::getAllCityDefenseModifier, "int ()")
		.def("getEspionageDefenseModifier", &CvBuildingInfo::getEspionageDefenseModifier, "int ()")
/********************************************************************************/
/**		REVDCM									4/09/10				phungus420	*/
/**																				*/
/**		Building Effects														*/
/********************************************************************************/
		.def("getUnitUpgradePriceModifier", &CvBuildingInfo::getUnitUpgradePriceModifier, "int ()")
		.def("getRevIdxLocal", &CvBuildingInfo::getRevIdxLocal, "int ()")
		.def("getRevIdxNational", &CvBuildingInfo::getRevIdxNational, "int ()")
		.def("getRevIdxDistanceModifier", &CvBuildingInfo::getRevIdxDistanceModifier, "int ()")
/********************************************************************************/
/**		REVDCM									END								*/
/********************************************************************************/
		.def("getMaxPopulationAllowed", &CvBuildingInfo::getMaxPopulationAllowed, "int ()")
		.def("getMaxPopulationChange", &CvBuildingInfo::getMaxPopulationChange, "int ()")

		.def("getMissionType", &CvBuildingInfo::getMissionType, "int ()")
		.def("getVoteSourceType", &CvBuildingInfo::getVoteSourceType, "int ()")
		.def("getPrereqVicinityBonus", &CvBuildingInfo::getPrereqVicinityBonus, "int ()")

		.def("isTeamShare", &CvBuildingInfo::isTeamShare, "bool ()")
		.def("isAutoBuild", &CvBuildingInfo::isAutoBuild, "bool ()")
		.def("isRequiresActiveCivics", &CvBuildingInfo::isRequiresActiveCivics, "bool ()")
		.def("isWater", &CvBuildingInfo::isWater, "bool ()")
		.def("isRiver", &CvBuildingInfo::isRiver, "bool ()")
		.def("isFreshWater", &CvBuildingInfo::isFreshWater, "bool ()")
		.def("isPower", &CvBuildingInfo::isPower, "bool ()")
		.def("isDirtyPower", &CvBuildingInfo::isDirtyPower, "bool ()")
		.def("isAreaCleanPower", &CvBuildingInfo::isAreaCleanPower, "bool ()")
		.def("isAreaBorderObstacle", &CvBuildingInfo::isAreaBorderObstacle, "bool ()")
		.def("isForceTeamVoteEligible", &CvBuildingInfo::isForceTeamVoteEligible, "bool ()")
		.def("isCapital", &CvBuildingInfo::isCapital, "bool ()")
		.def("isGovernmentCenter", &CvBuildingInfo::isGovernmentCenter, "bool ()")
		.def("isGoldenAge", &CvBuildingInfo::isGoldenAge, "bool ()")
		.def("isMapCentering", &CvBuildingInfo::isMapCentering, "bool ()")
		.def("isNoUnhappiness", &CvBuildingInfo::isNoUnhappiness, "bool ()")
		.def("isNoUnhealthyPopulation", &CvBuildingInfo::isNoUnhealthyPopulation, "bool ()")
		.def("isBuildingOnlyHealthy", &CvBuildingInfo::isBuildingOnlyHealthy, "bool ()")
		.def("isNeverCapture", &CvBuildingInfo::isNeverCapture, "bool ()")
		.def("isNukeImmune", &CvBuildingInfo::isNukeImmune, "bool ()")
		.def("isPrereqReligion", &CvBuildingInfo::isPrereqReligion, "bool ()")
		.def("isCenterInCity", &CvBuildingInfo::isCenterInCity, "bool ()")
		.def("isStateReligion", &CvBuildingInfo::isStateReligion, "bool ()")
		.def("isAllowsNukes", &CvBuildingInfo::isAllowsNukes, "bool ()")

		.def("getConstructSound", &CvBuildingInfo::getConstructSound, "string ()")
		.def("getHotKey", &CvBuildingInfo::getHotKey, "string ()")
		.def("getHotKeyDescription", &CvBuildingInfo::getHotKeyDescription, "string ()")
		.def("getArtDefineTag", &CvBuildingInfo::getArtDefineTag, "string ()")
		.def("getMovie", &CvBuildingInfo::getMovie, "string ()")
		.def("getMovieDefineTag", &CvBuildingInfo::getMovieDefineTag, "string ()")


		// Arrays

		.def("getYieldChange", &CvBuildingInfo::getYieldChange, "int (int i)")
		.def("getYieldPerPopChange", &CvBuildingInfo::getYieldPerPopChange, "int (int i)")
		.def("getYieldModifier", &CvBuildingInfo::getYieldModifier, "int (int i)")
		.def("getPowerYieldModifier", &CvBuildingInfo::getPowerYieldModifier, "int (int i)")
		.def("getGlobalYieldModifier", &CvBuildingInfo::getGlobalYieldModifier, "int (int i)")
		.def("getSeaPlotYieldChange", &CvBuildingInfo::getSeaPlotYieldChange, "int (int i)")
		.def("getRiverPlotYieldChange", &CvBuildingInfo::getRiverPlotYieldChange, "int (int i)")
		.def("getGlobalSeaPlotYieldChange", &CvBuildingInfo::getGlobalSeaPlotYieldChange, "int (int i)")
		.def("getCommerceChange", &CvBuildingInfo::getCommerceChange, "int (int i)")
		.def("getCommercePerPopChange", &CvBuildingInfo::getCommercePerPopChange, "int (int i)")
		.def("getObsoleteSafeCommerceChange", &CvBuildingInfo::getObsoleteSafeCommerceChange, "int (int i)")
		.def("getCommerceChangeDoubleTime", &CvBuildingInfo::getCommerceChangeDoubleTime, "int (int i)")
		.def("getCommerceModifier", &CvBuildingInfo::getCommerceModifier, "int (int i)")
		.def("getGlobalCommerceModifier", &CvBuildingInfo::getGlobalCommerceModifier, "int (int i)")
		.def("getStateReligionCommerce", &CvBuildingInfo::getStateReligionCommerce, "int (int i)")
		.def("getCommerceHappiness", &CvBuildingInfo::getCommerceHappiness, "int (int i)")
		.def("getReligionChange", &CvBuildingInfo::getReligionChange, "int (int i)")
		.def("getSpecialistCount", &CvBuildingInfo::getSpecialistCount, "int (int i)")
		.def("getFreeSpecialistCount", &CvBuildingInfo::getFreeSpecialistCount, "int (int i)")
		.def("getBonusHealthChanges", &CvBuildingInfo::getBonusHealthChanges, "int (int i)")
		.def("getBonusHappinessChanges", &CvBuildingInfo::getBonusHappinessChanges, "int (int i)")
		.def("getBonusProductionModifier", &CvBuildingInfo::getBonusProductionModifier, "int (int i)")
		.def("getUnitCombatFreeExperience", &CvBuildingInfo::getUnitCombatFreeExperience, "int (int i)")
		.def("getDomainFreeExperience", &CvBuildingInfo::getDomainFreeExperience, "int (int i)")
		.def("getDomainProductionModifier", &CvBuildingInfo::getDomainProductionModifier, "int (int i)")
		.def("getPrereqAndTechs", &CvBuildingInfo::getPrereqAndTechs, "int (int i)")
		.def("getPrereqOrBonuses", &CvBuildingInfo::getPrereqOrBonuses, "int (int i)")
		.def("getNumPrereqOrBonuses", &CvBuildingInfo::getNumPrereqOrBonuses, "int ()")
		//.def("getProductionTraits", &CvBuildingInfo::getProductionTraits, "int (int i)")
		//.def("getHappinessTraits", &CvBuildingInfo::getHappinessTraits, "int (int i)")
		.def("getBuildingHappinessChanges", &CvBuildingInfo::getBuildingHappinessChanges, "int (int i)")
		.def("getPrereqNumOfBuildingClass", &CvBuildingInfo::getPrereqNumOfBuildingClass, "int (int i)")
		.def("getFlavorValue", &CvBuildingInfo::getFlavorValue, "int (int i)")
		.def("getImprovementFreeSpecialist", &CvBuildingInfo::getImprovementFreeSpecialist, "int (int i)")
		
/************************************************************************************************/
/* Afforess	                  Start		 06/14/10                                               */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
		.def("isPrereqOrCivics", &CvBuildingInfo::isPrereqOrCivics, "bool (int i)")
		.def("isPrereqAndCivics", &CvBuildingInfo::isPrereqAndCivics, "bool (int i)")
		
		.def("isPrereqOrTerrain", &CvBuildingInfo::isPrereqOrTerrain, "bool (int i)")
		.def("isPrereqAndTerrain", &CvBuildingInfo::isPrereqAndTerrain, "bool (int i)")
		
		.def("isPrereqOrImprovement", &CvBuildingInfo::isPrereqOrImprovement, "bool (int i)")
		.def("isPrereqOrFeature", &CvBuildingInfo::isPrereqOrFeature, "bool (int i)")
		
		.def("getTechHealthChanges", &CvBuildingInfo::getTechHealthChanges, "int (int i)") 
		
		.def("isReplaceBuildingClass", &CvBuildingInfo::isReplaceBuildingClass, "bool (int i)")
		
		.def("isPrereqOrBuildingClass", &CvBuildingInfo::isPrereqOrBuildingClass, "bool (int i)")
		
		.def("getNumPopulationEmployed", &CvBuildingInfo::getNumPopulationEmployed, "int")
/************************************************************************************************/
/* Afforess	                     END                                                            */
/************************************************************************************************/
		.def("isCommerceFlexible", &CvBuildingInfo::isCommerceFlexible, "bool (int i)")
		.def("isCommerceChangeOriginalOwner", &CvBuildingInfo::isCommerceChangeOriginalOwner, "bool (int i)")
		.def("isBuildingClassNeededInCity", &CvBuildingInfo::isBuildingClassNeededInCity, "bool (int i)")

		.def("getSpecialistYieldChange", &CvBuildingInfo::getSpecialistYieldChange, "int (int i, int j)")
		.def("getBonusYieldModifier", &CvBuildingInfo::getBonusYieldModifier, "int (int i, int j)")

		.def("getProperties", &CvBuildingInfo::getProperties, python::return_value_policy<python::reference_existing_object>(), "CvProperties ()")

		.def("getArtInfo", &CvBuildingInfo::getArtInfo,  python::return_value_policy<python::reference_existing_object>())
		//TB Combat Mods (Buildings) begin
		//integers
		.def("getTradeCommunicability", &CvBuildingInfo::getTradeCommunicability, "int (int i)")
		.def("getFrontSupportPercentModifier", &CvBuildingInfo::getFrontSupportPercentModifier, "int (int i)")
		.def("getShortRangeSupportPercentModifier", &CvBuildingInfo::getShortRangeSupportPercentModifier, "int (int i)")
		.def("getMediumRangeSupportPercentModifier", &CvBuildingInfo::getMediumRangeSupportPercentModifier, "int (int i)")
		.def("getLongRangeSupportPercentModifier", &CvBuildingInfo::getLongRangeSupportPercentModifier, "int (int i)")
		.def("getFlankSupportPercentModifier", &CvBuildingInfo::getFlankSupportPercentModifier, "int (int i)")
		//boolean vectors without delayed resolution
		//.def("getFreePromoType", &CvBuildingInfo::getFreePromoType, "int (int i)")
		.def("getUnitCombatRetrainType", &CvBuildingInfo::getUnitCombatRetrainType, "int (int i)")
		//integer vectors with pairing method without delayed resolution
		.def("getUnitCombatRepelModifier", &CvBuildingInfo::getUnitCombatRepelModifier, "int (int i)")
		.def("getUnitCombatProdModifier", &CvBuildingInfo::getUnitCombatProdModifier, "int (int i)")
		.def("getUnitCombatOngoingTrainingDuration", &CvBuildingInfo::getUnitCombatOngoingTrainingDuration, "int (int i)")
		.def("getAfflictionOutbreakLevelChange", &CvBuildingInfo::getAfflictionOutbreakLevelChange, "int (int i)")
		.def("getTechOutbreakLevelChange", &CvBuildingInfo::getTechOutbreakLevelChange, "int (int i)")
		//TB Combat Mods (Buildings) end
		;

	python::class_<CvSpecialBuildingInfo, python::bases<CvInfoBase> >("CvSpecialBuildingInfo")
		.def("getObsoleteTech", &CvSpecialBuildingInfo::getObsoleteTech, "int ()")
		.def("getTechPrereq", &CvSpecialBuildingInfo::getTechPrereq, "int ()")
		.def("isValid", &CvSpecialBuildingInfo::isValid, "bool ()")

		// Arrays

		//.def("getProductionTraits", &CvSpecialBuildingInfo::getProductionTraits, "int (int i)")
		;

	python::class_<CvPromotionLineInfo, python::bases<CvInfoBase> >("CvPromotionLineInfo")
		.def("getPrereqTech", &CvPromotionLineInfo::getPrereqTech, "int ()")
		.def("getObsoleteTech", &CvPromotionLineInfo::getObsoleteTech, "int ()")
		.def("getToleranceBuildup", &CvPromotionLineInfo::getToleranceBuildup, "int ()")
		.def("getToleranceDecay", &CvPromotionLineInfo::getToleranceDecay, "int ()")
		.def("getCommunicability", &CvPromotionLineInfo::getCommunicability, "int ()")
		.def("getWorseningProbabilityIncrementModifier", &CvPromotionLineInfo::getWorseningProbabilityIncrementModifier, "int ()")
		.def("getWorsenedCommunicabilityIncrementModifier", &CvPromotionLineInfo::getWorsenedCommunicabilityIncrementModifier, "int ()")
		.def("getWorsenedOvercomeIncrementModifier", &CvPromotionLineInfo::getWorsenedOvercomeIncrementModifier, "int ()")
		.def("getOvercomeProbability", &CvPromotionLineInfo::getOvercomeProbability, "int ()")
		.def("getOvercomeAdjperTurn", &CvPromotionLineInfo::getOvercomeAdjperTurn, "int ()")
		.def("isAffliction", &CvPromotionLineInfo::isAffliction, "bool ()")
		.def("isEquipment", &CvPromotionLineInfo::isEquipment, "bool ()")
		.def("isCritical", &CvPromotionLineInfo::isCritical, "bool ()")
		.def("isNoSpreadonBattle", &CvPromotionLineInfo::isNoSpreadonBattle, "bool ()")
		.def("isNoSpreadUnitProximity", &CvPromotionLineInfo::isNoSpreadUnitProximity, "bool ()")
		.def("isNoSpreadUnittoCity", &CvPromotionLineInfo::isNoSpreadUnittoCity, "bool ()")
		.def("isNoSpreadCitytoUnit", &CvPromotionLineInfo::isNoSpreadCitytoUnit, "bool ()")
		.def("getUnitCombatPrereqType", &CvPromotionLineInfo::getUnitCombatPrereqType, "int (int i)")
		.def("getNumUnitCombatPrereqTypes", &CvPromotionLineInfo::getNumUnitCombatPrereqTypes, "int ()")
		.def("isUnitCombatPrereqType", &CvPromotionLineInfo::isUnitCombatPrereqType, "bool (int i)")
		.def("getNotOnUnitCombatType", &CvPromotionLineInfo::getNotOnUnitCombatType, "int (int i)")
		.def("getNumNotOnUnitCombatTypes", &CvPromotionLineInfo::getNumNotOnUnitCombatTypes, "int ()")
		.def("isNotOnUnitCombatType", &CvPromotionLineInfo::isNotOnUnitCombatType, "bool (int i)")
		.def("isNotOnDomainType", &CvPromotionLineInfo::isNotOnDomainType, "bool (int i)")
		.def("getNotOnGameOption", &CvPromotionLineInfo::getNotOnGameOption, "int (int i)")
		.def("getNumNotOnGameOptions", &CvPromotionLineInfo::getNumNotOnGameOptions, "int ()")
		.def("isNotOnGameOption", &CvPromotionLineInfo::isNotOnGameOption, "bool (int i)")
		.def("getCriticalOriginCombatClassType", &CvPromotionLineInfo::getCriticalOriginCombatClassType, "int (int i)")
		.def("getNumCriticalOriginCombatClassTypes", &CvPromotionLineInfo::getNumCriticalOriginCombatClassTypes, "int ()")
		.def("isCriticalOriginCombatClassType", &CvPromotionLineInfo::isCriticalOriginCombatClassType, "bool (int i)")
		.def("getNumUnitCombatContractChanceChanges", &CvPromotionLineInfo::getNumUnitCombatContractChanceChanges, "int ()")
		.def("getUnitCombatContractChanceChange", &CvPromotionLineInfo::getUnitCombatContractChanceChange, "int (int iUnitCombat)")
		.def("isUnitCombatContractChanceChange", &CvPromotionLineInfo::isUnitCombatContractChanceChange, "bool (int iUnitCombat)")
		.def("getNumUnitCombatOvercomeChanges", &CvPromotionLineInfo::getNumUnitCombatOvercomeChanges, "int ()")
		.def("getUnitCombatOvercomeChange", &CvPromotionLineInfo::getUnitCombatOvercomeChange, "int (int iUnitCombat)")
		.def("isUnitCombatOvercomeChange", &CvPromotionLineInfo::isUnitCombatOvercomeChange, "bool (int iUnitCombat)")
		.def("getNumTechContractChanceChanges", &CvPromotionLineInfo::getNumTechContractChanceChanges, "int ()")
		.def("getTechContractChanceChange", &CvPromotionLineInfo::getTechContractChanceChange, "int (int iTech)")
		.def("isTechContractChanceChange", &CvPromotionLineInfo::isTechContractChanceChange, "bool (int iTech)")
		.def("getNumTechOvercomeChanges", &CvPromotionLineInfo::getNumTechOvercomeChanges, "int ()")
		.def("getTechOvercomeChange", &CvPromotionLineInfo::getTechOvercomeChange, "int (int iTech)")
		.def("isTechOvercomeChange", &CvPromotionLineInfo::isTechOvercomeChange, "bool (int iTech)")
		.def("isBuildUp", &CvPromotionLineInfo::isBuildUp, "bool ()")
		;

	python::class_<CvUnitCombatInfo, python::bases<CvInfoBase> >("CvUnitCombatInfo")
		.def("getAssetMultiplier", &CvUnitCombatInfo::getAssetMultiplier, "int ()")
		.def("getPowerMultiplier", &CvUnitCombatInfo::getPowerMultiplier, "int ()")
		.def("getVisibilityChange", &CvUnitCombatInfo::getVisibilityChange, "int ()")
		.def("getMovesChange", &CvUnitCombatInfo::getMovesChange, "int ()")
		.def("getMoveDiscountChange", &CvUnitCombatInfo::getMoveDiscountChange, "int ()")
		.def("getAirRangeChange", &CvUnitCombatInfo::getAirRangeChange, "int ()")
		.def("getInterceptChange", &CvUnitCombatInfo::getInterceptChange, "int ()")
		.def("getEvasionChange", &CvUnitCombatInfo::getEvasionChange, "int ()")
		.def("getWithdrawalChange", &CvUnitCombatInfo::getWithdrawalChange, "int ()")
		.def("getCargoChange", &CvUnitCombatInfo::getCargoChange, "int ()")
		.def("getCollateralDamageChange", &CvUnitCombatInfo::getCollateralDamageChange, "int ()")
		.def("getBombardRateChange", &CvUnitCombatInfo::getBombardRateChange, "int ()")
		.def("getFirstStrikesChange", &CvUnitCombatInfo::getFirstStrikesChange, "int ()")
		.def("getChanceFirstStrikesChange", &CvUnitCombatInfo::getChanceFirstStrikesChange, "int ()")
		.def("getEnemyHealChange", &CvUnitCombatInfo::getEnemyHealChange, "int ()")
		.def("getNeutralHealChange", &CvUnitCombatInfo::getNeutralHealChange, "int ()")
		.def("getFriendlyHealChange", &CvUnitCombatInfo::getFriendlyHealChange, "int ()")
		.def("getSameTileHealChange", &CvUnitCombatInfo::getSameTileHealChange, "int ()")
		.def("getAdjacentTileHealChange", &CvUnitCombatInfo::getAdjacentTileHealChange, "int ()")
		.def("getCombatPercent", &CvUnitCombatInfo::getCombatPercent, "int ()")
		.def("getCityAttackPercent", &CvUnitCombatInfo::getCityAttackPercent, "int ()")
		.def("getCityDefensePercent", &CvUnitCombatInfo::getCityDefensePercent, "int ()")
		.def("getHillsAttackPercent", &CvUnitCombatInfo::getHillsAttackPercent, "int ()")
		.def("getHillsDefensePercent", &CvUnitCombatInfo::getHillsDefensePercent, "int ()")
		.def("getHillsWorkPercent", &CvUnitCombatInfo::getHillsWorkPercent, "int ()")
		.def("getWorkRatePercent", &CvUnitCombatInfo::getWorkRatePercent, "int ()")
		.def("getRevoltProtection", &CvUnitCombatInfo::getRevoltProtection, "int ()")
		.def("getCollateralDamageProtection", &CvUnitCombatInfo::getCollateralDamageProtection, "int ()")
		.def("getPillageChange", &CvUnitCombatInfo::getPillageChange, "int ()")
		.def("getUpgradeDiscount", &CvUnitCombatInfo::getUpgradeDiscount, "int ()")
		.def("getExperiencePercent", &CvUnitCombatInfo::getExperiencePercent, "int ()")
		.def("getKamikazePercent", &CvUnitCombatInfo::getKamikazePercent, "int ()")
		.def("getAirCombatLimitChange", &CvUnitCombatInfo::getAirCombatLimitChange, "int ()")
		.def("getCelebrityHappy", &CvUnitCombatInfo::getCelebrityHappy, "int ()")
		.def("getCollateralDamageLimitChange", &CvUnitCombatInfo::getCollateralDamageLimitChange, "int ()")
		.def("getCollateralDamageMaxUnitsChange", &CvUnitCombatInfo::getCollateralDamageMaxUnitsChange, "int ()")
		.def("getCombatLimitChange", &CvUnitCombatInfo::getCombatLimitChange, "int ()")
		.def("getExtraDropRange", &CvUnitCombatInfo::getExtraDropRange, "int ()")
		.def("getSurvivorChance", &CvUnitCombatInfo::getSurvivorChance, "int ()")
		.def("getVictoryAdjacentHeal", &CvUnitCombatInfo::getVictoryAdjacentHeal, "int ()")
		.def("getVictoryHeal", &CvUnitCombatInfo::getVictoryHeal, "int ()")
		.def("getVictoryStackHeal", &CvUnitCombatInfo::getVictoryStackHeal, "int ()")
		.def("getAttackCombatModifierChange", &CvUnitCombatInfo::getAttackCombatModifierChange, "int ()")
		.def("getDefenseCombatModifierChange", &CvUnitCombatInfo::getDefenseCombatModifierChange, "int ()")
		.def("getPursuitChange", &CvUnitCombatInfo::getPursuitChange, "int ()")
		.def("getEarlyWithdrawChange", &CvUnitCombatInfo::getEarlyWithdrawChange, "int ()")
		.def("getVSBarbsChange", &CvUnitCombatInfo::getVSBarbsChange, "int ()")
		.def("getArmorChange", &CvUnitCombatInfo::getArmorChange, "int ()")
		.def("getPunctureChange", &CvUnitCombatInfo::getPunctureChange, "int ()")
		.def("getOverrunChange", &CvUnitCombatInfo::getOverrunChange, "int ()")
		.def("getRepelChange", &CvUnitCombatInfo::getRepelChange, "int ()")
		.def("getFortRepelChange", &CvUnitCombatInfo::getFortRepelChange, "int ()")
		.def("getRepelRetriesChange", &CvUnitCombatInfo::getRepelRetriesChange, "int ()")
		.def("getUnyieldingChange", &CvUnitCombatInfo::getUnyieldingChange, "int ()")
		.def("getKnockbackChange", &CvUnitCombatInfo::getKnockbackChange, "int ()")
		.def("getKnockbackRetriesChange", &CvUnitCombatInfo::getKnockbackRetriesChange, "int ()")
		.def("getStrAdjperAttChange", &CvUnitCombatInfo::getStrAdjperAttChange, "int ()")
		.def("getStrAdjperDefChange", &CvUnitCombatInfo::getStrAdjperDefChange, "int ()")
		.def("getWithdrawAdjperAttChange", &CvUnitCombatInfo::getWithdrawAdjperAttChange, "int ()")
		.def("getUnnerveChange", &CvUnitCombatInfo::getUnnerveChange, "int ()")
		.def("getEncloseChange", &CvUnitCombatInfo::getEncloseChange, "int ()")
		.def("getLungeChange", &CvUnitCombatInfo::getLungeChange, "int ()")
		.def("getDynamicDefenseChange", &CvUnitCombatInfo::getDynamicDefenseChange, "int ()")
		.def("getStrengthChange", &CvUnitCombatInfo::getStrengthChange, "int ()")
		.def("getFortitudeChange", &CvUnitCombatInfo::getFortitudeChange, "int ()")
		.def("getFrontSupportPercentChange", &CvUnitCombatInfo::getFrontSupportPercentChange, "int ()")
		.def("getShortRangeSupportPercentChange", &CvUnitCombatInfo::getShortRangeSupportPercentChange, "int ()")
		.def("getMediumRangeSupportPercentChange", &CvUnitCombatInfo::getMediumRangeSupportPercentChange, "int ()")
		.def("getLongRangeSupportPercentChange", &CvUnitCombatInfo::getLongRangeSupportPercentChange, "int ()")
		.def("getFlankSupportPercentChange", &CvUnitCombatInfo::getFlankSupportPercentChange, "int ()")
		.def("getDodgeModifierChange", &CvUnitCombatInfo::getDodgeModifierChange, "int ()")
		.def("getPrecisionModifierChange", &CvUnitCombatInfo::getPrecisionModifierChange, "int ()")
		.def("getPowerShotsChange", &CvUnitCombatInfo::getPowerShotsChange, "int ()")
		.def("getPowerShotCombatModifierChange", &CvUnitCombatInfo::getPowerShotCombatModifierChange, "int ()")
		.def("getPowerShotPunctureModifierChange", &CvUnitCombatInfo::getPowerShotPunctureModifierChange, "int ()")
		.def("getPowerShotPrecisionModifierChange", &CvUnitCombatInfo::getPowerShotPrecisionModifierChange, "int ()")
		.def("getPowerShotCriticalModifierChange", &CvUnitCombatInfo::getPowerShotCriticalModifierChange, "int ()")
		.def("getCriticalModifierChange", &CvUnitCombatInfo::getCriticalModifierChange, "int ()")
		.def("getEnduranceChange", &CvUnitCombatInfo::getEnduranceChange, "int ()")
		.def("getRoundStunProbChange", &CvUnitCombatInfo::getRoundStunProbChange, "int ()")
		.def("getPoisonProbabilityModifierChange", &CvUnitCombatInfo::getPoisonProbabilityModifierChange, "int ()")
		.def("getCaptureProbabilityModifierChange", &CvUnitCombatInfo::getCaptureProbabilityModifierChange, "int ()")
		.def("getCaptureResistanceModifierChange", &CvUnitCombatInfo::getCaptureResistanceModifierChange, "int ()")
		.def("getHillsWorkModifierChange", &CvUnitCombatInfo::getHillsWorkModifierChange, "int ()")
		.def("getPeaksWorkModifierChange", &CvUnitCombatInfo::getPeaksWorkModifierChange, "int ()")
		.def("getBreakdownChanceChange", &CvUnitCombatInfo::getBreakdownChanceChange, "int ()")
		.def("getBreakdownDamageChange", &CvUnitCombatInfo::getBreakdownDamageChange, "int ()")
		.def("getTauntChange", &CvUnitCombatInfo::getTauntChange, "int ()")
		.def("getMaxHPChange", &CvUnitCombatInfo::getMaxHPChange, "int ()")
		.def("getStrengthModifier", &CvUnitCombatInfo::getStrengthModifier, "int ()")
		.def("isDefensiveVictoryMove", &CvUnitCombatInfo::isDefensiveVictoryMove, "bool ()")
		.def("isFreeDrop", &CvUnitCombatInfo::isFreeDrop, "bool ()")
		.def("isOffensiveVictoryMove", &CvUnitCombatInfo::isOffensiveVictoryMove, "bool ()")
		.def("isOneUp", &CvUnitCombatInfo::isOneUp, "bool ()")
		.def("isPillageCulture", &CvUnitCombatInfo::isPillageCulture, "bool ()")
		.def("isPillageEspionage", &CvUnitCombatInfo::isPillageEspionage, "bool ()")
		.def("isPillageMarauder", &CvUnitCombatInfo::isPillageMarauder, "bool ()")
		.def("isPillageOnMove", &CvUnitCombatInfo::isPillageOnMove, "bool ()")
		.def("isPillageOnVictory", &CvUnitCombatInfo::isPillageOnVictory, "bool ()")
		.def("isPillageResearch", &CvUnitCombatInfo::isPillageResearch, "bool ()")
		.def("isBlitz", &CvUnitCombatInfo::isBlitz, "bool ()")
		.def("isAmphib", &CvUnitCombatInfo::isAmphib, "bool ()")
		.def("isRiver", &CvUnitCombatInfo::isRiver, "bool ()")
		.def("isEnemyRoute", &CvUnitCombatInfo::isEnemyRoute, "bool ()")
		.def("isAlwaysHeal", &CvUnitCombatInfo::isAlwaysHeal, "bool ()")
		.def("isHillsDoubleMove", &CvUnitCombatInfo::isHillsDoubleMove, "bool ()")
		.def("isImmuneToFirstStrikes", &CvUnitCombatInfo::isImmuneToFirstStrikes, "bool ()")
		.def("isStampedeChange", &CvUnitCombatInfo::isStampedeChange, "bool ()")
		.def("isRemoveStampede", &CvUnitCombatInfo::isRemoveStampede, "bool ()")
		.def("getAnimalIgnoresBordersChange", &CvUnitCombatInfo::getAnimalIgnoresBordersChange, "int ()")
		.def("isOnslaughtChange", &CvUnitCombatInfo::isOnslaughtChange, "bool ()")
		.def("isMakesDamageCold", &CvUnitCombatInfo::isMakesDamageCold, "bool ()")
		.def("isMakesDamageNotCold", &CvUnitCombatInfo::isMakesDamageNotCold, "bool ()")
		.def("isAddsColdImmunity", &CvUnitCombatInfo::isAddsColdImmunity, "bool ()")
		.def("isRemovesColdImmunity", &CvUnitCombatInfo::isRemovesColdImmunity, "bool ()")
		.def("isAttackOnlyCitiesAdd", &CvUnitCombatInfo::isAttackOnlyCitiesAdd, "bool ()")
		.def("isAttackOnlyCitiesSubtract", &CvUnitCombatInfo::isAttackOnlyCitiesSubtract, "bool ()")
		.def("isIgnoreNoEntryLevelAdd", &CvUnitCombatInfo::isIgnoreNoEntryLevelAdd, "bool ()")
		.def("isIgnoreNoEntryLevelSubtract", &CvUnitCombatInfo::isIgnoreNoEntryLevelSubtract, "bool ()")
		.def("isIgnoreZoneofControlAdd", &CvUnitCombatInfo::isIgnoreZoneofControlAdd, "bool ()")
		.def("isIgnoreZoneofControlSubtract", &CvUnitCombatInfo::isIgnoreZoneofControlSubtract, "bool ()")
		.def("changesMoveThroughPlots", &CvUnitCombatInfo::changesMoveThroughPlots, "bool ()")
		.def("isCanMovePeaks", &CvUnitCombatInfo::isCanMovePeaks, "bool ()")
		.def("isCanLeadThroughPeaks", &CvUnitCombatInfo::isCanLeadThroughPeaks, "bool ()")
		.def("isZoneOfControl", &CvUnitCombatInfo::isZoneOfControl, "bool ()")
		;
}
