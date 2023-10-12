import numpy as np

x1 = np.array([-4.875, -7.25])
x2 = np.array([-2.275, -7.25])
x3 = np.array([-2.275, -4.65])
c1 = np.array([-5, -3.75])
radius = 1.5 + 0.25

theta1 = np.arcsin((c1[1] - x3[1]) / radius)
theta2 = np.arccos((x1[0] - c1[0]) / radius)

def print_point(x):
    print('      (xy {} {})'.format(round(x[0], 4), round(x[1], 4)))

print_point(x1)
print_point(x2)
print_point(x3)
for theta in np.linspace(theta1, theta2, 16):
    print_point(c1 + radius * np.array([np.cos(theta), -np.sin(theta)]))
