#ifndef MYTOOLS_COMPONENTS_ASKTAO_LIST_H
#define MYTOOLS_COMPONENTS_ASKTAO_LIST_H

#include <fstream>
#include <vector>
#include <string>

struct PackItem
{
    std::string name;
    std::string path;
    std::string color;
    int has_c_file;
    int icon;
    std::string unit;
    int no_float;
    int combined;
    int price;
    int reputation;
    int item_task;
    std::string description;
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

    void Show();
    void ShowEdit();

public:
    bool m_show;

private:
    std::vector<std::string> m_data;
    std::vector<PackItem *> m_pack_items;

    bool &show_main_menu_bar;
};

#endif