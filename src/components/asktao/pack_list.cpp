#include <iostream>

#include <imgui.h>
#include "pack_list.h"

AsktaoPackList::AsktaoPackList(/* args */)
{
    m_data = ReadFileToVector("D:\\gs\\etc.pak\\charge_item.list");
}

std::vector<std::string> AsktaoPackList::ReadFileToVector(const std::string &filePath)
{
    std::vector<std::string> lines;
    std::ifstream file(filePath);

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {

            if (!line.empty() && line[0] != '#')
            {

                size_t pos = 0;
                while ((pos = line.find(", ")) != std::string::npos)
                {
                    line.erase(pos + 1, line.find_first_not_of(' ', pos + 1) - (pos + 1));
                }

                PackItem item;

                if ((pos = line.find(',')) != std::string::npos)
                {
                    item.name = line.substr(0, pos);
                    line.erase(0, pos + 1);
                }
                if ((pos = line.find(',')) != std::string::npos)
                {
                    item.path = line.substr(0, pos);
                    line.erase(0, pos + 1);
                }
                if ((pos = line.find(',')) != std::string::npos)
                {
                    item.color = line.substr(0, pos);
                    line.erase(0, pos + 1);
                }
                sscanf(line.c_str(), "%d", &item.has_c_file);
                line.erase(0, line.find(',') + 1);
                sscanf(line.c_str(), "%d", &item.icon);
                line.erase(0, line.find(',') + 1);
                if ((pos = line.find(',')) != std::string::npos)
                {
                    item.unit = line.substr(0, pos);
                    line.erase(0, pos + 1);
                }
                sscanf(line.c_str(), "%d", &item.no_float);
                line.erase(0, line.find(',') + 1);
                sscanf(line.c_str(), "%d", &item.combined);
                line.erase(0, line.find(',') + 1);
                sscanf(line.c_str(), "%d", &item.price);
                line.erase(0, line.find(',') + 1);
                sscanf(line.c_str(), "%d", &item.reputation);
                line.erase(0, line.find(',') + 1);
                sscanf(line.c_str(), "%d", &item.item_task);
                line.erase(0, line.find(',') + 1);
                if ((pos = line.find(',')) != std::string::npos)
                {
                    item.description = line.substr(0, pos);
                    line.erase(0, pos + 1);
                }

                if (item.path.find("charge/cq_") != std::string::npos)
                {
                    m_pack_items.push_back(new PackItem(item));
                }
            }
        }
        file.close();
    }

    return lines;
}

AsktaoPackList::~AsktaoPackList()
{
}

void AsktaoPackList::Show()
{
    bool show = true;
    ImGui::Begin("礼包", &show);
    ImGui::SetWindowSize(ImVec2(800, 500));

    const float TEXT_BASE_HEIGHT = ImGui::GetTextLineHeightWithSpacing();
    static ImGuiTableFlags flags = ImGuiTableFlags_ScrollY | ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable;
    ImVec2 outer_size = ImVec2(0.0f, 0.0f);

    int selected_row = -1;

    if (ImGui::BeginChild("resizable", ImVec2(0.0f, 0.0f), true))
    {
        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("Open", "Ctrl+O"))
                { /* Do something */
                }
                if (ImGui::MenuItem("Save", "Ctrl+S"))
                { /* Do something */
                }
                if (ImGui::MenuItem("Close", "Ctrl+W"))
                { /* Do something */
                }
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }

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
                ImGui::TableNextRow();

                // 行背景颜色
                // if (selected_row == i)
                // {
                //     ImGui::TableSetBgColor(ImGuiTableBgTarget_RowBg0, ImGui::GetColorU32(ImGui::GetStyle().Colors[ImGuiCol_HeaderHovered]));
                // }

                ImGui::TableSetColumnIndex(0);
                ImGui::Text("%s", item->name.c_str());
                ImGui::TableSetColumnIndex(1);
                ImGui::Text("%s", item->path.c_str());
                ImGui::TableSetColumnIndex(2);
                ImGui::Text("%s", item->color.c_str());
                ImGui::TableSetColumnIndex(3);
                ImGui::Text("%d", item->icon);
                ImGui::TableSetColumnIndex(4);
                ImGui::Text("%s", item->unit.c_str());
                ImGui::TableSetColumnIndex(5);
                ImGui::Text("%d", item->combined);
                ImGui::TableSetColumnIndex(6);
                ImGui::Text("%d", item->price);
                ImGui::TableSetColumnIndex(7);
                ImGui::Text("%s", item->description.c_str());


                

                // if (ImGui::IsItemClicked())
                // {
                //     selected_row = i;
                // }
            }

            ImGui::EndTable();
        }
    }

    ImGui::EndChild();
    ImGui::End();
}

void AsktaoPackList::ShowEdit()
{

    char textInput[256] = "";
    char multiLineText[1024] = "";
    bool checkBoxValue = false;
    char largeTextEdit[1024] = "";
    static bool showDemoWindow = false;

    // 创建一个窗口
    ImGui::Begin("Two Column Layout");

    // 创建两列布局
    float leftWidth = 300.0f;                                        // 左边列的宽度
    float rightWidth = ImGui::GetContentRegionAvail().x - leftWidth; // 右边列的宽度

    // 左边列
    ImGui::BeginChild("left_column", ImVec2(leftWidth, 0), true);
    {
        // 添加一个文本输入框
        ImGui::Text("Text Input:");
        ImGui::InputText("##text_input", textInput, 256);

        // 添加一个复选框
        ImGui::Spacing();
        ImGui::Text("Check Box:");
        ImGui::Checkbox("##check_box", &checkBoxValue);

        // 添加一个多行文本输入框
        ImGui::Spacing();
        ImGui::Text("Multi-line Text Input:");

        ImVec2 m_size = ImVec2(-1, 100);
        ImGui::InputTextMultiline("##multi_line_text", multiLineText, 1024 * 1024, m_size); // 宽度为-1表示填充整个列的宽度，高度为100像素

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
    ImGui::BeginChild("right_column", ImVec2(rightWidth, 0), true);
    {
        // 添加一个大的文本编辑器
        ImGui::Text("Large Text Editor:");
        ImGui::InputTextMultiline("##large_text_edit", largeTextEdit, 256, ImVec2(-1, 300)); // 宽度为-1表示填充整个列的宽度，高度为300像素
    }
    ImGui::EndChild();

    ImGui::End();
}