# Ejercicio 1

import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

# Use esta funcion que recibe un valor x y retorna un valor f(x) donde f es la forma funcional que debe seguir su distribucion. 
lin = np.linspace(-4,4,10000)

def integralSimp(f,a,b,N):
	if N%2==1:N+=1
	h = (b-a)/N
	base = np.linspace(a,b,num = N+1)
	return h*(f(base[0]) + np.sum(4*f(base[1:-1:2])) + np.sum(2*f(base[2:-1:2])) + f(base[-1]))/3

def mifun(x):
	x_0 = 3.0
	a = 0.01
	return np.exp(-(x**2))/((x-x_0)**2 + a**2)

cte = 1/integralSimp(mifun,-4,4, 10000)


# Dentro de una funcion que reciba como parametros el numero de pasos y el sigma de la distribucion gausiana que va a usar para calcular el paso de su caminata, implemente el algortimo de Metropolis-Hastings. Finalmente, haga un histograma de los datos obtenidos y grafique en la misma grafica, la funcion de distribucion de probabilidad fx (Ojo, aca debe normalizar). Guarde la grafica sin mostrarla en un pdf. Use plt.savefig("histograma_"+str(sigma)+"_"+str(pasos)+".pdf"), donde sigma y pasos son los parametros que recibe la funcion. 

def Metropolis(num, sigma):

	x0 = np.random.rand(1)*8-4
	xv = x0
	lista = np.array([x0])
	for i in range(num):	
		xn = np.random.normal(xv,sigma)
		alpha = mifun(xn)/mifun(xv)
		if(alpha>=1):
			xv = xn
		elif(np.random.rand()<alpha):
			xv = xn
		lista = np.append(lista,[xv])

	plt.figure()
	plt.hist(lista,150, color = "orange", density = True)
	plt.plot(lin,mifun(lin)*cte, c ='r')
	plt.title("Sigma "+str(sigma))
	plt.xlabel("x")
	plt.ylabel("y")
	plt.savefig("histograma_"+str(sigma)+"_"+str(num)+ ".pdf")
	
			


# Cuando haya verificado que su codigo funciona, use los siguientes parametros:
# sigma = 5, pasos =100000 

Metropolis(100000,5)

# sigma = 0.2, pasos =100000 
Metropolis(100000,0.2)

# sigma = 0.01, pasos =100000 
Metropolis(100000,0.01)

# sigma = 0.1, pasos =1000 

Metropolis(1000,0.1)

# sigma = 0.1, pasos =100000 

Metropolis(100000,0.1)


# este puede ser muy demorado dependiendo del computador: sigma = 0.1, pasos =500000 

# Al ejecutar el codigo, este debe generar 6 (o 5) graficas .pdf una para cada vez que se llama a la funcion.
