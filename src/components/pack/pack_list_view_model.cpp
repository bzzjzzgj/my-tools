#include "pack_list_view_model.h"
#include <wx/log.h>

PackListViewModel::PackListViewModel()
{
    m_pRoot = new PackListViewModelNode(nullptr, _("Data Overview"));
    m_pDataSet1 = new PackListViewModelNode(m_pRoot, _("Data Set #1"));

    PackListViewModelNode *nodeDataSet1 = new PackListViewModelNode(m_pRoot, 455, "A data set", "describes", "informaton to a end");
    m_pDataSet1->Append(nodeDataSet1);

    m_pRoot->Append(m_pDataSet1);

    m_pDataSet2 = new PackListViewModelNode(m_pRoot, _("Data Set #2"));
    m_pRoot->Append(m_pDataSet2);
}

PackListViewModel::~PackListViewModel()
{
    delete m_pRoot;
}

void PackListViewModel::GetValue(wxVariant &variant,
                                 const wxDataViewItem &item,
                                 unsigned int col) const
{

    wxASSERT(item.IsOk());

    PackListViewModelNode *node = (PackListViewModelNode *)item.GetID();
    switch (col)
    {
    case Col_Code:
        variant = node->GetCode();
        break;
    case Col_Name:
        variant = node->GetName();
        break;
    case Col_Path:
        variant = node->GetPath();
        break;
    case Col_Id:
        variant = (long)node->GetId();
        break;
    case Col_Max:
    default:
        wxLogError("PackListViewModel::GetValue: wrong column %d", col);
        break;
    }
}

bool PackListViewModel::SetValue(const wxVariant &variant,
                                 const wxDataViewItem &item,
                                 unsigned int col)
{
    wxASSERT(item.IsOk());

    PackListViewModelNode *node = (PackListViewModelNode *)item.GetID();

    switch (col)
    {
    case Col_Code:
        node->SetCode(variant.GetString());
        break;
    case Col_Name:
        node->SetName(variant.GetString());
        break;
    case Col_Path:
        node->SetPath(variant.GetString());
        break;
    case Col_Id:
        node->SetId(variant.GetInteger());
        break;
    case Col_Max:
    default:
        wxLogError("PackListViewModel::GetValue: wrong column %d", col);
        break;
    }

    return false;
}

wxDataViewItem PackListViewModel::GetParent(const wxDataViewItem &item) const
{
    if (!item.IsOk())
        return wxDataViewItem(0);

    PackListViewModelNode *node = (PackListViewModelNode *)item.GetID();

    if (node == m_pRoot)
    {
        return wxDataViewItem(0);
    }

    return wxDataViewItem((void *)node->GetParent());
}

bool PackListViewModel::IsContainer(const wxDataViewItem &item) const
{
    if (!item.IsOk())
    {
        return true;
    }

    PackListViewModelNode *node = (PackListViewModelNode *)item.GetID();
    return node->IsContainer();
}

unsigned int PackListViewModel::GetChildren(const wxDataViewItem &parent, wxDataViewItemArray &array) const
{
    PackListViewModelNode *node = (PackListViewModelNode *)parent.GetID();
    if (!node)
    {
        array.Add(wxDataViewItem((void *)m_pRoot));
    }

    if (node->GetChildCount() == 0)
    {
        return 0;
    }

    unsigned int count = node->GetChildren().GetCount();
    for (unsigned int pos = 0; pos < count; pos++)
    {
        PackListViewModelNode *child = node->GetChildren().Item(pos);
        array.Add(wxDataViewItem((void *)child));
    }

    return count;
}

unsigned int PackListViewModel::GetColumnCount() const
{
    return Col_Max;
}

wxString PackListViewModel::GetColumnType(unsigned int col) const
{
    if (col == Col_Id)
    {
        return "long";
    }
    else
    {
        return "string";
    }
}

PackListViewModelNode::PackListViewModelNode(PackListViewModelNode *parent,
                                             int id,
                                             const wxString &name,
                                             const wxString &code,
                                             const wxString &path)
    : m_parent(parent),
      m_id(id),
      m_code(code),
      m_path(path),
      m_bContainer(false)
{
}

PackListViewModelNode::PackListViewModelNode(PackListViewModelNode *parent, const wxString &branch)
    : m_parent(parent),
      m_code(branch), m_bContainer(true)
{
}

PackListViewModelNode::~PackListViewModelNode()
{
    std::size_t count = m_children.GetCount();
    for (std::size_t i = 0; i < count; i++)
    {
        PackListViewModelNode *child = m_children[i];
        delete child;
    }
}

bool PackListViewModelNode::IsContainer() const
{
    return m_bContainer;
}

PackListViewModelNode *PackListViewModelNode::GetParent()
{
    return m_parent;
}

PackListViewModelNodePtrArry &PackListViewModelNode::GetChildren()
{
    return m_children;
}

PackListViewModelNode *PackListViewModelNode::GetNthChild(unsigned int n)
{
    return m_children.Item(n);
}

void PackListViewModelNode::Insert(PackListViewModelNode *child, unsigned int n)
{
    m_children.Insert(child, n);
}

void PackListViewModelNode::Append(PackListViewModelNode *child)
{
    m_children.Add(child);
}

int PackListViewModelNode::GetId() const
{
    return m_id;
}

wxString PackListViewModelNode::GetCode() const
{
    return m_code;
}

wxString PackListViewModelNode::GetName() const
{
    return m_name;
}

wxString PackListViewModelNode::GetPath() const
{
    return m_path;
}

void PackListViewModelNode::SetId(int value)
{
    m_id = value;
}

void PackListViewModelNode::SetCode(const wxString &value)
{
    m_code = value;
}

void PackListViewModelNode::SetName(const wxString &value)
{
    m_name = value;
}

void PackListViewModelNode::SetPath(const wxString &value)
{
    m_path = value;
}

const unsigned int PackListViewModelNode::GetChildCount() const
{
    return m_children.Count();
}
