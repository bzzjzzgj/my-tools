#ifndef _pack_list_view_model_
#define _pack_list_view_model_

#include <wx/dataview.h>
#include <wx/string.h>

class PackListDataItem final
{
public:
    PackListDataItem(const wxString &code, const wxString &name)
        : m_code(code), m_name(name) {}

    const wxString &GetCode() const { return m_code; }
    void SetCode(const wxString &code) { m_code = code; }

    const wxString &GetName() const { return m_name; }
    void SetName(const wxString &name) { m_name = name; }

private:
    wxString m_code;
    wxString m_name;
};

// WX_DEFINE_ARRAY(PackListDataItem, PackListDataItemArray);

class PackListViewModelNode;

WX_DEFINE_ARRAY_PTR(PackListViewModelNode *, PackListViewModelNodePtrArry);

class PackListViewModelNode final
{
public:
    PackListViewModelNode(PackListViewModelNode *parent,
                          int id,
                          const wxString &name,
                          const wxString &code,
                          const wxString &path);
    PackListViewModelNode(PackListViewModelNode *parent, const wxString &branch);
    ~PackListViewModelNode();

    bool IsContainer() const;
    PackListViewModelNode *GetParent();
    PackListViewModelNodePtrArry &GetChildren();
    PackListViewModelNode *GetNthChild(unsigned int n);

    void Insert(PackListViewModelNode *child, unsigned int n);
    void Append(PackListViewModelNode *child);
    const unsigned int GetChildCount() const;

    int GetId() const;
    wxString GetName() const;
    wxString GetCode() const;
    wxString GetPath() const;

    void SetId(int value);
    void SetName(const wxString &value);
    void SetCode(const wxString &value);
    void SetPath(const wxString &value);

private:
    PackListViewModelNode *m_parent;
    PackListViewModelNodePtrArry m_children;

    int m_id;
    wxString m_code;
    wxString m_name;
    wxString m_path;
    bool m_bContainer;
};

class PackListViewModel : public wxDataViewModel
{
public:
    enum
    {
        Col_Code = 0,
        Col_Name,
        Col_Path,
        Col_Id,
        Col_Max
    };

    PackListViewModel();
    ~PackListViewModel();

    unsigned int GetColumnCount() const override;
    wxString GetColumnType(unsigned int col) const override;
    void GetValue(wxVariant &variant,
                  const wxDataViewItem &item, unsigned int col) const override;
    bool SetValue(const wxVariant &variant,
                  const wxDataViewItem &item,
                  unsigned int col) override;
    // bool IsEnabled(const wxDataViewItem& item, unsigned int col) const override;
    wxDataViewItem GetParent(const wxDataViewItem &item) const override;
    bool IsContainer(const wxDataViewItem &item) const override;
    unsigned int GetChildren(const wxDataViewItem &item, wxDataViewItemArray &children) const override;

private:
    PackListViewModelNode *m_pRoot;
    PackListViewModelNode *m_pDataSet1;
    PackListViewModelNode *m_pDataSet2;
};

#endif