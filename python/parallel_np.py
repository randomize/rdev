import numpy as np
import numexpr as ne

size = 10000
a = np.random.random_sample((size, size))
b = np.random.random_sample((size, size))

n1 = ne.evaluate("sum(a*b)")

print(n1)

n2 = np.dot(a,b)

print(n1)

