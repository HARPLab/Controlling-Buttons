# Ros Controlling Buttons

## Setup:
Ensure ROS and computer is configured properly by following this tutorial: http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup . Ignore the part about setting up arduino environment

## How to run: 

1.) Plug arduino into computer 

2.) Find the port of the arduino by running the command: '''ls -l /dev/ttyACM*''', it should return the port in the form '''/dev/ttyACM_'''

3.) Then run the commands '''sudo usermod -a -G dialout <username> ''', followed by '''sudo chmod 666 /dev/ttyACM_'''

4.) Start up roscore, then '''rosrun rosserial_python serial_node.py /dev/ttyACM_ '''

5.) You should be able to find the topic by doing '''rostopic echo pushed'''
