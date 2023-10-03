find_package(Microsoft.GSL CONFIG REQUIRED)
add_library(leetcodecpp SHARED two_sum.cpp
        add_two_numbers.cpp)
target_link_libraries(leetcodecpp PRIVATE Microsoft.GSL::GSL)
