Resultados_hw2.pdf: Resultados_hw2.tex
	pdflatex Resultados_hw2.tex

Resultados_hw2.tex: posiciones.png  TransformadaAmbasCaras.png TransformadaHibrida.png CaraHibrida.png
	pdflatex Resultados_hw2.tex

posiciones.png: Plots_hw2.py posiciones.dat
	python3 Plots_hw2.py

posiciones.dat: ODEs.cpp
	g++ ODEs.cpp
	./a.out

TransformadaAmbasCaras.png: Fourier.py
	python3 Fourier.py

TransformadaHibrida.png: Fourier.py
	python3 Fourier.py

CaraHibrida.png: Fourier.py
	python3 Fourier.py


