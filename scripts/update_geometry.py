import sys
from kiutils.board import Board
from kiutils.items.gritems import GrLine, GrArc
from kiutils.items.common import Position

board = Board.from_file(sys.argv[1])
board.graphicItems = [graphicItem for graphicItem in board.graphicItems if graphicItem.layer != 'Edge.Cuts']
offset_x = 70
offset_y = 50

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

board.to_file(sys.argv[1])
