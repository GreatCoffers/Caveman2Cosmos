//  $Header:
//------------------------------------------------------------------------------------------------
//
//  FILE:    CvXMLLoadUtility.cpp
//
//  AUTHOR:  Eric MacDonald  --  8/2003
//			Mustafa Thamer
//
//  PURPOSE: Group of functions to load in the xml files for Civilization 4
//
//------------------------------------------------------------------------------------------------
//  Copyright (c) 2003 Firaxis Games, Inc. All rights reserved.
//------------------------------------------------------------------------------------------------


#include "CvGameCoreDLL.h"

static const int kBufSize = 2048;

//
// for logging
//
void CvXMLLoadUtility::logMsg(char* format, ... )
{
//#ifdef _DEBUG
	static char buf[kBufSize];
	_vsnprintf( buf, kBufSize-4, format, (char*)(&format+1) );
	OutputDebugString(buf);
	gDLL->logMsg("xml.log", buf);
//#endif
}

void CvXMLLoadUtility::logMsgW(wchar_t* format, ... )
{
//#ifdef _DEBUG
		static wchar_t buf[kBufSize];
		_vsnwprintf( buf, kBufSize-4, format, (char*)(&format+1) );
		OutputDebugStringW(buf);
		static char buf2[kBufSize];
		wcstombs(buf2, buf, kBufSize-4);
		gDLL->logMsg("xml.log", buf2);
//#endif
}

/************************************************************************************************/
/* XML_CHECK_DOUBLE_TYPE                   10/10/07                                MRGENIE      */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
#ifdef _DEBUG
void CvXMLLoadUtility::logXmlCheckDoubleTypes(char* format, ... )
{
	{
		static char buf[kBufSize];
		_vsnprintf( buf, kBufSize-4, format, (char*)(&format+1) );
		gDLL->logMsg("XmlCheckDoubleTypes.log", buf);
	}
}
#endif
/************************************************************************************************/
/* XML_CHECK_DOUBLE_TYPE                   END                                                  */
/************************************************************************************************/
/************************************************************************************************/
/* XML_MODULAR_ART_LOADING                 10/19/07                                MRGENIE      */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
#ifdef _DEBUG
void CvXMLLoadUtility::XmlArtTagVerification(char* format, ... )
{
	{
		static char buf[kBufSize];
		_vsnprintf( buf, kBufSize-4, format, (char*)(&format+1) );
		gDLL->logMsg("XmlArtTagVerification.log", buf);
	}
}
#endif
/************************************************************************************************/
/* XML_MODULAR_ART_LOADING                 END                                                  */
/************************************************************************************************/
/************************************************************************************************/
/* MODULAR_LOADING_CONTROL                 10/30/07                                MRGENIE      */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
void CvXMLLoadUtility::logMLF(char* format, ... )
{
#ifdef _DEBUG
	{
		static char buf[kBufSize];
		_vsnprintf( buf, kBufSize-4, format, (char*)(&format+1) );
		gDLL->logMsg("MLF.log", buf);
	}
#endif
}
/************************************************************************************************/
/* XML_MODULAR_ART_LOADING                 END                                                  */
/************************************************************************************************/
/************************************************************************************************/
/* MODULAR_LOADING_CONTROL                 02/20/08                                MRGENIE      */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
//
void CvXMLLoadUtility::logXmlDependencyTypes(char* format, ... )
{
#ifdef _DEBUG	
	{
		static char buf[kBufSize];
		_vsnprintf( buf, kBufSize-4, format, (char*)(&format+1) );
		gDLL->logMsg("XmlDependencyTypes.log", buf);
	}
#endif
}
//
/************************************************************************************************/
/* MODULAR_LOADING_CONTROL                 END                                                  */
/************************************************************************************************/
/************************************************************************************************/
/* Afforess	                  Start		 06/13/10                                               */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
void CvXMLLoadUtility::logXML(char* format, ... )
{
#ifdef _DEBUG	
	{
		static char buf[kBufSize];
		_vsnprintf( buf, kBufSize-4, format, (char*)(&format+1) );
		gDLL->logMsg("XML Loadup.log", buf);
	}
#endif
}
/************************************************************************************************/
/* Afforess	                     END                                                            */
/************************************************************************************************/
bool CvXMLLoadUtility::CreateFXml()
{
	PROFILE("CreateFXML");

/*	try
	{
#ifdef _DEBUG
		m_pFXml = GETXML->CreateFXml();
#else
		m_pFXml = GETXML->CreateFXml(m_pSchemaCache);
#endif
	}
	catch(...)
	{
		char	szMessage[512];
		sprintf( szMessage, "Caught unhandled exception creating XML parser object \n Current XML file is: %s", GC.getCurrentXMLFile().GetCString());
		gDLL->MessageBox( szMessage, "Loading Error" );
		return false;
	}*/

	m_pParser = new xercesc::XercesDOMParser();
	ParserErrorHandler* parserErrorHandler = new ParserErrorHandler();

	m_pParser->setErrorHandler(parserErrorHandler);
	m_pParser->setValidationScheme(xercesc::XercesDOMParser::Val_Auto);
    m_pParser->setDoNamespaces(true);
	m_pParser->setDoSchema(true);
	m_pParser->setValidationConstraintFatal(false);
	m_pParser->setValidationSchemaFullChecking(true);
	//std::string szDir = gDLL->getModName();
	//std::string szPath = szDir.append("Assets\\XML\\Schema\\Caveman2Cosmos.xsd");
	m_pParser->setHandleMultipleImports(true);
	m_pParser->useCachedGrammarInParse(true);
	m_pParser->setLoadSchema(true);
	m_pParser->cacheGrammarFromParse(true);
	//char szLog[2048];
	//try
	//{
	//	if (m_pParser->loadGrammar(szPath.c_str(), xercesc::Grammar::SchemaGrammarType, true) == NULL)
	//	{
	//		char	szMessage[512];
	//		sprintf( szMessage, "Error while loading XML parser grammar object \n");
	//		gDLL->MessageBox( szMessage, "Loading Error" );
	//		return false;
	//	}
	//}
	//catch (const xercesc::XMLException& toCatch) 
	//{
	//	char* message = xercesc::XMLString::transcode(toCatch.getMessage());
	//	sprintf(szLog, "XML error: %s(%i) : (%s)\n", 
	//		toCatch.getSrcFile(), toCatch.getSrcLine(), message);
	//	logMsg(szLog);
	//	gDLL->MessageBox(szLog, "Error");
	//	xercesc::XMLString::release(&message);
	//	return false;
	//}
	//catch (const xercesc::DOMException& toCatch) 
	//{
	//	char* message = xercesc::XMLString::transcode(toCatch.msg);
	//	sprintf(szLog, "XML model (DOM) error: %s : %s\n", szPath.c_str(), message);
	//	logMsg(szLog);
	//	gDLL->MessageBox(szLog, "Error");
	//	xercesc::XMLString::release(&message);
	//	return false;
	//}
	//catch (const xercesc::SAXParseException& toCatch)
	//{
	//	char* message = xercesc::XMLString::transcode(toCatch.getMessage());
	//	sprintf(szLog, "XML parsing SAX error:\n%s :\n%s at line %llu", szPath.c_str(), message, toCatch.getLineNumber());
	//	logMsg(szLog);
	//	gDLL->MessageBox(szLog, "Error");
	//	xercesc::XMLString::release(&message);
	//	return false;
	//}
	//catch (const xercesc::SAXException& toCatch) 
	//{
	//	char* message = xercesc::XMLString::transcode(toCatch.getMessage());
	//	sprintf(szLog, "XML parsing SAX error: %s : %s\n", szPath.c_str(), message);
	//	logMsg(szLog);
	//	gDLL->MessageBox(szLog, "Error");
	//	xercesc::XMLString::release(&message);
	//	return false;
	//}

	return true;
}

