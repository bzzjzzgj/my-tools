///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "pack_panel.h"

///////////////////////////////////////////////////////////////////////////

namespace MyTools
{

	PackPanel::PackPanel(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style, const wxString &name) : wxPanel(parent, id, pos, size, style, name)
	{
		wxFlexGridSizer *mainSizer;
		mainSizer = new wxFlexGridSizer(1, 3, 0, 20);
		mainSizer->AddGrowableCol(0, 20);
		mainSizer->AddGrowableCol(1, 60);
		mainSizer->AddGrowableCol(2, 20);
		mainSizer->AddGrowableRow(0, 100);
		mainSizer->SetFlexibleDirection(wxBOTH);
		mainSizer->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

		wxStaticBoxSizer *packListSbSizer;
		packListSbSizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("自定义礼包列表")), wxVERTICAL);

		m_packListTreeCtrl = new wxTreeCtrl(packListSbSizer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE);
		packListSbSizer->Add(m_packListTreeCtrl, 1, wxALL | wxEXPAND, 5);

		mainSizer->Add(packListSbSizer, 1, wxEXPAND, 5);

		wxStaticBoxSizer *contentSbSizer;
		contentSbSizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("礼包内容")), wxVERTICAL);

		m_contentTextCtrl = new wxTextCtrl(contentSbSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
		contentSbSizer->Add(m_contentTextCtrl, 1, wxALL | wxEXPAND, 5);

		mainSizer->Add(contentSbSizer, 1, wxEXPAND, 5);

		wxBoxSizer *basicBoxSizer;
		basicBoxSizer = new wxBoxSizer(wxVERTICAL);

		wxStaticBoxSizer *basicSbSizer;
		basicSbSizer = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, _("基础信息")), wxVERTICAL);

		wxBoxSizer *codeBoxSizer;
		codeBoxSizer = new wxBoxSizer(wxHORIZONTAL);

		m_codeStaticText = new wxStaticText(basicSbSizer->GetStaticBox(), wxID_ANY, _("编码"), wxDefaultPosition, wxDefaultSize, 0);
		m_codeStaticText->Wrap(-1);
		codeBoxSizer->Add(m_codeStaticText, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

		m_codeTextCtrl = new wxTextCtrl(basicSbSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
		codeBoxSizer->Add(m_codeTextCtrl, 1, wxALL | wxEXPAND, 5);

		basicSbSizer->Add(codeBoxSizer, 0, wxEXPAND, 5);

		wxBoxSizer *nameBoxSizer;
		nameBoxSizer = new wxBoxSizer(wxHORIZONTAL);

		m_nameStaticText = new wxStaticText(basicSbSizer->GetStaticBox(), wxID_ANY, _("名称"), wxDefaultPosition, wxDefaultSize, 0);
		m_nameStaticText->Wrap(-1);
		nameBoxSizer->Add(m_nameStaticText, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

		m_nameTextCtrl = new wxTextCtrl(basicSbSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
		nameBoxSizer->Add(m_nameTextCtrl, 1, wxALL | wxEXPAND, 5);

		basicSbSizer->Add(nameBoxSizer, 0, wxEXPAND, 5);

		wxBoxSizer *iconBoxSizer;
		iconBoxSizer = new wxBoxSizer(wxHORIZONTAL);

		m_iconStaticText = new wxStaticText(basicSbSizer->GetStaticBox(), wxID_ANY, _("图标"), wxDefaultPosition, wxDefaultSize, 0);
		m_iconStaticText->Wrap(-1);
		iconBoxSizer->Add(m_iconStaticText, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

		m_iconTextCtrl = new wxTextCtrl(basicSbSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
		iconBoxSizer->Add(m_iconTextCtrl, 0, wxALL | wxEXPAND, 5);

		basicSbSizer->Add(iconBoxSizer, 0, wxEXPAND, 5);

		wxBoxSizer *descBoxSizer;
		descBoxSizer = new wxBoxSizer(wxHORIZONTAL);

		m_descStaticText = new wxStaticText(basicSbSizer->GetStaticBox(), wxID_ANY, _("描述"), wxDefaultPosition, wxDefaultSize, 0);
		m_descStaticText->Wrap(-1);
		descBoxSizer->Add(m_descStaticText, 0, wxALL, 5);

		m_descTextCtrl = new wxTextCtrl(basicSbSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(-1, 150), wxTE_MULTILINE);
		descBoxSizer->Add(m_descTextCtrl, 1, wxALL | wxEXPAND, 5);

		basicSbSizer->Add(descBoxSizer, 0, wxEXPAND, 5);

		m_saveButton = new wxButton(basicSbSizer->GetStaticBox(), wxID_ANY, _("生成/保存"), wxDefaultPosition, wxDefaultSize, 0);
		basicSbSizer->Add(m_saveButton, 0, wxALL | wxALIGN_RIGHT, 5);

		basicBoxSizer->Add(basicSbSizer, 1, wxEXPAND, 5);

		mainSizer->Add(basicBoxSizer, 1, wxEXPAND, 5);

		this->SetSizer(mainSizer);
		this->Layout();
	}

	PackPanel::~PackPanel()
	{
	}

}