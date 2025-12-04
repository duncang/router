cmake_minimum_required(VERSION 3.28)

project(router)

add_executable(server)
add_executable(main)
add_executable(tests)
add_library(crc32)

target_sources(server
    PRIVATE
        server.c
)

target_sources(main
    PRIVATE
        main.c
)

target_link_libraries(main crc32)

target_sources(crc32
    PRIVATE
        crc32.c
)

target_sources(tests 
    PRIVATE 
        tests.c 
)

target_link_libraries(tests cmocka crc32)


