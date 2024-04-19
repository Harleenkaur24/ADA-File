import matplotlib.pyplot as plt
import numpy as np

b=[5.8,26.9,62.8,110.2,158.1,221.8,274.7,373.9,419.1,466,609.4,796,1038.3,1314.2,1217.4,1587.1,2591.2,2903.4,3241.9,3498.6,4111.2,]

# c=[1000000,4000000,9000000,16000000,25000000,36000000,49000000,64000000,81000000,100000000,121000000,144000000,169000000,196000000,225000000,256000000,289000000,324000000,361000000,400000000,441000000]

c = [10, 40, 90, 160, 250, 360, 490, 640, 810, 1000, 1210, 1440, 1690, 1960, 2250, 2560,2890,3240,3610,4000,4410]

print(len(c))

print(len(b))
b.sort()

a=np.arange(10000,1000001,10000)
print(a)

# Adjust according to the length of b
a=[10000,   20000,   30000,   40000,   50000,   60000,   70000,
         80000,   90000,  100000,  110000,  120000,  130000,  140000,
        150000,  160000, 170000, 180000, 190000, 200000, 210000]

plt.figure(figsize=(10,6))
plt.plot(a,b,color='g',marker='o',label='Growth Rate of Worst case')
plt.plot(a,c,color='b',marker='o',label='Growth Rate of n*n')
plt.title('Quick sort worst case' , fontsize=20)
plt.xlabel('No Of Inputs',fontsize=18)
plt.ylabel('Timing',fontsize=18)
plt.legend()
plt.show()