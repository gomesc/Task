set(this_module_name "queue_element")

if(UNITTEST)

	add_library(${this_module_name}_lib STATIC
        src/main.c
    )

    target_include_directories(${this_module_name}_lib PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/src
        ${CMAKE_CURRENT_LIST_DIR}/tests/mocks
        ${CMAKE_CURRENT_LIST_DIR}/tests
    )

    add_executable(
        test_${this_module_name}
        tests/test_${this_module_name}.cpp			
        tests/mocks/mock_${this_module_name}.cpp
    )

    target_include_directories(test_${this_module_name} PRIVATE tests tests/mocks)

    target_link_libraries(
        test_${this_module_name}
        gtest_main
        ${this_module_name}_lib
        gmock
    )

    add_test(NAME testsuite_${this_module_name} COMMAND test_${this_module_name})

else()
    if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/genlists.cmake")
	    include("${CMAKE_CURRENT_LIST_DIR}/genlists.cmake")
    endif()

    add_library(${this_module_name}_lib ${files})

    # Add module variant folder, if defined
    if (this_module_cfg)
        if (NOT ${this_module_cfg} STREQUAL "") 
            LIST(APPEND this_include_directories 
                adapt/${this_module_cfg}/
            )
        endif()  
    endif()

    target_include_directories(${this_module_name}_lib PUBLIC ${this_include_directories})
    target_link_libraries(${this_module_name}_lib)                        

    set(target_link_libs_list "${target_link_libs_list};${this_module_name}_lib"               PARENT_SCOPE)
endif()