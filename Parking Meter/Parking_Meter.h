
// Parking_Meter.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CParkingMeterApp:
// See Parking_Meter.cpp for the implementation of this class
//

class CParkingMeterApp : public CWinApp
{
public:
	CParkingMeterApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CParkingMeterApp theApp;
