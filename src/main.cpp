#include <wx/wx.h>

#include "components/pack/pack_panel.h"

namespace MyTools
{
  class Frame : public wxFrame
  {
    enum wxOwnedID
    {
      ID_Hello = 2,
      ID_OpenFile = 3,
    };

  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "我的 - 工具")
    {
      SetSize(1024, 800);

      auto menuFile = new wxMenu();
      menuFile->Append(wxID_OPEN, _("&打开...\tCtrl-H"), "Help string shown in status bar for this menu item");
      menuFile->AppendSeparator();

      menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
      menuFile->AppendSeparator();
      menuFile->Append(wxID_EXIT);

      auto menuHelp = new wxMenu();
      menuHelp->Append(wxID_ABOUT);

      auto menuBar = new wxMenuBar();
      menuBar->Append(menuFile, "&File");
      menuBar->Append(menuHelp, "&Help");
      SetMenuBar(menuBar);

      CreateStatusBar();
      SetStatusText("Welcome to wxWidgets!");

      // auto panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);

      // auto button = new wxButton(panel, wxID_ANY, "点击我", wxPoint(10, 10), wxDefaultSize);
      // button->Bind(wxEVT_BUTTON, [](wxCommandEvent &event) {
      //   wxLogMessage("按钮被点击了！");
      // });

      // panel->AddChild(button);

      wxBoxSizer *marginBoxSizer;
      marginBoxSizer = new wxBoxSizer(wxVERTICAL);
      marginBoxSizer->Add(new PackPanel(this), 1, wxEXPAND | wxALL, 20);
      SetSizer(marginBoxSizer);
      Layout();
      


      menuBar->Bind(wxEVT_MENU, [&](wxCommandEvent &event)
      {
        if (event.GetId() == ID_Hello) wxLogMessage("Hello world from wxWidgets!");
        else if (event.GetId() == wxID_ABOUT) wxMessageBox("This is a wxWidgets Hello World example", "About Hello World", wxOK|wxICON_INFORMATION);
        else if (event.GetId() == wxID_EXIT) Close(true);
        else if (event.GetId() == wxID_OPEN){

          wxFileDialog fileDialog(nullptr, "Choose a file", "", "", "All files (*.*)|*.*", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
          if (fileDialog.ShowModal() == wxID_CANCEL) {
              return;
          }
          wxString filePath = fileDialog.GetPath();
          wxLogMessage("Selected file: %s", filePath);

          // wxMessageDialog dialog(nullptr, "文件已成功打开", "文件打开", wxOK | wxICON_INFORMATION);
          // dialog.ShowModal();
          // 打开新窗口

          auto newFrame = new wxFrame(this, wxID_ANY, "新窗口", wxDefaultPosition, wxSize(400, 300));
          newFrame->Show();

        }
        else event.Skip(); 
      });
    }
  };

  class Application : public wxApp
  {
    bool OnInit() override
    {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(MyTools::Application);