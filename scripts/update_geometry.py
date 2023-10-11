import sys
from kiutils.board import Board
from kiutils.items.gritems import GrLine, GrArc
from kiutils.items.fpitems import FpText
from kiutils.items.common import Position

board = Board.from_file(sys.argv[1])

board.graphicItems = [graphicItem for graphicItem in board.graphicItems if graphicItem.layer != 'Edge.Cuts']
offset_x = 70
offset_y = 50
component_positions = {}
component_rotations = {'SW41': 25, 'SW42': 10, 'SW43': -5}
for x in range(3):
    for y in range(4):
        component_rotations['SW{}{}'.format(y + 1, x + 7)] = -10

with open(sys.argv[2]) as file:
    for line in file.readlines():
        tokens = line.split(',')
        if tokens[0] == 'edgeline':
            start_x = float(tokens[1]) + offset_x
            start_y = float(tokens[2]) + offset_y
            end_x = float(tokens[3]) + offset_x
            end_y = float(tokens[4]) + offset_y
            board.graphicItems.append(GrLine(start=Position(start_x, start_y, 0), end=Position(end_x, end_y, 0), layer='Edge.Cuts', width=0.1))
        elif tokens[0] == 'edgearc':
            start_x = float(tokens[1]) + offset_x
            start_y = float(tokens[2]) + offset_y
            end_x = float(tokens[3]) + offset_x
            end_y = float(tokens[4]) + offset_y
            mid_x = float(tokens[5]) + offset_x
            mid_y = float(tokens[6]) + offset_y
            board.graphicItems.append(GrArc(start=Position(start_x, start_y, 0), mid=Position(mid_x, mid_y, 0), end=Position(end_x, end_y, 0), layer='Edge.Cuts', width=0.1))        
        else:
            pos_x = float(tokens[1]) + offset_x
            pos_y = float(tokens[2]) + offset_y
            component_positions[tokens[0]] = Position(pos_x, pos_y, component_rotations.get(tokens[0], 0))

for i, footprint in enumerate(board.footprints):
    for graphicItem in footprint.graphicItems:
        if type(graphicItem) is FpText and graphicItem.type == 'reference':
            if graphicItem.text in component_positions:
                board.footprints[i].position = component_positions[graphicItem.text]
            else:
                print('Missing geometry data for footprint', graphicItem.text)
            break

board.to_file(sys.argv[1])
