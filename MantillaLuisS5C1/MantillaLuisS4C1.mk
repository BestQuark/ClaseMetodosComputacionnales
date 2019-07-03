S5C1PLOT.pdf: plotsS5C1.py valores.dat
	python3 plotsS5C1.py

valores.dat: S5C1Deriv.cpp
	g++ S5C1Deriv.cpp
	mv a.out programa.out
	./programa.out
