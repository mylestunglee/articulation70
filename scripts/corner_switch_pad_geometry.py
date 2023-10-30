import numpy as np

a = np.array([-3.1, -6.4])
x1 = np.array([-4.875, -7.25])
x2 = np.array([-2.275, -7.25])
x3 = np.array([-2.275, -4.65])
c1 = np.array([-5, -3.75])
clearance = 0.3001
radius = 1.5 + clearance
segments = 64

theta1 = np.arcsin((c1[1] - x3[1]) / radius)
theta2 = np.arccos((x1[0] - c1[0]) / radius)
pad_radius = 1.0 / np.cos((theta2 - theta1) / (2 * segments))

def print_point(x):
    print('      (xy {} {})'.format(round(x[0], 4), round(x[1], 4)))

print_point(x1 - a)
print_point(x2 - a)
print_point(x3 - a)
for theta in np.linspace(theta1, theta2, 64):
    print_point(c1 + radius * pad_radius * np.array([np.cos(theta), -np.sin(theta)]) - a)
