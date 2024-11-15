#include <iostream>
#include <imgui.h>
#include <iconv.h>
#include "pack_list.h"

AsktaoPackList::AsktaoPackList(bool &show_main_menu_bar)
    : m_show(false),
      show_main_menu_bar(show_main_menu_bar),
      m_show_edit(false)
{
    m_data = ReadFileToVector("./test/charge_item.list");
}

std::string AsktaoPackList::ConvertGBKToUTF8(const std::string &gbkStr)
{
    iconv_t cd = iconv_open("UTF-8", "GBK");
    if (cd == (iconv_t)-1)
    {
        perror("iconv_open");
        return "";
    }

    size_t inBytesLeft = gbkStr.size();
    size_t outBytesLeft = inBytesLeft * 2; // UTF-8 may require more space
    std::vector<char> outBuf(outBytesLeft);
    char *inBuf = const_cast<char *>(gbkStr.data());
    char *outPtr = outBuf.data();

    if (iconv(cd, &inBuf, &inBytesLeft, &outPtr, &outBytesLeft) == (size_t)-1)
    {
        perror("iconv");
        iconv_close(cd);
        return "";
    }

    iconv_close(cd);
    return std::string(outBuf.data(), outBuf.size() - outBytesLeft);
}

std::vector<std::string> AsktaoPackList::ReadFileToVector(const std::string &filePath)
{
    std::vector<std::string> lines;
    std::ifstream file(filePath);

    if (file.is_open())
    {
        std::string gbk_line;

        // 读取第一行
        while (std::getline(file, gbk_line))
        {
            if (!gbk_line.empty() && gbk_line[0] != '#')
            {
                break;
            }
        }

        std::string head_line = gbk_line;

        ImVector<int> head_pos_list;

        head_pos_list.push_back(head_line.find("key_name"));
        head_pos_list.push_back(head_line.find("file_id"));
        head_pos_list.push_back(head_line.find("color"));
        head_pos_list.push_back(head_line.find("has_c_file"));
        head_pos_list.push_back(head_line.find("icon"));
        head_pos_list.push_back(head_line.find("unit"));
        head_pos_list.push_back(head_line.find("no_float"));
        head_pos_list.push_back(head_line.find("combined"));
        head_pos_list.push_back(head_line.find("value"));
        head_pos_list.push_back(head_line.find("reputation"));
        head_pos_list.push_back(head_line.find("item_task"));
        head_pos_list.push_back(head_line.find("desc"));

        while (std::getline(file, gbk_line))
        {
            if (!gbk_line.empty() && gbk_line[0] != '#')
            {
                std::string line = gbk_line;

                PackItem item;

                for (int i = 0; i < head_pos_list.size(); ++i)
                {
                    int pos = head_pos_list[i];
                    std::string gbk_str;

                    if (i < head_pos_list.size() - 1)
                    {
                        gbk_str = line.substr(pos, (head_pos_list[i + 1] - pos));
                        gbk_str.erase(gbk_str.find_last_not_of(' '));
                    }
                    else
                    {
                        gbk_str = line.substr(pos);
                    }

                    std::string str = ConvertGBKToUTF8(gbk_str);

                    switch (i)
                    {
                    case 0:
                        strncpy(item.name, str.c_str(), sizeof(item.name) - 1);
                        item.name[sizeof(item.name) - 1] = '\0';
                        break;
                    case 1:
                        strncpy(item.path, str.c_str(), sizeof(item.path) - 1);
                        item.path[sizeof(item.path) - 1] = '\0';
                        break;
                    case 2:
                        strncpy(item.color, str.c_str(), sizeof(item.color) - 1);
                        item.color[sizeof(item.color) - 1] = '\0';
                        break;
                    case 3:
                        sscanf(str.c_str(), "%d", &item.has_c_file);
                        break;
                    case 4:
                        sscanf(str.c_str(), "%d", &item.icon);
                        break;
                    case 5:
                        strncpy(item.unit, str.c_str(), sizeof(item.unit) - 1);
                        item.unit[sizeof(item.unit) - 1] = '\0';
                        break;
                    case 6:
                        sscanf(str.c_str(), "%d", &item.no_float);
                        break;
                    case 7:
                        item.combined = (str == "1");
                        break;
                    case 8:
                        sscanf(str.c_str(), "%d", &item.price);
                        break;
                    case 9:
                        sscanf(str.c_str(), "%d", &item.reputation);
                        break;
                    case 10:
                        sscanf(str.c_str(), "%d", &item.item_task);
                        break;
                    case 11:
                        strncpy(item.description, str.c_str(), sizeof(item.description) - 1);
                        item.description[sizeof(item.description) - 1] = '\0';
                        break;
                    default:
                        break;
                    }
                }

                m_pack_items.push_back(new PackItem(item));
            }
        }
    }

    file.close();

    return lines;
}

