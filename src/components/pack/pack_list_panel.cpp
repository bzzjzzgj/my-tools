#include "pack_list_panel.h"

PackListPanel::PackListPanel(wxWindow *parent)
    : PackListPanelUI(parent)
{

    m_pModel = new PackListViewModel();
    m_dataViewListCtrl->AssociateModel(m_pModel.get());

    // auto codeTextRenderer = new wxDataViewTextRenderer("string", wxDATAVIEW_CELL_INERT);
    // auto nameTextRenderer = new wxDataViewTextRenderer("string", wxDATAVIEW_CELL_INERT);
    // auto pathTextRenderer = new wxDataViewTextRenderer("string", wxDATAVIEW_CELL_INERT);
    // auto idColumnRenderer = new wxDataViewTextRenderer("long", wxDATAVIEW_CELL_INERT);

    // auto columnCode = new wxDataViewColumn(wxT("Column 1"),
    //                                     codeTextRenderer,
    //                                     PackListViewModel::Col_Code,
    //                                     80,
    //                                     wxALIGN_LEFT,
    //                                     wxDATAVIEW_COL_RESIZABLE);
    // columnCode->SetWidth(wxCOL_WIDTH_AUTOSIZE);
    // m_dataViewListCtrl->AppendColumn(columnCode);
}