void CvXMLLoadUtility::DestroyFXml()
{
	PROFILE("DestroyFXML");
//	GETXML->DestroyFXml(m_pFXml);

	delete m_pParser;
}

//------------------------------------------------------------------------------------------------------
//
//  FUNCTION:   CvXMLLoadUtility()
//
//  PURPOSE :   Default constructor
//
//------------------------------------------------------------------------------------------------------
CvXMLLoadUtility::CvXMLLoadUtility() :
m_iCurProgressStep(0),
m_pCBFxn(NULL)
//m_pFXml(NULL)
{
	//OutputDebugString("Initializing XML Load Utility: Start");
	try 
	{
		xercesc::XMLPlatformUtils::Initialize();
	}
	catch (const xercesc::XMLException& toCatch) 
	{
		OutputDebugString("XMLPlatformUtils::Initialize Faild");
		char* message = xercesc::XMLString::transcode(toCatch.getMessage());
		logMsg(message);
		gDLL->MessageBox(message, "Error");
		xercesc::XMLString::release(&message);
	}
	//OutputDebugString("Initializing XML Load Utility: End");

//	m_pSchemaCache = GETXML->CreateFXmlSchemaCache();
//	m_pSchemaCache = NULL;

}

//------------------------------------------------------------------------------------------------------
//
//  FUNCTION:   ~CvXMLLoadUtility()
//
//  PURPOSE :   Default destructor
//
//------------------------------------------------------------------------------------------------------
CvXMLLoadUtility::~CvXMLLoadUtility()
{
	//GETXML->DestroyFXmlSchemaCache(m_pSchemaCache);

	xercesc::XMLPlatformUtils::Terminate();
}

