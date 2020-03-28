##############################################################################
#
#  Sample Makefile for C++ applications
#    Works for single and multiple file programs.
#    written by Robert Duvall
#    modified by Owen Astrachan
#    and by Garrett Mitchener
# 
##############################################################################

##############################################################################
# Application-specific variables
# EXEC is the name of the executable file
# SRC_FILES is a list of all source code files that must be linked
#           to create the executable
##############################################################################

EXEC      = ROBOT
SRC_FILES = main.cpp
COMP_FILES= ./utils/utils.cpp           \
            ./utils/IoT_Home_Error.cpp  \
            ./Data_Package/Sensor_Package_PraDa.cpp \
            ./Data_Package/IoT_Mesh_Data_Protocol.cpp\
            ./Costum_Error/General_Error.cpp \
            ./MG966/MG966_API.cpp\
            ./ACS712/ACS712_API.cpp\
            ./Robot_Arm_Controller/Robot_Arm_Controller.cpp

#SRC_FILES = application.cc displaycommand.cc filelister.cc menu.cc \
#        menuitem.cc pixmap.cc quitcommand.cc readcommand.cc \
#        usepix.cc


##############################################################################
# Where to find course related files
# COURSE_DIR is where various header files (.h) and library files (.so and .a)
# are found.  LIB_DIR is where other libraries not specific to the course
# are kept.

# for CS machines
# COURSE_DIR = /usr/project/courses/cps108/lib
# LIB_DIR     = /usr/local/lib

# for acpub machines
COURSE_DIR = -I./utils/include/       \
             -I./Data_Package/include/  \
	     -I./Costum_Error/include/  \
             -I./MG966/include/  \
             -I./ACS712/include/  \
             -I./Robot_Arm_Controller/include/  \

LIB_DIR     = /usr/include/          
	      		
	      

##############################################################################
# Compiler specifications
# These match the variable names given in /usr/share/lib/make/make.rules
# so that make's generic rules work to compile our files.
# gmake prefers CXX and CXXFLAGS for c++ programs
##############################################################################
# Which compiler should be used
CXX = g++
CC = $(CXX)


# What flags should be passed to the C pre-processor
#   In other words, where should we look for files to include - note,
#   you should never need to include compiler specific directories here
#   because each compiler already knows where to look for its system
#   files (unless you want to override the defaults)

CPPFLAGS        = -I. \
 		          $(COURSE_DIR)


# What flags should be passed to the compiler

DEBUG_LEVEL     = -g
EXTRA_CCFLAGS   = -Wall
CXXFLAGS        = $(DEBUG_LEVEL) $(EXTRA_CCFLAGS)
CCFLAGS         = $(CXXFLAGS) $(CPPFLAGS)

# What flags should be passed to the linker
#   In other words, where should we look for libraries to link with - note,
#   you should never need to include compiler specific directories here
#   because each compiler already knows where to look for its system files.

LDFLAGS         = -L. \
                  -L$(COURSE_DIR) \
                  -R $(LIB_DIR):$(COURSE_DIR)

# What libraries should be linked with.
# For example, -lm links with libm.so, the math library.
# If you make a library of your own, say, libscandir.a, you have to link it
# in by adding -lscandir here.

LDLIBS          = -lwiringPi -lm  -lpthread

# All source files have associated object files.
# This line sets `OFILES' to have the same value as `SRC_FILES' but
# with all the .cc's changed into .o's.
O_FILES         = $(SRC_FILES:%.cpp=%.o)


###########################################################################
# Additional rules make should know about in order to compile our files
###########################################################################
# all is the default rule
all: $(EXEC)


# exec depends on the object files
# It is made automagically using the LDFLAGS and LOADLIBES variables.
# The .o files are made automagically using the CXXFLAGS variable.
$(EXEC): $(O_FILES)

# to use `makedepend', the target is `depend'
depend:
	$(CC) $(CXXFLAGS) $(CPPFLAGS) $(COMP_FILES) $(SRC_FILES) -o $(EXEC)
	#makedepend -- $(CXXFLAGS) -- -Y $(SRC_FILES)

# to make through RPI
depend_rpi:
	$(CC) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS) $(COMP_FILES) $(SRC_FILES) -o $(EXEC)
	#makedepend -- $(CXXFLAGS) -- -Y $(SRC_FILES)

# clean up after you're done
clean:
	$(RM) $(O_FILES) core *.rpo

very-clean: clean
	$(RM) $(EXEC)
