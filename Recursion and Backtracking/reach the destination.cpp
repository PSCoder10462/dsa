bool reachDestination(int sx, int sy, int dx, int dy) {
    if (sx == dx and sy == dy) return true;
    if (sx > dx or sy > dy) return false;
    if (dx > dy)
        // move left
        return reachDestination(sx, sy, dx-dy, dy);
   	else 
        // move up
        return reachDestination(sx, sy, dx, dy-dx);
}
