GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = tree.o pa09.o helper.o
HDRS = tree.h helper.h
VALGRIND = valgrind --tool=memcheck --leak-check=full --verbose

pa09: $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.c.o: $(HDRS)
	$(GCC) $(CFLAGS) -c $*.c

clean:
	rm -f pa09 $(OBJS) outputs/*

grade: pa09
	perl grader.pl 4 2 101

test0: pa09
	@$(VALGRIND) --log-file=outputs/memoutput0 ./pa09 inputs/input0 outputs/output0
	@diff -w outputs/output0 expected/expected0

test1: pa09
	@$(VALGRIND) --log-file=outputs/memoutput1 ./pa09 inputs/input1 outputs/output1
	@diff -w outputs/output1 expected/expected1

test2: pa09
	@$(VALGRIND) --log-file=outputs/memoutput2 ./pa09 inputs/input2 outputs/output2
	@diff -w outputs/output2 expected/expected2

test3: pa09
	@$(VALGRIND) --log-file=outputs/memoutput3 ./pa09 inputs/input3 outputs/output3
	@diff -w outputs/output3 expected/expected3

test4: pa09
	@$(VALGRIND) --log-file=outputs/memoutput4 ./pa09 inputs/input4 outputs/output4
	@diff -w outputs/output4 expected/expected4

test5: pa09
	@$(VALGRIND) --log-file=outputs/memoutput5 ./pa09 inputs/input5 outputs/output5
	@diff -w outputs/output5 expected/expected5

test6: pa09
	@$(VALGRIND) --log-file=outputs/memoutput6 ./pa09 inputs/input6 outputs/output6
	@diff -w outputs/output6 expected/expected6

test7: pa09
	@$(VALGRIND) --log-file=outputs/memoutput7 ./pa09 inputs/input7 outputs/output7
	@diff -w outputs/output7 expected/expected7

test8: pa09
	@$(VALGRIND) --log-file=outputs/memoutput8 ./pa09 inputs/input8 outputs/output8
	@diff -w outputs/output8 expected/expected8

test9: pa09
	@$(VALGRIND) --log-file=outputs/memoutput9 ./pa09 inputs/input9 outputs/output9
	@diff -w outputs/output9 expected/expected9

test10: pa09
	@$(VALGRIND) --log-file=outputs/memoutput10 ./pa09 inputs/input10 outputs/output10
	@diff -w outputs/output10 expected/expected10

test11: pa09
	@$(VALGRIND) --log-file=outputs/memoutput11 ./pa09 inputs/input11 outputs/output11
	@diff -w outputs/output11 expected/expected11

test12: pa09
	@$(VALGRIND) --log-file=outputs/memoutput12 ./pa09 inputs/input12 outputs/output12
	@diff -w outputs/output12 expected/expected12

test13: pa09
	@$(VALGRIND) --log-file=outputs/memoutput13 ./pa09 inputs/input13 outputs/output13
	@diff -w outputs/output13 expected/expected13

test14: pa09
	@$(VALGRIND) --log-file=outputs/memoutput14 ./pa09 inputs/input14 outputs/output14
	@diff -w outputs/output14 expected/expected14

test15: pa09
	@$(VALGRIND) --log-file=outputs/memoutput15 ./pa09 inputs/input15 outputs/output15
	@diff -w outputs/output15 expected/expected15

test16: pa09
	@$(VALGRIND) --log-file=outputs/memoutput16 ./pa09 inputs/input16 outputs/output16
	@diff -w outputs/output16 expected/expected16

test17: pa09
	@$(VALGRIND) --log-file=outputs/memoutput17 ./pa09 inputs/input17 outputs/output17
	@diff -w outputs/output17 expected/expected17

test18: pa09
	@$(VALGRIND) --log-file=outputs/memoutput18 ./pa09 inputs/input18 outputs/output18
	@diff -w outputs/output18 expected/expected18

test19: pa09
	@$(VALGRIND) --log-file=outputs/memoutput19 ./pa09 inputs/input19 outputs/output19
	@diff -w outputs/output19 expected/expected19

test20: pa09
	@$(VALGRIND) --log-file=outputs/memoutput20 ./pa09 inputs/input20 outputs/output20
	@diff -w outputs/output20 expected/expected20

test21: pa09
	@$(VALGRIND) --log-file=outputs/memoutput21 ./pa09 inputs/input21 outputs/output21
	@diff -w outputs/output21 expected/expected21

test22: pa09
	@$(VALGRIND) --log-file=outputs/memoutput22 ./pa09 inputs/input22 outputs/output22
	@diff -w outputs/output22 expected/expected22

test23: pa09
	@$(VALGRIND) --log-file=outputs/memoutput23 ./pa09 inputs/input23 outputs/output23
	@diff -w outputs/output23 expected/expected23

test24: pa09
	@$(VALGRIND) --log-file=outputs/memoutput24 ./pa09 inputs/input24 outputs/output24
	@diff -w outputs/output24 expected/expected24

test25: pa09
	@$(VALGRIND) --log-file=outputs/memoutput25 ./pa09 inputs/input25 outputs/output25
	@diff -w outputs/output25 expected/expected25

test26: pa09
	@$(VALGRIND) --log-file=outputs/memoutput26 ./pa09 inputs/input26 outputs/output26
	@diff -w outputs/output26 expected/expected26

test27: pa09
	@$(VALGRIND) --log-file=outputs/memoutput27 ./pa09 inputs/input27 outputs/output27
	@diff -w outputs/output27 expected/expected27

test28: pa09
	@$(VALGRIND) --log-file=outputs/memoutput28 ./pa09 inputs/input28 outputs/output28
	@diff -w outputs/output28 expected/expected28

test29: pa09
	@$(VALGRIND) --log-file=outputs/memoutput29 ./pa09 inputs/input29 outputs/output29
	@diff -w outputs/output29 expected/expected29

test30: pa09
	@$(VALGRIND) --log-file=outputs/memoutput30 ./pa09 inputs/input30 outputs/output30
	@diff -w outputs/output30 expected/expected30

test31: pa09
	@$(VALGRIND) --log-file=outputs/memoutput31 ./pa09 inputs/input31 outputs/output31
	@diff -w outputs/output31 expected/expected31

test32: pa09
	@$(VALGRIND) --log-file=outputs/memoutput32 ./pa09 inputs/input32 outputs/output32
	@diff -w outputs/output32 expected/expected32

test33: pa09
	@$(VALGRIND) --log-file=outputs/memoutput33 ./pa09 inputs/input33 outputs/output33
	@diff -w outputs/output33 expected/expected33

test34: pa09
	@$(VALGRIND) --log-file=outputs/memoutput34 ./pa09 inputs/input34 outputs/output34
	@diff -w outputs/output34 expected/expected34

test35: pa09
	@$(VALGRIND) --log-file=outputs/memoutput35 ./pa09 inputs/input35 outputs/output35
	@diff -w outputs/output35 expected/expected35

test36: pa09
	@$(VALGRIND) --log-file=outputs/memoutput36 ./pa09 inputs/input36 outputs/output36
	@diff -w outputs/output36 expected/expected36

test37: pa09
	@$(VALGRIND) --log-file=outputs/memoutput37 ./pa09 inputs/input37 outputs/output37
	@diff -w outputs/output37 expected/expected37

test38: pa09
	@$(VALGRIND) --log-file=outputs/memoutput38 ./pa09 inputs/input38 outputs/output38
	@diff -w outputs/output38 expected/expected38

test39: pa09
	@$(VALGRIND) --log-file=outputs/memoutput39 ./pa09 inputs/input39 outputs/output39
	@diff -w outputs/output39 expected/expected39

test40: pa09
	@$(VALGRIND) --log-file=outputs/memoutput40 ./pa09 inputs/input40 outputs/output40
	@diff -w outputs/output40 expected/expected40

test41: pa09
	@$(VALGRIND) --log-file=outputs/memoutput41 ./pa09 inputs/input41 outputs/output41
	@diff -w outputs/output41 expected/expected41

test42: pa09
	@$(VALGRIND) --log-file=outputs/memoutput42 ./pa09 inputs/input42 outputs/output42
	@diff -w outputs/output42 expected/expected42

test43: pa09
	@$(VALGRIND) --log-file=outputs/memoutput43 ./pa09 inputs/input43 outputs/output43
	@diff -w outputs/output43 expected/expected43

test44: pa09
	@$(VALGRIND) --log-file=outputs/memoutput44 ./pa09 inputs/input44 outputs/output44
	@diff -w outputs/output44 expected/expected44

test45: pa09
	@$(VALGRIND) --log-file=outputs/memoutput45 ./pa09 inputs/input45 outputs/output45
	@diff -w outputs/output45 expected/expected45

test46: pa09
	@$(VALGRIND) --log-file=outputs/memoutput46 ./pa09 inputs/input46 outputs/output46
	@diff -w outputs/output46 expected/expected46

test47: pa09
	@$(VALGRIND) --log-file=outputs/memoutput47 ./pa09 inputs/input47 outputs/output47
	@diff -w outputs/output47 expected/expected47

test48: pa09
	@$(VALGRIND) --log-file=outputs/memoutput48 ./pa09 inputs/input48 outputs/output48
	@diff -w outputs/output48 expected/expected48

test49: pa09
	@$(VALGRIND) --log-file=outputs/memoutput49 ./pa09 inputs/input49 outputs/output49
	@diff -w outputs/output49 expected/expected49

test50: pa09
	@$(VALGRIND) --log-file=outputs/memoutput50 ./pa09 inputs/input50 outputs/output50
	@diff -w outputs/output50 expected/expected50

test51: pa09
	@$(VALGRIND) --log-file=outputs/memoutput51 ./pa09 inputs/input51 outputs/output51
	@diff -w outputs/output51 expected/expected51

test52: pa09
	@$(VALGRIND) --log-file=outputs/memoutput52 ./pa09 inputs/input52 outputs/output52
	@diff -w outputs/output52 expected/expected52

test53: pa09
	@$(VALGRIND) --log-file=outputs/memoutput53 ./pa09 inputs/input53 outputs/output53
	@diff -w outputs/output53 expected/expected53

test54: pa09
	@$(VALGRIND) --log-file=outputs/memoutput54 ./pa09 inputs/input54 outputs/output54
	@diff -w outputs/output54 expected/expected54

test55: pa09
	@$(VALGRIND) --log-file=outputs/memoutput55 ./pa09 inputs/input55 outputs/output55
	@diff -w outputs/output55 expected/expected55

test56: pa09
	@$(VALGRIND) --log-file=outputs/memoutput56 ./pa09 inputs/input56 outputs/output56
	@diff -w outputs/output56 expected/expected56

test57: pa09
	@$(VALGRIND) --log-file=outputs/memoutput57 ./pa09 inputs/input57 outputs/output57
	@diff -w outputs/output57 expected/expected57

test58: pa09
	@$(VALGRIND) --log-file=outputs/memoutput58 ./pa09 inputs/input58 outputs/output58
	@diff -w outputs/output58 expected/expected58

test59: pa09
	@$(VALGRIND) --log-file=outputs/memoutput59 ./pa09 inputs/input59 outputs/output59
	@diff -w outputs/output59 expected/expected59

test60: pa09
	@$(VALGRIND) --log-file=outputs/memoutput60 ./pa09 inputs/input60 outputs/output60
	@diff -w outputs/output60 expected/expected60

test61: pa09
	@$(VALGRIND) --log-file=outputs/memoutput61 ./pa09 inputs/input61 outputs/output61
	@diff -w outputs/output61 expected/expected61

test62: pa09
	@$(VALGRIND) --log-file=outputs/memoutput62 ./pa09 inputs/input62 outputs/output62
	@diff -w outputs/output62 expected/expected62

test63: pa09
	@$(VALGRIND) --log-file=outputs/memoutput63 ./pa09 inputs/input63 outputs/output63
	@diff -w outputs/output63 expected/expected63

test64: pa09
	@$(VALGRIND) --log-file=outputs/memoutput64 ./pa09 inputs/input64 outputs/output64
	@diff -w outputs/output64 expected/expected64

test65: pa09
	@$(VALGRIND) --log-file=outputs/memoutput65 ./pa09 inputs/input65 outputs/output65
	@diff -w outputs/output65 expected/expected65

test66: pa09
	@$(VALGRIND) --log-file=outputs/memoutput66 ./pa09 inputs/input66 outputs/output66
	@diff -w outputs/output66 expected/expected66

test67: pa09
	@$(VALGRIND) --log-file=outputs/memoutput67 ./pa09 inputs/input67 outputs/output67
	@diff -w outputs/output67 expected/expected67

test68: pa09
	@$(VALGRIND) --log-file=outputs/memoutput68 ./pa09 inputs/input68 outputs/output68
	@diff -w outputs/output68 expected/expected68

test69: pa09
	@$(VALGRIND) --log-file=outputs/memoutput69 ./pa09 inputs/input69 outputs/output69
	@diff -w outputs/output69 expected/expected69

test70: pa09
	@$(VALGRIND) --log-file=outputs/memoutput70 ./pa09 inputs/input70 outputs/output70
	@diff -w outputs/output70 expected/expected70

test71: pa09
	@$(VALGRIND) --log-file=outputs/memoutput71 ./pa09 inputs/input71 outputs/output71
	@diff -w outputs/output71 expected/expected71

test72: pa09
	@$(VALGRIND) --log-file=outputs/memoutput72 ./pa09 inputs/input72 outputs/output72
	@diff -w outputs/output72 expected/expected72

test73: pa09
	@$(VALGRIND) --log-file=outputs/memoutput73 ./pa09 inputs/input73 outputs/output73
	@diff -w outputs/output73 expected/expected73

test74: pa09
	@$(VALGRIND) --log-file=outputs/memoutput74 ./pa09 inputs/input74 outputs/output74
	@diff -w outputs/output74 expected/expected74

test75: pa09
	@$(VALGRIND) --log-file=outputs/memoutput75 ./pa09 inputs/input75 outputs/output75
	@diff -w outputs/output75 expected/expected75

test76: pa09
	@$(VALGRIND) --log-file=outputs/memoutput76 ./pa09 inputs/input76 outputs/output76
	@diff -w outputs/output76 expected/expected76

test77: pa09
	@$(VALGRIND) --log-file=outputs/memoutput77 ./pa09 inputs/input77 outputs/output77
	@diff -w outputs/output77 expected/expected77

test78: pa09
	@$(VALGRIND) --log-file=outputs/memoutput78 ./pa09 inputs/input78 outputs/output78
	@diff -w outputs/output78 expected/expected78

test79: pa09
	@$(VALGRIND) --log-file=outputs/memoutput79 ./pa09 inputs/input79 outputs/output79
	@diff -w outputs/output79 expected/expected79

test80: pa09
	@$(VALGRIND) --log-file=outputs/memoutput80 ./pa09 inputs/input80 outputs/output80
	@diff -w outputs/output80 expected/expected80

test81: pa09
	@$(VALGRIND) --log-file=outputs/memoutput81 ./pa09 inputs/input81 outputs/output81
	@diff -w outputs/output81 expected/expected81

test82: pa09
	@$(VALGRIND) --log-file=outputs/memoutput82 ./pa09 inputs/input82 outputs/output82
	@diff -w outputs/output82 expected/expected82

test83: pa09
	@$(VALGRIND) --log-file=outputs/memoutput83 ./pa09 inputs/input83 outputs/output83
	@diff -w outputs/output83 expected/expected83

test84: pa09
	@$(VALGRIND) --log-file=outputs/memoutput84 ./pa09 inputs/input84 outputs/output84
	@diff -w outputs/output84 expected/expected84

test85: pa09
	@$(VALGRIND) --log-file=outputs/memoutput85 ./pa09 inputs/input85 outputs/output85
	@diff -w outputs/output85 expected/expected85

test86: pa09
	@$(VALGRIND) --log-file=outputs/memoutput86 ./pa09 inputs/input86 outputs/output86
	@diff -w outputs/output86 expected/expected86

test87: pa09
	@$(VALGRIND) --log-file=outputs/memoutput87 ./pa09 inputs/input87 outputs/output87
	@diff -w outputs/output87 expected/expected87

test88: pa09
	@$(VALGRIND) --log-file=outputs/memoutput88 ./pa09 inputs/input88 outputs/output88
	@diff -w outputs/output88 expected/expected88

test89: pa09
	@$(VALGRIND) --log-file=outputs/memoutput89 ./pa09 inputs/input89 outputs/output89
	@diff -w outputs/output89 expected/expected89

test90: pa09
	@$(VALGRIND) --log-file=outputs/memoutput90 ./pa09 inputs/input90 outputs/output90
	@diff -w outputs/output90 expected/expected90

test91: pa09
	@$(VALGRIND) --log-file=outputs/memoutput91 ./pa09 inputs/input91 outputs/output91
	@diff -w outputs/output91 expected/expected91

test92: pa09
	@$(VALGRIND) --log-file=outputs/memoutput92 ./pa09 inputs/input92 outputs/output92
	@diff -w outputs/output92 expected/expected92

test93: pa09
	@$(VALGRIND) --log-file=outputs/memoutput93 ./pa09 inputs/input93 outputs/output93
	@diff -w outputs/output93 expected/expected93

test94: pa09
	@$(VALGRIND) --log-file=outputs/memoutput94 ./pa09 inputs/input94 outputs/output94
	@diff -w outputs/output94 expected/expected94

test95: pa09
	@$(VALGRIND) --log-file=outputs/memoutput95 ./pa09 inputs/input95 outputs/output95
	@diff -w outputs/output95 expected/expected95

test96: pa09
	@$(VALGRIND) --log-file=outputs/memoutput96 ./pa09 inputs/input96 outputs/output96
	@diff -w outputs/output96 expected/expected96

test97: pa09
	@$(VALGRIND) --log-file=outputs/memoutput97 ./pa09 inputs/input97 outputs/output97
	@diff -w outputs/output97 expected/expected97

test98: pa09
	@$(VALGRIND) --log-file=outputs/memoutput98 ./pa09 inputs/input98 outputs/output98
	@diff -w outputs/output98 expected/expected98

test99: pa09
	@$(VALGRIND) --log-file=outputs/memoutput99 ./pa09 inputs/input99 outputs/output99
	@diff -w outputs/output99 expected/expected99

test100: pa09
	@$(VALGRIND) --log-file=outputs/memoutput100 ./pa09 inputs/input100 outputs/output100
	@diff -w outputs/output100 expected/expected100
