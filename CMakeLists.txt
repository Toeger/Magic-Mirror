cmake_minimum_required(VERSION 2.8)

enable_language(CXX)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)

set(MISC_FILES
        .clang-format
        CMakeLists.txt
        README.md
)
add_custom_target(MISC_FILES
        COMMENT "This target only exists to list files in IDEs"
        SOURCES ${MISC_FILES} ${UI_FILES}
)

project(Magic-Mirror)
add_executable(${PROJECT_NAME} "Magic-Mirror.cpp")
