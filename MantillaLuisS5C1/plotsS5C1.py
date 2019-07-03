import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

datos = np.genfromtxt("valores.dat")

deriv = datos[:,0]
valor = datos[:,1]
x = datos[:,2]


plt.figure()
plt.title("Derivada usando C++")
plt.plot(x,deriv,c = 'r', label = "Derivada")
plt.plot(x,valor, c = 'g', label = "Funcion")
plt.xlabel("x")
plt.ylabel("$f(x)$")
plt.legend()
plt.savefig("S5C1PLOT.pdf")
