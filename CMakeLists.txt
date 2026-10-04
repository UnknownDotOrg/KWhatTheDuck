cmake_minimum_required(VERSION 3.16)

project(KWhatTheDuck VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ECM 6.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(KF6 REQUIRED COMPONENTS CoreAddons)

qt_standard_project_setup()

qt_add_executable(kwhattheduck
    main.cpp
)

target_link_libraries(kwhattheduck
    PRIVATE
        Qt6::Widgets
        KF6::CoreAddons
)

install(TARGETS kwhattheduck
    ${KDE_INSTALL_TARGETS_DEFAULT_ARGS}
)

install(
    FILES org.unknowndotorg.kwhattheduck.desktop
    DESTINATION ${KDE_INSTALL_APPDIR}
)

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "kwhattheduck")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "WHAT THE DUCK")
set(CPACK_PACKAGE_CONTACT "UnknownDotOrg")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "UnknownDotOrg")
set(CPACK_DEBIAN_PACKAGE_SECTION "utils")
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)

include(CPack)
