## Code for Caveman2Cosmos
##
## Gives a player a free gatherer when they discover the correct tech.
##
## When a city is conquered there is a chance that the conquerer's state religion will spread to the city.
##
## When a wooden ship is lost at sea there is the chance that a wreck improvement will be placed there.
##

from CvPythonExtensions import *
import BugUtil
import CvUtil

# globals
gc = CyGlobalContext()
#~ localText = CyTranslator()

#~ gaiSettlerWorkerList = None
gaiSettlerWorkerCombatList = None
giMilInstCivic = -1

def init():
	BugUtil.debug("Caveman2Cosmos INIT.")

	## MILITIA PROMOTIONS CODE ##
	#~ global gaiSettlerWorkerList, giMilInstCivic, giVolArmyCivic
	global giMilInstCivic, giVolArmyCivic, gaiSettlerWorkerCombatList
	#~ gaiSettlerWorkerList = [gc.getInfoTypeForString("UNITCLASS_GATHERER"), gc.getInfoTypeForString("UNITCLASS_TRIBE"),
					#~ gc.getInfoTypeForString("UNITCLASS_WORKER"), gc.getInfoTypeForString("UNITCLASS_SETTLER"),
					#~ gc.getInfoTypeForString("UNIT_INDIAN_FAST_WORKER"), gc.getInfoTypeForString("UNITCLASS_WORKBUFFALO"),
					#~ gc.getInfoTypeForString("UNITCLASS_WORKMULE"), gc.getInfoTypeForString("UNITCLASS_WORKELEPHANT"),
					#~ gc.getInfoTypeForString("UNIT_WORKER_INDUSTRIAL"), gc.getInfoTypeForString("UNIT_WORKER_MODERN"),
					#~ gc.getInfoTypeForString("UNIT_CLONES"), gc.getInfoTypeForString("UNIT_WORKER_ANDROID"),
					#~ gc.getInfoTypeForString("UNIT_WORKBOAT"), gc.getInfoTypeForString("UNIT_CLASSIC_WORKBOAT"),
					#~ gc.getInfoTypeForString("UNIT_MIDDLE_WORKBOAT"), gc.getInfoTypeForString("UNIT_MODERN_WORKBOAT"),
					#~ gc.getInfoTypeForString("UNIT_CONSTRUCT_SHIP")
					#~ ]

	gaiSettlerWorkerCombatList =  [gc.getInfoTypeForString("UNITCOMBAT_SETTLER"), gc.getInfoTypeForString("UNITCOMBAT_WORKER"),
							gc.getInfoTypeForString("UNITCOMBAT_SEA_WORKER")
							]

	giMilInstCivic = CvUtil.findInfoTypeNum(gc.getCivicInfo,gc.getNumCivicInfos(),'CIVIC_MILITARY_TRADITION')
	giVolArmyCivic = CvUtil.findInfoTypeNum(gc.getCivicInfo,gc.getNumCivicInfos(),'CIVIC_VOLUNTEER_ARMY')

def onUnitBuilt( argsList):
	'Unit Completed'
	city = argsList[0]
	unit = argsList[1]
	pPlayer = gc.getPlayer(unit.getOwner())

