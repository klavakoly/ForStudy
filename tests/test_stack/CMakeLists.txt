add_executable(test_stack main.cpp)
target_link_libraries(test_stack stack)
set_property(TARGET test_stack PROPERTY CXX_STANDARD 14)
