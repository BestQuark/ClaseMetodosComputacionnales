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

#def siono(x,y,r):
#	a = True
#	for i in len(posx):
#		if( ((x-posx[i])**2 + (y-posy[i])**2) )

centrox = 5
centroy = 5
radio = np.sqrt((np.min(np.abs(posx-centrox)))**2 +(np.min(np.abs(posy-centroy)))**2)

for i in range(1000):
	centroxN = np.random.normal(centrox,0.05)
	centroyN = np.random.normal(centrox,0.05)
	radioN = np.sqrt(np.min(posx-centroxN)**2 +np.min(posy-centroyN)**2)
	if(radioN > radio and (np.all(np.sqrt((centroxN-posx)**2 + (centroyN-posy)**2)) < radioN)):
		centrox = centroxN
		centroy = centroyN
		radio = radioN
#almacenamos los datos como lo pide el ejercicio
	datx = np.append(datx,[centrox])
	daty = np.append(daty,[centroy])
	datr = np.append(datr,[radio])


fig, ax = plt.subplots()
plt.axis('equal')
circle1 = plt.Circle((centrox, centroy), radio, color='r',fill=False)
ax.add_artist(circle1)
puntos = plt.scatter(posx,posy,s=2,c='b')
ax.add_artist(puntos)
plt.savefig("Canal.png")
plt.close()
