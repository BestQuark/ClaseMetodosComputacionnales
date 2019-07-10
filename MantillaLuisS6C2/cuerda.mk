all: Caso1.pdf Caso2.pdf Caso3.pdf Caso1.gif Caso2.gif Caso3.gif 

Caso1.pdf: Plots_cuerda.py posiciones.dat
	python3 Plots_cuerda.py

posiciones.dat: MantillaLuis_cuerda.cpp
	g++ MantillaLuis_cuerda.cpp
	./a.out

	
		


