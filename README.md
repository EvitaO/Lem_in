# Lem_in

Lem-in is an elementary algorithmic project, thats is meant to make you code an ant farm manager.
<br/>It is a project you have to do with 2people, I did it togheter with [@eutienne](https://github.com/Eutienne)

## Project

The goal of this project is to find the quickest way to get n ants across the farm. Quickest way means the solution with the least number of lines, respecting the output format requested below.

Obviously, there are some basic constraints. To be the first to arrive, ants will need to take the shortest path (and that isn’t necessarily the simplest). They will also need to avoid traffic jams as well as walking all over their fellow ants.

## Rules

At the beginning of the game, all the ants are in the room '##start'. The goal is to bring them to the room '##end'with as few turns as possible. Each room can only contain one ant at a time. (except at '##start' and '##end' which can contain as many ants as necessary.

We consider that all the ants are in the room##startat the beginning of the game. At each turn you will only display the ants that moved.

At each turn you can move each ant only once and through a tube (the room atthe receiving end must be empty).

You must to display your results on the standard output in the following format:
```
number_of_ants
the_rooms
the_links

Lx-y Lz-w Lr-o ...
```
x, z, r represents the ants numbers (going from 1 to number_of_ants) and y, w, o represents the rooms names.

## Data rules

Your program will receive the data describing the ant farm from the standard output in the following format:
```
number_of_ants
the_rooms
the_links
```
number_of_ants:<br/>how many ants you have to move from the start to the end room

the_rooms:<br/>rooms defined by: name coord_x coord_y<br/>rooms coordinates will always be integers and the room name can lever start with 'L', '#' or contain a '-'.

the_links:<br/>links defined by: name1-name2

In the date there can be comments, thay always start with an '#'. '##start' signals that the next lines is the start room and '##end' signals that the next lines is the end room.
All the other comments can be ignored.

Any non compliant or empty lines will automatically stop the ant farm’s reading as well as the orderly processing of the acquired data.

## Allowed functions

malloc
<br/>free
<br/>read
<br/>write
<br/>strerror
<br/>perror
<br/>exit

for the bonus part you can use other functions

## Bonus

We made the following bonusses:
<br/>A test script with invalid maps, to check if lem-in gives an error message.
<br/>A test script that generates maps with the generator, uses those maps on lem-in and gives a results if you failed or passed depending on how many lines lem-in used and on Linux it gives the average time your lem-in takes.
<br/>A python program that makes an image from the maps lem-in uses, but with random coordinates.

You can read the README's of the bonusses in my other git repositories(named: Tester-lem-in and map_image_lemin).

## Usage

Run the following command:
```bash
$ make
$ ./lem-in < [filename]
```
