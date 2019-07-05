MantillaLuisResorte.pdf: MantillaLuis_S5C3_plots.py posicion.dat
	python3 MantillaLuis_S5C3_plots.py

posicion.dat: MantillaLuis_S5C3_ODEs.cpp
	g++ MantillaLuis_S5C3_ODEs.cpp
	./a.out
