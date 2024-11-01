#include "pack_list_panel.h"
#include "pack_list_view_model.h"

PackListPanel::PackListPanel(wxWindow *parent)
    : PackListPanelUI(parent)
{
    wxDataViewTextRenderer *textRenderer = new wxDataViewTextRenderer();
    wxDataViewColumn *columnName = new wxDataViewColumn("Name", textRenderer, 0, 200, wxALIGN_LEFT, wxDATAVIEW_COL_SORTABLE);
    m_dataViewListCtrl->AppendColumn(columnName);

    wxDataViewColumn *columnCode = new wxDataViewColumn("Code", textRenderer, 0, 200, wxALIGN_LEFT, wxDATAVIEW_COL_SORTABLE);
    m_dataViewListCtrl->AppendColumn(columnCode);

    PackListViewModel *viewModel = new PackListViewModel();
    m_dataViewListCtrl->AssociateModel(viewModel);
    viewModel->DecRef();

    std::vector<PackListDataItem *> testDataItems = {};

    PackListDataItem* item1 = new PackListDataItem("1", "1");
    testDataItems.push_back(item1);

    for (const auto item : testDataItems)
    {
        wxDataViewItem dataItem(reinterpret_cast<void *>(0));
        viewModel->AddItem(*item);
        viewModel->ItemAdded(wxDataViewItem(nullptr), dataItem);
    }
}
