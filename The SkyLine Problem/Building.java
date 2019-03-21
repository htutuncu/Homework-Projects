// Building object has left,right and height values.
public class Building {
    final public int left;
    final public int right;
    final public int height;

    public Building(int left, int right, int height) {
        this.left = left;
        this.right = right;
        this.height = height;
        
        // If there is an error in parameters. 
        if (left <= 0 || right <= 0 || height <= 0 || left >= right) {
            throw new IllegalArgumentException ("Invalid building parameters: " +
                    left  + "," + right + "," + height);
        }
    }    
}

