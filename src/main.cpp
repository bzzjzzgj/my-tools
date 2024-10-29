#include <wx/wx.h>

#include "frames/main_frame.h"

namespace MyTools
{
  class Application : public wxApp
  {
    bool OnInit() override
    {
      wxLocale locale;
      locale.Init(wxLANGUAGE_CHINESE_SIMPLIFIED); // 设置为简体中文

      // 加载翻译文件
      locale.AddCatalogLookupPathPrefix("./locale"); // 设置翻译文件的路径
      locale.AddCatalog("message");                  // 加载名为 "myapp" 的翻译文件

      (new MainFrame(nullptr))->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(MyTools::Application);