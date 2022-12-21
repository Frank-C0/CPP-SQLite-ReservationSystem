cmake_minimum_required(VERSION 3.2)

project(CReservSystem)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

# set(CRESERV_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/CReserv)
set(SRC_DIR ${PROJECT_SOURCE_DIR})
set(CReserv_DIR ${SRC_DIR}/CReservSystem)
set(MODEL_DIR ${CReserv_DIR}/model)
set(RESERVATION_GUI_DIR ${SRC_DIR}/ReservationGUI)

set(CRESERV_FILES 
    ${SRC_DIR}/main.cpp
    ${CReserv_DIR}/creservsystem.cpp
    ${RESERVATION_GUI_DIR}/mainwindow.cpp
)

set(CMAKE_AUTOMOC ON)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)


add_executable(CReservSystem
    ${CRESERV_FILES}
)

target_link_libraries(CReservSystem Qt5::Widgets Qt5::Sql)

