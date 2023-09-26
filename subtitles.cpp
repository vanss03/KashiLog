hey what's going on guys welcome to a new series now for those of you waiting on laravel the premium course the crash

course and the youtube project should

all be released within the next few

weeks so in this series what we're going

to be doing is creating a nodejs and

express application from absolute

scratch so the idea of this series is to

be very very beginner friendly and to be

kind of a continuation off of my node.js

for beginners crash course alright so

after people finish that this gives them

the opportunity to actually create a

project with node and express in a bunch

of other technologies ok so this will be

from absolute scratch we're going to

start on a machine that doesn't even

have no js' or Express or MongoDB

installed we're going to go through the

installations we're going to set up the

environment and then there's going to be

no generators no copying and pasting the

goal of this is to write and explain

every line of code so that you guys can

really grasp what's going on as opposed

to just watching a demo of an app being

built alright so if you have a little

experience with node and express in

MongoDB that's great if you don't even

know what those are I would suggest

watching these three videos here they're

there on my channel I was just watching

those before tempting the course or the

series alright now as far as the

application goes it's going to be very

simple in terms of functionality at

least at first we're going to be able to

create read update and delete articles

stored in a MongoDB database from our

node and Express app all right so let's

take a look at some of the technologies

that we'll be using and learning so

nodejs and npm nodejs is a JavaScript

runtime and server-side technology and

it comes with NPM which is node package

manager and this is used to install

modules like Express and thousands of

others okay so Express is a back-end

framework for building powerful

applications web applications

MongoDB which is a no SQL database

mongoose which is an ORM or an object

relational mapper and this allows our

application to interface with MongoDB

we'll be using the pug template engine

for our views pug is formally known as J

we'll be installing bootstrap a few

videos in and we're going to use Bower

for that which is a front-end package

manager similar to NPM we'll also do a

little bit of jQuery and Ajax to make

delete requests to our server alright so

I try not to mention this stuff too much

but I do have a patreon if you guys want

to support this channel directly even

$1.00 per month is greatly appreciated

if there's enough people that can help

out then I'll be able to do this stuff

full-time which is my goal and I'm also

working on some exclusive content and

perks for patrons for one-time donations

I have a paypal dot me account and then

if you're interested in premium courses

I have affiliate links at traversée

Mediacom slash edge' wanax courses

alright and I will be creating my own

courses very very soon so that's it guys

let's go ahead and get started on this

project and hopefully you enjoy it

alright guys in this video we're going

to be setting up our environment so

we're going to install a couple things

to build our application now I'm using

Windows because I want this to be

completely beginner friendly and I know

that a lot of people that are just

getting into web development and so on

maybe on Windows alright

but this is completely cross-platform

all the code we write everything it

doesn't matter what system you're on

alright so we're going to install a

couple things of course we need nodejs

and nodejs is a JavaScript runtime if

you have no clue what nodejs is I would

suggest watching my node for beginners

video we're going to install that that

also comes with NPM which is node

package manager and that's a command

line tool that we can use to install

different modules like Express and

Mongoose and so on

alright we're also going to need a

database and we're going to use MongoDB

long would you be is a no SQL database

if you want to learn more about

I'd suggest my MongoDB in 30 minutes

video I also just did a video called a

guide to know SQL databases if you want

to learn more about no SQL in general

we're also going to be using atom which

is a text editor this is what I've been

using for the most part lately and it's

it's a really nice editor it's by github

it's very very

well as far as looks and themes and it

also has a bunch of packages that you

can install that will help you with

development so we're going to install

that and then sensitive on Windows we

need a better command line because the

the standard CMD command line in Windows

is garbage so we're going to be using

git bash okay so this right here get SCM

comm you can download it it's going to

download the git version control system

along with the command line tool called

git bash alright so let's get started

first thing we'll do is install nodejs

so we're going to just go ahead and

click here we're going to get the

recommended version which is at this

time six point ten point three and

that's going to just be an installer

we'll just go through it quickly

alright so let's open it up and just go

through this we'll click Next and it's

going to go into your Program Files if

you're on Windows click Next and install

alright and it's as easy as that nodejs

and NPM is now installed so next thing

we're going to do is we're going to

install MongoDB so let's go ahead and go

to C download and there's a few steps

that we need to do here some of which

are in the command line but it's not too

bad so we're going to grab the yeah

