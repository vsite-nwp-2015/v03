#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class MyDialog : public Dialog 
{
public:
	POINT p;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		
		
		SetInt(IDC_EDIT1,p.x);
		SetInt( IDC_EDIT2,p.y);
		return true;
	}
	bool OnOK()
	{
		try {
			p.x =GetInt( IDC_EDIT1);
			p.y = GetInt(IDC_EDIT2);
		}
		catch (XCtrl&) {
			MessageBox(*this, "Upisite samo  brojeve", 0, MB_OK);
			
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
	POINT CurPos;

	 GetCursorPos(&CurPos);
	   dlg.p.x = CurPos.x;
	   dlg.p.y = CurPos.y;

	


	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		
		SetCursorPos(dlg.p.x, dlg.p.y);
	}
	return 0;
}
