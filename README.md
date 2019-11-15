# StarDust

StarDust is a modular robot framework for C++ FRC teams

StarDust eliminates boilerplate code, fixes sneaky bugs, and wraps existing FRC libraries to squeeze in even more functionality. All of this is to direct attention to the real task at hand: Building seamless and optimized robots.

Say good bye to hard-coding the same drive train year after year, and hello to fine tuning your controller inputs for the perfect drive.

# Installing

## Pre-installation (Adding source folder to Gradle, required)

Gradle is very specific about what files make it into the final linking and compiling of your code

Since this project has both header and source (.hpp and .cpp) files, the `Stardust` directory must also be added into the source

In `build.gradle` (will be at or near the root of your project) find the following section:

```
sources.cpp {
    source {
        srcDir 'src/main/cpp'
        include '**/*.cpp', '**/*.cc'
    }
...
```

Here, the only soure folders are `src/main/cpp`, but we need to add the `src/main/include/Stardust` folder:

```
sources.cpp {
    source {
        srcDir 'src/main/cpp'
        srcDir 'src/main/include/Stardust' // <-- Add this line here
        include '**/*.cpp', '**/*.cc'
    }
...
```

Now, you can use and compile StarDust code!

## Git-based installation (recommended)

This assumes that you have Git installed on your system.

If you do not have Git installed, 

To be able to add another git repo into your existing git repo, a `submodule` will need to be made.

First, create a full backup of your git repo.

Then, inside of `src/main/include` in your project, run:

`git submodule add -b master https://github.com/FRC-4309/StarDust.git`

Then

`git submodule init`

To pull new changes from StarDust later, run `git pull --recurse-submodules`

## Non Git-based installation (not-recommended)

Click the green `Clone or download` button, and click `Download ZIP`.

Extract the newly downloaded file (`StarDust-master`).

You should have the following file tree:

```
/Downloads
    StarDust-master.zip
    StarDust-master/
        StarDust-master/
            ...
```

Copy the second folder (`StarDust-master/StarDust-master`) into `C:/path/to/robotcode/src/main/include/`

Your robot project should look like this:

```
/src
    /main
        /include
            StarDust/   <-- This folder should have the same content as StarDust-master/StarDust-master/
                ...
            Robot.h
```

Now, include files with `#include "StarDust/filename"` Where needed.