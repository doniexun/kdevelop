set( noprojectincludesanddefines_SRCS
        noprojectcustomincludepaths.cpp
        noprojectincludepathsmanager.cpp
   )

ki18n_wrap_ui( noprojectincludesanddefines_SRCS
        noprojectcustomincludepaths.ui )

add_library(kdevnoprojectincludesanddefines STATIC
        ${noprojectincludesanddefines_SRCS}
    )

target_link_libraries( kdevnoprojectincludesanddefines
LINK_PRIVATE
    KDev::Util
    KDev::Language
    ${KDE4_THREADWEAVER_LIBRARIES}
)

set_target_properties(kdevnoprojectincludesanddefines PROPERTIES POSITION_INDEPENDENT_CODE ON)