windows 64-bit 2008 and later and that's

going to download the MSI file so this

is another installer that we need to go

through and it is a hundred and forty

eight megabytes so it may take a couple

minutes to download so once it's

downloaded just open it up and we're

going to go through this next and I'm

going to click custom right here because

I want to change the install path by

default it's going to be Program Files

MongoDB server and then the version I

don't want that I want it to be right in

the C Drive

so let's go to local C Drive and what

I'll do here is create a new folder

called MongoDB alright and that's where

we want this to be installed c / MongoDB

will click Next and then install and

it's going to go through the setup okay

so we'll click finish now there's a

couple extra steps we need to take we

need to go into that folder that we just

installed it in so for me it's going to

be C Drive MongoDB and we're going to

create a folder here called data alright

and then inside the data folder we're

going to create another folder called DB

this is where all of our data will be

stored now we have to also create a

log-log folder so it's a new folder log

alright and then we need to open up a

command line and I haven't installed git

bash yet so we'll just use the standard

command prompt so it's a CMD and we'll

run that as administrator okay and then

let's see so I'm going to navigate to

that folder so we want to go to CD

MongoDB and we actually want to go in

the bin folder alright if we look at

what's in there oops can't do that

there is a vis MongoDB XE that's the

main program so we need to run that with

some options or some flags so let's say

D and then we're going to do - -

let me make this a little bigger so you

guys can see it see I haven't done this

in a while

font let's make it 28 there we go

alright so D directory oops why

isn't that typing directory and it's

going to be per DB okay directory / DB

and then - - DB path

and then we want to define that data

path that we created so it's going to be

in your MongoDB MongoDB folder slash

data slash the B okay that's the folder

we just created so what we're doing is

we're specifying the database path as

that folder all right or that location

then we need to specify the log path

okay so that is going to be C slash

MongoDB slash log and it's going to be a

file called Hmong dot log and

it'll create that on its own then we

just want to add a couple more flags

here - - log append

we also want to do dash dash rest and

dash dash install ok and then that will

install it as a service so that it runs

in the background we don't have to

manually start and stop at all the time

and so on

so let's go ahead and click enter and

next thing we want to do is start the

MongoDB service so to do that we can say

net start MongoDB okay now it says the

services started successfully so that's

it MongoDB is now installed it's running

and we can now interact with it from

from our application so let's go ahead

and close that up and then we're going

to move on we're going to install Adam

which is the text editor so I'm just

going to click download all right so

once that's done we're just going to

open that up and the Adam installer is

is really weird because it does

everything behind the scenes you'll see

this little splash screen and then once

it's done it'll just be installed on

your system alright Adam is it Adam was

actually created with JavaScript it uses

electron which is a JavaScript framework

that allows you to build desktop

applications with JavaScript which is

really cool and I do have an intro to

electron video if you're interested in

that

all right so it's installed Adam and

started it up I'm just going to get rid

of this stuff this is just because I had

it installed previously so let me just

remove that project and then this is

just kind of a welcome screen if you

want to open a project install packages

and so on but we're going to close all

that up and will most likely install

some packages but we're going to do that

later on all right so we can close that

for now and then we're going to move on

to install git and get bash so let's

click this download for Windows if

you're using a Mac you can go to

download slash Mac and get this same

same program all right so that's going

to start it's only 35 megabytes so it

shouldn't take too long to download all

right so we'll open that up and we're

just going to go through this it's going

to install it in your Program Files and

then for this we'll just leave all the

defaults and then when you see this

option I always choose this because this

will add optional UNIX tools to the

regular Windows command prompt so for

instance LS you saw that I tried doing

that in the regular command line and it

didn't work so it'll add that it'll add

a whole bunch of stuff so I always

choose that and then for the rest of

this stuff we're going to leave the

default open SSL library that's good

windows style click Next Next and enable

filesystem caching we'll leave that

credential manager we'll leave that and

we'll click install all right so that's

all set now

let's go ahead and click launch git bash

and then this is the command-line tool

so we can make this bigger with can

holding ctrl and then scroll the mouse

wheel and just to check to make sure

that node is installed we can say node

dash B you can see we have version six

point seven point three and we can also

say NP

- B and we have version three point

seven point ten so that's it for setting

setting up our environment in the next

video we're going to start - to build

out our application will create our

package JSON file and we'll go from

there
