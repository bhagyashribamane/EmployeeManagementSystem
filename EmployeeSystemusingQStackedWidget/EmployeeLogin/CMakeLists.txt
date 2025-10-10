cmake_minimum_required(VERSION 3.19)
project(EmployeeLogin LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(EmployeeLogin
    WIN32 MACOSX_BUNDLE
    main.cpp
    employeelogin.cpp
    employeelogin.h
    employeelogin.ui
    employeedashboard.cpp
    employeedashboard.h
    employeedashboard.ui
)

target_link_libraries(EmployeeLogin
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS EmployeeLogin
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET EmployeeLogin
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
