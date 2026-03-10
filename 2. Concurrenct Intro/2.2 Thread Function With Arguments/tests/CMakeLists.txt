include(Catch)

if(ENABLE_TESTING)
    set(TEST_MAIN "unit_tests")
    set(TEST_SOURCES "test.cpp")

    add_executable(${TEST_MAIN} ${TEST_SOURCES})
    target_link_libraries(${TEST_MAIN} PUBLIC Functions Catch2::Catch2WithMain)

    catch_discover_tests(${TEST_MAIN})
endif()