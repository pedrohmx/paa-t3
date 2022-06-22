-- premake5
workspace "paa-t3"
    configurations { "debug", "release" }

project "t3"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++latest"
    targetdir "bin/%{cfg.buildcfg}"

    files { "src/**.cpp", "src/**.hpp" }

    filter "configurations:debug"
        defines { "DEBUG" }
        symbols "On"
    filter "configurations:release"
        defines { "NDEBUG" }
        optimize "On"

project "libpaat3"
    kind "SharedLib"
    language "C++"
    cppdialect "C++latest"
    targetdir "shared/%{cfg.buildcfg}"

    files { "src/**.cpp", "src/**.hpp" }

    filter "configurations:debug"
        defines { "DEBUG" }
        symbols "On"
    filter "configurations:release"
        defines { "NDEBUG" }
        optimize "On"