all: Caso1.pdf Caso2.pdf Caso3.pdf Caso1.gif Caso2.gif Caso3.gif tambor0.png

Caso1.pdf: Plots_cuerdayTambor.py posiciones.dat
	python3 Plots_cuerdayTambor.py

Caso2.pdf: Plots_cuerdayTambor.py posiciones.dat
	python3 Plots_cuerda.py

Caso3.pdf: Plots_cuerdayTambor.py posiciones.dat
	python3 Plots_cuerda.py

posiciones.dat: MantillaLuis_cuerdayTambor.cpp
	g++ MantillaLuis_cuerdayTambor.cpp
	./a.out

posicionesTambor.dat: MantillaLuis_cuerdayTambor.cpp
	g++ MantillaLuis_cuerdayTambor.cpp
	./a.out

tambor0.png: Plots_cuerdayTambor.py posicionesTambor.dat
	python3 Plots_cuerdayTambor.py



	
		