//------------------------------------------------------------------------------------------------------
//
//  FUNCTION:   ResetLandscapeInfo()
//
//  PURPOSE :  Clean up items for in-game reloading
//
//------------------------------------------------------------------------------------------------------
void CvXMLLoadUtility::ResetLandscapeInfo()
{
	for (int i = 0; i < GC.getNumLandscapeInfos(); ++i)
	{
		SAFE_DELETE(GC.getLandscapeInfos()[i]);
	}

	GC.getLandscapeInfos().clear();

	SetupGlobalLandscapeInfo();
}

//------------------------------------------------------------------------------------------------------
//
//  FUNCTION:   ResetGlobalEffectInfo()
//
//  PURPOSE :  Clean up items for in-game reloading
//
//------------------------------------------------------------------------------------------------------
void CvXMLLoadUtility::ResetGlobalEffectInfo()
{
	for (int i = 0; i < GC.getNumEffectInfos(); ++i)
	{
		SAFE_DELETE(GC.getEffectInfos()[i]);
	}

	GC.getEffectInfos().clear();

	LoadGlobalClassInfo(GC.getEffectInfos(), "CIV4EffectInfos", "Misc", L"/Civ4EffectInfos/EffectInfos/EffectInfo", false);
}


//------------------------------------------------------------------------------------------------------
//
//  FUNCTION:   MakeMaskFromString(unsigned int *puiMask, char* szMask)
//
//  PURPOSE :   takes a string of hex digits, 0-f and converts it into an unsigned integer
//				mask value
//
//------------------------------------------------------------------------------------------------------
void CvXMLLoadUtility::MakeMaskFromString(unsigned int *puiMask, char* szMask)
{
	int iLen = strlen(szMask);

	// loop through each character in the szMask parameter
	for (int i=0;i<iLen;i++)
	{
		// if the current character in the string is a zero
		if (szMask[i] == '0')
		{
			// shift the current value of the mask to the left by 4 bits
			*puiMask <<= 4;
			// making the last 4 bits of the mask 0000
		}
		// if the current character in the string is a zero
		else if (szMask[i] == '1')
		{
			// shift the current value of the mask to the left by 4 bits
			*puiMask <<= 4;
			// add 1 to the adjusted value of the mask
			// making the last 4 bits of the mask 0001
			*puiMask += 1;
		}
		// if the current character in the string is a two
		else if (szMask[i] == '2')
		{
			// shift the current value of the mask to the left by 4 bits
			*puiMask <<= 4;
			// add 2 to the adjusted value of the mask
			// making the last 4 bits of the mask 0010
			*puiMask += 2;
		}
		// if the current character in the string is a three
		else if (szMask[i] == '3')
		{
			// shift the current value of the mask to the left by 4 bits
			*puiMask <<= 4;
			// add 3 to the adjusted value of the mask
			// making the last 4 bits of the mask 0011
			*puiMask += 3;
		}
		// if the current character in the string is a four
		else if (szMask[i] == '4')
		{
			// shift the current value of the mask to the left by 4 bits
			*puiMask <<= 4;
			// add 4 to the adjusted value of the mask
			// making the last 4 bits of the mask 0100
			*puiMask += 4;
		}
		// if the current character in the string is a five
		else if (szMask[i] == '5')
		{
			// shift the current value of the mask to the left by 4 bits
			*puiMask <<= 4;
			// add 5 to the adjusted value of the mask
			// making the last 4 bits of the mask 0101
			*puiMask += 5;
		}
		// if the current character in the string is a six
		else if (szMask[i] == '6')
		{
			// shift the current value of the mask to the left by 4 bits
			*puiMask <<= 4;
			// add 6 to the adjusted value of the mask
			// making the last 4 bits of the mask 0110
			*puiMask += 6;
		}
		// if the current character in the string is a seven
		else if (szMask[i] == '7')
		{
			// shift the current value of the mask to the left by 4 bits
			*puiMask <<= 4;
			// add 7 to the adjusted value of the mask
			// making the last 4 bits of the mask 0111
			*puiMask += 7;
		}
		// if the current character in the string is a eight
		else if (szMask[i] == '8')
		{
			// shift the current value of the mask to the left by 4 bits
			*puiMask <<= 4;
			// add 8 to the adjusted value of the mask
			// making the last 4 bits of the mask 1000
			*puiMask += 8;
		}
		// if the current character in the string is a nine
		else if (szMask[i] == '9')
		{
			// shift the current value of the mask to the left by 4 bits
			*puiMask <<= 4;
			// add 9 to the adjusted value of the mask
			// making the last 4 bits of the mask 1001
			*puiMask += 9;
		}
		// if the current character in the string is a A, 10
		else if ((szMask[i] == 'a') || (szMask[i] == 'A'))
		{
			// shift the current value of the mask to the left by 4 bits
			*puiMask <<= 4;
			// add 10 to the adjusted value of the mask
			// making the last 4 bits of the mask 1010
			*puiMask += 10;
		}
		// if the current character in the string is a B, 11
		else if ((szMask[i] == 'b') || (szMask[i] == 'B'))
		{
			// shift the current value of the mask to the left by 4 bits
			*puiMask <<= 4;
			// add 11 to the adjusted value of the mask
			// making the last 4 bits of the mask 1011
			*puiMask += 11;
		}
		// if the current character in the string is a C, 12
		else if ((szMask[i] == 'c') || (szMask[i] == 'C'))
		{
			// shift the current value of the mask to the left by 4 bits
			*puiMask <<= 4;
			// add 12 to the adjusted value of the mask
			// making the last 4 bits of the mask 1100
			*puiMask += 12;
		}
		// if the current character in the string is a D, 13
		else if ((szMask[i] == 'd') || (szMask[i] == 'D'))
		{
			// shift the current value of the mask to the left by 4 bits
			*puiMask <<= 4;
			// add 13 to the adjusted value of the mask
			// making the last 4 bits of the mask 1101
			*puiMask += 13;
		}
		// if the current character in the string is a E, 14
		else if ((szMask[i] == 'd') || (szMask[i] == 'E'))
		{
			// shift the current value of the mask to the left by 4 bits
			*puiMask <<= 4;
			// add 14 to the adjusted value of the mask
			// making the last 4 bits of the mask 1110
			*puiMask += 14;
		}
		// if the current character in the string is a F, 15
		else if ((szMask[i] == 'f') || (szMask[i] == 'F'))
		{
			// shift the current value of the mask to the left by 4 bits
			*puiMask <<= 4;
			// add 15 to the adjusted value of the mask
			// making the last 4 bits of the mask 1111
			*puiMask += 15;
		}
	}
}

