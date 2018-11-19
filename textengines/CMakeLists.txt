if(LIBQWT_ENABLE_MATHML)
	add_subdirectory(mathml)
endif()




#include_directories(../src)
#
#set(qwt_mathml_SRCS
#  mathml/qwt_mathml_text_engine.cpp
#  mathml/qwt_mml_document.cpp
#)
#
#add_library(qwt_mathml ${qwt_mathml_SRCS})
#target_link_libraries(qwt_mathml qwt ${QT_LIBS})
