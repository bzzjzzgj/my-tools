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
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/dataview.h>
#include <wx/statbmp.h>
#include <wx/menu.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class PackPanelUI
///////////////////////////////////////////////////////////////////////////////
class PackPanelUI : public wxPanel
{
	private:

	protected:
		wxStaticText* m_codeStaticText;
		wxTextCtrl* m_codeTextCtrl;
		wxStaticText* m_nameStaticText;
		wxTextCtrl* m_nameTextCtrl;
		wxStaticText* m_iconStaticText;
		wxTextCtrl* m_iconTextCtrl;
		wxStaticText* m_descStaticText;
		wxTextCtrl* m_descTextCtrl;
		wxButton* m_saveButton;
		wxTextCtrl* m_contentTextCtrl;

	public:

		PackPanelUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 850,539 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

		~PackPanelUI();

};

///////////////////////////////////////////////////////////////////////////////
/// Class PackListPanelUI
///////////////////////////////////////////////////////////////////////////////
class PackListPanelUI : public wxPanel
{
	private:

	protected:
		wxButton* m_AddButton;
		wxButton* m_DelButton;
		wxDataViewListCtrl* m_dataViewListCtrl;

	public:

		PackListPanelUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

		~PackListPanelUI();

};

///////////////////////////////////////////////////////////////////////////////
/// Class PackIconPanelUI
///////////////////////////////////////////////////////////////////////////////
class PackIconPanelUI : public wxPanel
{
	private:

	protected:
		wxStaticBitmap* m_bitmap1;
		wxStaticBitmap* m_bitmap2;
		wxStaticBitmap* m_bitmap3;
		wxStaticBitmap* m_bitmap4;
		wxStaticBitmap* m_bitmap5;
		wxStaticBitmap* m_bitmap6;
		wxStaticBitmap* m_bitmap7;
		wxStaticBitmap* m_bitmap8;

	public:

		PackIconPanelUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

		~PackIconPanelUI();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameUI
///////////////////////////////////////////////////////////////////////////////
class MainFrameUI : public wxFrame
{
	private:

	protected:
		wxMenuBar* m_menubar;
		wxMenu* m_fileMenu;
		wxMenu* m_openMenu;
		wxMenu* m_aboutMenu;

	public:

		MainFrameUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("My Tools"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrameUI();

};

