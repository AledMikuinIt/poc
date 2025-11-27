import matplotlib.pyplot as plt


n_list = [10000, 100000, 1000000]
temps_lin = [24205, 428003, 4007479]
temps_disp = [1003573, 11376624, 165956622]

plt.plot(n_list, temps_lin, label='Linéaire')
plt.plot(n_list, temps_disp, label='Dispersé')
plt.xlabel('Nombre d’objets')
plt.ylabel('Temps (ns)')
plt.legend()
plt.show()
