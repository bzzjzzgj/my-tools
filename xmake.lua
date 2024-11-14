add_rules("mode.debug", "mode.release")
set_languages("c++20")

add_requires("imgui", { configs ={ glfw_opengl3 = true, opengl3 = true, shared = true  }})
add_requires("libiconv")

target("my_tools")
    set_kind("binary")
    add_files("src/**.cpp")
    add_packages("imgui", "libiconv")
    add_includedirs("src")

    after_build(function (target) 
        os.cp("fonts", path.join(target:targetdir()))
        os.cp("test", path.join(target:targetdir()))
    end)