//------------------------------------------------------------------------------------------------------
//
//  FUNCTION:   GetInfoClass(TCHAR* pszVal)
//
//  PURPOSE :   Searches the InfoClass for the pszVal and returns the location if a match
//				is found.
//				returns -1 if no match is found
//
//------------------------------------------------------------------------------------------------------
int CvXMLLoadUtility::GetInfoClass(const TCHAR* pszVal)
{
/************************************************************************************************/
/* Afforess	                  Start		 03/18/10                                               */
/*                                                                                              */
/* Hide Assert for Deleted Objects                                                       */
/************************************************************************************************/
	//AIAndy: I don't think we should do a hack like that, references in the XML should always be valid
	//if ((GC.getNumGameSpeedInfos() > 0) && (GC.getDefineINT(pszVal)))
	//	hideAssert = true;
	//if (pszVal == "") return -1;
/************************************************************************************************/
/* Afforess	                     END                                                            */
/************************************************************************************************/

	int idx = GC.getInfoTypeForString(pszVal, false);

	// if we found a match in the list we will return the value of the loop counter
	// which will hold the location of the match in the list
	if (idx != -1)
	{
		return idx;
	}

	if (_tcscmp(pszVal,"NONE")!=0 && _tcscmp(pszVal,"")!=0)
	{
		char errorMsg[1024];
		sprintf(errorMsg, "Tag: %s in Info class was incorrect \n Current XML file is: %s", pszVal, GC.getCurrentXMLFile().GetCString());
		gDLL->MessageBox(errorMsg, "XML Error");
	}

	return idx;
}


