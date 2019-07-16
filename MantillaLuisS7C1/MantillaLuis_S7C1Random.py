#Ejercicio 0
#Lean el capitulo 5 del Landau (ver el programa del curso).

import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt


#Ejercicio 1
# Usando los generadores de numeros aleatorios de numpy (https://docs.scipy.org/doc/numpy-1.15.1/reference/routines.random.html):
# a) Genere 1000 numeros aleatorios que sigan una distribucion uniforme y esten entre -10 y 10. Haga un histograma y guardelo sin mostrarlo en un archivo llamado uniforme.pdf
plt.figure()
plt.hist(np.random.rand(1000)*20-10, color = "green")
plt.title("Distribucion uniforme")
plt.savefig("uniforme.pdf")


# a) Genere 1000 numeros aleatorios que sigan una distribucion gausiana centrada en 17 y de sigma 5. Haga un histograma y guardelo sin mostrarlo en un archivo llamado gausiana.pdf

plt.figure()
plt.hist(np.random.normal(17,5,1000), color = "green")
plt.title("Distribucion uniforme")
plt.savefig("gausiana.pdf")


# Ejercicio 2
# Escriba un programa en Python que: 
# Genere puntos aleatorios distribuidos uniformemente dentro de un cuadrado de lado 30.5. Grafique sus puntos y guarde la grafica sin mostrarla en un archivo llamado cuadrado.pdf. 

cuadradoPuntos = np.random.rand(1000,2)*30.5

plt.figure()
plt.scatter(cuadradoPuntos[:,0],cuadradoPuntos[:,1],s=2,c='r' )
plt.title("Cuadrado")
plt.savefig("cuadrado.pdf")



# Genere puntos aleatorios distribuidos uniformemente dentro de circulo de radio 23. Grafique sus puntos y guarde la grafica sin mostrarla en un archivo llamado circulo.pdf. 

cuadradoPuntos = np.random.rand(1000,2)*46-23

circuloPuntosX=np.array([])
circuloPuntosY=np.array([])

for i in range(1000):
	if(cuadradoPuntos[i,0]**2 + cuadradoPuntos[i,1]**2 <23*23 ):
		circuloPuntosX = np.append(circuloPuntosX,[cuadradoPuntos[i,0]])
		circuloPuntosY = np.append(circuloPuntosY,[cuadradoPuntos[i,1]])

plt.figure()
plt.scatter(circuloPuntosX,circuloPuntosY,s=2,c='r' )
plt.title("Circulo")
plt.savefig("circulo.pdf")

# Ejercicio 3 
# Lean sobre caminatas aleatorias.


# Ejercicio 4
# Tome los puntos distribuidos aleatoriamente dentro del cuadrado y haga que cada punto siga una caminata aleatoria de 100 pasos. 

punto = np.random.choice(range(1000))
puntox = np.array([])
puntoy = np.array([])


for j in range(1000):
	for i in range(100):
		caminata = np.random.normal(0,0.25,2)
		cuadradoPuntos[j,0] = cuadradoPuntos[j,0]+caminata[0]	
		cuadradoPuntos[j,1] = cuadradoPuntos[j,1]+caminata[1]
		if(cuadradoPuntos[j,0]>30.5):
			cuadradoPuntos[j,0] = cuadradoPuntos[j,0]-30.5
		elif(cuadradoPuntos[j,0]<0):
			cuadradoPuntos[j,0] = cuadradoPuntos[j,0]+30.5
		if(cuadradoPuntos[j,1]>30.5):
			cuadradoPuntos[j,1] = cuadradoPuntos[j,1]-30.5
		elif(cuadradoPuntos[j,1]<0):
			cuadradoPuntos[j,1] = cuadradoPuntos[j,1]+30.5
		if(j==punto):
			puntox = np.append(puntox, [cuadradoPuntos[j,0]])		
			puntoy = np.append(puntoy, [cuadradoPuntos[j,1]])
	
