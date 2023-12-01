# Project Compilation and Execution Guide

## Overview

This README provides the necessary commands and descriptions to compile and run the C++ project located in this repository.

## Compiling the Project

To compile the project, navigate to the root directory where the `Makefile` is located and run the following command:

```sh
make
```

This command compiles the `.cpp` files from the `src` directory into `.o` files in the `build` directory. It then links these object files to create the executable program.

## Running the Program

Once the project is compiled, you can run the executable by entering:

```sh
./your_program_name
```

Replace `your_program_name` with the actual name of the generated executable.

## Changing Executable Permissions

If the executable file does not have the necessary execution permissions, you can modify its permissions with:

```sh
chmod +x your_program_name
```

Replace `your_program_name` with the actual name of your executable file.

## Cleaning the Build

To clean up the build directory and remove all the `.o` files and the executable, you can use:

```sh
make clean
```

This command is assuming your `Makefile` has a `clean` rule set up.

## Additional Information

For any additional scripts, troubleshooting, or other project-specific information, refer to the relevant sections below.

<!-- BlackBox: Add your project-specific information or scripts here. -->

