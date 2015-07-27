cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

#######################
# Main
#######################

set(SOURCE    
    main/main.cpp
)

add_executable(main ${SOURCE})

#######################
# Main
#######################

set(TEST_SOURCE    
    test/main_test.cpp
)

add_executable(main_test ${SOURCE})

target_link_libraries(main_test gtest_main)

add_test(main_test main_test)