plt.figure()
plt.scatter(cuadradoPuntos[:,0],cuadradoPuntos[:,1],s=2,c='r' )
plt.title("Caminata")
plt.savefig("DistCaminata.pdf")

plt.figure()
plt.plot(puntox,puntoy,c='r' )
plt.title("Caminata 1 Punto")
plt.savefig("puntoCaminata.pdf")


# La magnitud de los pasos de esta caminata debe seguir una distribucion gaussiana centrada en el punto y de sigma igual a 0.25




# Implemente condiciones de frontera periodicas: si un punto se "sale" de cuadrado por un lado, "entra" por el otro  

# Grafique la distribucion final de puntos y guarde dicha grafica sin mostrarla en un archivo llamado DistCaminata.pdf
# Grafique la caminata de UNO de sus puntos y guarde dicha grafica sin mostrarla en un archivo llamado puntoCaminata.pdf



# Repita el proceso para sigma = 0.00025 y sigma= 2.5. Grafique la caminata de UNO de sus puntos para los distintos sigmas y guardela sin mostrarla en sigmaCaminata.pdf

cuadradoPuntos = np.random.rand(1000,2)*30.5

punto = np.random.choice(range(1000))
puntox1 = np.array([])
puntoy1 = np.array([])

for i in range(100):
	caminata = np.random.normal(0,0.00025,2)
	cuadradoPuntos[punto,0] = cuadradoPuntos[punto,0]+caminata[0]	
	cuadradoPuntos[punto,1] = cuadradoPuntos[punto,1]+caminata[1]
	if(cuadradoPuntos[punto,0]>30.5):
		cuadradoPuntos[punto,0] = cuadradoPuntos[punto,0]-30.5
	elif(cuadradoPuntos[punto,0]<0):
		cuadradoPuntos[punto,0] = cuadradoPuntos[punto,0]+30.5
	if(cuadradoPuntos[punto,1]>30.5):
		cuadradoPuntos[punto,1] = cuadradoPuntos[punto,1]-30.5
	elif(cuadradoPuntos[punto,1]<0):
		cuadradoPuntos[punto,1] = cuadradoPuntos[punto,1]+30.5

	puntox1 = np.append(puntox1, [cuadradoPuntos[punto,0]])		
	puntoy1 = np.append(puntoy1, [cuadradoPuntos[punto,1]])
	

plt.figure()
plt.plot(puntox1,puntoy1,c='r' )
plt.title("Caminata 1 Punto")
plt.savefig("000025Caminata.pdf")


cuadradoPuntos = np.random.rand(1000,2)*30.5

punto = np.random.choice(range(1000))
puntox2 = np.array([])
puntoy2 = np.array([])

for i in range(100):
	caminata = np.random.normal(0,2.5,2)
	cuadradoPuntos[punto,0] = cuadradoPuntos[punto,0]+caminata[0]	
	cuadradoPuntos[punto,1] = cuadradoPuntos[punto,1]+caminata[1]
	if(cuadradoPuntos[punto,0]>30.5):
		cuadradoPuntos[punto,0] = cuadradoPuntos[punto,0]-30.5
	elif(cuadradoPuntos[punto,0]<0):
		cuadradoPuntos[punto,0] = cuadradoPuntos[punto,0]+30.5
	if(cuadradoPuntos[punto,1]>30.5):
		cuadradoPuntos[punto,1] = cuadradoPuntos[punto,1]-30.5
	elif(cuadradoPuntos[punto,1]<0):
		cuadradoPuntos[punto,1] = cuadradoPuntos[punto,1]+30.5
	
	puntox2 = np.append(puntox2, [cuadradoPuntos[punto,0]])		
	puntoy2 = np.append(puntoy2, [cuadradoPuntos[punto,1]])
	

plt.figure()
plt.plot(puntox2,puntoy2,c='r' )
plt.title("Caminata 2 Punto")
plt.savefig("25Caminata.pdf")

