#include "app_config.h"

namespace MyTools
{
    AppConfig *AppConfig::GetInstance()
    {
        // 双重检查锁定模式 (Dobule-Checked Locking Pattern)
        if (instance == nullptr)
        {
            std::lock_guard<std::mutex> lock(mutext);
            if (instance == nullptr)
            {
                instance = new AppConfig();
            }
        }

        return instance;
    }

    void AppConfig::SetPath(const wxString &path)
    {
        this->path = &path;
    }
}