//------------------------------------------------------------------------------------------------------
//
//  FUNCTION:   LoadCivXml(FXml* pFXml, TCHAR* szFilename)
//
//  PURPOSE :   Gets the full pathname for the xml file from the FileManager .
//				If it is succesful we return true
//				from the function and a valid FXml pointer to the pFXml parameter.
//
//------------------------------------------------------------------------------------------------------
bool CvXMLLoadUtility::LoadCivXml(FXml* pFXml, const TCHAR* szFilename)
{
	char szLog[8192];
	sprintf(szLog, "LoadCivXml (%s)", szFilename);
	PROFILE(szLog);
	OutputDebugString(szLog);
	OutputDebugString("\n");
	m_pParser->setValidationScheme(xercesc::XercesDOMParser::Val_Auto);

	CvString szPath = szFilename;
	CvString fsFilename = szFilename;
	szPath = "Assets\\" + szPath;
	
	std::string szDir = gDLL->getModName();
	szDir.append(szPath);
	OutputDebugString(szDir.c_str());
	FILE* f = fopen(szDir.c_str(), "r");
	if (f == NULL)
	{
		// could not open file, try from current dir
		m_pParser->setValidationScheme(xercesc::XercesDOMParser::Val_Never);
		szDir = szPath;
		OutputDebugString(szDir.c_str());
		f = fopen(szDir.c_str(), "r");
		if (f == NULL)
		{
			// could not open file, try Warlords dir
			szDir = "..\\Warlords\\";
			szDir.append(szPath);
			OutputDebugString(szDir.c_str());
			f = fopen(szDir.c_str(), "r");
			if (f == NULL)
			{
				// could not open file, try from one further up
				szDir = "..\\";
				szDir.append(szPath);
				OutputDebugString(szDir.c_str());
				f = fopen(szDir.c_str(), "r");
				if (f == NULL)
				{
					sprintf(szLog, "IO error: %s : File can't be found\n", szPath.c_str());
					logMsg(szLog);
					gDLL->MessageBox(szLog, "Error");
					return false;
				}
			}
		}
	}
	fclose(f);

	sprintf(szLog, "LoadCivXml: Read %s", szDir.c_str());
	logMsg(szLog);
	OutputDebugString(szLog);

/************************************************************************************************/
/* XML_CHECK_DOUBLE_TYPE                   10/10/07                                MRGENIE      */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
#ifdef _DEBUG
	logXmlCheckDoubleTypes("Loading XML file %s\n", szPath.c_str());
#endif
/************************************************************************************************/
/* XML_CHECK_DOUBLE_TYPE                   END                                                  */
/************************************************************************************************/


	try 
	{
		m_pParser->parse(szDir.c_str());
		m_pCurrentXmlElement = m_pParser->getDocument()->getDocumentElement();
    }
	catch (const xercesc::XMLException& toCatch) 
	{
        char* message = xercesc::XMLString::transcode(toCatch.getMessage());
		sprintf(szLog, "XML error: %s(%i) : (%s)\n", 
			    toCatch.getSrcFile(), toCatch.getSrcLine(), message);
		logMsg(szLog);
		gDLL->MessageBox(szLog, "Error");
        xercesc::XMLString::release(&message);
		return false;
    }
	catch (const xercesc::DOMException& toCatch) 
	{
        char* message = xercesc::XMLString::transcode(toCatch.msg);
		sprintf(szLog, "XML model (DOM) error: %s : %s\n", szPath.c_str(), message);
		logMsg(szLog);
		gDLL->MessageBox(szLog, "Error");
        xercesc::XMLString::release(&message);
		return false;
    }
	catch (const xercesc::SAXParseException& toCatch)
	{
		char* message = xercesc::XMLString::transcode(toCatch.getMessage());
		sprintf(szLog, "XML parsing SAX error:\n%s :\n%s at line %llu", szPath.c_str(), message, toCatch.getLineNumber());
		logMsg(szLog);
		gDLL->MessageBox(szLog, "Error");
		xercesc::XMLString::release(&message);
		return false;
	}
	catch (const xercesc::SAXException& toCatch) 
	{
        char* message = xercesc::XMLString::transcode(toCatch.getMessage());
		sprintf(szLog, "XML parsing SAX error: %s : %s\n", szPath.c_str(), message);
		logMsg(szLog);
		gDLL->MessageBox(szLog, "Error");
        xercesc::XMLString::release(&message);
        return false;
    }
	catch (...) 
	{
		sprintf(szLog, "Something happened\n");
		logMsg(szLog);
		gDLL->MessageBox(szLog, "Error");
        return false;
    }

	logMsg("Load XML file %s SUCCEEDED\n", szPath.c_str());
	GC.setCurrentXMLFile(szFilename);
	return true;	// success
}

//------------------------------------------------------------------------------------------------------
//
//  FUNCTION:   CreateHotKeyFromDescription(bool bShift, bool bAlt, bool bCtrl)
//
//  PURPOSE :   create a hot key from a description and return it
//
//------------------------------------------------------------------------------------------------------
CvWString CvXMLLoadUtility::CreateHotKeyFromDescription(const TCHAR* pszHotKey, bool bShift, bool bAlt, bool bCtrl)
{
	// Delete <COLOR:140,255,40,255>Shift+Delete</COLOR>
	CvWString szHotKey;

	if (pszHotKey && strcmp(pszHotKey,"") != 0)
	{
		szHotKey += L" <color=140,255,40,255>";
		szHotKey += L"&lt;";

		if (bShift)
		{
			szHotKey += gDLL->getText("TXT_KEY_SHIFT");
		}

		if (bAlt)
		{
			szHotKey += gDLL->getText("TXT_KEY_ALT");
		}

		if (bCtrl)
		{
			szHotKey += gDLL->getText("TXT_KEY_CTRL");
		}

		szHotKey = szHotKey + CreateKeyStringFromKBCode(pszHotKey);
		szHotKey += L">";
		szHotKey += L"</color>";
	}

	return szHotKey;
}

