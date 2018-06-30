


add_library( Myjob SHARED
    1.cpp
    transform.cpp
)

target_link_libraries( Myjob
    ${MY_PARTY_LIBS}
)
