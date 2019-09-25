# Robo-Labyrinth (3 levels)

Three versioned Python / C/C++ program, consisting of three different implementations of a path finding agent towards a unique goal.

### 1. Dumb Robot

This is the starting version (or the first level). In this version, all decisions made by the agent are completely random.

### 2. Bellman Robot

This is the second version of the program. In this version, the steps are calculated with the **Bellman equation**. This version was taken from [Roberto Rama's Pacman GitHub project](https://github.com/ramaroberto/pacman), so all credits to him.

### 3. Intelligent Robot

In this final version of the program, the robot makes its decisions based on **its actual position, the position of the reward, and the position of the penalty**. As the grid works with coordinates, the agent decides whether to go one direction or any other, always trying to get as close as possible to the reward, maintaining its distance from the penalty.


This series of programs were made under as a project for the [Universidad Autónoma de Aguascalientes](https://www.uaa.mx/)
