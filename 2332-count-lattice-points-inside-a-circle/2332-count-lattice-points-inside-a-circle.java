class Pair {
    int x;
    int y;

    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Solution {
    public int countLatticePoints(int[][] circles) {
        Set<String> points = new HashSet<>();

        for (int[] circle : circles) {
            int xCenter = circle[0];
            int yCenter = circle[1];
            int radius = circle[2];

            for (int x = xCenter - radius; x <= xCenter + radius; x++) {
                for (int y = yCenter - radius; y <= yCenter + radius; y++) {
                    if ((x - xCenter) * (x - xCenter) + (y - yCenter) * (y - yCenter) <= radius * radius) {
                        points.add(x + "," + y);
                    }
                }
            }
        }

        return points.size();
    }
}

/*

((r-1)^2 + 4r)

*/