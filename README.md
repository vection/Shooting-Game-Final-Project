# FPS Game

# Final Report

### Aviv Harazi, Maor Bakshi, Neil Michaeli, Advisor: Dr. Dan Ophir
#### September 2019

##### * Due to heavy weight of the project only base code uploaded
##### * Video Review https://youtu.be/AWQGf6WZMDs 

## Introduction
This project is about development in the industry - standard game engine Unreal

Unreal Engine 4 is a powerful and complex tool that let you design and program
maps, environment, AI, actors and much more.
The programming language is c++ and Blueprints (a visual way to interact
and program in c++), unreal working alongside visual studio or xcode for code
writing.
Huge games were build and being build by this engine like Kingdom Hearts,
Bioshock, Gears Of War and the list goes on.
Our main objective here is to explore and build a first person shooter game
with highest standard as possible. Building these games generally takes around
3-4 years with hundreds of people working in teams that deals with design,
programming, networking, ui/ux etc, we are a team three people and except
for code we have a lot of things we are learning on the fly like semi - design
, level design , animation etc and that’s what makes the challenge even more
challenging.
In our project we tried our best to combine between whats the engine have to
offer, from c++ to Blueprints, Behaviour Trees and Blackboards.

![ue4](https://user-images.githubusercontent.com/28596354/66060426-4800e380-e546-11e9-8455-a1b5ec3df5a8.png)

Figure 1: Unreal Engine 4

## What we did
In our project we have:

### 2.1 Character
Body and Animations – There are few states which indicates on the movement,
a lot of work done on that part. We have a few state machine – the basic
one is Notmoving, Moving, toStop states. Some basic movements – Walking,
Running, Sprinting, Jumping, Crawling, Crouching, Aiming. On this part we
added blending with upper body and lower body as we need to animate with
our weapon. We ended up with basic state machine blend with upper body
animations result perfect control and character animated with weapon. Also we
have Reload functions which is also animated (Mag switch included). Aiming
parameters – we have few parameters dealing with aiming, target FOV, Aim
FOV, Aim speed and default FOV. These values can be changed via Blueprint.
(FOV – Field of view) As we mentioned before, character may hold weapon.
Movement System – We have movement system which controls on walking,
running, sprinting, crouching, crawling speed.

![project2](https://user-images.githubusercontent.com/28596354/66060514-7088dd80-e546-11e9-8574-e9d735b2cac1.png)
Figure 2: Character Class

### 2.2 Built AI
Using Behavior tree, Blackboards, Code and Blueprints. we implemented bots
that roam in the map, identify other players and shoot them. Blackboard
contains the variables we are working with.
the Behavior tree execute the tasks of our bots using 5 kind of nodes: sequence,
selector, simple parallel, service and decorators.
the bots has an AI that contains:

### 2.2.1 Sight

they can see you depends on the parameters we defined via c++ code like sight
range, angle and radius.

### 2.2.2 Act

The bot will try to approach and terminate you with shooting, but if he will
feel threatened he will flee.

### 2.3 Navigation
we defined an object called ”Navigation mash”, the component defines the
bounds and areas the bot can walk on and navigate

### 2.4 EQS
Unreal component that help out character to decide about he’s next step (use
very lightly).

![WhatsApp Image 2019-10-02 at 19 22 27](https://user-images.githubusercontent.com/28596354/66063004-2c4c0c00-e54b-11e9-9331-1ca1078e2be7.jpeg)

Figure 3: an example of a behavior tree and blackboard

### 2.5 AI debug
there’s a tool in unreal for debugging, when you use this tool you can actually
see all the
variables and EQS the specific AI sees and it helps a lot to understand what
your bot is seeing now. the green field represents the nav mash which is the
area the bot can navigate in and the big dots are the EQS area’s which the bot
taking into consideration in terms of escape and attack.

![WhatsApp Image 2019-10-02 at 19 24 50](https://user-images.githubusercontent.com/28596354/66063034-3e2daf00-e54b-11e9-932c-2121557a82bb.jpeg)

Figure 4: an example of a behavior tree and blackboard

### 2.6 Weapon
We have few types of weapons in the game – M4, AK47, AR85, AWM. Each
weapon has it own sounds, flash effect, muzzle effect, animations, mag, grip and
so on. Each weapon dealing different hit point , different recoil and fire rate.
Weapon can be added very quickly in our project because most of the code is
C++ based purely.

### 2.6.1 Scopes

In our game we have Red hot sight, Scope4x, Scope8x. All sights can be located
on each weapon.
![4](https://user-images.githubusercontent.com/28596354/66060867-0a508a80-e547-11e9-846e-32a06b5abda0.png)
Figure 5: Weapon Class

### 2.7 Animation
All character movement is animated and working using blueprint.
everything the character do is animated like run, shoot, magazine switch etc.

![AnimStateMachine](https://user-images.githubusercontent.com/28596354/66060942-281def80-e547-11e9-82d2-f3b138a7a75e.png)
Figure 6: Animation state machine

## 2.8 Design

### 2.8.1 Map

Using assets and free tools we designed beautiful forest-like map
with places to hide and stalk, we explored the editor and he’s functionality and
sculpt a bi, the assets were download it, after drag and drop them defined col-
lisions and if character can step on.

### 2.8.2 Skins

our character are not default looking they have army uniform for the feeling.
we variety of weapons that can be used.

## C++ Code

The base few classes written in C++ : Character, Weapon, Health Component,
AI Controller and Perception.
Brief explanations:

### 3.1 Character
In character we have a lot of pointers which we will use them to reveal to
Blueprint and assign it. Such as Mesh component (Character body), Camera
and so on...
Aiming parameters – we have few parameters dealing with aiming, target FOV,
Aim FOV, Aim speed and default FOV, These values can be changed via
Blueprint. (FOV – Field of view) There are a lot of parameters which re-
laying to ”Aiming” issue, some Booleans to indicate some states, weapons class
pointers and functions.

### 3.2 Weapon
I can say that working on weapon class was the hardest part, this class took
a lot of time to build and integrate it with different classes. Here again, we
have the Mesh component which is the body of our weapon (can be different
types) we have few more parameters – vectors (indicate some positions), floats,
booleans, sounds references, functions and so on..

### 3.3 Health Component
Basic class to represent health of character.

### 3.4 AI Controller
This is the class to control AI characters, we use the same character class and
added some figures and functions to actually enable playing with it.
AI Perception – it’s a very interesting object we can use to specify AI different
perceptions (we used sight), it allowing us to control how far AI will see, density
of generated points and so on. We have for example ”onPawnDetected” – when
pawn detected by AI sight and we can do some manipulations with it.

### 3.5 Nodes
we experiment with unreal engine classes and built behavior tree purely on c++,
we used inheritance to inherit tasks, services, Decorators etc, and override their
functions so we can define exactly what the character will do tho, for the final
Behavior we used blueprints in order to reach ”higher complexity” in the time
we had.

## Blueprints classes

### 4.1 Character
Here we can see character class in blueprint, there is Begin Play event and Tick
event.
In the begin play we set some basic parameters and also attach weapon to our
player.
We can see on the left the components of our player which Mesh is the body
representation in the world, also we have camera component (we have two types
here), health component and movement component.
On the right there are a lot of parameters we can change such as movement
system parameters and player parameters. We also can see the reference of the
weapon associated with the player.
In the middle of the screen there are few graphs which being handle every tick
or when we call them – this is blueprint programming.
Each graph contains few nodes and we can do whatever we need there, it is
same as C++ programming in unreal engine 4. For example, the next picture
is attaching weapon to character in blueprint.(screen is to small for the whole
process but its enough)

![1](https://user-images.githubusercontent.com/28596354/66061014-4a177200-e547-11e9-9342-e0f28af805f5.png)
Figure 7: Character Blueprint

Under ”PlayerInputGraph” we can see the input of the character, for ex-
ample by pressing ”R” in game we will reload the gun or by pressing ”w” our
character go forward.

![2](https://user-images.githubusercontent.com/28596354/66061064-5c91ab80-e547-11e9-883c-c5087cb650c5.png)
Figure 8: Character Blueprint

### 4.2 Weapon
This is the weapon class via Blueprint. We have the components of the weapon
on the left, camera for each position (for sight view) and some functions.
On the right we have weapon parameters such as base damage, fire rate, weapon
type and so on.
Firing is working by making straight line from flash hider and if we hit some
thing we get the information. Also we have Effects, Sounds, Animations and
Sight categories.

![3](https://user-images.githubusercontent.com/28596354/66061101-6d422180-e547-11e9-98a2-c05531940547.png)
Figure 9: Weapon Class

### 4.3 Weapon’s Sight
Again, the same structure as before, this is the sight class. There is a camera in
front of the sight, this camera makes the zoom and we render the capture of it
to the lens. Also we can change some values which you can see on the right. (*
Due to engine update Render texture 2d function do some trouble with creating
so to 4.22+ version scope4x/8x is not working for now)

![8](https://user-images.githubusercontent.com/28596354/66061144-85b23c00-e547-11e9-8601-252ad7416904.png)
Figure 10: Sight Class

### 4.4 AI Controller
This is the brain of AI character, it controls movement, decision and so on. This
class built in C++ and integrated with blueprint. In AI Controller we add EQS
queries (Environment query system) which helps us to identify what around
the bot, behavior tree and some other parameters. Also we have perception
component with bunch of abilities.

![5](https://user-images.githubusercontent.com/28596354/66061199-a5e1fb00-e547-11e9-9298-3d0ec35d6201.png)
Figure 11: AI Controller Class

### 4.5 Behavior Tree
AI designed to do this process – running between safe positions freely, if enemy
detected he checks if he can shoot towards him, if true he shoots, if false he run
to hiding place and shoot from there.(made with EQS)

![6](https://user-images.githubusercontent.com/28596354/66061231-b8f4cb00-e547-11e9-89b3-a3e2a55cfc73.png)
Figure 12: Final Behavior Tree

### 5 Conclusion
well, you can see that we explored a lot and At the end of the day we had a
great experience with this project.
It is not possible to actually develop an entire game but still we had a great
time and great work still there’s a lot we would be happy to add here so the
game will be actually playable for all like:

### 5.1 More complex AI
it’s a world of it’s own and there’s a lot to explore here.

### 5.2 Complex Navigation and EQS
we barley touched it and it’s awesome!

### 5.3 Game modes
so there will be actual rules.

### 5.3 Game modes

### 5.4 Optimization
how do developers keep stable frame rate? we wonder...

### 5.5 Online
well, it’s vary popular these days.

### More photos
![7](https://user-images.githubusercontent.com/28596354/66061262-ca3dd780-e547-11e9-8a2e-64e561e7b7d9.png)
AWM weapon class
![9](https://user-images.githubusercontent.com/28596354/66061295-dde93e00-e547-11e9-859f-49208cb0dc27.png)
Recoil stats


