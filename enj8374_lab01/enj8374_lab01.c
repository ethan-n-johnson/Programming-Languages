// Ethan Johnson
// 1002008374
// gcc version 13.1.0
// Windows

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int get_dir_size(char *path)
{
    int size = 0;

    // Open a new directory
    DIR *current_directory = opendir(path);
    if (current_directory == NULL)
    {
        printf("Can't open directory: %s\n", path);
        return 0;
    }

    // Create an entry
    struct dirent *current_entry;
    
    // Loop through entries in a directory
    while ((current_entry = readdir(current_directory)) != NULL)
    {
        // Skip the current and parent entries
        if (strcmp(current_entry->d_name, ".") == 0 || strcmp(current_entry->d_name, "..") == 0)
        {
            continue;
        }
        char file_path[512];
        struct stat file_info;
        // Get the true path from the current_entry
        snprintf(file_path,sizeof(file_path), "%s/%s", path, current_entry->d_name);
            if (stat(file_path, &file_info) == 0)
            {
                // If the current_entry is a directory call get_dir_size recursively
                if (S_ISDIR(file_info.st_mode))
                {
                    size += get_dir_size(file_path);
                }
                // Else add its size to the total
                else
                {
                    size += file_info.st_size;
                }
            }
    }
    closedir(current_directory);
    return size;
}

int main()
{
    int total_size = 0;
    
    // Call get_dir_size where the path is the current directory
    total_size = get_dir_size(".");

    printf("%d", total_size);

    return 0;
}