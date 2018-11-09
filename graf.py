import matplotlib
matplotlib.use("Agg")
import numpy as np
import matplotlib.pyplot as plt

A = np.genfromtxt("tiempo1.txt")
B = np.genfromtxt("tiempo2.txt")
C = np.genfromtxt("tiempo3.txt")
D = np.genfromtxt("tiempo4.txt")
a =np.array([1,10,20,50,100])
plt.plot(a,np.mean(A),legend="1P")
plt.plot(a,np.mean(B),legend="2P")
plt.plot(a,np.mean(C),legend="3P")
plt.plot(a,np.mean(D),legend="4P")
plt.legend()
plt.savefig("sample.pdf")
