#Importamos los paquetes necesarios
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from scipy.fftpack import fft, fftfreq

#Definimos la funcion sigmoid para suavizar el hibrido 
def sig(x):
	return 1/(1+ np.exp(-15*x))

#Almacenamos los datos de las imagenes en arreglos con imread
imCara1 = plt.imread("cara_02_grisesMF.png")
imCara2 = plt.imread("cara_03_grisesMF.png")

#Sacamos Transformada de fourier con el paquete fft a ambas imagenes
transCara1 = np.fft.fft2(imCara1)
transCara2 = np.fft.fft2(imCara2)


#Reordenamos los datos de la transformada para graficarlos
transCara1Shift = np.fft.fftshift(transCara1)
transCara2Shift = np.fft.fftshift(transCara2)

plt.figure()

plt.subplot(1,2,1)
plt.title("Cara Seria")
plt.imshow(transCara1Shift.real, vmax = 100, vmin = -100)

plt.subplot(1,2,2)
plt.title("Cara Riendo")
plt.imshow(transCara2Shift.real, vmax = 100, vmin = -100)

plt.savefig("TransformadaAmbasCaras.png")


#Filtramos ambas imagenes y graficamos la mezcla de ambas

#Multiplico por 1.7 las frecuencias altas pues se ven muy tenues estos razgos al juntar ambas imagenes
pasaAltas = 1.7*transCara1*sig(-(np.abs(transCara1) - 24))
pasaBajas = transCara2*sig(np.abs(transCara2)-16)
filtro = pasaAltas +pasaBajas

#Podriamos usar el siguiente codigo como filtro pero viene mejor suavizarlo y tomar el corte en distintos puntos las frecuencias especificadas en http://cvcl.mit.edu/publications/OlivaTorralb_Hybrid_Siggraph06.pdf
#np.where(np.abs(transCara1)<24, transCara1, transCara2)



plt.figure()
plt.title("Cara Hibrida")
plt.imshow((np.fft.fftshift(filtro)).real, vmax = 100, vmin = -100)
plt.savefig("TransformadaHibrida.png")


#Hallamos la transformada inversa de la transformada hibrida y la graficamos


#grafica del pasaAltas
caraPasaAltas = np.fft.ifft2(pasaAltas)
plt.figure()
plt.axis('off')
plt.imshow(-caraPasaAltas.real, cmap = 'Greys')
plt.savefig("CaraPasaAltas.png")

#grafica del pasaAltas
caraPasaBajas = np.fft.ifft2(pasaBajas)
plt.figure()
plt.axis('off')
plt.imshow(-caraPasaBajas.real, cmap = 'Greys')
plt.savefig("CaraPasaBajas.png")


#grafica de Ambas imagenes sumadas
caraHibrida = np.fft.ifft2(filtro)
plt.figure()
plt.axis('off')
plt.imshow(-caraHibrida.real, cmap = 'Greys')
plt.savefig("CaraHibrida.png")

#explicacion del warning por usar la exponencial
print("Este warning sale ya que uso una exponencial para el filtro y se estan calculando valores de la exponencial muy altos, pero para nuestros fines, la funcion sigmond del filtro toma valores de 0 exactamente cuando llega al overflow")






