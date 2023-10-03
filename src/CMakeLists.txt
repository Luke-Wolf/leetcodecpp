find_package(Microsoft.GSL CONFIG REQUIRED)
file(GLOB leetcode_SRC CONFIGURE_DEPENDS "*.cpp")
add_library(leetcodecpp SHARED ${leetcode_SRC})
target_link_libraries(leetcodecpp PRIVATE Microsoft.GSL::GSL)
