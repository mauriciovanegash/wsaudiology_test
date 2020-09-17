#****************************************************************************
# Preprocessor directives
#****************************************************************************

GOOGLE_TEST_LIB = gtest
GOOGLE_TEST_INCLUDE = /usr/local/include

CXX = g++
CXXFLAGS = -c -Wall -I $(GOOGLE_TEST_INCLUDE)
LD_FLAGS = -L /usr/local/lib -l $(GOOGLE_TEST_LIB) -l pthread

#****************************************************************************
# TARGET
#****************************************************************************

TARGET =	run_test

#****************************************************************************
# Directories
#****************************************************************************
DIRECTORIES = ./ ../src

# Add directories to the include and library paths
INCPATH = $(DIRECTORIES)

# Where to store object files.
STORE = unit_test
# Makes a list of the source (.cpp) files.
SOURCE := $(foreach DIR,$(DIRECTORIES),$(wildcard $(DIR)/*.cpp))
SOURCE := $(filter-out ../src/main.cpp, $(SOURCE))
# List of header files.
HEADERS := $(foreach DIR,$(DIRECTORIES),$(wildcard $(DIR)/*.h))
HEADERS += $(foreach DIR,$(DIRECTORIES),$(wildcard $(DIR)/*.hpp))
# Makes a list of the object files that will have to be created.
OBJECTS := $(addprefix $(STORE)/, $(SOURCE:.cpp=.o))

# Specify phony rules. These are rules that are not real files.
.PHONY: all clean dirs

$(TARGET): dirs $(OBJECTS)
		@echo 'Building target: $@'
		@echo 'Invoking: GCC C++ Linker'
		$(CXX) -o $(TARGET) $(OBJECTS) $(LD_FLAGS)
		@echo 'Finished building target: $@'
		@echo ' '

$(STORE)/%.o: %.cpp
	@echo 'Building partial codes: $^'
	$(CXX) $(CXXFLAGS) $(foreach INC,$(INCPATH),-I$(INC)) -c $^ -o $@
	@echo ' '

# Empty rule to prevent problems when a header is deleted.
%.hpp: ;

all: $(TARGET)

# Cleans up the objects, .d files and executables.
clean:
	@echo 'Cleaning all!!!'
	@-rm -f $(foreach DIR,$(DIRECTORIES),$(STORE)/$(DIR)/*.d $(STORE)/$(DIR)/*.dd $(STORE)/$(DIR)/*.o)
	@-rm -f $(TARGET)
	@echo ' '

# Create necessary directories
dirs:
	@-if [ ! -e $(STORE) ]; then mkdir $(STORE); fi;
	@-$(foreach DIR,$(DIRECTORIES), if [ ! -e $(STORE)/$(DIR) ]; then mkdir $(STORE)/$(DIR); fi; )
