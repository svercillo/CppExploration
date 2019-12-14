# Makefile Documentation:
# This Makefile is specific for program3 
# To compile program three, run 'make'
# To run program, run 'make run'
# To clean compilation of program3 object, run 'make clean'

evaluate:       TMA1Question3.cpp 
	g++  TMA1Question3.cpp -o TMA1Question3 

run:			TMA1Question3
	./TMA1Question3
clean:
	rm -f TMA1Question3