///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "ui.h"

///////////////////////////////////////////////////////////////////////////

PackPanelUI::PackPanelUI( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxFlexGridSizer* mainSizer;
	mainSizer = new wxFlexGridSizer( 1, 3, 0, 20 );
	mainSizer->AddGrowableCol( 0, 10 );
	mainSizer->AddGrowableCol( 1, 40 );
	mainSizer->AddGrowableRow( 0, 100 );
	mainSizer->SetFlexibleDirection( wxBOTH );
	mainSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxStaticBoxSizer* basicSbSizer;
	basicSbSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Basic Info") ), wxVERTICAL );

	wxBoxSizer* codeBoxSizer;
	codeBoxSizer = new wxBoxSizer( wxHORIZONTAL );

	m_codeStaticText = new wxStaticText( basicSbSizer->GetStaticBox(), wxID_ANY, _("Code"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_codeStaticText->Wrap( -1 );
	codeBoxSizer->Add( m_codeStaticText, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_codeTextCtrl = new wxTextCtrl( basicSbSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	codeBoxSizer->Add( m_codeTextCtrl, 1, wxALL|wxEXPAND, 5 );


	basicSbSizer->Add( codeBoxSizer, 0, wxEXPAND, 5 );

	wxBoxSizer* nameBoxSizer;
	nameBoxSizer = new wxBoxSizer( wxHORIZONTAL );

	m_nameStaticText = new wxStaticText( basicSbSizer->GetStaticBox(), wxID_ANY, _("Name"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_nameStaticText->Wrap( -1 );
	nameBoxSizer->Add( m_nameStaticText, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_nameTextCtrl = new wxTextCtrl( basicSbSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	nameBoxSizer->Add( m_nameTextCtrl, 1, wxALL|wxEXPAND, 5 );


	basicSbSizer->Add( nameBoxSizer, 0, wxEXPAND, 5 );

	wxBoxSizer* iconBoxSizer;
	iconBoxSizer = new wxBoxSizer( wxHORIZONTAL );

	m_iconStaticText = new wxStaticText( basicSbSizer->GetStaticBox(), wxID_ANY, _("Icon"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_iconStaticText->Wrap( -1 );
	iconBoxSizer->Add( m_iconStaticText, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_iconTextCtrl = new wxTextCtrl( basicSbSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	iconBoxSizer->Add( m_iconTextCtrl, 0, wxALL|wxEXPAND, 5 );


	basicSbSizer->Add( iconBoxSizer, 0, wxEXPAND, 5 );

	wxBoxSizer* descBoxSizer;
	descBoxSizer = new wxBoxSizer( wxHORIZONTAL );

	m_descStaticText = new wxStaticText( basicSbSizer->GetStaticBox(), wxID_ANY, _("Desc"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
	m_descStaticText->Wrap( -1 );
	descBoxSizer->Add( m_descStaticText, 0, wxALL, 5 );

	m_descTextCtrl = new wxTextCtrl( basicSbSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,150 ), wxTE_MULTILINE );
	descBoxSizer->Add( m_descTextCtrl, 1, wxALL|wxEXPAND, 5 );


	basicSbSizer->Add( descBoxSizer, 0, wxEXPAND, 5 );

	m_saveButton = new wxButton( basicSbSizer->GetStaticBox(), wxID_ANY, _("Save"), wxDefaultPosition, wxSize( 100,40 ), 0 );
	basicSbSizer->Add( m_saveButton, 0, wxALL|wxALIGN_RIGHT, 5 );


	mainSizer->Add( basicSbSizer, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* contentSbSizer;
	contentSbSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Pack Content") ), wxVERTICAL );

	m_contentTextCtrl = new wxTextCtrl( contentSbSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	contentSbSizer->Add( m_contentTextCtrl, 1, wxALL|wxEXPAND, 5 );


	mainSizer->Add( contentSbSizer, 1, wxEXPAND, 5 );


	this->SetSizer( mainSizer );
	this->Layout();
}

PackPanelUI::~PackPanelUI()
{
}

PackListPanelUI::PackListPanelUI( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* mainBoxSizer;
	mainBoxSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* toolbarBoxSizer;
	toolbarBoxSizer = new wxBoxSizer( wxHORIZONTAL );

	m_AddButton = new wxButton( this, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	toolbarBoxSizer->Add( m_AddButton, 0, wxALL, 5 );

	m_DelButton = new wxButton( this, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	toolbarBoxSizer->Add( m_DelButton, 0, wxALL, 5 );


	mainBoxSizer->Add( toolbarBoxSizer, 0, wxEXPAND, 5 );

	m_dataViewListCtrl = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_ROW_LINES );
	mainBoxSizer->Add( m_dataViewListCtrl, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( mainBoxSizer );
	this->Layout();
}

PackListPanelUI::~PackListPanelUI()
{
}

PackIconPanelUI::PackIconPanelUI( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxGridSizer* mainGridSizer;
	mainGridSizer = new wxGridSizer( 5, 10, 0, 0 );

	m_bitmap1 = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	mainGridSizer->Add( m_bitmap1, 0, wxALL, 5 );

	m_bitmap2 = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	mainGridSizer->Add( m_bitmap2, 0, wxALL, 5 );

	m_bitmap3 = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	mainGridSizer->Add( m_bitmap3, 0, wxALL, 5 );

	m_bitmap4 = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	mainGridSizer->Add( m_bitmap4, 0, wxALL, 5 );

	m_bitmap5 = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	mainGridSizer->Add( m_bitmap5, 0, wxALL, 5 );

	m_bitmap6 = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	mainGridSizer->Add( m_bitmap6, 0, wxALL, 5 );

	m_bitmap7 = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	mainGridSizer->Add( m_bitmap7, 0, wxALL, 5 );

	m_bitmap8 = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	mainGridSizer->Add( m_bitmap8, 0, wxALL, 5 );


	this->SetSizer( mainGridSizer );
	this->Layout();
}

PackIconPanelUI::~PackIconPanelUI()
{
}

MainFrameUI::MainFrameUI( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_menubar = new wxMenuBar( 0 );
	m_fileMenu = new wxMenu();
	m_openMenu = new wxMenu();
	wxMenuItem* m_openMenuItem = new wxMenuItem( m_fileMenu, wxID_ANY, _("Open"), wxEmptyString, wxITEM_NORMAL, m_openMenu );
	#if (defined( __WXMSW__ ) || defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_openMenuItem->SetBitmap( wxNullBitmap );
	#endif

	m_fileMenu->Append( m_openMenuItem );

	wxMenuItem* m_menuItem1;
	m_menuItem1 = new wxMenuItem( m_fileMenu, wxID_ANY, wxString( _("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_fileMenu->Append( m_menuItem1 );

	m_menubar->Append( m_fileMenu, _("File") );

	m_aboutMenu = new wxMenu();
	m_menubar->Append( m_aboutMenu, _("About") );

	this->SetMenuBar( m_menubar );


	this->Centre( wxBOTH );
}

MainFrameUI::~MainFrameUI()
{
}
