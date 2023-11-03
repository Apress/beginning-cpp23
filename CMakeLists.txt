cmake_minimum_required (VERSION 3.28)
project (BeginningCpp LANGUAGES CXX)

set(MY_EXERCISES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/MyExercises CACHE PATH
	"Location for generated empty source files to start from when solving exercises")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
SET(CMAKE_SUPPRESS_REGENERATION YES) # We prefer CMake GUI to generate CMake files...

# Function to inject workarounds through forced #includes...
function(inject_workarounds target)
	target_include_directories(${target} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Workarounds/)
	if(MSVC)
		target_compile_options(${target} PRIVATE /W4 /w34062 /FIworkarounds.h)
	else() # GCC or Clang (untested)
		target_compile_options(${target} PRIVATE -include workarounds.h)
	endif()
endfunction()

# Add source code of the workarounds to the solution
file( GLOB workarounds "Workarounds/*.h" )
add_library(Workarounds STATIC ${workarounds})
set_target_properties(Workarounds PROPERTIES LINKER_LANGUAGE CXX)

# Enable Scan Sources for Module Dependencies property of Visual Studio
if(MSVC)
	configure_file("Workarounds/Directory.Build.props" "Directory.Build.props" COPYONLY)
endif()

function(add_project name dir files chapter)
	add_executable( ${name} ${files} )
	inject_workarounds(${name})
	
	source_group(TREE ${dir} FILES ${files})
	if (dir MATCHES ".*Examples.*")
		set_target_properties(${name} PROPERTIES FOLDER ${chapter}/Examples)
	else()
		set_target_properties(${name} PROPERTIES FOLDER ${chapter}/Exercises)
	endif()
endfunction()

file( GLOB chapter_dirs Examples/* Exercises/*)
foreach( chapter_dir ${chapter_dirs} )
	if( IS_DIRECTORY ${chapter_dir} AND chapter_dir  )
	    get_filename_component( chapter ${chapter_dir} NAME )
		if( chapter MATCHES "^Chapter.*" OR chapter MATCHES "^Appendix.*")
			file( GLOB children ${chapter_dir}/* )
			foreach( child ${children} )
				get_filename_component( project_name ${child} NAME_WE )

				if( IS_DIRECTORY ${child} )
					file( GLOB grand_children ${child}/* )
					add_project(${project_name} ${child} "${grand_children}" ${chapter})
				else()
					add_project(${project_name} ${chapter_dir} ${child} ${chapter})
				endif()
				
				if (project_name MATCHES "Soln(.+_..).*")
					set(exercise_name Exer${CMAKE_MATCH_1})
					if (NOT TARGET ${exercise_name})
						if (IS_DIRECTORY ${child})
							set(my_exercise_subdir ${exercise_name})
						else()
							set(my_exercise_subdir "")
						endif()
						set(my_exercise_dir ${MY_EXERCISES_DIR}/${chapter}/${my_exercise_subdir})
						set(my_exercise_file_name ${my_exercise_dir}/${exercise_name}.cpp)
						
						if (NOT EXISTS ${my_exercise_file_name})
							file(WRITE ${my_exercise_file_name} "import std;\n\nint main()\n{\n}")
						endif()
						
						if (IS_DIRECTORY ${child})
							file(GLOB exercise_files ${my_exercise_dir}/*)
						else()
							set(exercise_files ${my_exercise_file_name})
						endif()
						
						add_project(${exercise_name} ${my_exercise_dir} "${exercise_files}" ${chapter})
					endif()
				endif()
			endforeach()
		endif()
	endif()
endforeach()