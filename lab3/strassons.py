import matplotlib.pyplot as plt
import numpy as np

b=[0,0.3,1.8,9.7,70.1,499.2,6399 ]

print(len(b))

# Adjust according to the length of b
a=[2,4,8,16,32,64,128,]

plt.figure(figsize=(10,6))
plt.plot(a,b,color='g',marker='o',label='Growth Rate of Average Case')
plt.title('Strassons Matrix Multiplication' , fontsize=20)
plt.xlabel('No Of Inputs',fontsize=18)
plt.ylabel('Timing',fontsize=18)
plt.legend()
plt.show()