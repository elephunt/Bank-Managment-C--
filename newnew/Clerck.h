#pragma once

# include "resource.h"
# include "SearchAccount.h"
# include "tellertransactions.h"


// NEW dialog

class NEW : public CDialogEx
{
	DECLARE_DYNAMIC(NEW)

public:
	NEW(CWnd* pParent = NULL);   // standard constructor
	virtual ~NEW();

// Dialog Data
	enum { IDD = IDD_NEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButAddacount();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
