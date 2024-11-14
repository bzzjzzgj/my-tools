add_rules("mode.debug", "mode.release")

add_requires("imgui", { configs ={ glfw_opengl3 = true, opengl3 = true }})

target("my_tools")
    set_kind("binary")
    add_files("src/**.cpp")
    add_packages("imgui")
    add_includedirs("src")

    after_build(function (target) 
        os.cp("fonts", path.join(target:targetdir()))
    end)