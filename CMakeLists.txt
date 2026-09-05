# CMakeList.txt : CMake project for Aevsh, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Aevsh" C)

# Add source to this project's executable.

add_executable (Aevsh "src/core/core.c"
                      "src/exec/builtins.c"
                      "src/frontend/lexer.c"
                      "src/core/input.c"
)

target_include_directories(Aevsh PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(WIN32)

  target_sources(Aevsh PRIVATE
                 assets/resource.rc
                 src/platform/windows/windowsTerminal.c)

else ()

  target_sources(Aevsh PRIVATE
                 src/platform/linux/linuxTerminal.c)


  find_package(PkgConfig REQUIRED)

  set(PKG_CONFIG_USE_STATIC_LIBS ON)
  pkg_check_modules(NC_CORE REQUIRED notcurses-core)

  target_include_directories(Aevsh PRIVATE ${NC_CORE_STATIC_INCLUDE_DIRS})

  target_link_libraries(Aevsh PRIVATE ${NC_CORE_STATIC_LIBRARIES})

  target_link_options(Aevsh PRIVATE ${NC_CORE_STATIC_LDFLAGS})

endif ()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Aevsh PROPERTY C_STANDARD 23)
endif()