# Repita el proceso para condiciones abiertas: si un punto se "sale" del cuadrado deja de ser considerado en la simulacion.

cuadradoPuntos = np.random.rand(1000,2)*30.5

punto = np.random.choice(range(1000))
puntox3 = np.array([])
puntoy3 = np.array([])

for i in range(100):
	caminata = np.random.normal(0,0.5,2)
	cuadradoPuntos[punto,0] = cuadradoPuntos[punto,0]+caminata[0]	
	cuadradoPuntos[punto,1] = cuadradoPuntos[punto,1]+caminata[1]	
	puntox3 = np.append(puntox3, [cuadradoPuntos[punto,0]])		
	puntoy3 = np.append(puntoy3, [cuadradoPuntos[punto,1]])
	

plt.figure()
plt.plot(puntox3,puntoy3,c='r' )
plt.title("Abiertas")
plt.savefig("OpenCaminata.pdf")

# Si le queda tiempo puede:

##################################################################################################################################################################
############################################################ Ejercicio  ##########################################################################
##################################################################################################################################################################

#difusion: una gota de crema en un Cafe.
#
#Condiciones iniciales:
#Cafe: 10000 particulas distribuidas uniformemente dentro de un circulo de radio igual a raiz de 230
#Crema: 100 particulas distribuidas uniformemente dentro de un circulo de radio igual a raiz de 2
#
#Nota: si su codigo se esta demorando mucho en correr, puede usar 1000 particulas de cafe en vez de 10000.
#
# 1) Haga una grafica de las condiciones iniciales donde los dos tipos de particulas tengan distintos colores. Guarde dicha grafica sin mostrarla en CafeLecheIni.pdf
#
#2) Todas las particulas deben hacer una caminata aleatoria de 1000 pasos. Los pasos en las coordenadas x y deben seguir una distribucion gausiana de sigma 2.5. Si va a usar coordenadas polares elija un sigma apropiado.
#
#3) Condiciones de frontera: implemente unas condiciones tales que si la particulas "sale" del circulo, usted vuelva a dar el paso. Si no puede implementar solo las condiciones antes descritas, debe al menos escribir comentarios explicando que hace cada linea de codigo de las condiciones propuestas (comentado abajo)
#
# 4) Haga una grafica de las posiciones finales de las particulas despues de la caminata donde los dos tipos de particulas tengan distintos colores. Guarde dicha grafica sin mostrarla en CafeLecheFin.pdf
#

import numpy as np
import matplotlib.pylab as plt


#Una posible implementacion de condiciones de frontera. Trate de hacer la suya propia sin usar esta. 
#Si usa esta (obtiene menos puntos) debe comentar cada una de las lineas explicando en palabras que hace el codigo. Debe tambien naturalmente usar los nombres de variables que uso en el resto de su codigo propio.
#indexcafe=np.where((xcafenuevo*xcafenuevo+ycafenuevo*ycafenuevo)>230)
#indexcrema=np.where((xcremanuevo*xcremanuevo+ycremanuevo*ycremanuevo)>230)
#while(len(indexcafe[0])>1):
#	xcafenuevo[indexcafe]=xcafe[indexcafe] + np.random.normal(0,sigma)
#	ycafenuevo[indexcafe]=ycafe[indexcafe] + np.random.normal(0,sigma)
#	indexcafe=np.where((xcafenuevo*xcafenuevo+ycafenuevo*ycafenuevo)>=230)
#while(len(indexcrema[0])>1):
#	xcremanuevo[indexcrema]=xcrema[indexcrema] + np.random.normal(0,sigma)
#	ycremanuevo[indexcrema]=ycrema[indexcrema] + np.random.normal(0,sigma)
#	indexcrema=np.where((xcremanuevo*xcremanuevo+ycremanuevo*ycremanuevo)>=230) 



	
