#ifndef MYTOOLS_COMPONENTS_ASKTAO_LIST_H
#define MYTOOLS_COMPONENTS_ASKTAO_LIST_H

#include <fstream>
#include <vector>
#include <string>

struct PackItem
{
    char name[256];
    char path[256];
    char color[256];
    int has_c_file;
    int icon;
    char unit[256];
    int no_float;
    bool combined;
    int price;
    int reputation;
    int item_task;
    char description[1024 * 2];
    char code[1024 * 2];
};

struct Item
{
    std::string name;
    int value;
    bool active;
};

class AsktaoPackList
{
private:
    std::vector<std::string> ReadFileToVector(const std::string &filePath);
    std::string ConvertGBKToUTF8(const std::string &gbkStr);

public:
    AsktaoPackList(bool &show_main_menu_bar);
    ~AsktaoPackList();

    void Show()
    {
        InitMainMenu();
        ShowList();
        ShowEdit();
    };

    void ShowList();
    void ShowEdit();
    void Delete();

    void InitMainMenu();

public:
    bool m_show;

private:
    std::vector<std::string> m_data;
    std::vector<PackItem *> m_pack_items;
    ImVector<char *> m_selection;

    bool &show_main_menu_bar;
    bool m_show_edit;

    // 菜单状态控制
    bool m_show_menu_bar;
    bool m_edit_disable;
};

#endif