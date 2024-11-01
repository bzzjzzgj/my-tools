#include "pack_list_view_model.h"

PackListViewModel::PackListViewModel() {}

PackListViewModel::~PackListViewModel() {}

void PackListViewModel::GetValue(wxVariant &variant,
                                 const wxDataViewItem &item,
                                 unsigned int col) const
{
    // 获取行号
    unsigned int row = reinterpret_cast<uintptr_t>(item.GetID());

    // 检查行号是否在数据项范围内
    if (row >= m_dataItems.size())
    {
        return;
    }

    // 根据列号获取不同的值
    switch (col)
    {
    case 0:
        variant = m_dataItems[row].GetName();
        break;
    case 1:
        variant = m_dataItems[row].GetCode();
        break;
    default:
        break;
    }
}

bool PackListViewModel::SetValue(const wxVariant &variant,
                                 const wxDataViewItem &item,
                                 unsigned int col)
{
    // 获取行号
    unsigned int row = reinterpret_cast<uintptr_t>(item.GetID());

    // 检查行号是否在数据项范围内
    if (row >= m_dataItems.size())
    {
        return false;
    }

    // 根据列号设置不同的值
    switch (col)
    {
    case 0:
        m_dataItems[row].SetName(variant.GetString());
        break;
    case 1:
        m_dataItems[row].SetCode(variant.GetString());
        break;
    default:
        return false;
    }

    // 通知视图数据已更改
    ItemChanged(item);
    return true;
}

wxDataViewItem PackListViewModel::GetParent(const wxDataViewItem &item) const
{
    // 在这个模型中，所有项目都没有父项，因此返回无效项
    return wxDataViewItem();
}

bool PackListViewModel::IsContainer(const wxDataViewItem &item) const
{
    // 只有不可见的（和无效的）根项目有子项目
    return !item.IsOk();
}

unsigned int PackListViewModel::GetChildren(const wxDataViewItem &item, wxDataViewItemArray &children) const
{
    // 如果项目无效，则返回所有顶级项目
    if (!item.IsOk())
    {
        for (unsigned int i = 0; i < m_dataItems.size(); ++i)
        {
            children.Add(wxDataViewItem(reinterpret_cast<void *>(static_cast<uintptr_t>(i))));
        }
        return m_dataItems.size();
    }
    // 否则，返回 0，因为此模型不支持嵌套
    return 0;
}

unsigned int PackListViewModel::GetCount() const
{
    return m_dataItems.size();
}

void PackListViewModel::AddItem(const PackListDataItem &item)
{
    m_dataItems.push_back(item);
    wxDataViewItem dataItem(reinterpret_cast<void *>(m_dataItems.size() - 1));
    ItemAdded(wxDataViewItem(nullptr), dataItem);
}

bool PackListViewModel::RemoveItem(unsigned int index)
{
    if (index >= m_dataItems.size())
    {
        return false;
    }
    wxDataViewItem dataItem(reinterpret_cast<void *>(static_cast<uintptr_t>(index)));
    ItemDeleted(wxDataViewItem(nullptr), dataItem);
    m_dataItems.erase(m_dataItems.begin() + index);
    return true;
}

const PackListDataItem &PackListViewModel::GetItem(unsigned int index) const
{
    return m_dataItems.at(index);
}

bool PackListViewModel::UpdateItem(unsigned int index, const PackListDataItem &item)
{
    if (index >= m_dataItems.size())
    {
        return false; 
    }
    m_dataItems[index] = item;
    wxDataViewItem dataItem(reinterpret_cast<void *>(static_cast<uintptr_t>(index)));
    ItemChanged(dataItem);
    return true;
}
