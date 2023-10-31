import pcbnew
import wx

class Plugin(pcbnew.ActionPlugin):
    def defaults(self):
        self.name = "Total track length"
        self.description = self.name
        self.show_toolbar_button = True

    def Run(self):
        parent = wx.FindWindowByName("PcbFrame")
        board = pcbnew.GetBoard()
        filter_selected = any(track.IsSelected() for track in board.GetTracks())
        mm_to_nm = 10 ** 6
        total = 0
        for track in board.GetTracks():
            if track.IsSelected() or not filter_selected:
                if type(track) is pcbnew.PCB_TRACK:
                    length = track.GetLength()
                elif type(track) is pcbnew.PCB_ARC:
                    length = track.GetRadius() * track.GetAngle().AsRadians()
                else:
                    continue
                total += length
        wx.MessageBox("{:,.3f} mm".format(total / mm_to_nm), self.name, parent=parent)
