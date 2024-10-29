
add_rules("mode.debug", "mode.release")

add_requires("wxwidgets", { configs = { shared = true } })

target("my-tools")
    set_kind("binary")
    add_files("src/**.cpp")
    add_includedirs("src/themes/my", "src/components/pack", "src/components/ui","src/frames")
    set_languages("c++17")
    add_packages("wxwidgets")

    before_build(function (target)
        local cpps = target:sourcefiles()
        local command = "xgettext --from-code=UTF-8 --keyword=_ -o ./src/locale/zh_CN/LC_MESSAGES/message.pot -L C++ "
     
        -- 生成 pot 文件
        for _, file in ipairs(cpps) do
            command = command .. " " .. file .. " "

            if not file:endswith("main.cpp") then
                command = command .. " " .. string.gsub(file, "%.cpp$", ".h")
            end
        end
        os.exec(command)

        -- 生成 po 文件
        command = "msgmerge --update ./src/locale/zh_CN/LC_MESSAGES/message.po ./src/locale/zh_CN/LC_MESSAGES/message.pot"
        os.exec(command)

        -- 生成 mo 文件
        command = "msgfmt ./src/locale/zh_CN/LC_MESSAGES/message.po -o ./src/locale/zh_CN/LC_MESSAGES/message.mo"
        os.exec(command)
    end)

    after_build(function (target)
        os.cp("src/locale", path.join(target:targetdir(), "locale"))
    end)

    on_clean(function (target) 
        os.rm(path.join(target:targetdir(), "locale"))
    end)



--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro definition
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--
