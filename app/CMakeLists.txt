find_package(KF5Plasma)
set_package_properties(KF5Plasma PROPERTIES
    PURPOSE "Plasma libraries for enabling the plasma addons"
    URL "http://www.kde.org"
    TYPE OPTIONAL)
if(KF5Plasma_FOUND)
    add_subdirectory(plasma)
endif()

find_package(SharedMimeInfo REQUIRED)

option(KDEVELOP_SINGLE_APP "Use QtSingleApplication as KDevelop's base" OFF)

set(singleapp_SRCS qtlocalpeer.cpp qtsingleapplication.cpp qtlockedfile.cpp)
if(WIN32)
    set(singleapp_SRCS ${singleapp_SRCS} qtlockedfile_win.cpp)
else()
    set(singleapp_SRCS ${singleapp_SRCS} qtlockedfile_unix.cpp)
endif()

set(kdevelop_SRCS  main.cpp kdevideextension.cpp)
if(KDEVELOP_SINGLE_APP)
    set(kdevelop_SRCS ${kdevelop_SRCS} ${singleapp_SRCS})
endif()

qt5_add_resources(kdevelop_SRCS kdevelop.qrc)

#TODO: remove CMAKE_CURRENT_SOURCE_DIR prefix when ECM is fixed
set(kdevelop_ICONS
    ${CMAKE_CURRENT_SOURCE_DIR}/icons/16-apps-kdevelop.png
    ${CMAKE_CURRENT_SOURCE_DIR}/icons/32-apps-kdevelop.png
    ${CMAKE_CURRENT_SOURCE_DIR}/icons/48-apps-kdevelop.png
    ${CMAKE_CURRENT_SOURCE_DIR}/icons/64-apps-kdevelop.png
    ${CMAKE_CURRENT_SOURCE_DIR}/icons/128-apps-kdevelop.png
    ${CMAKE_CURRENT_SOURCE_DIR}/icons/256-apps-kdevelop.png
)

ecm_install_icons(ICONS ${kdevelop_ICONS}
    DESTINATION ${ICON_INSTALL_DIR})
    
ecm_add_app_icon(kdevelop_SRCS ICONS
    ${kdevelop_ICONS})

qt5_add_resources(kdevelop_SRCS kdevelop.qrc)
add_executable(kdevelop ${kdevelop_SRCS} )

target_link_libraries(kdevelop
    KDev::Interfaces
    KDev::Shell
    KDev::Util

    KF5::Declarative
    KF5::IconThemes
    KF5::Crash
)
IF(APPLE)
    target_link_libraries(kdevelop "-framework CoreFoundation")
ENDIF()

install(TARGETS kdevelop ${KDE_INSTALL_TARGETS_DEFAULT_ARGS} )

install(FILES kdevelop! DESTINATION bin PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_READ WORLD_EXECUTE WORLD_READ)

if (APPLE)
    # the MacOSX bundle display name property (CFBundleDisplayName) is not currently supported by cmake,
    # so has to be set for all targets in this cmake file
    set(MACOSX_BUNDLE_DISPLAY_NAME KDevelop)
    # We provide our own Info.plist to disable AppNap for KDevelop:
    set_target_properties(kdevelop PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist.in)
    set_target_properties(kdevelop PROPERTIES MACOSX_BUNDLE_GUI_IDENTIFIER "org.kde.KDevelop")
    set_target_properties(kdevelop PROPERTIES MACOSX_BUNDLE_BUNDLE_NAME "KDevelop")
    set_target_properties(kdevelop PROPERTIES MACOSX_BUNDLE_DISPLAY_NAME "KDevelop")
    set_target_properties(kdevelop PROPERTIES MACOSX_BUNDLE_INFO_STRING "The KDevelop Integrated Development Environment")
    set_target_properties(kdevelop PROPERTIES MACOSX_BUNDLE_LONG_VERSION_STRING "KDevelop ${KDEVELOP_VERSION_MAJOR}.${KDEVELOP_VERSION_MINOR}")
    set_target_properties(kdevelop PROPERTIES MACOSX_BUNDLE_SHORT_VERSION_STRING "${KDEVELOP_VERSION_MAJOR}.${KDEVELOP_VERSION_MINOR}")
    set_target_properties(kdevelop PROPERTIES MACOSX_BUNDLE_BUNDLE_VERSION "${KDEVELOP_VERSION_MAJOR}.${KDEVELOP_VERSION_MINOR}")
    set_target_properties(kdevelop PROPERTIES MACOSX_BUNDLE_ICON_FILE "kdevelop_SRCS.icns")
    set_target_properties(kdevelop PROPERTIES MACOSX_BUNDLE_COPYRIGHT "KDevelop Team")
endif (APPLE)


########### install files ###############

install( PROGRAMS org.kde.kdevelop.desktop  DESTINATION  ${KDE_INSTALL_APPDIR} )
install( PROGRAMS org.kde.kdevelop_ps.desktop  DESTINATION  ${KDE_INSTALL_APPDIR} )
install( FILES kdevelop.notifyrc DESTINATION ${KDE_INSTALL_KNOTIFY5RCDIR} )
install( FILES kdevelop.xml kdevelopinternal.xml DESTINATION ${KDE_INSTALL_MIMEDIR} )
update_xdg_mimetypes( ${KDE_INSTALL_MIMEDIR} )
