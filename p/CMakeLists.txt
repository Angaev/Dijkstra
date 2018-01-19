add_executable(p main.cpp)

target_include_directories(p PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(p PUBLIC cxx_std_17)
target_compile_definitions(p PRIVATE SFML_STATIC)

target_link_libraries(p ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})