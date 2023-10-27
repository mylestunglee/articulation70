import numpy as np

a = np.array([-3.1, -7.4])
x1 = np.array([-4.875, -8.25])
x2 = np.array([-2.275, -8.25])
x3 = np.array([-2.275, -3.65])
x4 = np.array([-3.25, -3.65])
c1 = np.array([-5, -4.75])
radius = 1.5 + 0.25

theta = np.arccos((x1[0] - c1[0]) / radius)

def print_point(x):
    print('      (xy {} {})'.format(round(x[0], 4), round(x[1], 4)))

print_point(x1 - a)
print_point(x2 - a)
print_point(x3 - a)
print_point(x4 - a)
for theta in np.linspace(0, theta, 16):
    print_point(c1 + radius * np.array([np.cos(theta), -np.sin(theta)]) - a)
