///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/treectrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class PackPanel
///////////////////////////////////////////////////////////////////////////////

namespace MyTools
{

	class PackPanel : public wxPanel
	{
	private:
	protected:
		wxTreeCtrl *m_packListTreeCtrl;
		wxTextCtrl *m_contentTextCtrl;
		wxStaticText *m_codeStaticText;
		wxTextCtrl *m_codeTextCtrl;
		wxStaticText *m_nameStaticText;
		wxTextCtrl *m_nameTextCtrl;
		wxStaticText *m_iconStaticText;
		wxTextCtrl *m_iconTextCtrl;
		wxStaticText *m_descStaticText;
		wxTextCtrl *m_descTextCtrl;
		wxButton *m_saveButton;

	public:
		PackPanel(wxWindow *parent, wxWindowID id = wxID_ANY, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxSize(500, 300), long style = wxTAB_TRAVERSAL, const wxString &name = wxEmptyString);

		~PackPanel();
	};

}