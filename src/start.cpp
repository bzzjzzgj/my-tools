#include <imgui.h>
#include "start.h"

Start::Start()
{
}

Start::~Start()
{
}

void Start::Init()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls

    // 设置主题
    // ImGui::StyleColorsDark();
    ImGui::StyleColorsLight();

    // 加载字体
    ImFont *font1 = io.Fonts->AddFontFromFileTTF("./fonts/LXGWWenKai-Medium.ttf", 18.0f, nullptr, io.Fonts->GetGlyphRangesChineseFull());
    ImFont *font2 = io.Fonts->AddFontFromFileTTF("./fonts/LXGWWenKaiMono-Medium.ttf", 18.0f, nullptr, io.Fonts->GetGlyphRangesChineseFull());
    IM_ASSERT(font1 != nullptr);
    IM_ASSERT(font2 != nullptr);
}