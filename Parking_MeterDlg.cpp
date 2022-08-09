
// Parking_MeterDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Parking_Meter.h"
#include "Parking_MeterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CParkingMeterDlg dialog



CParkingMeterDlg::CParkingMeterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PARKING_METER_DIALOG, pParent)
	, ID_resident(0)
	, Money(0)
	, Special_number(0)
	, foreignName(_T(""))
	, foreignAddress(_T(""))
	, foreignID(0)
	, foreignMoney(0)
	, TimerStr(_T("00:00:00"))
	, resAge(0)
	, getMoney(0)
	, studentCode(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CParkingMeterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, InsertRes);
	DDX_Control(pDX, IDC_BUTTON4, InsertFor);
	DDX_Control(pDX, IDC_EDIT1, delRes);
	DDX_Control(pDX, IDC_EDIT5, delFor);
	DDX_Text(pDX, IDC_EDIT2, ID_resident);
	DDX_Control(pDX, IDC_EDIT2, resID);
	DDX_Text(pDX, IDC_EDIT3, Money);
	DDX_Control(pDX, IDC_EDIT3, resMoney);
	DDX_Text(pDX, IDC_EDIT4, Special_number);
	DDX_Control(pDX, IDC_EDIT4, resSpecialId);
	DDX_Text(pDX, IDC_EDIT6, foreignName);
	DDX_Control(pDX, IDC_EDIT6, forName);
	DDX_Text(pDX, IDC_EDIT7, foreignAddress);
	DDX_Control(pDX, IDC_EDIT7, forAddress);
	DDX_Text(pDX, IDC_EDIT8, foreignID);
	DDX_Control(pDX, IDC_EDIT8, forID);
	DDX_Text(pDX, IDC_EDIT9, foreignMoney);
	DDX_Control(pDX, IDC_EDIT9, forMoney);
	DDX_Control(pDX, IDC_BUTTON9, cost);
	DDX_Text(pDX, IDC_EDIT10, TimerStr);
	DDX_Control(pDX, IDC_EDIT10, parkingTimer);
	DDX_Text(pDX, IDC_EDIT11, resAge);
	DDX_Control(pDX, IDC_EDIT11, resAgeCon);
	DDX_Text(pDX, IDC_EDIT12, getMoney);
	DDX_Control(pDX, IDC_EDIT12, getMoneyCon);
	DDX_Text(pDX, IDC_EDIT13, studentCode);
	DDX_Control(pDX, IDC_EDIT13, studentCodeCon);
}

BEGIN_MESSAGE_MAP(CParkingMeterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON9, &CParkingMeterDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_RADIO1, &CParkingMeterDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CParkingMeterDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON8, &CParkingMeterDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON10, &CParkingMeterDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON1, &CParkingMeterDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CParkingMeterDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &CParkingMeterDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CParkingMeterDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON6, &CParkingMeterDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CParkingMeterDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON5, &CParkingMeterDlg::OnBnClickedButton5)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON11, &CParkingMeterDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_RADIO3, &CParkingMeterDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_BUTTON12, &CParkingMeterDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_RADIO4, &CParkingMeterDlg::OnBnClickedRadio4)
END_MESSAGE_MAP()


// CParkingMeterDlg message handlers

