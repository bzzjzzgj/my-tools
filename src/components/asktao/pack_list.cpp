#include <iostream>
#include <imgui.h>
#include <iconv.h>
#include "pack_list.h"

AsktaoPackList::AsktaoPackList(bool &show_main_menu_bar)
    : m_show(true), show_main_menu_bar(show_main_menu_bar)
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
        while (std::getline(file, gbk_line))
        {

            if (!gbk_line.empty() && gbk_line[0] != '#')
            {
                std::string line = ConvertGBKToUTF8(gbk_line);

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
    if (!m_show)
    {
        show_main_menu_bar = true;
        return;
    }

    show_main_menu_bar = false;

    ImGui::Begin("礼包", &m_show);

    const float TEXT_BASE_HEIGHT = ImGui::GetTextLineHeightWithSpacing();
    static ImGuiTableFlags flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable;
    ImVec2 outer_size = ImVec2(0.0f, 0.0f);

    static ImVector<std::string> selection;

    if (ImGui::BeginChild("resizable", ImVec2(0.0f, 0.0f), true))
    {
        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("礼包工具"))
            {
                if (ImGui::MenuItem("设置 etc 目录", "Ctrl+O"))
                { /* Do something */
                }

                if (ImGui::MenuItem("设置 gs 目录", "Ctrl+O"))
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
                ImGui::PushID(item->path.c_str());
                const bool row_is_selected = selection.contains(item->path);

                ImGui::TableNextRow();

                ImGuiSelectableFlags selectable_flags = ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowOverlap;

                ImGui::TableSetColumnIndex(0);
                ImGui::Text("%s", item->name.c_str());
                ImGui::TableSetColumnIndex(1);

                if (ImGui::Selectable(item->name.c_str(), row_is_selected, selectable_flags))
                {

                    if (ImGui::GetIO().KeyCtrl)
                    {
                        if (row_is_selected)
                        {
                            selection.find_erase_unsorted(item->path);
                        }
                        else
                        {
                            selection.push_back(item->path);
                        }
                    }
                    else
                    {
                        selection.clear();
                        selection.push_back(item->path);
                    }
                }

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
