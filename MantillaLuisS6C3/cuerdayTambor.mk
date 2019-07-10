all: Caso1.pdf Caso2.pdf Caso3.pdf Caso1.gif Caso2.gif Caso3.gif tamborCondiInic.png

Caso1.pdf: Plots_cuerdayTambor.py posiciones.dat
	python3 Plots_cuerdayTambor.py

Caso2.pdf: Plots_cuerdayTambor.py posiciones.dat
	python3 Plots_cuerda.py

Caso3.pdf: Plots_cuerdayTambor.py posiciones.dat
	python3 Plots_cuerda.py

posiciones.dat: MantillaLuis_cuerdayTambor.cpp
	g++ MantillaLuis_cuerdayTambor.cpp
	./a.out

tamborCondiInic.png: Plots_cuerdayTambor.py posiciones.dat
	python3 Plots_cuerdayTambor.py



	
		


