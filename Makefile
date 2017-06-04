default: rpn

rpncalc.o: rpn.h main.c
	cc -c main.c -o rpncalc.o

double_stack.o: rpn.h double_stack.c
	cc -c double_stack.c -o double_stack.o

rpn_parse_token.o: rpn.h rpn_parse_token.c
	cc -c rpn_parse_token.c -o rpn_parse_token.o

rpn_operators.o: rpn.h rpn_operators.c
	cc -c rpn_operators.c -o rpn_operators.o

rpn: double_stack.o rpn_parse_token.o rpn_operators.o rpncalc.o
	cc double_stack.o rpn_parse_token.o rpn_operators.o rpncalc.o -o rpn -lm