AsktaoPackList::~AsktaoPackList()
{
}

void AsktaoPackList::ShowList()
{

    if (!m_show)
    {
        show_main_menu_bar = true;
        return;
    }

    show_main_menu_bar = false;

    ImGui::SetNextWindowSize(ImVec2(1024, 600), ImGuiCond_FirstUseEver);
    ImGui::Begin("礼包", &m_show, ImGuiWindowFlags_NoCollapse);

    const float TEXT_BASE_HEIGHT = ImGui::GetTextLineHeightWithSpacing();
    static ImGuiTableFlags flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable;
    ImVec2 outer_size = ImVec2(0.0f, 0.0f);

    if (ImGui::BeginChild("resizable", ImVec2(0.0f, 0.0f), true))
    {

        if (ImGui::BeginTable("asktao_list", 8, flags, outer_size))
        {

            ImGui::TableSetupScrollFreeze(0, 1);

            ImGui::TableSetupColumn("名称", ImGuiTableColumnFlags_WidthFixed, 100.0f); // 设置列宽度为100
            ImGui::TableSetupColumn("编码", ImGuiTableColumnFlags_WidthFixed, 150.0f); // 设置列宽度为150
            ImGui::TableSetupColumn("颜色", ImGuiTableColumnFlags_WidthFixed, 100.0f); // 设置列宽度为100
            ImGui::TableSetupColumn("图标", ImGuiTableColumnFlags_WidthFixed, 80.0f);  // 设置列宽度为80
            ImGui::TableSetupColumn("单位", ImGuiTableColumnFlags_WidthFixed, 100.0f); // 设置列宽度为100
            ImGui::TableSetupColumn("叠加", ImGuiTableColumnFlags_WidthFixed, 80.0f);  // 设置列宽度为80
            ImGui::TableSetupColumn("价格", ImGuiTableColumnFlags_WidthFixed, 100.0f); // 设置列宽度为100
            ImGui::TableSetupColumn("描述", ImGuiTableColumnFlags_WidthStretch);       // 自动调整列宽度
            ImGui::TableHeadersRow();

            for (size_t i = 0; i < m_pack_items.size(); ++i)
            {

                PackItem *item = m_pack_items[i];
                ImGui::PushID(item->path);
                const bool row_is_selected = m_selection.contains(item->path);

                ImGui::TableNextRow();

                ImGuiSelectableFlags selectable_flags = ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowOverlap;

                ImGui::TableSetColumnIndex(0);
                ImGui::Text("%s", item->name);
                ImGui::TableSetColumnIndex(1);

                if (ImGui::Selectable(item->path, row_is_selected, selectable_flags))
                {

                    if (ImGui::GetIO().KeyCtrl)
                    {
                        if (row_is_selected)
                        {
                            m_selection.find_erase_unsorted(item->path);
                        }
                        else
                        {
                            m_selection.push_back(item->path);
                        }
                    }
                    else
                    {
                        m_selection.clear();
                        m_selection.push_back(item->path);
                    }
                }

                ImGui::TableSetColumnIndex(2);
                ImGui::Text("%s", item->color);
                ImGui::TableSetColumnIndex(3);
                ImGui::Text("%d", item->icon);
                ImGui::TableSetColumnIndex(4);
                ImGui::Text("%s", item->unit);
                ImGui::TableSetColumnIndex(5);
                ImGui::Text("%d", item->combined);
                ImGui::TableSetColumnIndex(6);
                ImGui::Text("%d", item->price);
                ImGui::TableSetColumnIndex(7);
                ImGui::Text("%s", item->description);

                ImGui::PopID();
            }

            ImGui::EndTable();
        }
    }

    ImGui::EndChild();
    ImGui::End();
}

