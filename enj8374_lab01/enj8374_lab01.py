# Ethan Johnson
# 1002008374
# Python 3.11.9
# Windows

import os

def get_dir_size(path):
    size = 0;

    # Loop through entries at a path
    for entry in os.scandir(path):
        # If the entry is a directory call get_dir_size recursively
        if entry.is_dir():
            size += get_dir_size(entry.path);
        # Else add its size to the total
        else:
            size += os.path.getsize(entry.path);
    return size
        
# Call get_dir_size where the path is the current directory
total_size = get_dir_size(os.getcwd())

print(total_size)