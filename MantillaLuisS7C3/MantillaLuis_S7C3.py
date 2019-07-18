#Ejercicio 1 Terminar lo que hizo en clase + dos preguntas adicionales (en mayusculas en el texto)

import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt


# 1) lea los datos de resorte.dat y almacenelos.
# 
resorte = np.genfromtxt("resorte.dat")

tiemp = resorte[:,0]
pos = resorte[:,1]

# Los datos corresponden a las posiciones en x de un oscilador (masa resorte) en funcion del tiempo. La ecuacion de movimiento esta dada por  

# Donde a, gamma, y omega son parametros.

# 2) Implemente un algoritmo que le permita, por medio de estimacion bayesiana de parametros, encontrar los parametros correspondientes a los datos d. Para esto debe:

# 2a.) definir una funcion que reciba los parametros que se busca estimar y los datos de tiempo y retorne el modelo  

def mov(a, gamma,omega,t):
	return a*np.exp(-gamma*t)*np.cos(omega*t)

# 2b.) Definir una funcion que retorne la funcion de verosimilitud
def funVero(xi2):
	return np.exp(-xi2/2)

def chi2(a,gamma,omega):
	return np.sum((pos-mov(a,gamma,omega,tiemp))**2)
# 2c.) Caminata

def Metropolis(num, sigma1, sigma2, sigma3, inic1, inic2, inic3):

	a0 = inic1
	gamma0 = inic2
	omega0 = inic3
	vero0 = funVero(chi2(a0,gamma0,omega0))
	av = a0
	gammav = gamma0
	omegav = omega0
	verov = vero0
	al = np.array([a0])
	gammal = np.array([gamma0])
	omegal = np.array([omega0])
	verol = np.array([vero0])
	
	for i in range(num):	
		an = np.random.normal(av,sigma1)
		gamman = np.random.normal(gammav,sigma2)
		omegan = np.random.normal(omegav,sigma3)
		veron = funVero(chi2(an,gamman,omegan))
		alpha = veron/verov
		if(alpha>=1 or np.random.rand()<alpha):
			av = an
			gammav = gamman
			omegav = omegan
			verov = veron
		al = np.append(al,[av])
		gammal = np.append(gammal,[gammav])
		omegal = np.append(omegal,[omegav])
		verol = np.append(verol,[verov])
	return al,gammal,omegal,verol


#condiciones iniciales
aini=7.5
gammaini=0.6
omegaini=18.2

asigma =0.1
gsigma = 0.1
osigma = 0.1
#numero de pasos
iteraciones=100000

aFin, gammaFin, omegaFin, verFin =Metropolis(iteraciones, asigma, gsigma,osigma, aini, gammaini, omegaini)

i = np.argmax(verFin)
aP = aFin[i]
gP = gammaFin[i]
oP = omegaFin[i]
# 2d.) Seleccione los mejores parametros E IMPRIMA UN MENSAJE QUE DIGA: "LOS MEJORES PARAMETROS SON a=... gamma=... Y omgega=..."

print("Los mejores parametro son a=",aP, " gamma=", gP, " omega=",oP )
# 2f.) Grafique sus datos originales y su modelo con los mejores parametros. Guarde su grafica sin mostrarla en Resorte.pdf


plt.figure()
plt.scatter(tiemp,pos,s=2, c='r',label = "Datos observados")
plt.plot(tiemp, mov(aP,gP,oP,tiemp), c='blue', label="Modelo")
plt.title("Estimacion Bayesiana de Parametros")
plt.xlabel("Tiempo [s]")
plt.ylabel("Posicion[m]")
plt.legend()
plt.savefig("Resorte.pdf")

# 3) SABIENDO QUE omega=np.sqrt(k/m), IMPRIMA UN MENSAJE DONDE EXPLIQUE SI PUEDE O NO DETERMINAR k Y m DE MANERA INDIVIDUAL USANDO EL METODO ANTERIOR. JUSTIFIQUE BIEN SU RESPUESTA (PUEDE ADEMAS HACER PRUEBAS CON EL CODIGO PARA RESPONDER ESTA PREGUNTA).

print("Esto no se puede, solo podriamos hallar la relacion entre ellas, tendriamos una recta de valores de k y m que nos daria exactamente la misma fisica que observamos. El metodo anterior nos variaria k y m de manera aleatoria y siempre buscaria quedarse en la misma recta donde k/m nos den el omega**2 que obtuvimos (al rededor de 17.0)")


