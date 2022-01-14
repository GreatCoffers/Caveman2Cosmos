﻿#include "CvWorkerService.h"
#include "CvDefines.h"
#include "CvInfos.h"
#include "CvPlayerAI.h"
#include "CvBonusInfo.h"
#include "CvReachablePlotSet.h"
#include "CvImprovementInfo.h"

bool CvWorkerService::ShouldImproveCity(CvCity* targetCity)
{
	if (targetCity == NULL) return false;
	foreach_(const CvPlot * pLoopPlot, targetCity->plots())
	{
		const int plotIndex = targetCity->getCityPlotIndex(pLoopPlot);
		if (pLoopPlot != NULL
		&& pLoopPlot->getWorkingCity() == targetCity
		&& pLoopPlot->isBeingWorked()
		&& pLoopPlot->getImprovementType() == NO_IMPROVEMENT
		&& targetCity->AI_getBestBuildValue(plotIndex) > 0
		&& GC.getBuildInfo((BuildTypes)targetCity->AI_getBestBuild(plotIndex)).getImprovement() != NO_IMPROVEMENT)
		{
			return true;
		}
	}
	return false;
}