find_package(Catch2 CONFIG REQUIRED)
include(CTest)

if (BUILD_TESTING)
    set(ALL_TESTS
            hello_world_test)
    add_executable(hello_world_test tests.cpp)

    foreach (target ${ALL_TESTS})
        target_link_libraries(${target} PRIVATE Catch2::Catch2WithMain Chapters)
        add_test(NAME ${target} COMMAND ${target})
    endforeach ()
endif ()
