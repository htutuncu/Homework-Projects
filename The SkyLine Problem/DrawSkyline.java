// This class Draws the skyline to the JFrame.
import java.awt.Graphics;
import java.awt.Point;
import java.util.List;
import javax.swing.JPanel;


public class DrawSkyline extends JPanel {

    private final List<Point> coordinates;
    public DrawSkyline(List<Point> c)
    {
        for ( Point p : c )
        {
            p.x = p.x + 10;
            p.y = p.y * -1;
            p.y = p.y + 45;
            p.x = (p.x * 10);
            p.y = (p.y * 10);
            // For a good drawing the skyline. We must some changes on coordinates.
        }
        coordinates = c;
        
        
    }
    public void paintComponent(Graphics g)
    {   // Every iteration, draws a line. 
        // Draw line function gets start coordinate and end coordinate.
        // So if we send skyline coordinates respectively to it,
        // It draws all the skyline solution to the JFrame.
        for ( int i=0; i<coordinates.size()-1; i++ )
        {
            g.drawLine(coordinates.get(i).x,coordinates.get(i).y,
                    coordinates.get(i+1).x, coordinates.get(i+1).y);
        }
    }
   
    
    
}
