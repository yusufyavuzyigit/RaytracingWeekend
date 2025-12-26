add_executable(App 
    src/main.cpp
)

target_include_directories(App PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(App PRIVATE core_lib)

