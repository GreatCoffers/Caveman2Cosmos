#pragma once

//  $Header:
//------------------------------------------------------------------------------------------------
//
//  FILE:    CvOutcomeList.h
//
//  PURPOSE: A list of possible outcomes with a relative chance
//
//------------------------------------------------------------------------------------------------
#ifndef CV_OUTCOME_LIST_H
#define CV_OUTCOME_LIST_H

#include "CvXMLLoadUtilityModTools.h"
#include "CvOutcome.h"

class CvUnitAI;

class CvOutcomeList
{
public:
	CvOutcomeList() : m_bIsReference(false) {}
	virtual ~CvOutcomeList();
	CvOutcome* getOutcome(int index);
	int getNumOutcomes() const;

	bool isPossible(const CvUnit& kUnit) const;
	bool isPossibleSomewhere(const CvUnit& kUnit) const;
	bool isPossibleInPlot(const CvUnit& kUnit, const CvPlot& kPlot, bool bForTrade = false) const;
	bool execute(CvUnit& kUnit, PlayerTypes eDefeatedUnitPlayer = NO_PLAYER, UnitTypes eDefeatedUnitType = NO_UNIT);

	int AI_getValueInPlot(const CvUnit& kUnit, const CvPlot& kPlot, bool bForTrade = false);
	
	bool isEmpty() const;
	void clear();

	void buildDisplayString(CvWStringBuffer& szBuffer, const CvUnit& kUnit);
	
	bool read(CvXMLLoadUtility* pXML, const wchar_t* szTagName = L"Outcomes");
	void copyNonDefaults(CvOutcomeList* pOutcomeList, CvXMLLoadUtility* pXML );

	void getCheckSum(unsigned int& iSum);
protected:
	bool m_bIsReference;
	std::vector<CvOutcome*> m_aOutcome;
};

// This outcome list version is supposed to contain a temporary merge of different outcome lists
class CvOutcomeListMerged : public CvOutcomeList
{
public:
	CvOutcomeListMerged() { m_bIsReference = true; }
	void addOutcomeList(CvOutcomeList* pList);

protected:
	std::set<OutcomeTypes> m_setTypes;
};

#endif