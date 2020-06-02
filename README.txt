Name: Ian Pirie
Date: 4/5/2020
Project: Convex_Hull

Recommendation:
    This was developed and only tested on Linux.

Compile instruction:
    1. uncompress project
    2. navigate to cmake-build-debug
    3. use "cmake .."
    4. use "make"

To use:
    There are various different test executables throughout this folder.
    To initialize:
        enter: "./Test"
    This will populate various different files with varying amount of Points for ten to ten million.

    To use:
        enter: "./Convex_Hull g name_of_file" for graham scan
               "./Convex_Hull j name_of_file" for jarvis march
               "./Convex_Hull q name_of_file" for quick hull


   Quick Hull has been set to automatically to use single, double or multi threading depending on the number of threads in
   your computer( single thread if one thread, double if two and multi thread if more than two). If you wish to test out
   each type, change the line 32 in main.cpp.
        default:
            Quick_Hull quick(input);
        single thread:
            Quick_Hull quick(input, Quick_Hull::singleThread);
        dual thread:
            Quick_Hull quick(input,Quick_Hull::doubleThread);
        multi thread:
            Quick_Hull quick(input,Quick_Hull::multiThread);
