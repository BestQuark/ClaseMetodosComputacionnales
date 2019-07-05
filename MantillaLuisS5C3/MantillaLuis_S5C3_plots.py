import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

datos = np.genfromtxt("posicion.dat")



x = datos[:,0]
y = datos[:,1]



plt.figure()
plt.title("Solucion ecuacion usando C++")
plt.plot(x,y,c = 'g', label = "Solucion")
plt.xlabel("tiempo")
plt.ylabel("posicion")
plt.legend()
plt.savefig("MantillaLuisResorte.pdf")
