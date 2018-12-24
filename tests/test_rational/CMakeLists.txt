add_executable(test_rational main.cpp )
target_link_libraries(test_rational rational)
set_property(TARGET test_rational PROPERTY CXX_STANDARD 14)
