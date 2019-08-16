# StarDust

StarDust is a modular robot framework for C++ FRC teams

StarDust eliminates boilerplate code, fixes sneaky bugs, and wraps existing FRC libraries to squeeze in even more functionality. All of this is to direct attention to the real task at hand: Building seamless and optimized robots.

Say good bye to hard-coding the same drive train year after year, and hello to fine tuning your controller inputs for the perfect drive

## Installing (non git based teams)

Download, extract and copy the `StarDust` folder into the `src/main/include` folder of your project

Now, include files with `#include "Stardust/path/to/file"` Where needed

## Installing (git based teams)

To be able to add another git repo into your existing git repo, a `submodule` should be made. 

First, create a full backup of your git repo

Then, inside of `src/main/include` in your project, run:

`git submodule add -b master https://github.com/FRC-4309/StarDust.git`

Then

`git submodule init`

To pull new changes from StarDust later, run `git pull --recurse-submodules`

## Adding source folder to Gradle (required)

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

Now, you can use and compile StarDust code