# BEGIN MILITIA PROMOTIONS CODE - based on a prototype from FfH mod
# If the civic is a military one and if the unit being built is not a settler, worker or hero, then begin the function
# Every tile around the city is checked and added to a count based on terrain/plot type
# Based on these results, there is a chance the unit will be given a free Winterborn, Sand Devil, Cliff Walker or Tree Warden promotion

	iMilitaryCivic = 0
	if pPlayer.isCivic(giMilInstCivic):
		iMilitaryCivic = iMilitaryCivic + 1
	if pPlayer.isCivic(giVolArmyCivic) :
		iMilitaryCivic = iMilitaryCivic + 1
	if iMilitaryCivic > 0 :
		#~ if not (unit.getUnitType() in gaiSettlerWorkerList) and isWorldUnitClass(unit.getUnitClassType()) == False:
		if not (unit.getUnitCombatType() in gaiSettlerWorkerCombatList) and isWorldUnitClass(unit.getUnitClassType()) == False:
			iX = city.getX()
			iY = city.getY()

			if unit.getDomainType() == gc.getInfoTypeForString('DOMAIN_LAND'):
				iNumCold = 0
				iNumHot = 0
				iNumBush = 0
				iNumHill = 0
				iNumTree = 0
				iNumCoast = 0
				iTundra = gc.getInfoTypeForString('TERRAIN_TAIGA')
				iPermafrost = gc.getInfoTypeForString('TERRAIN_TUNDRA')
				iSnow = gc.getInfoTypeForString('TERRAIN_ICE')
				iDesert = gc.getInfoTypeForString('TERRAIN_DESERT')
				iDunes = gc.getInfoTypeForString('TERRAIN_DUNES')
				iHills = gc.getInfoTypeForString('TERRAIN_HILL')
				iBarren = gc.getInfoTypeForString('TERRAIN_BARREN')
				iRocky = gc.getInfoTypeForString('TERRAIN_ROCKY')
				iScrub = gc.getInfoTypeForString('TERRAIN_SCRUB')
				iSaltFlats = gc.getInfoTypeForString('TERRAIN_SALT_FLATS')
				iMarsh = gc.getInfoTypeForString('TERRAIN_MARSH')

				for iiX in range(iX-1, iX+2, 1):
					for iiY in range(iY-1, iY+2, 1):
						pPlot = CyMap().plot(iiX,iiY)
						iTerrain = pPlot.getTerrainType()
						iFeature = pPlot.getFeatureType()
						iPlot = pPlot.getPlotType()
						if iTerrain == gc.getInfoTypeForString('TERRAIN_COAST'):
							iNumCoast = iNumCoast +1
						if iTerrain == iDesert or iTerrain == iDunes:
							iNumHot = iNumHot +1
						if (iPlot == iHills or pPlot.isPeak()):
							iNumHill = iNumHill +1
						if (iTerrain == iTundra or iTerrain == iSnow or iTerrain == iPermafrost):
							iNumCold = iNumCold +1
						if (iTerrain == iBarren or iTerrain == iRocky or iTerrain == iScrub or iTerrain == iSaltFlats or iTerrain == iMarsh):
							iNumBush = iNumBush +1
						if ((iFeature == gc.getInfoTypeForString('FEATURE_FOREST') or iFeature == gc.getInfoTypeForString('FEATURE_JUNGLE')) or iFeature == gc.getInfoTypeForString('FEATURE_BAMBOO')):
							iNumTree = iNumTree + 1

				iRnd = CyGame().getSorenRandNum(100, "")
				if iRnd < (iNumTree * 1.25 * iMilitaryCivic):
					iProposedPromotion = gc.getInfoTypeForString('PROMOTION_GREEN_WARDEN')
					if unit.canAcquirePromotion(iProposedPromotion):
						unit.setHasPromotion(iProposedPromotion, True)
				iRnd = CyGame().getSorenRandNum(100, "")
				if iRnd < (iNumCold * 1.25 * iMilitaryCivic):
					iProposedPromotion = gc.getInfoTypeForString('PROMOTION_WINTERBORN')
					if unit.canAcquirePromotion(iProposedPromotion):
						unit.setHasPromotion(iProposedPromotion, True)
				iRnd = CyGame().getSorenRandNum(100, "")
				if iRnd < (iNumHot * 1.5 * iMilitaryCivic):
					iProposedPromotion = gc.getInfoTypeForString('PROMOTION_SAND_DEVIL')
					if unit.canAcquirePromotion(iProposedPromotion):
						unit.setHasPromotion(iProposedPromotion, True)
				iRnd = CyGame().getSorenRandNum(100, "")
				if iRnd < iNumBush * 2 * iMilitaryCivic:
					iProposedPromotion = gc.getInfoTypeForString('PROMOTION_BUSHMAN')
					if unit.canAcquirePromotion(iProposedPromotion):
						unit.setHasPromotion(iProposedPromotion, True)
				iRnd = CyGame().getSorenRandNum(100, "")
				if iRnd < (iNumHill * 1.5 * iMilitaryCivic):
					iProposedPromotion = gc.getInfoTypeForString('PROMOTION_CLIFF_WALKER')
					if unit.canAcquirePromotion(iProposedPromotion):
						unit.setHasPromotion(iProposedPromotion, True)
				iRnd = CyGame().getSorenRandNum(100, "")
				if iRnd < (iNumCoast * 1.5 * iMilitaryCivic):
					iProposedPromotion = gc.getInfoTypeForString('PROMOTION_AMPHIBIOUS')
					if unit.canAcquirePromotion(iProposedPromotion):
						unit.setHasPromotion(iProposedPromotion, True)

			if unit.getDomainType() == gc.getInfoTypeForString('DOMAIN_SEA'):
				iNumReef = 0
				iNumIce = 0
				iNumCoral = 0
				iNumFresh = 0
				iNumCoast = 0
				iNumOcean = 0
				iReef = gc.getInfoTypeForString('FEAURE_REEF')
				iIce = gc.getInfoTypeForString('FEATURE_ICE')
				iCoral = gc.getInfoTypeForString('FEAURE_CORAL')

				for iiX in range(iX-1, iX+2, 1):
					for iiY in range(iY-1, iY+2, 1):
						pPlot = CyMap().plot(iiX,iiY)
						iTerrain = pPlot.getTerrainType()
						iFeature = pPlot.getFeatureType()
						iPlot = pPlot.getPlotType()
						if iFeature == iReef or iFeature == iCoral:
							iNumReef = iNumReef +1
						if iFeature == iIce:
							iNumIce = iNumIce +1

				iRnd = CyGame().getSorenRandNum(100, "")
				if iRnd < (iNumReef * 1.25 * iMilitaryCivic):
					iProposedPromotion = gc.getInfoTypeForString('PROMOTION_COASTAL_ASSAULT1')
					if unit.canAcquirePromotion(iProposedPromotion):
						unit.setHasPromotion(iProposedPromotion, True)
				iRnd = CyGame().getSorenRandNum(100, "")
				if iRnd < (iNumIce * 1.25 * iMilitaryCivic):
					iProposedPromotion = gc.getInfoTypeForString('PROMOTION_COASTAL_GUARD1')
					if unit.canAcquirePromotion(iProposedPromotion):
						unit.setHasPromotion(iProposedPromotion, True)


#END MILITIA PROMOTIONS CODE
