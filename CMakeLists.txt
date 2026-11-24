cmake_minimum_required(VERSION 3.16)
project(wipe-clock CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(wipeclock
    src/main.cpp
    src/timer.cpp
    src/reminders.cpp
    src/checklist.cpp
)

target_include_directories(wipeclock PRIVATE include)

if(WIN32)
    target_link_libraries(wipeclock PRIVATE userenv)
endif()
