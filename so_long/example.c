#include "mlx.h"  // Include the MinilibX library header

int main()
{
    void *mlx_ptr; // Declare a pointer for the MLX connection
    void *win_ptr; // Declare a pointer for the window

    // Initialize the connection to the MinilibX graphical system
    mlx_ptr = mlx_init(); // The returned pointer is stored in mlx_ptr
    
    // Create a new window with a width of 800 pixels, a height of 600 pixels, and the title "My First Window"
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "My First Window"); // The returned pointer is stored in win_ptr

    // Draw a pixel in the center of the window at coordinates (400, 300) with the color white (0xFFFFFF)
    // This places the pixel exactly in the middle of the window
    mlx_pixel_put(mlx_ptr, win_ptr, 400, 300, 0xFFFFFF);

    // Enter the event loop to keep the window open and responsive
    mlx_loop(mlx_ptr);

    // Return 0 to indicate successful execution
    return 0;
}

