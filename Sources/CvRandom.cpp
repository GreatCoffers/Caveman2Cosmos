// random.cpp

#include "CvGameCoreDLL.h"

#define RANDOM_A      (1103515245)
#define RANDOM_C      (12345)
#define RANDOM_SHIFT  (16)

CvRandom::CvRandom()
{ 
	reset();
}


CvRandom::~CvRandom()
{ 
	uninit();
}


void CvRandom::init(unsigned long ulSeed)
{
	//--------------------------------
	// Init saved data
	reset(ulSeed);

	//--------------------------------
	// Init non-saved data
}


void CvRandom::uninit()
{
}


// FUNCTION: reset()
// Initializes data members that are serialized.
void CvRandom::reset(unsigned long ulSeed)
{
	//--------------------------------
	// Uninit class
	uninit();

	m_ulRandomSeed = ulSeed;
}


unsigned short CvRandom::get(unsigned short usNum, const TCHAR* pszLog)
{

/*************************************************************************************************/
/**	Xienwolf Tweak							02/22/09											**/
/**																								**/
/**		Horrible method of logging randoms.  Removed to save from uselessly flooding filesize	**/
/*************************************************************************************************/
/**								---- Start Original Code ----									**/
#ifdef _DEBUG
	if (pszLog != NULL)
	{
		if (GC.getLogging() && GC.getRandLogging() && GC.getGameINLINE().isNetworkMultiPlayer())
		{
			if (GC.getGameINLINE().getTurnSlice() > 0)
			{
				TCHAR szOut[1024];
				sprintf(szOut, "Player %d - Multiplayer RNG Log.log", GC.getGameINLINE().getActivePlayer());
				//gDLL->messageControlLog(szOut);
				GC.getGameINLINE().logMsgTo(szOut, "Rand = %d (%d) on %d (%s)\n", getSeed(), usNum, GC.getGameINLINE().getTurnSlice(), pszLog);
			}
		}
	}
#endif
/**								----  End Original Code  ----									**/
/*************************************************************************************************/
/**	Tweak									END													**/
/*************************************************************************************************/
	m_ulRandomSeed = ((RANDOM_A * m_ulRandomSeed) + RANDOM_C);

	unsigned short us = ((unsigned short)((((m_ulRandomSeed >> RANDOM_SHIFT) & MAX_UNSIGNED_SHORT) * ((unsigned long)usNum)) / (MAX_UNSIGNED_SHORT + 1)));

	return us;
}

unsigned int CvRandom::getInt()
{
	return get(MAX_UNSIGNED_SHORT,NULL) + (get(MAX_UNSIGNED_SHORT,NULL) << 16);
}


float CvRandom::getFloat()
{
	return (((float)(get(MAX_UNSIGNED_SHORT))) / ((float)MAX_UNSIGNED_SHORT));
}


void CvRandom::reseed(unsigned long ulNewValue)
{
	m_ulRandomSeed = ulNewValue;
}


unsigned long CvRandom::getSeed()
{
	return m_ulRandomSeed;
}


void CvRandom::read(FDataStreamBase* pStream)
{
	CvTaggedSaveFormatWrapper&	wrapper = CvTaggedSaveFormatWrapper::getSaveFormatWrapper();

	wrapper.AttachToStream(pStream);

	WRAPPER_READ_OBJECT_START(wrapper);

	reset();

	WRAPPER_READ(wrapper, "CvRandom", &m_ulRandomSeed);

	WRAPPER_READ_OBJECT_END(wrapper);
}


void CvRandom::write(FDataStreamBase* pStream)
{
	CvTaggedSaveFormatWrapper&	wrapper = CvTaggedSaveFormatWrapper::getSaveFormatWrapper();

	wrapper.AttachToStream(pStream);

	WRAPPER_WRITE_OBJECT_START(wrapper);

	WRAPPER_WRITE(wrapper, "CvRandom", m_ulRandomSeed);

	WRAPPER_WRITE_OBJECT_END(wrapper);
}