bool CvXMLLoadUtility::SetStringList(CvString** ppszStringArray, int* piSize)
{
	int i;
	CvString* pszStringArray;

	FAssertMsg(*ppszStringArray == NULL, "Possible memory leak");
	*piSize = GetXmlChildrenNumber();
	*ppszStringArray = NULL;
	if (*piSize > 0)
	{
		*ppszStringArray = new CvString[*piSize];
		pszStringArray = *ppszStringArray;
		if (GetChildXmlVal(pszStringArray[0]))
		{
			for (i=1;i<*piSize;i++)
			{
				if (!GetNextXmlVal(pszStringArray[i]))
				{
					break;
				}
			}

			MoveToXmlParent();
		}
	}

	return true;
}

//------------------------------------------------------------------------------------------------------
//
//  FUNCTION:   CreateKeyStringFromKBCode(const TCHAR* pszHotKey)
//
//  PURPOSE :   Create a keyboard string from a KB code, Delete would be returned for KB_DELETE
//
//------------------------------------------------------------------------------------------------------
CvWString CvXMLLoadUtility::CreateKeyStringFromKBCode(const TCHAR* pszHotKey)
{
	// SPEEDUP
	PROFILE("CreateKeyStringFromKBCode");

	int i;

	struct CvKeyBoardMapping
	{
		TCHAR szDefineString[25];
		CvWString szKeyString;
	};

	// TODO - this should be a stl map instead of looping strcmp
	const int iNumKeyBoardMappings=108;
	const CvKeyBoardMapping asCvKeyBoardMapping[iNumKeyBoardMappings] =
	{
		{"KB_ESCAPE", gDLL->getText("TXT_KEY_KEYBOARD_ESCAPE")},
		{"KB_0","0"},
		{"KB_1","1"},
		{"KB_2","2"},
		{"KB_3","3"},
		{"KB_4","4"},
		{"KB_5","5"},
		{"KB_6","6"},
		{"KB_7","7"},
		{"KB_8","8"},
		{"KB_9","9"},
		{"KB_MINUS","-"},	    /* - on main keyboard */
		{"KB_A","A"},
		{"KB_B","B"},
		{"KB_C","C"},
		{"KB_D","D"},
		{"KB_E","E"},
		{"KB_F","F"},
		{"KB_G","G"},
		{"KB_H","H"},
		{"KB_I","I"},
		{"KB_J","J"},
		{"KB_K","K"},
		{"KB_L","L"},
		{"KB_M","M"},
		{"KB_N","N"},
		{"KB_O","O"},
		{"KB_P","P"},
		{"KB_Q","Q"},
		{"KB_R","R"},
		{"KB_S","S"},
		{"KB_T","T"},
		{"KB_U","U"},
		{"KB_V","V"},
		{"KB_W","W"},
		{"KB_X","X"},
		{"KB_Y","Y"},
		{"KB_Z","Z"},
		{"KB_EQUALS","="},
		{"KB_BACKSPACE",gDLL->getText("TXT_KEY_KEYBOARD_BACKSPACE")},
		{"KB_TAB","TAB"},
		{"KB_LBRACKET","["},
		{"KB_RBRACKET","]"},
		{"KB_RETURN",gDLL->getText("TXT_KEY_KEYBOARD_ENTER")},		/* Enter on main keyboard */
		{"KB_LCONTROL",gDLL->getText("TXT_KEY_KEYBOARD_LEFT_CONTROL_KEY")},
		{"KB_SEMICOLON",";"},
		{"KB_APOSTROPHE","'"},
		{"KB_GRAVE","`"},		/* accent grave */
		{"KB_LSHIFT",gDLL->getText("TXT_KEY_KEYBOARD_LEFT_SHIFT_KEY")},
		{"KB_BACKSLASH","\\"},
		{"KB_COMMA",","},
		{"KB_PERIOD","."},
		{"KB_SLASH","/"},
		{"KB_RSHIFT",gDLL->getText("TXT_KEY_KEYBOARD_RIGHT_SHIFT_KEY")},
		{"KB_NUMPADSTAR",gDLL->getText("TXT_KEY_KEYBOARD_NUM_PAD_STAR")},
		{"KB_LALT",gDLL->getText("TXT_KEY_KEYBOARD_LEFT_ALT_KEY")},
		{"KB_SPACE",gDLL->getText("TXT_KEY_KEYBOARD_SPACE_KEY")},
		{"KB_CAPSLOCK",gDLL->getText("TXT_KEY_KEYBOARD_CAPS_LOCK")},
		{"KB_F1","F1"},
		{"KB_F2","F2"},
		{"KB_F3","F3"},
		{"KB_F4","F4"},
		{"KB_F5","F5"},
		{"KB_F6","F6"},
		{"KB_F7","F7"},
		{"KB_F8","F8"},
		{"KB_F9","F9"},
		{"KB_F10","F10"},
		{"KB_NUMLOCK",gDLL->getText("TXT_KEY_KEYBOARD_NUM_LOCK")},
		{"KB_SCROLL",gDLL->getText("TXT_KEY_KEYBOARD_SCROLL_KEY")},
		{"KB_NUMPAD7",gDLL->getText("TXT_KEY_KEYBOARD_NUMPAD_NUMBER", 7)},
		{"KB_NUMPAD8",gDLL->getText("TXT_KEY_KEYBOARD_NUMPAD_NUMBER", 8)},
		{"KB_NUMPAD9",gDLL->getText("TXT_KEY_KEYBOARD_NUMPAD_NUMBER", 9)},
		{"KB_NUMPADMINUS",gDLL->getText("TXT_KEY_KEYBOARD_NUMPAD_MINUS")},
		{"KB_NUMPAD4",gDLL->getText("TXT_KEY_KEYBOARD_NUMPAD_NUMBER", 4)},
		{"KB_NUMPAD5",gDLL->getText("TXT_KEY_KEYBOARD_NUMPAD_NUMBER", 5)},
		{"KB_NUMPAD6",gDLL->getText("TXT_KEY_KEYBOARD_NUMPAD_NUMBER", 6)},
		{"KB_NUMPADPLUS",gDLL->getText("TXT_KEY_KEYBOARD_NUMPAD_PLUS")},
		{"KB_NUMPAD1",gDLL->getText("TXT_KEY_KEYBOARD_NUMPAD_NUMBER", 1)},
		{"KB_NUMPAD2",gDLL->getText("TXT_KEY_KEYBOARD_NUMPAD_NUMBER", 2)},
		{"KB_NUMPAD3",gDLL->getText("TXT_KEY_KEYBOARD_NUMPAD_NUMBER", 3)},
		{"KB_NUMPAD0",gDLL->getText("TXT_KEY_KEYBOARD_NUMPAD_NUMBER", 0)},
		{"KB_NUMPADPERIOD",gDLL->getText("TXT_KEY_KEYBOARD_NUMPAD_PERIOD")},
		{"KB_F11","F11"},
		{"KB_F12","F12"},
		{"KB_NUMPADEQUALS",gDLL->getText("TXT_KEY_KEYBOARD_NUMPAD_EQUALS")},
		{"KB_AT","@"},
		{"KB_UNDERLINE","_"},
		{"KB_COLON",":"},
		{"KB_NUMPADENTER",gDLL->getText("TXT_KEY_KEYBOARD_NUMPAD_ENTER_KEY")},
		{"KB_RCONTROL",gDLL->getText("TXT_KEY_KEYBOARD_RIGHT_CONTROL_KEY")},
		{"KB_VOLUMEDOWN",gDLL->getText("TXT_KEY_KEYBOARD_VOLUME_DOWN")},
		{"KB_VOLUMEUP",gDLL->getText("TXT_KEY_KEYBOARD_VOLUME_UP")},
		{"KB_NUMPADCOMMA",gDLL->getText("TXT_KEY_KEYBOARD_NUMPAD_COMMA")},
		{"KB_NUMPADSLASH",gDLL->getText("TXT_KEY_KEYBOARD_NUMPAD_SLASH")},
		{"KB_SYSRQ",gDLL->getText("TXT_KEY_KEYBOARD_SYSRQ")},
		{"KB_RALT",gDLL->getText("TXT_KEY_KEYBOARD_RIGHT_ALT_KEY")},
		{"KB_PAUSE",gDLL->getText("TXT_KEY_KEYBOARD_PAUSE_KEY")},
		{"KB_HOME",gDLL->getText("TXT_KEY_KEYBOARD_HOME_KEY")},
		{"KB_UP",gDLL->getText("TXT_KEY_KEYBOARD_UP_ARROW")},
		{"KB_PGUP",gDLL->getText("TXT_KEY_KEYBOARD_PAGE_UP")},
		{"KB_LEFT",gDLL->getText("TXT_KEY_KEYBOARD_LEFT_ARROW")},
		{"KB_RIGHT",gDLL->getText("TXT_KEY_KEYBOARD_RIGHT_ARROW")},
		{"KB_END",gDLL->getText("TXT_KEY_KEYBOARD_END_KEY")},
		{"KB_DOWN",gDLL->getText("TXT_KEY_KEYBOARD_DOWN_ARROW")},
		{"KB_PGDN",gDLL->getText("TXT_KEY_KEYBOARD_PAGE_DOWN")},
		{"KB_INSERT",gDLL->getText("TXT_KEY_KEYBOARD_INSERT_KEY")},
		{"KB_DELETE",gDLL->getText("TXT_KEY_KEYBOARD_DELETE_KEY")},
	};

	for (i=0;i<iNumKeyBoardMappings;i++)
	{
		if (strcmp(asCvKeyBoardMapping[i].szDefineString, pszHotKey) == 0)
		{
			return asCvKeyBoardMapping[i].szKeyString;
		}
	}

	return "";
}

