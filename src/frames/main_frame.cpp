#include "main_frame.h"
#include "../components/pack/pack_list_panel.h"
#include <wx/dialog.h>

MainFrame::MainFrame(wxWindow *parent)
    : MainFrameUI(parent)
{
    PackListPanel *packListPanel = new PackListPanel(this);
    packListPanel->Show();


  
}
