# Intelligent Robot

In this final version of the program, the robot makes its decisions based on **its actual position, the position of the reward, and the position of the penalty**. As the grid works with coordinates, the agent decides whether to go one direction or any other, always trying to get as close as possible to the reward, maintaining its distance from the penalty.

As the reward is always located in the same coordinates, the process is up to the robot, to find the quickest way between its coordinates, and the reward ones. The agent, every move decides wether to go south or east, observing its environment.

As a first parameter, like the first version, it requires you to enter the number of test robots you desire to run.

<p align="center">
	<img src="https://www.andrevital.com/extra/ai-robopath/images/input.png" width="45%">
</p>

Then, the program will start running _n_ iterations of the robot finding its way to the reward. When it reaches its reward, the program will display a message stating so, and the number of steps it took that robot to reach its goal.

<p align="center">
	<img src="https://www.andrevital.com/extra/ai-robopath/images/ind_steps.png" width="45%">
</p>

When all robots are done, a message displaying the one or the ones that took longer to reach the reward, along with the steps it took to reach it.

<p align="center">
	<img src="https://www.andrevital.com/extra/ai-robopath/images/single_long.png" width="65%">
	<img src="https://www.andrevital.com/extra/ai-robopath/images/mult_longs.png" width="60%">
</p>

After that, the results screen is shown, which shows all the robots with the steps each required to get to the reward.

<p align="center">
	<img src="https://www.andrevital.com/extra/ai-robopath/images/results_screen.png" width="40%">
</p>

Alongside this results screen is a _Path Reviewer_ option, which, as it names says, lets you review all the robots' paths to get to the reward.

<p align="center">
	<img src="https://www.andrevital.com/extra/ai-robopath/images/path_reviewer.png" width="70%">
	<img src="https://www.andrevital.com/extra/ai-robopath/images/path.png" width="35%">
</p>