void AsktaoPackList::ShowEdit()
{
    if (!m_show_edit)
        return;

    ImGui::SetNextWindowSize(ImVec2(1024, 600), ImGuiCond_FirstUseEver);
    ImGui::Begin("编辑礼包", &m_show_edit, ImGuiWindowFlags_NoCollapse);

    std::string path = m_selection[0];

    PackItem *selected_item = nullptr;

    auto it = std::find_if(m_pack_items.begin(), m_pack_items.end(), [&path](PackItem *item)
                           { return path == item->path; });

    if (it != m_pack_items.end())
    {
        selected_item = *it;
    }

    if (selected_item == nullptr)
    {
        return;
    }

    // static char name_input[256] = "";
    // static char path_input[256] = "";
    // static char color_input[7] = "金色";
    // static int icon_input = 9268;
    // static char unit_input[4] = "张";
    // static bool combined_checkbox = false;
    // static int price_input = 500;
    // static char desc_mutiline_text[2048] = "";
    // static char code_mutiline_text[2048] = "";

    // 创建两列布局
    float leftWidth = 300.0f;                                        // 左边列的宽度
    float rightWidth = ImGui::GetContentRegionAvail().x - leftWidth; // 右边列的宽度

    std::vector<std::string> options = {
        "金色",
        "粉色",
        "蓝色",
        "白色"};

    static int current_option_index = 0;

    // 左边列
    ImGui::BeginChild("left_column", ImVec2(leftWidth, 0), true);
    {
        ImGui::Text("名称:");
        ImGui::InputText("##name_input", selected_item->name, 256);

        ImGui::Text("路径");
        ImGui::InputText("##path_input", selected_item->path, 256);

        // 添加一个复选框
        ImGui::Spacing();
        ImGui::Text("颜色:");
        // 创建一个下拉选项菜单
        if (ImGui::BeginCombo("物品品质", options[current_option_index].c_str()))
        {
            for (int i = 0; i < options.size(); i++)
            {
                bool is_selected = (current_option_index == i);
                if (ImGui::Selectable(options[i].c_str(), is_selected))
                {
                    current_option_index = i;
                }

                // 设置当前选中的项为高亮
                if (is_selected)
                {
                    ImGui::SetItemDefaultFocus();
                }
            }
            ImGui::EndCombo();
        }

        std::string str = "";

        ImGui::Text("图标");
        ImGui::InputInt("##icon_input", &selected_item->icon, 256);

        ImGui::Text("单位");
        ImGui::InputText("##unit_input", selected_item->unit, 4);

        ImGui::Spacing();
        ImGui::Text("是否叠加:");
        ImGui::Checkbox("##combined_checkbox", &selected_item->combined);

        ImGui::Text("价格");
        ImGui::InputInt("##price_input", &selected_item->price, 256);

        // 添加一个多行文本输入框
        ImGui::Spacing();
        ImGui::Text("描述:");

        ImGui::InputTextMultiline("##description", selected_item->description, 1024 * 2, ImVec2(-1, 100)); // 宽度为-1表示填充整个列的宽度，高度为100像素

        // 添加一个按钮来提交表单
        if (ImGui::Button("Submit"))
        {
            // 处理表单提交逻辑
            ImGui::OpenPopup("Form Submitted");
        }

        // 弹出窗口显示提交结果
        if (ImGui::BeginPopupModal("Form Submitted", NULL, ImGuiWindowFlags_AlwaysAutoResize))
        {
            ImGui::Text("Your form has been submitted successfully!");
            ImGui::Separator();

            if (ImGui::Button("OK", ImVec2(120, 0)))
            {
                ImGui::CloseCurrentPopup();
            }
            ImGui::EndPopup();
        }
    }
    ImGui::EndChild();

    // 右边列
    ImGui::SameLine();
    ImGui::BeginChild("right", ImVec2(0, 0), true);
    {
        // 添加一个大的文本编辑器
        ImGui::Text("代码:");
        ImGui::InputTextMultiline("##code", selected_item->code, 256, ImVec2(-1, -1)); // 宽度为-1表示填充整个列的宽度，高度为300像素
    }
    ImGui::EndChild();

    ImGui::End();
}

void AsktaoPackList::Delete()
{
    ImGui::OpenPopup("Delete?");
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

    if (ImGui::BeginPopupModal("Delete?", NULL, ImGuiWindowFlags_AlwaysAutoResize))
    {
        if (ImGui::Button("确认", ImVec2(120, 0)))
        {
            ImGui::CloseCurrentPopup();
        }
        ImGui::SetItemDefaultFocus();
        ImGui::SameLine();
        if (ImGui::Button("取消", ImVec2(120, 0)))
        {
            ImGui::CloseCurrentPopup();
        }
        ImGui::EndPopup();
    }
}

void AsktaoPackList::InitMainMenu()
{
    if (!(m_show_edit | m_show))
        return;

    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("礼包工具"))
        {
            if (ImGui::MenuItem("关闭", ""))
            {
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("工作目录"))
        {
            if (ImGui::MenuItem("设置 etc 目录", "Ctrl+O"))
            {
            }

            if (ImGui::MenuItem("设置 gs 目录", "Ctrl+O"))
            {
            }

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("编辑"))
        {
            if (ImGui::MenuItem("新增", "Ctrl+O", nullptr, false))
            {
                // m_show_edit = true;
            }

            if (ImGui::MenuItem("修改", "Ctrl+O", nullptr, m_selection.size() == 1))
            {
                m_show_edit = true;
            }

            if (ImGui::MenuItem("删除", "Ctrl+D", nullptr, m_selection.size() > 0))
            {
            }

            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}
