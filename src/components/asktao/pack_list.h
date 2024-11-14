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

class AsktaoPackList
{
private:
    std::vector<std::string> ReadFileToVector(const std::string &filePath);

public:
    AsktaoPackList(/* args */);
    ~AsktaoPackList();

    void Show();
    void ShowEdit();

private:
    std::vector<std::string> m_data;
    std::vector<PackItem *> m_pack_items;
};

#endif