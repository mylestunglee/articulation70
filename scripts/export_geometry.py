def calc_midpoint(start_x, start_y, end_x, end_y, centre_x, centre_y):
    chord_dist = ((end_x - start_x) ** 2 + (end_y - start_y) ** 2) ** 0.5
    radius = ((centre_x - start_x) ** 2 + (centre_y - start_y) ** 2) ** 0.5
    dist = radius / chord_dist
    return centre_x + (end_y - start_y) * dist, centre_y + (start_x - end_x) * dist

origin_code = 50
code_lookup = {
    60: 'J1',
    70: 'U1'
}

for i in range(3):
    code_lookup[300 + i] = 'LED{}'.format(i)

for y in range(4):
    for x in range(9):
        if x == 3 and y == 3:
            continue
        code_lookup[100 + 10 * y + x] = 'SW{}{}'.format(y + 1, x + 1)

total_written = 0

with open('geometry.txt', 'w') as file:
    # find origin
    for geometry in App.ActiveDocument.getObjectsByLabel("Components")[0].Geometry:
        if geometry.TypeId == 'Part::GeomCircle':
            code = int(200 * geometry.Radius)
            if code == origin_code:
                origin = geometry.Center

    # export components
    for geometry in App.ActiveDocument.getObjectsByLabel("Components")[0].Geometry:
        if geometry.TypeId == 'Part::GeomCircle':
            code = int(200 * geometry.Radius)
            if code == origin_code:
                continue
            reference = code_lookup[code]
            total_written += file.write('{},{},{}\n'.format(reference, geometry.Center[0] - origin[0], origin[1] - geometry.Center[1]))

    # export edges
    for sketch in App.ActiveDocument.findObjects():
        if 'Edge' in sketch.Label:
            for geometry in sketch.Geometry:
                if geometry.TypeId == 'Part::GeomLineSegment':
                    total_written += file.write('edgeline,{},{},{},{}\n'.format(
                        geometry.StartPoint[0] - origin[0],
                        origin[1] - geometry.StartPoint[1],
                        geometry.EndPoint[0] - origin[0],
                        origin[1] - geometry.EndPoint[1]))
                elif geometry.TypeId == 'Part::GeomArcOfCircle':
                    midpoint_x, midpoint_y = calc_midpoint(geometry.StartPoint[0], geometry.StartPoint[1], geometry.EndPoint[0], geometry.EndPoint[1], geometry.Center[0], geometry.Center[1])
                    total_written += file.write('edgearc,{},{},{},{},{},{}\n'.format(
                        geometry.StartPoint[0] - origin[0],
                        origin[1] - geometry.StartPoint[1],
                        geometry.EndPoint[0] - origin[0],
                        origin[1] - geometry.EndPoint[1],
                        midpoint_x - origin[0],
                        origin[1] - midpoint_y))
