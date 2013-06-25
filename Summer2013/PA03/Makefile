
GCC = gcc
CFLAGS = -g -Wall -Wshadow
SOURCES = answer03.c pa03.c
TARGET = pa03
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose
SHOW = @echo "You can use gthumb to view the image:"
SHOW = feh -Z -F --force-alias

# -------------------------------------------------------------

.PHONY : all test build clean environment help test01 test02 test03 test04 test05 test06 test07 test08 test09 test10 test11 test12 test13 testXX
.DEFAULT_GOAL:= build

OBJF = obj
OBJS = $(patsubst %.c,$(OBJF)/%.o,$(SOURCES))
TARGET_O3 = $(TARGET)-O3
CORRUPT = "outputs/corrupt.ppm"

-include $(SOURCES:%=$(OBJF)/%.P)

all: | build test

test: | test01 test02 test03 test04 test05 test06 test07 test08 test09 test10 test11 test12 test13

test01: $(TARGET) | environment
	@bin/test.sh ./$(TARGET) images/typing-practice.ee264 images/x.ee264 outputs/find-x.ppm

test02: $(TARGET) | environment
	@bin/test.sh ./$(TARGET) images/typing-practice.ee264 images/k.ee264 outputs/find-k.ppm

test03: $(TARGET) | environment
	@bin/test.sh ./$(TARGET) images/typing-practice.ee264 images/z.ee264 outputs/find-z.ppm

test04: $(TARGET) | environment
	@bin/test.sh ./$(TARGET) images/typing-practice.ee264 images/w.ee264 outputs/find-w.ppm

test05: $(TARGET) | environment
	@bin/test.sh ./$(TARGET) images/typing-practice.ee264 images/corrupt-testcases/incomplete-header.ee264 $(CORRUPT) \
		"test05: file has less than 128 bytes, and thus not enough to read a complete header."

test06: $(TARGET) | environment
	@bin/test.sh ./$(TARGET) images/typing-practice.ee264 images/corrupt-testcases/check-magic-bits.ee264 $(CORRUPT) \
		"test06: file has corrupted magic bits."

test07: $(TARGET) | environment
	@bin/test.sh ./$(TARGET) images/typing-practice.ee264 images/corrupt-testcases/width0.ee264 $(CORRUPT) \
		"test07: file header specifies 0 width, which is an error that you must check for."

test08: $(TARGET) | environment
	@bin/test.sh ./$(TARGET) images/typing-practice.ee264 images/corrupt-testcases/height0.ee264 $(CORRUPT) \
		"test08: file header specifies 0 height, which is an error that you must check for."

test09: $(TARGET) | environment
	@bin/test.sh ./$(TARGET) images/typing-practice.ee264 images/corrupt-testcases/big-width-height.ee264 $(CORRUPT) \
		"test09: file header has crazy values for width and height which should cause malloc to fail."

test10: $(TARGET) | environment
	@bin/test.sh ./$(TARGET) images/typing-practice.ee264 images/corrupt-testcases/bad-comment-len.ee264 $(CORRUPT) \
		"test10: file header has a crazy value for the comment length which will either cause malloc to fail, or you will fail to find enough bytes in the file to read the comment."

test11: $(TARGET) | environment
	@bin/test.sh ./$(TARGET) images/typing-practice.ee264 images/corrupt-testcases/comment-has-no-null-byte.ee264 $(CORRUPT) \
		"test11: comment (in file) does not end with a null-byte, which can cause serious problems."

test12: $(TARGET) | environment
	@bin/test.sh ./$(TARGET) images/typing-practice.ee264 images/corrupt-testcases/height-wrong.ee264 $(CORRUPT) \
		"test12: file header specifies the wrong image height, meaning that you will not find the end of file when you expect to."

test13: $(TARGET) | environment
	@bin/test.sh ./$(TARGET) images/typing-practice.ee264 images/corrupt-testcases/incomplete-image.ee264 $(CORRUPT) \
		"test13: file is missing some data from the end"

testXX: $(TARGET_O3) | environment
	@bin/test.sh ./$(TARGET_O3) images/treasure-map.ee264 images/pentagram.ee264 outputs/find-pentagram.ppm


build: $(TARGET)

clean:
	@cd $(CURDIR)
	rm -rf $(TARGET) $(TARGET_O3) $(OBJF) output/typing.ppm output/memoutput 

environment:
	@mkdir -p outputs	
	@mkdir -p $(OBJF)

help:
	@echo
	@echo "   make             build $(TARGET)"
	@echo "   make all         build and test"
	@echo "   make test        run all testcases"
	@echo "   make clean       start from scratch"
	@echo
	@echo "   Temporary files written to ./$(OBJF) "
	@echo "   Outputs: output/output and output/memoutput "
	@echo "   You can use gthumb to view output files. Expected output in expected/*.ppm"
	@echo 
	@echo "   Testcases: "
	@echo
	@echo "      test01 => test 04  are valid input."
	@echo "      test05: input file is too small to contain a valid header."
	@echo "      test06: input file does not have the magic bits set correctly."
	@echo "      test07: input file header has 0 width. (How can an image have no width?)"
	@echo "      test08: input file header has 0 height."
	@echo "      test09: input file header has width and height values that will cause malloc to fail"
	@echo "      test10: input file header has a crazy value for the comment length that should cause problems"
	@echo "      test11: input file comment does not end in a NULL byte. You must check for this."
	@echo "      test12: input file header has too small height, which means you will not find the"
	@echo "              end-of-file in the specified place"
	@echo "      test13: input file is missing data from the end of file, so you will not be able to"
	@echo "              read all the specified pixels"
	@echo

$(TARGET): $(OBJS) | environment
	$(GCC) $(CFLAGS) $(OBJS) -o $@

$(TARGET_O3): $(SOURCES) | environment
	@echo "Building optimized version of $(TARGET): $(TARGET_O3)"
	$(GCC) -O3 $(SOURCES) -o $@

$(OBJF)/%.o: %.c | environment
	@$(GCC) -MM $(CFLAGS) $< | sed 's,^\([^ ]\),$(OBJF)\/\1,g' | sed '$$ s,$$, \\,' > $(OBJF)/$<.P
	$(GCC) $(CFLAGS) -c -o $@ $<


