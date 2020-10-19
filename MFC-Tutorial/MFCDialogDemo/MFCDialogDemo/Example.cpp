#include <afxwin.h>
#include "resource.h"

class CExample : public CWinApp {
public:
    BOOL InitInstance();
};

// Create dialog box by deriving from CDialog, implement default constructor/destructor

class CExampleDlg : public CDialog {
public:
    enum { IDD = IDD_EXAMPLE_DLG };

    CExampleDlg();
    ~CExampleDlg();
};

CExampleDlg::CExampleDlg() :CDialog(CExampleDlg::IDD) {

}

CExampleDlg::~CExampleDlg() {

}

/* 1. Instantiate dialog box
*  2. Set box to modal
*/

BOOL CExample::InitInstance() {
    CExampleDlg myDlg;
    m_pMainWnd = &myDlg;
    myDlg.DoModal();
    return TRUE;
}
CExample MyApp;