//
// call the progress updater fxn if it exists
//
void CvXMLLoadUtility::UpdateProgressCB(const char* szMessage)
{
	OutputDebugString("Updating ProgressCB: Start");
	if (m_iCurProgressStep>GetNumProgressSteps())
	{
		m_iCurProgressStep=1;	// wrap
	}

	if (m_pCBFxn)
	{
		m_pCBFxn(++m_iCurProgressStep, GetNumProgressSteps(), CvString::format("Reading XML %s",
			szMessage ? szMessage : "").c_str());
	}
	OutputDebugString("Updating ProgressCB: End");
}

//
// use for fast lookup of children by name
//
//void CvXMLLoadUtility::MapChildren()
//{
//GETXML->MapChildren(m_pFXml);
//}


bool CvXMLLoadUtility::TryMoveToXmlFirstMatchingElement(const XMLCh* xpath)
{
	char szLog[2000];
	try
	{
		xercesc::DOMXPathResult *result = 
			m_pParser->getDocument()->evaluate( xpath, 
												m_pCurrentXmlElement, 
												NULL, 
												xercesc::DOMXPathResult::FIRST_ORDERED_NODE_TYPE,
												NULL);
		xercesc::DOMNode* node = result->getNodeValue();
		if (node)
		{
			if (node->getNodeType() == xercesc::DOMNode::ELEMENT_NODE)
			{
				m_pCurrentXmlElement = reinterpret_cast<xercesc::DOMElement*>(node);
				result->release();
				return true;
			}
			/*else
			{
				char* fileName = xercesc::XMLString::transcode(
									m_pParser->getDocument()->getDocumentURI() );
				char* nodeStr  = xercesc::XMLString::transcode(
									node->getTextContent());
				char* xpathStr = xercesc::XMLString::transcode(
									xpath);
				sprintf(szLog, "XML model (DOM) error: %s : "
							   "Expected an XML element at '%s', found '%s'",
						fileName, xpathStr, nodeStr);
				xercesc::XMLString::release(&xpathStr);
				xercesc::XMLString::release(&nodeStr);
				xercesc::XMLString::release(&fileName);
			}*/
		}
		/*else
		{
			char* fileName = xercesc::XMLString::transcode(
								m_pParser->getDocument()->getDocumentURI() );
			char* xpathStr = xercesc::XMLString::transcode(
								xpath);
			sprintf(szLog, "XML model (DOM) error: %s : Expected an element at '%s', found none", 
				    fileName, xpathStr);
			xercesc::XMLString::release(&xpathStr);
			xercesc::XMLString::release(&fileName);
		}*/

		result->release();
		return false;
	}
	catch (const xercesc::DOMXPathException& toCatch)
	{
		char* fileName = xercesc::XMLString::transcode(
							m_pParser->getDocument()->getDocumentURI() );
		char* xpathStr = xercesc::XMLString::transcode(
							xpath);
		sprintf(szLog, "XML path error: %s : When quering '%s' - %s", 
			           fileName, xpathStr, toCatch.msg);
		xercesc::XMLString::release(&xpathStr);
		xercesc::XMLString::release(&fileName);
		if (toCatch.code == xercesc::DOMXPathException::INVALID_EXPRESSION_ERR)
		{
			FAssert(szLog);
			return false;
		}
	}
	catch (const xercesc::DOMException& toCatch)
	{
		char* fileName = xercesc::XMLString::transcode(
							m_pParser->getDocument()->getDocumentURI() );
		char* xpathStr = xercesc::XMLString::transcode(
							xpath);
		sprintf(szLog, "XML model (DOM) error: %s : When quering '%s' - %s", 
					   fileName, xpathStr, toCatch.msg);
		xercesc::XMLString::release(&xpathStr);
		xercesc::XMLString::release(&fileName);
	}

	logMsg(szLog);
	gDLL->MessageBox(szLog, "Error");
	return false;
}