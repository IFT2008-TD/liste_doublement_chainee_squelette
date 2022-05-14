set(TEST_SOURCES tests_liste.cpp  ${PROJECT_SOURCE_DIR}/Liste.h)

add_executable(
        tests_liste
        ${TEST_SOURCES}
)

target_include_directories(tests_liste PRIVATE ${PROJECT_SOURCE_DIR} )

target_link_libraries(
        tests_liste
        gtest_main
        gtest
        pthread
)

include(GoogleTest)
gtest_discover_tests(tests_liste)