BOOL CParkingMeterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CheckRadioButton(IDC_RADIO1, IDC_RADIO4, IDC_RADIO1); //checking radio buttons!!

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CParkingMeterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CParkingMeterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		CDialogEx::OnPaint();
		CPoint p3(0, 0);
		CPoint p4(260, 270);
		CBrush Brush2, * oldBrush;
		Brush2.CreateSolidBrush(RGB(0, 0, 204));
		oldBrush = dc.SelectObject(&Brush2);
		dc.Rectangle(p3.x, p3.y, p4.x, p4.y);
		dc.SelectObject(oldBrush);

		CRect rect;
		GetClientRect(&rect);
		CFont font;
		font.CreatePointFont(150, _T("David"));
		CFont* oldFont = dc.SelectObject(&font);
		dc.SetBkMode(TRANSPARENT);
		CString string = _T("Parking Meter");
		dc.SetTextColor(RGB(192, 192, 192));
		dc.DrawText(string, &rect, p3.x);


		CPoint p5(450, 0);
		CPoint p6(280, 150);
		CBrush Brush3, * oldBrush2;
		Brush3.CreateSolidBrush(RGB(0, 0, 0));
		oldBrush2 = dc.SelectObject(&Brush3);
		dc.Rectangle(p5.x, p5.y, p6.x, p6.y);
		dc.SelectObject(oldBrush2);

		CRect rect2;
		GetClientRect(&rect2);
		CFont font2;
		font2.CreatePointFont(150, _T("David"));
		CFont* oldFont2 = dc.SelectObject(&font2);
		dc.SetBkMode(TRANSPARENT);
		CString string2 = _T("ATM");
		dc.SetTextColor(RGB(255, 140, 0));
		rect2.left = -630;
		dc.DrawTextW(string2, &rect2, 1);

		if (purse)
		{
			CPen pen1, * oldPen;
			pen1.CreatePen(PS_SOLID, 4, RGB(128, 128, 128));
			oldPen = dc.SelectObject(&pen1);
			dc.Ellipse(p1.x, p1.y, p2.x, p2.y);
			dc.SelectObject(oldPen);

			CBrush Brush1, * oldBrush;
			Brush1.CreateSolidBrush(RGB(255, 255, 0));
			oldBrush = dc.SelectObject(&Brush1);
			dc.Ellipse(p1.x, p1.y, p2.x, p2.y);
			dc.SelectObject(oldBrush);
		}
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CParkingMeterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CParkingMeterDlg::OnBnClickedButton9()
{
	CString s;
	cost.GetWindowText(s);
	if (status == 1) cost.SetWindowTextW(_T("Resident - 10$"));
	else if (status == 2) cost.SetWindowTextW(_T("Foriegn - 20$"));
	else if (status == 3) cost.SetWindowTextW(_T("Old Resident - 8.4$"));
	else if (status == 4) cost.SetWindowTextW(_T("Student - 15$"));
}


void CParkingMeterDlg::OnBnClickedRadio1()
{
	status = 1;
}

void CParkingMeterDlg::OnBnClickedRadio2()
{
	status = 2;
}

void CParkingMeterDlg::OnBnClickedRadio3()
{
	status = 3;
}

void CParkingMeterDlg::OnBnClickedRadio4()
{
	status = 4;
}

void CParkingMeterDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (purse)
	{
		p1 = p2 = point;
		p2.x = p1.x + 40;
		p2.y = p1.y + 40;
		Invalidate();
	}
	CDialog::OnMouseMove(nFlags, point);
}

void CParkingMeterDlg::OnBnClickedButton8()
{
	purse = 1;
	timeVal = SetTimer(1, 200, 0);
}


void CParkingMeterDlg::OnBnClickedButton10()
{
	CString msg;
	double currMoney;

	if (purse && resident.IsEmpty() == 0 && currDriver == 1)
	{
		purse = 0;
		resident[resident.GetSize() - 1]->pay();
		currMoney = resident[resident.GetSize() - 1]->getMoney();
		msg.Format(_T("%lf"), currMoney);

		if (currMoney > 0 && resident[resident.GetSize() - 1]->mDiscount != 1)
		{
			MessageBox(L"Money: " + msg);
			countTime++;
		}
		else if (currMoney == 0)
		{
			MessageBox(L"Money: " + msg);
		}

		Invalidate();
	}
	else if (purse && foreign.IsEmpty() == 0 && currDriver == 2)
	{
		purse = 0;
		foreign[foreign.GetSize() - 1]->pay();
		currMoney = foreign[foreign.GetSize() - 1]->getMoney();
		msg.Format(_T("%lf"), currMoney);

		if (currMoney > 0)
		{
			MessageBox(L"Money: " + msg);
			countTime++;
		}
		else if (currMoney == 0)
		{
			MessageBox(L"Money: " + msg);
		}

		Invalidate();
	}
	else
	{
		purse = 0;
		Invalidate();
	}
}


