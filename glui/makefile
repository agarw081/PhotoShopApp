UNAME = $(shell uname)

CC = g++

OPTS=-g
OPTS=-O0



CPPFLAGS += $(OPTS) -Wall
CPPFLAGS += -I./ -I./include

LIBGLUI = -L./lib -lglui


ifeq ($(UNAME), Darwin)
	LIBS += -framework glut -framework opengl
else
	LIBS += -lglut -lGL -lGLU
endif


CPPFILES += glui_add_controls.cpp
CPPFILES += glui_string.cpp
CPPFILES += glui.cpp
CPPFILES += glui_bitmap_img_data.cpp
CPPFILES += glui_bitmaps.cpp
CPPFILES += glui_button.cpp
CPPFILES += glui_edittext.cpp
CPPFILES += glui_commandline.cpp
CPPFILES += glui_checkbox.cpp
CPPFILES += glui_node.cpp
CPPFILES += glui_radio.cpp
CPPFILES += glui_statictext.cpp
CPPFILES += glui_panel.cpp
CPPFILES += glui_separator.cpp
CPPFILES += glui_spinner.cpp
CPPFILES += glui_control.cpp
CPPFILES += glui_column.cpp
CPPFILES += glui_translation.cpp
CPPFILES += glui_rotation.cpp
CPPFILES += glui_mouse_iaction.cpp
CPPFILES += glui_listbox.cpp
CPPFILES += glui_rollout.cpp
CPPFILES += glui_window.cpp
CPPFILES += arcball.cpp
CPPFILES += algebra3.cpp
CPPFILES += quaternion.cpp
CPPFILES += viewmodel.cpp
CPPFILES += glui_treepanel.cpp
CPPFILES += glui_tree.cpp
CPPFILES += glui_textbox.cpp
CPPFILES += glui_scrollbar.cpp
CPPFILES += glui_list.cpp
CPPFILES += glui_filebrowser.cpp

SOURCES=$(addprefix ./src/,  $(CPPFILES))

OBJECTS = $(addprefix ./build/,  $(CPPFILES:.cpp=.o)) 

GLUI_LIB = lib/libglui.a

all: setup $(GLUI_LIB) 

setup: build lib

build:
	mkdir -p build
	mkdir -p lib

$(GLUI_LIB): $(OBJECTS)
	ar -r $(GLUI_LIB) $(OBJECTS)

build/%.o: src/%.cpp
	$(CXX) $(CPPFLAGS) -c -o $@ $<

.o:
	$(CXX) $(CPPFLAGS) -c $<

clean:
	\rm -rf build lib
