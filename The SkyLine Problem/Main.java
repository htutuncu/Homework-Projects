/*      OBJECT ORIENTED PROGRAMMING 
 *       ASSIGNMENT 7 - JUNE,2018
 *       HIKMET TUTUNCU  141044054
 *      THE SKYLINE PROBLEM SOLUTION
 */
import java.io.*;
import java.util.*;
import java.awt.Point;
import javax.swing.JFrame;
import javax.swing.WindowConstants;

public class Main {
    
    public static List<Building> getInput(File is) throws FileNotFoundException{
    // Method of read input file and returns it as a List of Building objects.
        ArrayList<Building> buildings = new ArrayList<Building>();
        // ArrayList of Building objects.
        Scanner sc = new Scanner (is); // Input stream. Opening input file.
        while ( sc.hasNextLine() ) // Reading file to the end. 
        {
            String s = sc.nextLine(); // Temp string that stores a new line from input.
            if (s.equals("")) { break; } // If there is no line, breaks the loop. 
            StringTokenizer st = new StringTokenizer(s); // For parsing the line.
            // First value is width, second is height and the last one is position.
            int wid = Integer.valueOf(st.nextToken());
            int hei = Integer.valueOf(st.nextToken());
            int pos = Integer.valueOf(st.nextToken());
            // Position means left of rectangle. Right is the end of rectangle.
            int left = pos;
            int right = left + wid;
            int height = hei;
            // Creating a new building object which has left,right and height.
            Building b = new Building (left, right, height);
            buildings.add(b); // New object adding to the ArrayList of Buildings.
        }
        return (buildings); // Function returns ArrayList of Building objects.
    }

    public static ArrayList<Edge> compute(List<Building> buildings) 
    { // Method of computing edge points.
        TreeSet<Integer> S = new TreeSet<Integer>();
        // TreeSet for integer values. TreeSet stores values and sorts them. There is no duplicate.
        HashMap<Integer,ArrayList<Building>> lefts = new HashMap<Integer,ArrayList<Building>>();
        HashMap<Integer,ArrayList<Building>> rights = new HashMap<Integer,ArrayList<Building>>();
        // HashMaps for int and arraylist: left and right coordinates of building.
        ArrayList<Building> list = null; // Empty arraylist, this will be temp.
        for (Building b : buildings) 
        {   // In every iteration, left and right coordinates adding to TreeSet.
            S.add(b.left); 
            list = lefts.get(b.left); // assignin to temp list.
            if (list == null) 
            { // If, creates new list and stores left coordinates of building. 
                list = new ArrayList<Building>();
                lefts.put(b.left, list);
            }
            list.add(b); // Adding left coordinates to the list.
            
            // Same operations for the right coordinates of buildings.
            S.add(b.right);
            list = rights.get(b.right);
            if (list == null) {
                list = new ArrayList<Building>();
                rights.put(b.right, list);
            }
            list.add(b);
        }
        // After for loop, we have two HashMap that buildings lefts and rights.
        // TreeSet stores all of the coordinates. Lefts and rights.
        int left = 0, top = 0;
        ArrayList<Edge>skyline = new ArrayList<Edge>();
        // Skyline arraylist is going to be our result. 
        ArrayList<Building> heightList = new ArrayList<Building>();
        // heightList stores all the heights of buildings.
        for (int x : S) 
        {   // For loop iterates our TreeSet, it means all the coordinates.
            if (heightList.isEmpty()) {
                top = 0;
            } else {
                // top is the most height building for now. Local heighest building.
                top = heightList.get(0).height;
            }

            list = rights.get(x); // get a building right from rights HashMap. 
            if (list != null) 
            {   // coordinate removing from heightList. Parallel arrays method.
                for (Building b : list) {
                    heightList.remove(b);
                }
            }
                
            list = lefts.get(x); // get a building left form lefts HashMap.
            if (list != null) {
                for (Building b : list) {
                    int i;
                    for (i = 0; i < heightList.size(); i++) {
                        if (heightList.get(i).height < b.height) {
                            // If there is a more height the building, adds to heightList.
                            // It means a corner. Sorting them.
                            heightList.add(i, b);
                            break;
                        }
                    }
                    if (i == heightList.size()) {
                        // If there is no more height than the building, adds the corner to heightList.
                        heightList.add(b);
                    }
                }
            }

            int newTop; // newTop is the most height building.
            if (heightList.isEmpty()) {
                newTop = 0;
            } else {
                newTop = heightList.get(0).height; // newTop updating.
            }

            if (top == 0) {
                left = x; // There is no higher building, this means a corner. Adds to left.
            } else if (top != newTop) {
                // Creating a local top corner. 
                Edge e = new Edge(new Point (left, top), new Point (x, top));
                skyline.add(e); // Adding our skyline list.
                left = x;
            }
        }
        return (skyline); // returns skyline list. Result.
    }

    public static List<Point> complete(ArrayList<Edge> skyline) 
    {   // complete function sorts the skyline coordinates and complete.
        ArrayList<Point> skylinepoints = new ArrayList<Point>();
        // Our result points. "skylinepoints".
        if (skyline.isEmpty()) { return skylinepoints; }

        int left = skyline.get(0).start.x;  // left of skyline, starting point.
        int right = skyline.get(skyline.size()-1).end.x; // last coordinate of skyline.

        skylinepoints.add(new Point (left, 0)); // adding first coordinate of skyline.

        for (int i = 0; i < skyline.size(); i++) 
        {   // Creating edge in every iteration.
            Edge edge = skyline.get(i);
            skylinepoints.add(edge.start); // start coordinates for lines.
            skylinepoints.add(edge.end);  // end coordinates for lines.

            Edge nextEdge = null; 
            if (i+1 < skyline.size()) 
            {   // next edge computing. If its not last point.
                nextEdge = skyline.get(i+1); // assign to next edge. 

                if (edge.end.x != nextEdge.start.x) 
                {   // If the skyline has blanks . It must be zero coordinates.
                    skylinepoints.add(new Point (edge.end.x, 0));
                    skylinepoints.add(new Point (nextEdge.start.x, 0));
                }
            }
        }

        skylinepoints.add(new Point (right, 0)); // adding last coordinate of skyline.
        return (skylinepoints); // return the result. List of skylinepoints.
    }

    public static void main(String[] args) throws FileNotFoundException {
        // opening input file.
        File file = new File("data.txt");
        List<Building> buildings = getInput(file);
        // getInput function returns all of the inputs at first.
        ArrayList<Edge> skyline = compute(buildings);
        // compute function returns skyline coordinates.
        List<Point> ResultPoints = complete(skyline);
        // complete function returns the final skyline lines. 
        
        // Prints the output all of skyline coordinates.
        for (Point p : ResultPoints) {
            System.out.print("(" + p.x + ", " + p.y + ")");
            if ( p != ResultPoints.get(ResultPoints.size()-1) )
                System.out.print(", ");
        }
        System.out.println();
        
        JFrame jf = new JFrame("The Skyline Problem Solution -hkmttnc");
        // new JFrame that drawing the skyline to the Frame.
        jf.add(new DrawSkyline(ResultPoints));// Calling DrawSkyline that draws skyline.
        jf.setSize(600,500);    // Initial size.
        jf.setVisible(true);  
        
        jf.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        // For close running. End of the program.
    }
}
