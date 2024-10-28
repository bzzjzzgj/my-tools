#include <mutex>
#include <wx/string.h>

namespace MyTools
{
    class AppConfig
    {
    private:
        // 私有构造函数，防止外部构造 。
        AppConfig() = default;

        // 删除拷贝构造函数和赋值操作符，防止拷贝
        AppConfig(const AppConfig &) = delete;

        // 单例实例
        static AppConfig *instance;

        // 互斥锁，用于线程安全
        static std::mutex mutext;

        const wxString *path;

    public:
        /**
         * 获取单例实例的静态方法 。
         */
        static AppConfig *GetInstance();

        void SetPath(const wxString &path);
    };
}