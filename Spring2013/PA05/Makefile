GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = answer05.o pa05.o
HDRS = pa05.h
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

pa05: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

grade: pa05
	perl grader.pl 4 2 10 10 10 10 10 10 10 10 10 10 10

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f pa05 $(OBJS) outputs/* memoutputs/*

test0:
	@$(VALGRIND) --log-file=memoutputs/memoutput0 ./pa05 my_strlen inputs/input0 outputs/output0_my_strlen
	@diff -q outputs/output0_my_strlen expected/expected0_my_strlen

test1:
	@$(VALGRIND) --log-file=memoutputs/memoutput1 ./pa05 my_strlen inputs/input1 outputs/output1_my_strlen
	@diff -q outputs/output1_my_strlen expected/expected1_my_strlen

test2:
	@$(VALGRIND) --log-file=memoutputs/memoutput2 ./pa05 my_strlen inputs/input2 outputs/output2_my_strlen
	@diff -q outputs/output2_my_strlen expected/expected2_my_strlen

test3:
	@$(VALGRIND) --log-file=memoutputs/memoutput3 ./pa05 my_strlen inputs/input3 outputs/output3_my_strlen
	@diff -q outputs/output3_my_strlen expected/expected3_my_strlen

test4:
	@$(VALGRIND) --log-file=memoutputs/memoutput4 ./pa05 my_strlen inputs/input4 outputs/output4_my_strlen
	@diff -q outputs/output4_my_strlen expected/expected4_my_strlen

test5:
	@$(VALGRIND) --log-file=memoutputs/memoutput5 ./pa05 my_strlen inputs/input5 outputs/output5_my_strlen
	@diff -q outputs/output5_my_strlen expected/expected5_my_strlen

test6:
	@$(VALGRIND) --log-file=memoutputs/memoutput6 ./pa05 my_strlen inputs/input6 outputs/output6_my_strlen
	@diff -q outputs/output6_my_strlen expected/expected6_my_strlen

test7:
	@$(VALGRIND) --log-file=memoutputs/memoutput7 ./pa05 my_strlen inputs/input7 outputs/output7_my_strlen
	@diff -q outputs/output7_my_strlen expected/expected7_my_strlen

test8:
	@$(VALGRIND) --log-file=memoutputs/memoutput8 ./pa05 my_strlen inputs/input8 outputs/output8_my_strlen
	@diff -q outputs/output8_my_strlen expected/expected8_my_strlen

test9:
	@$(VALGRIND) --log-file=memoutputs/memoutput9 ./pa05 my_strlen inputs/input9 outputs/output9_my_strlen
	@diff -q outputs/output9_my_strlen expected/expected9_my_strlen

test10:
	@$(VALGRIND) --log-file=memoutputs/memoutput10 ./pa05 my_countchar inputs/input0 outputs/output0_my_countchar
	@diff -q outputs/output0_my_countchar expected/expected0_my_countchar

test11:
	@$(VALGRIND) --log-file=memoutputs/memoutput11 ./pa05 my_countchar inputs/input1 outputs/output1_my_countchar
	@diff -q outputs/output1_my_countchar expected/expected1_my_countchar

test12:
	@$(VALGRIND) --log-file=memoutputs/memoutput12 ./pa05 my_countchar inputs/input2 outputs/output2_my_countchar
	@diff -q outputs/output2_my_countchar expected/expected2_my_countchar

test13:
	@$(VALGRIND) --log-file=memoutputs/memoutput13 ./pa05 my_countchar inputs/input3 outputs/output3_my_countchar
	@diff -q outputs/output3_my_countchar expected/expected3_my_countchar

test14:
	@$(VALGRIND) --log-file=memoutputs/memoutput14 ./pa05 my_countchar inputs/input4 outputs/output4_my_countchar
	@diff -q outputs/output4_my_countchar expected/expected4_my_countchar

test15:
	@$(VALGRIND) --log-file=memoutputs/memoutput15 ./pa05 my_countchar inputs/input5 outputs/output5_my_countchar
	@diff -q outputs/output5_my_countchar expected/expected5_my_countchar

test16:
	@$(VALGRIND) --log-file=memoutputs/memoutput16 ./pa05 my_countchar inputs/input6 outputs/output6_my_countchar
	@diff -q outputs/output6_my_countchar expected/expected6_my_countchar

test17:
	@$(VALGRIND) --log-file=memoutputs/memoutput17 ./pa05 my_countchar inputs/input7 outputs/output7_my_countchar
	@diff -q outputs/output7_my_countchar expected/expected7_my_countchar

test18:
	@$(VALGRIND) --log-file=memoutputs/memoutput18 ./pa05 my_countchar inputs/input8 outputs/output8_my_countchar
	@diff -q outputs/output8_my_countchar expected/expected8_my_countchar

test19:
	@$(VALGRIND) --log-file=memoutputs/memoutput19 ./pa05 my_countchar inputs/input9 outputs/output9_my_countchar
	@diff -q outputs/output9_my_countchar expected/expected9_my_countchar

test20:
	@$(VALGRIND) --log-file=memoutputs/memoutput20 ./pa05 my_strupper inputs/input0 outputs/output0_my_strupper
	@diff -q outputs/output0_my_strupper expected/expected0_my_strupper

test21:
	@$(VALGRIND) --log-file=memoutputs/memoutput21 ./pa05 my_strupper inputs/input1 outputs/output1_my_strupper
	@diff -q outputs/output1_my_strupper expected/expected1_my_strupper

test22:
	@$(VALGRIND) --log-file=memoutputs/memoutput22 ./pa05 my_strupper inputs/input2 outputs/output2_my_strupper
	@diff -q outputs/output2_my_strupper expected/expected2_my_strupper

test23:
	@$(VALGRIND) --log-file=memoutputs/memoutput23 ./pa05 my_strupper inputs/input3 outputs/output3_my_strupper
	@diff -q outputs/output3_my_strupper expected/expected3_my_strupper

test24:
	@$(VALGRIND) --log-file=memoutputs/memoutput24 ./pa05 my_strupper inputs/input4 outputs/output4_my_strupper
	@diff -q outputs/output4_my_strupper expected/expected4_my_strupper

test25:
	@$(VALGRIND) --log-file=memoutputs/memoutput25 ./pa05 my_strupper inputs/input5 outputs/output5_my_strupper
	@diff -q outputs/output5_my_strupper expected/expected5_my_strupper

test26:
	@$(VALGRIND) --log-file=memoutputs/memoutput26 ./pa05 my_strupper inputs/input6 outputs/output6_my_strupper
	@diff -q outputs/output6_my_strupper expected/expected6_my_strupper

test27:
	@$(VALGRIND) --log-file=memoutputs/memoutput27 ./pa05 my_strupper inputs/input7 outputs/output7_my_strupper
	@diff -q outputs/output7_my_strupper expected/expected7_my_strupper

test28:
	@$(VALGRIND) --log-file=memoutputs/memoutput28 ./pa05 my_strupper inputs/input8 outputs/output8_my_strupper
	@diff -q outputs/output8_my_strupper expected/expected8_my_strupper

test29:
	@$(VALGRIND) --log-file=memoutputs/memoutput29 ./pa05 my_strupper inputs/input9 outputs/output9_my_strupper
	@diff -q outputs/output9_my_strupper expected/expected9_my_strupper

test30:
	@$(VALGRIND) --log-file=memoutputs/memoutput30 ./pa05 my_strlower inputs/input0 outputs/output0_my_strlower
	@diff -q outputs/output0_my_strlower expected/expected0_my_strlower

test31:
	@$(VALGRIND) --log-file=memoutputs/memoutput31 ./pa05 my_strlower inputs/input1 outputs/output1_my_strlower
	@diff -q outputs/output1_my_strlower expected/expected1_my_strlower

test32:
	@$(VALGRIND) --log-file=memoutputs/memoutput32 ./pa05 my_strlower inputs/input2 outputs/output2_my_strlower
	@diff -q outputs/output2_my_strlower expected/expected2_my_strlower

test33:
	@$(VALGRIND) --log-file=memoutputs/memoutput33 ./pa05 my_strlower inputs/input3 outputs/output3_my_strlower
	@diff -q outputs/output3_my_strlower expected/expected3_my_strlower

test34:
	@$(VALGRIND) --log-file=memoutputs/memoutput34 ./pa05 my_strlower inputs/input4 outputs/output4_my_strlower
	@diff -q outputs/output4_my_strlower expected/expected4_my_strlower

test35:
	@$(VALGRIND) --log-file=memoutputs/memoutput35 ./pa05 my_strlower inputs/input5 outputs/output5_my_strlower
	@diff -q outputs/output5_my_strlower expected/expected5_my_strlower

test36:
	@$(VALGRIND) --log-file=memoutputs/memoutput36 ./pa05 my_strlower inputs/input6 outputs/output6_my_strlower
	@diff -q outputs/output6_my_strlower expected/expected6_my_strlower

test37:
	@$(VALGRIND) --log-file=memoutputs/memoutput37 ./pa05 my_strlower inputs/input7 outputs/output7_my_strlower
	@diff -q outputs/output7_my_strlower expected/expected7_my_strlower

test38:
	@$(VALGRIND) --log-file=memoutputs/memoutput38 ./pa05 my_strlower inputs/input8 outputs/output8_my_strlower
	@diff -q outputs/output8_my_strlower expected/expected8_my_strlower

test39:
	@$(VALGRIND) --log-file=memoutputs/memoutput39 ./pa05 my_strlower inputs/input9 outputs/output9_my_strlower
	@diff -q outputs/output9_my_strlower expected/expected9_my_strlower

test40:
	@$(VALGRIND) --log-file=memoutputs/memoutput40 ./pa05 my_strcpy inputs/input0 outputs/output0_my_strcpy
	@diff -q outputs/output0_my_strcpy expected/expected0_my_strcpy

test41:
	@$(VALGRIND) --log-file=memoutputs/memoutput41 ./pa05 my_strcpy inputs/input1 outputs/output1_my_strcpy
	@diff -q outputs/output1_my_strcpy expected/expected1_my_strcpy

test42:
	@$(VALGRIND) --log-file=memoutputs/memoutput42 ./pa05 my_strcpy inputs/input2 outputs/output2_my_strcpy
	@diff -q outputs/output2_my_strcpy expected/expected2_my_strcpy

test43:
	@$(VALGRIND) --log-file=memoutputs/memoutput43 ./pa05 my_strcpy inputs/input3 outputs/output3_my_strcpy
	@diff -q outputs/output3_my_strcpy expected/expected3_my_strcpy

test44:
	@$(VALGRIND) --log-file=memoutputs/memoutput44 ./pa05 my_strcpy inputs/input4 outputs/output4_my_strcpy
	@diff -q outputs/output4_my_strcpy expected/expected4_my_strcpy

test45:
	@$(VALGRIND) --log-file=memoutputs/memoutput45 ./pa05 my_strcpy inputs/input5 outputs/output5_my_strcpy
	@diff -q outputs/output5_my_strcpy expected/expected5_my_strcpy

test46:
	@$(VALGRIND) --log-file=memoutputs/memoutput46 ./pa05 my_strcpy inputs/input6 outputs/output6_my_strcpy
	@diff -q outputs/output6_my_strcpy expected/expected6_my_strcpy

test47:
	@$(VALGRIND) --log-file=memoutputs/memoutput47 ./pa05 my_strcpy inputs/input7 outputs/output7_my_strcpy
	@diff -q outputs/output7_my_strcpy expected/expected7_my_strcpy

test48:
	@$(VALGRIND) --log-file=memoutputs/memoutput48 ./pa05 my_strcpy inputs/input8 outputs/output8_my_strcpy
	@diff -q outputs/output8_my_strcpy expected/expected8_my_strcpy

test49:
	@$(VALGRIND) --log-file=memoutputs/memoutput49 ./pa05 my_strcpy inputs/input9 outputs/output9_my_strcpy
	@diff -q outputs/output9_my_strcpy expected/expected9_my_strcpy

test50:
	@$(VALGRIND) --log-file=memoutputs/memoutput50 ./pa05 my_strncpy inputs/input0 outputs/output0_my_strncpy
	@diff -q outputs/output0_my_strncpy expected/expected0_my_strncpy

test51:
	@$(VALGRIND) --log-file=memoutputs/memoutput51 ./pa05 my_strncpy inputs/input1 outputs/output1_my_strncpy
	@diff -q outputs/output1_my_strncpy expected/expected1_my_strncpy

test52:
	@$(VALGRIND) --log-file=memoutputs/memoutput52 ./pa05 my_strncpy inputs/input2 outputs/output2_my_strncpy
	@diff -q outputs/output2_my_strncpy expected/expected2_my_strncpy

test53:
	@$(VALGRIND) --log-file=memoutputs/memoutput53 ./pa05 my_strncpy inputs/input3 outputs/output3_my_strncpy
	@diff -q outputs/output3_my_strncpy expected/expected3_my_strncpy

test54:
	@$(VALGRIND) --log-file=memoutputs/memoutput54 ./pa05 my_strncpy inputs/input4 outputs/output4_my_strncpy
	@diff -q outputs/output4_my_strncpy expected/expected4_my_strncpy

test55:
	@$(VALGRIND) --log-file=memoutputs/memoutput55 ./pa05 my_strncpy inputs/input5 outputs/output5_my_strncpy
	@diff -q outputs/output5_my_strncpy expected/expected5_my_strncpy

test56:
	@$(VALGRIND) --log-file=memoutputs/memoutput56 ./pa05 my_strncpy inputs/input6 outputs/output6_my_strncpy
	@diff -q outputs/output6_my_strncpy expected/expected6_my_strncpy

test57:
	@$(VALGRIND) --log-file=memoutputs/memoutput57 ./pa05 my_strncpy inputs/input7 outputs/output7_my_strncpy
	@diff -q outputs/output7_my_strncpy expected/expected7_my_strncpy

test58:
	@$(VALGRIND) --log-file=memoutputs/memoutput58 ./pa05 my_strncpy inputs/input8 outputs/output8_my_strncpy
	@diff -q outputs/output8_my_strncpy expected/expected8_my_strncpy

test59:
	@$(VALGRIND) --log-file=memoutputs/memoutput59 ./pa05 my_strncpy inputs/input9 outputs/output9_my_strncpy
	@diff -q outputs/output9_my_strncpy expected/expected9_my_strncpy

test60:
	@$(VALGRIND) --log-file=memoutputs/memoutput60 ./pa05 my_strcat inputs/input0 outputs/output0_my_strcat
	@diff -q outputs/output0_my_strcat expected/expected0_my_strcat

test61:
	@$(VALGRIND) --log-file=memoutputs/memoutput61 ./pa05 my_strcat inputs/input1 outputs/output1_my_strcat
	@diff -q outputs/output1_my_strcat expected/expected1_my_strcat

test62:
	@$(VALGRIND) --log-file=memoutputs/memoutput62 ./pa05 my_strcat inputs/input2 outputs/output2_my_strcat
	@diff -q outputs/output2_my_strcat expected/expected2_my_strcat

test63:
	@$(VALGRIND) --log-file=memoutputs/memoutput63 ./pa05 my_strcat inputs/input3 outputs/output3_my_strcat
	@diff -q outputs/output3_my_strcat expected/expected3_my_strcat

test64:
	@$(VALGRIND) --log-file=memoutputs/memoutput64 ./pa05 my_strcat inputs/input4 outputs/output4_my_strcat
	@diff -q outputs/output4_my_strcat expected/expected4_my_strcat

test65:
	@$(VALGRIND) --log-file=memoutputs/memoutput65 ./pa05 my_strcat inputs/input5 outputs/output5_my_strcat
	@diff -q outputs/output5_my_strcat expected/expected5_my_strcat

test66:
	@$(VALGRIND) --log-file=memoutputs/memoutput66 ./pa05 my_strcat inputs/input6 outputs/output6_my_strcat
	@diff -q outputs/output6_my_strcat expected/expected6_my_strcat

test67:
	@$(VALGRIND) --log-file=memoutputs/memoutput67 ./pa05 my_strcat inputs/input7 outputs/output7_my_strcat
	@diff -q outputs/output7_my_strcat expected/expected7_my_strcat

test68:
	@$(VALGRIND) --log-file=memoutputs/memoutput68 ./pa05 my_strcat inputs/input8 outputs/output8_my_strcat
	@diff -q outputs/output8_my_strcat expected/expected8_my_strcat

test69:
	@$(VALGRIND) --log-file=memoutputs/memoutput69 ./pa05 my_strcat inputs/input9 outputs/output9_my_strcat
	@diff -q outputs/output9_my_strcat expected/expected9_my_strcat

test70:
	@$(VALGRIND) --log-file=memoutputs/memoutput70 ./pa05 my_strncat inputs/input0 outputs/output0_my_strncat
	@diff -q outputs/output0_my_strncat expected/expected0_my_strncat

test71:
	@$(VALGRIND) --log-file=memoutputs/memoutput71 ./pa05 my_strncat inputs/input1 outputs/output1_my_strncat
	@diff -q outputs/output1_my_strncat expected/expected1_my_strncat

test72:
	@$(VALGRIND) --log-file=memoutputs/memoutput72 ./pa05 my_strncat inputs/input2 outputs/output2_my_strncat
	@diff -q outputs/output2_my_strncat expected/expected2_my_strncat

test73:
	@$(VALGRIND) --log-file=memoutputs/memoutput73 ./pa05 my_strncat inputs/input3 outputs/output3_my_strncat
	@diff -q outputs/output3_my_strncat expected/expected3_my_strncat

test74:
	@$(VALGRIND) --log-file=memoutputs/memoutput74 ./pa05 my_strncat inputs/input4 outputs/output4_my_strncat
	@diff -q outputs/output4_my_strncat expected/expected4_my_strncat

test75:
	@$(VALGRIND) --log-file=memoutputs/memoutput75 ./pa05 my_strncat inputs/input5 outputs/output5_my_strncat
	@diff -q outputs/output5_my_strncat expected/expected5_my_strncat

test76:
	@$(VALGRIND) --log-file=memoutputs/memoutput76 ./pa05 my_strncat inputs/input6 outputs/output6_my_strncat
	@diff -q outputs/output6_my_strncat expected/expected6_my_strncat

test77:
	@$(VALGRIND) --log-file=memoutputs/memoutput77 ./pa05 my_strncat inputs/input7 outputs/output7_my_strncat
	@diff -q outputs/output7_my_strncat expected/expected7_my_strncat

test78:
	@$(VALGRIND) --log-file=memoutputs/memoutput78 ./pa05 my_strncat inputs/input8 outputs/output8_my_strncat
	@diff -q outputs/output8_my_strncat expected/expected8_my_strncat

test79:
	@$(VALGRIND) --log-file=memoutputs/memoutput79 ./pa05 my_strncat inputs/input9 outputs/output9_my_strncat
	@diff -q outputs/output9_my_strncat expected/expected9_my_strncat

test80:
	@$(VALGRIND) --log-file=memoutputs/memoutput80 ./pa05 my_strstr inputs/input0 outputs/output0_my_strstr
	@diff -q outputs/output0_my_strstr expected/expected0_my_strstr

test81:
	@$(VALGRIND) --log-file=memoutputs/memoutput81 ./pa05 my_strstr inputs/input1 outputs/output1_my_strstr
	@diff -q outputs/output1_my_strstr expected/expected1_my_strstr

test82:
	@$(VALGRIND) --log-file=memoutputs/memoutput82 ./pa05 my_strstr inputs/input2 outputs/output2_my_strstr
	@diff -q outputs/output2_my_strstr expected/expected2_my_strstr

test83:
	@$(VALGRIND) --log-file=memoutputs/memoutput83 ./pa05 my_strstr inputs/input3 outputs/output3_my_strstr
	@diff -q outputs/output3_my_strstr expected/expected3_my_strstr

test84:
	@$(VALGRIND) --log-file=memoutputs/memoutput84 ./pa05 my_strstr inputs/input4 outputs/output4_my_strstr
	@diff -q outputs/output4_my_strstr expected/expected4_my_strstr

test85:
	@$(VALGRIND) --log-file=memoutputs/memoutput85 ./pa05 my_strstr inputs/input5 outputs/output5_my_strstr
	@diff -q outputs/output5_my_strstr expected/expected5_my_strstr

test86:
	@$(VALGRIND) --log-file=memoutputs/memoutput86 ./pa05 my_strstr inputs/input6 outputs/output6_my_strstr
	@diff -q outputs/output6_my_strstr expected/expected6_my_strstr

test87:
	@$(VALGRIND) --log-file=memoutputs/memoutput87 ./pa05 my_strstr inputs/input7 outputs/output7_my_strstr
	@diff -q outputs/output7_my_strstr expected/expected7_my_strstr

test88:
	@$(VALGRIND) --log-file=memoutputs/memoutput88 ./pa05 my_strstr inputs/input8 outputs/output8_my_strstr
	@diff -q outputs/output8_my_strstr expected/expected8_my_strstr

test89:
	@$(VALGRIND) --log-file=memoutputs/memoutput89 ./pa05 my_strstr inputs/input9 outputs/output9_my_strstr
	@diff -q outputs/output9_my_strstr expected/expected9_my_strstr

test90:
	@$(VALGRIND) --log-file=memoutputs/memoutput90 ./pa05 my_strinsert inputs/input0 outputs/output0_my_strinsert
	@diff -q outputs/output0_my_strinsert expected/expected0_my_strinsert

test91:
	@$(VALGRIND) --log-file=memoutputs/memoutput91 ./pa05 my_strinsert inputs/input1 outputs/output1_my_strinsert
	@diff -q outputs/output1_my_strinsert expected/expected1_my_strinsert

test92:
	@$(VALGRIND) --log-file=memoutputs/memoutput92 ./pa05 my_strinsert inputs/input2 outputs/output2_my_strinsert
	@diff -q outputs/output2_my_strinsert expected/expected2_my_strinsert

test93:
	@$(VALGRIND) --log-file=memoutputs/memoutput93 ./pa05 my_strinsert inputs/input3 outputs/output3_my_strinsert
	@diff -q outputs/output3_my_strinsert expected/expected3_my_strinsert

test94:
	@$(VALGRIND) --log-file=memoutputs/memoutput94 ./pa05 my_strinsert inputs/input4 outputs/output4_my_strinsert
	@diff -q outputs/output4_my_strinsert expected/expected4_my_strinsert

test95:
	@$(VALGRIND) --log-file=memoutputs/memoutput95 ./pa05 my_strinsert inputs/input5 outputs/output5_my_strinsert
	@diff -q outputs/output5_my_strinsert expected/expected5_my_strinsert

test96:
	@$(VALGRIND) --log-file=memoutputs/memoutput96 ./pa05 my_strinsert inputs/input6 outputs/output6_my_strinsert
	@diff -q outputs/output6_my_strinsert expected/expected6_my_strinsert

test97:
	@$(VALGRIND) --log-file=memoutputs/memoutput97 ./pa05 my_strinsert inputs/input7 outputs/output7_my_strinsert
	@diff -q outputs/output7_my_strinsert expected/expected7_my_strinsert

test98:
	@$(VALGRIND) --log-file=memoutputs/memoutput98 ./pa05 my_strinsert inputs/input8 outputs/output8_my_strinsert
	@diff -q outputs/output8_my_strinsert expected/expected8_my_strinsert

test99:
	@$(VALGRIND) --log-file=memoutputs/memoutput99 ./pa05 my_strinsert inputs/input9 outputs/output9_my_strinsert
	@diff -q outputs/output9_my_strinsert expected/expected9_my_strinsert

test100:
	@$(VALGRIND) --log-file=memoutputs/memoutput100 ./pa05 my_strdelete inputs/input0 outputs/output0_my_strdelete
	@diff -q outputs/output0_my_strdelete expected/expected0_my_strdelete

test101:
	@$(VALGRIND) --log-file=memoutputs/memoutput101 ./pa05 my_strdelete inputs/input1 outputs/output1_my_strdelete
	@diff -q outputs/output1_my_strdelete expected/expected1_my_strdelete

test102:
	@$(VALGRIND) --log-file=memoutputs/memoutput102 ./pa05 my_strdelete inputs/input2 outputs/output2_my_strdelete
	@diff -q outputs/output2_my_strdelete expected/expected2_my_strdelete

test103:
	@$(VALGRIND) --log-file=memoutputs/memoutput103 ./pa05 my_strdelete inputs/input3 outputs/output3_my_strdelete
	@diff -q outputs/output3_my_strdelete expected/expected3_my_strdelete

test104:
	@$(VALGRIND) --log-file=memoutputs/memoutput104 ./pa05 my_strdelete inputs/input4 outputs/output4_my_strdelete
	@diff -q outputs/output4_my_strdelete expected/expected4_my_strdelete

test105:
	@$(VALGRIND) --log-file=memoutputs/memoutput105 ./pa05 my_strdelete inputs/input5 outputs/output5_my_strdelete
	@diff -q outputs/output5_my_strdelete expected/expected5_my_strdelete

test106:
	@$(VALGRIND) --log-file=memoutputs/memoutput106 ./pa05 my_strdelete inputs/input6 outputs/output6_my_strdelete
	@diff -q outputs/output6_my_strdelete expected/expected6_my_strdelete

test107:
	@$(VALGRIND) --log-file=memoutputs/memoutput107 ./pa05 my_strdelete inputs/input7 outputs/output7_my_strdelete
	@diff -q outputs/output7_my_strdelete expected/expected7_my_strdelete

test108:
	@$(VALGRIND) --log-file=memoutputs/memoutput108 ./pa05 my_strdelete inputs/input8 outputs/output8_my_strdelete
	@diff -q outputs/output8_my_strdelete expected/expected8_my_strdelete

test109:
	@$(VALGRIND) --log-file=memoutputs/memoutput109 ./pa05 my_strdelete inputs/input9 outputs/output9_my_strdelete
	@diff -q outputs/output9_my_strdelete expected/expected9_my_strdelete

