CC = g++
CCFLAGS = -O3 -Wall -std=c++0x
OUTDIR = ./bin
TARGET = xcom.exe
LIBRARIES = -lopengl32 -lgdi32

#======================================================
# Build all source (*.cpp) files in the root directory
# and one level deep.  If more levels are needed, add to
# the SOURCES list here.
#======================================================
SOURCES = $(sort $(strip $(wildcard *.cpp) $(wildcard */*.cpp)))

define BUILD_SOURCE =
OBJECTS += $(OUTDIR)/$(basename $(notdir $(1))).o
$(filter-out \,$(shell $(CC) $(CCFLAGS) -MM $(1) -MT $(OUTDIR)/$(basename $(notdir $(1))).o))
	$(CC) $(CCFLAGS) -c $(1) -o $(OUTDIR)/$(basename $(notdir $(1))).o
endef

$(foreach file,$(SOURCES),$(eval $(call BUILD_SOURCE,$(file))))

#======================================================
# Primary output.  Make output directory is dependency
# so that it will get created if it does not already exist.
# Since the BUILD_SOURCE template must be expanded by the
# preceding foreach statement, this cannot be the first
# target in the file; therefore we need to override the
# default goal to this target.
#======================================================
install: OUTDIR $(OBJECTS)
	$(CC) $(CCFLAGS) $(OBJECTS) -o $(OUTDIR)/$(TARGET) $(LIBRARIES)
	copy $(subst /,\,$(OUTDIR))\$(TARGET) $(TARGET)

.DEFAULT_GOAL := install

#======================================================
# The following section contains "phony" commands that
# do no actually build output files.
#======================================================
.PHONY: OUTDIR clean

#======================================================
# Create the output directory if it doesn't already exist.
#======================================================
OUTDIR:
ifeq ($(wildcard $(OUTDIR)),)
	mkdir $(subst /,\,$(OUTDIR))
endif

#======================================================
# Delete intermediate files from output directory and
# delete output directory.  Delete output file from
# root directory if it exists there as post build step.
#======================================================
clean:
ifneq ($(wildcard $(OUTDIR)/*.*),)
	del /Q $(subst /,\,$(OUTDIR))\*.*
endif
ifneq ($(wildcard $(OUTDIR)),)
	rmdir $(subst /,\,$(OUTDIR))
endif
ifneq ($(wildcard $(TARGET)),)
	del $(TARGET)
endif
