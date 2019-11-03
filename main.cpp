#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public:
	POINT cursorPos;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, cursorPos.x);
		SetInt(IDC_EDIT2, cursorPos.y);
		return true;
	}
	bool OnOK()
	{
		try {
			cursorPos.x = GetInt(IDC_EDIT1);
			cursorPos.y = GetInt(IDC_EDIT2);
		}
		catch (XCtrl&) {
			return false;
		}
		return true;
	}
	void OnCancel()	{ }
	bool OnCommand(int id, int code) { return false; }
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	GetCursorPos(&dlg.cursorPos);
	if (dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.cursorPos.x, dlg.cursorPos.y);
	}
	return 0;
}
