-- premake5
workspace "paa-t3"
    configurations { "debug", "release" }

project "t3"
    kind "ConsoleApp"
    language "C++"
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
    targetdir "shared/%{cfg.buildcfg}"

    files { "src/**.cpp", "src/**.hpp" }

    filter "configurations:debug"
        defines { "DEBUG" }
        symbols "On"
    filter "configurations:release"
        defines { "NDEBUG" }
        optimize "On"