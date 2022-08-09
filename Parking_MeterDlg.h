
// Parking_MeterDlg.h : header file
//

#pragma once
#include "Driver.h"
#include "CityResidentDriver.h"
#include "ForeignDriver.h"
#include "OldResident.h"
#include "Student.h"


// CParkingMeterDlg dialog
class CParkingMeterDlg : public CDialogEx
{
// Construction
public:
	CParkingMeterDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PARKING_METER_DIALOG };
#endif
	CPoint p1, p2;
	bool isPressed = false;
	int purse = 0;
	UINT timeVal;
	int countTime = 0;
	int t = 0; //For timer
	int currDriver = 0; // 1 = resident, 2 = foreign
	int status = 1; // 1 = resident, 2 = foreign
	CTypedPtrArray< CObArray, CityResidentDriver*> resident; //Array of CityResidentDriver
	CTypedPtrArray< CObArray, ForeignDriver*> foreign; //Array of ForeignDriver

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CButton InsertRes;
	CButton InsertFor;
	CEdit delRes;
	CEdit delFor;
	int ID_resident;
	CEdit resID;
	double Money;
	CEdit resMoney;
	int Special_number;
	CEdit resSpecialId;
	CString foreignName;
	CEdit forName;
	CString foreignAddress;
	CEdit forAddress;
	int foreignID;
	CEdit forID;
	double foreignMoney;
	CEdit forMoney;
	CButton cost;
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton5();
	CString TimerStr;
	CEdit parkingTimer;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton11();
	double resAge;
	CEdit resAgeCon;
	afx_msg void OnBnClickedRadio3();
	double getMoney;
	afx_msg void OnBnClickedButton12();
	CEdit getMoneyCon;
	afx_msg void OnBnClickedRadio4();
	CString studentCode;
	CEdit studentCodeCon;
};
