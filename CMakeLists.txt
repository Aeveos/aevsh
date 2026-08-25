# CMakeList.txt : CMake project for Aevsh, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Aevsh" C)

# Add source to this project's executable.

add_executable (Aevsh "src/core/core.c" "src/exec/builtins.c" "src/frontend/lexer.c")

target_include_directories(Aevsh PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Aevsh PROPERTY C_STANDARD 23)
endif()

if(MSVC)
    add_compile_options(/std:clatest)
endif()

