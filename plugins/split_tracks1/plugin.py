import pcbnew
import wx

def intersect(a, b, c, d):
    # Intersection point of two line segments in 2 dimensions - Paul Bourke
    # http://paulbourke.net/geometry/pointlineplane/
    denom = (d.y - c.y)*(b.x - a.x) - (d.x - c.x)*(b.y - a.y)
    if abs(denom) > 1e-6:
        abPos = ((d.x - c.x)*(a.y - c.y) - (d.y - c.y)*(a.x - c.x)) / denom
        cdPos = ((b.x - a.x)*(a.y - c.y) - (b.y - a.y)*(a.x - c.x)) / denom
        if 0 <= abPos <= 1 and 0 <= cdPos <= 1:
            return pcbnew.VECTOR2I(
                int(a.x + (b.x - a.x)*abPos + 0.5),
                int(a.y + (b.y - a.y)*abPos + 0.5))
    return None

class Plugin(pcbnew.ActionPlugin):
    def defaults(self):
        self.name = "Split tracks"
        self.description = "Split selected tracks from their intersection."
        self.show_toolbar_button = True

    def Run(self):
        parent = wx.FindWindowByName("PcbFrame")
        board = pcbnew.GetBoard()
        selected_tracks = [track for track in board.GetTracks() if track.IsSelected() and type(track) is pcbnew.PCB_TRACK]
        if len(selected_tracks) != 2:
            wx.MessageBox(f"Two tracks must be selected", "Split tracks", parent=parent)
            return
        track1, track2 = selected_tracks
        intersection = intersect(track1.GetStart(), track1.GetEnd(), track2.GetStart(), track2.GetEnd())
        if intersection is None:
            wx.MessageBox(f"Two tracks must intersect", "Split tracks", parent=parent)
            return

        def new_track(start, parent):
            if start == intersection:
                return

            track = pcbnew.PCB_TRACK(board)
            track.SetStart(start)
            track.SetEnd(intersection)
            track.SetWidth(parent.GetWidth())
            track.SetLayer(parent.GetLayer())
            board.Add(track)
            
        new_track(track1.GetStart(), track1)
        new_track(track1.GetEnd(), track1)
        new_track(track2.GetStart(), track2)
        new_track(track2.GetEnd(), track2)
        board.Remove(track1)
        board.Remove(track2)
