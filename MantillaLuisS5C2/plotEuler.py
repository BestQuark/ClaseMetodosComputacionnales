import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

datos = np.genfromtxt("aplot.dat")



x = datos[:,0]
y = datos[:,1]



plt.figure()
plt.title("Euler's Method usando C++")
plt.plot(x,y,c = 'r', label = "Solucion")
plt.xlabel("x")
plt.ylabel("$f(x)$")
plt.legend()
plt.savefig("euler.pdf")
