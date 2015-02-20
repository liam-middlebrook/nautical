find_package(SWIG)
if(SWIG_FOUND)
	include(UseSWIG)

	set(interface_files
		vector2.i
	)
set_source_files_properties(${interface_files} PROPERTIES CPLUSPLUS TRUE)
	function(add_swig_language lang default)
		string(TOUPPER "${lang}" upperlang)
		string(TOLOWER "${lang}" lowerlang)
		option(INTERFACE_${upperlang} "Enable ${lang} SWIG interface" ${default})
		if(INTERFACE_${upperlang})
			add_subdirectory(${lowerlang})
		endif()
	endfunction()

	add_swig_language(Lua TRUE)
	add_swig_language(Perl FALSE)
	add_swig_language(Python TRUE)
endif()