void CParkingMeterDlg::OnBnClickedButton1()
{
	CString ID, money, specialID, age;
	int ID2, spicialId2;
	double money2, age2;
	resID.GetWindowTextW(ID);
	resMoney.GetWindowTextW(money);
	resSpecialId.GetWindowTextW(specialID);
	resAgeCon.GetWindowTextW(age);
	_stscanf_s(money, _T("%lf"), &money2);
	_stscanf_s(age, _T("%lf"), &age2);
	_stscanf_s(ID, _T("%d"), &ID2);
	_stscanf_s(specialID, _T("%d"), &spicialId2);

	if(age2 == 0)
		resident.Add(new CityResidentDriver(ID2, money2, spicialId2));
	else
		resident.Add(new OldResident(ID2, money2, spicialId2, age2));

	resID.SetWindowTextW(0);
	resMoney.SetWindowTextW(0);
	resAgeCon.SetWindowTextW(0);
	resSpecialId.SetWindowTextW(0);

	currDriver = 1;
}


void CParkingMeterDlg::OnBnClickedButton4()
{
	CString name, address, ID, money, student;
	int ID1;
	double money1;
	forName.GetWindowTextW(name);
	forAddress.GetWindowTextW(address);
	forID.GetWindowTextW(ID);
	forMoney.GetWindowTextW(money);
	studentCodeCon.GetWindowTextW(student);
	_stscanf_s(ID, _T("%d"), &ID1);
	_stscanf_s(money, _T("%lf"), &money1);
	
	if (student == _T("StudentIL"))
		foreign.Add(new Student(name, address, ID1, money1, student));
	else if (student != _T("StudentIL") && student != _T(""))
		AfxMessageBox(L"Sorry, your studet promo code is not valid...\nTry again or enter as a foreign");
	else
		foreign.Add(new ForeignDriver(name, address, ID1, money1));
	
	forName.SetWindowTextW(0);
	forAddress.SetWindowTextW(0);
	forID.SetWindowTextW(0);
	forMoney.SetWindowTextW(0);
	studentCodeCon.SetWindowTextW(0);

	currDriver = 2;
}

void CParkingMeterDlg::OnBnClickedButton2()
{
	CString del;
	int delID;
	delRes.GetWindowTextW(del);
	_stscanf_s(del, _T("%d"), &delID);
	for (int i = 0; i < resident.GetSize(); i++)
	{
		if (delID == resident[i]->getDriverId())
		{
			resident.RemoveAt(i);
			delRes.SetWindowTextW(0);
			if (foreign.GetSize() != 0)
				currDriver = 2;
			else
				currDriver = 1;
			MessageBox(NULL,L"The resident was deleted successfully!");
		}
		else
		{
			AfxMessageBox(L"The resident was not in the system!");
		}
	}
}

void CParkingMeterDlg::OnBnClickedButton3()
{
	CString del;
	int delID;
	delFor.GetWindowTextW(del);
	_stscanf_s(del, _T("%d"), &delID);
	for (int i = 0; i < foreign.GetSize(); i++)
	{
		if (delID == foreign[i]->getDriverId())
		{
			foreign.RemoveAt(i);
			delFor.SetWindowTextW(0);
			if (resident.GetSize() != 0)
				currDriver = 1;
			else
				currDriver = 2;
			MessageBox(NULL, L"The foreign was deleted successfully!");
		}
		else
		{
			AfxMessageBox(L"The foreign was not in the system!");
		}
	}
}


