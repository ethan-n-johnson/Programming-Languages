// Ethan Johnson
// 1002008374
// openjdk version "21.0.1" 2023-10-17 LTS
// Windows

import java.io.File;

public class enj8374_lab01{
    public static int get_dir_size(String path)
    {
        int size = 0;

        // Open a new directory
        File current_directory = new File(path);

        File[] entries = current_directory.listFiles();
        if(entries == null){
            return -1;
        }
        // Loop through entries in a directory
        for (File current_entry : entries)
        {
            String file_path;
            // Get the true path from the current_entry
            file_path = current_entry.getPath();
                // If the current_entry is a directory call get_dir_size recursively
                if (current_entry.isDirectory())
                {
                    size += get_dir_size(file_path);
                }
                // Else add its size to the total
                else
                {
                    size += current_entry.length();
                }
        }
        return size;
    }

    public static void main(String[] args)
    {
        int total_size;
        
        // Call get_dir_size where the path is the current directory
        total_size = get_dir_size(".");

        System.out.println(total_size);
    }
}