#ifndef _pack_list_view_model_
#define _pack_list_view_model_

#include <wx/dataview.h>
#include <wx/string.h>

class PackListDataItem
{
public:
    PackListDataItem(const wxString &code, const wxString &name)
        : m_code(code), m_name(name) {}

    const wxString& GetCode() const { return m_code; }
    void SetCode(const wxString &code) { m_code = code; }

    const wxString& GetName() const { return m_name; }
    void SetName(const wxString &name) { m_name = name; }

private:
    wxString m_code;
    wxString m_name;
};

// WX_DEFINE_ARRAY(PackListDataItem, PackListDataItemArray);

class PackListViewModel : public wxDataViewModel
{

private:
    std::vector<PackListDataItem> m_dataItems;

public:
    PackListViewModel();
    virtual ~PackListViewModel();

    void GetValue(wxVariant &variant,
                  const wxDataViewItem &item, unsigned int col) const override;

    bool SetValue(const wxVariant &variant,
                  const wxDataViewItem &item,
                  unsigned int col) override;

    wxDataViewItem GetParent(const wxDataViewItem &item) const override;

    bool IsContainer(const wxDataViewItem &item) const override;

    unsigned int GetChildren(const wxDataViewItem &item, wxDataViewItemArray &children) const override;

public:

    unsigned int GetCount() const;


    void AddItem(const PackListDataItem &item);


    bool RemoveItem(unsigned int index);


    const PackListDataItem &GetItem(unsigned int index) const;


    bool UpdateItem(unsigned int index, const PackListDataItem &item);
};

#endif