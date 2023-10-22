cmake_minimum_required (VERSION 3.28) # Untested with earlier versions...
project (BeginningCpp LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

file( GLOB workarounds "Workarounds/*.h" )
add_library(Workarounds STATIC ${workarounds})
set_target_properties(Workarounds PROPERTIES LINKER_LANGUAGE CXX)

if(MSVC)
configure_file("Workarounds/Directory.Build.props" "Directory.Build.props" COPYONLY)
endif()

file( GLOB chapter_dirs Examples/* Exercises/*)
foreach( chapter_dir ${chapter_dirs} )
	if( IS_DIRECTORY ${chapter_dir} AND chapter_dir  )
	    get_filename_component( folder ${chapter_dir} NAME )
		if( folder MATCHES "^Chapter.*" OR folder MATCHES "^Appendix.*")
			file( GLOB children ${chapter_dir}/* )
			foreach( child ${children} )
				get_filename_component( project_name ${child} NAME_WE )

				if( IS_DIRECTORY ${child} )
					file( GLOB grand_children ${child}/* )
					add_executable( ${project_name} ${grand_children} )
				else()
					add_executable( ${project_name} ${child} )
				endif()
				
				target_include_directories(${project_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Workarounds/)
				if(MSVC)
					target_compile_options(${project_name} PRIVATE /W4 /w34062 /FIworkarounds.h)
				else() # GCC or Clang (untested)
					target_compile_options(${project_name} PRIVATE -include workarounds.h)
				endif()
				
				set_property(TARGET ${project_name} PROPERTY FOLDER ${folder}) 
			endforeach()
		endif()
	endif()
endforeach()