void CParkingMeterDlg::OnBnClickedButton6()
{
	CFileDialog dlg(FALSE, _T(".drivers"), NULL, 0, _T("dirvers (*.drivers)|*.dirvers|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName();
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		resident.Serialize(ar);
		foreign.Serialize(ar);
		ar.Close();
		file.Close();
	}
}


void CParkingMeterDlg::OnBnClickedButton7()
{
	CFileDialog dlg(TRUE, _T(".drivers"), NULL, 0, _T("dirvers (*.drivers)|*.dirvers|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName();
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		resident.Serialize(ar);
		foreign.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}

	if (resident.GetSize() != 0)
		currDriver = 1;
	else if (foreign.GetSize() != 0)
		currDriver = 2;
	else
		currDriver = 1; // Defualt
}


void CParkingMeterDlg::OnBnClickedButton5()
{
	int i, temp;
	CString res1 = _T("");
	CString res2 = _T("");
	for (i = 0; i < foreign.GetSize(); i++)
	{
		temp = foreign[i]->getDriverId();
		res1.Format(_T("%s %d\n"), res1, temp);
	}

	for (i = 0; i < resident.GetSize(); i++)
	{
		temp = resident[i]->getDriverId();
		res2.Format(_T("%s %d\n"), res2, temp);
	}

	MessageBox(res2 + res1);
}


void CParkingMeterDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default 
	CTime CurrentTime = CTime::GetCurrentTime();

	int iHours = CurrentTime.GetHour();
	int iMinutes = CurrentTime.GetMinute();
	int iSeconds = CurrentTime.GetSecond();
	CString strHours, strMinutes, strSeconds;

	if (t == 1)
	{
		iMinutes += 15 * countTime;
		if (iMinutes > 60)
		{
			iHours += (iMinutes / 60);
			iMinutes = iMinutes % 60;
		}
	}

	if (iHours < 10)
		strHours.Format(_T("0%d"), iHours);
	else
		strHours.Format(_T("%d"), iHours);

	if (iMinutes < 10)
		strMinutes.Format(_T("0%d"), iMinutes);
	else
		strMinutes.Format(_T("%d"), iMinutes);

	if (iSeconds < 10)
		strSeconds.Format(_T("0%d"), iSeconds);
	else
		strSeconds.Format(_T("%d"), iSeconds);

	TimerStr.Format(_T("%s:%s:%s"), strHours, strMinutes, strSeconds);

	UpdateData(FALSE);
	CDialogEx::OnTimer(nIDEvent);

	CDialogEx::OnTimer(nIDEvent);
}


void CParkingMeterDlg::OnBnClickedButton11()
{
	CString estimateTime;
	t = 1;
	OnTimer(timeVal);
	KillTimer(timeVal);
	estimateTime = TimerStr.GetString();
	MessageBox(L"Estimate time: " + estimateTime);
    t = 0;
	countTime = 0;
}

void CParkingMeterDlg::OnBnClickedButton12()
{
	CString newSum;
	double newSum2;
	if (currDriver == 1)
	{
		if (resident[resident.GetSize() - 1]->mResidentSpecialNumber != 0)
			resident[resident.GetSize() - 1]->mDiscount = 10;
		else
			resident[resident.GetSize() - 1]->mDiscount = 20;

		getMoneyCon.GetWindowTextW(newSum);
		_stscanf_s(newSum, _T("%lf"), &newSum2);
		newSum2 += resident[resident.GetSize() - 1]->getMoney();
		resident[resident.GetSize() - 1]->setMoney(newSum2);
		newSum2 = resident[resident.GetSize() - 1]->getMoney();
		MessageBox(L"The money updated");
	}
	else
	{
		resident[foreign.GetSize() - 1]->mDiscount = 20;
		getMoneyCon.GetWindowTextW(newSum);
		_stscanf_s(newSum, _T("%lf"), &newSum2);
		newSum2 += foreign[foreign.GetSize() - 1]->getMoney();
		foreign[foreign.GetSize() - 1]->setMoney(newSum2);
		newSum2 = foreign[foreign.GetSize() - 1]->getMoney();
		MessageBox(L"The money updated");
	}
}

