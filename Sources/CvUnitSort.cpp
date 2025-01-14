//  $Header:
//------------------------------------------------------------------------------------------------
//
//  FILE:	CvUnitSort.cpp
//
//  PURPOSE: Sorting classes for units
//
//------------------------------------------------------------------------------------------------
#include "CvGameCoreDLL.h"
#include "CvGameCoreDLLUnDefNew.h"
#include "CvGameCoreDLLDefNew.h"

bool UnitSortBase::isLesserUnit(CvPlayer *pPlayer, CvCity *pCity, UnitTypes eUnit1, UnitTypes eUnit2)
{
	// To keep the strict weak ordering for sorting, the result of the comparison cannot just be inverted, equal must always be false
	if (m_bInvert)
		return getUnitValue(pPlayer, pCity, eUnit1) < getUnitValue(pPlayer, pCity, eUnit2);
	else
		return getUnitValue(pPlayer, pCity, eUnit1) > getUnitValue(pPlayer, pCity, eUnit2);
}

bool UnitSortBase::isInverse()
{
	return m_bInvert;
}

bool UnitSortBase::setInverse(bool bInvert)
{
	bool bChanged = bInvert != m_bInvert;
	m_bInvert = bInvert;
	return bChanged;
}

UnitSortBase::~UnitSortBase()
{

}

int UnitSortStrength::getUnitValue(CvPlayer *pPlayer, CvCity *pCity, UnitTypes eUnit)
{
	return std::max(GC.getUnitInfo(eUnit).getCombat(), GC.getUnitInfo(eUnit).getAirCombat());
}

int UnitSortMove::getUnitValue(CvPlayer *pPlayer, CvCity *pCity, UnitTypes eUnit)
{
	return GC.getUnitInfo(eUnit).getMoves();
}

int UnitSortCollateral::getUnitValue(CvPlayer *pPlayer, CvCity *pCity, UnitTypes eUnit)
{
	return GC.getUnitInfo(eUnit).getCollateralDamage();
}

int UnitSortRange::getUnitValue(CvPlayer *pPlayer, CvCity *pCity, UnitTypes eUnit)
{
	return std::max(std::max(GC.getUnitInfo(eUnit).getAirRange(), GC.getUnitInfo(eUnit).getNukeRange()), GC.getUnitInfo(eUnit).getDropRange());
}

int UnitSortBombard::getUnitValue(CvPlayer *pPlayer, CvCity *pCity, UnitTypes eUnit)
{
	return GC.getUnitInfo(eUnit).getBombardRate();
}

int UnitSortCargo::getUnitValue(CvPlayer *pPlayer, CvCity *pCity, UnitTypes eUnit)
{
	return GC.getUnitInfo(eUnit).getCargoSpace();
}

int UnitSortWithdrawal::getUnitValue(CvPlayer *pPlayer, CvCity *pCity, UnitTypes eUnit)
{
	return GC.getUnitInfo(eUnit).getWithdrawalProbability();
}

int UnitSortPower::getUnitValue(CvPlayer *pPlayer, CvCity *pCity, UnitTypes eUnit)
{
	return GC.getUnitInfo(eUnit).getPowerValue();
}

int UnitSortCost::getUnitValue(CvPlayer *pPlayer, CvCity *pCity, UnitTypes eUnit)
{
	if (pCity)
	{
		return pCity->getProductionNeeded(eUnit) - pCity->getUnitProduction(eUnit);
	}
	else
	{
		return pPlayer->getProductionNeeded(eUnit);
	}
}

// dummy
int UnitSortName::getUnitValue(CvPlayer *pPlayer, CvCity *pCity, UnitTypes eUnit)
{
	return 0;
}

// name sorting defaults to A first
bool UnitSortName::isLesserUnit(CvPlayer *pPlayer, CvCity *pCity, UnitTypes eUnit1, UnitTypes eUnit2)
{
	if (m_bInvert)
		return wcscmp(GC.getUnitInfo(eUnit1).getDescription(), GC.getUnitInfo(eUnit2).getDescription()) > 0;
	else
		return wcscmp(GC.getUnitInfo(eUnit1).getDescription(), GC.getUnitInfo(eUnit2).getDescription()) < 0;
}

UnitSortList::UnitSortList(CvPlayer *pPlayer, CvCity *pCity)
{
	m_pPlayer = pPlayer;
	m_pCity = pCity;
	
	m_apUnitSort[UNIT_SORT_NAME] = new UnitSortName();
	m_apUnitSort[UNIT_SORT_COST] = new UnitSortCost(true);
	m_apUnitSort[UNIT_SORT_STRENGTH] = new UnitSortStrength();
	m_apUnitSort[UNIT_SORT_MOVE] = new UnitSortMove();
	m_apUnitSort[UNIT_SORT_COLLATERAL] = new UnitSortCollateral();
	m_apUnitSort[UNIT_SORT_RANGE] = new UnitSortRange();
	m_apUnitSort[UNIT_SORT_BOMBARD] = new UnitSortBombard();
	m_apUnitSort[UNIT_SORT_CARGO] = new UnitSortCargo();
	m_apUnitSort[UNIT_SORT_WITHDRAWAL] = new UnitSortWithdrawal();
	m_apUnitSort[UNIT_SORT_POWER] = new UnitSortPower();

	m_eActiveSort = UNIT_SORT_COST;
}

UnitSortList::~UnitSortList()
{
	for (int i = 0; i < NUM_UNIT_SORT; i++)
	{
		delete m_apUnitSort[i];
	}
}

int UnitSortList::getNumSort()
{
	return NUM_UNIT_SORT;
}

UnitSortTypes UnitSortList::getActiveSort()
{
	return m_eActiveSort;
}

bool UnitSortList::setActiveSort(UnitSortTypes eActiveSort)
{
	FAssertMsg(eActiveSort < NUM_UNIT_SORT, "Index out of bounds");
	FAssertMsg(eActiveSort > -1, "Index out of bounds");
	bool bChanged = m_eActiveSort != eActiveSort;
	m_eActiveSort = eActiveSort;
	return bChanged;
}

void UnitSortList::setCity(CvCity *pCity)
{
	m_pCity = pCity;
}

void UnitSortList::setPlayer(CvPlayer *pPlayer)
{
	m_pPlayer = pPlayer;
}

bool UnitSortList::operator ()(UnitTypes eUnit1, UnitTypes eUnit2)
{
	return m_apUnitSort[m_eActiveSort]->isLesserUnit(m_pPlayer, m_pCity, eUnit1, eUnit2);
}