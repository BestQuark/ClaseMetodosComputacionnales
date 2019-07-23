import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

datos = np.genfromtxt("Canal_ionico.txt")
posx = datos[:,0]
posy = datos[:,1]

datx = np.array([])
daty = np.array([])
datr = np.array([])

centrox = 0
centroy = 0
radio =np.min(np.sqrt((posx-centrox)**2 +(posy-centroy)**2))

for i in range(1000):
	centroxN = np.random.normal(centrox,1)
	centroyN = np.random.normal(centrox,1)
	radioN = np.min(np.sqrt((posx-centroxN)**2 +(posy-centroyN)**2))
	if(radioN > radio): 
		centrox = centroxN
		centroy = centroyN
		radio = radioN
#almacenamos los datos como lo pide el ejercicio
	datx = np.append(datx,[centrox])
	daty = np.append(daty,[centroy])
	datr = np.append(datr,[radio])
print("El centro que se hallo fue ("+str(centrox)+","+str(centroy)+"), con un radio de "+str(radio))
fig, ax = plt.subplots()
plt.axis('equal')
#le restamos eso para que no toque el borde
circle1 = plt.Circle((centrox, centroy), radio-0.0000001, color='r',fill=False)
ax.add_artist(circle1)
puntos = plt.scatter(posx,posy,s=2,c='b')
centro = plt.scatter(centrox,centroy,s=7, c = 'r')
ax.add_artist(puntos)
ax.add_artist(centro)
ax.set_title("punto 1")
plt.savefig("Canal.png")
plt.close()
